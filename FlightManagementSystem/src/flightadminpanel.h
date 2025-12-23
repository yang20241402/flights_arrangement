#ifndef FLIGHTADMINPANEL_H
#define FLIGHTADMINPANEL_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QHeaderView>
#include <QDialog>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include "databasemanager.h"

class FlightAdminPanel : public QWidget
{
    Q_OBJECT

public:
    explicit FlightAdminPanel(QWidget *parent = nullptr);
    ~FlightAdminPanel();

signals:
    void switchToUserManagement();

private slots:
    void onSearchClicked();
    void onRefreshClicked();
    void onAddFlightClicked();
    void onEditFlightClicked();
    void onDeleteFlightClicked();
    void onTableCellDoubleClicked(int row, int column);

private:
    // UI 组件
    QTableWidget *m_tableWidget;
    QLineEdit *m_departCityEdit;
    QLineEdit *m_arriveCityEdit;
    QPushButton *m_searchBtn;
    QPushButton *m_refreshBtn;
    QPushButton *m_addBtn;
    QPushButton *m_editBtn;
    QPushButton *m_deleteBtn;

    // 私有方法
    void setupUI();
    void loadFlightData(const QString& departCity = "", const QString& arriveCity = "");
};

#endif // FLIGHTADMINPANEL_H
