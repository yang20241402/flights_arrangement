#include "changeticketwidget.h"
#include "ui_changeticketwidget.h"
#include "flightdetailwidget.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QSqlError>
#include <QMap>

ChangeTicketWidget::ChangeTicketWidget(const QString& departCity,
                                       const QString& arriveCity,
                                       const QString& oldFlightNo,
                                       const QDate& oldFlightDate,
                                       QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeTicketWidget)
    , m_departCity(departCity)
    , m_arriveCity(arriveCity)
    , m_oldFlightNo(oldFlightNo)
    , m_oldFlightDate(oldFlightDate)
    , m_selectedDate(QDate()) // 初始化为无效日期
{
    ui->setupUi(this);
    
    // 验证数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    if (!dbManager->isConnected()) {
        QMessageBox::critical(this, "错误", "数据库连接失败！");
        return;
    }

    QList<QWidget*> widgetList = {
        ui->widget_3
    };
    foreach (QWidget *w, widgetList) {
        w->installEventFilter(this);
        QList<QLineEdit*> edits = w->findChildren<QLineEdit*>();
        foreach (QLineEdit *e, edits) {
            e->installEventFilter(this);
        }
    }

    QList<QLabel*> labels = {ui->lblDepart, ui->lblArrive, ui->lblOldFlight};
    foreach (QLabel* lbl, labels) {
        QFont f = lbl->font();
        f.setPointSize(12);
        f.setBold(true);
        lbl->setFont(f);
    }

    ui->lblDepart->setText(QString("<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">%1</span></p></body></html>").arg(m_departCity));
    ui->lblArrive->setText(QString("<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">%1</span></p></body></html>").arg(m_arriveCity));
    ui->lblOldFlight->setText(QString("%1 %2").arg(m_oldFlightNo).arg(m_oldFlightDate.toString("yyyy-MM-dd")));
    
    qDebug() << "=== 改签页面初始化 ===";
    qDebug() << "出发城市：" << m_departCity;
    qDebug() << "到达城市：" << m_arriveCity;
    qDebug() << "原航班号：" << m_oldFlightNo;
    qDebug() << "原航班日期：" << m_oldFlightDate;
    
    ui->calendarWidget->setVisible(false);
    
    // 设置日历控件的最小日期为今天，禁止选择过去的日期
    QDate today = QDate::currentDate();
    ui->calendarWidget->setMinimumDate(today);
    
    // 不在初始化时查询航班，等用户选择日期后再查询
    // allGoingFlights = queryFlights(0,2);
    // on_btnSearch_clicked();
}

ChangeTicketWidget::~ChangeTicketWidget()
{
    delete ui;
}

bool ChangeTicketWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            bool isClickWidget3 = (watched == ui->widget_3) ||
                                  (qobject_cast<QLineEdit*>(watched) && qobject_cast<QLineEdit*>(watched)->parentWidget() == ui->widget_3);

            if (isClickWidget3) {
                ui->label_8->setStyleSheet("color: #007fff;");
                ui->calendarWidget->show();
                return false;
            }

            if (ui->calendarWidget->isVisible()) {
                bool isClickCalendar = (watched == ui->calendarWidget) || ui->calendarWidget->isAncestorOf(qobject_cast<QWidget*>(watched));
                if (!isClickCalendar) {
                    ui->calendarWidget->hide();
                    ui->label_8->setStyleSheet("");
                }
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}

QList<FlightInfo> ChangeTicketWidget::queryFlights(int flightType, int type)
{
    QList<FlightInfo> flights;
    
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    // Query all 9 flight batch tables
    for (int batchNum = 1; batchNum <= 9; batchNum++) {
        QString tableName = QString("flights_batch_%1").arg(batchNum, 3, 10, QChar('0'));
        QSqlQuery query(db);
        query.clear();

        QString sql = QString("SELECT 航空公司, 航班号, 机型, 起飞时间, 到达时间, "
                             "出发机场, 到达机场, 成人价格, 儿童价格, 飞行时长, "
                             "出发城市, 到达城市 FROM %1 WHERE 1=1 ").arg(tableName);

        if(type==2){
            if (!m_departCity.isEmpty()) {
                sql += "AND 出发城市 = ? ";
            }
            if (!m_arriveCity.isEmpty()) {
                sql += "AND 到达城市 = ? ";
            }

            // 移除日期查询条件，让所有日期的数据都可以查询到
            // QDate departDate = getDepartDate();
            // if (departDate.isValid()) {
            //     sql += "AND DATE(起飞时间) = ? ";
            // }

            if (!query.prepare(sql)) {
                qCritical() << "Prepare失败：" << query.lastError().text();
                continue;
            }

            int paramIndex = 0;
            if (!m_departCity.isEmpty()) {
                query.bindValue(paramIndex++, m_departCity);
            }
            if (!m_arriveCity.isEmpty()) {
                query.bindValue(paramIndex++, m_arriveCity);
            }
            // 移除日期参数绑定
            // if (departDate.isValid()) {
            //     query.bindValue(paramIndex++, departDate.toString("yyyy-MM-dd"));
            // }

            if (!query.exec()) {
                qCritical() << "查询失败：" << query.lastError().text();
                continue;
            }

            while (query.next()) {
                FlightInfo info;
                info.airline = query.value(0).toString();
                info.logo = getAirlineLogo(info.airline);  // 根据航空公司名称获取 logo
                info.flightNo = query.value(1).toString();
                info.planeType = query.value(2).toString();
                info.departTime = query.value(3).toDateTime().toString("hh:mm");
                info.arriveTime = query.value(4).toDateTime().toString("hh:mm");
                info.departAirport = query.value(5).toString();
                info.arriveAirport = query.value(6).toString();
                info.price = query.value(7).toString();
                
                // Parse price for sorting
                QString priceStr = query.value(7).toString();
                priceStr.remove("¥");
                info.price_int = priceStr.toInt();
                
                // 忽略价格为0的废数据
                if (info.price_int <= 0) {
                    continue;
                }
                
                // Calculate duration
                QDateTime departDateTime = query.value(3).toDateTime();
                QDateTime arriveDateTime = query.value(4).toDateTime();
                int durationMinutes = departDateTime.secsTo(arriveDateTime) / 60;
                info.duration = durationMinutes;
                
                // Check if next day
                info.isNextDay = (departDateTime.date() != arriveDateTime.date()) ? 1 : 0;
                
                // Set default values for missing fields
                info.onTimeRate = 85; // Default on-time rate
                info.economyPrice = info.price_int;
                info.economyRemain = 50; // Default remaining seats
                info.businessPrice = info.price_int * 2;
                info.businessRemain = 10;
                info.firstPrice = info.price_int * 3;
                info.firstRemain = 5;
                info.remain = 50;
                
                flights.append(info);
            }

            int validPassengerCount = getValidPassengerCount();
            QList<FlightInfo> filteredFlights;
            for (const auto& flight : flights) {
                if (flight.remain >= validPassengerCount) {
                    filteredFlights.append(flight);
                }
            }
            flights = filteredFlights;
        }
    }

    return flights;
}

void ChangeTicketWidget::addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights)
{
    listWidget->clear();
    for (const auto& flight : flights) {
        QListWidgetItem *item = new QListWidgetItem(listWidget);
        item->setSizeHint(QSize(0, 80));

        FlightItemWidget *flightWidget = new FlightItemWidget();
        flightWidget->setFlightInfo(flight);
        
        // 连接点击信号，在点击时实时获取当前选择的日期
        connect(flightWidget, &FlightItemWidget::clicked, this, [=](const FlightInfo& info) {
            // 实时获取当前选择的日期
            QDate dateToUse = getDepartDate();
            
            // 如果日期无效，使用当前日期作为备用
            if (!dateToUse.isValid()) {
                dateToUse = QDate::currentDate();
                qDebug() << "改签页面：日期无效，使用当前日期：" << dateToUse;
            }
            
            qDebug() << "改签页面：点击航班，传递的日期：" << dateToUse;
            qDebug() << "航班号：" << info.flightNo;
            
            FlightDetailWidget* detailWidget = new FlightDetailWidget(info, 1, dateToUse, this);
            detailWidget->show();
        });
        
        listWidget->setItemWidget(item, flightWidget);
    }
}

void ChangeTicketWidget::refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights)
{
    addFlightsToWidget(listWidget, flights);
    if (flights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        listWidget->addItem(emptyItem);
    }
}

int ChangeTicketWidget::getValidPassengerCount()
{
    return 1;
}

void ChangeTicketWidget::on_btnSearch_clicked()
{
    // 检查是否选择了日期
    QDate selectedDate = getDepartDate();
    if (!selectedDate.isValid()) {
        QMessageBox::warning(this, "提示", "请选择日期！");
        return;
    }
    
    ui->listWidgetNewFlight->clear();
    QList<FlightInfo> newFlights = queryFlights(0, 2);
    addFlightsToWidget(ui->listWidgetNewFlight, newFlights);

    if (newFlights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->listWidgetNewFlight->addItem(emptyItem);
    }
    m_newFlights = newFlights;
}

void ChangeTicketWidget::on_dateNewFlight_dateChanged(const QDate &date)
{
    on_btnSearch_clicked();
}

QDate ChangeTicketWidget::getDepartDate() {
    // 直接返回成员变量中存储的日期
    qDebug() << "改签页面 getDepartDate() - 返回的日期：" << m_selectedDate;
    return m_selectedDate;
}

void ChangeTicketWidget::on_calendarWidget_clicked(const QDate &date)
{
    QString dateStr = date.toString("yyyy-MM-dd");

    QString weekStr;
    switch (date.dayOfWeek()) {
    case Qt::Monday: weekStr = "星期一"; break;
    case Qt::Tuesday: weekStr = "星期二"; break;
    case Qt::Wednesday: weekStr = "星期三"; break;
    case Qt::Thursday: weekStr = "星期四"; break;
    case Qt::Friday: weekStr = "星期五"; break;
    case Qt::Saturday: weekStr = "星期六"; break;
    case Qt::Sunday: weekStr = "星期日"; break;
    default: weekStr = "";
    }

    QString fullText = QString("%1 %2").arg(dateStr).arg(weekStr);
    
    // 保存选择的日期到成员变量
    m_selectedDate = date;
    
    // 更新 UI 显示（使用 HTML 格式保持样式）
    ui->lineEditDate->setText(QString("<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">%1</span></p></body></html>").arg(fullText));
    
    ui->calendarWidget->hide();
    
    qDebug() << "改签页面：选择了日期：" << m_selectedDate;
}

void ChangeTicketWidget::on_comboBox_3_currentIndexChanged(int index)
{
    if(index==0){
        return ;
    }else{
        SortType sortType = static_cast<SortType>(index-1);
        flightManager.setFlightList(allGoingFlights);
        QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);

        refreshFlightList(ui->listWidgetNewFlight, sortedGoing);
    }
}

void ChangeTicketWidget::on_dijia_clicked()
{
    ui->dijia->setStyleSheet("color: #007fff;");
    ui->ontime->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(7);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetNewFlight, sortedGoing);
}

void ChangeTicketWidget::on_ontime_clicked()
{
    ui->dijia->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #000000;");
    ui->ontime->setStyleSheet("color: #007fff;");
    SortType sortType = static_cast<SortType>(6);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetNewFlight, sortedGoing);
}

