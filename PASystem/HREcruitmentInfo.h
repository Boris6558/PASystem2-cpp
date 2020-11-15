#pragma once

#include <QWidget>
#include "ui_HREcruitmentInfo.h"

#include <cstring>
#include <string>

#include "Good.h"
#include "MSql.h"

class HREcruitmentInfo : public QWidget
{
	Q_OBJECT

public:
	HREcruitmentInfo(string c_mechanism_id, QWidget *parent = Q_NULLPTR);
	~HREcruitmentInfo();

private:
	Ui::HREcruitmentInfo ui;

public:
	void initMembers();
	void connectMembers();

private:
	string mechanism_id = "";

	MSql m_sql;
};
