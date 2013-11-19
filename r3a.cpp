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

#include "r3a.h"


r3A::r3A(QWidget *parent,QSqlDatabase *db1)
    : QDialog(parent)
{
	m=(mainWindow*)parent;
	this->db1=db1;
	ui.setupUi(this);
	QDate pr_date=QDate::currentDate();
	ui.dateEdit->setDate(pr_date);
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setHorizontalHeaderLabels(QStringList()<<trUtf8("Ημερομηνία/'Ωρα")<<trUtf8("Κωδ.Πωλούμενου")<<trUtf8("Περιγραφή")<<trUtf8("Κωδ.Ταυτοποίησης")<<trUtf8("Kg")<<trUtf8("Π/X")<<trUtf8("KEF"));
	ui.tableWidget->setColumnWidth(0,155);
	ui.tableWidget->setColumnWidth(1,135);
	ui.tableWidget->setColumnWidth(2,200);
	ui.tableWidget->setColumnWidth(3,135);
	ui.tableWidget->setColumnWidth(4,30);
	ui.tableWidget->setColumnWidth(5,30);
	ui.tableWidget->setColumnWidth(6,30);
	fetch_data();
	connect(ui.dateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(refresh()));
	connect(ui.updateButton, SIGNAL(clicked()),this,SLOT(update()));
}

r3A::~r3A()
{

}

void r3A::fetch_data()
{
	QDate nextdate= ui.dateEdit->date();
	nextdate=nextdate.addDays(1);
	QString st="SELECT p.pr_date,p.f_code,s.sName,p.code_t,p.weight,p.quality from production p,expstockitem s where s.sCode=p.f_code and quality='3A' and pr_date>='"+ui.dateEdit->date().toString("M/d/yy")+"' and pr_date<'"+nextdate.toString("M/d/yy")+"' and iskef=0";
	QSqlQuery query(*db1);
	query.exec(st);
	int r=0;
	while (query.next()!=FALSE){
			ui.tableWidget->setRowCount(r+1);
			QTableWidgetItem *j=new QTableWidgetItem;
			j->setText(query.value(0).toString());
			ui.tableWidget->setItem(r,0,j);

			QTableWidgetItem *k=new QTableWidgetItem;
			k->setText(query.value(1).toString());
			ui.tableWidget->setItem(r,1,k);

			QTableWidgetItem *l=new QTableWidgetItem;
			l->setText(query.value(2).toString());
			ui.tableWidget->setItem(r,2,l);

			QTableWidgetItem *m=new QTableWidgetItem;
			m->setText(query.value(3).toString());
			ui.tableWidget->setItem(r,3,m);

			QTableWidgetItem *n=new QTableWidgetItem;
			n->setText(query.value(4).toString());
			ui.tableWidget->setItem(r,4,n);

			QTableWidgetItem *o=new QTableWidgetItem;
			o->setText(query.value(5).toString());
			ui.tableWidget->setItem(r,5,o);

			QTableWidgetItem *p=new QTableWidgetItem;
			ui.tableWidget->setItem(r,6,p);
			ui.tableWidget->setCellWidget(r,6,new QCheckBox);


			r++;
	}
}

void r3A::refresh()
{
	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(0);
	fetch_data();
}

void r3A::update()
{
	int r=ui.tableWidget->rowCount();

	for (int i=0;i<r;++i){
		ui.tableWidget->setCurrentCell(i,6);
		QWidget* t;
		t= ui.tableWidget->cellWidget(i,6);
		QCheckBox* u;
		if (!(u=(QCheckBox*)t)) continue;
		if(u->checkState()==2){
			QSqlQuery query(*db1);
			QString dcomid=(QString) COMID;
			QString getmaxid="select max(rec_id) from ImpStockTrans";
			query.exec(getmaxid);
			query.last();
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

			QString partida=ui.tableWidget->item(i,3)->text();
			QString getquant="SELECT PR_DATE,F_CODE,WEIGHT,ID FROM PRODUCTION WHERE CODE_T='"+partida+"'";
			query.exec(getquant);
			query.last();
			QDate pr_date=query.value(0).toDate();
			QString code=query.value(1).toString();
			QString quant=query.value(2).toString();
			QString id=query.value(3).toString();
			QString insert="INSERT INTO IMPSTOCKTRANS(REC_ID,COMID,RECSTATUS,STDATE,SCODE,STTRANSKIND,STDOC,STLOCATION,STQUANT,STLOTCODE) VALUES ("+s_rec_id+","+dcomid+",0,'"+
					    pr_date.toString("MM-dd-yyyy")+"','"+code+"',66,'PARAGOGI',1,"+quant+",'"+partida+"')";
			query.exec(insert);

			//m->requestNewData();
			//m->readData();
			QString updiskef="UPDATE PRODUCTION SET ISKEF=1 WHERE ID="+id;
			query.exec(updiskef);
			refresh();

		}
	}

}
