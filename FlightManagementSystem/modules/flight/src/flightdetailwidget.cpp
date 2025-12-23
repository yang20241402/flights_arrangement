#include "flightdetailwidget.h"
#include "ui_flightdetailwidget.h"
#include "databasemanager.h"
#include <QFont>
#include <QColor>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QSpacerItem>
#include <QRandomGenerator>
#include <QDebug>

FlightDetailWidget::FlightDetailWidget(const FlightInfo& flightInfo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlightDetailWidget)
    , m_flightInfo(flightInfo)
    , m_userId(1) // 默认用户ID
    , m_selectedDate(QDate::currentDate()) // 默认使用今天
{
    ui->setupUi(this);
    this->setWindowTitle("航班详情");
    this->setFixedSize(850, 700);

    // 初始化操作
    initStyle();
    loadFlightDetail();
    
    // 连接按钮信号
    connect(ui->reserveBtn, &QPushButton::clicked, this, &FlightDetailWidget::onReserveClicked);
}

FlightDetailWidget::FlightDetailWidget(const FlightInfo& flightInfo, int userId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlightDetailWidget)
    , m_flightInfo(flightInfo)
    , m_userId(userId)
    , m_selectedDate(QDate::currentDate()) // 默认使用今天
{
    ui->setupUi(this);
    this->setWindowTitle("航班详情");
    this->setFixedSize(850, 700);

    // 初始化操作
    initStyle();
    loadFlightDetail();
    
    // 连接按钮信号
    connect(ui->reserveBtn, &QPushButton::clicked, this, &FlightDetailWidget::onReserveClicked);
}

FlightDetailWidget::FlightDetailWidget(const FlightInfo& flightInfo, int userId, const QDate& selectedDate, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlightDetailWidget)
    , m_flightInfo(flightInfo)
    , m_userId(userId)
    , m_selectedDate(selectedDate)
{
    qDebug() << "=== FlightDetailWidget 构造函数 ===";
    qDebug() << "接收到的日期：" << m_selectedDate;
    qDebug() << "日期是否有效：" << m_selectedDate.isValid();
    qDebug() << "航班号：" << m_flightInfo.flightNo;
    
    ui->setupUi(this);
    this->setWindowTitle("航班详情");
    this->setFixedSize(850, 700);

    // 初始化操作
    initStyle();
    loadFlightDetail();
    
    // 连接按钮信号
    connect(ui->reserveBtn, &QPushButton::clicked, this, &FlightDetailWidget::onReserveClicked);
}

FlightDetailWidget::~FlightDetailWidget()
{
    delete ui;
}

void FlightDetailWidget::initStyle()
{
    // 保持与FlightItemWidget一致的样式表
    this->setStyleSheet(R"(
        QDialog {
            background-color: #f8f9fa;
        }
        QLabel#titleLabel {
            font-size: 20px;
            font-weight: bold;
            color: #2c3e50;
            margin-bottom: 10px;
        }
        QWidget#cardWidget {
            background-color: white;
            border-radius: 12px;
            box-shadow: 0 2px 8px rgba(0,0,0,0.08);
            padding: 20px;
            margin-bottom: 15px;
        }
        QLabel#groupTitle {
            font-size: 16px;
            font-weight: bold;
            color: #34495e;
            padding-bottom: 10px;
            border-bottom: 2px solid #e6f7ff;
            margin-bottom: 15px;
        }
        QLabel#labelKey {
            font-size: 14px;
            color: #7f8c8d;
            min-width: 120px;
        }
        QLabel#labelValue {
            font-size: 14px;
            color: #2c3e50;
            font-weight: 500;
        }
        QLabel#warnLabel {
            font-size: 14px;
            color: #e74c3c;
            font-weight: bold;
        }
        QFrame#line {
            background-color: #ecf0f1;
            height: 1px;
            margin: 10px 0;
        }
    )");
}

