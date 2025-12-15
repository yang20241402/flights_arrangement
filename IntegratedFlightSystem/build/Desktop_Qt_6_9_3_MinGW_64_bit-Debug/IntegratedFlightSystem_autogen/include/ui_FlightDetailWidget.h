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
    QLabel *segmentNoKeyLabel;
    QLabel *lbSegmentNo;
    QLabel *planeTypeKeyLabel;
    QLabel *lbPlaneType;
    QLabel *flightTimeKeyLabel;
    QLabel *lbFlightTime;
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
    QVBoxLayout *arriveLayout;
    QLabel *arriveTitleLabel;
    QLabel *lbArriveCity;
    QLabel *lbArriveAirport;
    QLabel *lbArriveTime;
    QVBoxLayout *priceSeatLayout;
    QLabel *priceTitleLabel;
    QGridLayout *priceSeatGridLayout;
    QLabel *adultPriceKeyLabel;
    QLabel *lbAdultPrice;
    QLabel *childPriceKeyLabel;
    QLabel *lbChildPrice;
    QLabel *totalSeatsKeyLabel;
    QLabel *lbTotalSeats;
    QLabel *remainSeatsKeyLabel;
    QLabel *lbRemainSeats;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *buttonLayout;
    QPushButton *reserveBtn;
    QPushButton *closeBtn;

    void setupUi(QDialog *FlightDetailWidget)
    {
        if (FlightDetailWidget->objectName().isEmpty())
            FlightDetailWidget->setObjectName("FlightDetailWidget");
        FlightDetailWidget->resize(1500, 620);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(FlightDetailWidget->sizePolicy().hasHeightForWidth());
        FlightDetailWidget->setSizePolicy(sizePolicy);
        FlightDetailWidget->setFixedSize(QSize(2000, 1500));
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        FlightDetailWidget->setWindowIcon(icon);
        FlightDetailWidget->setModal(true);
        FlightDetailWidget->setWindowFlags(Qt::Dialog|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint);
        FlightDetailWidget->setMinimumSize(QSize(700, 500));
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 782, 458));
        contentLayout = new QVBoxLayout(scrollAreaWidgetContents);
        contentLayout->setSpacing(16);
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
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
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
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
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
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
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

        segmentNoKeyLabel = new QLabel(scrollAreaWidgetContents);
        segmentNoKeyLabel->setObjectName("segmentNoKeyLabel");
        segmentNoKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(segmentNoKeyLabel, 1, 2, 1, 1);

        lbSegmentNo = new QLabel(scrollAreaWidgetContents);
        lbSegmentNo->setObjectName("lbSegmentNo");
        lbSegmentNo->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbSegmentNo, 1, 3, 1, 1);

        planeTypeKeyLabel = new QLabel(scrollAreaWidgetContents);
        planeTypeKeyLabel->setObjectName("planeTypeKeyLabel");
        planeTypeKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(planeTypeKeyLabel, 2, 0, 1, 1);

        lbPlaneType = new QLabel(scrollAreaWidgetContents);
        lbPlaneType->setObjectName("lbPlaneType");
        lbPlaneType->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbPlaneType, 2, 1, 1, 1);

        flightTimeKeyLabel = new QLabel(scrollAreaWidgetContents);
        flightTimeKeyLabel->setObjectName("flightTimeKeyLabel");
        flightTimeKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(flightTimeKeyLabel, 2, 2, 1, 1);

        lbFlightTime = new QLabel(scrollAreaWidgetContents);
        lbFlightTime->setObjectName("lbFlightTime");
        lbFlightTime->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        baseGridLayout->addWidget(lbFlightTime, 2, 3, 1, 1);


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
        adultPriceKeyLabel = new QLabel(scrollAreaWidgetContents);
        adultPriceKeyLabel->setObjectName("adultPriceKeyLabel");
        adultPriceKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(adultPriceKeyLabel, 0, 0, 1, 1);

        lbAdultPrice = new QLabel(scrollAreaWidgetContents);
        lbAdultPrice->setObjectName("lbAdultPrice");
        lbAdultPrice->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: 600;\n"
