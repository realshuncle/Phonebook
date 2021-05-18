#ifndef DIALOGSAVE_H
#define DIALOGSAVE_H

#include <QDialog>

namespace Ui {
class DialogSave;
}

class DialogSave : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSave(QWidget *parent = nullptr);
    ~DialogSave();

private slots:

    void on_btYes_clicked();

    void on_btNo_clicked();

    void onButtonPressed(bool flag);

private:
    Ui::DialogSave *ui;

signals:
    void buttonPressed(bool flag);
};

#endif // DIALOGSAVE_H
