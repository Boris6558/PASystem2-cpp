#include "PASystem.h"

#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QCheckBox>
#include <QPalette>

PASystem::PASystem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initMembers();
	connectMembers();

}

void PASystem::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("金融机构绩效考核系统设计和实现"));

	m_sql.init();

	ui.stackedWidget->setCurrentIndex(0);

	ui.checkBox_auto_login_2->hide();
	ui.label_forget_passwd_2->hide();

	ui.label_provision_2->setText(QString::fromLocal8Bit(string(
		"<a href=\""
		"http://www.gov.cn/gongbao/content/2017/content_5213211.htm"
		"\">已同意Bingood相关条款"
	).c_str()));
	
	//记住密码
	property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
	if (!pt.empty())
	{
		ui.checkBox_remember_passwd_2->setChecked(pt.get<int>("system.remenber_login"));
		if (ui.checkBox_remember_passwd_2->isChecked())
		{
			ui.lineEdit_login_name_2->setText(QString::fromLocal8Bit(pt.get<string>("CurrentMechanismInfo.login_name").c_str()));
			ui.lineEdit_login_passwd_2->setText(QString::fromLocal8Bit(pt.get<string>("CurrentMechanismInfo.login_passwd").c_str()));
		}
	}

	/*********** 美化 ***********/
	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(login_back.jpg))));
	setPalette(pal);
	//LOGO
	ui.label->setText("");
	ui.label->setPixmap(QPixmap(PATH_IMG(LOGO.png)));
	ui.label->setFrameShape(QFrame::NoFrame);

	//图标 账户和密码
	ui.label_3->setPixmap(QPixmap(PATH_IMG(icons8_user_male_26px.png)));
	ui.label_4->setPixmap(QPixmap(PATH_IMG(icons8_password_26px.png)));
	
}

