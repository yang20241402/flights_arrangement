#ifndef PROFILEEDITWIDGET_H
#define PROFILEEDITWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QRegularExpression>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError> // 确保包含QSqlError头文件

#include "ui_profileeditwidget.h"

namespace Ui {
class ProfileEditWidget;
}

class ProfileEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileEditWidget(int userId, QWidget *parent = nullptr);
    ~ProfileEditWidget();

private slots:
    void on_btnSave_clicked();    // 保存修改
    void on_btnCancel_clicked();  // 取消操作

private:
    Ui::ProfileEditWidget *ui;
    int m_userId;                // 当前登录用户ID
    QSqlDatabase m_db;           // 数据库连接

    void initDatabase();         // 初始化数据库连接（复用消息功能配置）
    void initLayout();           // 布局调整
    void loadUserProfile();      // 加载用户资料（HEX解码方案）
    bool validateForm();         // 表单验证
    bool updateUserProfile();    // 更新资料（UNHEX保存方案）
signals:
    void profileUpdated();
};

#endif // PROFILEEDITWIDGET_H
