#include "newcontact.h"
#include "ui_newcontact.h"

NewContact::NewContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewContact)
{
    ui->setupUi(this);
}

NewContact::~NewContact()
{
    delete ui;
}

void NewContact::on_lePhone_editingFinished()
{
    QRegExp rx("\\d\\s(\\d\\d\\d)\\s\\d\\d-\\d\\d\\d-\\d\\d");

    if (rx.exactMatch(ui->lePhone->text()))
    {
        ui->lePhone->setFocus();
    }
}


void NewContact::on_lePhone_selectionChanged()
{
   QRegExp rx("\\d\\s(\\d\\d\\d)\\s\\d\\d-\\d\\d\\d-\\d\\d");
    if (!rx.exactMatch(ui->lePhone->text()))
    {
        ui->lePhone->setFocus(Qt::OtherFocusReason);
        bool f = ui->lePhone->hasFocus();
        f = false;
    }
}

void NewContact::closeEvent(QCloseEvent *event)
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    rx.exactMatch(ui->lePhone->text());
    QString temp = ui->lePhone->text();
    int i = rx.matchedLength();
    if (rx.exactMatch(ui->lePhone->text())) {
        event->accept();
    } else {
        event->ignore();
    }
}

void NewContact::on_buttonBox_accepted()
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d-\\d\\d\\d-\\d\\d");
     /*if (rx.exactMatch(ui->lePhone->text()))
     {
         //ui->lePhone->setFocus(Qt::OtherFocusReason);
         //bool f = ui->lePhone->hasFocus();
         //f = false;
     }
     else*/
   // ui->buttonBox->Ignore;
        // ui->buttonBox->Abort;
}

