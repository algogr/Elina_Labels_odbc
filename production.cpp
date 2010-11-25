#include "production.h"

production::production(QWidget *parent,QSqlDatabase *db1)
    : QDialog(parent)
{
	this->db1=db1;
	ui.setupUi(this);
	QDate pr_date=QDate::currentDate();
	ui.dateEdit->setDate(pr_date);

	fetch_data();
	connect(ui.dateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(refresh()));

}

production::~production()
{



}

void production::fetch_data()
{
	QDate nextdate= ui.dateEdit->date();
	nextdate=nextdate.addDays(1);
	QString st="SELECT p.pr_date,p.f_code,s.sName,p.code_t,p.weight,p.quality from production p,expstockitem s where s.sCode=p.f_code and pr_date>='"+ui.dateEdit->date().toString("M/d/yy")+"' and pr_date<'"+nextdate.toString("M/d/yy")+"'";
	QSqlQuery q(*db1);
	q.exec(st);
	QSqlQueryModel *model = new QSqlQueryModel;
	model->setQuery(q);
	model->setHeaderData(0, Qt::Horizontal, trUtf8("Ημερομηνία/'Ωρα"));
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Κωδ.Πωλούμενου"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Περιγραφή"));
	model->setHeaderData(3, Qt::Horizontal, trUtf8("Κωδ.Ταυτοποίησης"));
	model->setHeaderData(4, Qt::Horizontal, trUtf8("Κιλά"));
	model->setHeaderData(5, Qt::Horizontal, trUtf8("Ποιότητα"));
	ui.tableView->setModel(model);

	ui.tableView->setColumnWidth(0,125);
	ui.tableView->setColumnWidth(1,135);
	ui.tableView->setColumnWidth(2,200);
	ui.tableView->setColumnWidth(3,135);
	ui.tableView->setColumnWidth(4,50);
	ui.tableView->setColumnWidth(5,80);
	return ;
}

void production::refresh()
{
	fetch_data();
}
