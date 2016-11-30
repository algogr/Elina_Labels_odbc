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

#include "mainwindow.h"


#include <QtGui>
#include <QApplication>
#include <QSplashScreen>
#include <QDesktopWidget>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    int WIDTH = 400;
    int HEIGHT = 100;
    QString VERSION = "2.0";

    int screenWidth;
    int screenHeight;

    int x, y;
    QFile st(QDir::currentPath()+ "/settings.ini");
    QString settingsFile = (QDir::currentPath()+ "/settings.ini");
    QSettings *settings =new QSettings(settingsFile,QSettings::IniFormat);

    if(!st.open(QIODevice::ReadOnly | QIODevice::Text))

        {
            settings->setValue("dbhosterp","194.111.212.230");
            settings->setValue("dbhostext","194.111.212.249"); //prodiagrafes
            settings->setValue("dbhostpro","194.111.212.230"); //production
            settings->setValue("dbusererp","sa");
            settings->setValue("dbpassworderp","STM2support");
            settings->setValue("dbuserext","sa");
            settings->setValue("dbpasswordext","sa");
            settings->setValue("dbuserpro","sa");
            settings->setValue("dbpasswordpro","STM2support");


            settings->setValue("dberp","erp");
            settings->setValue("dbext","ext");
            settings->setValue("dbpro","pro");
            settings->setValue("apath","/home/elina/Elina_Labels/");
            settings->setValue("version",VERSION);
            settings->setValue("log","sql.log");
            settings->sync();

        }
        st.close();

    if (settings->value("version").toString()!=VERSION){

        settings->setValue("version",VERSION);
        settings->sync();
    }
    QSplashScreen *splash = new QSplashScreen;
    QString apath=settings->value("apath").toString();
    splash->setPixmap(QPixmap(apath+"images/Barcode.png"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::trUtf8("Εκκίνηση Εφαρμογής..."),
                        topRight, Qt::white);

    mainWindow w(0,1);


    w.show();
    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    //w.resize(WIDTH, HEIGHT);
    w.move( x, y );

    splash->finish(&w);
    delete splash;
    delete (settings);





    return a.exec();
}
