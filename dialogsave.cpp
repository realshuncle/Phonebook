#include "dialogsave.h"
#include "ui_dialogsave.h"

DialogSave::DialogSave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSave)
{
    QDialog::setModal(true);
    ui->setupUi(this);
}

DialogSave::~DialogSave()
{
    delete ui;
}


void DialogSave::on_btYes_clicked()
{
    this->close();
    onButtonPressed(true);
}


void DialogSave::on_btNo_clicked()
{
    this->close();
    onButtonPressed(false);
}

void DialogSave::onButtonPressed(bool flag)
{
    emit this->buttonPressed(flag);
}
