#ifndef PASSENGERDIALOG_H
#define PASSENGERDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringLiteral>
#include <QTableWidget>
#include <QPushButton>
#include <QMap>
#include <QList>

struct PassengerInfo {
    QString name;
    QString idCard;
    QString phone;
    bool isValid = false;

    bool isEmpty() const { return name.isEmpty() && idCard.isEmpty() && phone.isEmpty(); }
    QString toString() const { return QString("%1 (%2) - %3").arg(name).arg(idCard).arg(phone); }
};

namespace Ui {
class PassengerDialog;
}

class PassengerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PassengerDialog(int userId, QWidget *parent = nullptr);
    explicit PassengerDialog(int userId, bool isBuyTicketMode, QWidget *parent = nullptr);
    ~PassengerDialog();

    void setMode(bool isBuyTicketMode);
    PassengerInfo getSelectedPassenger() const;
    QList<PassengerInfo> getAllSelectedPassengers() const;
    void setDatabaseConnection(const QString &connectionName);
    void refreshData();
    bool isBuyTicketMode() const { return m_isBuyTicketMode; }

    static QList<PassengerInfo> getAllPassengers(int userId, const QString &connectionName = QString());
    static bool addPassenger(int userId, const PassengerInfo &info, const QString &connectionName = QString());
    static bool deletePassenger(int userId, const QString &idCard, const QString &connectionName = QString());
    static PassengerInfo selectPassenger(int userId, QWidget *parent = nullptr);

signals:
    void passengerSelected(const PassengerInfo &info);
    void dataChanged();
    void paymentCompleted(const PassengerInfo &info);

private slots:
    void on_addBtn_clicked();
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_selectBtn_clicked();

private:
    void initialize();
    void loadPassengerData();
    void setupLayout();
    QPushButton* createSelectButton(int row);
    bool openDatabase();
    void closeDatabase();
    PassengerInfo getPassengerAtRow(int row) const;
    void updateButtonStyle();

private:
    Ui::PassengerDialog *ui;
    int m_userId;
    bool m_isBuyTicketMode;
    QString m_connectionName;
    mutable QSqlDatabase m_db;
    QMap<int, QPushButton*> m_rowSelectBtnMap;
    QMap<int, bool> m_rowSelectedMap;

    PassengerDialog(const PassengerDialog &) = delete;
    PassengerDialog &operator=(const PassengerDialog &) = delete;
};

#endif
