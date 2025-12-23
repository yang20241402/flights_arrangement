#ifndef ADMINSYSTEMWIDGET_H
#define ADMINSYSTEMWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class AdminSystemWidget; }
QT_END_NAMESPACE

class AdminSystemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminSystemWidget(const QString &adminName,
                               QWidget *parent = nullptr);
    ~AdminSystemWidget();

private:
    void initDatabase();
    void initModels();
    void loadOrdersByUserId(int userId);

private:
    Ui::AdminSystemWidget *ui;
    QSqlDatabase db;
    QSqlQueryModel *userModel;
    QSqlQueryModel *orderModel;
};

#endif
