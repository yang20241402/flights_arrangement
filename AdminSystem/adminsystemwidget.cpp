#include "adminsystemwidget.h"
#include "ui_adminsystemwidget.h"

#include <QSqlError>
#include <QDebug>

AdminSystemWidget::AdminSystemWidget(const QString &adminName, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminSystemWidget)
{
    ui->setupUi(this);

    ui->adminLabel->setText(QString("当前管理员：%1").arg(adminName));

    initDatabase();
    initModels();

    connect(ui->userTableView, &QTableView::clicked,
            this, [=](const QModelIndex &index){
                int userId = userModel->data(userModel->index(index.row(), 0)).toInt();
                loadOrdersByUserId(userId);
            });
}

AdminSystemWidget::~AdminSystemWidget()
{
    delete ui;
}

void AdminSystemWidget::initDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("flight_management_system");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
}

void AdminSystemWidget::initModels()
{
    userModel = new QSqlQueryModel(this);
    userModel->setQuery(
        "SELECT id, username, nickname, phone, email FROM user", db);
    ui->userTableView->setModel(userModel);

    orderModel = new QSqlQueryModel(this);
    ui->orderTableView->setModel(orderModel);
}

void AdminSystemWidget::loadOrdersByUserId(int userId)
{
    orderModel->setQuery(
        QString("SELECT * FROM orders WHERE user_id = %1").arg(userId),
        db
        );
}
