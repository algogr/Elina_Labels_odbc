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

#ifndef REWRAP_H
#define REWRAP_H

//#include <QtGui/QDialog>
#include <QDialog>
#include "ui_rewrap.h"
#include <QtNetwork>
#include <QtSql>
#include <QMessageBox>


class rewrap : public QDialog
{
    Q_OBJECT

public:
    rewrap(QWidget *parent = 0,QSqlDatabase *db1=0);
    ~rewrap();


private:
    Ui::rewrapClass ui;
    QSqlDatabase *db1;
    bool isDummy;
    void insert_production(const QString &old_code,const QStringList &new_codes,const QString &old_acode,const QStringList &new_acodes);
    void checkDummy(const QString &code);


private slots:
	void scanned_old();
    void scanned_Aold();
	void scanned_new1();
	void scanned_new2();
	void scanned_new3();
	void scanned_new4();
	void scanned_new5();
    void scanned_Anew1();
    void scanned_Anew2();
    void scanned_Anew3();
    void scanned_Anew4();
    void scanned_Anew5();

    void doubleread();

	void insertClicked();
	void cancelClicked();

};

#endif // REWRAP_H
