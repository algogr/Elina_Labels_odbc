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
#include "elina_labels.h"
//#define QT_USE_FAST_CONCATENATION
//#include <QStringBuilder>
#include <fstream>
#include <iostream>
#include "scanlabels.h"
#include "mailsender.h"

using namespace std;

Elina_Labels::Elina_Labels(QWidget *parent, QSqlDatabase *db,
		QSqlDatabase *db1, QTcpSocket *client) :
	QDialog(parent) {
	codec = QTextCodec::codecForName("Windows1253");
	decoder = codec->makeDecoder();
	this->db = db;
	this->db1 = db1;
	this->client = client;
	this->kefcheck = TRUE;
	m = (mainWindow*) parent;
	setupModel_Code("");

	ui.setupUi(this);
	ui.quitButton->setVisible(FALSE);
	ui.scanlineEdit->setEnabled(FALSE);
	//ui.productiontableWidget->setEnabled(FALSE);

	ui.pushDelPro->setEnabled(FALSE);

	ui.insertButton->setEnabled(FALSE);
	ui.removeButton->setEnabled(FALSE);

	ui.machinespinBox_2->setVisible(FALSE);
	ui.machinespinBox_3->setVisible(FALSE);

	ui.aaSpinBox_2->setVisible(FALSE);
	ui.aaSpinBox_3->setVisible(FALSE);
	ui.middleDateEdit_2->setVisible(FALSE);
	ui.middleDateEdit_3->setVisible(FALSE);


    ui.dummyProdDate->setEnabled(FALSE);
    ui.dummyVardiaCombo->setEnabled(FALSE);
    ui.dummyProdDate->setVisible(FALSE);
    ui.dummyVardiaCombo->setVisible(FALSE);
    ui.label_8->setVisible(FALSE);
    ui.label_9->setVisible(FALSE);

	ui.quitButton->setEnabled(FALSE);
	disable_entry_controls();

	ui.tableView->setModel(model);
	ui.tableView->setColumnWidth(0, 150);
	ui.tableView->setColumnWidth(1, 500);

	ui.qualCombo->insertItem(0, "1A");
	ui.qualCombo->insertItem(1, "2A");
	ui.qualCombo->insertItem(2, "3A");
    ui.qualCombo->insertItem(3, "A");
	//ui.qualCombo->insertItem(4, "K/Z");

    ui.dummyVardiaCombo->insertItem(0,"A");
    ui.dummyVardiaCombo->insertItem(0,"B");
    ui.dummyVardiaCombo->insertItem(0,"C");

	ui.productiontableWidget->setHorizontalHeaderLabels(QStringList()
			<< trUtf8("Ημερ./Ωρα") << trUtf8("Κωδικός Προιόντος") << trUtf8(
			"Κιλά") << trUtf8("Κωδ./Τ") << trUtf8("ΚEΦ") << trUtf8("Π/Χ")
			<< trUtf8("Β"));
	ui.productiontableWidget->setColumnWidth(0, 170);
	ui.productiontableWidget->setColumnWidth(1, 170);
	ui.productiontableWidget->setColumnWidth(2, 35);
	ui.productiontableWidget->setColumnWidth(3, 150);
	ui.productiontableWidget->setColumnWidth(4, 50);
	ui.productiontableWidget->setColumnWidth(5, 50);
	ui.productiontableWidget->setColumnWidth(6, 35);

	ui.codeTableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8(
			"Κωδικός") << trUtf8("Περιγραφή"));
	ui.codeTableWidget->setColumnWidth(0, 130);
	ui.codeTableWidget->setColumnWidth(1, 240);
	QTableWidgetItem *a0 = new QTableWidgetItem;
	QTableWidgetItem *a1 = new QTableWidgetItem;
	a0->setText("");
	a1->setText("");
	a0->setBackgroundColor(QColor(Qt::black));
	a1->setBackgroundColor(QColor(Qt::black));

	ui.codeTableWidget->setRowCount(1);

	ui.codeTableWidget->setItem(0, 0, a0);
	ui.codeTableWidget->setItem(0, 1, a1);
	ui.codeTableWidget->setCurrentCell(0, 0);
	row_sel = 0;
	reset_values();
	refresh_production();
	setSpinBoxFormat();

	// find out which IP to connect to
	//QString ipAddress;
	//QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// use the first non-localhost IPv4 address
	//for (int i = 0; i < ipAddressesList.size(); ++i) {
	//if (ipAddressesList.at(i) != QHostAddress::LocalHost
	//	&& ipAddressesList.at(i).toIPv4Address()) {
	//ipAddress = ipAddressesList.at(i).toString();
	//break;
	//}
	//}
	// if we did not find one, use IPv4 localhost
	//if (ipAddress.isEmpty())
	//ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    timer1=new QTimer;
    timer2=new QTimer;
	connect(ui.quitButton, SIGNAL(clicked()), this, SLOT(close()));

	connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this,
			SLOT(onTypeChar()));
	connect(ui.tableView, SIGNAL(pressed(const QModelIndex &)), this,
			SLOT(rowClicked(const QModelIndex &)));
	connect(ui.nextButton, SIGNAL(clicked()), this, SLOT(next1Clicked()));
	connect(ui.insertButton, SIGNAL(clicked()), this, SLOT(insertClicked()));
	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeClicked()));
	connect(ui.upButton, SIGNAL(clicked()), this, SLOT(upClicked()));
	connect(ui.downButton, SIGNAL(clicked()), this, SLOT(downClicked()));
	connect(ui.codeTableWidget, SIGNAL(pressed(const QModelIndex &)), this,
			SLOT(rowClickedSel(const QModelIndex &)));
	connect(ui.scanlineEdit, SIGNAL(returnPressed()), this, SLOT(Scanned()));
	connect(ui.aaSpinBox, SIGNAL(valueChanged(int)), this,
			SLOT(setSpinBoxFormat()));
	connect(ui.aaSpinBox_2, SIGNAL(valueChanged(int)), this,
			SLOT(setSpinBoxFormat()));
	connect(ui.aaSpinBox_3, SIGNAL(valueChanged(int)), this,
			SLOT(setSpinBoxFormat()));
	connect(ui.acpushButton, SIGNAL(clicked()), this, SLOT(clearLineEdit()));
	connect(ui.weightLineEdit, SIGNAL(returnPressed()), this,
			SLOT(next1Clicked()));
	connect(ui.machinespinBox, SIGNAL(valueChanged(int)), this,
			SLOT(copy_machine()));
	connect(ui.middleDateEdit, SIGNAL(dateChanged(QDate)), this,
			SLOT(copy_middledate()));
	connect(client, SIGNAL(readyRead()), this, SLOT(startread()));
	connect(ui.checkBox, SIGNAL(clicked()), this, SLOT(checkClicked()));
	connect(ui.pushrewrap, SIGNAL(clicked()), this, SLOT(rewrapClicked()));
	connect(ui.weightLineEdit, SIGNAL(textChanged(const QString &)), this,
			SLOT(weight_check()));
	connect(ui.productiontableWidget, SIGNAL(pressed(const QModelIndex &)),
			this, SLOT(rowClickedSelProd(const QModelIndex &)));
	//connect(ui.pushDelPro, SIGNAL(clicked()), this, SLOT(delprobycell()));
    connect(this->timer1,SIGNAL(timeout()),this,SLOT(timer1_v()));
    connect(this->timer2,SIGNAL(timeout()),this,SLOT(timer2_v()));
    connect(ui.dummycheckBox,SIGNAL(clicked()),this,SLOT(dummycheckpressed()));

