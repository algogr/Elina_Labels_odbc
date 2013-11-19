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

#ifndef KTREPORT_H
#define KTREPORT_H

#include <QtGui/QDialog>
#include <QtSql>
#include "ui_ktreport.h"

class ktreport : public QDialog
{
    Q_OBJECT

public:
    ktreport(QWidget *parent = 0,QSqlDatabase *db=0);
    ~ktreport();

private slots:
	void onTypeChar();
    void rowClicked(const QModelIndex &);

private:
    Ui::ktreportClass ui;
    QSqlDatabase *db;
    QSqlQueryModel *model;
    void setupModel_Code(QString like);

};

#endif // KTREPORT_H
