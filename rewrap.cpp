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

#include "rewrap.h"

rewrap::rewrap(QWidget *parent, QSqlDatabase *db1) :
	QDialog(parent) {
	ui.setupUi(this);
    QString settingsFile = (QDir::currentPath()+ "/settings.ini");
    QSettings *settings =new QSettings(settingsFile,QSettings::IniFormat);

    QString appserver=settings->value("appserver").toString();

	this->db1 = db1;
    QHostAddress addr((QString) appserver);
	client = new QTcpSocket;
	client->connectToHost(addr, 8889);
    ui.lineAold->setFocus();
	ui.label_new1->setVisible(FALSE);
	ui.label_new2->setVisible(FALSE);
	ui.label_new3->setVisible(FALSE);
	ui.label_new4->setVisible(FALSE);
	ui.label_new5->setVisible(FALSE);
    ui.lineANew1->setVisible(FALSE);
    ui.lineANew2->setVisible(FALSE);
    ui.lineANew3->setVisible(FALSE);
    ui.lineANew4->setVisible(FALSE);
    ui.lineANew5->setVisible(FALSE);
	ui.lineNew1->setVisible(FALSE);
	ui.lineNew2->setVisible(FALSE);
	ui.lineNew3->setVisible(FALSE);
	ui.lineNew4->setVisible(FALSE);
	ui.lineNew5->setVisible(FALSE);
	ui.pushCancel->setEnabled(FALSE);
	ui.pushInsert->setEnabled(FALSE);
	ui.pushCancel->setFocusPolicy(Qt::NoFocus);
	ui.pushInsert->setFocusPolicy(Qt::NoFocus);
	connect(ui.lineOld, SIGNAL(returnPressed()), this, SLOT(scanned_old()));
    connect(ui.lineAold, SIGNAL(returnPressed()), this, SLOT(scanned_Aold()));
    connect(ui.lineANew1, SIGNAL(returnPressed()), this, SLOT(scanned_Anew1()));
    connect(ui.lineANew2, SIGNAL(returnPressed()), this, SLOT(scanned_Anew2()));
    connect(ui.lineANew3, SIGNAL(returnPressed()), this, SLOT(scanned_Anew3()));
    connect(ui.lineANew4, SIGNAL(returnPressed()), this, SLOT(scanned_Anew4()));
    connect(ui.lineANew5, SIGNAL(returnPressed()), this, SLOT(scanned_Anew5()));

	connect(ui.lineNew1, SIGNAL(returnPressed()), this, SLOT(scanned_new1()));
	connect(ui.lineNew2, SIGNAL(returnPressed()), this, SLOT(scanned_new2()));
	connect(ui.lineNew3, SIGNAL(returnPressed()), this, SLOT(scanned_new3()));
	connect(ui.lineNew4, SIGNAL(returnPressed()), this, SLOT(scanned_new4()));
	connect(ui.lineNew5, SIGNAL(returnPressed()), this, SLOT(scanned_new5()));
	connect(ui.pushCancel, SIGNAL(clicked()), this, SLOT(cancelClicked()));
	connect(ui.pushInsert, SIGNAL(clicked()), this, SLOT(insertClicked()));
    delete settings;

}

rewrap::~rewrap() {
	client->disconnectFromHost();

}

void rewrap::scanned_Aold() {
    QString scanned = ui.lineAold->text();

    QRegExp ka("\[AE]\\d{14,14}");

    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineAold->setText("");
        ui.lineAold->setFocus();
        return;
    }
    ui.lineOld->setFocus();
}


void rewrap::scanned_old() {
	QString scanned = ui.lineOld->text();

	QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineOld->setText("");
		ui.lineOld->setFocus();
		return;
	}
	ui.label_new1->setVisible(TRUE);
    ui.lineANew1->setVisible(TRUE);
    ui.lineANew1->setFocus();
}

void rewrap::scanned_Anew1() {

    QString scanned = ui.lineANew1->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineANew1->setText("");
        ui.lineANew1->setFocus();
        return;
    }
    ui.label_new1->setVisible(TRUE);
    ui.lineNew1->setVisible(TRUE);
    ui.lineNew1->setFocus();

}



void rewrap::scanned_new1() {
	QString scanned = ui.lineNew1->text();

	QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineNew1->setText("");
		ui.lineNew1->setFocus();
		return;
	}
    if (ui.lineNew1->text()==ui.lineOld->text())
    {
        QMessageBox m;

        m.setText(trUtf8("O K/T έχει ξαναδιαβαστεί"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineNew3->setText("");
        ui.lineNew3->setFocus();
        return;

    }

	ui.label_new2->setVisible(TRUE);
    ui.lineANew2->setVisible(TRUE);
    ui.lineANew2->setFocus();
	ui.pushCancel->setEnabled(TRUE);
	ui.pushInsert->setEnabled(TRUE);
}


void rewrap::scanned_Anew2() {
    QString scanned = ui.lineANew2->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineANew2->setText("");
        ui.lineANew2->setFocus();
        return;
    }

    ui.lineNew2->setVisible(TRUE);
    ui.lineNew2->setFocus();
}







