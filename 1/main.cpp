#include "widget.h"

#include <QApplication>
#include <QStyleFactory>
#include <QPalette>
#include <QColor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStyle *lightStyle = QStyleFactory::create("Fusion");  // 推荐！跨平台浅色样式
    // Windows 平台可选：QStyleFactory::create("Windows") （系统原生浅色）
    // macOS 平台可选：QStyleFactory::create("Macintosh") （系统原生浅色）
    // Linux 平台可选：QStyleFactory::create("gtk2") （适配系统 GTK 浅色主题）

    if (lightStyle) {  // 确保样式创建成功
        a.setStyle(lightStyle);
    }

    // 第二步：用调色板固化浅色配色（防止系统深色模式覆盖）
    QPalette lightPalette;
    // 窗口背景：纯白
    lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));
    // 窗口文字：纯黑（确保可读性）
    lightPalette.setColor(QPalette::WindowText, QColor(30, 30, 30));
    // 按钮背景：浅灰（hover 时会自动加深，符合浅色逻辑）
    lightPalette.setColor(QPalette::Button, QColor(245, 245, 245));
    // 按钮文字：纯黑
    lightPalette.setColor(QPalette::ButtonText, QColor(30, 30, 30));
    // 输入框背景：纯白
    lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));
    // 输入框文字：纯黑
    lightPalette.setColor(QPalette::Text, QColor(30, 30, 30));
    // 提示语（placeholder）：浅灰
    lightPalette.setColor(QPalette::PlaceholderText, QColor(150, 150, 150));
    // 选中状态背景：淡蓝（贴合之前的携程风格）
    lightPalette.setColor(QPalette::Highlight, QColor(0, 120, 255));
    // 选中状态文字：纯白
    lightPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));

    // 应用调色板到整个应用
    a.setPalette(lightPalette);
    Widget w;
    w.show();
    return a.exec();
}


