#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    ui->widget->setStyleSheet(R"(
    QWidget {
        border: 1px solid #cccccc;
        border-radius: 4px;
    }
    )");


}

MainWindow::~MainWindow()
{
    delete ui;
}