void PASystem::connectMembers()
{
	/***********************  QCheckBox ****************************/
	connect(ui.checkBox_remember_passwd_2, &QCheckBox::stateChanged,//记住密码
		[=](int status)mutable
	{
		property_tree::ini_parser::read_ini(CONFIG_FILE, pt);

		if (status == Qt::Checked)
		{
			pt.put<int>("system.remenber_login", 1);
		} else if (status == Qt::Unchecked)
		{
			pt.put<int>("system.remenber_login", 0);
			pt.put<string>("CurrentMechanismInfo.login_name", "");
			pt.put<string>("CurrentMechanismInfo.login_passwd", "");
		}

		property_tree::ini_parser::write_ini(CONFIG_FILE, pt);
	}
	);

	/***********************  MLabel ****************************/
	connect(ui.label_register_2, &MLabel::sigClick,//注册
		[=]()mutable
	{
		COUT string(ui.label_register_2->text().toLocal8Bit()) LN;

		ui.stackedWidget->setCurrentWidget(ui.page_register_2);
	}
	);
	connect(ui.label_forget_passwd_2, &MLabel::sigClick,//忘记密码
		[=]()mutable
	{
		COUT string(ui.label_forget_passwd_2->text().toLocal8Bit()) LN;
	}
	);
	connect(ui.label_provision_2, &MLabel::sigClick,//注册条款
		[=]()mutable
	{
		COUT string(ui.label_provision_2->text().toLocal8Bit()) LN;
	}
	);

	/***********************  QPushButton ****************************/
	connect(ui.pushButton_back_2, &QPushButton::clicked,//后退
		[=]()mutable
	{
		COUT string(ui.pushButton_back_2->text().toLocal8Bit()) LN;

		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->currentIndex() - 1);
	}
	);
	/***********************  QPushButton ****************************/
	connect(ui.pushButton_login_2, &QPushButton::clicked,//登录
		[=]()mutable
	{
		string c_login_name = string(ui.lineEdit_login_name_2->text().toLocal8Bit());
		string c_login_passwd = string(ui.lineEdit_login_passwd_2->text().toLocal8Bit());
		//判断时绩效管理员登陆还是机构登录
		m_sql.search(
			"SELECT login_passwd FROM admin_acc WHERE login_name="+APOSTROPHE+c_login_name+APOSTROPHE+";"
		);
		if (m_sql.getRows())//管理员账号找到
		{
			if (m_sql.getRowDatas()[0][0].compare(c_login_passwd)==0)//绩效考核管理员登录
			{
				POINTER_INS(m_bmp, BackManagerPanel);
				m_bmp->show();
				SET_NULL(m_bmp);
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码错误！"));
			}
		} else//找机构账号
		{
			m_sql.search(
				"SELECT login_passwd,mechanism_id,path_logo FROM mechanism_info WHERE login_name=" + APOSTROPHE + c_login_name + APOSTROPHE + ";"
			);
			if (m_sql.getRows())
			{
				if (m_sql.getRowDatas()[0][0].compare(c_login_passwd) == 0)
				{
					property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
					if (!pt.empty())
					{
						pt.put<string>("CurrentMechanismInfo.mechanism_id", m_sql.getRowDatas()[0][1]);
						pt.put<string>("CurrentMechanismInfo.login_name", c_login_name);
						pt.put<string>("CurrentMechanismInfo.login_passwd", c_login_passwd);
						pt.put<string>("CurrentMechanismInfo.path_mechanism_logo", m_sql.getRowDatas()[0][2]);

						property_tree::ini_parser::write_ini(CONFIG_FILE, pt);
					}
					//机构登录
					POINTER_INS(m_mp, MechanismInfoPanel);
					m_mp->show();
					SET_NULL(m_mp);
				} else
				{
					QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("密码错误！"));
				}
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("该账号没有注册！"));
			}
				
		}
	}
	);
	connect(ui.pushButton, &QPushButton::clicked,//上传 金融机构代码证
		[=]()mutable
	{
		path_id = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("上传头像"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_5->setPixmap(QPixmap(QString(path_id.c_str())));
	}
	);
	connect(ui.pushButton_2, &QPushButton::clicked,//上传 公司logo
		[=]()mutable
	{
		path_logo = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("上传头像"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_6->setPixmap(QPixmap(QString(path_logo.c_str())));
	}
	);
	connect(ui.pushButton_3, &QPushButton::clicked,//注册
		[=]()mutable
	{
		regex reg_mechanism_id(str_mechanism_id);
		regex reg_man_id(str_man_id);
		regex reg_phone(str_phone);
		regex reg_email(str_email);
		regex reg_number(str_number);

		//是否勾选条款
		if (!ui.checkBox_2->isChecked())
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("失败！请勾选相关条款！").c_str()));
			return;
		}

		if (ui.lineEdit_team_name_2->text().compare("")==0 ||
			ui.lineEdit_team_name_3->text().compare("") == 0 ||
			ui.plainTextEdit->toPlainText().compare("") == 0 ||
			ui.lineEdit_team_name_4->text().compare("") == 0 ||
			ui.lineEdit_team_name_5->text().compare("") == 0 ||
			ui.lineEdit_team_name_6->text().compare("") == 0 ||
			ui.lineEdit_team_name_7->text().compare("") == 0 ||
			ui.lineEdit_team_name_8->text().compare("") == 0 ||
			ui.lineEdit_team_name_9->text().compare("") == 0 ||
			ui.lineEdit_team_name_10->text().compare("") == 0 ||
			ui.lineEdit_team_name_11->text().compare("") == 0 ||
			ui.lineEdit_team_name_12->text().compare("") == 0 ||
			ui.lineEdit_team_name_13->text().compare("") == 0 ||
			ui.lineEdit_team_name_14->text().compare("") == 0 ||
			ui.plainTextEdit_2->toPlainText().compare("") == 0 ||
			path_id.compare("")==0
			)
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("失败！请检查输入是否有空或者机构代码证是否上传！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_2->text().toLocal8Bit()), reg_mechanism_id)==false)//机构编号
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("机构编号错误！格式如123456-123456").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_6->text().toLocal8Bit()), reg_man_id) == false)//身份证
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("身份证格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_7->text().toLocal8Bit()), reg_phone) == false)//电话
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("电话格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_8->text().toLocal8Bit()), reg_email) == false)//邮箱
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("邮箱格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_9->text().toLocal8Bit()), reg_number) == false)//总人数
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("（总人数一栏）格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_10->text().toLocal8Bit()), reg_number) == false)//男性占比
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("（男性占比）格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_11->text().toLocal8Bit()), reg_number) == false)//女性占比
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("（女性占比）格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_12->text().toLocal8Bit()), reg_number) == false)//本科占比
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("（本科占比）格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_13->text().toLocal8Bit()), reg_number) == false)//非本科占比
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("（非本科占比）格式错误！").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_14->text().toLocal8Bit()), reg_number) == false)//本科以上占比
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("（本科以上占比）格式错误！").c_str()));
			return;
		}

		m_sql.search(
			"SELECT * FROM mechanism_info WHERE mechanism_id="+
			APOSTROPHE + string(ui.lineEdit_team_name_2->text().toLocal8Bit()) + APOSTROPHE+" OR "
			"login_name="+ APOSTROPHE + string(ui.lineEdit_team_name_16->text().toLocal8Bit()) + APOSTROPHE+";"
		);
		if (m_sql.getRows())
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("机构编号或登录账户存在！").c_str()));
			return;
		}
		if (!m_sql.query(
			"INSERT INTO mechanism_info("
			"mechanism_id,"
			"mechanism_name,"
			"mechanism_introduce,"
			"address,"
			"type,"
			"register,"
			"id_card,"
			"phone,"
			"email,"
			"status,"
			"path_id,"
			"count,"
			"male_rate,"
			"female_rate,"
			"RCC_rate,"
			"non_RCC_rate,"
			"more_RCC,"
			"mark,"
			"path_logo,"
			"login_name,"
			"login_passwd)"
			"VALUES(" +
			APOSTROPHE + string(ui.lineEdit_team_name_2->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_3->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.plainTextEdit->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_4->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.comboBox_province_2->currentText().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_5->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_6->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_7->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_8->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.comboBox_province_3->currentText().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + path_id + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_9->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_10->text().toLocal8Bit() + "%") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_11->text().toLocal8Bit() + "%") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_12->text().toLocal8Bit() + "%") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_13->text().toLocal8Bit() + "%") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_14->text().toLocal8Bit() + "%") + APOSTROPHE + "," +
			APOSTROPHE + string(ui.plainTextEdit_2->toPlainText().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + path_logo + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_16->text().toLocal8Bit()) + APOSTROPHE + "," +
			APOSTROPHE + string(ui.lineEdit_team_name_15->text().toLocal8Bit()) + APOSTROPHE +
			");"
		))
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("插入失败！原因："+m_sql.error()).c_str()));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(string("注册成功！").c_str()));
			ui.stackedWidget->setCurrentIndex(0);
		}
		
	}
	);
}
