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
#include "elina_labels.h"

rewrap::rewrap(QWidget *parent, QSqlDatabase *db1) :
    QDialog(parent),db1(db1) {
	ui.setupUi(this);

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


}

rewrap::~rewrap() {


}

void rewrap::scanned_Aold() {
    QString scanned = ui.lineAold->text();

    if (! Elina_Labels::checkCodeA(scanned))
    {
        ui.lineAold->setText("");
        ui.lineAold->setFocus();
        return;
    }
    ui.lineOld->setFocus();
}


void rewrap::scanned_old() {
	QString scanned = ui.lineOld->text();

    if (!Elina_Labels::checkCodeT(scanned))
    {
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

    if (! Elina_Labels::checkCodeA(scanned)) {
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

    if (! Elina_Labels::checkCodeT(scanned)) {
        ui.lineNew1->setText("");
		ui.lineNew1->setFocus();
		return;
	}
    if (ui.lineNew1->text()==ui.lineOld->text())
    {
        doubleread();
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

    if (! Elina_Labels::checkCodeA(scanned)) {
        ui.lineANew2->setText("");
        ui.lineANew2->setFocus();
        return;
    }

    ui.lineNew2->setVisible(TRUE);
    ui.lineNew2->setFocus();
}







void rewrap::scanned_new2() {
	QString scanned = ui.lineNew2->text();

    if (! Elina_Labels::checkCodeT(scanned)) {
		ui.lineNew2->setText("");
		ui.lineNew2->setFocus();
		return;
	}

    if (ui.lineNew2->text()==ui.lineOld->text() || ui.lineNew2->text()==ui.lineNew1->text())
    {
        doubleread();
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

    if (! Elina_Labels::checkCodeA(scanned)) {
        ui.lineANew3->setText("");
        ui.lineANew3->setFocus();
        return;
    }


    ui.lineNew3->setVisible(TRUE);
    ui.lineNew3->setFocus();
}


void rewrap::scanned_new3() {
	QString scanned = ui.lineNew3->text();

if (! Elina_Labels::checkCodeT(scanned)) {
        ui.lineNew3->setText("");
		ui.lineNew3->setFocus();
		return;
	}

    if (ui.lineNew3->text()==ui.lineOld->text() || ui.lineNew3->text()==ui.lineNew1->text() || ui.lineNew3->text()==ui.lineNew2->text())
    {
        doubleread();
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

    if (! Elina_Labels::checkCodeA(scanned)) {
        ui.lineANew4->setText("");
        ui.lineANew4->setFocus();
        return;
    }




    ui.lineNew4->setVisible(TRUE);
    ui.lineNew4->setFocus();
}


void rewrap::scanned_new4() {
	QString scanned = ui.lineNew4->text();

    if (! Elina_Labels::checkCodeT(scanned)) {
        ui.lineNew4->setText("");
		ui.lineNew4->setFocus();
		return;
	}

    if (ui.lineNew4->text()==ui.lineOld->text() || ui.lineNew4->text()==ui.lineNew1->text() || ui.lineNew4->text()==ui.lineNew2->text() || ui.lineNew4->text()==ui.lineNew3->text())
    {
        doubleread();
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

    if (! Elina_Labels::checkCodeA(scanned)) {
        ui.lineANew5->setText("");
        ui.lineANew5->setFocus();
        return;
    }

    ui.lineNew5->setVisible(TRUE);
    ui.lineNew5->setFocus();
}




void rewrap::scanned_new5() {
	QString scanned = ui.lineNew5->text();

    if (! Elina_Labels::checkCodeT(scanned)) {
        ui.lineNew5->setText("");
		ui.lineNew5->setFocus();
		return;
	}

    if (ui.lineNew5->text()==ui.lineOld->text() || ui.lineNew5->text()==ui.lineNew1->text() || ui.lineNew5->text()==ui.lineNew2->text() || ui.lineNew5->text()==ui.lineNew3->text() || ui.lineNew5->text()==ui.lineNew4->text() )
    {
        doubleread();
        ui.lineNew5->setText("");
        ui.lineNew5->setFocus();
        return;

    }


}

void rewrap::doubleread()
{
    QMessageBox m;

    m.setText(trUtf8("O K/T έχει ξαναδιαβαστεί"));
    m.setWindowTitle(trUtf8("ΠΡΟΣΟΧΗ!!!"));
    m.setStandardButtons(QMessageBox::Ok);
    m.move(0, 100);
    QFont serifFont("Times", 18, QFont::Bold);
    m.setFont(serifFont);
    m.exec();
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
    query.exec(	"select top 1 pr_date from production where code_t='"+ old_code + "'");
	query.next();

    QString pr_date = query.value(0).toString();




    for (int q = 0; q < new_codes.size(); ++q) {
		QString code_t = new_codes.value(q);
        QString code_a = new_acodes.value(q);
        query.prepare("INSERT INTO rewrap (oldcode_a,oldcode_t,newcode_a,newcode_t,rewrap_date,pr_date_oldcode) VALUES (?,?,?,?,?,?)");
        query.addBindValue(old_acode);
        query.addBindValue(old_code);
        query.addBindValue(code_a);
        query.addBindValue(code_t);
        query.addBindValue(old_acode);
        query.addBindValue(QDateTime::currentDateTime().toString(Qt::ISODate)) ;
        query.addBindValue(pr_date);
        query.exec();

		}

	}