void ChangeTicketWidget::on_depart_clicked()
{
    ui->dijia->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #007fff;");
    ui->ontime->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(8);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetNewFlight, sortedGoing);
}

// 根据航空公司名称获取对应的 logo
QString ChangeTicketWidget::getAirlineLogo(const QString& airlineName)
{
    // 航空公司名称到 logo 文件的映射
    static QMap<QString, QString> airlineLogoMap = {
        {"中国国际航空", ":/newimages/newimages/airchina.jpg"},
        {"国航", ":/newimages/newimages/airchina.jpg"},
        {"Air China", ":/newimages/newimages/airchina.jpg"},
        {"CA", ":/newimages/newimages/airchina.jpg"},
        
        {"中国东方航空", ":/newimages/newimages/eastern.jpg"},
        {"东方航空", ":/newimages/newimages/eastern.jpg"},
        {"东航", ":/newimages/newimages/eastern.jpg"},
        {"China Eastern", ":/newimages/newimages/eastern.jpg"},
        {"MU", ":/newimages/newimages/eastern.jpg"},
        
        {"中国南方航空", ":/newimages/newimages/southern.jpg"},
        {"南方航空", ":/newimages/newimages/southern.jpg"},
        {"南航", ":/newimages/newimages/southern.jpg"},
        {"China Southern", ":/newimages/newimages/southern.jpg"},
        {"CZ", ":/newimages/newimages/southern.jpg"},
        
        {"海南航空", ":/newimages/newimages/hainan.jpg"},
        {"Hainan Airlines", ":/newimages/newimages/hainan.jpg"},
        {"HU", ":/newimages/newimages/hainan.jpg"},
        
        {"厦门航空", ":/newimages/newimages/xiamen.jpg"},
        {"厦航", ":/newimages/newimages/xiamen.jpg"},
        {"Xiamen Air", ":/newimages/newimages/xiamen.jpg"},
        {"MF", ":/newimages/newimages/xiamen.jpg"},
        
        {"深圳航空", ":/newimages/newimages/shenzhen.jpg"},
        {"深航", ":/newimages/newimages/shenzhen.jpg"},
        {"Shenzhen Airlines", ":/newimages/newimages/shenzhen.jpg"},
        {"ZH", ":/newimages/newimages/shenzhen.jpg"},
        
        {"春秋航空", ":/newimages/newimages/chunqiu.jpg"},
        {"Spring Airlines", ":/newimages/newimages/chunqiu.jpg"},
        {"9C", ":/newimages/newimages/chunqiu.jpg"},
        
        {"吉祥航空", ":/newimages/newimages/jixiang.jpg"},
        {"Juneyao Airlines", ":/newimages/newimages/jixiang.jpg"},
        {"HO", ":/newimages/newimages/jixiang.jpg"}
    };
    
    // 先尝试精确匹配
    if (airlineLogoMap.contains(airlineName)) {
        return airlineLogoMap[airlineName];
    }
    
    // 尝试模糊匹配（包含关系）
    for (auto it = airlineLogoMap.begin(); it != airlineLogoMap.end(); ++it) {
        if (airlineName.contains(it.key()) || it.key().contains(airlineName)) {
            return it.value();
        }
    }
    
    // 如果没有匹配，返回默认 logo
    return ":/newimages/newimages/logo1.png";
}