#ifndef DIALOGNEWCONTACT_H
#define DIALOGNEWCONTACT_H

#include <QDialog>
#include <QCloseEvent>
#include <QRegularExpression>

namespace Ui {
class DialogNewContact;
}

class DialogNewContact : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewContact(QWidget *parent = nullptr);

    ~DialogNewContact();

private slots:
    void closeEvent(QCloseEvent *event);
    void onButtonOkPressed();
    void on_btOk_clicked();
    void on_btCancel_clicked();

private:
    Ui::DialogNewContact *ui;

signals:
    void newContactEntered(const std::vector<std::string> &con);

};

#endif // DIALOGNEWCONTACT_H
