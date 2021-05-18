#include "dialognewcontact.h"
#include "ui_dialognewcontact.h"

DialogNewContact::DialogNewContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewContact)
{
    QDialog::setModal(true);
    ui->setupUi(this);
   /* connect(ui->btOk, SIGNAL(clicked),
                this, SIGNAL(onButtonOkPressed()));*/
}

void DialogNewContact::onButtonOkPressed()
{
    // Emitting a signal with the new text
    std::vector<std::string> temp;
    temp.push_back(ui->leName->text().toStdString());
    temp.push_back(ui->lePhone->text().toStdString());
    temp.push_back(ui->teInformation->toPlainText().toStdString());
    emit this->newContactEntered(temp);
    //emit this->newContactEntered("temp");
}

DialogNewContact::~DialogNewContact()
{
    delete ui;
}

void DialogNewContact::closeEvent(QCloseEvent *event)
{
    ui->leName->setText("");
    ui->lePhone->setText("");
    ui->teInformation->setText("");
    event->accept();
    /*QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.exactMatch(ui->lePhone->text())) {
        event->accept();
    } else {
        event->ignore();
    }*/
}
/*QString DialogNewContact::getTextboxText(){
    return ui->lePhone->text();
}*/

void DialogNewContact::on_btOk_clicked()
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.exactMatch(ui->lePhone->text())) {
        onButtonOkPressed();
        ui->leName->setText("");
        ui->lePhone->setText("");
        ui->teInformation->setText("");
        this->close();
        //this->destroy();
    }
    else {
        ui->lePhone->setStyleSheet("QLineEdit { background: rgb(255, 20, 20); selection-background-color: rgb(233, 99, 0); }");
    }
}


void DialogNewContact::on_btCancel_clicked()
{
    ui->leName->setText("");
    ui->lePhone->setText("");
    ui->teInformation->setText("");
    this->close();
    //this->destroy();
}
