
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
    //db=Προδιαγραφες   ----                db1=Production
	db = QSqlDatabase::addDatabase("QTDS");
	db.setDatabaseName(DB_EXT);
	db.setUserName(USER);
	db.setPassword(PASS);
	db.setHostName(HOST);
    qDebug()<<HOST;
    qDebug()<<DB_EXT;
	db1 = QSqlDatabase::addDatabase("QTDS","kef");
	db1.setDatabaseName(DB_KEF);
	db1.setUserName(USER);
	db1.setPassword(PASS);
	db1.setHostName(HOST);
    qDebug()<<HOST;
    qDebug()<<DB_KEF;
	db = QSqlDatabase::database();
	db1 = QSqlDatabase::database("kef");

	ui.setupUi(this);
	QHostAddress addr((QString)SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);


	qDebug()<<"UI:"<<&ui;
	connect(ui.action, SIGNAL(triggered()), this, SLOT(labels()));
	qDebug()<<"ACTION:"<<&(ui.action_2);
	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(logout()));
	connect(ui.actionProduction, SIGNAL(triggered()), this, SLOT(production_rep()));
	connect(ui.action3A, SIGNAL(triggered()), this, SLOT(rep_3A()));
	connect(ui.actionK_T, SIGNAL(triggered()), this, SLOT(rep_KT()));
	qDebug()<<"UI1:"<<&ui;

	if (mode==1)
		{


			ui.action3A->setVisible(FALSE);
			ui.actionK_T->setVisible(FALSE);

			labels();
		}
	//connect(ui.actionK_T, SIGNAL(triggered()), this, SLOT(rep_KT()));
}

mainWindow::~mainWindow()
{
	client->disconnectFromHost();
	db.close();
	db1.close();


}

void mainWindow::labels()
{
	Elina_Labels *w= new Elina_Labels(this,&db,&db1,client);

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




