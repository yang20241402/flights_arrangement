#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "changeticketwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->tabWidget_2->setTabVisible(1, false);
    ui->tabWidget->setCurrentIndex(0);
    ui->widget_4->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);

    db = QSqlDatabase::database("plane_db_conn");

    if (!db.isOpen()) {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，正在尝试重新连接……");
        if (!db.open()) {
            QMessageBox::critical(this, "连接失败", "重连数据库失败：" + db.lastError().text());
            return;
        }
    }else{
        QMessageBox::information(this,"连接提示","连接成功");
    }

    ui->passengerWidget->hide();
    ui->calendarWidget->hide();
    ui->calendarWidget_2->hide();
    ui->calendarWidget_3->hide();

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

    allGoingFlights = queryFlights(0,2);
    allReturnFlights = queryFlights(1,2);
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

QList<FlightInfo> MainWindow::queryFlights(int flightType,int type)
{
    QList<FlightInfo> flights;
    QSqlQuery query(db);
    query.clear();

    QString sql = "SELECT logo_path, airline, flight_no, plane_type, depart_time, "
                  "arrive_time, is_next_day, depart_airport, arrive_airport, "
                  "price,on_time_rate,price_int,duration ,is_next_day,"
                  "economy_price, economy_remain,business_price,business_remain,first_price,first_remain,remain_tickets FROM flight_info WHERE flight_type = ? ";

    if(type==1){
        QString flightNo = getflightNo();

        if (!flightNo.isEmpty()) {
            sql += "AND flight_no = ? ";
        }

        QDate otherDate = getOtherDate();
        if (otherDate.isValid()) {
            sql += "AND flight_date = ? ";
        }

        if (!query.prepare(sql)) {
            qCritical() << "Prepare失败：" << query.lastError().text();
            return flights;
        }

        int paramIndex = 0;
        query.bindValue(paramIndex++, flightType);
        if (!flightNo.isEmpty()) {
            query.bindValue(paramIndex++, flightNo);
        }
        if (!otherDate.isValid()) {
            query.bindValue(paramIndex++, otherDate);
        }

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
            info.economyPrice = query.value(14).toInt();
            info.economyRemain = query.value(15).toInt();
            info.businessPrice = query.value(16).toInt();
            info.businessRemain = query.value(17).toInt();
            info.firstPrice = query.value(18).toInt();
            info.firstRemain = query.value(19).toInt();
            info.remain = query.value(20).toInt();
            flights.append(info);
        }
        return flights;

    }else if(type==2){
        QString departCity = getDepartCity();
        QString arriveCity = getArriveCity();
        if (!departCity.isEmpty()) {
            sql += "AND depart_city = ? ";
        }
        if (!arriveCity.isEmpty()) {
            sql += "AND arrive_city = ? ";
        }

        QDate departDate = getDepartDate();
        if (departDate.isValid()) {
            sql += "AND flight_date = ? ";
        }

        if (!query.prepare(sql)) {
            qCritical() << "Prepare失败：" << query.lastError().text();
            return flights;
        }

        int paramIndex = 0;
        query.bindValue(paramIndex++, flightType);
        if (!departCity.isEmpty()) {
            query.bindValue(paramIndex++, departCity);
        }
        if (!arriveCity.isEmpty()) {
            query.bindValue(paramIndex++, arriveCity);
        }
        if (departDate.isValid()) {
            query.bindValue(paramIndex++, departDate.toString("yyyy-MM-dd"));
        }

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
            info.economyPrice = query.value(14).toInt();
            info.economyRemain = query.value(15).toInt();
            info.businessPrice = query.value(16).toInt();
            info.businessRemain = query.value(17).toInt();
            info.firstPrice = query.value(18).toInt();
            info.firstRemain = query.value(19).toInt();
            info.remain = query.value(20).toInt();
            flights.append(info);
        }

        int validPassengerCount = getValidPassengerCount();
        QList<FlightInfo> filteredFlights;
        for (const auto& flight : flights) {
            if (flight.remain >= validPassengerCount) {
                filteredFlights.append(flight);
            }
        }

        return filteredFlights;
    }else if(type==3){
        QString departCity = getDepartCity_2();
        QString arriveCity = getArriveCity_2();
        if (!departCity.isEmpty()) {
            sql += "AND depart_city = ? ";
        }
        if (!arriveCity.isEmpty()) {
            sql += "AND arrive_city = ? ";
        }

        QDate othertDate = getOtherDate();
        if (othertDate.isValid()) {
            sql += "AND flight_date = ? ";
        }

        if (!query.prepare(sql)) {
            qCritical() << "Prepare失败：" << query.lastError().text();
            return flights;
        }

        int paramIndex = 0;
        query.bindValue(paramIndex++, flightType);
        if (!departCity.isEmpty()) {
            query.bindValue(paramIndex++, departCity);
        }
        if (!arriveCity.isEmpty()) {
            query.bindValue(paramIndex++, arriveCity);
        }
        if (othertDate.isValid()) {
            query.bindValue(paramIndex++, othertDate.toString("yyyy-MM-dd"));
        }

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
            info.economyPrice = query.value(14).toInt();
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

}

