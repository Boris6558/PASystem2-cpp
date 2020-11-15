#pragma once

#include <QWidget>
#include "ui_PATable.h"

#include <cstring>
#include <string>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

#include "MSql.h"
#include "Good.h"

using namespace boost;

class PATable : public QWidget
{
	Q_OBJECT

public:
	PATable(string _mechanism_id,string _pa_type,QWidget *parent = Q_NULLPTR);
	PATable(QWidget *parent = Q_NULLPTR);
	~PATable();

private:
	Ui::PATable ui;

public:
	void initMembers();
	void connectMembers();
	bool isInput();
	void submit();//提交数据

private:
	MSql m_sql;

	string mechanism_id;
	string pa_type;

	float base_day;//根据月度，年度，半年度，季度来设置天数基数

	string complaints_level;//投诉率 等级 
	string norm_level;//手续规范性 错误率
	string loan_efficiency_level;//发放贷款效率等级 错误率
	string muster_error_rate_level;//归集出错率等级
	string loan_error_rate_level;//贷款出错率等级
	string get_muster_rate_level;//归集资金到账率等级
	string get_loan_rate_level;//贷款资金到账率等级
	string net_save_error_rate_level;//网络缴存出错率等级
	string net_get_error_rate_level;//网络提取错误率等级
	string net_loan_error_rata_level;//网络贷款出错率
	string net_return_error_rate_level;//网络还款错误率
	string net_over_error_rate_level;//网络逾期出错率
	string net_time_level;//网络负时效等级

	string result_level;//最总评级

	/*总共有13个指标
	总评级：
		13个全是A才是A
		11个A 降为 B
		10个A 降为 C
		否则就是 D
	*/
	int pa_count = 0;
	string str_number = "^\\d{1,}$";//数字
};
