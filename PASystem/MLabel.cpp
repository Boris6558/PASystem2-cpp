#include "MLabel.h"

MLabel::MLabel(QWidget *parent)
	: QLabel(parent)
{
}

MLabel::~MLabel()
{
}

void MLabel::mousePressEvent(QMouseEvent * event)
{
	Q_EMIT sigClick();
}

void MLabel::mouseMoveEvent(QMouseEvent * event)
{
}
