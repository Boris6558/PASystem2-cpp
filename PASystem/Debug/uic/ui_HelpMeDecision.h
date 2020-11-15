/********************************************************************************
** Form generated from reading UI file 'HelpMeDecision.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPMEDECISION_H
#define UI_HELPMEDECISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpMeDecision
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_wait;
    QLabel *label_3;
    QWidget *page_main;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QComboBox *comboBox_reference;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QPushButton *pushButton_fresh;
    QLabel *label_4;
    QLineEdit *lineEdit_search;
    QGroupBox *groupBox;
    QLabel *label_5;
    QLineEdit *lineEdit_id;
    QLabel *label_6;
    QComboBox *comboBox_levelAlter;
    QPushButton *pushButton_alter;
    QPushButton *pushButton_commit;

    void setupUi(QWidget *HelpMeDecision)
    {
        if (HelpMeDecision->objectName().isEmpty())
            HelpMeDecision->setObjectName(QString::fromUtf8("HelpMeDecision"));
        HelpMeDecision->resize(702, 777);
        stackedWidget = new QStackedWidget(HelpMeDecision);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 681, 755));
        stackedWidget->setFrameShape(QFrame::Box);
        page_wait = new QWidget();
        page_wait->setObjectName(QString::fromUtf8("page_wait"));
        label_3 = new QLabel(page_wait);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 120, 361, 381));
        QFont font;
        font.setPointSize(23);
        label_3->setFont(font);
        stackedWidget->addWidget(page_wait);
        page_main = new QWidget();
        page_main->setObjectName(QString::fromUtf8("page_main"));
        gridLayout_2 = new QGridLayout(page_main);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(page_main);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 636, 1000));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label->setFont(font1);
        comboBox_reference = new QComboBox(scrollAreaWidgetContents);
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->addItem(QString());
        comboBox_reference->setObjectName(QString::fromUtf8("comboBox_reference"));
        comboBox_reference->setGeometry(QRect(170, 20, 201, 31));
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 200, 631, 461));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 150, 311, 31));
        label_2->setFont(font1);
        pushButton_fresh = new QPushButton(scrollAreaWidgetContents);
        pushButton_fresh->setObjectName(QString::fromUtf8("pushButton_fresh"));
        pushButton_fresh->setGeometry(QRect(520, 670, 101, 31));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 80, 41, 31));
        label_4->setFont(font1);
        lineEdit_search = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setGeometry(QRect(170, 80, 241, 41));
        lineEdit_search->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 720, 611, 141));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 40, 91, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(120, 30, 121, 31));
        lineEdit_id->setFont(font2);
        lineEdit_id->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 40, 71, 16));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        comboBox_levelAlter = new QComboBox(groupBox);
        comboBox_levelAlter->addItem(QString());
        comboBox_levelAlter->addItem(QString());
        comboBox_levelAlter->addItem(QString());
        comboBox_levelAlter->addItem(QString());
        comboBox_levelAlter->setObjectName(QString::fromUtf8("comboBox_levelAlter"));
        comboBox_levelAlter->setGeometry(QRect(400, 30, 61, 31));
        comboBox_levelAlter->setFont(font2);
        pushButton_alter = new QPushButton(groupBox);
        pushButton_alter->setObjectName(QString::fromUtf8("pushButton_alter"));
        pushButton_alter->setGeometry(QRect(240, 90, 101, 31));
        pushButton_commit = new QPushButton(scrollAreaWidgetContents);
        pushButton_commit->setObjectName(QString::fromUtf8("pushButton_commit"));
        pushButton_commit->setGeometry(QRect(190, 890, 211, 41));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(page_main);

        retranslateUi(HelpMeDecision);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HelpMeDecision);
    } // setupUi

    void retranslateUi(QWidget *HelpMeDecision)
    {
        HelpMeDecision->setWindowTitle(QCoreApplication::translate("HelpMeDecision", "HelpMeDecision", nullptr));
        label_3->setText(QCoreApplication::translate("HelpMeDecision", "\346\255\243\345\234\250\345\210\206\346\236\220.......\n"
"\n"
"(\350\257\245\345\210\206\346\236\220\347\273\223\346\236\234\347\224\261\347\263\273\347\273\237\n"
"\350\207\252\345\212\250\345\210\244\345\256\232\357\274\214\344\273\205\344\276\233\345\217\202\350\200\203)", nullptr));
        label->setText(QCoreApplication::translate("HelpMeDecision", "\345\217\202\350\200\203\346\214\207\346\240\207\357\274\232", nullptr));
        comboBox_reference->setItemText(0, QCoreApplication::translate("HelpMeDecision", "\347\273\274\345\220\210\346\225\264\344\275\223(\351\273\230\350\256\244)", nullptr));
        comboBox_reference->setItemText(1, QCoreApplication::translate("HelpMeDecision", "\346\212\225\350\257\211\347\216\207", nullptr));
        comboBox_reference->setItemText(2, QCoreApplication::translate("HelpMeDecision", "\346\211\213\347\273\255\350\247\204\350\214\203\347\216\207", nullptr));
        comboBox_reference->setItemText(3, QCoreApplication::translate("HelpMeDecision", "\345\217\221\346\224\276\350\264\267\346\254\276\346\225\210\347\216\207", nullptr));
        comboBox_reference->setItemText(4, QCoreApplication::translate("HelpMeDecision", "\345\275\222\351\233\206\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(5, QCoreApplication::translate("HelpMeDecision", "\350\264\267\346\254\276\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(6, QCoreApplication::translate("HelpMeDecision", "\345\275\222\351\233\206\350\265\204\351\207\221\345\210\260\350\264\246\347\216\207", nullptr));
        comboBox_reference->setItemText(7, QCoreApplication::translate("HelpMeDecision", "\350\264\267\346\254\276\350\265\204\351\207\221\345\210\260\350\264\246\347\216\207", nullptr));
        comboBox_reference->setItemText(8, QCoreApplication::translate("HelpMeDecision", "\347\275\221\347\273\234\347\274\264\345\255\230\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(9, QCoreApplication::translate("HelpMeDecision", "\347\275\221\347\273\234\346\217\220\345\217\226\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(10, QCoreApplication::translate("HelpMeDecision", "\347\275\221\347\273\234\350\264\267\346\254\276\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(11, QCoreApplication::translate("HelpMeDecision", "\347\275\221\347\273\234\350\277\230\346\254\276\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(12, QCoreApplication::translate("HelpMeDecision", "\347\275\221\347\273\234\351\200\276\346\234\237\345\207\272\351\224\231\347\216\207", nullptr));
        comboBox_reference->setItemText(13, QCoreApplication::translate("HelpMeDecision", "\347\275\221\347\273\234\350\264\237\346\227\266\346\225\210\346\246\202\347\216\207", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("HelpMeDecision", "\346\234\272\346\236\204\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("HelpMeDecision", "\346\234\272\346\236\204\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("HelpMeDecision", "\350\257\204\347\272\247\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("HelpMeDecision", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("HelpMeDecision", "\350\200\203\346\240\270\345\221\250\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("HelpMeDecision", "\351\207\221\350\236\215\346\234\272\346\236\204\347\273\251\346\225\210\350\257\204\347\272\247\347\273\223\346\236\234(\345\267\262\345\241\253\345\206\231\350\200\203\346\240\270\350\241\250)\357\274\232", nullptr));
        pushButton_fresh->setText(QCoreApplication::translate("HelpMeDecision", "\345\210\267\346\226\260\346\225\260\346\215\256", nullptr));
        label_4->setText(QCoreApplication::translate("HelpMeDecision", "\346\220\234\347\264\242\357\274\232", nullptr));
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("HelpMeDecision", "\346\220\234\347\264\242\346\234\272\346\236\204\347\233\270\345\205\263\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HelpMeDecision", "\344\277\256\346\224\271\350\257\204\347\272\247\347\273\223\346\236\234\357\274\210\347\273\274\345\220\210\347\273\223\346\236\234\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("HelpMeDecision", "\346\234\272\346\236\204\347\274\226\345\217\267\357\274\232", nullptr));
        lineEdit_id->setText(QString());
        label_6->setText(QCoreApplication::translate("HelpMeDecision", "\350\257\204\347\272\247\347\273\223\346\236\234\357\274\232", nullptr));
        comboBox_levelAlter->setItemText(0, QCoreApplication::translate("HelpMeDecision", "A", nullptr));
        comboBox_levelAlter->setItemText(1, QCoreApplication::translate("HelpMeDecision", "B", nullptr));
        comboBox_levelAlter->setItemText(2, QCoreApplication::translate("HelpMeDecision", "C", nullptr));
        comboBox_levelAlter->setItemText(3, QCoreApplication::translate("HelpMeDecision", "D", nullptr));

        pushButton_alter->setText(QCoreApplication::translate("HelpMeDecision", "\344\277\256\346\224\271", nullptr));
        pushButton_commit->setText(QCoreApplication::translate("HelpMeDecision", "\351\207\207\347\224\250\346\255\244\345\206\263\347\255\226\350\257\204\347\272\247\347\273\223\346\236\234\345\271\266\345\205\254\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpMeDecision: public Ui_HelpMeDecision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPMEDECISION_H