/*
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
         qDebug() << "Name        : " << info.portName();
         qDebug() << "Description : " << info.description();
         qDebug() << "Manufacturer: " << info.manufacturer();

         // Example use QSerialPort
         QSerialPort serial;
         serial.setPort(info);
         if (serial.open(QIODevice::ReadWrite))
             serial.close();
     }
*/


    timer1->start(60000);
}

Elina_Labels::~Elina_Labels() {

}

void Elina_Labels::setupModel_Code(QString like) {
	QString
			query =
					("SELECT kodikos_p,perigrafi FROM telika_proionta where kodikos_p like \'%");

	query.append(like);
	query.append("%\' ");
	if (ex_codes.size() > 0) {
		for (int i = 0; i < ex_codes.size(); ++i) {
			query.append(" and kodikos_p<>'" + ex_codes.at(i) + "'");
		}
	}
	query.append(" order by kodikos_p");

	QSqlQuery qp;
	QSqlQueryModel *model1 = new QSqlQueryModel;
	//qp.prepare(query);
	//QString result = codec->toUnicode( qp.value( 0 ).toString() );
	qp.exec(query);
    qDebug()<<"QUERY:"<<query;
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
	model1->setHeaderData(1, Qt::Horizontal, trUtf8("Περιγραφή"));
	//    	QSqlError jim=db.lastError();
	//    	qDebug()<<jim;
	model = model1;

}

void Elina_Labels::onTypeChar() {
	QString app = ui.lineEdit->text();
	QStringList list1 = app.split("-");
	QString like = list1.join("");
	//QString like=ui.lineEdit->text();
	ui.prodLabel->setText("");
	this->setupModel_Code(like);
	ui.tableView->setModel(model);
	int len = like.length();
	QString str;
	if (len >= 3 && len < 6) {
		ui.lineEdit->setText(like.insert(3, "-"));
	}
	if (len >= 6 && len < 9) {
		str = like.insert(3, "-");
		str = str.insert(7, "-");
		ui.lineEdit->setText(str);
	}
	if (len >= 9 && len < 11) {
		str = like.insert(3, "-");
		str = str.insert(7, "-");
		str = str.insert(11, "-");
		ui.lineEdit->setText(str);
	}
	if (len >= 11) {
		str = like.insert(3, "-");
		str = str.insert(7, "-");
		str = str.insert(11, "-");
		str = str.insert(14, "-");
		ui.lineEdit->setText(str);
	}
    ui.pushDelPro->setEnabled(FALSE);

}

void Elina_Labels::rowClicked(const QModelIndex &index) {
	int row = index.row();
	QString code = model->record(row).value(0).toString();
	ui.lineEdit->setText(code);
	QString query ="select p.kodikos as kodikos from prodiagrafes p,telika_proionta t where t.prodiagrafi=p.pid and t.kodikos_p='";
	query.append(code);
	query.append("'");
    QSqlQuery qp;
	qp.exec(query);
	qp.next();
	QString prod = qp.value(0).toString();
	ui.prodLabel->setText(prod);
    if (ui.codeTableWidget->rowCount() < 15) {
		ui.insertButton->setEnabled(TRUE);
	}
	ui.pushDelPro->setEnabled(FALSE);

}

void Elina_Labels::next1Clicked() {

	QTableWidgetItem *c = ui.codeTableWidget->item(row_sel, 0);
	QString f_code = c->text();
	if (final_check(f_code) == FALSE)
		return;

	if (kefcheck == FALSE)
		return;

	QString code_t = get_code_t(f_code);

    ////ΑΛΛΑΓΗ 7/8/2012 ΕΛΕΓΧΟΣ ΔΙΠΛΟΥ Κ/Τ
    QSqlQuery query999(*db1);
    QString qr99,qr100;
    qr99="select * from production where code_t='"+code_t+"'";
    qr100="select * from production_dummy where code_t='"+code_t+"'";
    qDebug()<<qr99;
    qDebug()<<qr100;
    query999.exec(qr99);
    if (query999.next())
    {
        QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
                "Aυτός ο Κ/Τ υπάρχει ήδη. Η ετικέτα δεν θα εκτυπωθεί"));
        return;
    }


    query999.exec(qr100);
    if (query999.next())
    {
        QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
                "Aυτός ο Κ/Τ έχει ήδη εκτυπωθεί σαν dummy. Η ετικέτα δεν θα εκτυπωθεί"));
        return;
    }
   //ΤΕΛΟΣ ΑΛΛΑΓΗΣ 8/7/2012

    print_label(code_t, f_code);
    //if (f_code.left(1)!="E")
    insert_db_prod(f_code);
    qDebug()<<"K?T:"<<code_t;
	insert_kef(code_t);

	disable_entry_controls();
	ui.dummycheckBox->setCheckState(Qt::Unchecked);
	ui.pushDelPro->setEnabled(FALSE);
	ui.scanlineEdit->setFocus();

}

void Elina_Labels::check_kef_code(QString f_code) {

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "KFCHECK";
	out << quint16(0) << req_type << f_code;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
	ui.pushDelPro->setEnabled(FALSE);

}

