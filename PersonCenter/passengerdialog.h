#ifndef PASSENGERDIALOG_H
#define PASSENGERDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringLiteral>
#include <QTableWidget>
#include <QPushButton>
#include <QMap>

struct PassengerInfo{
    QString name;
    QString idCard;
    QString phone;
    bool isValid = false;
};

namespace Ui {
class PassengerDialog;
}

class PassengerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PassengerDialog(int userId, QWidget *parent = nullptr);
    ~PassengerDialog();
    void setBuyTicketMode(bool isBuyMode);
    PassengerInfo getSelectedPassenger(int row = -1);

signals:
    void passengerSelected(const PassengerInfo &info);

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_selectBtn_clicked();

private:
    Ui::PassengerDialog *ui;
    int m_userId;
    QSqlDatabase m_db;
    bool m_isBuyTicketMode = false;
    QMap<int, QPushButton*> m_rowSelectBtnMap;
    QMap<int, bool> m_rowSelectedMap;

    void loadPassengerData();
    void initDatabase();
    void setupLayout();
    QPushButton* createSelectButton(int row);
};

#endif
