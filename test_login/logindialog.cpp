#include "logindialog.h"
#include "ui_logindialog.h"
#include "qmessagebox.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    ui->edtPassword->setEchoMode(QLineEdit::Password);
    // 设置信号函数与槽函数之间的联系
    connect(this, &LoginDialog::login, this, &LoginDialog::loginSlot);
    //    connect(this, &LoginDialog::cancel, this, &LoginDialog::cancelSlot);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnLogin_clicked()
{
    QString username = ui->edtUsername->text();
    QString password = ui->edtPassword->text();
    emit login(username, password);
}

void LoginDialog::loginSlot(QString username, QString password)
{
    // 非空校验
    if (username.trimmed().length() == 0) {
        QMessageBox::information(this, "提示", "用户名不能为空！");
        ui->edtUsername->setFocus();
        return;
    }
    if (password.trimmed().length() == 0) {
        QMessageBox::information(this, "提示", "密码不能为空！");
        ui->edtPassword->setFocus();
        return;
    }
    // 用户合法性判断
    if (username == "123" && password == "123") {
        QMessageBox::information(this, "提示", "恭喜，登录成功！");
        parentWidget()->show();
        this->hide();
    } else {
        QMessageBox::information(this, "提示", "遗憾，登录失败！");
    }

}
