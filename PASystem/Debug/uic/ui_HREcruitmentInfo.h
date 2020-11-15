/********************************************************************************
** Form generated from reading UI file 'HREcruitmentInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRECRUITMENTINFO_H
#define UI_HRECRUITMENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HREcruitmentInfo
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QLabel *label_41;
    QComboBox *comboBox;
    QLabel *label_42;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QFrame *line;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QFrame *line_2;
    QLabel *label_55;
    QPlainTextEdit *plainTextEdit_2;

    void setupUi(QWidget *HREcruitmentInfo)
    {
        if (HREcruitmentInfo->objectName().isEmpty())
            HREcruitmentInfo->setObjectName(QString::fromUtf8("HREcruitmentInfo"));
        HREcruitmentInfo->resize(985, 750);
        gridLayout = new QGridLayout(HREcruitmentInfo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(HREcruitmentInfo);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 940, 2000));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 2000));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(40, 50, 151, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_41->setFont(font);
        label_41->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(210, 50, 171, 41));
        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(40, 130, 91, 31));
        label_42->setFont(font);
        label_42->setAlignment(Qt::AlignCenter);
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(110, 170, 741, 451));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_43 = new QLabel(groupBox);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(470, 50, 91, 41));
        label_43->setFont(font);
        label_43->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(groupBox);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(590, 50, 171, 41));
        label_44->setFont(font);
        label_44->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(40, 680, 81, 31));
        label_45->setFont(font);
        label_45->setAlignment(Qt::AlignCenter);
        label_46 = new QLabel(groupBox);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(130, 680, 91, 31));
        label_46->setFont(font);
        label_46->setAlignment(Qt::AlignCenter);
        label_47 = new QLabel(groupBox);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(220, 680, 81, 31));
        label_47->setFont(font);
        label_47->setAlignment(Qt::AlignCenter);
        label_48 = new QLabel(groupBox);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(310, 680, 91, 31));
        label_48->setFont(font);
        label_48->setAlignment(Qt::AlignCenter);
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 730, 911, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_49 = new QLabel(groupBox);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(40, 760, 91, 31));
        label_49->setFont(font);
        label_49->setAlignment(Qt::AlignCenter);
        label_50 = new QLabel(groupBox);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(140, 760, 91, 31));
        label_50->setFont(font);
        label_50->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_51 = new QLabel(groupBox);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(590, 100, 171, 41));
        label_51->setFont(font);
        label_51->setAlignment(Qt::AlignCenter);
        label_52 = new QLabel(groupBox);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(470, 100, 91, 41));
        label_52->setFont(font);
        label_52->setAlignment(Qt::AlignCenter);
        label_53 = new QLabel(groupBox);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(40, 820, 91, 31));
        label_53->setFont(font);
        label_53->setAlignment(Qt::AlignCenter);
        label_54 = new QLabel(groupBox);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(140, 820, 421, 31));
        label_54->setFont(font);
        label_54->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 870, 911, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_55 = new QLabel(groupBox);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(40, 900, 91, 31));
        label_55->setFont(font);
        label_55->setAlignment(Qt::AlignCenter);
        plainTextEdit_2 = new QPlainTextEdit(groupBox);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(90, 950, 741, 451));
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(HREcruitmentInfo);

        QMetaObject::connectSlotsByName(HREcruitmentInfo);
    } // setupUi

    void retranslateUi(QWidget *HREcruitmentInfo)
    {
        HREcruitmentInfo->setWindowTitle(QCoreApplication::translate("HREcruitmentInfo", "HREcruitmentInfo", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HREcruitmentInfo", "\346\213\233\350\201\230\344\277\241\346\201\257\346\237\245\347\234\213", nullptr));
        label_41->setText(QCoreApplication::translate("HREcruitmentInfo", "\351\200\211\346\213\251\345\267\262\345\217\221\345\270\203\347\232\204\345\262\227\344\275\215\357\274\232", nullptr));
        label_42->setText(QCoreApplication::translate("HREcruitmentInfo", "\345\262\227\344\275\215\344\273\213\347\273\215\357\274\232", nullptr));
        label_43->setText(QCoreApplication::translate("HREcruitmentInfo", "\345\217\221\345\270\203\346\227\266\351\227\264\357\274\232", nullptr));
        label_44->setText(QCoreApplication::translate("HREcruitmentInfo", "XX/XX/XXXX", nullptr));
        label_45->setText(QCoreApplication::translate("HREcruitmentInfo", "\350\226\252\350\265\204\357\274\232", nullptr));
        label_46->setText(QCoreApplication::translate("HREcruitmentInfo", "start", nullptr));
        label_47->setText(QCoreApplication::translate("HREcruitmentInfo", "\342\200\224\342\200\224", nullptr));
        label_48->setText(QCoreApplication::translate("HREcruitmentInfo", "end", nullptr));
        label_49->setText(QCoreApplication::translate("HREcruitmentInfo", "\346\213\233\350\201\230\344\272\272\346\225\260\357\274\232", nullptr));
        label_50->setText(QCoreApplication::translate("HREcruitmentInfo", "XXX", nullptr));
        label_51->setText(QCoreApplication::translate("HREcruitmentInfo", "XXXXXXX", nullptr));
        label_52->setText(QCoreApplication::translate("HREcruitmentInfo", "\346\213\233\350\201\230\347\212\266\346\200\201\357\274\232", nullptr));
        label_53->setText(QCoreApplication::translate("HREcruitmentInfo", "\345\267\245\344\275\234\345\234\260\347\202\271\357\274\232", nullptr));
        label_54->setText(QCoreApplication::translate("HREcruitmentInfo", "XXX", nullptr));
        label_55->setText(QCoreApplication::translate("HREcruitmentInfo", "\345\205\266\344\273\226\350\257\264\346\230\216\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HREcruitmentInfo: public Ui_HREcruitmentInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRECRUITMENTINFO_H
