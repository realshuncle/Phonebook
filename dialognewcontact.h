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
    //QString getTextboxText();
    ~DialogNewContact();

private slots:
    void closeEvent(QCloseEvent *event);
    //new
    void onButtonOkPressed();
    //void onTextBoxReturnPressed();
    void on_btOk_clicked();

    void on_btCancel_clicked();

private:
    Ui::DialogNewContact *ui;

signals:
    //new
    void newContactEntered(const std::vector<std::string> &con);
    //void newContactEntered(const QString &con);
    //void newTextEntered(const QString &text);
};

#endif // DIALOGNEWCONTACT_H
