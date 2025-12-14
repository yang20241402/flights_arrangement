#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

// 自定义可点击 Label，添加 clicked 信号
class ClickableLabel : public QLabel
{
    Q_OBJECT // 必须有这个宏，才能支持信号槽

public:
    // 构造函数（和普通 QLabel 用法一样）
    explicit ClickableLabel(QWidget *parent = nullptr) : QLabel(parent) {}
    ~ClickableLabel() = default;

signals:
    // 自定义 clicked 信号（关键！设计器会识别这个信号）
    void clicked();

protected:
    // 重写鼠标左键点击事件，触发 clicked 信号
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) { // 只响应左键点击
            emit clicked(); // 触发信号
        }
        QLabel::mousePressEvent(event); // 保留 Label 原有功能（比如显示文字）
    }
};

#endif // CLICKABLELABEL_H
