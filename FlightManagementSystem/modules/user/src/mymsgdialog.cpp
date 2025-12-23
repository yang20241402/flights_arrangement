#include "mymsgdialog.h"
#include "ui_mymsgdialog.h"
#include "databasemanager.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QResizeEvent>

mymsgdialog::mymsgdialog(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mymsgdialog),
    m_userId(userId)
{
    ui->setupUi(this);
    setWindowTitle("我的消息");
    resize(800, 550);
    setMinimumSize(600, 400);

    QLayout *oldLayout = this->layout();
    if (oldLayout) {
        oldLayout->deleteLater();
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0); // 窗口无留白
    mainLayout->setSpacing(5);

    QWidget *filterBar = new QWidget();
    QHBoxLayout *filterLayout = new QHBoxLayout(filterBar);
    filterLayout->setContentsMargins(10, 5, 10, 5); // 少量内边距
    filterLayout->setSpacing(10);
    filterLayout->addWidget(ui->allMsgBtn);
    filterLayout->addWidget(ui->unreadMsgBtn);
    filterLayout->addStretch();
    filterBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    filterBar->setFixedHeight(40);
    mainLayout->addWidget(filterBar);

    ui->msgTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(ui->msgTable, 1);

    QWidget *funcBar = new QWidget();
    QHBoxLayout *funcLayout = new QHBoxLayout(funcBar);
    funcLayout->setContentsMargins(10, 5, 10, 5);
    funcLayout->setSpacing(10);
    funcLayout->addStretch();
    funcLayout->addWidget(ui->markReadBtn);
    funcLayout->addWidget(ui->deleteBtn);
    funcBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    funcBar->setFixedHeight(40);
    mainLayout->addWidget(funcBar);

    initTableConfig();
    on_allMsgBtn_clicked();
}

mymsgdialog::~mymsgdialog()
{
    delete ui;
}

void mymsgdialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
}

void mymsgdialog::initTableConfig()
{
    QStringList headers;
    headers << "标题" << "内容" << "发送时间" << "状态";
    ui->msgTable->setColumnCount(4);
    ui->msgTable->setHorizontalHeaderLabels(headers);

    ui->msgTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->msgTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->msgTable->setWordWrap(false);
    ui->msgTable->setShowGrid(false);
    ui->msgTable->verticalHeader()->setVisible(false);

    ui->msgTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->msgTable->verticalHeader()->setDefaultSectionSize(40);
    ui->msgTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 列宽铺满

    ui->msgTable->setContentsMargins(0, 0, 0, 0);
    ui->msgTable->setMinimumSize(0, 0);
    ui->msgTable->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);

    connect(ui->msgTable, &QTableWidget::cellDoubleClicked, this, &mymsgdialog::onMsgCellDoubleClicked);
}

void mymsgdialog::updateBtnStyle(QPushButton *selectedBtn)
{
    QString defaultStyle = "background:transparent;color:#333;border:none;padding:4px 12px;";
    QString selectedStyle = "background:#FF6700;color:white;border-radius:4px;padding:4px 12px;";

    ui->allMsgBtn->setStyleSheet(defaultStyle);
    ui->unreadMsgBtn->setStyleSheet(defaultStyle);
    selectedBtn->setStyleSheet(selectedStyle);
}

