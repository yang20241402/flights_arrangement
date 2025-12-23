#include "flightsearchwidget.h"
#include "ui_flightsearchwidget.h"
#include "changeticketwidget.h"
#include "personcenterwindow.h"
#include "myorderdialog.h"
#include <QMap>

FlightSearchWidget::FlightSearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlightSearchWidget)
    , m_currentUserId(1)  // 默认用户ID为1
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->tabWidget_2->setTabVisible(1, false);
    ui->tabWidget->setCurrentIndex(0);
    ui->widget_4->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);

    // 验证数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    if (!dbManager->isConnected()) {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，正在尝试重新连接……");
        if (!dbManager->initializeWithDefaults()) {
            QMessageBox::critical(this, "连接失败", QString("重连数据库失败：%1").arg(dbManager->getLastError()));
            return;
        }
    } else {
        QMessageBox::information(this, "连接提示", "连接成功");
    }

    ui->passengerWidget->hide();
    ui->calendarWidget->hide();
    ui->calendarWidget_2->hide();
    ui->calendarWidget_3->hide();
    
    // 设置日历控件的最小日期为今天，禁止选择过去的日期
    QDate today = QDate::currentDate();
    ui->calendarWidget->setMinimumDate(today);
    ui->calendarWidget_2->setMinimumDate(today);
    ui->calendarWidget_3->setMinimumDate(today);

    qApp->installEventFilter(this);

    QList<QWidget*> widgetList = {
        ui->widget,
        ui->widget_5,
        ui->widget_2,
        ui->widget_3,
        ui->widget_4,
        ui->widget_7,
        ui->widget_10,
        ui->widget_11
    };
    foreach (QWidget *w, widgetList) {
        w->installEventFilter(this);
        QList<QLineEdit*> edits = w->findChildren<QLineEdit*>();
        foreach (QLineEdit *e, edits) {
            e->installEventFilter(this);
        }
    }

    // 加载城市列表并设置自动补全
    m_cities = loadCitiesFromDatabase();
    setupCityCompleters();

    // 初始化时不加载航班数据，避免登录时卡住
    // 显示提示信息，引导用户进行搜索
    showInitialMessage();
}

void FlightSearchWidget::updateTabWidget2PageCount(bool hasReturnFlight)
{
    ui->tabWidget_2->setTabVisible(1, hasReturnFlight);

    if (!hasReturnFlight && ui->tabWidget_2->currentIndex() == 1) {
        ui->tabWidget_2->setCurrentIndex(0);
    }
}

QList<FlightInfo> FlightSearchWidget::queryFlights(int flightType, int type)
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

        if(type==1){
            QString flightNo = getflightNo();

            if (!flightNo.isEmpty()) {
                sql += "AND 航班号 = ? ";
            }

            // 移除日期查询条件，让所有日期的数据都可以查询到
            // QDate otherDate = getOtherDate();
            // if (otherDate.isValid()) {
            //     sql += "AND DATE(起飞时间) = ? ";
            // }

            if (!query.prepare(sql)) {
                qCritical() << "Prepare失败：" << query.lastError().text();
                continue;
            }

            int paramIndex = 0;
            if (!flightNo.isEmpty()) {
                query.bindValue(paramIndex++, flightNo);
            }
            // 移除日期参数绑定
            // if (otherDate.isValid()) {
            //     query.bindValue(paramIndex++, otherDate.toString("yyyy-MM-dd"));
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

        }else if(type==2){
            QString departCity = getDepartCity();
            QString arriveCity = getArriveCity();
            if (!departCity.isEmpty()) {
                sql += "AND 出发城市 = ? ";
            }
            if (!arriveCity.isEmpty()) {
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
            if (!departCity.isEmpty()) {
                query.bindValue(paramIndex++, departCity);
            }
            if (!arriveCity.isEmpty()) {
                query.bindValue(paramIndex++, arriveCity);
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

        }else if(type==3){
            QString departCity = getDepartCity_2();
            QString arriveCity = getArriveCity_2();
            if (!departCity.isEmpty()) {
                sql += "AND 出发城市 = ? ";
            }
            if (!arriveCity.isEmpty()) {
                sql += "AND 到达城市 = ? ";
            }

            // 移除日期查询条件，让所有日期的数据都可以查询到
            // QDate othertDate = getOtherDate();
            // if (othertDate.isValid()) {
            //     sql += "AND DATE(起飞时间) = ? ";
            // }

            if (!query.prepare(sql)) {
                qCritical() << "Prepare失败：" << query.lastError().text();
                continue;
            }

            int paramIndex = 0;
            if (!departCity.isEmpty()) {
                query.bindValue(paramIndex++, departCity);
            }
            if (!arriveCity.isEmpty()) {
                query.bindValue(paramIndex++, arriveCity);
            }
            // 移除日期参数绑定
            // if (othertDate.isValid()) {
            //     query.bindValue(paramIndex++, othertDate.toString("yyyy-MM-dd"));
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
        }
    }

    return flights;
}

