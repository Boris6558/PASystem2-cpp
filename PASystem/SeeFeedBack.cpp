#include "SeeFeedBack.h"

#include <QMessageBox>

string EnterViewLabel::img1 = "";
string EnterViewLabel::img2 = "";
string EnterViewLabel::img3 = "";

SeeFeedBack::SeeFeedBack(string c_mechanism_id, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	mechanism_id = c_mechanism_id;
	initMembers();
	connectMembers();
}

SeeFeedBack::~SeeFeedBack()
{
}

void SeeFeedBack::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("�����鿴"));

	m_sql.init();

	//��õ�ǰ��������
	m_sql.search(
		"SELECT mechanism_name FROM mechanism_info WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
	);

	ui.label_emp_id->setText(QString::fromLocal8Bit(mechanism_id.c_str()));
	ui.label_emp_name->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][0].c_str()));

	//��õ�ǰ����������Ϣ
	m_sql.search(
		"SELECT feedback,img_1,img_2,img_3 FROM mechanism_feedback WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
	);

	EnterViewLabel::img1 = m_sql.getRowDatas()[0][1];
	EnterViewLabel::img2 = m_sql.getRowDatas()[0][2];
	EnterViewLabel::img3 = m_sql.getRowDatas()[0][3];

	ui.label->setId(1);
	ui.label_2->setId(2);
	ui.label_3->setId(3);

	ui.plainTextEdit_feedback->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][0].c_str()));
	ui.label->setPixmap(QPixmap(QString::fromLocal8Bit(m_sql.getRowDatas()[0][1].c_str())));
	ui.label_2->setPixmap(QPixmap(QString::fromLocal8Bit(m_sql.getRowDatas()[0][2].c_str())));
	ui.label_3->setPixmap(QPixmap(QString::fromLocal8Bit(m_sql.getRowDatas()[0][3].c_str())));

	//������չ� ��ť������
	m_sql.search(
		"SELECT is_write FROM mechanism_feedback WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
	);
	if (m_sql.getRowDatas()[0][0].compare("��") == 0)//�ѽ���
	{
		ui.pushButton_receive->setEnabled(false);
	} else
	{
		ui.pushButton_receive->setEnabled(true);
	}

	//����
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void SeeFeedBack::connectMembers()
{
	/***************** QPushButton ***********************/
	connect(ui.pushButton_receive, &QPushButton::clicked,//����
		[=]()mutable
	{

		//��Ա��������Ϊ�Ѷ�
		if (m_sql.query(
			"UPDATE mechanism_feedback SET is_write='��' WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("�ɹ�"), QString::fromLocal8Bit(string("���ճɹ�").c_str()));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("ʧ��"), QString::fromLocal8Bit(string("����ʧ�ܣ�ԭ��" + m_sql.error()).c_str()));
		}

		close();
	}
	);
}
