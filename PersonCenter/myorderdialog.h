#ifndef MYORDERDIALOG_H
#define MYORDERDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class MyOrderDialog;
}

class MyOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyOrderDialog(int userId, QWidget *parent = nullptr);
    ~MyOrderDialog();

private slots:
    void on_allOrderBtn_clicked();
    void onPayOrderClicked();
    void on_upcomingOrderBtn_clicked();
    void on_finishedOrderBtn_clicked();
    void on_cancelledOrderBtn_clicked();
    void onCancelOrderClicked();
    void on_unpaidOrderBtn_clicked();
    void onChangeOrderClicked();
private:
    Ui::MyOrderDialog *ui;
    int m_userId;
    void loadOrderData(const QString &status = "全部订单");
    void updateBtnStyle(QPushButton *selectedBtn);
    void initLayout();
};

#endif
