#include "PATable.h"

#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>

PATable::PATable(string _mechanism_id, string _pa_type,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	mechanism_id = _mechanism_id;
	pa_type =_pa_type;

	initMembers();
	connectMembers();

}

PATable::PATable(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);
	ui.pushButton_login_2->hide();
	ui.label_name_113->show();

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

PATable::~PATable()
{
}

void PATable::initMembers()
{
	setWindowTitle(QString::fromLocal8Bit("考核表"));

	m_sql.init();

	ui.pushButton_login_2->show();
	ui.label_name_113->hide();

	//初始表格信息
	m_sql.search(
		"SELECT a.mechanism_id,a.mechanism_name,a.type,a.path_logo,b.type,b.date,b.is_write FROM mechanism_info AS a,pa_level_result AS b WHERE a.mechanism_id=b.mechanism_id AND"
		" b.mechanism_id ="+APOSTROPHE+mechanism_id+APOSTROPHE+";"
	);
	if (m_sql.getRows())
	{
		//标题
		ui.label_name_team_name->setText(QString::fromLocal8Bit(string(
			m_sql.getRowDatas()[0][1] + "——" + "绩效考核表("+ m_sql.getRowDatas()[0][4] +")"
		).c_str()));
		//周期
		ui.label_name_34->setText(QString::fromLocal8Bit(string(
			m_sql.getRowDatas()[0][5] + "  " + m_sql.getRowDatas()[0][4]
		).c_str()));
		//被考核的机构受理编号
		ui.label_name_35->setText(QString::fromLocal8Bit(string(
			m_sql.getRowDatas()[0][0]
		).c_str()));
		//被考核的机构名称
		ui.label_name_38->setText(QString::fromLocal8Bit(string(
			m_sql.getRowDatas()[0][1]
		).c_str()));
		//被考核的机构类型
		ui.label_name_111->setText(QString::fromLocal8Bit(string(
			m_sql.getRowDatas()[0][2]
		).c_str()));
		//LOGO
		if (m_sql.getRowDatas()[0][3].compare("")==0)
		{
			ui.label_name_logo_2->setText(QString::fromLocal8Bit("未上传"));
		} else
		{
			ui.label_name_logo_2->setPixmap(QPixmap(m_sql.getRowDatas()[0][3].c_str()));
		}

		//设置基数
		if (m_sql.getRowDatas()[0][4].compare("月度考核")==0)
		{
			base_day = 31.f;
		}else if (m_sql.getRowDatas()[0][4].compare("季度考核") == 0)
		{
			base_day = 90.f;
		}else if (m_sql.getRowDatas()[0][4].compare("半年度考核") == 0)
		{
			base_day = 180.f;
		} else if (m_sql.getRowDatas()[0][4].compare("年度考核") == 0)
		{
			base_day = 365.f;
		}

		//查看是否填写过
		if (m_sql.getRowDatas()[0][6].compare("否") == 0)
		{
			ui.pushButton_login_2->setEnabled(true);
		} else
		{
			ui.pushButton_login_2->setEnabled(false);
		}

	}

	//背景
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

void PATable::connectMembers()
{
	/***************** QPushButton ******************/
	connect(ui.pushButton_login_2,&QPushButton::clicked,//提交
		[=]()mutable
	{
		if (!isInput())
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("有空或输入错误！"));
			return;
		}

		float complaints_rate;//投诉率
		float norm_rate;//手续规范性 错误率
		float loan_efficiency_rate;//发放贷款效率等级 错误率
		float muster_error_rate;//归集出错率
		float loan_error_rate;//贷款出错率
		float get_muster_rate;//归集资金到账率
		float get_loan_rate;//贷款资金到账率
		float net_save_error_rate;//网络缴存出错率
		float net_get_error_rate;//网络提取错误率
		float net_loan_error_rata;//网络贷款出错率
		float net_return_error_rate;//网络还款错误率
		float net_over_error_rate;//网络逾期出错率
		float net_time_rate;//网络负时效

		complaints_rate = lexical_cast<float>(string(ui.lineEdit->text().toLocal8Bit()))/
			lexical_cast<float>(string(ui.lineEdit_3->text().toLocal8Bit()))*100;
		norm_rate = lexical_cast<float>(string(ui.lineEdit_2->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_3->text().toLocal8Bit())) * 100;
		loan_efficiency_rate = lexical_cast<float>(string(ui.lineEdit_4->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_5->text().toLocal8Bit())) * 100;
		muster_error_rate = lexical_cast<float>(string(ui.lineEdit_6->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_8->text().toLocal8Bit())) * 100;
		loan_error_rate = lexical_cast<float>(string(ui.lineEdit_7->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_11->text().toLocal8Bit())) * 100;
		get_muster_rate = lexical_cast<float>(string(ui.lineEdit_9->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_10->text().toLocal8Bit())) * 100;
		get_loan_rate = lexical_cast<float>(string(ui.lineEdit_12->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_13->text().toLocal8Bit())) * 100;
		net_save_error_rate = lexical_cast<float>(string(ui.lineEdit_14->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_16->text().toLocal8Bit())) * 100;
		net_get_error_rate = lexical_cast<float>(string(ui.lineEdit_15->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_19->text().toLocal8Bit())) * 100;
		net_loan_error_rata = lexical_cast<float>(string(ui.lineEdit_17->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_18->text().toLocal8Bit())) * 100;
		net_return_error_rate = lexical_cast<float>(string(ui.lineEdit_20->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_21->text().toLocal8Bit())) * 100;
		net_over_error_rate = lexical_cast<float>(string(ui.lineEdit_22->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_23->text().toLocal8Bit())) * 100;
		net_time_rate = lexical_cast<float>(string(ui.lineEdit_25->text().toLocal8Bit())) /
			lexical_cast<float>(string(ui.lineEdit_24->text().toLocal8Bit())) * 100;

		/********** 评级 ********/
		//投诉率
		if (complaints_rate >= 0.f && complaints_rate <=1.f)
		{
			complaints_level = "A";
			++pa_count;
		}else if (complaints_rate > 1.f && complaints_rate <= 3.f)
		{
			complaints_level = "B";
		} else if (complaints_rate > 3.f && complaints_rate < 5.f)
		{
			complaints_level = "C";
		} else
		{
			complaints_level = "D";
		}
		//手续规范性
		if (norm_rate >= 0.f && norm_rate <= 1.f)
		{
			norm_level = "A";
			++pa_count;
		} else if (norm_rate > 1.f && norm_rate <= 3.f)
		{
			norm_level = "B";
		} else if (norm_rate > 3.f && norm_rate < 5.f)
		{
			norm_level = "C";
		} else
		{
			norm_level = "D";
		}
		//发放贷款效率
		if (loan_efficiency_rate >= 0.f && loan_efficiency_rate <= 1.f)
		{
			loan_efficiency_level = "A";
			++pa_count;
		} else if (loan_efficiency_rate > 1.f && loan_efficiency_rate <= 3.f)
		{
			loan_efficiency_level = "B";
		} else if (loan_efficiency_rate > 3.f && loan_efficiency_rate < 5.f)
		{
			loan_efficiency_level = "C";
		} else
		{
			loan_efficiency_level = "D";
		}
		//归集出错率
		if (muster_error_rate >= 0.f && muster_error_rate <= 1.f)
		{
			muster_error_rate_level = "A";
			++pa_count;
		} else if (muster_error_rate > 1.f && muster_error_rate <= 1.5f)
		{
			muster_error_rate_level = "B";
		} else if (muster_error_rate > 1.5f && muster_error_rate < 3.f)
		{
			muster_error_rate_level = "C";
		} else
		{
			muster_error_rate_level = "D";
		}
		//贷款出错率
		if (loan_error_rate >= 0.f && loan_error_rate <= 1.f)
		{
			loan_error_rate_level = "A";
			++pa_count;
		} else if (loan_error_rate > 1.f && loan_error_rate <= 1.5f)
		{
			loan_error_rate_level = "B";
		} else if (loan_error_rate > 1.5f && loan_error_rate < 3.f)
		{
			loan_error_rate_level = "C";
		} else
		{
			loan_error_rate_level = "D";
		}
		//归集资金到账率
		if (get_muster_rate ==100.f )
		{
			get_muster_rate_level = "A";
			++pa_count;
		} else if (get_muster_rate < 100.f && get_muster_rate > 98.f)
		{
			get_muster_rate_level = "B";
		} else if (get_muster_rate  <=98.f && get_muster_rate > 95.f)
		{
			get_muster_rate_level = "C";
		} else
		{
			get_muster_rate_level = "D";
		}
		//贷款资金到账率
		if (get_loan_rate == 100.f)
		{
			get_loan_rate_level = "A";
			++pa_count;
		} else if (get_loan_rate < 100.f && get_loan_rate > 95.f)
		{
			get_loan_rate_level = "B";
		} else if (get_loan_rate <= 95.f && get_loan_rate > 92.f)
		{
			get_loan_rate_level = "C";
		} else
		{
			get_loan_rate_level = "D";
		}
		//网络缴存出错率
		if (net_save_error_rate >=0.f &&  net_save_error_rate < 10.f)
		{
			net_save_error_rate_level = "A";
			++pa_count;
		} else if (net_save_error_rate >=10.f && net_save_error_rate < 30.f)
		{
			net_save_error_rate_level = "B";
		} else if (net_save_error_rate >= 30.f && net_save_error_rate < 50.f)
		{
			net_save_error_rate_level = "C";
		} else
		{
			net_save_error_rate_level = "D";
		}
		//网络提取错误率
		if (net_get_error_rate >= 0.f &&  net_get_error_rate < 10.f)
		{
			net_get_error_rate_level = "A";
			++pa_count;
		} else if (net_get_error_rate >= 10.f && net_get_error_rate < 30.f)
		{
			net_get_error_rate_level = "B";
		} else if (net_get_error_rate >= 30.f && net_get_error_rate < 50.f)
		{
			net_get_error_rate_level = "C";
		} else
		{
			net_get_error_rate_level = "D";
		}
		//网络贷款出错率
		if (net_loan_error_rata >= 0.f &&  net_loan_error_rata < 10.f)
		{
			net_loan_error_rata_level = "A";
			++pa_count;
		} else if (net_loan_error_rata >= 10.f && net_loan_error_rata < 30.f)
		{
			net_loan_error_rata_level = "B";
		} else if (net_loan_error_rata >= 30.f && net_loan_error_rata < 50.f)
		{
			net_loan_error_rata_level = "C";
		} else
		{
			net_loan_error_rata_level = "D";
		}
		//网络还款错误率
		if (net_return_error_rate >= 0.f &&  net_return_error_rate < 10.f)
		{
			net_return_error_rate_level = "A";
			++pa_count;
		} else if (net_return_error_rate >= 10.f && net_return_error_rate < 30.f)
		{
			net_return_error_rate_level = "B";
		} else if (net_return_error_rate >= 30.f && net_return_error_rate < 50.f)
		{
			net_return_error_rate_level = "C";
		} else
		{
			net_return_error_rate_level = "D";
		}
		//网络逾期出错率
		if (net_over_error_rate >= 0.f &&  net_over_error_rate < 10.f)
		{
			net_over_error_rate_level = "A";
			++pa_count;
		} else if (net_over_error_rate >= 10.f && net_over_error_rate < 30.f)
		{
			net_over_error_rate_level = "B";
		} else if (net_over_error_rate >= 30.f && net_over_error_rate < 50.f)
		{
			net_over_error_rate_level = "C";
		} else
		{
			net_over_error_rate_level = "D";
		}
		//网络负时效错误率
		if (net_time_rate >= 0.f &&  net_time_rate < 10.f)
		{
			net_time_level = "A";
			++pa_count;
		} else if (net_time_rate >= 10.f && net_time_rate < 30.f)
		{
			net_time_level = "B";
		} else if (net_time_rate >= 30.f && net_time_rate < 50.f)
		{
			net_time_level = "C";
		} else
		{
			net_time_level = "D";
		}

		if (pa_count<=13 && pa_count >11)
		{
			result_level = "A";
		}else if (pa_count == 11)
		{
			result_level = "B";
		} else if (pa_count == 10)
		{
			result_level = "C";
		} else
		{
			result_level = "D";
		}

		COUT "投诉率：" LK complaints_rate LK "%" LK "等级：" LK complaints_level LN;
		COUT "手续规范性 错误率：" LK norm_rate LK "%" LK "等级：" LK norm_level LN;
		COUT "发放贷款效率等级 错误率：" LK loan_efficiency_rate LK "%" LK "等级：" LK loan_efficiency_level  LN;
		COUT "归集出错率：" LK muster_error_rate LK "%" LK "等级：" LK muster_error_rate_level  LN;
		COUT "贷款出错率：" LK loan_error_rate LK "%" LK "等级：" LK loan_error_rate_level  LN;
		COUT "归集资金到账率：" LK get_muster_rate LK "%" LK "等级：" LK get_muster_rate_level  LN;
		COUT "贷款资金到账率：" LK get_loan_rate LK "%" LK "等级：" LK get_loan_rate_level  LN;
		COUT "网络缴存出错率：" LK net_save_error_rate LK "%" LK "等级：" LK net_save_error_rate_level  LN;
		COUT "网络提取错误率：" LK net_get_error_rate LK "%" LK "等级：" LK net_get_error_rate_level  LN;
		COUT "网络贷款出错率：" LK net_loan_error_rata LK "%" LK "等级：" LK net_loan_error_rata_level  LN;
		COUT "网络还款错误率：" LK net_return_error_rate LK "%" LK "等级：" LK net_return_error_rate_level  LN;
		COUT "网络逾期出错率：" LK net_over_error_rate LK "%" LK "等级：" LK net_over_error_rate_level  LN;
		COUT " 网络负时效错误率：" LK net_time_rate LK "%" LK "等级：" LK net_time_level  LN;
		COUT_LN;
		COUT "总评级：" LK result_level LN;
		COUT_LN;

		submit();


	}
		);
}

