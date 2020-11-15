#include "MechanismDetail.h"

#include <QPushButton>
#include <QMessageBox>

MechanismDetail::MechanismDetail(string c_mechanism_id, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	mechanism_id = c_mechanism_id;

	initMembers();
	connectMembers();
}

MechanismDetail::~MechanismDetail()
{
}

void MechanismDetail::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("机构详情"));

	m_sql.init();

	m_sql.search(
		"SELECT * FROM mechanism_info WHERE mechanism_id=" +
		APOSTROPHE + mechanism_id + APOSTROPHE + ";"
	);
	if (m_sql.getRows() != 0)
	{
		if (m_sql.getRowDatas()[0][18].compare("") != 0)
		{
			QImage img;
			img.load(QString::fromLocal8Bit(m_sql.getRowDatas()[0][18].c_str()));
			ui.label_name_logo_3->setPixmap(QPixmap::fromImage(img));
		} else
		{
			ui.label_name_logo_3->setText(QString::fromLocal8Bit("LOGO HEER"));
		}

		ui.lineEdit_team_name_11->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][0].c_str()));
		ui.lineEdit_team_name_12->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][1].c_str()));
		ui.plainTextEdit_3->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][2].c_str()));
		ui.lineEdit_team_name_17->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][3].c_str()));
		ui.lineEdit_team_name_18->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][4].c_str()));
		ui.lineEdit_team_name_13->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][5].c_str()));
		ui.lineEdit_team_name_19->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][6].c_str()));
		ui.lineEdit_team_name_14->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][7].c_str()));
		ui.lineEdit_team_name_15->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][8].c_str()));
		ui.lineEdit_team_name_16->setText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][9].c_str()));
		//机构证书
		if (m_sql.getRowDatas()[0][10].compare("") != 0)
		{
			QImage img;
			img.load(QString::fromLocal8Bit(m_sql.getRowDatas()[0][10].c_str()));
			ui.label_6->setPixmap(QPixmap::fromImage(img));
		} else
		{
			ui.label_6->setText(QString::fromLocal8Bit("未上传"));
		}
		ui.plainTextEdit_4->setPlainText(QString::fromLocal8Bit(m_sql.getRowDatas()[0][17].c_str()));
	}

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void MechanismDetail::connectMembers()
{

	/***************** QPushButton ******************/
	connect(ui.pushButton,&QPushButton::clicked,
		[=]()mutable
	{
		if (m_sql.query(
			"UPDATE mechanism_info SET mechanism_name=" + APOSTROPHE + string(ui.lineEdit_team_name_12->text().toLocal8Bit()) + APOSTROPHE + "," +
			"mechanism_introduce=" + APOSTROPHE + string(ui.plainTextEdit_3->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
			"address=" + APOSTROPHE + string(ui.lineEdit_team_name_17->text().toLocal8Bit()) + APOSTROPHE + "," +
			"type=" + APOSTROPHE + string(ui.lineEdit_team_name_18->text().toLocal8Bit()) + APOSTROPHE + "," +
			"register=" + APOSTROPHE + string(ui.lineEdit_team_name_13->text().toLocal8Bit()) + APOSTROPHE + "," +
			"id_card=" + APOSTROPHE + string(ui.lineEdit_team_name_19->text().toLocal8Bit()) + APOSTROPHE + "," +
			"phone=" + APOSTROPHE + string(ui.lineEdit_team_name_14->text().toLocal8Bit()) + APOSTROPHE + "," +
			"email=" + APOSTROPHE + string(ui.lineEdit_team_name_15->text().toLocal8Bit()) + APOSTROPHE + "," +
			"status=" + APOSTROPHE + string(ui.lineEdit_team_name_16->text().toLocal8Bit()) + APOSTROPHE + "," +
			"mark=" + APOSTROPHE + string(ui.plainTextEdit_4->toPlainText().toLocal8Bit()) + APOSTROPHE +
			" WHERE mechanism_id=" + APOSTROPHE + string(ui.lineEdit_team_name_11->text().toLocal8Bit()) + APOSTROPHE + ";"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("保存成功！").c_str()));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit(string("保存失败！原因：" + m_sql.error()).c_str()));
		}

	}
		);
}