QString Elina_Labels::insert_db_prod(QString f_code) {
	QString middle_2, middle_3;

	QString weight = ui.weightLineEdit->text();

	QString middle = ui.machinespinBox->text()
			+ ui.middleDateEdit->text().remove("/") + ui.aaSpinBox->text();
	if (ui.aaSpinBox_2->isVisible() == TRUE) {
		middle_2 = ui.machinespinBox_2->text()
				+ ui.middleDateEdit_2->text().remove("/")
				+ ui.aaSpinBox_2->text();
	}
	if (ui.aaSpinBox_3->isVisible() == TRUE) {
		middle_3 = ui.machinespinBox_3->text()
				+ ui.middleDateEdit_3->text().remove("/")
				+ ui.aaSpinBox_3->text();
	}
	QString qual, qual1;
	switch (ui.qualCombo->currentIndex()) {
	case 0:
		qual = "1A";
		qual1 = "X";
		break;
	case 1:
		qual = "2A";
		qual1 = "Y";
		break;
    case 2:
		qual = "3A";
		qual1 = "Z";
		break;
	case 3:
        qual = "A";
        qual1 = "A";
		break;
    //case 4:
        //qual = "K/Z";
        //qual1 = "K";

        break;
	}

	switch (ui.weightLineEdit->text().length()) {
	case 1:
		weight = "00" + ui.weightLineEdit->text();
		break;
	case 2:
		weight = "0" + ui.weightLineEdit->text();
		break;
	case 3:
		weight = ui.weightLineEdit->text();
		break;

	}

	QSqlQuery query(*db1);
	QDateTime pr_date = QDateTime::currentDateTime();
	QDateTime nextdate = pr_date.addDays(1);
	QString code = ui.lineEdit->text();
	QString f_aa = "SELECT COUNT(*) from PRODUCTION where f_code='" + f_code
			+ "' and middle='" + middle + "'";
	query.exec(f_aa);
	query.first();

	QString day_aa;

	QVariant a;

    a = query.value(0).toInt()+1 ;

    f_aa= "SELECT COUNT(*) from PRODUCTION_DUMMY where f_code='" + f_code
            + "' and middle='" + middle + "'";
    query.exec(f_aa);
    query.first();

    a=a.toInt()+query.value(0).toInt()+1;


	day_aa = a.toString();



	if (day_aa.length() == 1)
		day_aa = "0" + day_aa;



    // ELEGXOS IF IS DUMMY

    if (ui.dummycheckBox->checkState()==1)
    {

        middle = ui.machinespinBox->text()
                    + ui.dummyProdDate->text().remove("/") + ui.aaSpinBox->text();
    }

    // TELOS ELEGXOY IF IS DUMMY
	QString code_t = weight + middle + qual1 + day_aa;
	QTime ct = QTime::currentTime();

	int hr = ct.hour();
	QString vardia;
	if (hr >= 6 && hr < 14)
		vardia = "A";
	if (hr >= 14 && hr < 22)
		vardia = "B";
	if (hr >= 22 && hr <= 23)
		vardia = "C";
	if (hr < 6)
		vardia = "C";


	if (ui.dummycheckBox->checkState() == 0) {
        if (qual!="A")
        {

		QString
				insert =
						"INSERT INTO PRODUCTION(weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia) VALUES ("
								+ weight + ",'" + qual + "','" + middle + "',"
								+ ui.aaSpinBox->text() + ",'"
								+ QDateTime::currentDateTime().toString(
										Qt::ISODate) + "','" + f_code + "',0,'"
								+ code_t + "','" + middle_2 + "','" + middle_3
								+ "','" + vardia + "')";

		query.exec(insert);
		refresh_production();
        }
        
        if (qual=="A")
        {
		QString
				insert =
                        "INSERT INTO PRODUCTION_dummy(weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia) VALUES ("
								+ weight + ",'" + qual + "','" + middle + "',"
								+ ui.aaSpinBox->text() + ",'"
								+ QDateTime::currentDateTime().toString(
										Qt::ISODate) + "','" + f_code + "',0,'"
								+ code_t + "','" + middle_2 + "','" + middle_3
								+ "','" + vardia + "')";

		query.exec(insert);
		refresh_production();
        }

	}
	else
	{
        vardia=ui.dummyVardiaCombo->currentText();
		QString
						insert =
								"INSERT INTO PRODUCTION_dummy (weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia) VALUES ("
										+ weight + ",'" + qual + "','" + middle + "',"
										+ ui.aaSpinBox->text() + ",'"
										+ QDateTime::currentDateTime().toString(
												Qt::ISODate) + "','" + f_code + "',0,'"
										+ code_t + "','" + middle_2 + "','" + middle_3
										+ "','" + vardia + "')";

				query.exec(insert);
	}
	ui.pushDelPro->setEnabled(FALSE);
	return code_t;

}

void Elina_Labels::insert_kef(QString code_t) {
    if (code_t.contains("A"))
            return;
	QString pid, code, vardia;
	QSqlQuery query(*db1);
	query.exec("select id,f_code,vardia from production where code_t='"
			+ code_t + "'");
	query.last();
	code = query.value(1).toString();
	pid = query.value(0).toString();
	vardia = query.value(2).toString();

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "KFINSERT";
	out << quint16(0) << req_type << code_t << code << pid << vardia;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);
	ui.pushDelPro->setEnabled(FALSE);
	ui.scanlineEdit->setText("");
	ui.scanlineEdit->setFocus();

}

bool Elina_Labels::final_check(QString f_code) {
	//disable_entry_controls();


	if (ui.machinespinBox->text() == "0") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν Μηχανή 1ου ενδιμέσου"));
		return FALSE;
	}
	if (ui.aaSpinBox->text() == "00") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε Α/Α"));
		return FALSE;
	}

	if (ui.aaSpinBox_2->text() == "00" && ui.aaSpinBox_2->isVisible() == TRUE) {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε Α/Α 2oυ ενδιαμέσου"));
		return FALSE;
	}

	if (ui.aaSpinBox_3->text() == "00" && ui.aaSpinBox_3->isVisible() == TRUE) {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε Α/Α 2oυ ενδιαμέσου"));
		return FALSE;
	}

	if (f_code == "") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν επιλέχθηκε κωδικός"));
		return FALSE;
	}

	//if (ui.prodLabel->text() == "") {
	//	QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
	//				"Δεν βρέθηκε η προδιαγραφή"));
	//	return FALSE;
	//}

	if (ui.qualCombo->currentIndex() == -1) {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
                "Δεν δόθηκε ποιοτικός χαρακτηρισμός"));
		return FALSE;
	}

	if (ui.weightLineEdit->text() == "") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε ζύγιση"));
		return FALSE;
	}
	if (ui.weightLineEdit->text().toInt() < 10) {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Λάθος ζύγιση"));
		return FALSE;
	}

	if (ui.machinespinBox->text() == "0") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε μηχανή"));
		return FALSE;
	}

	if (f_code.mid(10, 1).toInt() >= 2) {

		if (ui.aaSpinBox_2->text() == "00") {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δεν δόθηκε Α/Α"));
			return FALSE;
		}
		if (ui.machinespinBox_2->text() == "0") {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δεν δόθηκε μηχανή 2ου ενδιαμέσου"));
			return FALSE;
		}

		if (ui.aaSpinBox->text() == ui.aaSpinBox_2->text()
				&& ui.machinespinBox_2->text() == ui.machinespinBox_3->text()
				&& ui.middleDateEdit_2->text() == ui.middleDateEdit_3->text()) {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δόθηκε ίδιος κωδικός ενδιαμέσου"));
            //return FALSE;
		}

	}
	if (f_code.mid(10, 1).toInt() == 3) {
		if (ui.machinespinBox_3->text() == "0") {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δεν δόθηκε μηχανή 3ου ενδιαμέσου"));
			return FALSE;
		}

		if (ui.aaSpinBox_3->text() == "00") {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δεν δόθηκε Α/Α"));
			return FALSE;
		}

		if (ui.aaSpinBox_2->text() == ui.aaSpinBox_3->text()
				&& ui.machinespinBox_2->text() == ui.machinespinBox_3->text()
				&& ui.middleDateEdit_2->text() == ui.middleDateEdit_3->text()) {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δόθηκε ίδιος κωδικός ενδιαμέσου"));
            //return FALSE;
		}

		if (ui.aaSpinBox->text() == ui.aaSpinBox_3->text()
				&& ui.machinespinBox_2->text() == ui.machinespinBox_3->text()
				&& ui.middleDateEdit_2->text() == ui.middleDateEdit_3->text()) {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δόθηκε ίδιος κωδικός ενδιαμέσου"));
            //return FALSE;
		}
		if (ui.aaSpinBox->text() == ui.aaSpinBox_2->text()
				&& ui.machinespinBox_2->text() == ui.machinespinBox_3->text()
				&& ui.middleDateEdit_2->text() == ui.middleDateEdit_3->text()) {
			QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
					"Δόθηκε ίδιος κωδικός ενδιαμέσου"));
			return FALSE;
		}

	}
	enable_entry_controls();
	ui.pushDelPro->setEnabled(FALSE);
	return TRUE;

}