bool PATable::isInput()
{
	bool ret = false;

	regex reg_number(str_number);

	if (ui.lineEdit_3->text().isEmpty() ||
		ui.lineEdit->text().isEmpty() ||
		ui.lineEdit_2->text().isEmpty() ||
		ui.lineEdit_5->text().isEmpty() ||
		ui.lineEdit_4->text().isEmpty() ||
		ui.lineEdit_8->text().isEmpty() ||
		ui.lineEdit_6->text().isEmpty() ||
		ui.lineEdit_11->text().isEmpty() ||
		ui.lineEdit_7->text().isEmpty() ||
		ui.lineEdit_10->text().isEmpty() ||
		ui.lineEdit_9->text().isEmpty() ||
		ui.lineEdit_13->text().isEmpty() ||
		ui.lineEdit_12->text().isEmpty() ||
		ui.lineEdit_16->text().isEmpty() ||
		ui.lineEdit_14->text().isEmpty() ||
		ui.lineEdit_19->text().isEmpty() ||
		ui.lineEdit_15->text().isEmpty() ||
		ui.lineEdit_18->text().isEmpty() ||
		ui.lineEdit_17->text().isEmpty() ||
		ui.lineEdit_21->text().isEmpty() ||
		ui.lineEdit_20->text().isEmpty() ||
		ui.lineEdit_23->text().isEmpty() ||
		ui.lineEdit_22->text().isEmpty() ||
		ui.lineEdit_24->text().isEmpty() ||
		ui.lineEdit_25->text().isEmpty() ||
		regex_match(string(ui.lineEdit_3->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_2->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_5->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_4->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_8->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_6->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_11->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_7->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_10->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_9->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_13->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_12->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_16->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_14->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_19->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_15->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_18->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_17->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_21->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_20->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_23->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_22->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_24->text().toLocal8Bit()), reg_number) == false ||
		regex_match(string(ui.lineEdit_25->text().toLocal8Bit()), reg_number) == false 
		)
	{
		ret = false;
	} else
	{
		ret = true;
	}

	return ret;
}