void FlightDetailWidget::loadFlightDetail()
{
    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    // 查询所有9个航班批次表
    bool found = false;
    for (int batchNum = 1; batchNum <= 9; batchNum++) {
        QString tableName = QString("flights_batch_%1").arg(batchNum, 3, 10, QChar('0'));
        QSqlQuery query(db);
        
        QString sql = QString("SELECT 航空公司, 航班号, 机型, 起飞时间, 到达时间, "
                             "出发机场, 到达机场, 成人价格, 儿童价格, 飞行时长, "
                             "出发城市, 到达城市 FROM %1 WHERE 航班号 = ?").arg(tableName);

        if (!query.prepare(sql)) {
            qCritical() << "Prepare失败：" << query.lastError().text();
            continue;
        }

        query.bindValue(0, m_flightInfo.flightNo);

        if (!query.exec()) {
            qCritical() << "查询失败：" << query.lastError().text();
            continue;
        }

        if (query.next()) {
            found = true;
            
            // 1. 基础信息
            ui->lbFlightId->setText(QString("Batch_%1").arg(batchNum, 3, 10, QChar('0'))); // 显示批次信息
            ui->lbFlightNo->setText(query.value("航班号").toString());
            ui->lbAirline->setText(query.value("航空公司").toString());
            ui->lbPlaneType->setText(query.value("机型").toString());
            ui->lbFlightType->setText("国内航班"); // 默认为国内航班
            
            // 从起飞时间提取日期
            QDateTime departDateTime = query.value("起飞时间").toDateTime();
            QDateTime arriveDateTime = query.value("到达时间").toDateTime();
            
            qDebug() << "数据库起飞时间：" << departDateTime;
            qDebug() << "数据库到达时间：" << arriveDateTime;
            qDebug() << "用户选择日期：" << m_selectedDate;
            
            // 如果用户选择了有效的日期，使用用户选择的日期；否则使用数据库中的日期
            QDate displayDate = m_selectedDate.isValid() ? m_selectedDate : departDateTime.date();
            
            // 将数据库中的时间与显示日期组合
            QTime departTime = departDateTime.time();
            QTime arriveTime = arriveDateTime.time();
            
            // 创建新的日期时间
            QDateTime newDepartDateTime(displayDate, departTime);
            QDateTime newArriveDateTime(displayDate, arriveTime);
            
            // 如果原本是次日到达，新的到达时间也要加一天
            bool isNextDay = (departDateTime.date() != arriveDateTime.date());
            if (isNextDay) {
                newArriveDateTime = newArriveDateTime.addDays(1);
            }
            
            qDebug() << "显示日期：" << displayDate;
            qDebug() << "起飞时间：" << newDepartDateTime;
            qDebug() << "到达时间：" << newArriveDateTime;
            qDebug() << "是否次日：" << isNextDay;
            
            ui->lbFlightDate->setText(displayDate.toString("yyyy-MM-dd"));

            // 2. 起降信息
            ui->lbDepartCity->setText(query.value("出发城市").toString());
            ui->lbArriveCity->setText(query.value("到达城市").toString());
            ui->lbDepartAirport->setText(query.value("出发机场").toString());
            ui->lbArriveAirport->setText(query.value("到达机场").toString());
            ui->lbDepartTime->setText(newDepartDateTime.toString("hh:mm"));
            ui->lbArriveTime->setText(newArriveDateTime.toString("hh:mm"));
            
            // 检查是否次日到达
            ui->lbIsNextDay->setVisible(isNextDay);
            if (isNextDay) {
                ui->lbIsNextDay->setText("+1日");
            }
            
            // 计算飞行时长
            int durationMinutes = newDepartDateTime.secsTo(newArriveDateTime) / 60;
            int hours = durationMinutes / 60;
            int minutes = durationMinutes % 60;
            
            qDebug() << "飞行时长（分钟）：" << durationMinutes;
            qDebug() << "小时：" << hours << " 分钟：" << minutes;
            
            if (hours > 0) {
                ui->lbDuration->setText(QString("%1小时%2分钟").arg(hours).arg(minutes));
            } else {
                ui->lbDuration->setText(QString("%1分钟").arg(minutes));
            }

            // 3. 价格信息
            QString adultPriceStr = query.value("成人价格").toString();
            adultPriceStr.remove("¥"); // 移除货币符号
            int adultPrice = adultPriceStr.toInt();
            
            ui->lbPrice->setText(QString("¥%1").arg(adultPrice));
            ui->lbPriceInt->setText(QString("¥%1").arg(adultPrice));
            ui->lbEconomyPrice->setText(QString("¥%1").arg(adultPrice));
            ui->lbBusinessPrice->setText(QString("¥%1").arg(adultPrice * 2)); // 公务舱约为经济舱2倍
            ui->lbFirstPrice->setText(QString("¥%1").arg(adultPrice * 3)); // 头等舱约为经济舱3倍

            // 4. 余票信息（模拟数据，实际应从数据库获取）
            ui->lbEconomyRemain->setText("50");
            ui->lbBusinessRemain->setText("10");
            ui->lbFirstRemain->setText("5");
            ui->lbRemainTickets->setText("充足");

            break; // 找到数据后退出循环
        }
    }

    if (!found) {
        QMessageBox::information(this, "提示",
                                 "未找到航班号为 " + m_flightInfo.flightNo + " 的航班数据");
        
        // 显示传入的FlightInfo数据作为备用
        displayFlightInfoData();
    }
}

