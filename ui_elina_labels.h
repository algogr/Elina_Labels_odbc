/********************************************************************************
** Form generated from reading UI file 'elina_labels.ui'
**
** Created: Tue Nov 23 17:59:27 2010
**      by: Qt User Interface Compiler version 4.6.3
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
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *quitButton;
    QPushButton *getDataButton;
    QPushButton *nextButton;
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

    void setupUi(QDialog *Elina_LabelsClass)
    {
        if (Elina_LabelsClass->objectName().isEmpty())
            Elina_LabelsClass->setObjectName(QString::fromUtf8("Elina_LabelsClass"));
        Elina_LabelsClass->resize(746, 568);
        Elina_LabelsClass->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Barcode.png"), QSize(), QIcon::Selected, QIcon::On);
        Elina_LabelsClass->setWindowIcon(icon);
        Elina_LabelsClass->setLocale(QLocale(QLocale::Greek, QLocale::Greece));
        tableView = new QTableView(Elina_LabelsClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 90, 721, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        tableView->setFont(font);
        horizontalLayoutWidget = new QWidget(Elina_LabelsClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 10, 215, 29));
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

        horizontalLayoutWidget_2 = new QWidget(Elina_LabelsClass);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 480, 337, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        quitButton = new QPushButton(horizontalLayoutWidget_2);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout_2->addWidget(quitButton);

        getDataButton = new QPushButton(horizontalLayoutWidget_2);
        getDataButton->setObjectName(QString::fromUtf8("getDataButton"));
        getDataButton->setEnabled(true);

        horizontalLayout_2->addWidget(getDataButton);

        nextButton = new QPushButton(horizontalLayoutWidget_2);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout_2->addWidget(nextButton);

        label = new QLabel(Elina_LabelsClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 10, 101, 31));
        prodLabel = new QLabel(Elina_LabelsClass);
        prodLabel->setObjectName(QString::fromUtf8("prodLabel"));
        prodLabel->setGeometry(QRect(460, 16, 251, 21));
        qualCombo = new QComboBox(Elina_LabelsClass);
        qualCombo->setObjectName(QString::fromUtf8("qualCombo"));
        qualCombo->setGeometry(QRect(30, 430, 111, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        qualCombo->setFont(font1);
        qualCombo->setMaxVisibleItems(3);
        label_2 = new QLabel(Elina_LabelsClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 400, 191, 17));
        label_3 = new QLabel(Elina_LabelsClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 400, 62, 17));
        weightLineEdit = new QLineEdit(Elina_LabelsClass);
        weightLineEdit->setObjectName(QString::fromUtf8("weightLineEdit"));
        weightLineEdit->setGeometry(QRect(240, 430, 113, 27));
        aaSpinBox = new QSpinBox(Elina_LabelsClass);
        aaSpinBox->setObjectName(QString::fromUtf8("aaSpinBox"));
        aaSpinBox->setGeometry(QRect(550, 430, 55, 27));
        aaSpinBox->setMinimumSize(QSize(55, 27));
        aaSpinBox->setMaximumSize(QSize(55, 27));
        aaSpinBox->setMinimum(0);
        aaSpinBox->setValue(0);
        label_4 = new QLabel(Elina_LabelsClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(560, 400, 31, 17));
        label_6 = new QLabel(Elina_LabelsClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(371, 400, 161, 20));
        middleDateEdit = new QDateEdit(Elina_LabelsClass);
        middleDateEdit->setObjectName(QString::fromUtf8("middleDateEdit"));
        middleDateEdit->setGeometry(QRect(390, 430, 110, 27));
        middleDateEdit->setDateTime(QDateTime(QDate(2010, 1, 1), QTime(0, 0, 0)));
        middleDateEdit->setCalendarPopup(true);
        label_5 = new QLabel(Elina_LabelsClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(640, 400, 62, 17));
        machinespinBox = new QSpinBox(Elina_LabelsClass);
        machinespinBox->setObjectName(QString::fromUtf8("machinespinBox"));
        machinespinBox->setGeometry(QRect(650, 430, 50, 25));
        machinespinBox->setMinimum(1);
        machinespinBox->setMaximum(2);
        dummycheckBox = new QCheckBox(Elina_LabelsClass);
        dummycheckBox->setObjectName(QString::fromUtf8("dummycheckBox"));
        dummycheckBox->setGeometry(QRect(400, 510, 92, 22));

        retranslateUi(Elina_LabelsClass);

        QMetaObject::connectSlotsByName(Elina_LabelsClass);
    } // setupUi

    void retranslateUi(QDialog *Elina_LabelsClass)
    {
        Elina_LabelsClass->setWindowTitle(QApplication::translate("Elina_LabelsClass", "\316\225\317\204\316\271\316\272\316\255\317\204\316\265\317\202", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("Elina_LabelsClass", "\316\232\317\211\316\264\316\271\316\272\317\214\317\202:", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("Elina_LabelsClass", "Quit", 0, QApplication::UnicodeUTF8));
        getDataButton->setText(QApplication::translate("Elina_LabelsClass", "Get Data", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("Elina_LabelsClass", "\316\225\317\200\317\214\316\274\316\265\316\275\316\277", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Elina_LabelsClass", "\316\240\317\201\316\277\316\264\316\271\316\261\316\263\317\201\316\261\317\206\316\256", 0, QApplication::UnicodeUTF8));
        prodLabel->setText(QString());
        label_2->setText(QApplication::translate("Elina_LabelsClass", "\316\240\316\277\316\271\316\277\317\204\316\271\316\272\317\214\317\202 \316\247\316\261\317\201\316\261\316\272\317\204\316\267\317\201\316\271\317\203\316\274\317\214\317\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Elina_LabelsClass", "\316\226\317\215\316\263\316\271\317\203\316\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Elina_LabelsClass", "\316\221/\316\221", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Elina_LabelsClass", "\316\227\316\274\316\265\317\201\316\277\316\274\316\267\316\275\316\257\316\261 \316\225\316\275\316\264\316\271\316\254\316\274\316\265\317\203\316\277\317\205", 0, QApplication::UnicodeUTF8));
        middleDateEdit->setDisplayFormat(QApplication::translate("Elina_LabelsClass", "yy/MM/dd", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Elina_LabelsClass", "\316\234\316\267\317\207\316\261\316\275\316\256", 0, QApplication::UnicodeUTF8));
        dummycheckBox->setText(QApplication::translate("Elina_LabelsClass", "Dummy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Elina_LabelsClass: public Ui_Elina_LabelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELINA_LABELS_H
