#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->tabWidget_2->setTabVisible(1, false);
    ui->widget_4->setVisible(false);

    db = QSqlDatabase::database("plane_db_conn"); // 传入之前定义的连接名

    // 检查连接是否有效（可选，避免连接意外断开）
    if (!db.isOpen()) {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，正在尝试重新连接……");
        if (!db.open()) { // 尝试重新打开
            QMessageBox::critical(this, "连接失败", "重连数据库失败：" + db.lastError().text());
            return;
        }
    }else{
        QMessageBox::information(this,"连接提示","连接成功");
    }

    ui->passengerWidget->hide();
    ui->calendarWidget->hide();
    ui->calendarWidget_2->hide();

    qApp->installEventFilter(this);

    QList<QWidget*> widgetList = {
        ui->widget,
        ui->widget_5,
        ui->widget_2,
        ui->widget_3,
        ui->widget_4
    };
    foreach (QWidget *w, widgetList) {

        w->installEventFilter(this);
        QList<QLineEdit*> edits = w->findChildren<QLineEdit*>();
        foreach (QLineEdit *e, edits) {
            e->installEventFilter(this);
        }
    }


    // 加载去程和返程航班

    allGoingFlights = queryFlights(0);
    allReturnFlights = queryFlights(1);
    addFlightsToWidget(ui->listWidgetGoing, allGoingFlights);
    addFlightsToWidget(ui->listWidgetReturn, allReturnFlights);

}

void MainWindow::updateTabWidget2PageCount(bool hasReturnFlight)
{
    ui->tabWidget_2->setTabVisible(1, hasReturnFlight);

    if (!hasReturnFlight && ui->tabWidget_2->currentIndex() == 1) {
        ui->tabWidget_2->setCurrentIndex(0);
    }
}



QList<FlightInfo> MainWindow::queryFlights(int flightType)
{
    QList<FlightInfo> flights;
    QSqlQuery query(db);
    query.clear();

    // 基础SQL（添加日期和城市筛选）
    QString sql = "SELECT logo_path, airline, flight_no, plane_type, depart_time, "
                  "arrive_time, is_next_day, depart_airport, arrive_airport, "
                  "price,on_time_rate,price_int,duration ,is_next_day,"
                  "economy_price, economy_remain,business_price,business_remain,first_price,first_remain,remain_tickets FROM flight_info WHERE flight_type = ? ";

    // 1. 添加出发地/目的地筛选（如果输入了内容）
    QString departCity = getDepartCity();
    QString arriveCity = getArriveCity();
    if (!departCity.isEmpty()) {
        sql += "AND depart_city = ? ";
    }
    if (!arriveCity.isEmpty()) {
        sql += "AND arrive_city = ? ";
    }

    // 2. 添加日期筛选（航班日期字段需提前在数据库中存在）
    QDate departDate = getDepartDate();
    if (departDate.isValid()) {
        sql += "AND flight_date = ? ";
    }

    // 3. 绑定参数
    if (!query.prepare(sql)) {
        qCritical() << "Prepare失败：" << query.lastError().text();
        return flights;
    }

    int paramIndex = 0;
    query.bindValue(paramIndex++, flightType); // 绑定flight_type
    if (!departCity.isEmpty()) {
        query.bindValue(paramIndex++, departCity);
    }
    if (!arriveCity.isEmpty()) {
        query.bindValue(paramIndex++, arriveCity);
    }
    if (departDate.isValid()) {
        query.bindValue(paramIndex++, departDate.toString("yyyy-MM-dd"));
    }

    // 执行查询（后续逻辑不变）
    if (!query.exec()) {
        qCritical() << "查询失败：" << query.lastError().text();
        return flights;
    }

    while (query.next()) {
        FlightInfo info;
        info.logo = query.value(0).toString();
        info.airline = query.value(1).toString();
        info.flightNo = query.value(2).toString();
        info.planeType = query.value(3).toString();
        info.departTime = query.value(4).toString();
        info.arriveTime = query.value(5).toString();
        info.isNextDay = query.value(6).toBool();
        info.departAirport = query.value(7).toString();
        info.arriveAirport = query.value(8).toString();
        info.price = query.value(9).toString();
        info.onTimeRate=query.value(10).toInt();
        info.price_int=query.value(11).toInt();
        info.duration=query.value(12).toInt();
        info.isNextDay=query.value(13).toInt();
        info.economyPrice = query.value(14).toInt();  // economy_price的索引（根据实际表结构调整）
        info.economyRemain = query.value(15).toInt();
        info.businessPrice = query.value(16).toInt();
        info.businessRemain = query.value(17).toInt();
        info.firstPrice = query.value(18).toInt();
        info.firstRemain = query.value(19).toInt();
        info.remain = query.value(20).toInt();
        flights.append(info);
    }

    return flights;
}

