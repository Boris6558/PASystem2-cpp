/********************************************************************************
** Form generated from reading UI file 'PAType.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATYPE_H
#define UI_PATYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PAType
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton_alter_passwd;

    void setupUi(QWidget *PAType)
    {
        if (PAType->objectName().isEmpty())
            PAType->setObjectName(QString::fromUtf8("PAType"));
        PAType->resize(316, 142);
        comboBox = new QComboBox(PAType);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 30, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        comboBox->setFont(font);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setFrame(false);
        label = new QLabel(PAType);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 131, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(13);
        label->setFont(font1);
        pushButton_alter_passwd = new QPushButton(PAType);
        pushButton_alter_passwd->setObjectName(QString::fromUtf8("pushButton_alter_passwd"));
        pushButton_alter_passwd->setGeometry(QRect(100, 90, 101, 41));

        retranslateUi(PAType);

        QMetaObject::connectSlotsByName(PAType);
    } // setupUi

    void retranslateUi(QWidget *PAType)
    {
        PAType->setWindowTitle(QCoreApplication::translate("PAType", "PAType", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("PAType", "\346\234\210\345\272\246\350\200\203\346\240\270", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("PAType", "\345\255\243\345\272\246\350\200\203\346\240\270", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("PAType", "\345\215\212\345\271\264\345\272\246\350\200\203\346\240\270", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("PAType", "\345\271\264\345\272\246\350\200\203\346\240\270", nullptr));

        label->setText(QCoreApplication::translate("PAType", "\351\200\211\346\213\251\350\200\203\346\240\270\346\234\237:", nullptr));
        pushButton_alter_passwd->setText(QCoreApplication::translate("PAType", "\345\217\221\350\265\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PAType: public Ui_PAType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATYPE_H
