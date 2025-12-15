#ifndef PASSENGERDIALOG_H
#define PASSENGERDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringLiteral>

namespace Ui {
class PassengerDialog;
}

class PassengerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PassengerDialog(int userId, QWidget *parent = nullptr);
    ~PassengerDialog();

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();

private:
    Ui::PassengerDialog *ui;
    int m_userId;

    void loadPassengerData();
    void setupLayout();
};

#endif
