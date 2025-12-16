#ifndef WIDGET_H
#define WIDGET_H

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


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_switchLabel_clicked();


    void on_pushButton_2_clicked();


    void on_getCode_clicked();

    void on_registerLabel_clicked();

    void on_label_9_clicked();

    void on_label_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QString g_verifyCode;
    QTimer *g_countdownTimer;

    QString generateVerifyCode();
    QString m_verifyCode;
};
#endif // WIDGET_H