void MainWindow::addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights)
{
    listWidget->clear();
    for (const auto& flight : flights) {
        FlightItemWidget* itemWidget = new FlightItemWidget;
        itemWidget->setFlightInfo(flight);

        connect(itemWidget, &FlightItemWidget::clicked, this, [=](const FlightInfo& info) {
            FlightDetailWidget* detailWidget = new FlightDetailWidget(info, this);
            detailWidget->show();
        });

        QListWidgetItem *item = new QListWidgetItem(listWidget);
        item->setSizeHint(QSize(0, 80));

        FlightItemWidget *flightWidget = new FlightItemWidget();
        flightWidget->setFlightInfo(flight);
        listWidget->setItemWidget(item, flightWidget);
    }
}

void MainWindow::refreshFlightList(QListWidget *listWidget, const QList<FlightInfo> &flights)
{
    addFlightsToWidget(listWidget, flights);
    if (flights.isEmpty()) {
        QListWidgetItem *emptyItem = new QListWidgetItem("暂无符合条件的航班");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        listWidget->addItem(emptyItem);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
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

QString MainWindow::getDepartCity() {
    return ui->lineEdit_Depart->text().trimmed();
}

QString MainWindow::getArriveCity() {
    return ui->lineEdit_Arrive->text().trimmed();
}

QString MainWindow::getflightNo() {
    return ui->lineEdit_3->text().trimmed();
}

QDate MainWindow::getDepartDate() {
    QString dateText = ui->dateDepart->text().split(" ")[0];
    return QDate::fromString(dateText, "yyyy-MM-dd");
}

QDate MainWindow::getReturnDate() {
    QString dateText = ui->dateReturn->text().split(" ")[0];
    return QDate::fromString(dateText, "yyyy-MM-dd");
}

QDate MainWindow::getOtherDate() {
    QString dateText = ui->dateDepart_2->text().split(" ")[0];
    return QDate::fromString(dateText, "yyyy-MM-dd");
}

QString MainWindow::getDepartCity_2() {
    return ui->lineEdit_Depart_2->text().trimmed();
}

QString MainWindow::getArriveCity_2() {
    return ui->lineEdit_Arrive_2->text().trimmed();
}

int MainWindow::getValidPassengerCount()
{
    return m_cachedValidPassengerCount;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCachedPassengerCount()
{
    int adultCount = ui->spinBox->value();
    int childCount = ui->spinBox_2->value();
    int validCount = adultCount + childCount;
    m_cachedValidPassengerCount = validCount > 0 ? validCount : 1;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
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

void MainWindow::on_calendarWidget_2_clicked(const QDate &date)
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

void MainWindow::on_calendarWidget_3_clicked(const QDate &date)
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

void MainWindow::on_btnSearch_clicked()
{
    ui->listWidgetGoing->clear();
    ui->listWidgetReturn->clear();

    QList<FlightInfo> goingFlights = queryFlights(0,2);
    addFlightsToWidget(ui->listWidgetGoing, goingFlights);

    QList<FlightInfo> returnFlights = queryFlights(1,2);
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
    updateCachedPassengerCount();
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
    QListWidget *listWidget = ui->listWidgetGoing;
    int count = listWidget->count();

    for (int i = 0; i < count; ++i) {
        QListWidgetItem *item = listWidget->item(i);
        FlightItemWidget *flightWidget = qobject_cast<FlightItemWidget*>(listWidget->itemWidget(item));
        if (!flightWidget) continue;

        flightWidget->updateCabinPrice(index);
    }
}

void MainWindow::on_btnSearch_2_clicked()
{
    QString flightNo = ui->lineEdit_3->text().trimmed();
    QDate flightDate = getOtherDate();

    if(ui->radioButton_4->isChecked()){
        if (flightNo.isEmpty()) {
            QMessageBox::warning(this, "查询提示", "请输入航班号！");
            return;
        }

        ui->listWidgetGoing->clear();
        ui->tabWidget_2->setTabVisible(1, false);

        QList<FlightInfo> goingFlights = queryFlights(0,1);
        addFlightsToWidget(ui->listWidgetGoing, goingFlights);

        if (goingFlights.isEmpty()) {
            QListWidgetItem *emptyItem = new QListWidgetItem(QString("暂无%1日期的%2去程航班").arg(flightDate.toString("yyyy-MM-dd")).arg(flightNo));
            emptyItem->setTextAlignment(Qt::AlignCenter);
            ui->listWidgetGoing->addItem(emptyItem);
        }
    }else if(ui->radioButton_5->isChecked()){

        ui->listWidgetGoing->clear();
        ui->tabWidget_2->setTabVisible(1, false);

        QList<FlightInfo> goingFlights = queryFlights(0,3);
        addFlightsToWidget(ui->listWidgetGoing, goingFlights);

        QString departCity = getDepartCity_2();
        QString arriveCity = getArriveCity_2();

        if (goingFlights.isEmpty()) {
            QListWidgetItem *emptyItem = new QListWidgetItem(QString("暂无%1日期的%2飞往%3的去程航班").arg(flightDate.toString("yyyy-MM-dd")).arg(departCity).arg(arriveCity));
            emptyItem->setTextAlignment(Qt::AlignCenter);
            ui->listWidgetGoing->addItem(emptyItem);
        }
    }
}

void MainWindow::on_radioButton_5_toggled(bool checked)
{
    if(checked){
        ui->stackedWidget->setCurrentIndex(1);

    }else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString departCity = "北京";
    QString arriveCity = "上海";
    QString oldFlightNo = "MF8340";
    QDate oldFlightDate = QDate::currentDate();

    ChangeTicketWidget *changeticketwidget = new ChangeTicketWidget(departCity, arriveCity, oldFlightNo, oldFlightDate, this);

    changeticketwidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    changeticketwidget->show();

    changeticketwidget->activateWindow();
}
