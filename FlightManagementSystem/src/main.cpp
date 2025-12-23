#include "mainwindow.h"
#include "constants.h"
#include "databasemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    DatabaseManager::instance()->initializeWithDefaults();
    // 设置应用程序信息
    app.setApplicationName(Constants::APP_NAME);
    app.setApplicationVersion(Constants::APP_VERSION);
    
    // 创建主窗口
    MainWindow window;
    window.show();
    
    return app.exec();
}
