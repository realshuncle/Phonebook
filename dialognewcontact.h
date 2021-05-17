#ifndef DIALOGNEWCONTACT_H
#define DIALOGNEWCONTACT_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class DialogNewContact;
}

class DialogNewContact : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewContact(QWidget *parent = nullptr);
    QString getTextboxText();
    ~DialogNewContact();

private slots:
   // void closeEvent(QCloseEvent *event, bool flag);

    void on_btOk_clicked();

private:
    Ui::DialogNewContact *ui;


};

#endif // DIALOGNEWCONTACT_H
