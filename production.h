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
