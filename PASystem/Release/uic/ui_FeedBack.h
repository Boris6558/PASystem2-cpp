/********************************************************************************
** Form generated from reading UI file 'FeedBack.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACK_H
#define UI_FEEDBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeedBack
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QLabel *label_41;
    QPushButton *pushButton_commit;
    QPlainTextEdit *plainTextEdit_feedback;
    QLabel *label_42;
    QLabel *label;
    QPushButton *pushButton_up1;
    QLabel *label_2;
    QPushButton *pushButton_up2;
    QLabel *label_3;
    QPushButton *pushButton_up3;

    void setupUi(QWidget *FeedBack)
    {
        if (FeedBack->objectName().isEmpty())
            FeedBack->setObjectName(QString::fromUtf8("FeedBack"));
        FeedBack->resize(771, 720);
        gridLayout = new QGridLayout(FeedBack);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(FeedBack);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 726, 1500));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1500));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(20, 40, 231, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_41->setFont(font);
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_commit = new QPushButton(groupBox);
        pushButton_commit->setObjectName(QString::fromUtf8("pushButton_commit"));
        pushButton_commit->setGeometry(QRect(280, 1350, 101, 41));
        plainTextEdit_feedback = new QPlainTextEdit(groupBox);
        plainTextEdit_feedback->setObjectName(QString::fromUtf8("plainTextEdit_feedback"));
        plainTextEdit_feedback->setGeometry(QRect(20, 80, 681, 331));
        plainTextEdit_feedback->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(20, 450, 361, 31));
        label_42->setFont(font);
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 510, 481, 231));
        label->setFrameShape(QFrame::Box);
        label->setScaledContents(true);
        pushButton_up1 = new QPushButton(groupBox);
        pushButton_up1->setObjectName(QString::fromUtf8("pushButton_up1"));
        pushButton_up1->setGeometry(QRect(560, 660, 81, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font1.setPointSize(28);
        pushButton_up1->setFont(font1);
        pushButton_up1->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 790, 481, 231));
        label_2->setFrameShape(QFrame::Box);
        label_2->setScaledContents(true);
        pushButton_up2 = new QPushButton(groupBox);
        pushButton_up2->setObjectName(QString::fromUtf8("pushButton_up2"));
        pushButton_up2->setGeometry(QRect(560, 940, 81, 81));
        pushButton_up2->setFont(font1);
        pushButton_up2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 1060, 481, 231));
        label_3->setFrameShape(QFrame::Box);
        label_3->setScaledContents(true);
        pushButton_up3 = new QPushButton(groupBox);
        pushButton_up3->setObjectName(QString::fromUtf8("pushButton_up3"));
        pushButton_up3->setGeometry(QRect(560, 1210, 81, 81));
        pushButton_up3->setFont(font1);
        pushButton_up3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(FeedBack);

        QMetaObject::connectSlotsByName(FeedBack);
    } // setupUi

    void retranslateUi(QWidget *FeedBack)
    {
        FeedBack->setWindowTitle(QCoreApplication::translate("FeedBack", "FeedBack", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FeedBack", "\345\217\215\351\246\210\344\277\241\346\201\257", nullptr));
        label_41->setText(QCoreApplication::translate("FeedBack", "\350\257\267\345\206\231\344\270\213\344\275\240\344\277\241\346\201\257\350\246\201\344\277\256\346\224\271\347\232\204\345\234\260\346\226\271\357\274\232", nullptr));
        pushButton_commit->setText(QCoreApplication::translate("FeedBack", "\346\217\220\344\272\244", nullptr));
        label_42->setText(QCoreApplication::translate("FeedBack", "\346\267\273\345\212\240\345\233\276\347\211\207\357\274\210\345\217\257\351\200\211\357\274\214\345\246\202\350\246\201\344\270\212\344\274\240\357\274\214\350\207\263\345\260\221\344\270\212\344\274\2403\345\274\240\357\274\211\357\274\232", nullptr));
        label->setText(QString());
        pushButton_up1->setText(QCoreApplication::translate("FeedBack", "+", nullptr));
        label_2->setText(QString());
        pushButton_up2->setText(QCoreApplication::translate("FeedBack", "+", nullptr));
        label_3->setText(QString());
        pushButton_up3->setText(QCoreApplication::translate("FeedBack", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeedBack: public Ui_FeedBack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACK_H
