#pragma once

#include <QWidget>
#include "ui_HelpMeDecision.h"

#include <cstring>
#include <string>

#include "Good.h"
#include "MSql.h"

class HelpMeDecision : public QWidget
{
	Q_OBJECT

public:
	HelpMeDecision(QWidget *parent = Q_NULLPTR);
	~HelpMeDecision();

private:
	Ui::HelpMeDecision ui;

public:
	void initMembers();
	void connectMembers();
	void findEmpInfoFromTable(string & str);

private:
	MSql m_sql;
};