void PATable::submit()
{
	int ret = QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("确认无误？提交之后不可更改！）"), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Ok)
	{
		//保存等级
		m_sql.search(
			"SELECT * FROM pa_each_level WHERE mechanism_id=" +
			APOSTROPHE + mechanism_id + APOSTROPHE + ";"
		);
		if (m_sql.getRows() == 0)//未添加
		{
			if (m_sql.query(
				"INSERT INTO pa_each_level("
				"mechanism_id,"
				"mechanism_name,"
				"check_type,"
				"complaints_level,"
				"norm_level,"
				"loan_efficiency_level,"
				"muster_error_rate_level,"
				"loan_error_rate_level,"
				"get_muster_rate_level,"
				"get_loan_rate_level,"
				"net_save_error_rate_level,"
				"net_get_error_rate_level,"
				"net_loan_error_rata_level,"
				"net_return_error_rate_level,"
				"net_over_error_rate_level,"
				"net_time_level,"
				"result_level)"
				"vALUES(" +
				APOSTROPHE + mechanism_id + APOSTROPHE + "," +
				APOSTROPHE + string(ui.label_name_38->text().toLocal8Bit()) + APOSTROPHE + "," +
				APOSTROPHE + pa_type + APOSTROPHE + "," +
				APOSTROPHE + complaints_level + APOSTROPHE + "," +
				APOSTROPHE + norm_level + APOSTROPHE + "," +
				APOSTROPHE + loan_efficiency_level + APOSTROPHE + "," +
				APOSTROPHE + muster_error_rate_level + APOSTROPHE + "," +
				APOSTROPHE + loan_error_rate_level + APOSTROPHE + "," +
				APOSTROPHE + get_muster_rate_level + APOSTROPHE + "," +
				APOSTROPHE + get_loan_rate_level + APOSTROPHE + "," +
				APOSTROPHE + net_save_error_rate_level + APOSTROPHE + "," +
				APOSTROPHE + net_get_error_rate_level + APOSTROPHE + "," +
				APOSTROPHE + net_loan_error_rata_level + APOSTROPHE + "," +
				APOSTROPHE + net_return_error_rate_level + APOSTROPHE + "," +
				APOSTROPHE + net_over_error_rate_level + APOSTROPHE + "," +
				APOSTROPHE + net_time_level + APOSTROPHE + "," +
				APOSTROPHE + result_level + APOSTROPHE +
				");"
			))
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("提交成功!"));
				ui.pushButton_login_2->setEnabled(false);
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("提交失败！原因：" + m_sql.error()).c_str()));
			}
		} else//修改
		{
			if (m_sql.query(
				"UPDATE pa_each_level SET "
				"check_type=" + APOSTROPHE + pa_type + APOSTROPHE + "," +
				"complaints_level=" + APOSTROPHE + complaints_level + APOSTROPHE + "," +
				"norm_level=" + APOSTROPHE + norm_level + APOSTROPHE + "," +
				"loan_efficiency_level=" + APOSTROPHE + loan_efficiency_level + APOSTROPHE + "," +
				"muster_error_rate_level=" + APOSTROPHE + muster_error_rate_level + APOSTROPHE + "," +
				"loan_error_rate_level=" + APOSTROPHE + loan_error_rate_level + APOSTROPHE + "," +
				"get_muster_rate_level=" + APOSTROPHE + get_muster_rate_level + APOSTROPHE + "," +
				"get_loan_rate_level=" + APOSTROPHE + get_loan_rate_level + APOSTROPHE + "," +
				"net_save_error_rate_level=" + APOSTROPHE + net_save_error_rate_level + APOSTROPHE + "," +
				"net_get_error_rate_level=" + APOSTROPHE + net_get_error_rate_level + APOSTROPHE + "," +
				"net_loan_error_rata_level=" + APOSTROPHE + net_loan_error_rata_level + APOSTROPHE + "," +
				"net_return_error_rate_level=" + APOSTROPHE + net_return_error_rate_level + APOSTROPHE + "," +
				"net_over_error_rate_level=" + APOSTROPHE + net_over_error_rate_level + APOSTROPHE + "," +
				"net_time_level=" + APOSTROPHE + net_time_level + APOSTROPHE + "," +
				"result_level=" + APOSTROPHE + result_level + APOSTROPHE +
				" WHERE mechanism_id=" + APOSTROPHE + mechanism_id + APOSTROPHE + ";"
			))
			{
				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("提交成功!"));
				ui.pushButton_login_2->setEnabled(false);
			} else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(string("提交失败！原因：" + m_sql.error()).c_str()));
			}

		}
	}

	//把状态更新为 已写
	m_sql.query(
		"UPDATE pa_level_result SET is_write='是' WHERE mechanism_id="+
		APOSTROPHE + mechanism_id + APOSTROPHE +";"
	);
}
