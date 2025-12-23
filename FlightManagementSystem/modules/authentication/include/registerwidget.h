#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

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
class RegisterWidget;
}
QT_END_NAMESPACE

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

signals:
    void registrationCompleted();
    void backToLoginRequested();

private slots:
    void on_getcodeLabel1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_backLabel_clicked();
    void on_backLabel_2_clicked();
    void on_label_4_clicked();
    void on_label_6_clicked();

private:
    Ui::RegisterWidget *ui;
    QString g_verifyCode;
    QTimer *g_countdownTimer;

    QString generateVerifyCode();
    QString m_verifyCode;
    QDateTime m_verifyCodeTime; // 记录验证码生成时间
};

#endif // REGISTERWIDGET_H