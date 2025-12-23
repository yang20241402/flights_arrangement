#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ViewManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onViewChanged(int from, int to);
    void onUserLoggedIn(int userId);

private:
    void setupUI();
    void setupMenuBar();

private:
    Ui::MainWindow *ui;
    QStackedWidget *m_stackedWidget;
    ViewManager *m_viewManager;
};

#endif // MAINWINDOW_H