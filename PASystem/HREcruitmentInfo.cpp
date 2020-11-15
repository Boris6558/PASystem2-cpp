#include "HREcruitmentInfo.h"

#include <QComboBox>

HREcruitmentInfo::HREcruitmentInfo(string c_mechanism_id, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	mechanism_id = c_mechanism_id;
	initMembers();
	connectMembers();
}

HREcruitmentInfo::~HREcruitmentInfo()
{
}

void HREcruitmentInfo::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("������Ƹ"));

	m_sql.init();

	//������Ƹ��Ϣ
	m_sql.search(
		"SELECT * FROM hr_ecruitment WHERE mechanism_id="+APOSTROPHE+ mechanism_id+APOSTROPHE+";"
	);
	for (int i = 0;i<m_sql.getRows();++i)
	{
		ui.comboBox->addItem(QString::fromLocal8Bit(m_sql.getRowDatas()[i][1].c_str()));
	}

	//��ʾ
	m_sql.search(
		"SELECT * FROM hr_ecruitment WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + " AND "
		"recruitment_post="+APOSTROPHE+string(ui.comboBox->currentText().toLocal8Bit())+APOSTROPHE+";"
	);
	
	ui.label_44->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][10].c_str()));//����ʱ��
	ui.label_51->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][8].c_str()));//��Ƹ״̬
	ui.plainTextEdit->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][3].c_str()));//��λ����
	ui.label_46->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][5].c_str()));//н�ʿ�ʼ
	ui.label_48->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][6].c_str()));//н�ʽ���
	ui.label_50->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][4].c_str()));//��Ƹ����
	ui.label_54->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][7].c_str()));//�����ص�
	ui.plainTextEdit_2->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][9].c_str()));//����˵��

	//����
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void HREcruitmentInfo::connectMembers()
{
	void (QComboBox::*p_currentTextChanged)(const QString &text) = &QComboBox::currentTextChanged;
	connect(ui.comboBox, p_currentTextChanged,
		[=](const QString &text)mutable
	{
		//��ʾ
		m_sql.search(
			"SELECT * FROM hr_ecruitment WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + " AND "
			"recruitment_post=" + APOSTROPHE + string(text.toLocal8Bit()) + APOSTROPHE + ";"
		);

		ui.label_44->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][10].c_str()));//����ʱ��
		ui.label_51->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][8].c_str()));//��Ƹ״̬
		ui.plainTextEdit->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][3].c_str()));//��λ����
		ui.label_46->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][5].c_str()));//н�ʿ�ʼ
		ui.label_48->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][6].c_str()));//н�ʽ���
		ui.label_50->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][4].c_str()));//��Ƹ����
		ui.label_54->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][7].c_str()));//�����ص�
		ui.plainTextEdit_2->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][9].c_str()));//����˵��
	}
		);
}
