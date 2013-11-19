/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Thu Jun 27 12:45:33 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userlineEdit;
    QLineEdit *passlineEdit_2;
    QPushButton *okButton;

    void setupUi(QDialog *loginClass)
    {
        if (loginClass->objectName().isEmpty())
            loginClass->setObjectName(QString::fromUtf8("loginClass"));
        loginClass->resize(400, 109);
        label = new QLabel(loginClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 67, 33));
        label_2 = new QLabel(loginClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 60, 62, 17));
        userlineEdit = new QLineEdit(loginClass);
        userlineEdit->setObjectName(QString::fromUtf8("userlineEdit"));
        userlineEdit->setGeometry(QRect(150, 20, 113, 25));
        passlineEdit_2 = new QLineEdit(loginClass);
        passlineEdit_2->setObjectName(QString::fromUtf8("passlineEdit_2"));
        passlineEdit_2->setGeometry(QRect(150, 60, 113, 25));
        passlineEdit_2->setEchoMode(QLineEdit::Password);
        okButton = new QPushButton(loginClass);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(280, 40, 90, 27));

        retranslateUi(loginClass);

        QMetaObject::connectSlotsByName(loginClass);
    } // setupUi

    void retranslateUi(QDialog *loginClass)
    {
        loginClass->setWindowTitle(QApplication::translate("loginClass", "\316\225\316\257\317\203\316\277\316\264\316\277\317\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("loginClass", "Username\n"
"", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("loginClass", "Password", 0, QApplication::UnicodeUTF8));
        userlineEdit->setText(QApplication::translate("loginClass", "user", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("loginClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loginClass: public Ui_loginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
