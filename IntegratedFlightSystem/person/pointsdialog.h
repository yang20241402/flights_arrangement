#ifndef POINTSDIALOG_H
#define POINTSDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringLiteral>

namespace Ui {
class PointsDialog;
}

class PointsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PointsDialog(int userId, QWidget *parent = nullptr);
    ~PointsDialog();

private slots:
    void on_refreshBtn_clicked();

private:
    Ui::PointsDialog *ui;
    int m_userId;
    QSqlDatabase m_db;

    void initDatabase();
    void loadPointsData();
    int calculateTotalPoints();
    void setupLayout();
    void initTableConfig();
};

#endif
