#pragma once

#include <QtWidgets/QWidget>
#include "ui_PASystem.h"

#include <cstring>
#include <string>

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

#include "Good.h"
#include "MSql.h"
#include "MLabel.h"
#include "MechanismInfoPanel.h"
#include "BackManagerPanel.h"

using namespace boost;

typedef char RegisterName[64];

class PASystem : public QWidget
{
	Q_OBJECT

public:
	PASystem(QWidget *parent = Q_NULLPTR);

private:
	Ui::PASystemClass ui;

public:
	void initMembers();
	void connectMembers();

private:
	MSql m_sql;

	//ע��
	string path_id="";//��������֤·��
	string path_logo = "";//logo·��

	property_tree::ptree pt;

	POINTER_INIT(MechanismInfoPanel, m_mp);//������Ϣ���
	POINTER_INIT(BackManagerPanel, m_bmp);//������Ϣ���

	//������ʽ
	string str_mechanism_id="^\\d{6}-\\d{6}$";//����id
	string str_man_id = "(^\\d{15}$)|(^\\d{17}([0-9]|X)$)";//���֤
	string str_phone = //�绰����
		"^1(3\\d|47|5([0-3]|[5-9])|8(0|2|[5-9]))\\d{8}$";
	string str_email = //����
		"^([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)$";
	string str_number = "^\\d{1,}$";//����

};
