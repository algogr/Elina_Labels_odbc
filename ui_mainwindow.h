/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 27 12:45:33 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_mainwindowClass
{
public:
    QAction *action;
    QAction *action_2;
    QAction *actionProduction;
    QAction *action3A;
    QAction *actionK_T;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QString::fromUtf8("mainwindowClass"));
        mainwindowClass->resize(1024, 768);
        action = new QAction(mainwindowClass);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(mainwindowClass);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionProduction = new QAction(mainwindowClass);
        actionProduction->setObjectName(QString::fromUtf8("actionProduction"));
        action3A = new QAction(mainwindowClass);
        action3A->setObjectName(QString::fromUtf8("action3A"));
        actionK_T = new QAction(mainwindowClass);
        actionK_T->setObjectName(QString::fromUtf8("actionK_T"));
        centralwidget = new QWidget(mainwindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainwindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindowClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        mainwindowClass->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindowClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainwindowClass->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu_2->addAction(actionProduction);
        menu_2->addAction(action3A);
        menu_2->addAction(actionK_T);

        retranslateUi(mainwindowClass);

        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QApplication::translate("mainwindowClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("mainwindowClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("mainwindowClass", "\316\221\316\273\316\273\316\261\316\263\316\256 \316\247\316\265\316\271\317\201\316\271\317\203\317\204\316\256", 0, QApplication::UnicodeUTF8));
        actionProduction->setText(QApplication::translate("mainwindowClass", "Production", 0, QApplication::UnicodeUTF8));
        action3A->setText(QApplication::translate("mainwindowClass", "3A", 0, QApplication::UnicodeUTF8));
        actionK_T->setText(QApplication::translate("mainwindowClass", "K/T", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("mainwindowClass", "\316\224\316\271\316\261\317\207\316\265\316\257\317\201\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("mainwindowClass", "\316\221\316\275\316\261\317\206\316\277\317\201\316\255\317\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
