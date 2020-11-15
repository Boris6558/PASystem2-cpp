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

	//注册
	string path_id="";//机构代码证路径
	string path_logo = "";//logo路径

	property_tree::ptree pt;

	POINTER_INIT(MechanismInfoPanel, m_mp);//机构信息面板
	POINTER_INIT(BackManagerPanel, m_bmp);//机构信息面板

	//正则表达式
	string str_mechanism_id="^\\d{6}-\\d{6}$";//机构id
	string str_man_id = "(^\\d{15}$)|(^\\d{17}([0-9]|X)$)";//身份证
	string str_phone = //电话号码
		"^1(3\\d|47|5([0-3]|[5-9])|8(0|2|[5-9]))\\d{8}$";
	string str_email = //邮箱
		"^([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)$";
	string str_number = "^\\d{1,}$";//数字

};
