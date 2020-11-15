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
	setWindowTitle(QString::fromLocal8Bit("���ڻ�����Ч����ϵͳ��ƺ�ʵ��"));

	m_sql.init();

	ui.stackedWidget->setCurrentIndex(0);

	ui.checkBox_auto_login_2->hide();
	ui.label_forget_passwd_2->hide();

	ui.label_provision_2->setText(QString::fromLocal8Bit(string(
		"<a href=\""
		"http://www.gov.cn/gongbao/content/2017/content_5213211.htm"
		"\">��ͬ��Bingood�������"
	).c_str()));
	
	//��ס����
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

	/*********** ���� ***********/
	//����
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(login_back.jpg))));
	setPalette(pal);
	//LOGO
	ui.label->setText("");
	ui.label->setPixmap(QPixmap(PATH_IMG(LOGO.png)));
	ui.label->setFrameShape(QFrame::NoFrame);

	//ͼ�� �˻�������
	ui.label_3->setPixmap(QPixmap(PATH_IMG(icons8_user_male_26px.png)));
	ui.label_4->setPixmap(QPixmap(PATH_IMG(icons8_password_26px.png)));
	
}

void PASystem::connectMembers()
{
	/***********************  QCheckBox ****************************/
	connect(ui.checkBox_remember_passwd_2, &QCheckBox::stateChanged,//��ס����
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
	connect(ui.label_register_2, &MLabel::sigClick,//ע��
		[=]()mutable
	{
		COUT string(ui.label_register_2->text().toLocal8Bit()) LN;

		ui.stackedWidget->setCurrentWidget(ui.page_register_2);
	}
	);
	connect(ui.label_forget_passwd_2, &MLabel::sigClick,//��������
		[=]()mutable
	{
		COUT string(ui.label_forget_passwd_2->text().toLocal8Bit()) LN;
	}
	);
	connect(ui.label_provision_2, &MLabel::sigClick,//ע������
		[=]()mutable
	{
		COUT string(ui.label_provision_2->text().toLocal8Bit()) LN;
	}
	);

	/***********************  QPushButton ****************************/
	connect(ui.pushButton_back_2, &QPushButton::clicked,//����
		[=]()mutable
	{
		COUT string(ui.pushButton_back_2->text().toLocal8Bit()) LN;

		ui.stackedWidget->setCurrentIndex(ui.stackedWidget->currentIndex() - 1);
	}
	);
	/***********************  QPushButton ****************************/
	connect(ui.pushButton_login_2, &QPushButton::clicked,//��¼
		[=]()mutable
	{
		string c_login_name = string(ui.lineEdit_login_name_2->text().toLocal8Bit());
		string c_login_passwd = string(ui.lineEdit_login_passwd_2->text().toLocal8Bit());
		//�ж�ʱ��Ч����Ա��½���ǻ�����¼
		m_sql.search(
			"SELECT login_passwd FROM admin_acc WHERE login_name="+APOSTROPHE+c_login_name+APOSTROPHE+";"
		);
		if (m_sql.getRows())//����Ա�˺��ҵ�
		{
			if (m_sql.getRowDatas()[0][0].compare(c_login_passwd)==0)//��Ч���˹���Ա��¼
			{
				POINTER_INS(m_bmp, BackManagerPanel);
				m_bmp->show();
				SET_NULL(m_bmp);
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������"));
			}
		} else//�һ����˺�
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
					//������¼
					POINTER_INS(m_mp, MechanismInfoPanel);
					m_mp->show();
					SET_NULL(m_mp);
				} else
				{
					QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������"));
				}
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���˺�û��ע�ᣡ"));
			}
				
		}
	}
	);
	connect(ui.pushButton, &QPushButton::clicked,//�ϴ� ���ڻ�������֤
		[=]()mutable
	{
		path_id = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("�ϴ�ͷ��"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_5->setPixmap(QPixmap(QString(path_id.c_str())));
	}
	);
	connect(ui.pushButton_2, &QPushButton::clicked,//�ϴ� ��˾logo
		[=]()mutable
	{
		path_logo = QFileDialog::getOpenFileName(this,
			QString::fromLocal8Bit("�ϴ�ͷ��"),
			"./",
			"image(*.png *.jpeg *.jpg *.bmp)").toLocal8Bit().toStdString();
		ui.label_6->setPixmap(QPixmap(QString(path_logo.c_str())));
	}
	);
	connect(ui.pushButton_3, &QPushButton::clicked,//ע��
		[=]()mutable
	{
		regex reg_mechanism_id(str_mechanism_id);
		regex reg_man_id(str_man_id);
		regex reg_phone(str_phone);
		regex reg_email(str_email);
		regex reg_number(str_number);

		//�Ƿ�ѡ����
		if (!ui.checkBox_2->isChecked())
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("ʧ�ܣ��빴ѡ������").c_str()));
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
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("ʧ�ܣ����������Ƿ��пջ��߻�������֤�Ƿ��ϴ���").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_2->text().toLocal8Bit()), reg_mechanism_id)==false)//�������
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("������Ŵ��󣡸�ʽ��123456-123456").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_6->text().toLocal8Bit()), reg_man_id) == false)//���֤
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("���֤��ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_7->text().toLocal8Bit()), reg_phone) == false)//�绰
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("�绰��ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_8->text().toLocal8Bit()), reg_email) == false)//����
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("�����ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_9->text().toLocal8Bit()), reg_number) == false)//������
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("��������һ������ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_10->text().toLocal8Bit()), reg_number) == false)//����ռ��
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("������ռ�ȣ���ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_11->text().toLocal8Bit()), reg_number) == false)//Ů��ռ��
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("��Ů��ռ�ȣ���ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_12->text().toLocal8Bit()), reg_number) == false)//����ռ��
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("������ռ�ȣ���ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_13->text().toLocal8Bit()), reg_number) == false)//�Ǳ���ռ��
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("���Ǳ���ռ�ȣ���ʽ����").c_str()));
			return;
		} else if (regex_match(string(ui.lineEdit_team_name_14->text().toLocal8Bit()), reg_number) == false)//��������ռ��
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("����������ռ�ȣ���ʽ����").c_str()));
			return;
		}

		m_sql.search(
			"SELECT * FROM mechanism_info WHERE mechanism_id="+
			APOSTROPHE + string(ui.lineEdit_team_name_2->text().toLocal8Bit()) + APOSTROPHE+" OR "
			"login_name="+ APOSTROPHE + string(ui.lineEdit_team_name_16->text().toLocal8Bit()) + APOSTROPHE+";"
		);
		if (m_sql.getRows())
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("������Ż��¼�˻����ڣ�").c_str()));
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
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("����ʧ�ܣ�ԭ��"+m_sql.error()).c_str()));
		} else
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(string("ע��ɹ���").c_str()));
			ui.stackedWidget->setCurrentIndex(0);
		}
		
	}
	);
}
