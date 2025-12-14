#include "personcenterwindow.h"
#include "ui_personcenterwindow.h"
#include "myorderdialog.h"  // 包含订单窗口头文件
#include "passengerdialog.h"
#include "pointsdialog.h"
PersonCenterWindow::PersonCenterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PersonCenterWindow)
{
    ui->setupUi(this);
}

PersonCenterWindow::~PersonCenterWindow()
{
    delete ui;
}

void PersonCenterWindow::on_myOrderBtn_clicked()
{
    MyOrderDialog dialog(1, this);
    dialog.exec();
}

void PersonCenterWindow::on_commonInfoBtn_clicked()
{
    int currentUserId = 1;
    PassengerDialog dialog(currentUserId, this);
    dialog.exec();
}

void PersonCenterWindow::on_myPointsBtn_clicked()
{
    int currentUserId = 1;
    PointsDialog dialog(currentUserId, this);
    dialog.exec();
}
