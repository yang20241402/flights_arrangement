#include "mymsgdialog.h"
#include "ui_mymsgdialog.h"
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
    m_userId(userId) // 初始化用户ID
{
    ui->setupUi(this);
    setWindowTitle("我的消息");
    resize(800, 550);
    setMinimumSize(600, 400); // 设置最小尺寸，避免挤压

    // ========== 修复数据库连接（避免重复创建） ==========
    if (QSqlDatabase::contains("MsgDialogConnection")) {
        m_db = QSqlDatabase::database("MsgDialogConnection");
    } else {
        m_db = QSqlDatabase::addDatabase("QODBC", "MsgDialogConnection");
        m_db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
        m_db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");
    }

    if (!m_db.open()) {
        QMessageBox::warning(this, "Error", "ODBC connect failed: " + m_db.lastError().text());
        return;
    }

    QSqlQuery query(m_db);
    query.exec("SET NAMES utf8mb4;");
    query.exec("SET CHARACTER_SET_RESULTS=utf8mb4;");

    // ========== 重构布局（核心自适应配置） ==========
    // 清空原有布局（安全方式）
    QLayout *oldLayout = this->layout();
    if (oldLayout) {
        oldLayout->deleteLater();
    }

    // 主布局：垂直布局，无内边距，控件间距5px
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0); // 窗口无留白
    mainLayout->setSpacing(5);

    // 1. 筛选按钮栏
    QWidget *filterBar = new QWidget();
    QHBoxLayout *filterLayout = new QHBoxLayout(filterBar);
    filterLayout->setContentsMargins(10, 5, 10, 5); // 少量内边距
    filterLayout->setSpacing(10);
    filterLayout->addWidget(ui->allMsgBtn);
    filterLayout->addWidget(ui->unreadMsgBtn);
    filterLayout->addStretch(); // 按钮左对齐
    // 筛选栏固定高度，不拉伸
    filterBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    filterBar->setFixedHeight(40);
    mainLayout->addWidget(filterBar);

    // 2. 表格区域（核心：自适应占满剩余空间）
    // 表格尺寸策略：水平+垂直都扩展
    ui->msgTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // 伸缩因子=1，优先占满剩余空间
    mainLayout->addWidget(ui->msgTable, 1);

    // 3. 功能按钮栏
    QWidget *funcBar = new QWidget();
    QHBoxLayout *funcLayout = new QHBoxLayout(funcBar);
    funcLayout->setContentsMargins(10, 5, 10, 5);
    funcLayout->setSpacing(10);
    funcLayout->addStretch(); // 按钮右对齐
    funcLayout->addWidget(ui->markReadBtn);
    funcLayout->addWidget(ui->deleteBtn);
    // 功能栏固定高度，不拉伸
    funcBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    funcBar->setFixedHeight(40);
    mainLayout->addWidget(funcBar);

    // 初始化表格和数据
    initDatabase();
    initTableConfig();
    on_allMsgBtn_clicked();
}

mymsgdialog::~mymsgdialog()
{
    // 关闭数据库连接
    if (m_db.isOpen()) {
        m_db.close();
    }
    delete ui;
}

// ========== 移除错误的resizeEvent（不再手动调整表格尺寸） ==========
void mymsgdialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    // 移除 ui->msgTable->adjustSize(); 避免干扰布局
}

// 初始化数据库（创建消息表）
void mymsgdialog::initDatabase()
{
    QSqlQuery query(m_db);
    const QString createSql = "CREATE TABLE IF NOT EXISTS message ("
                              "id INT PRIMARY KEY AUTO_INCREMENT,"
                              "user_id INT NOT NULL,"
                              "title VARCHAR(100) NOT NULL COMMENT '消息标题',"
                              "content TEXT NOT NULL COMMENT '消息内容',"
                              "create_time DATETIME DEFAULT CURRENT_TIMESTAMP COMMENT '发送时间',"
                              "is_read TINYINT DEFAULT 0 COMMENT '0=未读，1=已读',"
                              "FOREIGN KEY (user_id) REFERENCES user(id)"
                              ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci";
    if (!query.exec(createSql)) {
        QMessageBox::warning(this, "Error", "Message table create failed: " + query.lastError().text());
    }
}