void FlightDetailWidget::displayFlightInfoData()
{
    // 使用传入的FlightInfo数据填充界面
    ui->lbFlightId->setText("--");
    ui->lbFlightNo->setText(m_flightInfo.flightNo);
    ui->lbAirline->setText(m_flightInfo.airline);
    ui->lbPlaneType->setText(m_flightInfo.planeType);
    ui->lbFlightType->setText("国内航班");
    
    // 如果用户选择了有效的日期，使用用户选择的日期；否则使用数据库中的日期
    QDate displayDate = m_selectedDate.isValid() ? m_selectedDate : QDate::fromString("2025-11-13", "yyyy-MM-dd");
    ui->lbFlightDate->setText(displayDate.toString("yyyy-MM-dd"));

    // 起降信息
    ui->lbDepartCity->setText("--");
    ui->lbArriveCity->setText("--");
    ui->lbDepartAirport->setText(m_flightInfo.departAirport);
    ui->lbArriveAirport->setText(m_flightInfo.arriveAirport);
    ui->lbDepartTime->setText(m_flightInfo.departTime);
    ui->lbArriveTime->setText(m_flightInfo.arriveTime);
    ui->lbIsNextDay->setVisible(m_flightInfo.isNextDay);
    
    // 飞行时长
    int hours = m_flightInfo.duration / 60;
    int minutes = m_flightInfo.duration % 60;
    if (hours > 0) {
        ui->lbDuration->setText(QString("%1小时%2分钟").arg(hours).arg(minutes));
    } else {
        ui->lbDuration->setText(QString("%1分钟").arg(minutes));
    }

    // 价格信息
    ui->lbPrice->setText(m_flightInfo.price);
    ui->lbPriceInt->setText(QString("¥%1").arg(m_flightInfo.price_int));
    ui->lbEconomyPrice->setText(QString("¥%1").arg(m_flightInfo.economyPrice));
    ui->lbBusinessPrice->setText(QString("¥%1").arg(m_flightInfo.businessPrice));
    ui->lbFirstPrice->setText(QString("¥%1").arg(m_flightInfo.firstPrice));

    // 余票信息
    ui->lbEconomyRemain->setText(QString::number(m_flightInfo.economyRemain));
    ui->lbBusinessRemain->setText(QString::number(m_flightInfo.businessRemain));
    ui->lbFirstRemain->setText(QString::number(m_flightInfo.firstRemain));
    ui->lbRemainTickets->setText(QString::number(m_flightInfo.remain));
}

void FlightDetailWidget::onReserveClicked()
{
    // 确认预订
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认预订", 
        QString("确认预订航班 %1 吗？\n\n出发：%2 %3\n到达：%4 %5\n价格：%6")
            .arg(m_flightInfo.flightNo)
            .arg(m_flightInfo.departAirport)
            .arg(m_flightInfo.departTime)
            .arg(m_flightInfo.arriveAirport)
            .arg(m_flightInfo.arriveTime)
            .arg(m_flightInfo.price),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (createOrder()) {
            QMessageBox::information(this, "预订成功", 
                "航班预订成功！\n\n订单已生成，状态为【待支付】\n请前往【我的订单】查看并支付");
            this->accept(); // 关闭对话框
        }
    }
}

// 生成订单号
QString FlightDetailWidget::generateOrderId()
{
    // 格式：ORD + 时间戳 + 随机数
    // 例如：ORD20231215143025001
    QDateTime now = QDateTime::currentDateTime();
    QString timestamp = now.toString("yyyyMMddHHmmss");
    int random = QRandomGenerator::global()->bounded(100, 999);
    return QString("ORD%1%2").arg(timestamp).arg(random);
}

