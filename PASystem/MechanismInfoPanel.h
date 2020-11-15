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
	void freshSeeInfo();//ˢ�²鿴���

private:
	MSql m_sql;

	property_tree::ptree pt;

	string path_positive="";
	string path_signature="";

	POINTER_INIT(FeedBack, fb);//ɾ����ͬ

	POINTER_INIT(QAction, contract_del);//ɾ����ͬ
	POINTER_INIT(QAction, contract_re);//�ָ���ͬ

	POINTER_INIT(PATable, m_table);//��Ч���˱�
	POINTER_INIT(PAResult, m_result);//�鿴���˽��
	POINTER_INIT(HREcruitmentInfo, m_hr_info);//��Ƹ��Ϣ

	int c_row;//��ǰѡ��ڼ���
	string c_ctract_id;//��ǰѡ���еĺ�ͬ��

	string str_number = "^\\d{1,}$";//����
};