void mymsgdialog::loadMsgData(const QString &status)
{
    ui->msgTable->setRowCount(0);

    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    QString sql = "SELECT id, "
                  "HEX(title) AS title_hex, "
                  "HEX(content) AS content_hex, "
                  "create_time, "
                  "is_read "
                  "FROM message WHERE user_id=? ";

    if (status == "未读消息") {
        sql += "AND is_read=0 ";
    }

    sql += "ORDER BY create_time DESC";
    query.prepare(sql);
    query.addBindValue(m_userId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Message query failed: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->msgTable->insertRow(row);

        const int msgId = query.value("id").toInt();
        const QString createTime = query.value("create_time").toDateTime().toString("yyyy-MM-dd HH:mm");
        const bool isRead = query.value("is_read").toBool();

        QString titleHex = query.value("title_hex").toString();
        QByteArray titleBytes = QByteArray::fromHex(titleHex.toUtf8());
        QString title = QString::fromUtf8(titleBytes);

        QString contentHex = query.value("content_hex").toString();
        QByteArray contentBytes = QByteArray::fromHex(contentHex.toUtf8());
        QString content = QString::fromUtf8(contentBytes);

        QTableWidgetItem *titleItem = new QTableWidgetItem(title);
        titleItem->setData(Qt::UserRole, msgId);
        titleItem->setData(Qt::UserRole+1, title);
        titleItem->setTextAlignment(Qt::AlignVCenter);
        ui->msgTable->setItem(row, 0, titleItem);

        QTableWidgetItem *contentItem = new QTableWidgetItem(content);
        contentItem->setData(Qt::UserRole+1, content);
        contentItem->setTextAlignment(Qt::AlignVCenter);
        ui->msgTable->setItem(row, 1, contentItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(createTime);
        timeItem->setTextAlignment(Qt::AlignVCenter);
        ui->msgTable->setItem(row, 2, timeItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(isRead ? "已读" : "未读");
        statusItem->setForeground(isRead ? QColor("#888888") : QColor("#FF4444"));
        statusItem->setTextAlignment(Qt::AlignCenter);
        ui->msgTable->setItem(row, 3, statusItem);

        if (!isRead) {
            QFont font = titleItem->font();
            font.setBold(true);
            titleItem->setFont(font);
        }

        row++;
    }

    if (row == 0) {
        ui->msgTable->setRowCount(1);
        QTableWidgetItem *emptyItem = new QTableWidgetItem(status == "未读消息" ? "暂无未读消息" : "暂无消息通知");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        emptyItem->setForeground(QColor("#888888"));
        ui->msgTable->setSpan(0, 0, 1, 4);
        ui->msgTable->setItem(0, 0, emptyItem);
    }
}

void mymsgdialog::onMsgCellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    QTableWidgetItem *titleItem = ui->msgTable->item(row, 0);
    QTableWidgetItem *contentItem = ui->msgTable->item(row, 1);
    QTableWidgetItem *timeItem = ui->msgTable->item(row, 2);
    QTableWidgetItem *statusItem = ui->msgTable->item(row, 3);

    if (!titleItem || !contentItem) return;

    QDialog *detailDialog = new QDialog(this);
    detailDialog->setWindowTitle("消息详情");
    detailDialog->resize(500, 350);
    detailDialog->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(detailDialog);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    QLabel *titleLabel = new QLabel("标题：" + titleItem->data(Qt::UserRole+1).toString());
    QFont titleFont = titleLabel->font();
    titleFont.setBold(true);
    titleFont.setPointSize(12);
    titleLabel->setFont(titleFont);
    layout->addWidget(titleLabel);

    QLabel *contentLabel = new QLabel("内容：" + contentItem->data(Qt::UserRole+1).toString());
    contentLabel->setWordWrap(true);
    contentLabel->setMinimumHeight(150);
    layout->addWidget(contentLabel);

    QWidget *infoWidget = new QWidget();
    QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
    infoLayout->addWidget(new QLabel("发送时间：" + timeItem->text()));
    infoLayout->addStretch();
    infoLayout->addWidget(new QLabel("状态：" + statusItem->text()));
    layout->addWidget(infoWidget);

    detailDialog->exec();
    delete detailDialog;
}

void mymsgdialog::on_allMsgBtn_clicked()
{
    updateBtnStyle(ui->allMsgBtn);
    loadMsgData("全部消息");
}

void mymsgdialog::on_unreadMsgBtn_clicked()
{
    updateBtnStyle(ui->unreadMsgBtn);
    loadMsgData("未读消息");
}

void mymsgdialog::on_markReadBtn_clicked()
{
    int currentRow = ui->msgTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请选择一条消息！");
        return;
    }

    QTableWidgetItem *titleItem = ui->msgTable->item(currentRow, 0);
    QTableWidgetItem *statusItem = ui->msgTable->item(currentRow, 3);
    if (!titleItem || !statusItem) {
        QMessageBox::warning(this, "错误", "无效的消息数据！");
        return;
    }

    int msgId = titleItem->data(Qt::UserRole).toInt();
    if (msgId <= 0) {
        QMessageBox::warning(this, "错误", "无效的消息ID！");
        return;
    }

    if (statusItem->text() == "已读") {
        QMessageBox::information(this, "提示", "该消息已处于已读状态！");
        return;
    }

    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    query.prepare("UPDATE message SET is_read=1 WHERE id=? AND user_id=?");
    query.addBindValue(msgId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "消息已标记为已读！");
        statusItem->setText("已读");
        statusItem->setForeground(QColor("#888888"));
        QFont font = titleItem->font();
        font.setBold(false);
        titleItem->setFont(font);
    } else {
        QMessageBox::warning(this, "错误", "标记失败：" + query.lastError().text());
    }
}

void mymsgdialog::on_deleteBtn_clicked()
{
    int currentRow = ui->msgTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请选择一条消息！");
        return;
    }

    QTableWidgetItem *titleItem = ui->msgTable->item(currentRow, 0);
    if (!titleItem) {
        QMessageBox::warning(this, "错误", "无效的消息数据！");
        return;
    }

    int msgId = titleItem->data(Qt::UserRole).toInt();
    QString title = titleItem->data(Qt::UserRole+1).toString();
    if (msgId <= 0) {
        QMessageBox::warning(this, "错误", "无效的消息ID！");
        return;
    }

    QMessageBox::StandardButton ret = QMessageBox::question(
        this,
        "确认删除",
        "是否永久删除消息《" + title + "》？",
        QMessageBox::Yes | QMessageBox::No, // 标准按钮
        QMessageBox::No // 默认选中No
        );

    if (ret != QMessageBox::Yes) {
        return;
    }

    QSqlDatabase db = DatabaseManager::instance()->getDatabase();
    QSqlQuery query(db);
    query.prepare("DELETE FROM message WHERE id=? AND user_id=?");
    query.addBindValue(msgId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "消息删除成功！");
        ui->msgTable->removeRow(currentRow);
        if (ui->msgTable->rowCount() == 0) {
            if (ui->allMsgBtn->styleSheet().contains("background:#FF6700")) {
                loadMsgData("全部消息");
            } else {
                loadMsgData("未读消息");
            }
        }
    } else {
        QMessageBox::warning(this, "错误", "删除失败：" + query.lastError().text());
    }
}