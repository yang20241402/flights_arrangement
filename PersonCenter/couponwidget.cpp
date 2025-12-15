#include "couponwidget.h"
#include "ui_couponwidget.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QFont>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>

CouponWidget::CouponWidget(int userId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CouponWidget)
{
    ui->setupUi(this);
    setWindowTitle("我的优惠券");
    resize(800, 550); // 和消息模块一致的窗口大小
    m_userId = userId;

    // ========== 数据库连接（完全仿照消息模块） ==========
    m_db = QSqlDatabase::addDatabase("QODBC", "CouponConnection"); // 独立连接名，避免冲突
    m_db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
    m_db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");

    if (!m_db.open()) {
        QMessageBox::warning(this, "数据库错误", "优惠券模块连接失败：" + m_db.lastError().text());
        return;
    }

    QSqlQuery query(m_db);
    query.exec("SET NAMES utf8mb4;");
    query.exec("SET CHARACTER_SET_RESULTS=utf8mb4;");

    // ========== 布局重构（和消息模块一致：无留白+表格布满） ==========
    if (this->layout()) {
        delete this->layout();
    }

    // 主布局：无内边距、无间距
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // 筛选按钮栏（4个筛选按钮：全部/未使用/已使用/已过期）
    QWidget *filterBar = new QWidget();
    QHBoxLayout *filterLayout = new QHBoxLayout(filterBar);
    filterLayout->setContentsMargins(5, 2, 5, 2); // 最小边距，减少留白
    filterLayout->addWidget(ui->allCouponBtn);
    filterLayout->addWidget(ui->unusedCouponBtn);
    filterLayout->addWidget(ui->usedCouponBtn);
    filterLayout->addWidget(ui->expiredCouponBtn);
    filterLayout->addStretch();
    mainLayout->addWidget(filterBar);

    // 优惠券表格（核心：同宽+布满页面）
    ui->couponTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    mainLayout->addWidget(ui->couponTable, 1); // 伸缩因子=1，占满剩余空间

    // 功能按钮栏（使用+删除）
    QWidget *funcBar = new QWidget();
    QHBoxLayout *funcLayout = new QHBoxLayout(funcBar);
    funcLayout->setContentsMargins(5, 2, 5, 2); // 最小边距
    funcLayout->addStretch();
    funcLayout->addWidget(ui->useCouponBtn);
    funcLayout->addWidget(ui->deleteCouponBtn);
    mainLayout->addWidget(funcBar);

    // 初始化
    initDatabase();
    initTableConfig();
    on_allCouponBtn_clicked(); // 默认加载全部优惠券
}

CouponWidget::~CouponWidget()
{
    m_db.close(); // 关闭数据库连接
    delete ui;
}

// 窗口缩放：强制表格刷新（确保同宽）
void CouponWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    ui->couponTable->adjustSize();
}

// 初始化数据库：创建优惠券表（若不存在）
void CouponWidget::initDatabase()
{
    QSqlQuery query(m_db);
    const QString createSql = "CREATE TABLE IF NOT EXISTS coupon ("
                              "id INT PRIMARY KEY AUTO_INCREMENT,"
                              "user_id INT NOT NULL COMMENT '所属用户ID',"
                              "title VARCHAR(100) NOT NULL COMMENT '优惠券标题（如：满100减20）',"
                              "discount DECIMAL(10,2) NOT NULL COMMENT '优惠金额',"
                              "min_amount DECIMAL(10,2) NOT NULL COMMENT '使用门槛（0=无门槛）',"
                              "start_time DATETIME NOT NULL COMMENT '生效时间',"
                              "end_time DATETIME NOT NULL COMMENT '过期时间',"
                              "is_used TINYINT DEFAULT 0 COMMENT '0=未使用，1=已使用',"
                              "used_time DATETIME NULL COMMENT '使用时间（未使用则为NULL）',"
                              "FOREIGN KEY (user_id) REFERENCES user(id)"
                              ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci";

    if (!query.exec(createSql)) {
        QMessageBox::warning(this, "数据库错误", "创建优惠券表失败：" + query.lastError().text());
    }
}

