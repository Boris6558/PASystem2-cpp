/********************************************************************************
** Form generated from reading UI file 'SeeFeedBack.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEFEEDBACK_H
#define UI_SEEFEEDBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include "enterviewlabel.h"

QT_BEGIN_NAMESPACE

class Ui_SeeFeedBack
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QLabel *label_41;
    QLabel *label_emp_id;
    QFrame *line;
    QPlainTextEdit *plainTextEdit_feedback;
    QPushButton *pushButton_receive;
    QLabel *label_emp_name;
    QLabel *label_42;
    QLabel *label_43;
    EnterViewLabel *label_2;
    EnterViewLabel *label;
    EnterViewLabel *label_3;

    void setupUi(QWidget *SeeFeedBack)
    {
        if (SeeFeedBack->objectName().isEmpty())
            SeeFeedBack->setObjectName(QString::fromUtf8("SeeFeedBack"));
        SeeFeedBack->resize(762, 708);
        gridLayout = new QGridLayout(SeeFeedBack);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(SeeFeedBack);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 717, 1500));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1500));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(20, 40, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_41->setFont(font);
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_emp_id = new QLabel(groupBox);
        label_emp_id->setObjectName(QString::fromUtf8("label_emp_id"));
        label_emp_id->setGeometry(QRect(130, 40, 281, 31));
        label_emp_id->setFont(font);
        label_emp_id->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 120, 671, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        plainTextEdit_feedback = new QPlainTextEdit(groupBox);
        plainTextEdit_feedback->setObjectName(QString::fromUtf8("plainTextEdit_feedback"));
        plainTextEdit_feedback->setGeometry(QRect(20, 160, 661, 371));
        plainTextEdit_feedback->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        pushButton_receive = new QPushButton(groupBox);
        pushButton_receive->setObjectName(QString::fromUtf8("pushButton_receive"));
        pushButton_receive->setGeometry(QRect(270, 1410, 121, 41));
        label_emp_name = new QLabel(groupBox);
        label_emp_name->setObjectName(QString::fromUtf8("label_emp_name"));
        label_emp_name->setGeometry(QRect(130, 80, 371, 31));
        label_emp_name->setFont(font);
        label_emp_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(20, 80, 81, 31));
        label_42->setFont(font);
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_43 = new QLabel(groupBox);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(20, 550, 61, 31));
        label_43->setFont(font);
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new EnterViewLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 860, 481, 231));
        label_2->setFrameShape(QFrame::Box);
        label_2->setScaledContents(true);
        label = new EnterViewLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 580, 481, 231));
        label->setFrameShape(QFrame::Box);
        label->setScaledContents(true);
        label_3 = new EnterViewLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 1130, 481, 231));
        label_3->setFrameShape(QFrame::Box);
        label_3->setScaledContents(true);

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(SeeFeedBack);

        QMetaObject::connectSlotsByName(SeeFeedBack);
    } // setupUi

    void retranslateUi(QWidget *SeeFeedBack)
    {
        SeeFeedBack->setWindowTitle(QCoreApplication::translate("SeeFeedBack", "SeeFeedBack", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SeeFeedBack", "\346\234\272\346\236\204\345\217\215\351\246\210", nullptr));
        label_41->setText(QCoreApplication::translate("SeeFeedBack", "\346\234\272\346\236\204\347\274\226\345\217\267:", nullptr));
        label_emp_id->setText(QCoreApplication::translate("SeeFeedBack", "XXXX", nullptr));
        pushButton_receive->setText(QCoreApplication::translate("SeeFeedBack", "\346\216\245\346\224\266", nullptr));
        label_emp_name->setText(QCoreApplication::translate("SeeFeedBack", "XXXX", nullptr));
        label_42->setText(QCoreApplication::translate("SeeFeedBack", "\346\234\272\346\236\204\345\220\215\347\247\260:", nullptr));
        label_43->setText(QCoreApplication::translate("SeeFeedBack", "\351\231\204\345\212\240\357\274\232", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SeeFeedBack: public Ui_SeeFeedBack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEFEEDBACK_H
