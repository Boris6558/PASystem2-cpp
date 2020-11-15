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
	void submit();//�ύ����

private:
	MSql m_sql;

	string mechanism_id;
	string pa_type;

	float base_day;//�����¶ȣ���ȣ�����ȣ�������������������

	string complaints_level;//Ͷ���� �ȼ� 
	string norm_level;//�����淶�� ������
	string loan_efficiency_level;//���Ŵ���Ч�ʵȼ� ������
	string muster_error_rate_level;//�鼯�����ʵȼ�
	string loan_error_rate_level;//��������ʵȼ�
	string get_muster_rate_level;//�鼯�ʽ����ʵȼ�
	string get_loan_rate_level;//�����ʽ����ʵȼ�
	string net_save_error_rate_level;//����ɴ�����ʵȼ�
	string net_get_error_rate_level;//������ȡ�����ʵȼ�
	string net_loan_error_rata_level;//������������
	string net_return_error_rate_level;//���绹�������
	string net_over_error_rate_level;//�������ڳ�����
	string net_time_level;//���縺ʱЧ�ȼ�

	string result_level;//��������

	/*�ܹ���13��ָ��
	��������
		13��ȫ��A����A
		11��A ��Ϊ B
		10��A ��Ϊ C
		������� D
	*/
	int pa_count = 0;
	string str_number = "^\\d{1,}$";//����
};
