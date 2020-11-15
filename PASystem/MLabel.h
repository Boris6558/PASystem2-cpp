#pragma once

#include <QLabel>
#include <QMouseEvent>

class MLabel : public QLabel
{
	Q_OBJECT

public:
	MLabel(QWidget *parent);
	~MLabel();

public:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

Q_SIGNALS:
	void sigClick();
};