"                 color: #718096;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbAdultPrice, 0, 1, 1, 1);

        childPriceKeyLabel = new QLabel(scrollAreaWidgetContents);
        childPriceKeyLabel->setObjectName("childPriceKeyLabel");
        childPriceKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(childPriceKeyLabel, 0, 2, 1, 1);

        lbChildPrice = new QLabel(scrollAreaWidgetContents);
        lbChildPrice->setObjectName("lbChildPrice");
        lbChildPrice->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbChildPrice, 0, 3, 1, 1);

        totalSeatsKeyLabel = new QLabel(scrollAreaWidgetContents);
        totalSeatsKeyLabel->setObjectName("totalSeatsKeyLabel");
        totalSeatsKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(totalSeatsKeyLabel, 1, 0, 1, 1);

        lbTotalSeats = new QLabel(scrollAreaWidgetContents);
        lbTotalSeats->setObjectName("lbTotalSeats");
        lbTotalSeats->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 color: #2D3748;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbTotalSeats, 1, 1, 1, 1);

        remainSeatsKeyLabel = new QLabel(scrollAreaWidgetContents);
        remainSeatsKeyLabel->setObjectName("remainSeatsKeyLabel");
        remainSeatsKeyLabel->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: bold; /* \345\212\240\347\262\227 */\n"
"                 color: #718096;\n"
"                 min-width: 80px;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(remainSeatsKeyLabel, 1, 2, 1, 1);

        lbRemainSeats = new QLabel(scrollAreaWidgetContents);
        lbRemainSeats->setObjectName("lbRemainSeats");
        lbRemainSeats->setStyleSheet(QString::fromUtf8("\n"
"                QLabel {\n"
"                 font-size: 14px;\n"
"                 font-weight: 600;\n"
"                 color: #2B6CB0;\n"
"                }\n"
"               "));

        priceSeatGridLayout->addWidget(lbRemainSeats, 1, 3, 1, 1);


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
        segmentNoKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\210\252\346\256\265\345\272\217\345\217\267\357\274\232", nullptr));
        lbSegmentNo->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        planeTypeKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\346\234\272\345\236\213\357\274\232", nullptr));
        lbPlaneType->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        flightTimeKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\351\243\236\350\241\214\346\227\266\351\225\277\357\274\232", nullptr));
        lbFlightTime->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        routeTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\350\265\267\351\231\215\344\277\241\346\201\257", nullptr));
        departTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\207\272\345\217\221", nullptr));
        lbDepartCity->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbDepartAirport->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbDepartTime->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        arrowLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\342\236\224", nullptr));
        arriveTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\210\260\350\276\276", nullptr));
        lbArriveCity->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbArriveAirport->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        lbArriveTime->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        priceTitleLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\344\273\267\346\240\274\344\270\216\345\272\247\344\275\215", nullptr));
        adultPriceKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\346\210\220\344\272\272\344\273\267\346\240\274\357\274\232", nullptr));
        lbAdultPrice->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        childPriceKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\204\277\347\253\245\344\273\267\346\240\274\357\274\232", nullptr));
        lbChildPrice->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        totalSeatsKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\346\200\273\345\272\247\344\275\215\346\225\260\357\274\232", nullptr));
        lbTotalSeats->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        remainSeatsKeyLabel->setText(QCoreApplication::translate("FlightDetailWidget", "\345\211\251\344\275\231\345\272\247\344\275\215\346\225\260\357\274\232", nullptr));
        lbRemainSeats->setText(QCoreApplication::translate("FlightDetailWidget", "--", nullptr));
        reserveBtn->setText(QCoreApplication::translate("FlightDetailWidget", "\351\242\204\350\256\242\346\255\244\350\210\252\347\217\255", nullptr));
        closeBtn->setText(QCoreApplication::translate("FlightDetailWidget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightDetailWidget: public Ui_FlightDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTDETAILWIDGET_H
