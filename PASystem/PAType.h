#pragma once

#include <QWidget>
#include "ui_PAType.h"

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include "Good.h"
#include "MSql.h"

using namespace boost;

class PAType : public QWidget
{
	Q_OBJECT

public:
	PAType(QWidget *parent = Q_NULLPTR);
	~PAType();

private:
	Ui::PAType ui;

Q_SIGNALS:
	void sigSendPATable(const QString &text);

private:
	property_tree::ptree pt;

	MSql m_sql;
};
