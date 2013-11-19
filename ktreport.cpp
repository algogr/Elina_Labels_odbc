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

#include "ktreport.h"

ktreport::ktreport(QWidget *parent,QSqlDatabase *db)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->db=db;
	setupModel_Code("");
	ui.tableView->setModel(model);
	ui.tableView->setColumnWidth(0, 150);
	ui.tableView->setColumnWidth(1, 150);

	connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this,
				SLOT(onTypeChar()));
	connect(ui.tableView, SIGNAL(pressed(const QModelIndex &)), this,
				SLOT(rowClicked(const QModelIndex &)));

}

void ktreport::setupModel_Code(QString like) {
	QString
	//		query =
		//			("SELECT weight,quality,middle,pr_date,f_code,iskef,code_t,middle_2,middle_3,vardia from production where code_t like \'%");

	//		query =
			//

	query =	("SELECT code_t,pr_date from production where code_t like \'");


	query.append(like);
	query.append("%\'");


	QSqlQuery qp(*db);
	QSqlQueryModel *model1 = new QSqlQueryModel;
	//qp.prepare(query);
	//QString result = codec->toUnicode( qp.value( 0 ).toString() );
	qp.exec(query);
	model1->setQuery(qp);
	//		while (model1->canFetchMore())
	//		model1->fetchMore();
	//		int i = model1->rowCount();
	//		for (int k=0;k< i-1;k++)
	//		{
	//			QSqlRecord record=model1->record(k);
	//			QString jim5=record.value(0).toString();
	//            int jim6=jim5.length();
	//			QString jim1=codec->toUnicode(record.value(0).toByteArray());
	//			QString jim2=codec->toUnicode(record.value(1).toByteArray());
	//			QString jim3=decoder->toUnicode(record.value(0).toByteArray());
	//			QString jim4=decoder->toUnicode(record.value(1).toByteArray());

	//QString jim=codec->toUnicode(QVariant::ByteArray(QVariant(record.value(0).toString())));
	//			qDebug() << "Date:" << jim1 << jim2 << jim3 << jim4 << jim5 ;

	//			record.value(0)=QVariant(codec->toUnicode(record.value(0).toByteArray()));
	//			record.value(1)=QVariant(codec->toUnicode(record.value(1).toByteArray()));
	//cout<<record.value(2);
	//index->i
	//		}
	//model1->setQuery(codec->toUnicode(resultqp.value( 0 ).toString() ));
	model1->setHeaderData(0, Qt::Horizontal, trUtf8("Κωδικός"));
	model1->setHeaderData(1, Qt::Horizontal, trUtf8("Ημερομηνία"));
	//    	QSqlError jim=db.lastError();
	//    	qDebug()<<jim;
	model = model1;

}

void ktreport::onTypeChar() {
	QString like = ui.lineEdit->text();
	this->setupModel_Code(like);
	ui.tableView->setModel(model);
}

void ktreport::rowClicked(const QModelIndex &index) {
	int row = index.row();
	QString code = model->record(row).value(0).toString();
	ui.lineEdit->setText(code);
	QString query ="SELECT weight,quality,middle,pr_date,f_code,iskef,code_t,middle_2,middle_3,vardia from production where code_t ='"+code+"'";
	QSqlQuery qp(*db);
	qp.exec(query);
	qp.last();
	QString weight = qp.value(0).toString();
    ui.lweight->setText(weight);
    QString quality = qp.value(1).toString();
    ui.lquality->setText(quality);
    QString middle=qp.value(2).toString();
    ui.lmiddle->setText(middle);
    QString pr_date=qp.value(3).toString();
    ui.lpr_date->setText(pr_date);
    QString f_code=qp.value(4).toString();
    ui.lf_code->setText(f_code);
    QString iskef=qp.value(5).toString();
    ui.liskef->setText(iskef);
    QString code_t=qp.value(6).toString();
    ui.lcode_t->setText(code_t);
    QString middle_2=qp.value(7).toString();
    ui.lmiddle_2->setText(middle_2);
    QString middle_3=qp.value(8).toString();
    ui.lmiddle_3->setText(middle_3);
    QString vardia=qp.value(9).toString();
    ui.lvardia->setText(vardia);

}

ktreport::~ktreport()
{

}
