#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

signals:
    void login(QString username, QString password);
//    void cancel();

private slots:
    void on_btnLogin_clicked();
//    void on_btnCancel_clicked();
    void loginSlot(QString username, QString password);
//    void cancelSlot();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
