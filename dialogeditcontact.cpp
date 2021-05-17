#include "dialogeditcontact.h"
#include "ui_dialogeditcontact.h"

DialogEditContact::DialogEditContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditContact)
{
    QDialog::setModal(true);
    ui->setupUi(this);
   /* connect(ui->btOk, SIGNAL(clicked),
                this, SIGNAL(onButtonOkPressed()));*/
}

void DialogEditContact::onButtonOkPressed()
{
    // Emitting a signal with the new text
    std::vector<std::string> temp;
    temp.push_back(ui->leName->text().toStdString());
    temp.push_back(ui->lePhone->text().toStdString());
    temp.push_back(ui->teInformation->toPlainText().toStdString());
    temp.push_back(Id);
    emit this->editContactEntered(temp);
    //emit this->newContactEntered("temp");
}

DialogEditContact::~DialogEditContact()
{
    delete ui;
}

void DialogEditContact::closeEvent(QCloseEvent *event)
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

void DialogEditContact::on_btOk_clicked()
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.exactMatch(ui->lePhone->text())) {
        onButtonOkPressed();
        //ui->leName->setText("");
        //ui->lePhone->setText("");
        //ui->teInformation->setText("");
        this->close();
        //this->destroy();
    }
    else {
        ui->lePhone->setStyleSheet("QLineEdit { background: rgb(255, 20, 20); selection-background-color: rgb(233, 99, 0); }");
    }
}


void DialogEditContact::on_btCancel_clicked()
{
    //ui->leName->setText("");
    //ui->lePhone->setText("");
    //ui->teInformation->setText("");
    this->close();
    //this->destroy();
}

void DialogEditContact::SetDate(std::vector<std::string> date)
{
    ui->leName->setText(QString::fromStdString(date[0]));
    ui->lePhone->setText(QString::fromStdString(date[1]));
    ui->teInformation->setText(QString::fromStdString(date[2]));
    this->Id = date[3];// stoi(date[3]);
}

void DialogEditContact::on_btDelete_clicked()
{
    onButtonDeletePressed();
    this->close();
}
void DialogEditContact::onButtonDeletePressed()
{
    emit this->deleteContactEntered(stoi(this->Id));
}