// 初始化表格：布满页面+同宽（复用消息模块的核心配置）
void CouponWidget::initTableConfig()
{
    QStringList headers;
    headers << "优惠券名称" << "优惠金额" << "使用门槛" << "生效时间" << "过期时间" << "状态";
    ui->couponTable->setColumnCount(6);
    ui->couponTable->setHorizontalHeaderLabels(headers);

    // ========== 核心：确保表格和页面同宽（保留你之前验证有效的代码） ==========
    // 清除表格及表头边距
    ui->couponTable->setContentsMargins(0, 0, 0, 0);
    ui->couponTable->horizontalHeader()->setContentsMargins(0, 0, 0, 0);
    // 强制表格无水平限制
    ui->couponTable->setMinimumWidth(0);
    ui->couponTable->setMaximumWidth(QWIDGETSIZE_MAX);
    // 表格水平/垂直扩展
    ui->couponTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    // 列宽自动拉伸，布满表格
    for (int i = 0; i < ui->couponTable->columnCount(); ++i) {
        ui->couponTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    // 表格基础配置（和消息模块一致）
    ui->couponTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->couponTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->couponTable->setWordWrap(false);
    ui->couponTable->setShowGrid(false);
    ui->couponTable->verticalHeader()->setVisible(false);
    // 行高固定40px（和消息模块一致）
    ui->couponTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->couponTable->verticalHeader()->setDefaultSectionSize(40);

    // 文本省略号委托（名称过长时显示...）
    EllipsisDelegate *delegate = new EllipsisDelegate(this);
    ui->couponTable->setItemDelegateForColumn(0, delegate); // 仅对“优惠券名称”列生效

    // 双击查看详情
    connect(ui->couponTable, &QTableWidget::cellDoubleClicked, this, &CouponWidget::onCouponCellDoubleClicked);
}

// 筛选按钮样式切换（复用消息模块的逻辑）
void CouponWidget::updateBtnStyle(QPushButton *selectedBtn)
{
    QString defaultStyle = "background:transparent;color:#333;border:none;padding:4px 12px;";
    QString selectedStyle = "background:#FF6700;color:white;border-radius:4px;padding:4px 12px;";

    // 重置所有按钮样式
    ui->allCouponBtn->setStyleSheet(defaultStyle);
    ui->unusedCouponBtn->setStyleSheet(defaultStyle);
    ui->usedCouponBtn->setStyleSheet(defaultStyle);
    ui->expiredCouponBtn->setStyleSheet(defaultStyle);
    // 设置选中按钮样式
    selectedBtn->setStyleSheet(selectedStyle);
}

// 加载优惠券数据（核心功能）
void CouponWidget::loadCouponData(const QString &status)
{
    ui->couponTable->setRowCount(0); // 清空表格

    QSqlQuery query(m_db);
    QString sql = "SELECT id, title, discount, min_amount, "
                  "start_time, end_time, is_used, used_time "
                  "FROM coupon WHERE user_id=? ";

    // 根据筛选状态拼接SQL条件
    if (status == "未使用") {
        // 未使用：is_used=0 且 过期时间>当前时间
        sql += "AND is_used=0 AND end_time > NOW() ";
    } else if (status == "已使用") {
        sql += "AND is_used=1 ";
    } else if (status == "已过期") {
        // 已过期：is_used=0 且 过期时间<=当前时间
        sql += "AND is_used=0 AND end_time <= NOW() ";
    }
    // 按过期时间升序排序（快过期的在前）
    sql += "ORDER BY end_time ASC";

    query.prepare(sql);
    query.addBindValue(m_userId);

    if (!query.exec()) {
        QMessageBox::warning(this, "数据加载错误", "查询优惠券失败：" + query.lastError().text());
        return;
    }

    int row = 0;
    QDateTime currentTime = QDateTime::currentDateTime();
    while (query.next()) {
        ui->couponTable->insertRow(row);

        // 读取数据库字段
        const int couponId = query.value("id").toInt();
        const QString title = query.value("title").toString();
        const double discount = query.value("discount").toDouble();
        const double minAmount = query.value("min_amount").toDouble();
        const QString startTime = query.value("start_time").toDateTime().toString("yyyy-MM-dd");
        const QString endTime = query.value("end_time").toDateTime().toString("yyyy-MM-dd");
        const bool isUsed = query.value("is_used").toBool();
        const QString usedTime = query.value("used_time").isNull() ? "无" : query.value("used_time").toDateTime().toString("yyyy-MM-dd");

        // 计算优惠券状态（覆盖筛选条件，显示更精准）
        QString couponStatus = "未知状态";
        QColor statusColor = QColor("#888888");
        if (isUsed) {
            couponStatus = "已使用";
            statusColor = QColor("#666666");
        } else {
            QDateTime expireTime = query.value("end_time").toDateTime();
            if (expireTime < currentTime) {
                couponStatus = "已过期";
                statusColor = QColor("#FF4444");
            } else {
                couponStatus = "未使用";
                statusColor = QColor("#22CC22");
            }
        }

        // 填充表格（文本居中对齐，和消息模块一致）
        auto createItem = [](const QString &text, Qt::Alignment alignment = Qt::AlignVCenter) -> QTableWidgetItem* {
            QTableWidgetItem *item = new QTableWidgetItem(text);
            item->setTextAlignment(alignment);
            return item;
        };

        // 优惠券名称（存储couponId用于后续操作）
        QTableWidgetItem *titleItem = createItem(title);
        titleItem->setData(Qt::UserRole, couponId);
        titleItem->setData(Qt::UserRole+1, title); // 存储原始标题
        ui->couponTable->setItem(row, 0, titleItem);

        // 优惠金额（显示“¥XX.00”格式）
        ui->couponTable->setItem(row, 1, createItem(QString("¥%1").arg(discount, 0, 'f', 2)));
        // 使用门槛（无门槛显示“无”）
        ui->couponTable->setItem(row, 2, createItem(minAmount == 0 ? "无门槛" : QString("满¥%1").arg(minAmount, 0, 'f', 2)));
        // 生效时间
        ui->couponTable->setItem(row, 3, createItem(startTime));
        // 过期时间
        ui->couponTable->setItem(row, 4, createItem(endTime));
        // 状态（设置颜色）
        QTableWidgetItem *statusItem = createItem(couponStatus, Qt::AlignCenter);
        statusItem->setForeground(statusColor);
        ui->couponTable->setItem(row, 5, statusItem);

        row++;
    }

    // 空数据提示（跨列显示）
    if (row == 0) {
        ui->couponTable->setRowCount(1);
        QTableWidgetItem *emptyItem = new QTableWidgetItem("暂无" + status + "优惠券");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        emptyItem->setForeground(QColor("#888888"));
        ui->couponTable->setSpan(0, 0, 1, 6); // 跨6列
        ui->couponTable->setItem(0, 0, emptyItem);
    }
}

// 双击查看优惠券详情
void CouponWidget::onCouponCellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    QTableWidgetItem *titleItem = ui->couponTable->item(row, 0);
    if (!titleItem || titleItem->data(Qt::UserRole).toInt() <= 0) {
        return; // 空数据行忽略
    }

    int couponId = titleItem->data(Qt::UserRole).toInt();
    QString title = titleItem->data(Qt::UserRole+1).toString();
    QString discount = ui->couponTable->item(row, 1)->text();
    QString minAmount = ui->couponTable->item(row, 2)->text();
    QString startTime = ui->couponTable->item(row, 3)->text();
    QString endTime = ui->couponTable->item(row, 4)->text();
    QString status = ui->couponTable->item(row, 5)->text();

    // 详情弹窗（和消息详情弹窗风格一致）
    QDialog *detailDialog = new QDialog(this);
    detailDialog->setWindowTitle("优惠券详情");
    detailDialog->resize(500, 300);
    detailDialog->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(detailDialog);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(12);

    // 标题（加粗）
    QLabel *titleLabel = new QLabel("优惠券名称：" + title);
    QFont titleFont = titleLabel->font();
    titleFont.setBold(true);
    titleFont.setPointSize(12);
    titleLabel->setFont(titleFont);
    layout->addWidget(titleLabel);

    // 详情列表（网格布局）
    QWidget *infoWidget = new QWidget();
    QGridLayout *infoLayout = new QGridLayout(infoWidget);
    infoLayout->setSpacing(10);
    infoLayout->addWidget(new QLabel("优惠金额："), 0, 0);
    infoLayout->addWidget(new QLabel(discount), 0, 1);
    infoLayout->addWidget(new QLabel("使用门槛："), 1, 0);
    infoLayout->addWidget(new QLabel(minAmount), 1, 1);
    infoLayout->addWidget(new QLabel("生效时间："), 2, 0);
    infoLayout->addWidget(new QLabel(startTime), 2, 1);
    infoLayout->addWidget(new QLabel("过期时间："), 3, 0);
    infoLayout->addWidget(new QLabel(endTime), 3, 1);
    infoLayout->addWidget(new QLabel("当前状态："), 4, 0);
    infoLayout->addWidget(new QLabel(status), 4, 1);
    layout->addWidget(infoWidget);

    detailDialog->exec();
    delete detailDialog;
}