void FlightSearchWidget::addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights)
{
    listWidget->clear();
    
    for (const auto& flight : flights) {
        QListWidgetItem *item = new QListWidgetItem(listWidget);
        item->setSizeHint(QSize(0, 80));

        FlightItemWidget *flightWidget = new FlightItemWidget();
        flightWidget->setFlightInfo(flight);
        
        // 连接点击信号，传递用户ID和选择的日期
        // 注意：这里不捕获日期，而是在点击时实时获取
        connect(flightWidget, &FlightItemWidget::clicked, this, [=](const FlightInfo& info) {
            // 在点击时实时获取当前选择的日期
            QDate dateToUse;
            if (ui->stackedWidget->currentIndex() == 0) {
                // 国内/国际航班搜索
                if (listWidget == ui->listWidgetGoing) {
                    dateToUse = getDepartDate();
                    qDebug() << "点击去程航班，实时获取的出发日期：" << dateToUse;
                } else if (listWidget == ui->listWidgetReturn) {
                    dateToUse = getReturnDate();
                    qDebug() << "点击返程航班，实时获取的返程日期：" << dateToUse;
                }
            } else {
                // 航班动态搜索
                dateToUse = getOtherDate();
                qDebug() << "点击航班动态，实时获取的日期：" << dateToUse;
            }
            
            // 如果日期无效，使用当前日期作为备用
            if (!dateToUse.isValid()) {
                dateToUse = QDate::currentDate();
                qDebug() << "日期无效，使用当前日期：" << dateToUse;
            }
            
            qDebug() << "最终传递给详情页面的日期：" << dateToUse;
            qDebug() << "航班号：" << info.flightNo;
            
            FlightDetailWidget* detailWidget = new FlightDetailWidget(info, m_currentUserId, dateToUse, this);
            detailWidget->show();
        });
        
        listWidget->setItemWidget(item, flightWidget);
    }
}

void FlightSearchWidget::refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights)
{
    addFlightsToWidget(listWidget, flights);
    if (flights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        listWidget->addItem(emptyItem);
    }
}

