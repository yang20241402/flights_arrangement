#ifndef PERSONCENTERWINDOW_H
#define PERSONCENTERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
class PassengerDialog;
namespace Ui {
class PersonCenterWindow;
}

class PersonCenterWindow : public QMainWindow
{
    Q_OBJECT

public:
    PersonCenterWindow(QWidget *parent = nullptr);
    ~PersonCenterWindow();

private slots:

    void on_myOrderBtn_clicked();
    void on_commonInfoBtn_clicked();
    void on_myPointsBtn_clicked();
private:
    Ui::PersonCenterWindow *ui;
    int m_currentUserId=1;
};
#endif
