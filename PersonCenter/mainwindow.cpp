#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myorderdialog.h"  // 包含订单窗口头文件
#include "passengerdialog.h"
#include "pointsdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_myOrderBtn_clicked()
{
    MyOrderDialog dialog(1, this);
    dialog.exec();
}

void MainWindow::on_commonInfoBtn_clicked()
{
    int currentUserId = 1;
    PassengerDialog dialog(currentUserId, this);
    dialog.exec();
}

void MainWindow::on_myPointsBtn_clicked()
{
    int currentUserId = 1;
    PointsDialog dialog(currentUserId, this);
    dialog.exec();
}