// 初始化表格（优化自适应配置，移除无效的省略号代码）
void mymsgdialog::initTableConfig()
{
    QStringList headers;
    headers << "标题" << "内容" << "发送时间" << "状态";
    ui->msgTable->setColumnCount(4);
    ui->msgTable->setHorizontalHeaderLabels(headers);

    // 1. 表格基础配置
    ui->msgTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->msgTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->msgTable->setWordWrap(false);
    ui->msgTable->setShowGrid(false);
    ui->msgTable->verticalHeader()->setVisible(false);

    // 2. 行高固定40px，列宽自适应拉伸
    ui->msgTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->msgTable->verticalHeader()->setDefaultSectionSize(40);
    ui->msgTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 列宽铺满

    // 3. 表格自适应核心配置
    ui->msgTable->setContentsMargins(0, 0, 0, 0);
    ui->msgTable->setMinimumSize(0, 0); // 无最小尺寸限制
    ui->msgTable->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX); // 无最大限制

    // 4. 双击查看详情
    connect(ui->msgTable, &QTableWidget::cellDoubleClicked, this, &mymsgdialog::onMsgCellDoubleClicked);
}

// 按钮样式切换
void mymsgdialog::updateBtnStyle(QPushButton *selectedBtn)
{
    QString defaultStyle = "background:transparent;color:#333;border:none;padding:4px 12px;";
    QString selectedStyle = "background:#FF6700;color:white;border-radius:4px;padding:4px 12px;";

    ui->allMsgBtn->setStyleSheet(defaultStyle);
    ui->unreadMsgBtn->setStyleSheet(defaultStyle);
    selectedBtn->setStyleSheet(selectedStyle);
}

// 加载消息数据（移除单元格省略号代码）
void mymsgdialog::loadMsgData(const QString &status)
{
    ui->msgTable->setRowCount(0);

    QSqlQuery query(m_db);
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

        // HEX解码中文字段
        QString titleHex = query.value("title_hex").toString();
        QByteArray titleBytes = QByteArray::fromHex(titleHex.toUtf8());
        QString title = QString::fromUtf8(titleBytes);

        QString contentHex = query.value("content_hex").toString();
        QByteArray contentBytes = QByteArray::fromHex(contentHex.toUtf8());
        QString content = QString::fromUtf8(contentBytes);

        // 填充表格（移除setTextElideMode）
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

        // 未读消息标题加粗
        if (!isRead) {
            QFont font = titleItem->font();
            font.setBold(true);
            titleItem->setFont(font);
        }

        row++;
    }

    // 空数据提示
    if (row == 0) {
        ui->msgTable->setRowCount(1);
        QTableWidgetItem *emptyItem = new QTableWidgetItem(status == "未读消息" ? "暂无未读消息" : "暂无消息通知");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        emptyItem->setForeground(QColor("#888888"));
        ui->msgTable->setSpan(0, 0, 1, 4);
        ui->msgTable->setItem(0, 0, emptyItem);
    }
}

// 双击查看消息详情
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

// 全部消息按钮
void mymsgdialog::on_allMsgBtn_clicked()
{
    updateBtnStyle(ui->allMsgBtn);
    loadMsgData("全部消息");
}

// 未读消息按钮
void mymsgdialog::on_unreadMsgBtn_clicked()
{
    updateBtnStyle(ui->unreadMsgBtn);
    loadMsgData("未读消息");
}

// 标记已读按钮
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

    QSqlQuery query(m_db);
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

// 删除消息按钮（修复QMessageBox::question废弃警告）
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

    // 修复废弃警告：使用StandardButtons重载
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

    QSqlQuery query(m_db);
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
