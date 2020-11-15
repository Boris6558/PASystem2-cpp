/********************************************************************************
** Form generated from reading UI file 'BackManagerPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKMANAGERPANEL_H
#define UI_BACKMANAGERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackManagerPanel
{
public:
    QListWidget *listWidget;
    QLabel *label_name_team_name;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_search;
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget_2;
    QLabel *label_name_14;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_help_me_decision_level;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_performanceAll;
    QPushButton *pushButton_performance_rules;
    QPushButton *pushButton_see_performanceResult;
    QWidget *page_3;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_fresh;
    QListWidget *listWidget_see;
    QWidget *page_4;
    QGridLayout *gridLayout_8;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_4;
    QLineEdit *lineEdit_new_passwd;
    QLineEdit *lineEdit_old_passwd;
    QLabel *label_129;
    QLabel *label_128;
    QLineEdit *lineEdit_new_passwd_again;
    QLabel *label_90;
    QPushButton *pushButton_alter_passwd;

    void setupUi(QWidget *BackManagerPanel)
    {
        if (BackManagerPanel->objectName().isEmpty())
            BackManagerPanel->setObjectName(QString::fromUtf8("BackManagerPanel"));
        BackManagerPanel->resize(1202, 774);
        listWidget = new QListWidget(BackManagerPanel);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 70, 261, 691));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_name_team_name = new QLabel(BackManagerPanel);
        label_name_team_name->setObjectName(QString::fromUtf8("label_name_team_name"));
        label_name_team_name->setGeometry(QRect(20, 10, 1171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_name_team_name->setFont(font);
        label_name_team_name->setFrameShape(QFrame::Box);
        label_name_team_name->setAlignment(Qt::AlignCenter);
        stackedWidget = new QStackedWidget(BackManagerPanel);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(290, 60, 911, 711));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 887, 687));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        lineEdit_search = new QLineEdit(groupBox);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setGeometry(QRect(590, 26, 241, 41));
        lineEdit_search->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 30, 58, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label->setFont(font1);
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 110, 841, 541));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 866, 1200));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(0, 1200));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        tableWidget_2 = new QTableWidget(groupBox_2);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 90, 821, 541));
        tableWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->setShowGrid(false);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        label_name_14 = new QLabel(groupBox_2);
        label_name_14->setObjectName(QString::fromUtf8("label_name_14"));
        label_name_14->setGeometry(QRect(20, 30, 141, 41));
        label_name_14->setFont(font);
        label_name_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 810, 811, 111));
        pushButton_help_me_decision_level = new QPushButton(groupBox_5);
        pushButton_help_me_decision_level->setObjectName(QString::fromUtf8("pushButton_help_me_decision_level"));
        pushButton_help_me_decision_level->setGeometry(QRect(40, 40, 201, 41));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 650, 811, 141));
        pushButton_performanceAll = new QPushButton(groupBox_6);
        pushButton_performanceAll->setObjectName(QString::fromUtf8("pushButton_performanceAll"));
        pushButton_performanceAll->setGeometry(QRect(40, 40, 151, 41));
        pushButton_performance_rules = new QPushButton(groupBox_6);
        pushButton_performance_rules->setObjectName(QString::fromUtf8("pushButton_performance_rules"));
        pushButton_performance_rules->setGeometry(QRect(270, 40, 211, 41));
        pushButton_see_performanceResult = new QPushButton(groupBox_6);
        pushButton_see_performanceResult->setObjectName(QString::fromUtf8("pushButton_see_performanceResult"));
        pushButton_see_performanceResult->setGeometry(QRect(580, 40, 151, 41));

        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_4->addWidget(scrollArea_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_6 = new QGridLayout(page_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        scrollArea_3 = new QScrollArea(page_3);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 887, 687));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        pushButton_fresh = new QPushButton(groupBox_3);
        pushButton_fresh->setObjectName(QString::fromUtf8("pushButton_fresh"));
        pushButton_fresh->setGeometry(QRect(760, 20, 93, 28));
        listWidget_see = new QListWidget(groupBox_3);
        listWidget_see->setObjectName(QString::fromUtf8("listWidget_see"));
        listWidget_see->setGeometry(QRect(10, 60, 851, 591));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(17);
        listWidget_see->setFont(font2);
        listWidget_see->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_6->addWidget(scrollArea_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_8 = new QGridLayout(page_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        scrollArea_4 = new QScrollArea(page_4);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 887, 687));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        lineEdit_new_passwd = new QLineEdit(groupBox_4);
        lineEdit_new_passwd->setObjectName(QString::fromUtf8("lineEdit_new_passwd"));
        lineEdit_new_passwd->setGeometry(QRect(130, 100, 301, 41));
        lineEdit_new_passwd->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_old_passwd = new QLineEdit(groupBox_4);
        lineEdit_old_passwd->setObjectName(QString::fromUtf8("lineEdit_old_passwd"));
        lineEdit_old_passwd->setGeometry(QRect(130, 30, 301, 41));
        lineEdit_old_passwd->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_129 = new QLabel(groupBox_4);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setGeometry(QRect(30, 170, 91, 41));
        label_129->setFont(font1);
        label_129->setAlignment(Qt::AlignCenter);
        label_128 = new QLabel(groupBox_4);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        label_128->setGeometry(QRect(50, 100, 71, 41));
        label_128->setFont(font1);
        label_128->setAlignment(Qt::AlignCenter);
        lineEdit_new_passwd_again = new QLineEdit(groupBox_4);
        lineEdit_new_passwd_again->setObjectName(QString::fromUtf8("lineEdit_new_passwd_again"));
        lineEdit_new_passwd_again->setGeometry(QRect(130, 170, 301, 41));
        lineEdit_new_passwd_again->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_90 = new QLabel(groupBox_4);
        label_90->setObjectName(QString::fromUtf8("label_90"));
        label_90->setGeometry(QRect(50, 30, 71, 41));
        label_90->setFont(font1);
        label_90->setAlignment(Qt::AlignCenter);
        pushButton_alter_passwd = new QPushButton(groupBox_4);
        pushButton_alter_passwd->setObjectName(QString::fromUtf8("pushButton_alter_passwd"));
        pushButton_alter_passwd->setGeometry(QRect(310, 260, 101, 41));

        gridLayout_7->addWidget(groupBox_4, 0, 0, 1, 1);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        gridLayout_8->addWidget(scrollArea_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        retranslateUi(BackManagerPanel);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BackManagerPanel);
    } // setupUi

    void retranslateUi(QWidget *BackManagerPanel)
    {
        BackManagerPanel->setWindowTitle(QCoreApplication::translate("BackManagerPanel", "BackManagerPanel", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("BackManagerPanel", "\346\234\272\346\236\204\344\277\241\346\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("BackManagerPanel", "\347\273\251\346\225\210\350\257\204\347\272\247", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("BackManagerPanel", "\346\237\245\347\234\213", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("BackManagerPanel", "\350\256\276\347\275\256", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_name_team_name->setText(QCoreApplication::translate("BackManagerPanel", "\351\207\221\350\236\215\346\234\272\346\236\204\347\273\251\346\225\210\350\200\203\346\240\270\347\263\273\347\273\237-------\345\220\216\345\217\260\347\256\241\347\220\206", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BackManagerPanel", "\346\234\272\346\236\204\344\277\241\346\201\257", nullptr));
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("BackManagerPanel", "\346\220\234\347\264\242\346\234\272\346\236\204\347\233\270\345\205\263\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("BackManagerPanel", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BackManagerPanel", "\346\234\272\346\236\204\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BackManagerPanel", "\346\234\272\346\236\204\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BackManagerPanel", "\351\207\221\350\236\215\346\234\215\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BackManagerPanel", "\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BackManagerPanel", "\345\205\254\345\217\270\346\263\225\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BackManagerPanel", "\347\212\266\346\200\201", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("BackManagerPanel", "\347\273\251\346\225\210\350\257\204\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("BackManagerPanel", "\346\234\272\346\236\204\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("BackManagerPanel", "\346\234\272\346\236\204\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("BackManagerPanel", "\351\207\221\350\236\215\346\234\215\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("BackManagerPanel", "\345\234\260\345\235\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("BackManagerPanel", "\345\205\254\345\217\270\346\263\225\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("BackManagerPanel", "\347\212\266\346\200\201", nullptr));
        label_name_14->setText(QCoreApplication::translate("BackManagerPanel", "\351\207\221\350\236\215\346\234\272\346\236\204\346\225\260\346\215\256\350\241\250\357\274\232", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("BackManagerPanel", "\350\276\205\345\212\251\357\274\210\350\257\245\345\206\263\347\255\226\344\273\205\346\217\220\344\276\233\345\217\202\350\200\203\357\274\211", nullptr));
        pushButton_help_me_decision_level->setText(QCoreApplication::translate("BackManagerPanel", "\345\270\256\346\210\221\345\206\263\347\255\226\347\273\251\346\225\210\350\257\204\347\272\247", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("BackManagerPanel", "\345\212\237\350\203\275", nullptr));
        pushButton_performanceAll->setText(QCoreApplication::translate("BackManagerPanel", "\345\220\221\345\205\250\344\275\223\345\217\221\350\265\267\347\273\251\346\225\210\350\200\203\346\240\270", nullptr));
        pushButton_performance_rules->setText(QCoreApplication::translate("BackManagerPanel", "\347\273\251\346\225\210\350\257\204\347\272\247\346\214\207\346\240\207\345\217\212\350\200\203\346\240\270\346\240\267\345\274\217\350\241\250", nullptr));
        pushButton_see_performanceResult->setText(QCoreApplication::translate("BackManagerPanel", "\346\237\245\347\234\213\347\273\251\346\225\210\347\273\223\346\236\234", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("BackManagerPanel", "\346\237\245\347\234\213", nullptr));
        pushButton_fresh->setText(QCoreApplication::translate("BackManagerPanel", "\345\210\267\346\226\260", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("BackManagerPanel", "\350\256\276\347\275\256", nullptr));
        lineEdit_new_passwd->setText(QString());
        lineEdit_new_passwd->setPlaceholderText(QString());
        lineEdit_old_passwd->setText(QString());
        lineEdit_old_passwd->setPlaceholderText(QString());
        label_129->setText(QCoreApplication::translate("BackManagerPanel", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", nullptr));
        label_128->setText(QCoreApplication::translate("BackManagerPanel", "\346\226\260\345\257\206\347\240\201", nullptr));
        lineEdit_new_passwd_again->setText(QString());
        lineEdit_new_passwd_again->setPlaceholderText(QString());
        label_90->setText(QCoreApplication::translate("BackManagerPanel", "\346\227\247\345\257\206\347\240\201", nullptr));
        pushButton_alter_passwd->setText(QCoreApplication::translate("BackManagerPanel", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackManagerPanel: public Ui_BackManagerPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKMANAGERPANEL_H