bool FlightSearchWidget::eventFilter(QObject *watched, QEvent *event)
{
    // 处理城市输入框的焦点事件
    QLineEdit* cityInput = qobject_cast<QLineEdit*>(watched);
    if (cityInput && (cityInput == ui->lineEdit_Depart || 
                      cityInput == ui->lineEdit_Arrive ||
                      cityInput == ui->lineEdit_Depart_2 || 
                      cityInput == ui->lineEdit_Arrive_2)) {
        
        if (event->type() == QEvent::FocusIn) {
            // 输入框获得焦点时，显示完整的城市列表
            QCompleter* completer = cityInput->completer();
            if (completer) {
                // 如果输入框为空，设置一个空格触发显示所有项
                if (cityInput->text().isEmpty()) {
                    completer->setCompletionPrefix("");
                }
                completer->complete();
            }
        }
        else if (event->type() == QEvent::MouseButtonPress) {
            // 点击输入框时也显示列表
            QCompleter* completer = cityInput->completer();
            if (completer) {
                if (cityInput->text().isEmpty()) {
                    completer->setCompletionPrefix("");
                }
                completer->complete();
            }
        }
    }
    
    if (watched == ui->calendarWidget || ui->calendarWidget->isAncestorOf(qobject_cast<QWidget*>(watched))) {
        return false;
    }

    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {

            QWidget *targetWidget = nullptr;

            if (watched == ui->widget) targetWidget = ui->widget;
            else if (watched == ui->widget_5) targetWidget = ui->widget_5;
            else if (watched == ui->widget_2) targetWidget = ui->widget_2;
            else if (watched == ui->widget_3) targetWidget = ui->widget_3;
            else if (watched == ui->widget_4) targetWidget = ui->widget_4;
            else if (watched == ui->widget_11) targetWidget = ui->widget_11;

            else if (QLineEdit *edit = qobject_cast<QLineEdit*>(watched)) {
                targetWidget = edit->parentWidget();
            }

            if (targetWidget) {
                if (targetWidget == ui->widget) {
                    ui->label_6->setStyleSheet("color: #007fff;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                }
                else if (targetWidget == ui->widget_2) {
                    ui->label_7->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                }
                else if (targetWidget == ui->widget_3) {
                    ui->label_8->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                    ui->calendarWidget->show();
                }
                else if (targetWidget == ui->widget_4) {
                    ui->label_9->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                    ui->calendarWidget_2->show();
                }
                else if (targetWidget == ui->widget_5) {
                    ui->passengerWidget->show();
                    ui->label_10->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                }else if (targetWidget == ui->widget_11) {
                    ui->label_16->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->calendarWidget_3->show();
                }else if(targetWidget == ui->widget_7){
                    ui->label_14->setStyleSheet("color: #007fff;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->label_15->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                }else if(targetWidget == ui->widget_10){
                    ui->label_15->setStyleSheet("color: #007fff;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->label_14->setStyleSheet("color: #000000;");
                    ui->label_16->setStyleSheet("color: #000000;");
                }
            }

            if (ui->passengerWidget && ui->passengerWidget->isVisible()) {
                if (ui->widget_5) {
                    QRect widgetRect = ui->passengerWidget->geometry();
                    widgetRect.moveTopLeft(ui->passengerWidget->mapToGlobal(QPoint(0, 0)));

                    QRect widget5Rect = ui->widget_5->geometry();
                    widget5Rect.moveTopLeft(ui->widget_5->mapToGlobal(QPoint(0, 0)));

                    QPoint clickPos = mouseEvent->globalPosition().toPoint();
                    if (!widgetRect.contains(clickPos) && !widget5Rect.contains(clickPos)) {
                        ui->passengerWidget->hide();
                    }
                }
            }

            if (ui->calendarWidget && ui->calendarWidget->isVisible()) {
                if (ui->widget_3) {
                    QRect calendarRect = ui->calendarWidget->geometry();
                    calendarRect.moveTopLeft(ui->calendarWidget->mapToGlobal(QPoint(0, 0)));

                    QRect widget3Rect = ui->widget_3->geometry();
                    widget3Rect.moveTopLeft(ui->widget_3->mapToGlobal(QPoint(0, 0)));

                    QPoint clickPos = mouseEvent->globalPosition().toPoint();

                    if (!calendarRect.contains(clickPos) && !widget3Rect.contains(clickPos) ) {
                        ui->calendarWidget->hide();
                    }
                }
            }

            if (ui->calendarWidget_2 && ui->calendarWidget_2->isVisible()) {
                if (ui->widget_4) {
                    QRect calendarRect = ui->calendarWidget_2->geometry();
                    calendarRect.moveTopLeft(ui->calendarWidget_2->mapToGlobal(QPoint(0, 0)));

                    QRect widget4Rect = ui->widget_4->geometry();
                    widget4Rect.moveTopLeft(ui->widget_4->mapToGlobal(QPoint(0, 0)));

                    QPoint clickPos = mouseEvent->globalPosition().toPoint();

                    if (!calendarRect.contains(clickPos)&& !widget4Rect.contains(clickPos)) {
                        ui->calendarWidget_2->hide();
                    }
                }
            }

            if (ui->calendarWidget_3 && ui->calendarWidget_3->isVisible()) {
                if (ui->widget_11) {
                    QRect calendarRect = ui->calendarWidget_3->geometry();
                    calendarRect.moveTopLeft(ui->calendarWidget_3->mapToGlobal(QPoint(0, 0)));

                    QRect widget11Rect = ui->widget_11->geometry();
                    widget11Rect.moveTopLeft(ui->widget_11->mapToGlobal(QPoint(0, 0)));

                    QPoint clickPos = mouseEvent->globalPosition().toPoint();

                    if (!calendarRect.contains(clickPos)&& !widget11Rect.contains(clickPos)) {
                        ui->calendarWidget_3->hide();
                    }
                }
            }
        }
    }
    return false;
}

QString FlightSearchWidget::getDepartCity() {
    return ui->lineEdit_Depart->text().trimmed();
}

QString FlightSearchWidget::getArriveCity() {
    return ui->lineEdit_Arrive->text().trimmed();
}

QString FlightSearchWidget::getflightNo() {
    return ui->lineEdit_3->text().trimmed();
}

QDate FlightSearchWidget::getDepartDate() {
    QString dateText = ui->dateDepart->text().split(" ")[0];
    QDate date = QDate::fromString(dateText, "yyyy-MM-dd");
    qDebug() << "getDepartDate() - 原始文本：" << ui->dateDepart->text();
    qDebug() << "getDepartDate() - 解析后的日期文本：" << dateText;
    qDebug() << "getDepartDate() - 返回的日期：" << date;
    return date;
}

QDate FlightSearchWidget::getReturnDate() {
    QString dateText = ui->dateReturn->text().split(" ")[0];
    QDate date = QDate::fromString(dateText, "yyyy-MM-dd");
    qDebug() << "getReturnDate() - 原始文本：" << ui->dateReturn->text();
    qDebug() << "getReturnDate() - 解析后的日期文本：" << dateText;
    qDebug() << "getReturnDate() - 返回的日期：" << date;
    return date;
}

QDate FlightSearchWidget::getOtherDate() {
    QString dateText = ui->dateDepart_2->text().split(" ")[0];
    QDate date = QDate::fromString(dateText, "yyyy-MM-dd");
    qDebug() << "getOtherDate() - 原始文本：" << ui->dateDepart_2->text();
    qDebug() << "getOtherDate() - 解析后的日期文本：" << dateText;
    qDebug() << "getOtherDate() - 返回的日期：" << date;
    return date;
}

QString FlightSearchWidget::getDepartCity_2() {
    return ui->lineEdit_Depart_2->text().trimmed();
}

QString FlightSearchWidget::getArriveCity_2() {
    return ui->lineEdit_Arrive_2->text().trimmed();
}

int FlightSearchWidget::getValidPassengerCount()
{
    return m_cachedValidPassengerCount;
}

FlightSearchWidget::~FlightSearchWidget()
{
    delete ui;
}

// 用户ID管理
void FlightSearchWidget::setUserId(int userId)
{
    m_currentUserId = userId;
}

int FlightSearchWidget::getUserId() const
{
    return m_currentUserId;
}

void FlightSearchWidget::updateCachedPassengerCount()
{
    int adultCount = ui->spinBox->value();
    int childCount = ui->spinBox_2->value();
    int validCount = adultCount + childCount;
    m_cachedValidPassengerCount = validCount > 0 ? validCount : 1;
}

void FlightSearchWidget::on_calendarWidget_clicked(const QDate &date)
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
    ui->dateDepart->setText(fullText);
}

void FlightSearchWidget::on_calendarWidget_2_clicked(const QDate &date)
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
    ui->dateReturn->setText(fullText);
}

void FlightSearchWidget::on_calendarWidget_3_clicked(const QDate &date)
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
    ui->dateDepart_2->setText(fullText);
}

