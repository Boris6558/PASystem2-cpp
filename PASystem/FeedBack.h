#pragma once

#include <QWidget>
#include "ui_FeedBack.h"

#include <cstring>
#include <string>

#include "Good.h"
#include "MSql.h"

class FeedBack : public QWidget
{
	Q_OBJECT

public:
	FeedBack(string m_mechanism_id,QWidget *parent = Q_NULLPTR);
	~FeedBack();

private:
	Ui::FeedBack ui;

public:
	void initMembers();
	void connectMembers();

private:
	MSql m_sql;

	string mechanism_id;

	//上传的图片路径
	string path_img_1;
	string path_img_2;
	string path_img_3;

};
