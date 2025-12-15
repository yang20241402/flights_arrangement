#ifndef COUPONWIDGET_H
#define COUPONWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QPushButton>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>

// 文本省略号委托（复用消息模块的逻辑）
class EllipsisDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit EllipsisDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);
        opt.text = opt.fontMetrics.elidedText(opt.text, Qt::ElideRight, opt.rect.width() - 10);
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

#include "ui_couponwidget.h"

namespace Ui {
class CouponWidget;
}

class CouponWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CouponWidget(int userId, QWidget *parent = nullptr);
    ~CouponWidget();

private slots:
    void on_allCouponBtn_clicked();      // 全部优惠券
    void on_unusedCouponBtn_clicked();   // 未使用优惠券
    void on_usedCouponBtn_clicked();     // 已使用优惠券
    void on_expiredCouponBtn_clicked();  // 已过期优惠券
    void on_useCouponBtn_clicked();      // 使用优惠券
    void on_deleteCouponBtn_clicked();   // 删除优惠券
    void onCouponCellDoubleClicked(int row, int column); // 双击查看详情

private:
    Ui::CouponWidget *ui;
    int m_userId;                        // 当前用户ID
    QSqlDatabase m_db;                   // 数据库连接

    void initDatabase();                 // 初始化数据库（创建优惠券表）
    void initTableConfig();              // 初始化表格（布满页面、同宽）
    void updateBtnStyle(QPushButton *selectedBtn); // 按钮样式切换
    void loadCouponData(const QString &status);    // 加载优惠券数据
    void resizeEvent(QResizeEvent *event) override; // 窗口缩放适配
};

#endif // COUPONWIDGET_H
