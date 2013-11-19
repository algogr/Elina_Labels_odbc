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

#include "login.h"

login::login(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.passlineEdit_2->setFocus();
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(okpressed()));
}

login::~login()
{

}

void login::okpressed()
{
		int WIDTH = 1280;
	    int HEIGHT = 1024;

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