void FlightSearchWidget::on_btnSearch_clicked()
{
    // 检查是否选择了出发日期
    QDate departDate = getDepartDate();
    if (!departDate.isValid()) {
        QMessageBox::warning(this, "提示", "请选择出发日期！");
        return;
    }
    
    // 如果是往返航班，检查返程日期
    if (ui->radioRoundTrip->isChecked()) {
        QDate returnDate = getReturnDate();
        if (!returnDate.isValid()) {
            QMessageBox::warning(this, "提示", "请选择返程日期！");
            return;
        }
        
        // 检查返程日期是否早于出发日期
        if (returnDate < departDate) {
            QMessageBox::warning(this, "提示", "返程日期不能早于出发日期！");
            return;
        }
    }
    
    ui->listWidgetGoing->clear();
    ui->listWidgetReturn->clear();

    // 更新全局航班列表变量
    allGoingFlights = queryFlights(0,2);
    allReturnFlights = queryFlights(1,2);
    
    addFlightsToWidget(ui->listWidgetGoing, allGoingFlights);
    addFlightsToWidget(ui->listWidgetReturn, allReturnFlights);

    if (allGoingFlights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的去程航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->listWidgetGoing->addItem(emptyItem);
    }
    if (allReturnFlights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的返程航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->listWidgetReturn->addItem(emptyItem);
    }
}

