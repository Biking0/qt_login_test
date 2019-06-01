#include "dialog.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //登陆窗口
    Dialog w;
    w.setWindowTitle("welcome");
    w.show();


    return a.exec();
}
