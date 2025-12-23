#ifndef ADMINPANEL_H
#define ADMINPANEL_H

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
#include "databasemanager.h"

class AdminPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

signals:
    void switchToFlightManagement();

private slots:
    void onRefreshClicked();
    void onAddUserClicked();
    void onEditUserClicked();
    void onDeleteUserClicked();
    void onSearchClicked();
    void onTableCellDoubleClicked(int row, int column);

private:
    QTableWidget *m_tableWidget;
    QLineEdit *m_searchEdit;
    QPushButton *m_refreshBtn;
    QPushButton *m_addBtn;
    QPushButton *m_editBtn;
    QPushButton *m_deleteBtn;
    QPushButton *m_searchBtn;

    void setupUI();
    void loadUserData(const QString& searchText = "");
    void showEditDialog(int userId = -1);
};

#endif // ADMINPANEL_H