void FlightSearchWidget::on_pushButton_2_clicked()
{
    ui->passengerWidget->hide();
}

void FlightSearchWidget::on_pushButton_clicked()
{
    QString chenren = ui->spinBox->cleanText();
    QString ertong = ui->spinBox_2->cleanText();
    QString yiner = ui->spinBox_3->cleanText();
    QString str=QString("%1 成人 %2 儿童 %3 婴儿").arg(chenren).arg(ertong).arg(yiner);
    QFont labelFont;
    labelFont.setPointSize(10);
    labelFont.setBold(true);
    ui->passenger->setFont(labelFont);
    ui->passenger->setText(str);
    updateCachedPassengerCount();
}

void FlightSearchWidget::on_comboBox_3_currentIndexChanged(int index)
{
    if(index==0){
        return ;
    }else{
        SortType sortType = static_cast<SortType>(index-1);
        flightManager.setFlightList(allGoingFlights);
        QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);

        refreshFlightList(ui->listWidgetGoing, sortedGoing);
    }
}

void FlightSearchWidget::on_dijia_clicked()
{
    ui->dijia->setStyleSheet("color: #007fff;");
    ui->ontime->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(7);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetGoing, sortedGoing);
}

void FlightSearchWidget::on_ontime_clicked()
{
    ui->dijia->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #000000;");
    ui->ontime->setStyleSheet("color: #007fff;");
    SortType sortType = static_cast<SortType>(6);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetGoing, sortedGoing);
}

void FlightSearchWidget::on_depart_clicked()
{
    ui->dijia->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #007fff;");
    ui->ontime->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(8);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetGoing, sortedGoing);
}

void FlightSearchWidget::on_comboBox_4_currentIndexChanged(int index)
{
    if(index==0){
        return ;
    }else{
        SortType sortType = static_cast<SortType>(index-1);
        flightManager.setFlightList(allReturnFlights);
        QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
        refreshFlightList(ui->listWidgetReturn, sortedReturn);
    }
}

void FlightSearchWidget::on_dijia_2_clicked()
{
    ui->dijia_2->setStyleSheet("color: #007fff;");
    ui->ontime_2->setStyleSheet("color: #000000;");
    ui->depart_2->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(7);
    flightManager.setFlightList(allReturnFlights);
    QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetReturn, sortedReturn);
}

void FlightSearchWidget::on_ontime_2_clicked()
{
    ui->dijia_2->setStyleSheet("color: #000000;");
    ui->depart_2->setStyleSheet("color: #000000;");
    ui->ontime_2->setStyleSheet("color: #007fff;");
    SortType sortType = static_cast<SortType>(6);
    flightManager.setFlightList(allReturnFlights);
    QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetReturn, sortedReturn);
}

void FlightSearchWidget::on_depart_2_clicked()
{
    ui->dijia_2->setStyleSheet("color: #000000;");
    ui->depart_2->setStyleSheet("color: #007fff;");
    ui->ontime_2->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(8);
    flightManager.setFlightList(allReturnFlights);
    QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetReturn, sortedReturn);
}

void FlightSearchWidget::on_radioOneWay_clicked()
{
    ui->widget_4->setVisible(false);
    updateTabWidget2PageCount(false);
}

void FlightSearchWidget::on_radioRoundTrip_clicked()
{
    ui->widget_4->setVisible(true);
    updateTabWidget2PageCount(true);
}

void FlightSearchWidget::on_comboBox_currentIndexChanged(int index)
{
    QListWidget *listWidget = ui->listWidgetGoing;
    int count = listWidget->count();

    for (int i = 0; i < count; ++i) {
        QListWidgetItem *item = listWidget->item(i);
        FlightItemWidget *flightWidget = qobject_cast<FlightItemWidget*>(listWidget->itemWidget(item));
        if (!flightWidget) continue;

        flightWidget->updateCabinPrice(index);
    }
}

