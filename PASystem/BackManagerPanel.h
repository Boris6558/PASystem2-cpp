#pragma once

#include <QWidget>
#include "ui_BackManagerPanel.h"

#include <cstring>
#include <string>
#include <QTableWidget>
#include <QAction>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

#include <vector>

#include "MSql.h"
#include "Good.h"
#include "PAType.h"
#include "PATable.h"
#include "PAResult.h"
#include "HelpMeDecision.h"
#include "MechanismDetail.h"
#include "SeeFeedBack.h"

using namespace boost;
using namespace boost::assign;

class BackManagerPanel : public QWidget
{
	Q_OBJECT

public:
	BackManagerPanel(QWidget *parent = Q_NULLPTR);
	~BackManagerPanel();

private:
	Ui::BackManagerPanel ui;

public:
	void initMembers();
	void connectMembers();
	void findEmpInfoFromTable(string & str, QTableWidget *widget);
	void freshSeeInfo();//刷新查看面板

private:
	MSql m_sql;

	property_tree::ptree pt;

	POINTER_INIT(SeeFeedBack, m_sfb);//反馈信息

	POINTER_INIT(QAction, m_detail);//详情
	POINTER_INIT(QAction, m_pa);//发起绩效考核(单个机构)
	POINTER_INIT(QAction, m_revoke);//吊销机构

	POINTER_INIT(PAType, m_pa_type);//考核类型选择
	POINTER_INIT(PATable, m_table);//考核样式表
	POINTER_INIT(PAResult, m_result);//查看考核结果
	POINTER_INIT(HelpMeDecision, m_hmd);//辅助决策
	POINTER_INIT(MechanismDetail, m_md);//机构详情面板

	int c_row;//当前选择第几行
	string c_mechanism_id;//当前选择行的机构编号
	string c_mechanism_name;//当前选择行的机构名称

	vector<string> v_all_id;//保存所有机构编号 用来发起全体绩效考核
	vector<string> v_all_name;//保存所有机构名称 用来发起全体绩效考核

};
