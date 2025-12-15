#include "login/widget.h"
#include "databasemanager.h"
#include <QApplication>
#include <QStyleFactory>
#include <QPalette>
#include <QColor>
#include <QMessageBox>
#include<QDebug>
#include<QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();
    // 初始化数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    if (!dbManager->initializeAllDatabases()) {
        QMessageBox::critical(nullptr, "数据库错误", 
            "数据库连接失败，请检查MySQL服务是否启动以及配置是否正确。\n错误信息: " + 
            dbManager->getLastError());
        return -1;
    }
    
    // 设置浅色主题样式
    QStyle *lightStyle = QStyleFactory::create("Fusion");
    if (lightStyle) {
        a.setStyle(lightStyle);
    }

    // 设置调色板
    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::WindowText, QColor(30, 30, 30));
    lightPalette.setColor(QPalette::Button, QColor(245, 245, 245));
    lightPalette.setColor(QPalette::ButtonText, QColor(30, 30, 30));
    lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::Text, QColor(30, 30, 30));
    lightPalette.setColor(QPalette::PlaceholderText, QColor(150, 150, 150));
    lightPalette.setColor(QPalette::Highlight, QColor(0, 120, 255));
    lightPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
    a.setPalette(lightPalette);

    // 启动登录界面
    Widget w;
    w.show();
    return a.exec();
}
