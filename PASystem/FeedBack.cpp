#include "FeedBack.h"

#include <QPushButton>
#include <QDate>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;

FeedBack::FeedBack(string m_mechanism_id,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	mechanism_id = m_mechanism_id;

	initMembers();
	connectMembers();
}

FeedBack::~FeedBack()
{
}

void FeedBack::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("反馈"));

	m_sql.init();

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void FeedBack::connectMembers()
{
	/***************** QPushButton *********************/
	connect(ui.pushButton_up1, &QPushButton::clicked, //图片1
		[=]()mutable
	{
		path_img_1 = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("上传附加图片"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label->setPixmap(QPixmap(QString(path_img_1.c_str())));
	}
		);
	connect(ui.pushButton_up2, &QPushButton::clicked, //图片2
		[=]()mutable
	{
		path_img_2 = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("上传附加图片"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_2->setPixmap(QPixmap(QString(path_img_2.c_str())));
	}
	);
	connect(ui.pushButton_up3, &QPushButton::clicked, //图片3
		[=]()mutable
	{
		path_img_3 = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("上传附加图片"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_3->setPixmap(QPixmap(QString(path_img_3.c_str())));
	}
	);
	connect(ui.pushButton_commit, &QPushButton::clicked,//提交
		[=]()mutable
	{
		/*COUT "提交反馈 id=" LK emp_id LN;
		COUT QDate::currentDate().year() LK "-" LK QDate::currentDate().month() LK "-" LK QDate::currentDate().day() LN;*/

		//先检查是否提交过，如果没有就INSERT,提交过，就UPDATE

		if (ui.plainTextEdit_feedback->toPlainText().compare("")==0)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("内容不能为空！").c_str()));
			return;
		}

		m_sql.search(
			"SELECT * FROM mechanism_feedback WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
		);
		if (m_sql.getRows() == 0)
		{

			//反馈信息写入数据库
			if (m_sql.query(
				"INSERT INTO mechanism_feedback(mechanism_id,feedback,img_1,img_2,img_3,feedback_time,is_write)"
				"VALUES(" +
				APOSTROPHE + mechanism_id + APOSTROPHE + "," +
				APOSTROPHE + string(ui.plainTextEdit_feedback->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + path_img_1 + APOSTROPHE + "," +
				APOSTROPHE + path_img_2 + APOSTROPHE + "," +
				APOSTROPHE + path_img_3 + APOSTROPHE + "," +
				APOSTROPHE + string(lexical_cast<string>(QDate::currentDate().year()) + "-" +
					lexical_cast<string>(QDate::currentDate().month()) + "-" +
					lexical_cast<string>(QDate::currentDate().day())
				) + APOSTROPHE +","+
				APOSTROPHE+string("否")+APOSTROPHE+
				");"
			))
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("反馈成功！").c_str()));
			} else
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("反馈失败！原因：" + m_sql.error()).c_str()));
			}
			close();

		} else
		{
			//反馈信息更改
			if (m_sql.query(
				"UPDATE mechanism_feedback SET feedback=" +
				APOSTROPHE + string(ui.plainTextEdit_feedback->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
				"img_1="+APOSTROPHE+path_img_1+APOSTROPHE+","+
				"img_2=" + APOSTROPHE + path_img_2 + APOSTROPHE + "," +
				"img_3=" + APOSTROPHE + path_img_3 + APOSTROPHE + "," +
				"feedback_time=" + APOSTROPHE + string(lexical_cast<string>(QDate::currentDate().year()) + "-" +
					lexical_cast<string>(QDate::currentDate().month()) + "-" +
					lexical_cast<string>(QDate::currentDate().day())
				) + APOSTROPHE + "," + "is_write='否'"
				" WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
			))
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("反馈成功！").c_str()));
			} else
			{
				QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("反馈失败！原因：" + m_sql.error()).c_str()));
			}

			close();
		}



	}
	);
}
