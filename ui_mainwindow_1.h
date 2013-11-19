/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 15 16:28:31 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindowClass
{
public:
    QAction *action;
    QAction *action_3;
    QAction *action3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *actionProductio;
    QAction *action3A;
    QAction *actionK_T;
    QAction *action_8;
    QAction *action_2;
    QAction *action_9;
    QAction *actionProduction;
    QAction *action3A_2;
    QAction *actionK_T_2;
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *mainWindowClass)
    {
        if (mainWindowClass->objectName().isEmpty())
            mainWindowClass->setObjectName(QString::fromUtf8("mainWindowClass"));
        mainWindowClass->setWindowModality(Qt::NonModal);
        mainWindowClass->resize(1024, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Barcode.png"), QSize(), QIcon::Normal, QIcon::On);
        mainWindowClass->setWindowIcon(icon);
        mainWindowClass->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        action = new QAction(mainWindowClass);
        action->setObjectName(QString::fromUtf8("action"));
        action_3 = new QAction(mainWindowClass);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action3 = new QAction(mainWindowClass);
        action3->setObjectName(QString::fromUtf8("action3"));
        action_4 = new QAction(mainWindowClass);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(mainWindowClass);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(mainWindowClass);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_7 = new QAction(mainWindowClass);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        actionProductio = new QAction(mainWindowClass);
        actionProductio->setObjectName(QString::fromUtf8("actionProductio"));
        action3A = new QAction(mainWindowClass);
        action3A->setObjectName(QString::fromUtf8("action3A"));
        actionK_T = new QAction(mainWindowClass);
        actionK_T->setObjectName(QString::fromUtf8("actionK_T"));
        action_8 = new QAction(mainWindowClass);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        action_2 = new QAction(mainWindowClass);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_9 = new QAction(mainWindowClass);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        actionProduction = new QAction(mainWindowClass);
        actionProduction->setObjectName(QString::fromUtf8("actionProduction"));
        action3A_2 = new QAction(mainWindowClass);
        action3A_2->setObjectName(QString::fromUtf8("action3A_2"));
        actionK_T_2 = new QAction(mainWindowClass);
        actionK_T_2->setObjectName(QString::fromUtf8("actionK_T_2"));
        centralwidget = new QWidget(mainWindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainWindowClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(mainWindowClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainWindowClass->setStatusBar(statusbar);
        menuBar = new QMenuBar(mainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        mainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_2);
        menu->addAction(action_9);
        menu_2->addAction(actionProduction);
        menu_2->addAction(action3A_2);
        menu_2->addAction(actionK_T_2);

        retranslateUi(mainWindowClass);

        QMetaObject::connectSlotsByName(mainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindowClass)
    {
        mainWindowClass->setWindowTitle(QApplication::translate("mainWindowClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("mainWindowClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("mainWindowClass", "\316\240\316\261\317\201\316\261\316\263\317\211\316\263\316\256 \316\227\316\274\316\255\317\201\316\261\317\202", 0, QApplication::UnicodeUTF8));
        action3->setText(QApplication::translate("mainWindowClass", "3\316\221", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("mainWindowClass", "\316\232\317\211\316\264\316\271\316\272\316\277\316\257 \316\244\316\261\317\205\317\204\316\277\317\200\316\277\316\257\316\267\317\203\316\267\317\202", 0, QApplication::UnicodeUTF8));
        action_5->setText(QApplication::translate("mainWindowClass", "\316\221\316\273\316\273\316\261\316\263\316\256 \317\207\316\265\316\271\317\201\316\271\317\203\317\204\316\256", 0, QApplication::UnicodeUTF8));
        action_6->setText(QApplication::translate("mainWindowClass", "\316\221\316\275\316\261\317\206\316\277\317\201\316\255\317\202", 0, QApplication::UnicodeUTF8));
        action_7->setText(QApplication::translate("mainWindowClass", "\316\240\316\261\317\201\316\261\316\263\317\211\316\263\316\256", 0, QApplication::UnicodeUTF8));
        actionProductio->setText(QApplication::translate("mainWindowClass", "Production", 0, QApplication::UnicodeUTF8));
        action3A->setText(QApplication::translate("mainWindowClass", "3A", 0, QApplication::UnicodeUTF8));
        actionK_T->setText(QApplication::translate("mainWindowClass", "K/T", 0, QApplication::UnicodeUTF8));
        action_8->setText(QApplication::translate("mainWindowClass", "\316\221\316\273\316\273\316\261\316\263\316\256 \316\247\316\265\316\271\317\201\316\271\317\203\317\204\316\256", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("mainWindowClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        action_9->setText(QApplication::translate("mainWindowClass", "\316\221\316\273\316\273\316\261\316\263\316\256 \316\247\316\265\316\271\317\201\316\271\317\203\317\204\316\256", 0, QApplication::UnicodeUTF8));
        actionProduction->setText(QApplication::translate("mainWindowClass", "Production", 0, QApplication::UnicodeUTF8));
        action3A_2->setText(QApplication::translate("mainWindowClass", "3A", 0, QApplication::UnicodeUTF8));
        actionK_T_2->setText(QApplication::translate("mainWindowClass", "K/T", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("mainWindowClass", "\316\224\316\271\316\261\317\207\316\265\316\257\317\201\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("mainWindowClass", "\316\221\316\275\316\261\317\206\316\277\317\201\316\255\317\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainWindowClass: public Ui_mainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
