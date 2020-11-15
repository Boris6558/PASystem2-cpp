#pragma once

#include <QLabel>
#include <QEvent>
#include "Good.h"

#include <cstring>
#include <string>

#include <opencv2/opencv.hpp>

using namespace cv;

class EnterViewLabel : public QLabel
{
	Q_OBJECT

public:
	EnterViewLabel(QWidget *parent);
	~EnterViewLabel();

protected:
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	
public:
	void setId(int _id);
	int getId();

public:
	static string img1;
	static string img2;
	static string img3;

private:
	Mat idCard_temp;
	int id=1;
};
