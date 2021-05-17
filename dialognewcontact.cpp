#include "dialognewcontact.h"
#include "ui_dialognewcontact.h"

DialogNewContact::DialogNewContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewContact)
{
    ui->setupUi(this);
}

DialogNewContact::~DialogNewContact()
{
    delete ui;
}

/*void DialogNewContact::closeEvent(QCloseEvent *event, bool flag)
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.exactMatch(ui->lePhone->text())) {
        event->accept();
    } else {
        event->ignore();
    }
}*/
QString DialogNewContact::getTextboxText(){
    return ui->lePhone->text();
}

void DialogNewContact::on_btOk_clicked()
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.exactMatch(ui->lePhone->text())) {

        this->close();
    }
    else {
        ui->lePhone->setStyleSheet("QLineEdit { background: rgb(255, 20, 20); selection-background-color: rgb(233, 99, 0); }");
    }
}

