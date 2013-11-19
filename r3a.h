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

#ifndef R3A_H
#define R3A_H

#include <QtGui/QDialog>
#include <QtGui/QCheckBox>
#include <QtSql>
#include "mainwindow.h"
#include "ui_r3a.h"
#include "constants.h"
#include "elina_labels.h"
class mainWindow;
class r3A : public QDialog
{
    Q_OBJECT


public:
    r3A(QWidget *parent = 0,QSqlDatabase *db1=0);
    ~r3A();

private:
    Ui::r3AClass ui;
    QSqlDatabase *db1;
    mainWindow *m;
    void fetch_data();


private slots:
	void refresh();
	void update();
};

#endif // R3A_H