void rewrap::scanned_new2() {
	QString scanned = ui.lineNew2->text();

	QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineNew2->setText("");
		ui.lineNew2->setFocus();
		return;
	}

    if (ui.lineNew2->text()==ui.lineOld->text() || ui.lineNew2->text()==ui.lineNew1->text())
    {
        QMessageBox m;

        m.setText(trUtf8("O K/T έχει ξαναδιαβαστεί"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineNew2->setText("");
        ui.lineNew2->setFocus();
        return;

    }

	ui.label_new3->setVisible(TRUE);
    ui.lineANew3->setVisible(TRUE);
    ui.lineANew3->setFocus();
}


void rewrap::scanned_Anew3() {
    QString scanned = ui.lineANew3->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineANew3->setText("");
        ui.lineANew3->setFocus();
        return;
    }


    ui.lineNew3->setVisible(TRUE);
    ui.lineNew3->setFocus();
}


void rewrap::scanned_new3() {
	QString scanned = ui.lineNew3->text();

	QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineNew3->setText("");
		ui.lineNew3->setFocus();
		return;
	}

    if (ui.lineNew3->text()==ui.lineOld->text() || ui.lineNew3->text()==ui.lineNew1->text() || ui.lineNew3->text()==ui.lineNew2->text())
    {
        QMessageBox m;

        m.setText(trUtf8("O K/T έχει ξαναδιαβαστεί"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineNew3->setText("");
        ui.lineNew3->setFocus();
        return;

    }





    ui.label_new4->setVisible(TRUE);
    ui.lineANew4->setVisible(TRUE);
    ui.lineANew4->setFocus();
}


void rewrap::scanned_Anew4() {
    QString scanned = ui.lineANew4->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/A"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineANew4->setText("");
        ui.lineANew4->setFocus();
        return;
    }




    ui.lineNew4->setVisible(TRUE);
    ui.lineNew4->setFocus();
}


