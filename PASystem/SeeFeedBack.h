#pragma once

#include <QWidget>
#include "ui_SeeFeedBack.h"

#include <cstring>
#include <string>

#include "Good.h"
#include "MSql.h"
#include "EnterViewLabel.h"

class SeeFeedBack : public QWidget
{
	Q_OBJECT

public:
	SeeFeedBack(string c_mechanism_id,QWidget *parent = Q_NULLPTR);
	~SeeFeedBack();

private:
	Ui::SeeFeedBack ui;

public:
	void initMembers();
	void connectMembers();

private:
	string mechanism_id = "";

	MSql m_sql;
};
