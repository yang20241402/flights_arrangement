#ifndef PASSWORDRESETWIDGET_H
#define PASSWORDRESETWIDGET_H

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

QT_BEGIN_NAMESPACE
namespace Ui {
class PasswordResetWidget;
}
QT_END_NAMESPACE

class PasswordResetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordResetWidget(QWidget *parent = nullptr);
    ~PasswordResetWidget();

signals:
    void passwordResetCompleted();
    void backToLoginRequested();

private slots:
    void on_pushButton_2_clicked();
    void on_getcodeLabel1_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_backLabel_clicked();
    void on_backLabel_2_clicked();
    void on_backLabel_3_clicked();

private:
    Ui::PasswordResetWidget *ui;
    QString g_verifyCode;
    QTimer *g_countdownTimer;

    QString generateVerifyCode();
    QString m_verifyCode;
};

#endif // PASSWORDRESETWIDGET_H