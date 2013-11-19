/*
    Elina Labels Production Logging
    Copyright (C) 2012 Dimitris PAraschou

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef ELINA_LABELS_H
#define ELINA_LABELS_H

#include <QtGui/QWidget>
#include <QtGui/QDialog>
#include <QtGui/QMessageBox>
#include <QtNetwork>
#include <QtSql>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QVector>
#include "ui_elina_labels.h"
#include "constants.h"
#include "mainwindow.h"
#include "rewrap.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class mainWindow;
class Elina_Labels : public QDialog
{
    Q_OBJECT

public:
    Elina_Labels(QWidget *parent = 0,QSqlDatabase *db=0 ,QSqlDatabase *db1=0,QTcpSocket *client=0);
    ~Elina_Labels();




private slots:

     void onTypeChar();
     void rowClicked(const QModelIndex &);
     void next1Clicked();
     void insertClicked();
     void removeClicked();
     void rewrapClicked();
     void rowClickedSel(const QModelIndex &);
     void Scanned();
     void setSpinBoxFormat();
     void clearLineEdit();
     //void enableGetDataButton();
     void copy_machine();
     void copy_middledate();
     void upClicked();
     void downClicked();
     void checkClicked();
     void startread();
     void weight_check();
     void rowClickedSelProd(const QModelIndex &);
     //void delprobycell();
     void timer1_v();
     void timer2_v();
     void dummycheckpressed();



private:
    Ui::Elina_LabelsClass ui;
    QSqlDatabase *db;
    QSqlDatabase *db1;
    QTcpSocket *client;
    QSqlQueryModel *model;
    QTextCodec *codec;
    QTextDecoder *decoder;
    QList<QString> ex_codes;
    int row_sel;
    mainWindow *m;
    quint16 nextblocksize;
    bool kefcheck;


    void setupModel_Code(QString like);
    void check_kef_code(QString f_code);
    QString insert_db_prod(QString f_code);
    void insert_kef(QString code_t);
    void print_label(QString code_t,QString f_code);
    bool final_check(QString f_code);
    void reset_values();
    void refresh_production();
    void disable_entry_controls();
    void enable_entry_controls();
    QString get_code_t(QString f_code);
    QString get_middle();
    QString get_middle2();
    QString get_middle3();
    QString stcode,serial;
    QString stmaxid,semaxid;
    QTimer *timer1,*timer2;




};

#endif // ELINA_LABELS_H