void Elina_Labels::print_label(QString code_t, QString f_code) {

	//QPrinter  printer(QPrinterInfo::defaultPrinter());
	//printer.setOutputFormat(QPrinter::NativeFormat);
	//printer.setOutputFileName("lab/zpl1.txt");

	//QPrintDialog printDialog(&printer,this);
	//QPainter painter;
	//printDialog.exec();
	//if (printDialog.exec() == QDialog::Accepted) {

	// painter.begin(&printer);
	//printer.newPage();
	//}
	///// DOULEYEI to parakato
	//char s[] = "^XA^FO100,40^BY3^B3,,30^FD123ABC^XZ";
	//char s[]="^XA^FO50,50^ADN,40,35,^FDM A D E   I N   E.U.^FS^XZ";
	//char s[]="^XA~TA000~JSN^LT0^MNW^MTD^PON^PMN^LH0,0^JMA^PR4,4~SD15^JUS^LRN^CI0^XZ~DG000.GRF,03328,104,,:::pMFE:::::::,:::::::::::::::::::^XA^MMT^LL1231^PW831^LS0^FT0,864^XG000.GRF,1,1^FS^FO8,34^GB816,78,78^FS^FT8,96^A0N,62,98^FR^FH\^FDM A D E   I N    E.U.^FS^FT5,145^A0N,28,36^FH\^FD                        KOMOTINI PAPER MILL S.A.^FS^FT5,179^A0N,28,36^FH\^FDINDUSTRIAL AREA OF KOMOTINI - ETVA,GR - 691 00^FS^FT5,213^A0N,28,36^FH\^FD                            P.O. BOX: 57,GREECE^FS^FT5,247^A0N,28,36^FH\^FD    TEL:(+30) 25310 82216  FAX::(+30) 25310 82217^FS^FT5,281^A0N,28,36^FH\^FD                       email:elinapm@otenet.gr^FS^FO0,301^GB828,0,1^FS^FT6,337^A0N,28,45^FH\^FDΠΕΛΑΤΗΣ^FS^FT6,371^A0N,28,45^FH\^FDCUSTOMER^FS^FO0,386^GB820,0,3^FS^FT2,424^A0N,28,43^FH\^FDΠΡΟΟΡΙΣΜΟΣ^FS^FT2,458^A0N,28,43^FH\^FDDESTINATION^FS^FO0,295^GB822,0,8^FS^FO0,468^GB822,0,8^FS^FT4,504^A0N,28,55^FH\^FDΠΟΙΟΤΗΣ^FS^FT4,538^A0N,28,55^FH\^FDQUALITY^FS^FT218,531^A0N,49,72^FH\^FDEES NAPKIN 1-PLY^FS^BY4,3,94^FT148,659^BCN,,Y,N^FD>:P>501021020316026^FS^BY4,3,83^FT148,790^BCN,,Y,N^FD>;2521001263>6X01^FS^FT6,880^A0N,33,33^FH\^FDΒΑΡΟΣ ΑΝΑ m2^FS^FT6,921^A0N,33,33^FH\^FDBASIS WEIGHT^FS^FO218,851^GB365,82,8^FS^FT590,883^A0N,28,48^FH\^FDΦΥΛΛΑ^FS^FT590,917^A0N,28,48^FH\^FDPLIES^FS^FO0,938^GB818,0,7^FS^FT6,982^A0N,28,38^FH\^FDΠΛΑΤΟΣ^FS^FT6,1016^A0N,28,38^FH\^FDWIDTH^FS^FT309,978^A0N,28,38^FH\^FDBAΡΟΣ ΡΟΛ.^FS^FT309,1012^A0N,28,38^FH\^FDTOTAL WEIGHT^FS^FO0,1031^GB824,0,8^FS^FT6,1082^A0N,40,38^FH\^FDΗΜΕΡ.ΠΑΡΑΓ^FS^FT6,1132^A0N,40,38^FH\^FDPROD.DATE^FS^FT226,1112^A0N,59,60^FH\^FD31/12/2010^FS^FT516,1082^A0N,28,50^FH\^FDBAΡΔΙΑ^FS^FT516,1116^A0N,28,50^FH\^FDSHIFT^FS^FT723,1109^A0N,52,160^FH\^FDA^FS^FT603,1005^A0N,52,144^FH\^FD250^FS^FT161,1010^A0N,56,40^FH\^FD460+10^FS^FT753,906^A0N,52,88^FH\^FD2^FS^PQ1,0,1,Y^XZ^XA^ID000.GRF^FS^XZ";
	//ofstream print("/dev/lp0",ios::out);
	//if (!print)
	//{
	//	cout << "Unable to open file, /dev/lp0" << endl;
	//}

	//print << s ;
	//print.close();

	QString weight = ui.weightLineEdit->text();

	QSqlQuery query(*db);
	QString a = "SELECT perigrafi2,kopi FROM telika_proionta where kodikos_p='"
			+ f_code + "'";
	query.exec(a);
	query.last();
	QString quality = query.value(0).toString();
	QString width = query.value(1).toString();
	a
			= "SELECT p.fulla from prodiagrafes p,telika_proionta t where t.prodiagrafi=p.pid and t.kodikos_p='"
					+ f_code + "'";
	query.exec(a);
	query.last();
	QString fylla = query.value(0).toString();
	QTime ct = QTime::currentTime();
	QString cdate = QDate::currentDate().toString("dd/MM/yyyy");

	int hr = ct.hour();
	QString vardia;
	if (hr >= 6 && hr < 14)
		vardia = "A";
	if (hr >= 14 && hr < 22)
		vardia = "B";
	if (hr >= 22 && hr <= 23)
		vardia = "C";
	if (hr < 6) {
		vardia = "C";
		QDate c1date = QDate::currentDate().addDays(-1);
		cdate = c1date.toString("dd/MM/yyyy");
	}

	///////EDO
	///QSqlQuery query1(*db1);
	///a="SELECT middle from production where code_t='"+code_t+"'";
	//query1.exec(a);
	///query1.last();
	//QString middle=query1.value(0).toString();
	//Qt implementation test
	QString middle = get_middle();
	QString middle_2 = "";
	QString middle_3 = "";
	if (fylla == "2") {
		middle_2 = get_middle2();
	}

	if (fylla == "3") {
		middle_2 = get_middle2();
		middle_3 = get_middle3();
	}

	QFile fh("/dev/lp0");
	fh.open(QIODevice::WriteOnly);
	qDebug() << fh.error();
	QTextStream out(&fh);

	QFile lab((QString) APATH + "lab/Elina.txt");
	qDebug() << "dsada" << quality << fylla << width;
	QString line;

	if (lab.open(QFile::ReadOnly)) {
		qDebug() << lab.error();
		QTextStream in(&lab);
		out.setCodec("UTF-8 ");
		//out.setCodec("UTF-8");
		in.setCodec("UTF-8");
        QString dummy="";
        if (ui.dummycheckBox->checkState() == 1)
        {
            dummy="*";

        }

        if (ui.dummycheckBox->isChecked())
        {

            cdate=ui.dummyProdDate->date().toString("dd/MM/yyyy");
            vardia=ui.dummyVardiaCombo->currentText();

        }


		do {
			line = in.readLine();
			line.replace("@quality1111111", quality);
			line.replace("@barcode>5222222>62", f_code);
			line.replace("@barcode>5333333>63", code_t);
			line.replace("@f", fylla);
			line.replace("@width", width);
			line.replace("@weight", weight);
			line.replace("@7", vardia);
			line.replace("@date88888", cdate);
			line.replace("@middle999", middle);
			line.replace("@middle299", middle_2);
			line.replace("@middle399", middle_3);
            line.replace("@dummy", dummy);
			out << line << endl;
			out.flush();

		} while (!line.isNull());
		qDebug() << lab.error();
	}
	fh.close();
	ui.pushDelPro->setEnabled(FALSE);
}