// 全部优惠券按钮
void CouponWidget::on_allCouponBtn_clicked()
{
    updateBtnStyle(ui->allCouponBtn);
    loadCouponData("全部");
}

// 未使用优惠券按钮
void CouponWidget::on_unusedCouponBtn_clicked()
{
    updateBtnStyle(ui->unusedCouponBtn);
    loadCouponData("未使用");
}

// 已使用优惠券按钮
void CouponWidget::on_usedCouponBtn_clicked()
{
    updateBtnStyle(ui->usedCouponBtn);
    loadCouponData("已使用");
}

// 已过期优惠券按钮
void CouponWidget::on_expiredCouponBtn_clicked()
{
    updateBtnStyle(ui->expiredCouponBtn);
    loadCouponData("已过期");
}

// 使用优惠券按钮
void CouponWidget::on_useCouponBtn_clicked()
{
    int currentRow = ui->couponTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "操作提示", "请选择一张优惠券！");
        return;
    }

    QTableWidgetItem *titleItem = ui->couponTable->item(currentRow, 0);
    QTableWidgetItem *statusItem = ui->couponTable->item(currentRow, 5);
    if (!titleItem || !statusItem) {
        QMessageBox::warning(this, "操作错误", "无效的优惠券数据！");
        return;
    }

    int couponId = titleItem->data(Qt::UserRole).toInt();
    QString title = titleItem->data(Qt::UserRole+1).toString();
    QString status = statusItem->text();

    // 校验状态（只能使用“未使用”的优惠券）
    if (status != "未使用") {
        QMessageBox::warning(this, "操作提示", "只有未使用的优惠券才能使用！");
        return;
    }

    if (QMessageBox::question(this, "确认使用", "是否使用优惠券《" + title + "》？",
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    // 执行更新操作（标记为已使用，记录使用时间）
    QSqlQuery query(m_db);
    query.prepare("UPDATE coupon SET is_used=1, used_time=NOW() WHERE id=? AND user_id=?");
    query.addBindValue(couponId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "操作成功", "优惠券使用成功！");
        // 刷新当前行状态
        statusItem->setText("已使用");
        statusItem->setForeground(QColor("#666666"));
    } else {
        QMessageBox::warning(this, "操作失败", "使用优惠券失败：" + query.lastError().text());
    }
}

