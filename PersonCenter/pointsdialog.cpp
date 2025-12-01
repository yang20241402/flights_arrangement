#include "pointsdialog.h"
#include "ui_pointsdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QHeaderView>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>

PointsDialog::PointsDialog(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PointsDialog)
{
    ui->setupUi(this);
    setWindowTitle("我的积分");
    resize(650, 500);
    m_userId = userId;

    setupLayout();
    initDatabase();
    initTableConfig();
    loadPointsData();
}

PointsDialog::~PointsDialog()
{
    delete ui;
}

void PointsDialog::initDatabase()
{
    m_db = QSqlDatabase::addDatabase("QODBC", "PointsDialogConnection");
    m_db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
    m_db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");

    if (!m_db.open())
    {
        QMessageBox::warning(this, "Error", "ODBC connect failed: " + m_db.lastError().text());
        return;
    }

    QSqlQuery query(m_db);
    query.exec("SET NAMES utf8mb4;");
    query.exec("SET CHARACTER_SET_RESULTS=utf8mb4;");
}

void PointsDialog::setupLayout()
{
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());
    if (!mainLayout)
    {
        mainLayout = new QVBoxLayout(this);
        setLayout(mainLayout);
    }

    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(12);

    ui->totalPointsLabel->setFixedHeight(40);
    mainLayout->addWidget(ui->totalPointsLabel);

    ui->pointsTable->setStyleSheet(R"(
        QTableWidget { background:#ffffff; border:1px solid #e0e0e0; border-radius:8px; padding:5px; gridline-color:#f0f0f0; }
        QHeaderView::section { background:#f8f9fa; font-weight:bold; color:#333333; padding:8px; border:none; border-bottom:1px solid #e0e0e0; }
        QTableWidget::item:even { background:#fcfcfc; }
        QTableWidget::item:odd { background:#f9f9f9; }
        QTableWidget::item:hover { background:#e6f7ff; }
        QTableWidget::item { padding:6px; color:#333333; }
    )");
    mainLayout->addWidget(ui->pointsTable);
    mainLayout->setStretchFactor(ui->pointsTable, 1);

    ui->ruleLabel->setFixedHeight(80);
    mainLayout->addWidget(ui->ruleLabel);

    QWidget *btnWidget = new QWidget();
    QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
    btnLayout->setAlignment(Qt::AlignCenter);

    ui->refreshBtn->setFixedSize(120, 36);
    ui->refreshBtn->setStyleSheet("QPushButton { background:#409EFF; color:white; border:none; border-radius:6px; font-size:14px; }"
                                  "QPushButton:hover { background:#66b1ff; }"
                                  "QPushButton:pressed { background:#3a8ee6; }");
    btnLayout->addWidget(ui->refreshBtn);
    mainLayout->addWidget(btnWidget);
}

void PointsDialog::initTableConfig()
{
    ui->pointsTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->pointsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->pointsTable->setColumnWidth(1, 100);
    ui->pointsTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->pointsTable->setColumnWidth(2, 160);
    ui->pointsTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->pointsTable->setColumnWidth(3, 60);

    ui->pointsTable->setWordWrap(true);
    ui->pointsTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->pointsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

int PointsDialog::calculateTotalPoints()
{
    QSqlQuery query(m_db);
    const QString sql = "SELECT SUM(points_num) AS total FROM points WHERE user_id=?";
    query.prepare(sql);
    query.addBindValue(m_userId);

    if (query.exec() && query.next())
        return query.value("total").toInt();

    return 0;
}

void PointsDialog::loadPointsData()
{
    ui->pointsTable->setRowCount(0);

    QSqlQuery query(m_db);
    const QString sql = "SELECT HEX(points_type) AS type_hex, points_num, create_time, "
                        "CASE WHEN points_num > 0 THEN '积分增加' ELSE '积分扣除' END AS remark "
                        "FROM points WHERE user_id=? ORDER BY create_time DESC";
    query.prepare(sql);
    query.addBindValue(m_userId);

    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", "Points query failed: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next())
    {
        ui->pointsTable->insertRow(row);

        const QString typeHex = query.value("type_hex").toString();
        const QByteArray typeBytes = QByteArray::fromHex(typeHex.toUtf8());
        const QString pointsType = QString::fromUtf8(typeBytes);

        const int pointsNum = query.value("points_num").toInt();
        QTableWidgetItem *numItem = new QTableWidgetItem(QString::number(pointsNum));
        numItem->setForeground(pointsNum > 0 ? QColor("#32CD32") : QColor("#FF4444"));

        const QString createTime = query.value("create_time").toDateTime().toString("yyyy-MM-dd HH:mm");
        const QString remark = query.value("remark").toString();

        ui->pointsTable->setItem(row, 0, new QTableWidgetItem(pointsType));
        ui->pointsTable->setItem(row, 1, numItem);
        ui->pointsTable->setItem(row, 2, new QTableWidgetItem(createTime));
        ui->pointsTable->setItem(row, 3, new QTableWidgetItem(remark));

        row++;
    }

    if (row == 0)
    {
        ui->pointsTable->setRowCount(1);
        QTableWidgetItem *emptyItem = new QTableWidgetItem("暂无积分记录，可通过下单、参与活动获取积分");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->pointsTable->setSpan(0, 0, 1, 4);
        ui->pointsTable->setItem(0, 0, emptyItem);
    }

    const int totalPoints = calculateTotalPoints();
    ui->totalPointsLabel->setText(QString("当前总积分：%1").arg(totalPoints));
}

void PointsDialog::on_refreshBtn_clicked()
{
    loadPointsData();
    QMessageBox::information(this, "Success", "Points refreshed successfully!");
}
