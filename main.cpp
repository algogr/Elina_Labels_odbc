#include "login.h"


#include <QtGui>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int WIDTH = 400;
    int HEIGHT = 100;

    int screenWidth;
    int screenHeight;

    int x, y;



    //QTextCodec *codec = QTextCodec::codecForName( "ISO8859-7" );
    //QString result = codec->toUnicode( query->value( 0 ).toString() );
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("/home/jim/workspace/Elina_Labels/images/Barcode.png"));
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

    return a.exec();
}