// 创建订单
bool FlightDetailWidget::createOrder()
{
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return false;
    }
    
    // 生成订单号
    QString orderId = generateOrderId();
    
    // 获取当前时间作为订单创建时间
    QDateTime now = QDateTime::currentDateTime();
    
    // 构建目的地信息（使用城市而不是机场）
    // 从数据库查询出发城市和到达城市
    QString departCity = "";
    QString arriveCity = "";
    
    // 查询航班的城市信息
    for (int batchNum = 1; batchNum <= 9; batchNum++) {
        QString tableName = QString("flights_batch_%1").arg(batchNum, 3, 10, QChar('0'));
        QSqlQuery cityQuery(db);
        QString citySql = QString("SELECT 出发城市, 到达城市 FROM %1 WHERE 航班号 = ?").arg(tableName);
        
        if (cityQuery.prepare(citySql)) {
            cityQuery.addBindValue(m_flightInfo.flightNo);
            if (cityQuery.exec() && cityQuery.next()) {
                departCity = cityQuery.value("出发城市").toString();
                arriveCity = cityQuery.value("到达城市").toString();
                break;
            }
        }
    }
    
    // 如果没有查到城市信息，使用机场名称作为备用
    if (arriveCity.isEmpty()) {
        arriveCity = m_flightInfo.arriveAirport;
    }
    
    QString destination = arriveCity;
    
    qDebug() << "=== 开始创建订单 ===";
    qDebug() << "航班号：" << m_flightInfo.flightNo;
    qDebug() << "用户选择的日期：" << m_selectedDate;
    
    // 从数据库查询起飞时间
    QDateTime departDateTime;
    
    for (int batchNum = 1; batchNum <= 9; batchNum++) {
        QString tableName = QString("flights_batch_%1").arg(batchNum, 3, 10, QChar('0'));
        QSqlQuery timeQuery(db);
        QString timeSql = QString("SELECT 起飞时间 FROM %1 WHERE 航班号 = ?").arg(tableName);
        
        if (timeQuery.prepare(timeSql)) {
            timeQuery.addBindValue(m_flightInfo.flightNo);
            if (timeQuery.exec() && timeQuery.next()) {
                departDateTime = timeQuery.value("起飞时间").toDateTime();
                qDebug() << "从数据库查询到起飞时间：" << departDateTime;
                
                // 如果用户选择了有效的日期，替换日期部分
                if (m_selectedDate.isValid()) {
                    QTime timeOnly = departDateTime.time();
                    departDateTime = QDateTime(m_selectedDate, timeOnly);
                    qDebug() << "使用用户选择的日期，组合后：" << departDateTime;
                }
                
                break;
            }
        }
    }
    
    // 如果还是无效，使用当前时间作为备用
    if (!departDateTime.isValid()) {
        qDebug() << "未从数据库查到，使用当前时间作为备用";
        departDateTime = QDateTime::currentDateTime();
    }
    
    qDebug() << "最终起飞时间：" << departDateTime;
    qDebug() << "最终起飞时间字符串：" << departDateTime.toString("yyyy-MM-dd HH:mm:ss");
    
    // 插入订单
    QSqlQuery query(db);
    
    // 转义字符串中的单引号，避免 SQL 注入和语法错误
    QString escapedFlightNo = m_flightInfo.flightNo;
    escapedFlightNo.replace("'", "''");
    
    QString escapedDestination = destination;
    escapedDestination.replace("'", "''");
    
    // 使用直接字符串拼接而不是参数绑定，避免 ODBC 驱动的函数序列错误
    QString sql = QString("INSERT INTO `order` (order_id, user_id, flight_num, depart_time, destination, status) "
                         "VALUES ('%1', %2, '%3', '%4', '%5', '%6')")
                      .arg(orderId)
                      .arg(m_userId)
                      .arg(escapedFlightNo)
                      .arg(departDateTime.toString("yyyy-MM-dd HH:mm:ss"))
                      .arg(escapedDestination)
                      .arg("未支付");
    
    qDebug() << "准备执行SQL：" << sql;
    
    if (!query.exec(sql)) {
        qDebug() << "SQL执行失败：" << query.lastError().text();
        qDebug() << "错误类型：" << query.lastError().type();
        qDebug() << "数据库错误：" << query.lastError().databaseText();
        qDebug() << "驱动错误：" << query.lastError().driverText();
        
        QMessageBox::critical(this, "预订失败", 
            QString("创建订单失败：%1\n\n详细信息：\n数据库：%2\n驱动：%3")
                .arg(query.lastError().text())
                .arg(query.lastError().databaseText())
                .arg(query.lastError().driverText()));
        return false;
    }
    
    qDebug() << "订单创建成功：" << orderId << "用户ID：" << m_userId;
    return true;
}