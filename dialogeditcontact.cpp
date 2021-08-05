#include "dialogeditcontact.h"
#include "ui_dialogeditcontact.h"

DialogEditContact::DialogEditContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditContact)
{
    QDialog::setModal(true);
    ui->setupUi(this);
    setWindowTitle("Телефонный справочник");
}

void DialogEditContact::onButtonOkPressed()
{
    std::vector<std::string> temp;
    temp.push_back(ui->leName->text().toStdString());
    temp.push_back(ui->lePhone->text().toStdString());
    temp.push_back(ui->teInformation->toPlainText().toStdString());
    temp.push_back(Id);
    emit this->editContactEntered(temp);
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
    ui->lePhone->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); selection-background-color: rgb(233, 99, 0); }");
    event->accept();
}

void DialogEditContact::on_btOk_clicked()
{
    QRegularExpression rx("\\d\\s\\(\\d\\d\\d\\)\\s\\d\\d\\d-\\d\\d-\\d\\d");
    if (rx.match(ui->lePhone->text()).hasMatch()) {
        onButtonOkPressed();
        this->close();
    }
    else {
        ui->lePhone->setStyleSheet("QLineEdit { background: rgb(255, 20, 20); selection-background-color: rgb(233, 99, 0); }");
    }
}


void DialogEditContact::on_btCancel_clicked()
{
    this->close();
}

void DialogEditContact::SetDate(std::vector<std::string> date)
{
    ui->leName->setText(QString::fromStdString(date[0]));
    ui->lePhone->setText(QString::fromStdString(date[1]));
    ui->teInformation->setText(QString::fromStdString(date[2]));
    this->Id = date[3];
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
