#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status=new QStatusBar(this);
    this->centralWidget();

    menu[0]=new QMenu('file');



}

MainWindow::~MainWindow()
{
    delete ui;
}
