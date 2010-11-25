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

	ui.setupUi(this);
	if (mode==1)
	{
		ui.action3A->setVisible(FALSE);
		ui.actionK_T->setVisible(FALSE);
	}
	connect(ui.action, SIGNAL(triggered()), this, SLOT(labels()));
	connect(ui.action_8, SIGNAL(triggered()), this, SLOT(logout()));
	connect(ui.actionProductio, SIGNAL(triggered()), this, SLOT(production_rep()));
}

mainWindow::~mainWindow()
{

}

void mainWindow::labels()
{
	Elina_Labels *w= new Elina_Labels(this,&db,&db1);

	w->show();
	w->move(100,100);
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
	w->move(100,100);
}