void FlightSearchWidget::on_btnSearch_2_clicked()
{
    // 检查是否选择了日期
    QDate flightDate = getOtherDate();
    if (!flightDate.isValid()) {
        QMessageBox::warning(this, "提示", "请选择日期！");
        return;
    }
    
    QString flightNo = ui->lineEdit_3->text().trimmed();

    if(ui->radioButton_4->isChecked()){
        if (flightNo.isEmpty()) {
            QMessageBox::warning(this, "查询提示", "请输入航班号！");
            return;
        }

        ui->listWidgetGoing->clear();
        ui->tabWidget_2->setTabVisible(1, false);

        // 更新全局航班列表变量
        allGoingFlights = queryFlights(0,1);
        addFlightsToWidget(ui->listWidgetGoing, allGoingFlights);

        if (allGoingFlights.isEmpty()) {
            QListWidgetItem *emptyItem = new QListWidgetItem(QString("暂无%1日期的%2去程航班").arg(flightDate.toString("yyyy-MM-dd")).arg(flightNo));
            emptyItem->setTextAlignment(Qt::AlignCenter);
            ui->listWidgetGoing->addItem(emptyItem);
        }
    }else if(ui->radioButton_5->isChecked()){

        ui->listWidgetGoing->clear();
        ui->tabWidget_2->setTabVisible(1, false);

        // 更新全局航班列表变量
        allGoingFlights = queryFlights(0,3);
        addFlightsToWidget(ui->listWidgetGoing, allGoingFlights);

        QString departCity = getDepartCity_2();
        QString arriveCity = getArriveCity_2();

        if (allGoingFlights.isEmpty()) {
            QListWidgetItem *emptyItem = new QListWidgetItem(QString("暂无%1日期的%2飞往%3的去程航班").arg(flightDate.toString("yyyy-MM-dd")).arg(departCity).arg(arriveCity));
            emptyItem->setTextAlignment(Qt::AlignCenter);
            ui->listWidgetGoing->addItem(emptyItem);
        }
    }
}

void FlightSearchWidget::on_radioButton_5_toggled(bool checked)
{
    if(checked){
        ui->stackedWidget->setCurrentIndex(1);

    }else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void FlightSearchWidget::on_pushButton_3_clicked()
{
    QString departCity = "北京";
    QString arriveCity = "上海";
    QString oldFlightNo = "MF8340";
    QDate oldFlightDate = QDate::currentDate();

    ChangeTicketWidget* changeticketwidget = new ChangeTicketWidget(departCity, arriveCity, oldFlightNo, oldFlightDate);
    changeticketwidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    changeticketwidget->show();

    changeticketwidget->activateWindow();
}

QList<FlightInfo> FlightSearchWidget::getGoingFlights()
{
    return allGoingFlights;
}

QList<FlightInfo> FlightSearchWidget::getReturnFlights()
{
    return allReturnFlights;
}

void FlightSearchWidget::showInitialMessage()
{
    // 在去程航班列表中显示提示信息
    QListWidgetItem *goingItem = new QListWidgetItem("请输入出发地、目的地和出发日期，然后点击搜索按钮查找航班");
    goingItem->setTextAlignment(Qt::AlignCenter);
    goingItem->setForeground(QColor(128, 128, 128)); // 灰色文字
    ui->listWidgetGoing->addItem(goingItem);
    
    // 在返程航班列表中显示提示信息
    QListWidgetItem *returnItem = new QListWidgetItem("请先搜索去程航班");
    returnItem->setTextAlignment(Qt::AlignCenter);
    returnItem->setForeground(QColor(128, 128, 128)); // 灰色文字
    ui->listWidgetReturn->addItem(returnItem);
}

// 从数据库加载所有城市
QStringList FlightSearchWidget::loadCitiesFromDatabase()
{
    QSet<QString> citySet; // 使用Set自动去重
    
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        qWarning() << "数据库连接无效，无法加载城市列表";
        return QStringList();
    }
    
    // 查询所有9个航班批次表
    for (int batchNum = 1; batchNum <= 9; batchNum++) {
        QString tableName = QString("flights_batch_%1").arg(batchNum, 3, 10, QChar('0'));
        
        // 查询出发城市
        QString sql = QString("SELECT DISTINCT 出发城市 FROM %1 WHERE 出发城市 IS NOT NULL AND 出发城市 != ''").arg(tableName);
        QSqlQuery query(db);
        
        if (query.exec(sql)) {
            while (query.next()) {
                QString city = query.value(0).toString().trimmed();
                if (!city.isEmpty()) {
                    citySet.insert(city);
                }
            }
        } else {
            qWarning() << "查询出发城市失败：" << query.lastError().text();
        }
        
        // 查询到达城市
        sql = QString("SELECT DISTINCT 到达城市 FROM %1 WHERE 到达城市 IS NOT NULL AND 到达城市 != ''").arg(tableName);
        query.clear();
        
        if (query.exec(sql)) {
            while (query.next()) {
                QString city = query.value(0).toString().trimmed();
                if (!city.isEmpty()) {
                    citySet.insert(city);
                }
            }
        } else {
            qWarning() << "查询到达城市失败：" << query.lastError().text();
        }
    }
    
    // 转换为排序的列表
    QStringList cities = citySet.values();
    cities.sort();
    
    qDebug() << "加载了" << cities.size() << "个城市";
    
    return cities;
}

