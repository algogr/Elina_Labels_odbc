
/********************************************************************************
** Form generated from reading UI file 'scanlabels.ui'
**
** Created: Mon Sep 27 13:50:15 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANLABELS_H
#define UI_SCANLABELS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scanlabelsClass
{
public:
    QLineEdit *scanlineEdit;
    QLabel *scanLabel;
    QTableWidget *scantableWidget;
    QPushButton *contpushButton;

    void setupUi(QDialog *scanlabelsClass)
    {
        if (scanlabelsClass->objectName().isEmpty())
            scanlabelsClass->setObjectName(QString::fromUtf8("scanlabelsClass"));
        scanlabelsClass->resize(400, 321);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Barcode.png"), QSize(), QIcon::Selected, QIcon::On);
        scanlabelsClass->setWindowIcon(icon);

        scanlineEdit = new QLineEdit(scanlabelsClass);
        scanlineEdit->setObjectName(QString::fromUtf8("scanlineEdit"));
        scanlineEdit->setGeometry(QRect(100, 30, 221, 25));
        scanLabel = new QLabel(scanlabelsClass);
        scanLabel->setObjectName(QString::fromUtf8("scanLabel"));
        scanLabel->setGeometry(QRect(20, 30, 62, 17));
        scantableWidget = new QTableWidget(scanlabelsClass);
        scantableWidget->setObjectName(QString::fromUtf8("scantableWidget"));
        scantableWidget->setGeometry(QRect(10, 80, 371, 192));
        scantableWidget->setRowCount(0);
        scantableWidget->setColumnCount(0);
        scantableWidget->verticalHeader()->setVisible(false);
        contpushButton = new QPushButton(scanlabelsClass);
        contpushButton->setObjectName(QString::fromUtf8("contpushButton"));
        contpushButton->setGeometry(QRect(40, 280, 90, 27));

        retranslateUi(scanlabelsClass);

        QMetaObject::connectSlotsByName(scanlabelsClass);
    } // setupUi

    void retranslateUi(QDialog *scanlabelsClass)
    {
        scanlabelsClass->setWindowTitle(QApplication::translate("scanlabelsClass", "\316\221\316\275\316\254\316\263\316\275\317\211\317\203\316\267 \316\225\317\204\316\271\316\272\316\265\317\204\317\216\316\275", 0, QApplication::UnicodeUTF8));
        scanLabel->setText(QApplication::translate("scanlabelsClass", "Scan", 0, QApplication::UnicodeUTF8));
        contpushButton->setText(QApplication::translate("scanlabelsClass", "\316\243\317\205\316\275\316\255\317\207\316\265\316\271\316\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class scanlabelsClass: public Ui_scanlabelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANLABELS_H
