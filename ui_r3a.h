/********************************************************************************
** Form generated from reading UI file 'r3a.ui'
**
** Created: Thu Jun 27 12:45:33 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_R3A_H
#define UI_R3A_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_r3AClass
{
public:
    QDateEdit *dateEdit;
    QPushButton *updateButton;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *r3AClass)
    {
        if (r3AClass->objectName().isEmpty())
            r3AClass->setObjectName(QString::fromUtf8("r3AClass"));
        r3AClass->resize(746, 568);
        dateEdit = new QDateEdit(r3AClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(110, 0, 110, 26));
        dateEdit->setCalendarPopup(true);
        updateButton = new QPushButton(r3AClass);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(420, 0, 91, 27));
        label = new QLabel(r3AClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 81, 21));
        tableWidget = new QTableWidget(r3AClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 50, 731, 501));

        retranslateUi(r3AClass);

        QMetaObject::connectSlotsByName(r3AClass);
    } // setupUi

    void retranslateUi(QDialog *r3AClass)
    {
        r3AClass->setWindowTitle(QApplication::translate("r3AClass", "\316\244\316\261\316\272\317\204\316\277\317\200\316\277\316\257\316\267\317\203\316\267 3\316\221", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("r3AClass", "d/M/yy", 0, QApplication::UnicodeUTF8));
        updateButton->setText(QApplication::translate("r3AClass", "\316\225\316\275\316\267\316\274\316\255\317\201\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("r3AClass", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class r3AClass: public Ui_r3AClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R3A_H
