
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

    QString dbhost=settings->value("dbhost").toString();
    QString dbuser=settings->value("dbuser").toString();
    QString dbpassword=settings->value("dbpassword").toString();
    QString dberp=settings->value("dberp").toString();
    QString dbext=settings->value("dbext").toString();

    //db=Προδιαγραφες   ----                db1=ERP
	db = QSqlDatabase::addDatabase("QTDS");
    db.setDatabaseName("elinaProdiagrafes");
    db.setUserName("sa");
    db.setPassword("sa");
    db.setHostName("192.168.0.250");

    db1 = QSqlDatabase::addDatabase("QTDS","erp");
    //db1 = QSqlDatabase::addDatabase("QTDS");
    db1.setDatabaseName(dberp);
    db1.setUserName(dbuser);
    db1.setPassword(dbpassword);
    db1.setHostName(dbhost);

    if (db.open() == false) {
            QMessageBox::critical(0, "Error", "Error");
            exit(0);
        }
    //db.open();
    db1.open();

    //db = QSqlDatabase::database();
    //db1 = QSqlDatabase::database("erp");
    //TODO      TESTING DB
    QString
            query =
                    ("SELECT * FROM telika_proionta");


    QSqlQuery qp;
    bool success1= qp.prepare(query);
    qDebug()<<"SU1:"<<success1;
     bool success=qp.exec(query);
     qDebug()<<qp.lastError().text();
    qDebug()<<db.lastError().text();
    qDebug()<<db1.lastError().text();
    qDebug()<<"SU:"<<success;
    qDebug()<<query;
    qDebug()<<qp.lastError().text();
    qp.next();
    qDebug()<<qp.value(0).toString();
	ui.setupUi(this);
    connect(ui.action, SIGNAL(triggered()), this, SLOT(labels()));

	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(logout()));
	connect(ui.actionProduction, SIGNAL(triggered()), this, SLOT(production_rep()));
	connect(ui.action3A, SIGNAL(triggered()), this, SLOT(rep_3A()));
	connect(ui.actionK_T, SIGNAL(triggered()), this, SLOT(rep_KT()));
    connect(ui.actionAbout,SIGNAL(triggered()),this,SLOT(about()));


	if (mode==1)
		{


			ui.action3A->setVisible(FALSE);
			ui.actionK_T->setVisible(FALSE);

            labels();
		}
    qDebug()<<"db:"<<db.isOpen();
    qDebug()<<"db1:"<<db1.isOpen();

    //connect(ui.actionK_T, SIGNAL(triggered()), this, SLOT(rep_KT()));
}

mainWindow::~mainWindow()
{

	db.close();
	db1.close();


}

void mainWindow::labels()
{
    Elina_Labels *w= new Elina_Labels(this,&db,&db1);

	w->show();
	w->move(0,0);
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