void rewrap::scanned_new4() {
	QString scanned = ui.lineNew4->text();

	QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineNew4->setText("");
		ui.lineNew4->setFocus();
		return;
	}

    if (ui.lineNew4->text()==ui.lineOld->text() || ui.lineNew4->text()==ui.lineNew1->text() || ui.lineNew4->text()==ui.lineNew2->text() || ui.lineNew4->text()==ui.lineNew3->text())
    {
        QMessageBox m;

        m.setText(trUtf8("O K/T έχει ξαναδιαβαστεί"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineNew4->setText("");
        ui.lineNew4->setFocus();
        return;

    }


	ui.label_new5->setVisible(TRUE);
    ui.lineANew5->setVisible(TRUE);
    ui.lineANew5->setFocus();
}

void rewrap::scanned_Anew5() {
    QString scanned = ui.lineANew5->text();

    QRegExp ka("\[AE]\\d{14,14}");
    if (ka.exactMatch(scanned) == FALSE) {
        QMessageBox m;

        m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineANew5->setText("");
        ui.lineANew5->setFocus();
        return;
    }

    ui.lineNew5->setVisible(TRUE);
    ui.lineNew5->setFocus();
}


void rewrap::scanned_new5() {
	QString scanned = ui.lineNew5->text();

	QRegExp kt("\\d{12,12}[XYZ-]\\d{2,2}");
	if (kt.exactMatch(scanned) == FALSE) {
		QMessageBox m;

		m.setText(trUtf8("Λάθος μορφή  Κ/Τ"));
		m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
		m.setStandardButtons(QMessageBox::Ok);
		m.move(0, 100);
		QFont serifFont("Times", 18, QFont::Bold);
		m.setFont(serifFont);
		m.exec();
		ui.lineNew5->setText("");
		ui.lineNew5->setFocus();
		return;
	}

    if (ui.lineNew5->text()==ui.lineOld->text() || ui.lineNew5->text()==ui.lineNew1->text() || ui.lineNew5->text()==ui.lineNew2->text() || ui.lineNew5->text()==ui.lineNew3->text() || ui.lineNew5->text()==ui.lineNew4->text() )
    {
        QMessageBox m;

        m.setText(trUtf8("O K/T έχει ξαναδιαβαστεί"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.exec();
        ui.lineNew5->setText("");
        ui.lineNew5->setFocus();
        return;

    }


}

void rewrap::insertClicked() {
	int newWeight = 0;
	int oldWeight = 0;

	newWeight += ui.lineNew1->text().left(3).toInt();

	if (ui.lineNew2->text() != "")
		newWeight += ui.lineNew2->text().left(3).toInt();

	if (ui.lineNew3->text() != "")
		newWeight += ui.lineNew3->text().left(3).toInt();

	if (ui.lineNew4->text() != "")
		newWeight += ui.lineNew4->text().left(3).toInt();

	if (ui.lineNew5->text() != "")
		newWeight += ui.lineNew5->text().left(3).toInt();

	oldWeight = ui.lineOld->text().left(3).toInt();





    if (oldWeight <newWeight)  {
        QMessageBox m;

        m.setText(trUtf8("ΔΕΝ ΓΙΝΕΤΑΙ Η ΑΝΑΤΥΛΙΞΗ ΝΑ ΕΧΕΙ ΠΕΡΙΣΣΟΤΕΡΑ ΚΙΛΑ ΑΠΟ ΤΟ ΑΡΧΙΚΟ ΠΡΟΪΟΝ. ΚΑΛΕΣΤΕ ΕΝΑΝ ΥΠΕΥΘΥΝΟ."));
        m.setWindowTitle(trUtf8("ΛΑΘΟΣ!!!"));
        m.setStandardButtons(QMessageBox::Ok);
        m.move(0, 100);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);
        m.move(200,200);
        m.exec();

        return;
    }

    if (oldWeight >newWeight) {
        QMessageBox m;

        m.setText(trUtf8("ΤΑ ΚΙΛΑ ΔΕΝ ΣΥΜΦΩΝΟΥΝ!ΝΑ ΠΕΡΑΣΩ ΤΑ ΚΙΛΑ ΠΟΥ ΠΕΡΙΣΣΕΥΟΥΝ ΩΣ ΦΥΡΑ;"));
        m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
        QAbstractButton *acc1 = m.addButton(trUtf8("Ναί"),
                QMessageBox::ActionRole);
        QAbstractButton *rej1 = m.addButton(trUtf8("Όχι"),
                QMessageBox::ActionRole);
        m.move(0, 100);

        m.setDefaultButton((QPushButton*)rej1);
        QFont serifFont("Times", 18, QFont::Bold);
        m.setFont(serifFont);

        m.exec();
        if (m.clickedButton() == rej1) {

            return;

        }
    }




















	QStringList new_codes = (QStringList() << ui.lineNew1->text()
			<< ui.lineNew2->text() << ui.lineNew3->text()
			<< ui.lineNew4->text() << ui.lineNew5->text());
	QString old_code = ui.lineOld->text();

    QStringList new_acodes = (QStringList() << ui.lineANew1->text()
            << ui.lineANew2->text() << ui.lineANew3->text()
            << ui.lineANew4->text() << ui.lineANew5->text());
    QString old_acode = ui.lineAold->text();

    insert_production(old_code, new_codes,old_acode,new_acodes);
	delete(this);
}

void rewrap::cancelClicked() {
	delete (this);
}

void rewrap::insert_production(QString old_code, QStringList new_codes,QString old_acode,QStringList new_acodes) {
	QSqlQuery query(*db1);
	query.exec(
			"select top 1 id,pr_date,vardia,f_code,middle,middle_2,middle_3 from production where code_t='"
					+ old_code + "'");
	query.next();
	QString id = query.value(0).toString();
	QString pr_date = query.value(1).toString();
	QString vardia = query.value(2).toString();
    //QString f_code = query.value(3).toString();
	QString middle = query.value(4).toString();
	QString middle_2 = query.value(5).toString();
	QString middle_3 = query.value(6).toString();

	query.exec("DELETE from production where code_t='"+old_code+"'");
    QString last_record="0";

    int ls= new_codes.indexOf(NULL)-1;

    if (ls==-1 )
        ls=4;
	for (int q = 0; q < new_codes.size(); ++q) {
		QString code_t = new_codes.value(q);
        QString code_a = new_acodes.value(q);
		if (code_t != "") {
			QString weight = code_t.left(3);
			QString qual = code_t.mid(12, 1);
            if (qual=="X")
                qual="1A";
            if (qual=="Y")
                qual="2A";
            if (qual=="Z")
                qual="3A";

			QString aa = code_t.mid(11, 1);
			query.exec(
					"INSERT INTO PRODUCTION(weight,quality,middle,aa,pr_date,f_code,isKef,code_t,middle_2,middle_3,vardia) VALUES ("
							+ weight + ",'" + qual + "','" + middle + "'," + aa
                            + ",'" + pr_date + "','" + code_a + "',0,'"
							+ code_t + "','" + middle_2 + "','" + middle_3
							+ "','" + vardia + "')");
			query.exec("select top 1 id from production where code_t='"+ code_t + "'");
			query.next();
			QString pid = query.value(0).toString();

			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_4_1);
			QString req_type = "KFREWRAP";


            if (q==ls)
                last_record="1";
            out << quint16(0) << req_type << old_code << code_t << old_acode << code_a << pid	<< vardia << last_record;
            out.device()->seek(0);
			out << quint16(block.size() - sizeof(quint16));
			client->write(block);
			QByteArray block1;
			QDataStream out1(&block, QIODevice::WriteOnly);
			out1.setVersion(QDataStream::Qt_4_1);
			out1 << quint16(0xFFFF);
			client->write(block1);

		}

	}
}
