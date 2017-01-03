
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

#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent,int mode)
    : QMainWindow(parent)
{

    QString settingsFile = (QDir::currentPath()+ "/settings.ini");
    QSettings *settings =new QSettings(settingsFile,QSettings::IniFormat);

    QString dbhosterp=settings->value("dbhosterp").toString();
    QString dbusererp=settings->value("dbusererp").toString();
    QString dbpassworderp=settings->value("dbpassworderp").toString();

    QString dbhostext=settings->value("dbhostext").toString();
    QString dbuserext=settings->value("dbuserext").toString();
    QString dbpasswordext=settings->value("dbpasswordext").toString();

    QString dbhostpro=settings->value("dbhostpro").toString();
    QString dbuserpro=settings->value("dbuserpro").toString();
    QString dbpasswordpro=settings->value("dbpasswordpro").toString();


    QString dberp=settings->value("dberp").toString();
    QString dbext=settings->value("dbext").toString();
    QString dbpro=settings->value("dbpro").toString();

    delete settings;

    //db=Production---db1=Προδιαγραφες   ----                db2=ERP
    //db = QSqlDatabase::addDatabase("QTDS");
    db = QSqlDatabase::addDatabase("QODBC","ext");

    db.setDatabaseName(dbext);
    db.setUserName(dbuserext);
    db.setPassword(dbpasswordext);
    db.setHostName(dbhostext);



    db1 = QSqlDatabase::addDatabase("QODBC","pro");
    db1.setDatabaseName(dbpro);
    db1.setUserName(dbuserpro);
    db1.setPassword(dbpasswordpro);
    db1.setHostName(dbhostpro);

    db2 = QSqlDatabase::addDatabase("QODBC","erp");
    db2.setDatabaseName(dberp);
    db2.setUserName(dbusererp);
    db2.setPassword(dbpassworderp);
    db2.setHostName(dbhosterp);


    db=QSqlDatabase::database("ext");

    if (db.open() == false) {
            QMessageBox::critical(0, "Error on Prodiagrafes", db.lastError().text());
            exit(0);
        }

    if (db1.open()==false)
    {
        QMessageBox::critical(0, "Error on Production", db1.lastError().text());
        exit(0);
    }

    if (db2.open()==false)
    {
        QMessageBox::critical(0, "Error on ERP", db2.lastError().text());
        exit(0);
    }

    ;

	ui.setupUi(this);
    connect(ui.action, SIGNAL(triggered()), this, SLOT(labels()));

	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(logout()));
	connect(ui.actionProduction, SIGNAL(triggered()), this, SLOT(production_rep()));
	connect(ui.action3A, SIGNAL(triggered()), this, SLOT(rep_3A()));
	connect(ui.actionK_T, SIGNAL(triggered()), this, SLOT(rep_KT()));
    connect(ui.actionAbout,SIGNAL(triggered()),this,SLOT(about()));


	if (mode==1)
		{


            ui.action3A->setVisible(false);
            ui.actionK_T->setVisible(false);

            labels();
		}



}

mainWindow::~mainWindow()
{

	db.close();
	db1.close();
    db2.close();


}

void mainWindow::labels()
{
    Elina_Labels *w= new Elina_Labels(this,&db,&db1,&db2);

	w->show();
	w->move(0,0);
    w->setFocus();
    this->setHidden(true);
}

void mainWindow::logout()
{
	QWidget *w=(QWidget*)this->parent();
	w->show();
	delete(this);
}

void mainWindow::production_rep()
{
	production *w=new production(this,&db1);
	w->show();
	w->move(200,200);
}

void mainWindow::rep_3A()
{
	r3A *w=new r3A(this,&db1);
	w->show();
	w->move(200,200);
}

void mainWindow::rep_KT()
{
	ktreport *w=new ktreport(this,&db1);
	w->show();
	w->move(200,200);
}

void mainWindow::about()
{
    QString settingsFile = (QDir::currentPath()+ "/settings.ini");
    QSettings *settings =new QSettings(settingsFile,QSettings::IniFormat);
    QString version=settings->value("version").toString();
    QMessageBox mb;
    mb.setStandardButtons(QMessageBox::Ok);
    mb.setText("Elina Labels Version:"+version);

    mb.setWindowTitle("Elina Labels");

    mb.exec();


}

void mainWindow::changelog()
{

}



