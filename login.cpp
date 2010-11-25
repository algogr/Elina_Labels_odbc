#include "login.h"

login::login(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(okpressed()));
}

login::~login()
{

}

void login::okpressed()
{
		int WIDTH = 1024;
	    int HEIGHT = 768;

	    int screenWidth;
	    int screenHeight;

	    int x, y;

	if(ui.userlineEdit->text()=="admin" && ui.passlineEdit_2->text()=="789")
	{
		QDesktopWidget *desktop = QApplication::desktop();

	    screenWidth = desktop->width();
	    screenHeight = desktop->height();

	    x = (screenWidth - WIDTH) / 2;
	    y = (screenHeight - HEIGHT) / 2;

		mainWindow *m= new mainWindow(this,0);
		this->hide();
		m->show();
		m->move(x,y);
		return;
	}

	if(ui.userlineEdit->text()=="user" && ui.passlineEdit_2->text()=="123")
	{
		QDesktopWidget *desktop = QApplication::desktop();

		screenWidth = desktop->width();
		screenHeight = desktop->height();

	    x = (screenWidth - WIDTH) / 2;
	    y = (screenHeight - HEIGHT) / 2;

		mainWindow *m= new mainWindow(0,1);

		m->show();
		this->hide();
		m->move(x,y);
		return;

	}
	QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Λάθος στοιχεία χρήστη "));
	//return;

}
