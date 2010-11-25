#include "elina_labels.h"
//#define QT_USE_FAST_CONCATENATION
//#include <QStringBuilder>
#include <fstream>
#include <iostream>
#include "scanlabels.h"

using namespace std;

Elina_Labels::Elina_Labels(QWidget *parent,QSqlDatabase *db,QSqlDatabase *db1) :
	QDialog(parent) {
	codec = QTextCodec::codecForName("Windows1253");
	decoder = codec->makeDecoder();
	this->db=db;
	this->db1=db1;

	setupModel_Code("");

	ui.setupUi(this);
	ui.nextButton->setEnabled(FALSE);

	ui.tableView->setModel(model);
	ui.tableView->setColumnWidth(0, 150);
	ui.tableView->setColumnWidth(1, 500);

	ui.qualCombo->insertItem(0, "1A");
	ui.qualCombo->insertItem(1, "2A");
	ui.qualCombo->insertItem(2, "3A");

	ui.qualCombo->setCurrentIndex(-1);
	scanlabels_dialog=new scanlabels(this,db,db1);


	// find out which IP to connect to
	QString ipAddress;
	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// use the first non-localhost IPv4 address
	for (int i = 0; i < ipAddressesList.size(); ++i) {
		if (ipAddressesList.at(i) != QHostAddress::LocalHost
				&& ipAddressesList.at(i).toIPv4Address()) {
			ipAddress = ipAddressesList.at(i).toString();
			break;
		}
	}
	// if we did not find one, use IPv4 localhost
	if (ipAddress.isEmpty())
		ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

	tcpSocket = new QTcpSocket(this);
	connect(ui.getDataButton, SIGNAL(clicked()), this, SLOT(requestNewData()));
	connect(ui.quitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this,
			SLOT(displayError(QAbstractSocket::SocketError)));

	connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this,
			SLOT(onTypeChar()));
	connect(ui.tableView, SIGNAL(pressed(const QModelIndex &)), this,
			SLOT(rowClicked(const QModelIndex &)));
	connect(ui.nextButton, SIGNAL(clicked()), this, SLOT(next1Clicked()));

}

Elina_Labels::~Elina_Labels()
{

}

void Elina_Labels::requestNewData() {
	ui.getDataButton->setEnabled(false);
	blockSize = 0;
	tcpSocket->abort();
	tcpSocket->connectToHost(SVR_HOST,7071);
}

void Elina_Labels::readData() {
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_0);

	if (blockSize == 0) {
		if (tcpSocket->bytesAvailable() < (int) sizeof(quint16))
			return;

		in >> blockSize;
	}

	if (tcpSocket->bytesAvailable() < blockSize)
		return;

	QString nextData;
	in >> nextData;

	if (nextData == currentData) {
		QTimer::singleShot(0, this, SLOT(requestNewData()));
		return;
	}

	currentData = nextData;
	//ui.statusLabel->setText(currentData);
	return ;
}

void Elina_Labels::displayError(QAbstractSocket::SocketError socketError) {
	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, tr("Fortune Client"), tr(
				"The host was not found. Please check the "
					"host name and port settings."));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Fortune Client"), tr(
				"The connection was refused by the peer. "
					"Make sure the fortune server is running, "
					"and check that the host name and port "
					"settings are correct."));
		break;
	default:
		QMessageBox::information(this, tr("Fortune Client"), tr(
				"The following error occurred: %1.") .arg(
				tcpSocket->errorString()));
	}

	ui.getDataButton->setEnabled(true);
}


void Elina_Labels::setupModel_Code(QString like) {
	QString
			query =
					("SELECT kodikos_p,perigrafi FROM telika_proionta where kodikos_p like \'");

	query.append(like);
	QString sup = "%\'";
	query.append(sup);
	QSqlQuery qp;
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
	model1->setHeaderData(1, Qt::Horizontal, trUtf8("Περιγραφή"));
	//    	QSqlError jim=db.lastError();
	//    	qDebug()<<jim;
	model = model1;

}

void Elina_Labels::onTypeChar() {
	QString like = ui.lineEdit->text();
	ui.prodLabel->setText("");
	this->setupModel_Code(like);
	ui.tableView->setModel(model);
}

void Elina_Labels::rowClicked(const QModelIndex &index) {
	int row = index.row();
	QString code = model->record(row).value(0).toString();
	ui.lineEdit->setText(code);
	QString query =
			"select p.kodikos as kodikos from prodiagrafes p,telika_proionta t where "
				"t.prodiagrafi=p.pid and t.kodikos_p='";
	query.append(code);
	query.append("'");
	QSqlQuery qp;
	qp.exec(query);
	qp.next();
	QString prod = qp.value(0).toString();
	ui.prodLabel->setText(prod);
	ui.nextButton->setEnabled(TRUE);
}

void Elina_Labels::next1Clicked() {
	if (final_check()==FALSE) return;

	if (check_kef_code()==FALSE) return;

	QString code_t=	insert_db_prod();

	//print_label(code_t);
	this->scanlabels_dialog->move(200,300);

	this->scanlabels_dialog->show();
	this->scanlabels_dialog->activateWindow();


}

