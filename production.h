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

#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <QtGui/QWidget>
#include <QtGui/QDialog>
#include <QtSql>
#include "ui_production.h"
#include "constants.h"

class production : public QDialog
{
    Q_OBJECT

public:
    production(QWidget *parent = 0,QSqlDatabase *db1 = 0);
    ~production();

private:
    Ui::productionClass ui;
    QSqlDatabase *db1;
    void fetch_data();

private slots:
	void refresh();
};

#endif // PRODUCTION_H
