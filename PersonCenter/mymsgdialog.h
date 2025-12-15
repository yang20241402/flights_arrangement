#ifndef MYMSGDALOG_H
#define MYMSGDALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QPushButton>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>

// 文本省略号委托
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


#include "ui_mymsgdialog.h"

namespace Ui {
class mymsgdialog;
}

class mymsgdialog : public QDialog
{
    Q_OBJECT

public:
    explicit mymsgdialog(int userId, QWidget *parent = nullptr);
    ~mymsgdialog();

private slots:
    void on_allMsgBtn_clicked();
    void on_unreadMsgBtn_clicked();
    void on_markReadBtn_clicked();
    void on_deleteBtn_clicked();
    void onMsgCellDoubleClicked(int row, int column);

private:
    Ui::mymsgdialog *ui;
    int m_userId;
    QSqlDatabase m_db;

    void initDatabase();
    void initTableConfig();
    void updateBtnStyle(QPushButton *selectedBtn);
    void loadMsgData(const QString &status);
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MYMSGDALOG_H
