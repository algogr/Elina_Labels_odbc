/********************************************************************************
** Form generated from reading UI file 'production.ui'
**
** Created: Mon Oct 11 20:09:46 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTION_H
#define UI_PRODUCTION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_productionClass
{
public:
    QDateEdit *dateEdit;
    QLabel *label;
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QDialog *productionClass)
    {
        if (productionClass->objectName().isEmpty())
            productionClass->setObjectName(QString::fromUtf8("productionClass"));
        productionClass->setWindowModality(Qt::WindowModal);
        productionClass->resize(746, 568);
        productionClass->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Barcode.png"), QSize(), QIcon::Normal, QIcon::Off);
        productionClass->setWindowIcon(icon);
        productionClass->setModal(true);
        dateEdit = new QDateEdit(productionClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(120, 0, 110, 25));
        dateEdit->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);
        label = new QLabel(productionClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 78, 17));
        pushButton = new QPushButton(productionClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 0, 90, 27));
        pushButton->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        tableView = new QTableView(productionClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 30, 741, 531));

        retranslateUi(productionClass);

        QMetaObject::connectSlotsByName(productionClass);
    } // setupUi

    void retranslateUi(QDialog *productionClass)
    {
        productionClass->setWindowTitle(QApplication::translate("productionClass", "\316\240\316\261\317\201\316\261\316\263\317\211\316\263\316\256 \316\227\316\274\316\255\317\201\316\261\317\202", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("productionClass", "d/M/yy", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("productionClass", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("productionClass", "'\316\225\316\276\316\277\316\264\316\277\317\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class productionClass: public Ui_productionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTION_H
