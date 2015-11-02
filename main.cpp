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


#include <QtGui>
#include <QApplication>
#include <QSharedMemory>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
//    QApplication::setGlobalStrut(QSize(30, 30));

    int WIDTH = 400;
    int HEIGHT = 100;

    int screenWidth;
    int screenHeight;

    int x, y;
    QFile st(QDir::currentPath()+ "/settings.ini");
    QString settingsFile = (QDir::currentPath()+ "/settings.ini");
    QSettings *settings =new QSettings(settingsFile,QSettings::IniFormat);

    if(!st.open(QIODevice::ReadOnly | QIODevice::Text))

        {
            settings->setValue("dbhost","194.111.212.249");
            settings->setValue("dbuser","sa");
            settings->setValue("dbpassword","sa");
            settings->setValue("dbkef","kef_dblink");
            settings->setValue("dbext","elinaProdiagrafes");
            settings->setValue("appserver","194.111.212.84");
            settings->setValue("apath","/home/elina/Elina_Labels/");
            settings->setValue("comid","7");
            settings->sync();

        }
        st.close();


    //QTextCodec *codec = QTextCodec::codecForName( "ISO8859-7" );
    //QString result = codec->toUnicode( query->value( 0 ).toString() );
    QSplashScreen *splash = new QSplashScreen;
    QString apath=settings->value("apath").toString();
    splash->setPixmap(QPixmap(apath+"images/Barcode.png"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::trUtf8("Εκκίνηση Εφαρμογής..."),
                        topRight, Qt::white);

    login w;
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

    //a.processEvents();

     //---- Check for another instance code snippet ----

     //GUID : Generated once for your application
     // you could get one GUID here: http://www.guidgenerator.com/online-guid-generator.aspx
     //QSharedMemory shared("015ebe5f-2566-42b1-877b-1cf894c6e08b");

     //if( !shared.create( 512, QSharedMemory::ReadWrite) )
     //{
       // For a GUI application, replace this by :
       // QMessageBox msgBox;
       //msgBox.setText( QObject::tr("Can't start more than one instance of the application.") );
       //msgBox.setIcon( QMessageBox::Critical );
       //msgBox.exec();

       //qWarning() << "The application is already running.";

       //exit(0);
     //}
     //else {
       //  qDebug() << "Application started successfully.";
     //}
     //---- END OF Check for another instance code snippet ----



    return a.exec();
}
