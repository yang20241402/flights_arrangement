#ifndef PERSONCENTERWINDOW_H
#define PERSONCENTERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
class PassengerDialog;
namespace Ui { 
class PersonCenterWindow; 
}
QT_END_NAMESPACE

class PersonCenterWindow : public QMainWindow
{
    Q_OBJECT

public:
    PersonCenterWindow(QWidget *parent = nullptr);
    ~PersonCenterWindow();
    
    // 用户ID管理
    void setUserId(int userId);
    int getUserId() const;
    
    // 加载用户信息
    void loadUserInfo();

private slots:
    void on_myOrderBtn_clicked();
    void on_commonInfoBtn_clicked();
    void on_myPointsBtn_clicked();
    void on_myMsgBtn_clicked();
    void on_editBtn_clicked();
    
    // 简单的跳转方法
    void showMyOrders();
    void showPassengerInfo();
    void showMyPoints();
    void showMyMessages();
    void showProfileEdit();

private:
    Ui::PersonCenterWindow *ui;
    int m_currentUserId;
};

#endif // PERSONCENTERWINDOW_H