bool Elina_Labels::check_kef_code() {

	QSqlQuery query(*db1);
	int k;
	QString code = ui.lineEdit->text();
	query.exec("select * from expstockitem where scode='" + code + "'");
	query.last();
	k = query.at() + 1;

	if (k < 1) {
		QMessageBox::critical(0, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Ο κωδικός δεν βρέθηκε στο ΚΕΦ.\n"
					"Πιέστε ΟΚ για συνέχεια."), QMessageBox::Ok,
				QMessageBox::NoButton);
		return FALSE;
	}
	return TRUE;

}

QString Elina_Labels::insert_db_prod() {

	QString f_code = ui.lineEdit->text();
	QString weight = ui.weightLineEdit->text();

	QString middle = ui.machinespinBox->text()
			+ ui.middleDateEdit->text().remove("/") + ui.aaSpinBox->text();
	QString qual,qual1;
	switch (ui.qualCombo->currentIndex()) {
	case 0:
		qual = "1A";
		qual1= "X";
		break;
	case 1:
		qual = "2A";
		qual1= "Y";
		break;
	case 2:
		qual = "3A";
		qual1= "Z";
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
	QDateTime nextdate=pr_date.addDays(1);
	QString code = ui.lineEdit->text();
	QString f_aa = "SELECT COUNT(*) from PRODUCTION where f_code='" + code
			+ "' and pr_date>='" + pr_date.toString("MM-dd-yyyy") + "' and pr_date<'"+nextdate.toString("MM-dd-yy")+"'";
	query.exec(f_aa);
	query.first();

	QString day_aa;

	QVariant a;

	a = query.value(0).toInt() + 1;

	day_aa = a.toString();

	if (day_aa.length() == 1)
		day_aa = "0" + day_aa;

	QString code_t = weight + middle + qual1 + day_aa;
	if (ui.dummycheckBox->checkState()==0){
	QString
			insert =
					"INSERT INTO PRODUCTION(weight,quality,middle,aa,pr_date,f_code,isKef,code_t) VALUES ("
							+ weight + ",'" + qual + "','" + middle + "',"
							+ ui.aaSpinBox->text() + ",'"
							+ QDateTime::currentDateTime().toString(Qt::ISODate)
							+ "','" + f_code + "',0,'" + code_t + "')";
	query.exec(insert);
	}
	return code_t;
}

bool Elina_Labels::final_check() {
	if (ui.aaSpinBox->text() == "0") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε Α/Α"));
		return FALSE;
	}

	if (ui.lineEdit->text() == "") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν επιλέχθηκε κωδικός"));
		return FALSE;
	}

	if (ui.prodLabel->text() == "") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν βρέθηκε η προδιαγραφή"));
		return FALSE;
	}

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

	if (ui.machinespinBox->text() == "0") {
		QMessageBox::critical(this, qApp->trUtf8("Προσοχή"), qApp->trUtf8(
				"Δεν δόθηκε μηχανή"));
		return FALSE;
	}

	return TRUE;

}

void Elina_Labels::print_label(QString code_t) {

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
	QString f_code=ui.lineEdit->text();
	QString weight=ui.weightLineEdit->text();

	QSqlQuery query(*db);
	QString a="SELECT perigrafi2,kopi FROM telika_proionta where kodikos_p='"+f_code+"'";
	query.exec(a);
	query.last();
	QString quality= query.value(0).toString();
	QString width=query.value(1).toString();
	a="SELECT p.fulla from prodiagrafes p,telika_proionta t where t.prodiagrafi=p.pid and t.kodikos_p='"+f_code+"'";
	query.exec(a);
	query.last();
	QString fylla=query.value(0).toString();
	QTime ct=QTime::currentTime();
	QString cdate=QDate::currentDate().toString("dd/MM/yyyy");
	int hr=ct.hour();
    QString vardia;
    if (hr>=6 && hr<14) vardia="A";
    if (hr>=14 && hr<22) vardia="B";
    if (hr>=22 && hr<=23) vardia="C";
    if (hr<6) vardia="C";
	//Qt implementation test
	QFile fh("/dev/lp0");
	fh.open(QIODevice::WriteOnly);
	QTextStream out(&fh);

	QFile lab("lab/Elina.txt");
	QString line;

	if (lab.open(QFile::ReadOnly)) {
		QTextStream in(&lab);
		out.setCodec("UTF-8 ");
		//out.setCodec("UTF-8");
		in.setCodec("UTF-8");

		do {
			line = in.readLine();
			line.replace("@quality1111111",quality);
			line.replace("@barcode>5222222>62",f_code);
			line.replace("@barcode>5333333>63",code_t);
			line.replace("@f",fylla);
			line.replace("@width",width);
			line.replace("@weight",weight);
			line.replace("@7",vardia);
			line.replace("@date88888",cdate);
			out << line << endl;
			out.flush();

		} while (!line.isNull());
	}
	fh.close();
}

