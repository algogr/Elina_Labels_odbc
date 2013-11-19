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
    Ui::mainwindowClass ui;

private slots:
	void labels();
	void logout();
	void production_rep();
	void rep_3A();
	void rep_KT();




	//void rep_KT();
};

#endif // MAINWINDOW_H
