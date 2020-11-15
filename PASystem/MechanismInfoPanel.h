#pragma once

#include <QWidget>
#include <QAction>

#include <cstring>
#include <string>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

#include "ui_MechanismInfoPanel.h"
#include "MSql.h"
#include "Good.h"
#include "PATable.h"
#include "PAResult.h"
#include "FeedBack.h"
#include "HREcruitmentInfo.h"

using namespace boost;

class MechanismInfoPanel : public QWidget
{
	Q_OBJECT

public:
	MechanismInfoPanel(QWidget *parent = Q_NULLPTR);
	~MechanismInfoPanel();

private:
	Ui::MechanismInfoPanel ui;

public:
	void initMembers();
	void connectMembers();
	void showMechanismInfo();
	void showHR();
	void showContractManager();
	void showSee();
	void showSet();
	void findEmpInfoFromTable(string & str, QTableWidget *widget);
	void freshSeeInfo();//刷新查看面板

private:
	MSql m_sql;

	property_tree::ptree pt;

	string path_positive="";
	string path_signature="";

	POINTER_INIT(FeedBack, fb);//删除合同

	POINTER_INIT(QAction, contract_del);//删除合同
	POINTER_INIT(QAction, contract_re);//恢复合同

	POINTER_INIT(PATable, m_table);//绩效考核表
	POINTER_INIT(PAResult, m_result);//查看考核结果
	POINTER_INIT(HREcruitmentInfo, m_hr_info);//招聘信息

	int c_row;//当前选择第几行
	string c_ctract_id;//当前选择行的合同号

	string str_number = "^\\d{1,}$";//数字
};
