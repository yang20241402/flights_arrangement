#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QSqlDatabase>
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

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_getcodeLabel1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_backLabel_clicked();

    void on_backLabel_2_clicked();

    void on_label_4_clicked();

    void on_label_6_clicked();

private:
    Ui::Form *ui;
    QString g_verifyCode;
    QTimer *g_countdownTimer;

    QString generateVerifyCode();
    QString m_verifyCode;
    QSqlDatabase db;
};

#endif // FORM_H
