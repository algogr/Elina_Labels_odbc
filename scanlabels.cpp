#include "scanlabels.h"
#include "elina_labels.h"
#include "ui_scanlabels.h"
scanlabels::scanlabels(QWidget *parent,QSqlDatabase *db,QSqlDatabase *db1)
    : QDialog(parent)
{

	ui.setupUi(this);
	connect(ui.scanlineEdit, SIGNAL(returnPressed()),this,SLOT(Scanned()));
	connect(ui.contpushButton, SIGNAL(clicked()),this,SLOT(Cont()));

	ui.scantableWidget->setColumnCount(3);
	ui.scantableWidget->setColumnWidth(0,170);
	ui.scantableWidget->setColumnWidth(1,150);
	ui.scantableWidget->setColumnWidth(2,40);
	ui.scantableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("Κωδικός Ταυτοποίησης")<<trUtf8("Κωδικός Προιόντος") << trUtf8("Εκτ"));
	this->db=db;
	this->db1=db1;
	ui.scanlineEdit->setFocus();
	ui.contpushButton->setDefault(false);
	ui.contpushButton->setAutoDefault(false);

}

scanlabels::~scanlabels()
{

}

void scanlabels::show()
{
	QWidget::show();
	ui.scantableWidget->clearContents();
	ui.scantableWidget->setRowCount(0);
}

void scanlabels::Scanned()
{
	QString code_t;
	code_t=ui.scanlineEdit->text();
	ui.scanlineEdit->setText("");
	QTableWidgetItem *j=new QTableWidgetItem ;
	j->setText(code_t);
	int r=ui.scantableWidget->rowCount();
	ui.scantableWidget->setRowCount(r+1);
	ui.scantableWidget->setItem(r,0,j);
	QSqlQuery query(*db1);
	query.exec("select f_code from production where code_t='"+code_t+"'");
	QTableWidgetItem *k=new QTableWidgetItem ;
	QTableWidgetItem *l=new QTableWidgetItem;
	if (query.last()==FALSE)
	{
		k->setText("");
		l->setFlags(Qt::ItemIsSelectable);
	}
	else
	{
		k->setText(query.value(0).toString());
		l->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable);
	}
	ui.scantableWidget->setItem(r,1,k);
	if (query.last()==TRUE)
	{
	ui.scantableWidget->setItem(r,2,l);
	ui.scantableWidget->setCellWidget(r,2,new QCheckBox);
	}
	ui.scanlineEdit->setFocus();
	//return;

}

void scanlabels::Cont()
{
	int i=ui.scantableWidget->rowCount();

	for (int k=0;k<i;k++)
	{
		ui.scantableWidget->setCurrentCell(k,2);
		QWidget* t;
		t= ui.scantableWidget->cellWidget(k,2);
		QCheckBox* u;
		if (!(u=(QCheckBox*)t)) continue;
		if(u->checkState()==2)
		{
				QSqlQuery query(*db1);
				QString getmaxid="select max(rec_id) from ImpStockTrans";
				query.exec(getmaxid);
				QVariant rec_id;
				if (query.last()==FALSE)
				{
					rec_id=0;
				}
				else
				{
					rec_id=query.value(0);

					rec_id=rec_id.toInt()+1;

				}
				QString s_rec_id;
				s_rec_id=rec_id.toString();
				QString code=ui.scantableWidget->item(k,1)->text();
				QString partida=ui.scantableWidget->item(k,0)->text();
				QString getquant="SELECT WEIGHT,ID,QUALITY FROM PRODUCTION WHERE CODE_T='"+partida+"'";
				query.exec(getquant);
				query.last();
				QString quant=query.value(0).toString();
				QString quality=query.value(2).toString();
				QString id=query.value(1).toString();
				QDateTime pr_date=QDateTime::currentDateTime();
				if (quality!="3A"){
				QString insert="INSERT INTO IMPSTOCKTRANS(REC_ID,COMID,RECSTATUS,STDATE,SCODE,STTRANSKIND,STDOC,STLOCATION,STQUANT,STLOTCODE) VALUES ("+s_rec_id+","+COMID+",0,'"+
			    pr_date.toString("MM-dd-yyyy")+"','"+code+"',66,'PARAGOGI',1,"+quant+",'"+partida+"')";
				query.exec(insert);
				Elina_Labels *j;
				j=(Elina_Labels*)this->parent();
				j->requestNewData();
				j->readData();
				if (j->currentData=="OK"){
				QString updiskef="UPDATE PRODUCTION SET ISKEF=1 WHERE ID="+id;
				query.exec(updiskef);
				}
				}


		}
	}

				this->hide();





}
