#ifndef SCANLABELS_H
#define SCANLABELS_H

#include <QtGui/QWidget>
#include <QtGui/QCheckBox>
#include <QtSql>
//#include "ui_scanlabels.h"


class scanlabels : public QDialog
{
    Q_OBJECT

public:
    //scanlabels(QWidget *parent = 0);
    scanlabels(QWidget *parent = 0,QSqlDatabase *db=NULL,QSqlDatabase *db1=NULL);
    ~scanlabels();
    void show();

private slots:
	void Scanned();
	void Cont();

private:
    Ui::scanlabelsClass ui;
    QSqlDatabase *db;
    QSqlDatabase *db1;

};

#endif // SCANLABELS_H
