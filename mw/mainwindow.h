#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtSql>
#include "ui_mainwindow.h"
#include "elina_labels.h"
#include "production.h"
#include "r3a.h"
#include "ktreport.h"
#include "constants.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = 0,int mode=0);
    ~mainWindow();
    QString currentData;
    QSqlDatabase db,db1;
    QTcpSocket *client;
    quint16 blockSize;



private:
    Ui::mainWindowClass ui;

private slots:
	void labels();
	void logout();
	void production_rep();
	void rep_3A();
	void rep_KT();




	//void rep_KT();
};

#endif // MAINWINDOW_H
