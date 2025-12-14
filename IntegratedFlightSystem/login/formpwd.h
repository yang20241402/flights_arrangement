#ifndef FORMPWD_H
#define FORMPWD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QSqlError>
#include <QTimer>
#include <QRegularExpression>    // 替代 QRegExp
#include <QRegularExpressionValidator>
#include <QDateTime>
#include <QtGlobal>

namespace Ui {
class Formpwd;
}

class Formpwd : public QWidget
{
    Q_OBJECT

public:
    explicit Formpwd(QWidget *parent = nullptr);
    ~Formpwd();

private slots:
    void on_pushButton_2_clicked();

    void on_getcodeLabel1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_backLabel_clicked();

    void on_backLabel_2_clicked();

    void on_backLabel_3_clicked();

private:
    Ui::Formpwd *ui;
    QSqlDatabase db;
    QString g_verifyCode;
    QTimer *g_countdownTimer;

    QString generateVerifyCode();
    QString m_verifyCode;
};

#endif // FORMPWD_H
