#include "EnterViewLabel.h"

EnterViewLabel::EnterViewLabel(QWidget *parent)
	: QLabel(parent)
{
}

EnterViewLabel::~EnterViewLabel()
{
}

void EnterViewLabel::enterEvent(QEvent * event)
{
	if (img1.compare("")==0 || 
		img2.compare("") == 0||
		img3.compare("") == 0
		)
	{
		return;
	}
	switch (getId())
	{
	case 1:
		idCard_temp = imread(img1);
		break;
	case 2:
		idCard_temp = imread(img2);
		break;
	case 3:
		idCard_temp = imread(img3);
		break;
	}
	cv::resize(idCard_temp, idCard_temp, cv::Size(800, 500));
	imshow("图片查看", idCard_temp);
}

void EnterViewLabel::leaveEvent(QEvent * event)
{
	if (img1.compare("") == 0 ||
		img2.compare("") == 0 ||
		img3.compare("") == 0
		)
	{
		return;
	}

	destroyWindow("图片查看");
}

void EnterViewLabel::setId(int _id)
{
	id = _id;
}

int EnterViewLabel::getId()
{
	return id;
}
