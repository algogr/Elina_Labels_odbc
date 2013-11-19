#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent,int mode)
    : QMainWindow(parent)
{
	db = QSqlDatabase::addDatabase("QTDS");
	db.setDatabaseName(DB_EXT);
	db.setUserName(USER);
	db.setPassword(PASS);
	db.setHostName(HOST);
	db1 = QSqlDatabase::addDatabase("QTDS","kef");
	db1.setDatabaseName(DB_KEF);
	db1.setUserName(USER);
	db1.setPassword(PASS);
	db1.setHostName(HOST);

	db = QSqlDatabase::database();
	db1 = QSqlDatabase::database("kef");

	QHostAddress addr((QString)SVR_HOST);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);


	//connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
	//connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this,
	//			SLOT(displayError(QAbstractSocket::SocketError)));
	qDebug()<<"UI:"<<&ui;
	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(labels()));
	qDebug()<<"ACTION:"<<(ui.action_2);
	connect(ui.action_9, SIGNAL(triggered()), this, SLOT(logout()));
	connect(ui.actionProduction, SIGNAL(triggered()), this, SLOT(production_rep()));
	connect(ui.action3A_2, SIGNAL(triggered()), this, SLOT(rep_3A()));
	connect(ui.actionK_T_2, SIGNAL(triggered()), this, SLOT(rep_KT()));
	qDebug()<<"UI1:"<<&ui;

	if (mode==1)
		{


			ui.action3A_2->setVisible(FALSE);
			//ui.actionK_T->setVisible(FALSE);
			qDebug()<<"UI2:"<<&ui;
			//labels();
		}
	//connect(ui.actionK_T, SIGNAL(triggered()), this, SLOT(rep_KT()));
}

mainWindow::~mainWindow()
{

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



