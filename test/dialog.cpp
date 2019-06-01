#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "qmessagebox.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(this, &Dialog::login, this, &Dialog::loginSlot);
//    connect(this, &Dialog::cancel, this, &Dialog::cancelSlot);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loginSlot(QString username, QString password)
{
    //主窗口
    MainWindow m;
    m.setWindowTitle("main window");


    // 非空校验
    if (username.trimmed().length() == 0) {
        QMessageBox::information(this, "提示", "用户名不能为空！");
        ui->lineEdit->setFocus();
        return;
    }
    if (password.trimmed().length() == 0) {
        QMessageBox::information(this, "提示", "密码不能为空！");
        ui->lineEdit_2->setFocus();
        return;
    }
    // 用户合法性判断
    if (username == "test" && password == "test") {
        QMessageBox::information(this, "提示", "恭喜，登录成功！");
        m.show();

        this->hide();
    } else {
        QMessageBox::information(this, "提示", "遗憾，登录失败！");
    }

}

