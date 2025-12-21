/********************************************************************************
** Form generated from reading UI file 'flightdetailwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTDETAILWIDGET_H
#define UI_FLIGHTDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightDetailWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *contentLayout;
    QVBoxLayout *baseInfoLayout;
    QLabel *baseTitleLabel;
    QGridLayout *baseGridLayout;
    QLabel *flightIdKeyLabel;
    QLabel *lbFlightId;
    QLabel *flightNoKeyLabel;
    QLabel *lbFlightNo;
    QLabel *airlineKeyLabel;
    QLabel *lbAirline;
    QLabel *planeTypeKeyLabel;
    QLabel *lbPlaneType;
    QLabel *flightTypeKeyLabel;
    QLabel *lbFlightType;
    QLabel *flightDateKeyLabel;
    QLabel *lbFlightDate;
    QVBoxLayout *departArriveLayout;
    QLabel *routeTitleLabel;
    QHBoxLayout *routeHLayout;
    QVBoxLayout *departLayout;
    QLabel *departTitleLabel;
    QLabel *lbDepartCity;
    QLabel *lbDepartAirport;
    QLabel *lbDepartTime;
    QVBoxLayout *arrowLayout;
    QLabel *arrowLabel;
    QLabel *lbDuration;
    QLabel *lbIsNextDay;
    QVBoxLayout *arriveLayout;
    QLabel *arriveTitleLabel;
    QLabel *lbArriveCity;
    QLabel *lbArriveAirport;
    QLabel *lbArriveTime;
    QVBoxLayout *priceSeatLayout;
    QLabel *priceTitleLabel;
    QGridLayout *priceSeatGridLayout;
    QLabel *priceKeyLabel;
    QLabel *lbPrice;
    QLabel *priceIntKeyLabel;
    QLabel *lbPriceInt;
    QLabel *economyPriceKeyLabel;
    QLabel *lbEconomyPrice;
    QLabel *businessPriceKeyLabel;
    QLabel *lbBusinessPrice;
    QLabel *firstPriceKeyLabel;
    QLabel *lbFirstPrice;
    QLabel *economyRemainKeyLabel;
    QLabel *lbEconomyRemain;
    QLabel *businessRemainKeyLabel;
    QLabel *lbBusinessRemain;
    QLabel *firstRemainKeyLabel;
    QLabel *lbFirstRemain;
    QLabel *remainTicketsKeyLabel;
    QLabel *lbRemainTickets;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *buttonLayout;
    QPushButton *reserveBtn;
    QPushButton *closeBtn;

    void setupUi(QDialog *FlightDetailWidget)
    {
        if (FlightDetailWidget->objectName().isEmpty())
            FlightDetailWidget->setObjectName("FlightDetailWidget");
        FlightDetailWidget->resize(1000, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(FlightDetailWidget->sizePolicy().hasHeightForWidth());
        FlightDetailWidget->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        FlightDetailWidget->setWindowIcon(icon);
        FlightDetailWidget->setModal(true);
        FlightDetailWidget->setWindowFlags(Qt::Dialog|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint);
        FlightDetailWidget->setMinimumSize(QSize(900, 700));
        verticalLayout = new QVBoxLayout(FlightDetailWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(24, 24, 24, 24);
        titleLabel = new QLabel(FlightDetailWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"       QLabel {\n"
"        font-size: 22px;\n"
"        font-weight: bold;\n"
"        color: #2D3748;\n"
"        padding-bottom: 12px;\n"
"        border-bottom: 2px solid #E2E8F0;\n"
"       }\n"
"      "));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        scrollArea = new QScrollArea(FlightDetailWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("\n"
"       QScrollArea {\n"
"        border: none;\n"
"       }\n"
"       QScrollBar:vertical {\n"
"        width: 8px;\n"
"        background: #F7FAFC;\n"
"        border-radius: 4px;\n"
"       }\n"
"       QScrollBar::handle:vertical {\n"
"        background: #CBD5E0;\n"
"        border-radius: 4px;\n"
"       }\n"
"       QScrollBar::handle:vertical:hover {\n"
"        background: #A0AEC0;\n"
"       }\n"
"      "));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 900, 600));
        contentLayout = new QVBoxLayout(scrollAreaWidgetContents);
        contentLayout->setSpacing(24);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        baseInfoLayout = new QVBoxLayout();
        baseInfoLayout->setObjectName("baseInfoLayout");
        baseTitleLabel = new QLabel(scrollAreaWidgetContents);
        baseTitleLabel->setObjectName("baseTitleLabel");
        baseTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"              QLabel {\n"
"               font-size: 16px;\n"
"               font-weight: 600;\n"
"               color: #2D3748;\n"
"               margin-bottom: 16px;\n"
"              }\n"
"             "));

        baseInfoLayout->addWidget(baseTitleLabel);

        baseGridLayout = new QGridLayout();
        baseGridLayout->setObjectName("baseGridLayout");
        baseGridLayout->setHorizontalSpacing(24);
        baseGridLayout->setVerticalSpacing(16);
        flightIdKeyLabel = new QLabel(scrollAreaWidgetContents);
        flightIdKeyLabel->setObjectName("flightIdKeyLabel");
        flightIdKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(flightIdKeyLabel, 0, 0, 1, 1);

        lbFlightId = new QLabel(scrollAreaWidgetContents);
        lbFlightId->setObjectName("lbFlightId");
        lbFlightId->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbFlightId, 0, 1, 1, 1);

        flightNoKeyLabel = new QLabel(scrollAreaWidgetContents);
        flightNoKeyLabel->setObjectName("flightNoKeyLabel");
        flightNoKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(flightNoKeyLabel, 0, 2, 1, 1);

        lbFlightNo = new QLabel(scrollAreaWidgetContents);
        lbFlightNo->setObjectName("lbFlightNo");
        lbFlightNo->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: 600;\n"
"                 color: #2B6CB0;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbFlightNo, 0, 3, 1, 1);

        airlineKeyLabel = new QLabel(scrollAreaWidgetContents);
        airlineKeyLabel->setObjectName("airlineKeyLabel");
        airlineKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(airlineKeyLabel, 1, 0, 1, 1);

        lbAirline = new QLabel(scrollAreaWidgetContents);
        lbAirline->setObjectName("lbAirline");
        lbAirline->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbAirline, 1, 1, 1, 1);

        planeTypeKeyLabel = new QLabel(scrollAreaWidgetContents);
        planeTypeKeyLabel->setObjectName("planeTypeKeyLabel");
        planeTypeKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(planeTypeKeyLabel, 1, 2, 1, 1);

        lbPlaneType = new QLabel(scrollAreaWidgetContents);
        lbPlaneType->setObjectName("lbPlaneType");
        lbPlaneType->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbPlaneType, 1, 3, 1, 1);

        flightTypeKeyLabel = new QLabel(scrollAreaWidgetContents);
        flightTypeKeyLabel->setObjectName("flightTypeKeyLabel");
        flightTypeKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(flightTypeKeyLabel, 2, 0, 1, 1);

        lbFlightType = new QLabel(scrollAreaWidgetContents);
        lbFlightType->setObjectName("lbFlightType");
        lbFlightType->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbFlightType, 2, 1, 1, 1);

        flightDateKeyLabel = new QLabel(scrollAreaWidgetContents);
        flightDateKeyLabel->setObjectName("flightDateKeyLabel");
        flightDateKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(flightDateKeyLabel, 2, 2, 1, 1);

        lbFlightDate = new QLabel(scrollAreaWidgetContents);
        lbFlightDate->setObjectName("lbFlightDate");
        lbFlightDate->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbFlightDate, 2, 3, 1, 1);


        baseInfoLayout->addLayout(baseGridLayout);


        contentLayout->addLayout(baseInfoLayout);

        departArriveLayout = new QVBoxLayout();
        departArriveLayout->setObjectName("departArriveLayout");
        routeTitleLabel = new QLabel(scrollAreaWidgetContents);
        routeTitleLabel->setObjectName("routeTitleLabel");
        routeTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"              QLabel {\n"
"               font-size: 16px;\n"
"               font-weight: 600;\n"
"               color: #2D3748;\n"
"               margin-bottom: 20px;\n"
"              }\n"
"             "));

        departArriveLayout->addWidget(routeTitleLabel);

        routeHLayout = new QHBoxLayout();
        routeHLayout->setSpacing(0);
        routeHLayout->setObjectName("routeHLayout");
        departLayout = new QVBoxLayout();
        departLayout->setObjectName("departLayout");
        departTitleLabel = new QLabel(scrollAreaWidgetContents);
        departTitleLabel->setObjectName("departTitleLabel");
        departTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 16px;\n"
"                   font-weight: 600;\n"
"                   color: #E53E3E;\n"
"                   margin-bottom: 12px;\n"
"                  }\n"
"                 "));

        departLayout->addWidget(departTitleLabel);

        lbDepartCity = new QLabel(scrollAreaWidgetContents);
        lbDepartCity->setObjectName("lbDepartCity");
        lbDepartCity->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 18px;\n"
"                   font-weight: 600;\n"
"                   color: #2D3748;\n"
"                   margin-bottom: 4px;\n"
"                  }\n"
"                 "));

        departLayout->addWidget(lbDepartCity);

        lbDepartAirport = new QLabel(scrollAreaWidgetContents);
        lbDepartAirport->setObjectName("lbDepartAirport");
        lbDepartAirport->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 14px;\n"
"                   color: #718096;\n"
"                   margin-bottom: 8px;\n"
"                  }\n"
"                 "));

        departLayout->addWidget(lbDepartAirport);

        lbDepartTime = new QLabel(scrollAreaWidgetContents);
        lbDepartTime->setObjectName("lbDepartTime");
        lbDepartTime->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 15px;\n"
"                   font-weight: 600;\n"
"                   color: #2D3748;\n"
"                  }\n"
"                 "));

        departLayout->addWidget(lbDepartTime);


        routeHLayout->addLayout(departLayout);

        arrowLayout = new QVBoxLayout();
        arrowLayout->setObjectName("arrowLayout");
        arrowLabel = new QLabel(scrollAreaWidgetContents);
        arrowLabel->setObjectName("arrowLabel");
        arrowLabel->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 24px;\n"
"                   color: #CBD5E0;\n"
"                   padding: 0 30px;\n"
"                  }\n"
"                 "));

        arrowLayout->addWidget(arrowLabel);

        lbDuration = new QLabel(scrollAreaWidgetContents);
        lbDuration->setObjectName("lbDuration");
        lbDuration->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 14px;\n"
"                   color: #718096;\n"
"                   padding: 0 30px;\n"
"                  }\n"
"                 "));

        arrowLayout->addWidget(lbDuration);

        lbIsNextDay = new QLabel(scrollAreaWidgetContents);
        lbIsNextDay->setObjectName("lbIsNextDay");
        lbIsNextDay->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 12px;\n"
"                   color: #E53E3E;\n"
"                   padding: 0 30px;\n"
"                  }\n"
"                 "));

        arrowLayout->addWidget(lbIsNextDay);


        routeHLayout->addLayout(arrowLayout);

        arriveLayout = new QVBoxLayout();
        arriveLayout->setObjectName("arriveLayout");
        arriveTitleLabel = new QLabel(scrollAreaWidgetContents);
        arriveTitleLabel->setObjectName("arriveTitleLabel");
        arriveTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 16px;\n"
"                   font-weight: 600;\n"
"                   color: #38A169;\n"
"                   margin-bottom: 12px;\n"
"                  }\n"
"                 "));

        arriveLayout->addWidget(arriveTitleLabel);

        lbArriveCity = new QLabel(scrollAreaWidgetContents);
        lbArriveCity->setObjectName("lbArriveCity");
        lbArriveCity->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 18px;\n"
"                   font-weight: 600;\n"
"                   color: #2D3748;\n"
"                   margin-bottom: 4px;\n"
"                  }\n"
"                 "));

        arriveLayout->addWidget(lbArriveCity);

        lbArriveAirport = new QLabel(scrollAreaWidgetContents);
        lbArriveAirport->setObjectName("lbArriveAirport");
        lbArriveAirport->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 14px;\n"
"                   color: #718096;\n"
"                   margin-bottom: 8px;\n"
"                  }\n"
"                 "));

        arriveLayout->addWidget(lbArriveAirport);

        lbArriveTime = new QLabel(scrollAreaWidgetContents);
        lbArriveTime->setObjectName("lbArriveTime");
        lbArriveTime->setStyleSheet(QString::fromUtf8("\n"
"                  QLabel {\n"
"                   font-size: 15px;\n"
"                   font-weight: 600;\n"
"                   color: #2D3748;\n"
"                  }\n"
"                 "));

        arriveLayout->addWidget(lbArriveTime);


        routeHLayout->addLayout(arriveLayout);


        departArriveLayout->addLayout(routeHLayout);


        contentLayout->addLayout(departArriveLayout);

        priceSeatLayout = new QVBoxLayout();
        priceSeatLayout->setObjectName("priceSeatLayout");
        priceTitleLabel = new QLabel(scrollAreaWidgetContents);
        priceTitleLabel->setObjectName("priceTitleLabel");
        priceTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"              QLabel {\n"
"               font-size: 16px;\n"
"               font-weight: 600;\n"
"               color: #2D3748;\n"
"               margin-bottom: 16px;\n"
"              }\n"
"             "));

        priceSeatLayout->addWidget(priceTitleLabel);

        priceSeatGridLayout = new QGridLayout();
        priceSeatGridLayout->setObjectName("priceSeatGridLayout");
        priceSeatGridLayout->setHorizontalSpacing(24);
        priceSeatGridLayout->setVerticalSpacing(16);
        priceKeyLabel = new QLabel(scrollAreaWidgetContents);
        priceKeyLabel->setObjectName("priceKeyLabel");
        priceKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(priceKeyLabel, 0, 0, 1, 1);

        lbPrice = new QLabel(scrollAreaWidgetContents);
        lbPrice->setObjectName("lbPrice");
        lbPrice->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: 600;\n"
"                 color: #E53E3E;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbPrice, 0, 1, 1, 1);

        priceIntKeyLabel = new QLabel(scrollAreaWidgetContents);
        priceIntKeyLabel->setObjectName("priceIntKeyLabel");
        priceIntKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(priceIntKeyLabel, 0, 2, 1, 1);

        lbPriceInt = new QLabel(scrollAreaWidgetContents);
        lbPriceInt->setObjectName("lbPriceInt");
        lbPriceInt->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbPriceInt, 0, 3, 1, 1);

        economyPriceKeyLabel = new QLabel(scrollAreaWidgetContents);
        economyPriceKeyLabel->setObjectName("economyPriceKeyLabel");
        economyPriceKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(economyPriceKeyLabel, 1, 0, 1, 1);

        lbEconomyPrice = new QLabel(scrollAreaWidgetContents);
        lbEconomyPrice->setObjectName("lbEconomyPrice");
        lbEconomyPrice->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbEconomyPrice, 1, 1, 1, 1);

        businessPriceKeyLabel = new QLabel(scrollAreaWidgetContents);
        businessPriceKeyLabel->setObjectName("businessPriceKeyLabel");
        businessPriceKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(businessPriceKeyLabel, 1, 2, 1, 1);

        lbBusinessPrice = new QLabel(scrollAreaWidgetContents);
        lbBusinessPrice->setObjectName("lbBusinessPrice");
        lbBusinessPrice->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbBusinessPrice, 1, 3, 1, 1);

        firstPriceKeyLabel = new QLabel(scrollAreaWidgetContents);
        firstPriceKeyLabel->setObjectName("firstPriceKeyLabel");
        firstPriceKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(firstPriceKeyLabel, 2, 0, 1, 1);

        lbFirstPrice = new QLabel(scrollAreaWidgetContents);
        lbFirstPrice->setObjectName("lbFirstPrice");
        lbFirstPrice->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbFirstPrice, 2, 1, 1, 1);

        economyRemainKeyLabel = new QLabel(scrollAreaWidgetContents);
        economyRemainKeyLabel->setObjectName("economyRemainKeyLabel");
        economyRemainKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(economyRemainKeyLabel, 3, 0, 1, 1);

        lbEconomyRemain = new QLabel(scrollAreaWidgetContents);
        lbEconomyRemain->setObjectName("lbEconomyRemain");
        lbEconomyRemain->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbEconomyRemain, 3, 1, 1, 1);

        businessRemainKeyLabel = new QLabel(scrollAreaWidgetContents);
        businessRemainKeyLabel->setObjectName("businessRemainKeyLabel");
        businessRemainKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(businessRemainKeyLabel, 3, 2, 1, 1);

        lbBusinessRemain = new QLabel(scrollAreaWidgetContents);
        lbBusinessRemain->setObjectName("lbBusinessRemain");
        lbBusinessRemain->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbBusinessRemain, 3, 3, 1, 1);

        firstRemainKeyLabel = new QLabel(scrollAreaWidgetContents);
        firstRemainKeyLabel->setObjectName("firstRemainKeyLabel");
        firstRemainKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(firstRemainKeyLabel, 4, 0, 1, 1);

        lbFirstRemain = new QLabel(scrollAreaWidgetContents);
        lbFirstRemain->setObjectName("lbFirstRemain");
        lbFirstRemain->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbFirstRemain, 4, 1, 1, 1);

        remainTicketsKeyLabel = new QLabel(scrollAreaWidgetContents);
        remainTicketsKeyLabel->setObjectName("remainTicketsKeyLabel");
        remainTicketsKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold;\n"
"                 color: #718096;\n"
"                 min-width: 100px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(remainTicketsKeyLabel, 4, 2, 1, 1);

        lbRemainTickets = new QLabel(scrollAreaWidgetContents);
        lbRemainTickets->setObjectName("lbRemainTickets");
        lbRemainTickets->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbRemainTickets, 4, 3, 1, 1);


        priceSeatLayout->addLayout(priceSeatGridLayout);


        contentLayout->addLayout(priceSeatLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        contentLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(12);
        buttonLayout->setObjectName("buttonLayout");
        reserveBtn = new QPushButton(FlightDetailWidget);
        reserveBtn->setObjectName("reserveBtn");
        reserveBtn->setMinimumSize(QSize(120, 40));
        reserveBtn->setStyleSheet(QString::fromUtf8("\n"
"         QPushButton {\n"
"          background-color: #2B6CB0;\n"
"          color: #FFFFFF;\n"
"          border: none;\n"
"          border-radius: 8px;\n"
"          font-size: 14px;\n"
"          font-weight: 500;\n"
"         }\n"
"         QPushButton:hover {\n"
"          background-color: #2C5282;\n"
"         }\n"
"         QPushButton:pressed {\n"
"          background-color: #2A4365;\n"
"         }\n"
"        "));

        buttonLayout->addWidget(reserveBtn);

        closeBtn = new QPushButton(FlightDetailWidget);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setMinimumSize(QSize(120, 40));
        closeBtn->setStyleSheet(QString::fromUtf8("\n"
"         QPushButton {\n"
"          background-color: #FFFFFF;\n"
"          color: #4A5568;\n"
"          border: 1px solid #E2E8F0;\n"
"          border-radius: 8px;\n"
"          font-size: 14px;\n"
"          font-weight: 500;\n"
"         }\n"
"         QPushButton:hover {\n"
"          background-color: #F7FAFC;\n"
"         }\n"
"         QPushButton:pressed {\n"
"          background-color: #EDF2F7;\n"
"         }\n"
"        "));

        buttonLayout->addWidget(closeBtn);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(FlightDetailWidget);
        QObject::connect(closeBtn, &QPushButton::clicked, FlightDetailWidget, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(FlightDetailWidget);
    } // setupUi

    void retranslateUi(QDialog *FlightDetailWidget)
    {
        FlightDetailWidget->setWindowTitle(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\217\255\350\257\246\346\203\205", nullptr));
        titleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\217\255\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        baseTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
        flightIdKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\217\255ID\357\274\232", nullptr));
        lbFlightId->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        flightNoKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\217\255\345\217\267\357\274\232", nullptr));
        lbFlightNo->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        airlineKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\251\272\345\205\254\345\217\270\357\274\232", nullptr));
        lbAirline->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        planeTypeKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\346\234\272\345\236\213\357\274\232", nullptr));
        lbPlaneType->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        flightTypeKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\217\255\347\261\273\345\236\213\357\274\232", nullptr));
        lbFlightType->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        flightDateKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\347\217\255\346\227\245\346\234\237\357\274\232", nullptr));
        lbFlightDate->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        routeTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\265\267\351\231\215\344\277\241\346\201\257", nullptr));
        departTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\207\272\345\217\221", nullptr));
        lbDepartCity->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbDepartAirport->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbDepartTime->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        arrowLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\342\236\224", nullptr));
        lbDuration->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbIsNextDay->setText(QCoreApplication::translate("FlightDetailWidget", "\346\254\241\346\227\245\345\210\260\350\276\276", nullptr));
        arriveTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\210\260\350\276\276", nullptr));
        lbArriveCity->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbArriveAirport->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbArriveTime->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        priceTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\344\273\267\346\240\274\344\270\216\345\272\247\344\275\215", nullptr));
        priceKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\217\202\350\200\203\344\273\267\346\240\274\357\274\232", nullptr));
        lbPrice->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        priceIntKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\346\225\264\346\225\260\344\273\267\346\240\274\357\274\232", nullptr));
        lbPriceInt->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        economyPriceKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\347\273\217\346\265\216\350\210\261\344\273\267\346\240\274\357\274\232", nullptr));
        lbEconomyPrice->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        businessPriceKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\205\254\345\212\241\350\210\261\344\273\267\346\240\274\357\274\232", nullptr));
        lbBusinessPrice->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        firstPriceKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\244\264\347\255\211\350\210\261\344\273\267\346\240\274\357\274\232", nullptr));
        lbFirstPrice->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        economyRemainKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\347\273\217\346\265\216\350\210\261\344\275\231\347\245\250\357\274\232", nullptr));
        lbEconomyRemain->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        businessRemainKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\205\254\345\212\241\350\210\261\344\275\231\347\245\250\357\274\232", nullptr));
        lbBusinessRemain->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        firstRemainKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\244\264\347\255\211\350\210\261\344\275\231\347\245\250\357\274\232", nullptr));
        lbFirstRemain->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        remainTicketsKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\344\275\231\347\245\250\347\212\266\346\200\201\357\274\232", nullptr));
        lbRemainTickets->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        reserveBtn->setText(QCoreApplication::translate("FlightDetailWidget", "\351\242\204\350\256\242\346\255\244\350\210\252\347\217\255", nullptr));
        closeBtn->setText(QCoreApplication::translate("FlightDetailWidget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightDetailWidget: public Ui_FlightDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTDETAILWIDGET_H
