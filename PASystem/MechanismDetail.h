#pragma once

#include <QWidget>
#include "ui_MechanismDetail.h"

#include <cstring>
#include <string>

#include "MSql.h"
#include "Good.h"

class MechanismDetail : public QWidget
{
	Q_OBJECT

public:
	MechanismDetail(string c_mechanism_id,QWidget *parent = Q_NULLPTR);
	~MechanismDetail();

private:
	Ui::MechanismDetail ui;

public:
	void initMembers();
	void connectMembers();

private:
	MSql m_sql;

	string mechanism_id;
};
