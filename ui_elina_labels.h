/********************************************************************************
** Form generated from reading UI file 'elina_labels.ui'
**
** Created: Thu Jun 27 12:45:33 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELINA_LABELS_H
#define UI_ELINA_LABELS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elina_LabelsClass
{
public:
    QTableView *tableView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *codeLabel;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *prodLabel;
    QComboBox *qualCombo;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *weightLineEdit;
    QSpinBox *aaSpinBox;
    QLabel *label_4;
    QLabel *label_6;
    QDateEdit *middleDateEdit;
    QLabel *label_5;
    QSpinBox *machinespinBox;
    QCheckBox *dummycheckBox;
    QPushButton *quitButton;
    QPushButton *nextButton;
    QPushButton *insertButton;
    QPushButton *removeButton;
    QTableWidget *codeTableWidget;
    QTableWidget *productiontableWidget;
    QSpinBox *machinespinBox_2;
    QDateEdit *middleDateEdit_2;
    QSpinBox *aaSpinBox_2;
    QSpinBox *aaSpinBox_3;
    QDateEdit *middleDateEdit_3;
    QSpinBox *machinespinBox_3;
    QLineEdit *scanlineEdit;
    QLabel *label_7;
    QPushButton *acpushButton;
    QPushButton *upButton;
    QPushButton *downButton;
    QCheckBox *checkBox;
    QPushButton *pushrewrap;
    QPushButton *pushDelPro;
    QDateEdit *dummyProdDate;
    QComboBox *dummyVardiaCombo;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QDialog *Elina_LabelsClass)
    {
        if (Elina_LabelsClass->objectName().isEmpty())
            Elina_LabelsClass->setObjectName(QString::fromUtf8("Elina_LabelsClass"));
        Elina_LabelsClass->resize(1200, 1000);
        Elina_LabelsClass->setMaximumSize(QSize(16777214, 16777215));
        Elina_LabelsClass->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Barcode.png"), QSize(), QIcon::Selected, QIcon::On);
        Elina_LabelsClass->setWindowIcon(icon);
        Elina_LabelsClass->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        tableView = new QTableView(Elina_LabelsClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 90, 590, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        tableView->setFont(font);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        horizontalLayoutWidget = new QWidget(Elina_LabelsClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 10, 215, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        codeLabel = new QLabel(horizontalLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));

        horizontalLayout->addWidget(codeLabel);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(Elina_LabelsClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 10, 101, 71));
        prodLabel = new QLabel(Elina_LabelsClass);
        prodLabel->setObjectName(QString::fromUtf8("prodLabel"));
        prodLabel->setGeometry(QRect(380, 30, 191, 31));
        qualCombo = new QComboBox(Elina_LabelsClass);
        qualCombo->setObjectName(QString::fromUtf8("qualCombo"));
        qualCombo->setGeometry(QRect(730, 580, 171, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        qualCombo->setFont(font1);
        qualCombo->setMaxVisibleItems(4);
        qualCombo->setIconSize(QSize(32, 32));
        label_2 = new QLabel(Elina_LabelsClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(730, 560, 191, 17));
        label_3 = new QLabel(Elina_LabelsClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(920, 560, 62, 17));
        weightLineEdit = new QLineEdit(Elina_LabelsClass);
        weightLineEdit->setObjectName(QString::fromUtf8("weightLineEdit"));
        weightLineEdit->setGeometry(QRect(920, 580, 113, 41));
        QFont font2;
        font2.setPointSize(15);
        weightLineEdit->setFont(font2);
        aaSpinBox = new QSpinBox(Elina_LabelsClass);
        aaSpinBox->setObjectName(QString::fromUtf8("aaSpinBox"));
        aaSpinBox->setGeometry(QRect(1030, 490, 111, 61));
        aaSpinBox->setMinimumSize(QSize(55, 27));
        aaSpinBox->setFont(font2);
        aaSpinBox->setMinimum(0);
        aaSpinBox->setValue(0);
        label_4 = new QLabel(Elina_LabelsClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1030, 470, 31, 17));
        label_6 = new QLabel(Elina_LabelsClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(860, 470, 161, 20));
        middleDateEdit = new QDateEdit(Elina_LabelsClass);
        middleDateEdit->setObjectName(QString::fromUtf8("middleDateEdit"));
        middleDateEdit->setGeometry(QRect(860, 490, 141, 41));
        middleDateEdit->setFont(font2);
        middleDateEdit->setDateTime(QDateTime(QDate(2010, 1, 1), QTime(0, 0, 0)));
        middleDateEdit->setCalendarPopup(true);
        label_5 = new QLabel(Elina_LabelsClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(730, 470, 62, 17));
        machinespinBox = new QSpinBox(Elina_LabelsClass);
        machinespinBox->setObjectName(QString::fromUtf8("machinespinBox"));
        machinespinBox->setGeometry(QRect(730, 490, 101, 61));
        machinespinBox->setFont(font2);
        machinespinBox->setMinimum(0);
        machinespinBox->setMaximum(2);
        machinespinBox->setValue(0);
        dummycheckBox = new QCheckBox(Elina_LabelsClass);
        dummycheckBox->setObjectName(QString::fromUtf8("dummycheckBox"));
        dummycheckBox->setGeometry(QRect(920, 790, 91, 21));
        quitButton = new QPushButton(Elina_LabelsClass);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setEnabled(false);
        quitButton->setGeometry(QRect(380, 410, 131, 51));
        nextButton = new QPushButton(Elina_LabelsClass);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(730, 770, 164, 51));
        insertButton = new QPushButton(Elina_LabelsClass);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(610, 140, 101, 61));
        QFont font3;
        font3.setPointSize(30);
        insertButton->setFont(font3);
        insertButton->setStyleSheet(QString::fromUtf8(""));
        removeButton = new QPushButton(Elina_LabelsClass);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(610, 240, 101, 61));
        removeButton->setFont(font3);
        codeTableWidget = new QTableWidget(Elina_LabelsClass);
        if (codeTableWidget->columnCount() < 2)
            codeTableWidget->setColumnCount(2);
        codeTableWidget->setObjectName(QString::fromUtf8("codeTableWidget"));
        codeTableWidget->setGeometry(QRect(730, 10, 390, 461));
        codeTableWidget->setColumnCount(2);
        productiontableWidget = new QTableWidget(Elina_LabelsClass);
        if (productiontableWidget->columnCount() < 7)
            productiontableWidget->setColumnCount(7);
        productiontableWidget->setObjectName(QString::fromUtf8("productiontableWidget"));
        productiontableWidget->setGeometry(QRect(10, 610, 710, 371));
        productiontableWidget->setColumnCount(7);
        machinespinBox_2 = new QSpinBox(Elina_LabelsClass);
        machinespinBox_2->setObjectName(QString::fromUtf8("machinespinBox_2"));
        machinespinBox_2->setGeometry(QRect(730, 630, 101, 61));
        machinespinBox_2->setFont(font2);
        machinespinBox_2->setMinimum(0);
        machinespinBox_2->setMaximum(2);
        machinespinBox_2->setValue(0);
        middleDateEdit_2 = new QDateEdit(Elina_LabelsClass);
        middleDateEdit_2->setObjectName(QString::fromUtf8("middleDateEdit_2"));
        middleDateEdit_2->setGeometry(QRect(870, 640, 141, 41));
        middleDateEdit_2->setFont(font2);
        middleDateEdit_2->setDateTime(QDateTime(QDate(2010, 1, 1), QTime(0, 0, 0)));
        middleDateEdit_2->setCalendarPopup(true);
        aaSpinBox_2 = new QSpinBox(Elina_LabelsClass);
        aaSpinBox_2->setObjectName(QString::fromUtf8("aaSpinBox_2"));
        aaSpinBox_2->setGeometry(QRect(1040, 630, 111, 61));
        aaSpinBox_2->setMinimumSize(QSize(55, 27));
        aaSpinBox_2->setFont(font2);
        aaSpinBox_2->setMinimum(0);
        aaSpinBox_2->setValue(0);
        aaSpinBox_3 = new QSpinBox(Elina_LabelsClass);
        aaSpinBox_3->setObjectName(QString::fromUtf8("aaSpinBox_3"));
        aaSpinBox_3->setGeometry(QRect(1040, 700, 111, 61));
        aaSpinBox_3->setMinimumSize(QSize(55, 27));
        aaSpinBox_3->setFont(font2);
        aaSpinBox_3->setMinimum(0);
        aaSpinBox_3->setValue(0);
        middleDateEdit_3 = new QDateEdit(Elina_LabelsClass);
        middleDateEdit_3->setObjectName(QString::fromUtf8("middleDateEdit_3"));
        middleDateEdit_3->setGeometry(QRect(870, 710, 141, 41));
        middleDateEdit_3->setFont(font2);
        middleDateEdit_3->setDateTime(QDateTime(QDate(2010, 1, 1), QTime(0, 0, 0)));
        middleDateEdit_3->setCalendarPopup(true);
        machinespinBox_3 = new QSpinBox(Elina_LabelsClass);
        machinespinBox_3->setObjectName(QString::fromUtf8("machinespinBox_3"));
        machinespinBox_3->setGeometry(QRect(730, 700, 101, 61));
        machinespinBox_3->setFont(font2);
        machinespinBox_3->setMinimum(0);
        machinespinBox_3->setMaximum(2);
        machinespinBox_3->setValue(0);
        scanlineEdit = new QLineEdit(Elina_LabelsClass);
        scanlineEdit->setObjectName(QString::fromUtf8("scanlineEdit"));
        scanlineEdit->setGeometry(QRect(170, 550, 221, 41));
        label_7 = new QLabel(Elina_LabelsClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 550, 91, 41));
        acpushButton = new QPushButton(Elina_LabelsClass);
        acpushButton->setObjectName(QString::fromUtf8("acpushButton"));
        acpushButton->setGeometry(QRect(10, 10, 61, 71));
        upButton = new QPushButton(Elina_LabelsClass);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(1140, 70, 51, 81));
        QFont font4;
        font4.setPointSize(35);
        font4.setBold(true);
        font4.setWeight(75);
        upButton->setFont(font4);
        downButton = new QPushButton(Elina_LabelsClass);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(1140, 160, 51, 81));
        QFont font5;
        font5.setPointSize(30);
        font5.setBold(true);
        font5.setWeight(75);
        downButton->setFont(font5);
        checkBox = new QCheckBox(Elina_LabelsClass);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(430, 550, 111, 41));
        pushrewrap = new QPushButton(Elina_LabelsClass);
        pushrewrap->setObjectName(QString::fromUtf8("pushrewrap"));
        pushrewrap->setGeometry(QRect(1030, 770, 161, 51));
        pushDelPro = new QPushButton(Elina_LabelsClass);
        pushDelPro->setObjectName(QString::fromUtf8("pushDelPro"));
        pushDelPro->setGeometry(QRect(540, 550, 121, 41));
        dummyProdDate = new QDateEdit(Elina_LabelsClass);
        dummyProdDate->setObjectName(QString::fromUtf8("dummyProdDate"));
        dummyProdDate->setGeometry(QRect(730, 850, 141, 41));
        dummyProdDate->setFont(font2);
        dummyProdDate->setDateTime(QDateTime(QDate(2010, 1, 1), QTime(0, 0, 0)));
        dummyProdDate->setCalendarPopup(true);
        dummyVardiaCombo = new QComboBox(Elina_LabelsClass);
        dummyVardiaCombo->setObjectName(QString::fromUtf8("dummyVardiaCombo"));
        dummyVardiaCombo->setGeometry(QRect(950, 850, 161, 41));
        dummyVardiaCombo->setFont(font1);
        dummyVardiaCombo->setMaxVisibleItems(4);
        dummyVardiaCombo->setIconSize(QSize(32, 32));
        label_8 = new QLabel(Elina_LabelsClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(730, 830, 191, 17));
        label_9 = new QLabel(Elina_LabelsClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(950, 830, 191, 17));

        retranslateUi(Elina_LabelsClass);

        QMetaObject::connectSlotsByName(Elina_LabelsClass);
    } // setupUi

    void retranslateUi(QDialog *Elina_LabelsClass)
    {
        Elina_LabelsClass->setWindowTitle(QApplication::translate("Elina_LabelsClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("Elina_LabelsClass", "\316\232\317\211\316\264\316\271\316\272\317\214\317\202:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Elina_LabelsClass", "\316\240\317\201\316\277\316\264\316\271\316\261\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        prodLabel->setText(QString());
        label_2->setText(QApplication::translate("Elina_LabelsClass", "\316\240\316\277\316\271\316\277\317\204\316\271\316\272\317\214\317\202 \316\247\316\261\317\201\316\261\316\272\317\204\316\267\317\201\316\271\317\203\316\274\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Elina_LabelsClass", "\316\226\317\215\316\263\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Elina_LabelsClass", "\316\221/\316\221", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Elina_LabelsClass", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261 \316\225\316\275\316\264\316\271\316\254\316\274\316\265\317\203\316\277\317\205", 0, QApplication::UnicodeUTF8));
        middleDateEdit->setDisplayFormat(QApplication::translate("Elina_LabelsClass", "yy/MM/dd", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Elina_LabelsClass", "\316\234\316\267\317\207\316\261\316\275\316\256", 0, QApplication::UnicodeUTF8));
        dummycheckBox->setText(QApplication::translate("Elina_LabelsClass", "Dummy", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("Elina_LabelsClass", "\316\225\316\276\316\277\316\264\316\277\317\202", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("Elina_LabelsClass", "\316\225\316\272\317\204\317\215\317\200\317\211\317\203\316\267", 0, QApplication::UnicodeUTF8));
        insertButton->setText(QApplication::translate("Elina_LabelsClass", ">>", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("Elina_LabelsClass", "<<", 0, QApplication::UnicodeUTF8));
        middleDateEdit_2->setDisplayFormat(QApplication::translate("Elina_LabelsClass", "yy/MM/dd", 0, QApplication::UnicodeUTF8));
        middleDateEdit_3->setDisplayFormat(QApplication::translate("Elina_LabelsClass", "yy/MM/dd", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Elina_LabelsClass", "SCANNER", 0, QApplication::UnicodeUTF8));
        acpushButton->setText(QApplication::translate("Elina_LabelsClass", "AC", 0, QApplication::UnicodeUTF8));
        upButton->setText(QApplication::translate("Elina_LabelsClass", "^", 0, QApplication::UnicodeUTF8));
        downButton->setText(QApplication::translate("Elina_LabelsClass", "v", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Elina_LabelsClass", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        pushrewrap->setText(QApplication::translate("Elina_LabelsClass", "\316\221\316\275\316\261\317\204\317\215\316\273\316\271\316\276\316\267", 0, QApplication::UnicodeUTF8));
        pushDelPro->setText(QApplication::translate("Elina_LabelsClass", "\316\224\316\271\316\261\316\263\317\201\316\261\317\206\316\256 \316\240\316\261\317\201\316\261\316\263\317\211\316\263\316\256\317\202", 0, QApplication::UnicodeUTF8));
        dummyProdDate->setDisplayFormat(QApplication::translate("Elina_LabelsClass", "yy/MM/dd", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Elina_LabelsClass", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261 \316\240\316\261\317\201\316\261\316\263\317\211\316\263\316\256\317\202", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Elina_LabelsClass", "\316\222\316\254\317\201\316\264\316\271\316\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Elina_LabelsClass: public Ui_Elina_LabelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELINA_LABELS_H
