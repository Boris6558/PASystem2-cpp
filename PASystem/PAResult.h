#pragma once

#include <QWidget>
#include "ui_PAResult.h"

#include <cstring>
#include <string>

#include "MSql.h"
#include "Good.h"

class PAResult : public QWidget
{
	Q_OBJECT

public:
	PAResult(QWidget *parent = Q_NULLPTR);//后台显示
	PAResult(string mark,QWidget *parent = Q_NULLPTR);//机构面板显示
	~PAResult();

private:
	Ui::PAResult ui;

public:
	void initMembers();
	void connectMembers();
	void findEmpInfoFromTable(string &str);//在表格中查找数据

private:
	MSql m_sql;
};
