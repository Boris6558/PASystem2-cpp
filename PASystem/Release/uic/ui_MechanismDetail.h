/********************************************************************************
** Form generated from reading UI file 'MechanismDetail.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MECHANISMDETAIL_H
#define UI_MECHANISMDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MechanismDetail
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QLabel *label_name_logo_3;
    QLineEdit *lineEdit_team_name_11;
    QLabel *label_name_22;
    QLabel *label_name_23;
    QLineEdit *lineEdit_team_name_12;
    QFrame *line_2;
    QGroupBox *groupBox_8;
    QLineEdit *lineEdit_team_name_13;
    QLineEdit *lineEdit_team_name_14;
    QLabel *label_name_24;
    QLineEdit *lineEdit_team_name_15;
    QLabel *label_name_25;
    QLabel *label_name_26;
    QLabel *label_name_27;
    QLineEdit *lineEdit_team_name_16;
    QLabel *label_name_28;
    QLineEdit *lineEdit_team_name_17;
    QLineEdit *lineEdit_team_name_18;
    QLineEdit *lineEdit_team_name_19;
    QLabel *label_name_29;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_name_30;
    QLabel *label_name_31;
    QGroupBox *groupBox_9;
    QLabel *label_name_32;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_name_34;
    QPushButton *pushButton;

    void setupUi(QWidget *MechanismDetail)
    {
        if (MechanismDetail->objectName().isEmpty())
            MechanismDetail->setObjectName(QString::fromUtf8("MechanismDetail"));
        MechanismDetail->resize(1131, 863);
        gridLayout = new QGridLayout(MechanismDetail);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(MechanismDetail);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -1158, 1086, 3000));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 3000));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_name_logo_3 = new QLabel(groupBox);
        label_name_logo_3->setObjectName(QString::fromUtf8("label_name_logo_3"));
        label_name_logo_3->setGeometry(QRect(40, 60, 201, 191));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_name_logo_3->setFont(font);
        label_name_logo_3->setFrameShape(QFrame::Box);
        label_name_logo_3->setScaledContents(true);
        label_name_logo_3->setAlignment(Qt::AlignCenter);
        lineEdit_team_name_11 = new QLineEdit(groupBox);
        lineEdit_team_name_11->setObjectName(QString::fromUtf8("lineEdit_team_name_11"));
        lineEdit_team_name_11->setGeometry(QRect(440, 70, 241, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_team_name_11->setFont(font1);
        lineEdit_team_name_11->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_11->setReadOnly(true);
        label_name_22 = new QLabel(groupBox);
        label_name_22->setObjectName(QString::fromUtf8("label_name_22"));
        label_name_22->setGeometry(QRect(260, 70, 161, 41));
        label_name_22->setFont(font);
        label_name_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_name_23 = new QLabel(groupBox);
        label_name_23->setObjectName(QString::fromUtf8("label_name_23"));
        label_name_23->setGeometry(QRect(290, 140, 161, 41));
        label_name_23->setFont(font);
        label_name_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_team_name_12 = new QLineEdit(groupBox);
        lineEdit_team_name_12->setObjectName(QString::fromUtf8("lineEdit_team_name_12"));
        lineEdit_team_name_12->setGeometry(QRect(440, 140, 411, 41));
        lineEdit_team_name_12->setFont(font1);
        lineEdit_team_name_12->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_12->setReadOnly(false);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 270, 1101, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 300, 1091, 1061));
        lineEdit_team_name_13 = new QLineEdit(groupBox_8);
        lineEdit_team_name_13->setObjectName(QString::fromUtf8("lineEdit_team_name_13"));
        lineEdit_team_name_13->setGeometry(QRect(260, 690, 411, 41));
        lineEdit_team_name_13->setFont(font1);
        lineEdit_team_name_13->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_13->setReadOnly(false);
        lineEdit_team_name_14 = new QLineEdit(groupBox_8);
        lineEdit_team_name_14->setObjectName(QString::fromUtf8("lineEdit_team_name_14"));
        lineEdit_team_name_14->setGeometry(QRect(260, 850, 411, 41));
        lineEdit_team_name_14->setFont(font1);
        lineEdit_team_name_14->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_14->setReadOnly(false);
        label_name_24 = new QLabel(groupBox_8);
        label_name_24->setObjectName(QString::fromUtf8("label_name_24"));
        label_name_24->setGeometry(QRect(140, 690, 111, 41));
        label_name_24->setFont(font);
        label_name_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_team_name_15 = new QLineEdit(groupBox_8);
        lineEdit_team_name_15->setObjectName(QString::fromUtf8("lineEdit_team_name_15"));
        lineEdit_team_name_15->setGeometry(QRect(260, 930, 411, 41));
        lineEdit_team_name_15->setFont(font1);
        lineEdit_team_name_15->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_15->setReadOnly(false);
        label_name_25 = new QLabel(groupBox_8);
        label_name_25->setObjectName(QString::fromUtf8("label_name_25"));
        label_name_25->setGeometry(QRect(60, 30, 131, 41));
        label_name_25->setFont(font);
        label_name_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_name_26 = new QLabel(groupBox_8);
        label_name_26->setObjectName(QString::fromUtf8("label_name_26"));
        label_name_26->setGeometry(QRect(140, 620, 111, 41));
        label_name_26->setFont(font);
        label_name_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_name_27 = new QLabel(groupBox_8);
        label_name_27->setObjectName(QString::fromUtf8("label_name_27"));
        label_name_27->setGeometry(QRect(140, 850, 111, 41));
        label_name_27->setFont(font);
        label_name_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_team_name_16 = new QLineEdit(groupBox_8);
        lineEdit_team_name_16->setObjectName(QString::fromUtf8("lineEdit_team_name_16"));
        lineEdit_team_name_16->setGeometry(QRect(260, 1010, 411, 41));
        lineEdit_team_name_16->setFont(font1);
        lineEdit_team_name_16->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_16->setReadOnly(false);
        label_name_28 = new QLabel(groupBox_8);
        label_name_28->setObjectName(QString::fromUtf8("label_name_28"));
        label_name_28->setGeometry(QRect(140, 530, 111, 41));
        label_name_28->setFont(font);
        label_name_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_team_name_17 = new QLineEdit(groupBox_8);
        lineEdit_team_name_17->setObjectName(QString::fromUtf8("lineEdit_team_name_17"));
        lineEdit_team_name_17->setGeometry(QRect(260, 530, 411, 41));
        lineEdit_team_name_17->setFont(font1);
        lineEdit_team_name_17->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_17->setReadOnly(false);
        lineEdit_team_name_18 = new QLineEdit(groupBox_8);
        lineEdit_team_name_18->setObjectName(QString::fromUtf8("lineEdit_team_name_18"));
        lineEdit_team_name_18->setGeometry(QRect(260, 620, 411, 41));
        lineEdit_team_name_18->setFont(font1);
        lineEdit_team_name_18->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_18->setReadOnly(false);
        lineEdit_team_name_19 = new QLineEdit(groupBox_8);
        lineEdit_team_name_19->setObjectName(QString::fromUtf8("lineEdit_team_name_19"));
        lineEdit_team_name_19->setGeometry(QRect(260, 770, 411, 41));
        lineEdit_team_name_19->setFont(font1);
        lineEdit_team_name_19->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        lineEdit_team_name_19->setReadOnly(false);
        label_name_29 = new QLabel(groupBox_8);
        label_name_29->setObjectName(QString::fromUtf8("label_name_29"));
        label_name_29->setGeometry(QRect(140, 930, 111, 41));
        label_name_29->setFont(font);
        label_name_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        plainTextEdit_3 = new QPlainTextEdit(groupBox_8);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(140, 80, 741, 421));
        plainTextEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_name_30 = new QLabel(groupBox_8);
        label_name_30->setObjectName(QString::fromUtf8("label_name_30"));
        label_name_30->setGeometry(QRect(140, 770, 111, 41));
        label_name_30->setFont(font);
        label_name_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_name_31 = new QLabel(groupBox_8);
        label_name_31->setObjectName(QString::fromUtf8("label_name_31"));
        label_name_31->setGeometry(QRect(140, 1010, 111, 41));
        label_name_31->setFont(font);
        label_name_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_9 = new QGroupBox(groupBox);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(20, 1370, 1081, 691));
        label_name_32 = new QLabel(groupBox_9);
        label_name_32->setObjectName(QString::fromUtf8("label_name_32"));
        label_name_32->setGeometry(QRect(20, 20, 161, 41));
        label_name_32->setFont(font);
        label_name_32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 70, 821, 581));
        label_6->setFrameShape(QFrame::Box);
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignCenter);
        plainTextEdit_4 = new QPlainTextEdit(groupBox);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(60, 2110, 841, 421));
        plainTextEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_name_34 = new QLabel(groupBox);
        label_name_34->setObjectName(QString::fromUtf8("label_name_34"));
        label_name_34->setGeometry(QRect(50, 2060, 131, 41));
        label_name_34->setFont(font);
        label_name_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 2580, 181, 41));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(MechanismDetail);

        QMetaObject::connectSlotsByName(MechanismDetail);
    } // setupUi

    void retranslateUi(QWidget *MechanismDetail)
    {
        MechanismDetail->setWindowTitle(QCoreApplication::translate("MechanismDetail", "MechanismDetail", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MechanismDetail", "\345\205\254\345\217\270\346\246\202\345\206\265", nullptr));
        label_name_logo_3->setText(QCoreApplication::translate("MechanismDetail", "LOGO HEER", nullptr));
        lineEdit_team_name_11->setText(QString());
        label_name_22->setText(QCoreApplication::translate("MechanismDetail", "\345\217\227\347\220\206\351\207\221\350\236\215\346\234\272\346\236\204\347\274\226\345\217\267\357\274\232", nullptr));
        label_name_23->setText(QCoreApplication::translate("MechanismDetail", "\351\207\221\350\236\215\346\234\272\346\236\204\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_team_name_12->setText(QString());
        groupBox_8->setTitle(QCoreApplication::translate("MechanismDetail", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        lineEdit_team_name_13->setText(QString());
        lineEdit_team_name_14->setText(QString());
        label_name_24->setText(QCoreApplication::translate("MechanismDetail", "\346\263\250\345\206\214\344\272\272\357\274\232", nullptr));
        lineEdit_team_name_15->setText(QString());
        label_name_25->setText(QCoreApplication::translate("MechanismDetail", "\345\205\254\345\217\270\344\273\213\347\273\215\357\274\232", nullptr));
        label_name_26->setText(QCoreApplication::translate("MechanismDetail", "\350\241\214\344\270\232\347\261\273\345\236\213\357\274\232", nullptr));
        label_name_27->setText(QCoreApplication::translate("MechanismDetail", "\347\224\265\350\257\235\357\274\232", nullptr));
        lineEdit_team_name_16->setText(QString());
        label_name_28->setText(QCoreApplication::translate("MechanismDetail", "\350\257\246\347\273\206\345\234\260\345\235\200\357\274\232", nullptr));
        lineEdit_team_name_17->setText(QString());
        lineEdit_team_name_18->setText(QString());
        lineEdit_team_name_19->setText(QString());
        label_name_29->setText(QCoreApplication::translate("MechanismDetail", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_name_30->setText(QCoreApplication::translate("MechanismDetail", "\350\272\253\344\273\275\350\257\201;", nullptr));
        label_name_31->setText(QCoreApplication::translate("MechanismDetail", "\347\212\266\346\200\201\357\274\232", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MechanismDetail", "\350\257\201\344\271\246", nullptr));
        label_name_32->setText(QCoreApplication::translate("MechanismDetail", "\351\207\221\350\236\215\346\234\272\346\236\204\344\273\243\347\240\201\350\257\201\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MechanismDetail", "\350\257\201\344\273\266", nullptr));
        label_name_34->setText(QCoreApplication::translate("MechanismDetail", "\345\244\207\346\263\250\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MechanismDetail", "\344\277\235\345\255\230\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MechanismDetail: public Ui_MechanismDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MECHANISMDETAIL_H
