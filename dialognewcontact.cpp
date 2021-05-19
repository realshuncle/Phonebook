#include "dialognewcontact.h"
#include "ui_dialognewcontact.h"

DialogNewContact::DialogNewContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewContact)
{
    QDialog::setModal(true);
    ui->setupUi(this);
    setWindowTitle("Телефонный справочник");
}

void DialogNewContact::onButtonOkPressed()
{
    std::vector<std::string> temp;
    temp.push_back(ui->leName->text().toStdString());
    temp.push_back(ui->lePhone->text().toStdString());
    temp.push_back(ui->teInformation->toPlainText().toStdString());
    emit this->newContactEntered(temp);
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
    ui->lePhone->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); selection-background-color: rgb(233, 99, 0); }");
    event->accept();
}

void DialogNewContact::on_btOk_clicked()
{
    QRegExp rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.exactMatch(ui->lePhone->text())) {
        onButtonOkPressed();
        ui->leName->setText("");
        ui->lePhone->setText("");
        ui->teInformation->setText("");
        this->close();
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
}

