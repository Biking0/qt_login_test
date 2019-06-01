#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
    void login(QString username, QString password);
    void cancel();


private slots:
    void on_btnLogin_clicked();
//    void on_btnCancel_clicked();
    void loginSlot(QString username, QString password);
//    void cancelSlot();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
