#include "PASystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PASystem w;
	w.show();
	return a.exec();
}
