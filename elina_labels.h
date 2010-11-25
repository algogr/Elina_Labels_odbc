#ifndef ELINA_LABELS_H
#define ELINA_LABELS_H

#include <QtGui/QWidget>
#include <QtGui/QDialog>
#include <QtGui/QMessageBox>
#include <QtNetwork>
#include <QtSql>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include "ui_elina_labels.h"
#include "constants.h"
//#include "scanlabels.h"
class scanlabels;
class Elina_Labels : public QDialog
{
    Q_OBJECT

public:
    Elina_Labels(QWidget *parent = 0,QSqlDatabase *db=0 ,QSqlDatabase *db1=0);
    ~Elina_Labels();
    QString currentData;

public slots:
	void requestNewData();
	void readData();

private slots:
     void displayError(QAbstractSocket::SocketError socketError);
     void onTypeChar();
     void rowClicked(const QModelIndex &);
     void next1Clicked();
     //void enableGetDataButton();



private:
    Ui::Elina_LabelsClass ui;
    QTcpSocket *tcpSocket;
    quint16 blockSize;
    QSqlDatabase *db;
    QSqlDatabase *db1;
    QSqlQueryModel *model;
    QTextCodec *codec;
    QTextDecoder *decoder;
    scanlabels *scanlabels_dialog;


    void setupModel_Code(QString like);
    bool check_kef_code();
    QString insert_db_prod();
    void print_label(QString code_t);
    bool final_check();
};

#endif // ELINA_LABELS_H
