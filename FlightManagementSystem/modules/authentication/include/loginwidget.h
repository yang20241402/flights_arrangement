#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QSqlError>
#include <QTimer>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDateTime>
#include <QtGlobal>
#include <QDialog>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWidget;
}
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

signals:
    void loginSuccessful(int userId);  // 传递用户ID
    void adminLoginSuccessful();
    void registerRequested();
    void passwordResetRequested();

private slots:
    void on_pushButton_clicked();
    void on_switchLabel_clicked();
    void on_pushButton_2_clicked();
    void on_getCode_clicked();
    void on_registerLabel_clicked();
    void on_label_9_clicked();
    void on_label_2_clicked();
    void on_label_4_clicked();
    void on_label_6_clicked();
    void on_adminLoginBtn_clicked();  // 管理员登录按钮

private:
    Ui::LoginWidget *ui;
    QString g_verifyCode;
    QTimer *g_countdownTimer;

    QString generateVerifyCode();
    QString m_verifyCode;
};

#endif // LOGINWIDGET_H