void Elina_Labels::insertClicked() {

	QString kodikos_p = ui.lineEdit->text().split("-").join("");
	QString query =
			"select kodikos_p,perigrafi from telika_proionta where kodikos_p='"
					+ kodikos_p + "'";
	QSqlQuery qp;
	qp.exec(query);
	qp.next();
	int r = ui.codeTableWidget->rowCount();
	ui.codeTableWidget->setRowCount(r + 1);
	QTableWidgetItem *j = new QTableWidgetItem;
	j->setText(qp.value(0).toString());
	j->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	ui.codeTableWidget->setItem(r, 0, j);
	QTableWidgetItem *k = new QTableWidgetItem;
	k->setText(qp.value(1).toString());
	k->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	ui.codeTableWidget->setItem(r, 1, k);
	ex_codes << (qp.value(0).toString());
	ui.lineEdit->setText("");
	ui.insertButton->setEnabled(FALSE);
	disable_entry_controls();
	ui.lineEdit->setFocus();
	ui.pushDelPro->setEnabled(FALSE);

}

void Elina_Labels::removeClicked() {
	QTableWidgetItem *c = ui.codeTableWidget->item(row_sel, 0);
	QString code = c->text();
	if (code != "") {
		ui.codeTableWidget->removeRow(row_sel);
		ex_codes.removeOne(code);
		QString like = ui.lineEdit->text();
		ui.prodLabel->setText("");
		this->setupModel_Code(like);
		ui.tableView->setModel(model);
		ui.removeButton->setEnabled(FALSE);
		disable_entry_controls();
		ui.lineEdit->setFocus();
	}
	ui.pushDelPro->setEnabled(FALSE);
}

void Elina_Labels::upClicked() {
	qDebug() << row_sel;
	if (row_sel >= 1) {
		QTableWidgetItem *c = ui.codeTableWidget->item(row_sel, 0);
		QTableWidgetItem *d = ui.codeTableWidget->item(row_sel, 1);
		QTableWidgetItem *e = ui.codeTableWidget->item(row_sel - 1, 0);
		QTableWidgetItem *f = ui.codeTableWidget->item(row_sel - 1, 1);

		QString cs = c->text();
		QString ds = d->text();
		QString es = e->text();
		QString fs = f->text();

		c->setText(es);
		d->setText(fs);
		e->setText(cs);
		f->setText(ds);
		if (c->text() == "") {
			c->setBackgroundColor(QColor(Qt::black));
			d->setBackgroundColor(QColor(Qt::black));
		} else {
			c->setBackgroundColor(QColor(Qt::white));
			d->setBackgroundColor(QColor(Qt::white));
		}

		if (e->text() == "") {
			e->setBackgroundColor(QColor(Qt::black));
			f->setBackgroundColor(QColor(Qt::black));
		} else {
			e->setBackgroundColor(QColor(Qt::white));
			f->setBackgroundColor(QColor(Qt::white));
		}
		if (row_sel > 0) {
			ui.codeTableWidget->setCurrentCell(row_sel - 1, 0);
			row_sel -= 1;
		}

	}
	qDebug() << row_sel;
	ui.pushDelPro->setEnabled(FALSE);

}