void MainWindow::addFlightsToWidget(QListWidget *listWidget, const QList<FlightInfo> &flights)
{
    listWidget->clear(); // 清空列表
    foreach (const FlightInfo& info, flights) {
        QListWidgetItem *item = new QListWidgetItem(listWidget);
        item->setSizeHint(QSize(0, 80)); // 固定项高度

        FlightItemWidget *flightWidget = new FlightItemWidget();
        flightWidget->setFlightInfo(info); // 设置航班信息
        listWidget->setItemWidget(item, flightWidget);

    }
}

void MainWindow::refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights)
{
    addFlightsToWidget(listWidget, flights); // 复用原有添加逻辑
    // 空数据提示
    if (flights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        listWidget->addItem(emptyItem);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->calendarWidget || ui->calendarWidget->isAncestorOf(qobject_cast<QWidget*>(watched))) {
        return false; // 让事件正常传递给日历
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
                }
                else if (targetWidget == ui->widget_2) {
                    ui->label_7->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                }
                else if (targetWidget == ui->widget_3) {
                    ui->label_8->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->calendarWidget->show();
                }
                else if (targetWidget == ui->widget_4) {
                    ui->label_9->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_10->setStyleSheet("color: #000000;");
                    ui->calendarWidget_2->show();
                }
                else if (targetWidget == ui->widget_5) {
                    ui->passengerWidget->show();
                    ui->label_10->setStyleSheet("color: #007fff;");
                    ui->label_6->setStyleSheet("color: #000000;");
                    ui->label_7->setStyleSheet("color: #000000;");
                    ui->label_8->setStyleSheet("color: #000000;");
                    ui->label_9->setStyleSheet("color: #000000;");
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
                if (ui->widget_3) { // 确保触发控件非空
                    // 日历的全局区域
                    QRect calendarRect = ui->calendarWidget->geometry();
                    calendarRect.moveTopLeft(ui->calendarWidget->mapToGlobal(QPoint(0, 0)));

                    // widget_3的全局区域
                    QRect widget3Rect = ui->widget_3->geometry();
                    widget3Rect.moveTopLeft(ui->widget_3->mapToGlobal(QPoint(0, 0)));

                    QPoint clickPos = mouseEvent->globalPosition().toPoint();

                    // 点击不在日历内，且不在widget_3/widget_4内 → 隐藏
                    if (!calendarRect.contains(clickPos) && !widget3Rect.contains(clickPos) ) {
                        ui->calendarWidget->hide();
                    }
                }
            }

            if (ui->calendarWidget_2 && ui->calendarWidget_2->isVisible()) {
                if (ui->widget_4) { // 确保触发控件非空
                    // 日历的全局区域
                    QRect calendarRect = ui->calendarWidget_2->geometry();
                    calendarRect.moveTopLeft(ui->calendarWidget_2->mapToGlobal(QPoint(0, 0)));


                    // widget_4的全局区域
                    QRect widget4Rect = ui->widget_4->geometry();
                    widget4Rect.moveTopLeft(ui->widget_4->mapToGlobal(QPoint(0, 0)));

                    // 全局点击位置（和passengerWidget用一样的API）
                    QPoint clickPos = mouseEvent->globalPosition().toPoint();

                    // 点击不在日历内，且不在widget_3/widget_4内 → 隐藏
                    if (!calendarRect.contains(clickPos)&& !widget4Rect.contains(clickPos)) {
                        ui->calendarWidget_2->hide();
                    }
                }
            }
        }
    }
    return false;
}


QString MainWindow::getDepartCity() {
    return ui->lineEdit_Depart->text().trimmed(); // 替换为你实际的出发地输入框名
}

QString MainWindow::getArriveCity() {
    return ui->lineEdit_Arrive->text().trimmed(); // 替换为你实际的目的地输入框名
}

QDate MainWindow::getDepartDate() {
    QString dateText = ui->dateDepart->text().split(" ")[0];
    return QDate::fromString(dateText, "yyyy-MM-dd");
}