// 创建城市自动补全器
QCompleter* FlightSearchWidget::createCityCompleter(const QStringList& cities)
{
    QCompleter* completer = new QCompleter(cities, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive); // 不区分大小写
    completer->setFilterMode(Qt::MatchContains); // 包含匹配
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion); // 未过滤的弹出补全列表
    completer->setMaxVisibleItems(15); // 最多显示15个选项
    
    // 设置弹出窗口的样式
    QListView* popup = qobject_cast<QListView*>(completer->popup());
    if (popup) {
        popup->setStyleSheet(
            "QListView {"
            "    border: 1px solid #cccccc;"
            "    background-color: white;"
            "    selection-background-color: #e3f2fd;"
            "    selection-color: #000000;"
            "    font-size: 12px;"
            "    padding: 2px;"
            "}"
            "QListView::item {"
            "    height: 25px;"
            "    padding-left: 5px;"
            "}"
            "QListView::item:hover {"
            "    background-color: #f5f5f5;"
            "}"
        );
    }
    
    return completer;
}

// 为所有城市输入框设置自动补全
void FlightSearchWidget::setupCityCompleters()
{
    if (m_cities.isEmpty()) {
        qWarning() << "城市列表为空，无法设置自动补全";
        return;
    }
    
    // 为国内/国际航班搜索的出发地和目的地设置自动补全
    QCompleter* departCompleter = createCityCompleter(m_cities);
    ui->lineEdit_Depart->setCompleter(departCompleter);
    ui->lineEdit_Depart->installEventFilter(this);
    
    QCompleter* arriveCompleter = createCityCompleter(m_cities);
    ui->lineEdit_Arrive->setCompleter(arriveCompleter);
    ui->lineEdit_Arrive->installEventFilter(this);
    
    // 为航班动态搜索的出发地和目的地设置自动补全
    QCompleter* departCompleter2 = createCityCompleter(m_cities);
    ui->lineEdit_Depart_2->setCompleter(departCompleter2);
    ui->lineEdit_Depart_2->installEventFilter(this);
    
    QCompleter* arriveCompleter2 = createCityCompleter(m_cities);
    ui->lineEdit_Arrive_2->setCompleter(arriveCompleter2);
    ui->lineEdit_Arrive_2->installEventFilter(this);
    
    qDebug() << "城市自动补全设置完成";
}


// 个人中心点击事件
void FlightSearchWidget::on_label_5_clicked()
{
    PersonCenterWindow* personCenter = new PersonCenterWindow();
    personCenter->setUserId(m_currentUserId);  // 设置用户ID
    personCenter->setAttribute(Qt::WA_DeleteOnClose);
    personCenter->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    personCenter->show();
    personCenter->activateWindow();
}

// 我的订单点击事件
void FlightSearchWidget::on_label_3_clicked()
{
    MyOrderDialog* myOrder = new MyOrderDialog(m_currentUserId);  // 传入用户ID
    myOrder->setAttribute(Qt::WA_DeleteOnClose);
    myOrder->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    myOrder->show();
    myOrder->activateWindow();
}

// 根据航空公司名称获取对应的 logo
QString FlightSearchWidget::getAirlineLogo(const QString& airlineName)
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
