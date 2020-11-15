/********************************************************************************
** Form generated from reading UI file 'PAResult.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARESULT_H
#define UI_PARESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PAResult
{
public:
    QTableWidget *tableWidget_level;
    QLabel *label;
    QLineEdit *lineEdit_search;

    void setupUi(QWidget *PAResult)
    {
        if (PAResult->objectName().isEmpty())
            PAResult->setObjectName(QString::fromUtf8("PAResult"));
        PAResult->resize(778, 552);
        tableWidget_level = new QTableWidget(PAResult);
        if (tableWidget_level->columnCount() < 6)
            tableWidget_level->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_level->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_level->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_level->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_level->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_level->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_level->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_level->setObjectName(QString::fromUtf8("tableWidget_level"));
        tableWidget_level->setGeometry(QRect(10, 90, 761, 451));
        tableWidget_level->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        tableWidget_level->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_level->setShowGrid(false);
        label = new QLabel(PAResult);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 30, 58, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label->setFont(font);
        lineEdit_search = new QLineEdit(PAResult);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setGeometry(QRect(520, 30, 241, 41));
        lineEdit_search->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        retranslateUi(PAResult);

        QMetaObject::connectSlotsByName(PAResult);
    } // setupUi

    void retranslateUi(QWidget *PAResult)
    {
        PAResult->setWindowTitle(QCoreApplication::translate("PAResult", "PAResult", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_level->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PAResult", "\346\234\272\346\236\204\345\217\227\347\220\206\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_level->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PAResult", "\346\234\272\346\236\204\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_level->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PAResult", "\347\273\251\346\225\210\347\255\211\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_level->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PAResult", "\350\257\204\347\272\247\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_level->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("PAResult", "\346\230\257\345\220\246\345\241\253\345\206\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_level->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("PAResult", "\350\200\203\346\240\270\345\221\250\346\234\237", nullptr));
        label->setText(QCoreApplication::translate("PAResult", "\346\220\234\347\264\242", nullptr));
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("PAResult", "\346\220\234\347\264\242\346\234\272\346\236\204\347\233\270\345\205\263\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PAResult: public Ui_PAResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARESULT_H
