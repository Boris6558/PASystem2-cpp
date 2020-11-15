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
	PAResult(QWidget *parent = Q_NULLPTR);//��̨��ʾ
	PAResult(string mark,QWidget *parent = Q_NULLPTR);//���������ʾ
	~PAResult();

private:
	Ui::PAResult ui;

public:
	void initMembers();
	void connectMembers();
	void findEmpInfoFromTable(string &str);//�ڱ���в�������

private:
	MSql m_sql;
};
