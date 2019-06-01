#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("welcome");
//    w.setWindowIcon('./new');


    LoginDialog login(&w);
    login.setWindowTitle("登录");
    login.show();
//    login.move((desktop->width() - login.width())/ 2, (desktop->height() - login.height()) /2);

    return a.exec();
}