void Elina_Labels::downClicked() {
	if (row_sel <= ui.codeTableWidget->rowCount() - 2) {
		QTableWidgetItem *c = ui.codeTableWidget->item(row_sel, 0);
		QTableWidgetItem *d = ui.codeTableWidget->item(row_sel, 1);
		QTableWidgetItem *e = ui.codeTableWidget->item(row_sel + 1, 0);
		QTableWidgetItem *f = ui.codeTableWidget->item(row_sel + 1, 1);

		QString cs = c->text();
		QString ds = d->text();
		QString es = e->text();
		QString fs = f->text();

		c->setText(es);
		d->setText(fs);
		e->setText(cs);
		f->setText(ds);
		if (c->text() == "") {
			c->setBackgroundColor(QColor(Qt::black));
			d->setBackgroundColor(QColor(Qt::black));
		} else {
			c->setBackgroundColor(QColor(Qt::white));
			d->setBackgroundColor(QColor(Qt::white));
		}

		if (e->text() == "") {
			e->setBackgroundColor(QColor(Qt::black));
			f->setBackgroundColor(QColor(Qt::black));
		} else {
			e->setBackgroundColor(QColor(Qt::white));
			f->setBackgroundColor(QColor(Qt::white));
		}

		ui.codeTableWidget->setCurrentCell(row_sel + 1, 0);
		row_sel += 1;

	}

	qDebug() << row_sel;
	ui.pushDelPro->setEnabled(FALSE);
}

void Elina_Labels::rowClickedSel(const QModelIndex &index) {
	enable_entry_controls();
	reset_values();
	row_sel = index.row();
	ui.removeButton->setEnabled(TRUE);
	QTableWidgetItem *c = ui.codeTableWidget->item(row_sel, 0);
	QString code = c->text();
	qDebug() << code;
	if (code == "") {
		disable_entry_controls();

		return;
	}

	if (code.mid(10, 1).toInt() == 1) {
		ui.machinespinBox_2->setVisible(FALSE);
		ui.machinespinBox_3->setVisible(FALSE);
		ui.aaSpinBox_2->setVisible(FALSE);
		ui.aaSpinBox_3->setVisible(FALSE);
		ui.middleDateEdit_2->setVisible(FALSE);
		ui.middleDateEdit_3->setVisible(FALSE);
	}

	if (code.mid(10, 1).toInt() == 2) {
		ui.machinespinBox_2->setVisible(TRUE);
		ui.aaSpinBox_2->setVisible(TRUE);
		ui.middleDateEdit_2->setVisible(TRUE);
		ui.machinespinBox_3->setVisible(FALSE);
		ui.aaSpinBox_3->setVisible(FALSE);
		ui.middleDateEdit_3->setVisible(FALSE);

	}

	if (code.mid(10, 1).toInt() == 3) {
		ui.machinespinBox_2->setVisible(TRUE);
		ui.machinespinBox_3->setVisible(TRUE);
		ui.aaSpinBox_2->setVisible(TRUE);
		ui.aaSpinBox_3->setVisible(TRUE);
		ui.middleDateEdit_2->setVisible(TRUE);
		ui.middleDateEdit_3->setVisible(TRUE);
	}
	ui.pushDelPro->setEnabled(FALSE);
}

void Elina_Labels::reset_values() {

	QTime ct = QTime::currentTime();
	int hr = ct.hour();
	QDate default_date;
	if (hr < 6) {
		default_date = QDate::currentDate().addDays(-1);

	} else {
		default_date = QDate::currentDate();
	}
	ui.machinespinBox->setValue(0);
	ui.machinespinBox_2->setValue(0);
	ui.machinespinBox_3->setValue(0);
	ui.aaSpinBox->setValue(0);
	ui.aaSpinBox_2->setValue(0);
	ui.aaSpinBox_3->setValue(0);
	ui.middleDateEdit->setDate(default_date);
	ui.middleDateEdit_2->setDate(default_date);
	ui.middleDateEdit_3->setDate(default_date);
    ui.dummyProdDate->setDate(default_date);
	ui.qualCombo->setCurrentIndex(-1);
	ui.weightLineEdit->setText("");
	ui.pushDelPro->setEnabled(FALSE);
}

void Elina_Labels::refresh_production() {
	ui.productiontableWidget->clearContents();
	QSqlQuery query(*db1);

	QString
			a =
                    "SELECT pr_date,f_code,weight,code_t,iskef,quality,vardia from production where pr_date>=dateadd(hour,-8,getdate()) order by pr_date desc";
	query.exec(a);
	int r = 0;
    qDebug()<<"Q:"<<query.size();

	while (query.next() != FALSE) {
		ui.productiontableWidget->setRowCount(r + 1);
		QTableWidgetItem *j = new QTableWidgetItem;
		//j->setFlags(Qt::ItemIsSelectable);
		j->setText(query.value(0).toString());
		j->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//if (query.value(5).toString()=="K/Z"){
		//j->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "X") {
			j->setBackgroundColor(QColor(Qt::red));
		}
		ui.productiontableWidget->setItem(r, 0, j);

		QTableWidgetItem *k = new QTableWidgetItem;
		//k->setFlags(Qt::ItemIsSelectable);
		k->setText(query.value(1).toString());
		k->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//if (query.value(5).toString()=="K/Z"){
		//k->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "X") {
			k->setBackgroundColor(QColor(Qt::red));
		}
		ui.productiontableWidget->setItem(r, 1, k);

		QTableWidgetItem *l = new QTableWidgetItem;
		//l->setFlags(Qt::ItemIsSelectable);
		l->setText(query.value(2).toString());
		l->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//if (query.value(5).toString()=="K/Z"){
		//l->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "X") {
			l->setBackgroundColor(QColor(Qt::red));
		}
		ui.productiontableWidget->setItem(r, 2, l);

		QTableWidgetItem *m = new QTableWidgetItem;
		//m->setFlags(Qt::ItemIsSelectable);
		m->setText(query.value(3).toString());
		m->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//if (query.value(5).toString()=="K/Z"){
		//m->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "K/Z") {
			m->setBackgroundColor(QColor(Qt::red));
		}
		ui.productiontableWidget->setItem(r, 3, m);

		QTableWidgetItem *n = new QTableWidgetItem;
		n->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		ui.productiontableWidget->setItem(r, 4, n);
		ui.productiontableWidget->setCellWidget(r, 4, new QCheckBox);
		if (query.value(4).toInt() == 1) {
			QWidget *t = ui.productiontableWidget->cellWidget(r, 4);
			QCheckBox* u;
			u = (QCheckBox*) t;
			u->setEnabled(FALSE);
			u->setCheckState(Qt::Checked);
		}
		//if (query.value(5).toString()=="K/Z"){
		//n->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "X") {
			n->setBackgroundColor(QColor(Qt::red));
		}
		//		n->setFlags(Qt::ItemIsSelectable);

		QTableWidgetItem *o = new QTableWidgetItem;
		//	o->setFlags(Qt::ItemIsSelectable);
		o->setText(query.value(5).toString());
		o->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//if (query.value(5).toString()=="K/Z"){
		//o->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "X") {
			o->setBackgroundColor(QColor(Qt::red));
		}
		ui.productiontableWidget->setItem(r, 5, o);

		QTableWidgetItem *p = new QTableWidgetItem;
		//p->setFlags(Qt::ItemIsSelectable);
		p->setText(query.value(6).toString());
		p->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//if (query.value(5).toString()=="K/Z"){
		//p->setBackgroundColor(QColor(Qt::red));
		//}
		if (query.value(5).toString() == "X") {
			p->setBackgroundColor(QColor(Qt::red));
		}
		ui.productiontableWidget->setItem(r, 6, p);

		r++;
	}
	ui.pushDelPro->setEnabled(FALSE);
}
//////////////////////////////////////////??EDO EIMAI//////////////////////////////
void Elina_Labels::Scanned() {
	QString code_t, pid, code;
	code_t = ui.scanlineEdit->text();
	QSqlQuery query(*db1);
	query.exec("select f_code from production where code_t='" + code_t + "'");
	query.last();
	code = query.value(0).toString();

    query.exec("insert into production_deleted (weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia)(select weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia from production where code_t='"+code_t+"')");
    query.exec("delete from production where code_t='" + code_t	+ "'");

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_1);
	QString req_type = "KFDELETE";
	out << quint16(0) << req_type << code_t << code;
	out.device()->seek(0);
	out << quint16(block.size() - sizeof(quint16));
	client->write(block);
	QByteArray block1;
	QDataStream out1(&block, QIODevice::WriteOnly);
	out1.setVersion(QDataStream::Qt_4_1);
	out1 << quint16(0xFFFF);
	client->write(block1);

	ui.scanlineEdit->setText("");
	ui.scanlineEdit->setEnabled(FALSE);
	ui.checkBox->setChecked(FALSE);

	refresh_production();

}

