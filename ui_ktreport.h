/********************************************************************************
** Form generated from reading UI file 'ktreport.ui'
**
** Created: Thu Jun 27 12:45:33 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KTREPORT_H
#define UI_KTREPORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ktreportClass
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QTableView *tableView;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *lpr_date;
    QLabel *lf_code;
    QLabel *lcode_t;
    QLabel *lweight;
    QLabel *lquality;
    QLabel *lmiddle;
    QLabel *lmiddle_2;
    QLabel *lmiddle_3;
    QLabel *liskef;
    QLabel *lvardia;

    void setupUi(QDialog *ktreportClass)
    {
        if (ktreportClass->objectName().isEmpty())
            ktreportClass->setObjectName(QString::fromUtf8("ktreportClass"));
        ktreportClass->resize(746, 269);
        lineEdit = new QLineEdit(ktreportClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 181, 26));
        label = new QLabel(ktreportClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 61, 16));
        tableView = new QTableView(ktreportClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 50, 381, 192));
        line = new QFrame(ktreportClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(400, 0, 20, 271));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(ktreportClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 0, 136, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        layoutWidget1 = new QWidget(ktreportClass);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(580, 0, 171, 271));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lpr_date = new QLabel(layoutWidget1);
        lpr_date->setObjectName(QString::fromUtf8("lpr_date"));

        verticalLayout_2->addWidget(lpr_date);

        lf_code = new QLabel(layoutWidget1);
        lf_code->setObjectName(QString::fromUtf8("lf_code"));

        verticalLayout_2->addWidget(lf_code);

        lcode_t = new QLabel(layoutWidget1);
        lcode_t->setObjectName(QString::fromUtf8("lcode_t"));

        verticalLayout_2->addWidget(lcode_t);

        lweight = new QLabel(layoutWidget1);
        lweight->setObjectName(QString::fromUtf8("lweight"));

        verticalLayout_2->addWidget(lweight);

        lquality = new QLabel(layoutWidget1);
        lquality->setObjectName(QString::fromUtf8("lquality"));

        verticalLayout_2->addWidget(lquality);

        lmiddle = new QLabel(layoutWidget1);
        lmiddle->setObjectName(QString::fromUtf8("lmiddle"));

        verticalLayout_2->addWidget(lmiddle);

        lmiddle_2 = new QLabel(layoutWidget1);
        lmiddle_2->setObjectName(QString::fromUtf8("lmiddle_2"));

        verticalLayout_2->addWidget(lmiddle_2);

        lmiddle_3 = new QLabel(layoutWidget1);
        lmiddle_3->setObjectName(QString::fromUtf8("lmiddle_3"));

        verticalLayout_2->addWidget(lmiddle_3);

        liskef = new QLabel(layoutWidget1);
        liskef->setObjectName(QString::fromUtf8("liskef"));

        verticalLayout_2->addWidget(liskef);

        lvardia = new QLabel(layoutWidget1);
        lvardia->setObjectName(QString::fromUtf8("lvardia"));

        verticalLayout_2->addWidget(lvardia);


        retranslateUi(ktreportClass);

        QMetaObject::connectSlotsByName(ktreportClass);
    } // setupUi

    void retranslateUi(QDialog *ktreportClass)
    {
        ktreportClass->setWindowTitle(QApplication::translate("ktreportClass", "\316\221\316\275\316\261\316\266\316\256\317\204\316\267\317\203\316\267 \316\232/\316\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ktreportClass", "\316\232/\316\244", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ktreportClass", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ktreportClass", "\316\232\317\211\316\264.\316\240\317\211\316\273\316\277\317\205\316\274\316\255\316\275\316\277\317\205", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ktreportClass", "\316\232/\316\244", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ktreportClass", "\316\222\316\254\317\201\316\277\317\202", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ktreportClass", "\316\240\316\277\316\271\317\214\317\204\316\267\317\204\316\261", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ktreportClass", "\316\232\317\211\316\264.\316\225\316\275\316\264\316\271\316\261\316\274\316\255\317\203\316\277\317\205", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ktreportClass", "\316\232\317\211\316\264. 2\316\277\317\205 \316\225\316\275\316\264\316\271\316\261\316\274\316\255\317\203\316\277\317\205", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ktreportClass", "\316\232\317\211\316\264. 3\316\277\317\205 \316\225\316\275\316\264\316\271\316\261\316\274\316\255\317\203\316\277\317\205", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ktreportClass", "KEF", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ktreportClass", "\316\222\316\254\317\201\316\264\316\271\316\261", 0, QApplication::UnicodeUTF8));
        lpr_date->setText(QString());
        lf_code->setText(QString());
        lcode_t->setText(QString());
        lweight->setText(QString());
        lquality->setText(QString());
        lmiddle->setText(QString());
        lmiddle_2->setText(QString());
        lmiddle_3->setText(QString());
        liskef->setText(QString());
        lvardia->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ktreportClass: public Ui_ktreportClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KTREPORT_H
