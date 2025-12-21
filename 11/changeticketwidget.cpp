#include "changeticketwidget.h"
#include "ui_changeticketwidget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QSqlError>
#include "FlightDetailWidget.h"

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
{
    ui->setupUi(this);
    m_db = QSqlDatabase::database("plane_db_conn");
    if (!m_db.isOpen()) {
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

    ui->lblDepart->setText(QString("%1").arg(m_departCity));
    ui->lblArrive->setText(QString("%1").arg(m_arriveCity));
    ui->lblOldFlight->setText(QString("%1 %2").arg(m_oldFlightNo).arg(m_oldFlightDate.toString("yyyy-MM-dd")));
    QDate defaultDate = m_oldFlightDate.addDays(1);

    ui->calendarWidget->setVisible(false);
    allGoingFlights = queryFlights(0,2);
    on_btnSearch_clicked();
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
    QSqlQuery query(m_db);
    query.clear();

    QString sql = "SELECT logo_path, airline, flight_no, plane_type, depart_time, "
                  "arrive_time, is_next_day, depart_airport, arrive_airport, "
                  "price,on_time_rate,price_int,duration ,is_next_day,"
                  "economy_price, economy_remain,business_price,business_remain,first_price,first_remain,remain_tickets FROM flight_info WHERE flight_type = ? ";

    if(type==2){
        if (!m_departCity.isEmpty()) {
            sql += "AND depart_city = ? ";
        }
        if (!m_arriveCity.isEmpty()) {
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
        if (!m_departCity.isEmpty()) {
            query.bindValue(paramIndex++, m_departCity);
        }
        if (!m_arriveCity.isEmpty()) {
            query.bindValue(paramIndex++, m_arriveCity);
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
    }

    return flights;
}

void ChangeTicketWidget::addFlightsToWidget(QListWidget* listWidget, const QList<FlightInfo>& flights)
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
    QString dateText = ui->lineEditDate->text().split(" ")[0];
    return QDate::fromString(dateText, "yyyy-MM-dd");
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
    ui->calendarWidget->hide();
    ui->lineEditDate->setText(fullText);
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
