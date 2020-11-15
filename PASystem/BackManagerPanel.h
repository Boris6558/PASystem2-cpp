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
	void freshSeeInfo();//ˢ�²鿴���

private:
	MSql m_sql;

	property_tree::ptree pt;

	POINTER_INIT(SeeFeedBack, m_sfb);//������Ϣ

	POINTER_INIT(QAction, m_detail);//����
	POINTER_INIT(QAction, m_pa);//����Ч����(��������)
	POINTER_INIT(QAction, m_revoke);//��������

	POINTER_INIT(PAType, m_pa_type);//��������ѡ��
	POINTER_INIT(PATable, m_table);//������ʽ��
	POINTER_INIT(PAResult, m_result);//�鿴���˽��
	POINTER_INIT(HelpMeDecision, m_hmd);//��������
	POINTER_INIT(MechanismDetail, m_md);//�����������

	int c_row;//��ǰѡ��ڼ���
	string c_mechanism_id;//��ǰѡ���еĻ������
	string c_mechanism_name;//��ǰѡ���еĻ�������

	vector<string> v_all_id;//�������л������ ��������ȫ�弨Ч����
	vector<string> v_all_name;//�������л������� ��������ȫ�弨Ч����

};
