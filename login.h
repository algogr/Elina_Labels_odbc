#ifndef LOGIN_H
#define LOGIN_H

#include <QtGui/QDialog>
#include <QtGui>
#include <QtGui/QMessageBox>
#include <QApplication>
#include "ui_login.h"
#include "mainwindow.h"

class login : public QDialog
{
    Q_OBJECT

public:
    login(QWidget *parent = 0);
    ~login();

private:
    Ui::loginClass ui;
private slots:
	void okpressed();
};

#endif // LOGIN_H