void Elina_Labels::disable_entry_controls() {
	ui.machinespinBox->setEnabled(FALSE);
	ui.aaSpinBox->setEnabled(FALSE);
	ui.middleDateEdit->setEnabled(FALSE);
	ui.qualCombo->setEnabled(FALSE);
	ui.weightLineEdit->setEnabled(FALSE);
	ui.nextButton->setEnabled(FALSE);
	ui.machinespinBox_2->setVisible(FALSE);
	ui.aaSpinBox_2->setVisible(FALSE);
	ui.middleDateEdit_2->setVisible(FALSE);
	ui.machinespinBox_2->setVisible(FALSE);
	ui.aaSpinBox_2->setVisible(FALSE);
	ui.middleDateEdit_2->setVisible(FALSE);
	ui.pushDelPro->setEnabled(FALSE);
    ui.dummyProdDate->setEnabled(FALSE);
    ui.dummyProdDate->setVisible(FALSE);
    ui.dummyVardiaCombo->setEnabled(FALSE);
    ui.dummyVardiaCombo->setVisible(FALSE);

}

void Elina_Labels::enable_entry_controls() {
	ui.machinespinBox->setEnabled(TRUE);
	ui.aaSpinBox->setEnabled(TRUE);
	ui.middleDateEdit->setEnabled(TRUE);
	ui.qualCombo->setEnabled(TRUE);
	ui.weightLineEdit->setEnabled(TRUE);
	ui.nextButton->setEnabled(TRUE);
}

void Elina_Labels::setSpinBoxFormat() {
	if (ui.aaSpinBox->value() < 10) {
		ui.aaSpinBox->setPrefix("0");
	} else {
		ui.aaSpinBox->setPrefix("");
	}
	if (ui.aaSpinBox_2->value() < 10) {
		ui.aaSpinBox_2->setPrefix("0");
	} else {
		ui.aaSpinBox_2->setPrefix("");
	}
	if (ui.aaSpinBox_3->value() < 10) {
		ui.aaSpinBox_3->setPrefix("0");
	} else {
		ui.aaSpinBox_3->setPrefix("");
	}
	ui.pushDelPro->setEnabled(FALSE);

}

void Elina_Labels::clearLineEdit() {
	ui.lineEdit->setText("");
	ui.pushDelPro->setEnabled(FALSE);
}

void Elina_Labels::copy_machine() {
	if (ui.machinespinBox_2->isEnabled() == TRUE)
		ui.machinespinBox_2->setValue(ui.machinespinBox->value());
	if (ui.machinespinBox_3->isEnabled() == TRUE)
		ui.machinespinBox_3->setValue(ui.machinespinBox->value());
}

void Elina_Labels::copy_middledate() {
	if (ui.middleDateEdit_2->isEnabled() == TRUE)
		ui.middleDateEdit_2->setDate(ui.middleDateEdit->date());
	if (ui.middleDateEdit_3->isEnabled() == TRUE)
		ui.middleDateEdit_3->setDate(ui.middleDateEdit->date());
}

QString Elina_Labels::get_code_t(QString f_code) {
	QSqlQuery query(*db1);
	QString middle = get_middle();
	QString f_aa = "SELECT COUNT(*) from PRODUCTION where f_code='" + f_code
			+ "' and middle='" + middle + "'";
	query.exec(f_aa);
	query.first();
	QString day_aa;
	QVariant a;
	a = query.value(0).toInt() + 1;


    f_aa= "SELECT COUNT(*) from PRODUCTION_DUMMY where f_code='" + f_code
            + "' and middle='" + middle + "'";
    query.exec(f_aa);
    query.first();

    a=a.toInt()+query.value(0).toInt()+1;


    day_aa = a.toString();




	if (day_aa.length() == 1)
		day_aa = "0" + day_aa;

	QString weight;
	QString qual1;
	switch (ui.qualCombo->currentIndex()) {
	case 0:
		qual1 = "X";
		break;
	case 1:
		qual1 = "Y";
		break;
	case 2:
		qual1 = "Z";
		break;
    //case 3:
        //qual1 = "-";
        //break;
    case 3:
        qual1 = "A";

		break;
	}

	switch (ui.weightLineEdit->text().length()) {
	case 1:
		weight = "00" + ui.weightLineEdit->text();
		break;
	case 2:
		weight = "0" + ui.weightLineEdit->text();
		break;
	case 3:
		weight = ui.weightLineEdit->text();
		break;

	}

	QString code_t = weight + middle + qual1 + day_aa;
	return code_t;
}

QString Elina_Labels::get_middle() {
	QString middle = ui.machinespinBox->text()
			+ ui.middleDateEdit->text().remove("/") + ui.aaSpinBox->text();
	return middle;

}
QString Elina_Labels::get_middle2() {
	QString middle = ui.machinespinBox_2->text()
			+ ui.middleDateEdit_2->text().remove("/") + ui.aaSpinBox_2->text();
	return middle;

}
QString Elina_Labels::get_middle3() {
	QString middle = ui.machinespinBox_3->text()
			+ ui.middleDateEdit_3->text().remove("/") + ui.aaSpinBox_3->text();
	return middle;

}

