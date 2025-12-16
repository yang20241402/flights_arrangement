  #ifndef PERSONCENTERWINDOW_H
#define PERSONCENTERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
class PassengerDialog;
QT_BEGIN_NAMESPACE
namespace Ui { class PersonCenterWindow; }
QT_END_NAMESPACE

class PersonCenterWindow : public QMainWindow
{
    Q_OBJECT

public:
    PersonCenterWindow(QWidget *parent = nullptr);
    ~PersonCenterWindow();
    int m_currentUserId;
    void loadUserInfo();

private slots:

    void on_myOrderBtn_clicked();
    void on_commonInfoBtn_clicked();
    void on_myPointsBtn_clicked();
    void on_myMsgBtn_clicked();
    void on_editBtn_clicked();
private:
    Ui::PersonCenterWindow *ui;
};
#endif