QDate MainWindow::getReturnDate() {
    QString dateText = ui->dateReturn->text().split(" ")[0];
    return QDate::fromString(dateText, "yyyy-MM-dd");
}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QString dateStr = date.toString("yyyy-MM-dd");

    // 2. 获取星期几（Qt::DayOfWeek枚举转换为中文）
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

    // 3. 拼接完整文本并设置到Label
    QString fullText = QString("%1 %2").arg(dateStr).arg(weekStr);
    ui->dateDepart->setText(fullText); // 替换为你的Label名称
}


void MainWindow::on_calendarWidget_2_clicked(const QDate &date)
{
    QString dateStr = date.toString("yyyy-MM-dd");

    // 2. 获取星期几（Qt::DayOfWeek枚举转换为中文）
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

    // 3. 拼接完整文本并设置到Label
    QString fullText = QString("%1 %2").arg(dateStr).arg(weekStr);
    ui->dateReturn->setText(fullText);
}


void MainWindow::on_btnSearch_clicked()
{
    ui->listWidgetGoing->clear();
    ui->listWidgetReturn->clear();

    QList<FlightInfo> goingFlights = queryFlights(0);
    addFlightsToWidget(ui->listWidgetGoing, goingFlights);

    QList<FlightInfo> returnFlights = queryFlights(1);
    addFlightsToWidget(ui->listWidgetReturn, returnFlights);

    if (goingFlights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的去程航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->listWidgetGoing->addItem(emptyItem);
    }
    if (returnFlights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的返程航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->listWidgetReturn->addItem(emptyItem);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->passengerWidget->hide();
}


void MainWindow::on_pushButton_clicked()
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
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
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


void MainWindow::on_dijia_clicked()
{
    ui->dijia->setStyleSheet("color: #007fff;");
    ui->ontime->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(7);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetGoing, sortedGoing);
}


void MainWindow::on_ontime_clicked()
{
    ui->dijia->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #000000;");
    ui->ontime->setStyleSheet("color: #007fff;");
    SortType sortType = static_cast<SortType>(6);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetGoing, sortedGoing);
}


void MainWindow::on_depart_clicked()
{
    ui->dijia->setStyleSheet("color: #000000;");
    ui->depart->setStyleSheet("color: #007fff;");
    ui->ontime->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(8);
    flightManager.setFlightList(allGoingFlights);
    QList<FlightInfo> sortedGoing = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetGoing, sortedGoing);
}


void MainWindow::on_comboBox_4_currentIndexChanged(int index)
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


void MainWindow::on_dijia_2_clicked()
{
    ui->dijia_2->setStyleSheet("color: #007fff;");
    ui->ontime_2->setStyleSheet("color: #000000;");
    ui->depart_2->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(7);
    flightManager.setFlightList(allReturnFlights);
    QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetReturn, sortedReturn);
}


void MainWindow::on_ontime_2_clicked()
{
    ui->dijia_2->setStyleSheet("color: #000000;");
    ui->depart_2->setStyleSheet("color: #000000;");
    ui->ontime_2->setStyleSheet("color: #007fff;");
    SortType sortType = static_cast<SortType>(6);
    flightManager.setFlightList(allReturnFlights);
    QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetReturn, sortedReturn);
}


void MainWindow::on_depart_2_clicked()
{
    ui->dijia_2->setStyleSheet("color: #000000;");
    ui->depart_2->setStyleSheet("color: #007fff;");
    ui->ontime_2->setStyleSheet("color: #000000;");
    SortType sortType = static_cast<SortType>(8);
    flightManager.setFlightList(allReturnFlights);
    QList<FlightInfo> sortedReturn = flightManager.sortFlights(sortType);
    refreshFlightList(ui->listWidgetReturn, sortedReturn);
}


void MainWindow::on_radioOneWay_clicked()
{
    ui->widget_4->setVisible(false);
    updateTabWidget2PageCount(false);
}


void MainWindow::on_radioRoundTrip_clicked()
{
    ui->widget_4->setVisible(true);
    updateTabWidget2PageCount(true);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // 下拉框规则：0=不限，1=经济，2=公务，3=头等 → 直接传递index
    QListWidget *listWidget = ui->listWidgetGoing;
    int count = listWidget->count();

    // 遍历所有航班项更新价格/余票
    for (int i = 0; i < count; ++i) {
        QListWidgetItem *item = listWidget->item(i);
        FlightItemWidget *flightWidget = qobject_cast<FlightItemWidget*>(listWidget->itemWidget(item));
        if (!flightWidget) continue; // 空指针防护

        // 直接传递下拉框index（完全匹配舱位规则）
        flightWidget->updateCabinPrice(index);
    }
}