// 删除优惠券按钮
void CouponWidget::on_deleteCouponBtn_clicked()
{
    int currentRow = ui->couponTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "操作提示", "请选择一张优惠券！");
        return;
    }

    QTableWidgetItem *titleItem = ui->couponTable->item(currentRow, 0);
    if (!titleItem) {
        QMessageBox::warning(this, "操作错误", "无效的优惠券数据！");
        return;
    }

    int couponId = titleItem->data(Qt::UserRole).toInt();
    QString title = titleItem->data(Qt::UserRole+1).toString();

    if (QMessageBox::question(this, "确认删除", "是否永久删除优惠券《" + title + "》？",
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
        return;
    }

    // 执行删除操作
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM coupon WHERE id=? AND user_id=?");
    query.addBindValue(couponId);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "操作成功", "优惠券删除成功！");
        ui->couponTable->removeRow(currentRow);
        // 若删除后无数据，刷新当前筛选状态
        if (ui->couponTable->rowCount() == 0) {
            if (ui->allCouponBtn->styleSheet().contains("background:#FF6700")) {
                loadCouponData("全部");
            } else if (ui->unusedCouponBtn->styleSheet().contains("background:#FF6700")) {
                loadCouponData("未使用");
            } else if (ui->usedCouponBtn->styleSheet().contains("background:#FF6700")) {
                loadCouponData("已使用");
            } else if (ui->expiredCouponBtn->styleSheet().contains("background:#FF6700")) {
                loadCouponData("已过期");
            }
        }
    } else {
        QMessageBox::warning(this, "操作失败", "删除优惠券失败：" + query.lastError().text());
    }
}