void Elina_Labels::startread() {
	QDataStream in(client);
	in.setVersion(QDataStream::Qt_4_1);
	nextblocksize = 0;
	QSqlQuery query(*db1);

	forever {
		if (nextblocksize == 0) {
			if (client->bytesAvailable() < sizeof(quint16))
				return;
			in >> nextblocksize;
			qDebug() << nextblocksize;

		}

		if (nextblocksize == 0xFFFF) {

			return;
		}

		if (client->bytesAvailable() < nextblocksize)
			return;
		QString req_type;
		in >> req_type;

		qDebug() << req_type;
		if (req_type == "KFCHECK") {

			QString reply, code;
			in << reply << code;
			if (reply == "0") {
				QDate pr_date = QDate::currentDate();
				QMessageBox::critical(this, qApp->trUtf8("Προσοχή"),
						qApp->trUtf8("Ο κωδικός δεν βρέθηκε στο ΚΕΦ.\n"
							"Πιέστε ΟΚ για συνέχεια."));
				query.exec("insert into notfound (code,prdate) values ('"
						+ code + "','" + pr_date.toString("MM-dd-yyyy") + "')");

				this->kefcheck = FALSE;
			}
		}

	}

}

void Elina_Labels::checkClicked() {
	ui.pushDelPro->setEnabled(FALSE);
	if (ui.checkBox->checkState() == 2)
		ui.scanlineEdit->setEnabled(TRUE);
	else
		ui.scanlineEdit->setEnabled(FALSE);

}

void Elina_Labels::rewrapClicked() {
	ui.pushDelPro->setEnabled(FALSE);
    rewrap *w = new rewrap(this, db1);
	w->move(200, 200);
	w->show();

}

void Elina_Labels::weight_check() {
	ui.pushDelPro->setEnabled(FALSE);
	QString weight = ui.weightLineEdit->text();
	bool ok;
	int wint = weight.toInt(&ok, 10);

	if (ok == FALSE) {
		weight = "";
		goto tt;
	}

    if (wint > 999) {
		weight = "";
		goto tt;
	}

	if (weight.length() > 3) {
		weight = weight.left(3);
	}

	tt: ui.weightLineEdit->setText(weight);

}

void Elina_Labels::rowClickedSelProd(const QModelIndex &index) {

	row_sel = index.row();

	QTableWidgetItem *c = ui.productiontableWidget->item(row_sel, 3);
	QString code_t = c->text();
	QMessageBox m;
	m.setText(trUtf8("Θέλετε να διαγράψετε τον Κ/Τ"));
	m.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
	QAbstractButton *acc = m.addButton(trUtf8("Ναί"),
			QMessageBox::ActionRole);
	QAbstractButton *rej = m.addButton(trUtf8("Όχι"), QMessageBox::ActionRole);

	m.move(100, 100);
	QFont serifFont("Times", 18, QFont::Bold);
	m.setFont(serifFont);
	m.setDefaultButton((QPushButton*)rej);

	m.exec();
	if (m.clickedButton() == rej) {
		return;

	}

	if (m.clickedButton() == acc) {

		QMessageBox n;
        n.setText(trUtf8("Είστε σίγουροι ότι θέλετε να διαγράψετε τον Κ/Τ"));
		n.setInformativeText(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		QAbstractButton *acc1 = n.addButton(trUtf8("Ναί"),
				QMessageBox::ActionRole);
		QAbstractButton *rej1 = n.addButton(trUtf8("Όχι"),
				QMessageBox::ActionRole);

		n.move(100, 100);
		n.setDefaultButton((QPushButton*)rej1);
		QFont serifFont("Times", 18, QFont::Bold);
		n.setFont(serifFont);

		n.exec();
		if (n.clickedButton() == rej1) {
			return;

		}
		if (n.clickedButton() == acc1) {

			QString pid, code;

			QSqlQuery query(*db1);
			query.exec("select f_code from production where code_t='" + code_t
					+ "'");
			query.last();
			code = query.value(0).toString();

            query.exec("insert into production_deleted (weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia)(select weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia from production where code_t='"+code_t+"')");
			query.exec("delete from production where code_t='" + code_t	+ "'");
			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_4_1);
			QString req_type = "KFDELETE";
			out << quint16(0) << req_type << code_t << code;
			out.device()->seek(0);
			out << quint16(block.size() - sizeof(quint16));
			client->write(block);
			QByteArray block1;
			QDataStream out1(&block, QIODevice::WriteOnly);
			out1.setVersion(QDataStream::Qt_4_1);
			out1 << quint16(0xFFFF);
			client->write(block1);

			//ui.scanlineEdit->setText("");
			//ui.scanlineEdit->setEnabled(FALSE);
			//ui.checkBox->setChecked(FALSE);

			refresh_production();

			return;

		}

		return;

	}

	ui.pushDelPro->setEnabled(TRUE);

}

void Elina_Labels::timer1_v()
{
    QSqlQuery query(*db1);
    query.exec("SELECT top 1 iskef from production order by id desc");
    query.next();
    if (query.value(0).toInt()==0)
    {
        timer1->stop();
        timer2->start(108000000);
        QStringList to1;
        QString from="linux@komotinipaper.gr";
        to1.append("pg@komotinipaper.gr");
        to1.append("mg@komotinipaper.gr");
        to1.append("elefter@alfasoftware.gr");
        QString subject="COMMUNICATION ERROR";
        QString body="Η ΠΑΡΑΓΩΓΗ ΔΕΝ ΕΝΗΜΕΡΩΝΕΙ ΤΟ ΚΕΦΑΛΑΙΟ";
        MailSender test1("localhost",from,to1, subject, body);
        test1.setPriority(MailSender::high);
        test1.send();

    }


}

void Elina_Labels::timer2_v()
{
    timer2->stop();
    timer1->start(60000);
}

void Elina_Labels::dummycheckpressed()
{
    if (ui.dummycheckBox->checkState() == 2)
    {
        ui.dummyProdDate->setEnabled(TRUE);
        ui.dummyProdDate->setVisible(TRUE);
        //ui.dummyProdDate->setDate(QDate::currentDate());
        ui.dummyVardiaCombo->setEnabled(TRUE);
        ui.dummyVardiaCombo->setVisible(TRUE);
        ui.label_8->setVisible(TRUE);
        ui.label_9->setVisible(TRUE);
    }

    else
    {
        ui.dummyProdDate->setEnabled(FALSE);
        ui.dummyProdDate->setVisible(FALSE);
        ui.dummyVardiaCombo->setEnabled(FALSE);
        ui.dummyVardiaCombo->setVisible(FALSE);
        ui.label_8->setVisible(FALSE);
        ui.label_9->setVisible(FALSE);
    }
}
