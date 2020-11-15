#include "PAType.h"

#include <QPushButton>

PAType::PAType(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(QString::fromLocal8Bit("��������"));

	m_sql.init();

	/*************** QPushButton ******************/
	connect(ui.pushButton_alter_passwd,&QPushButton::clicked,
		[=]()mutable
	{
		Q_EMIT sigSendPATable(ui.comboBox->currentText());
	}
		);

	//����
	QPalette pal = palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(PATH_IMG(dialog_back.jpg))));
	setPalette(pal);
}

PAType::~PAType()
{

}
