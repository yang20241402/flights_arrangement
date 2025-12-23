/********************************************************************************
** Form generated from reading UI file 'flightsearchwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTSEARCHWIDGET_H
#define UI_FLIGHTSEARCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_FlightSearchWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *radioOneWay;
    QRadioButton *radioRoundTrip;
    QWidget *widget;
    QLabel *label_6;
    QLineEdit *lineEdit_Depart;
    QWidget *widget_2;
    QLabel *label_7;
    QLineEdit *lineEdit_Arrive;
    QWidget *widget_3;
    QLabel *label_8;
    QLabel *dateDepart;
    QWidget *widget_4;
    QLabel *label_9;
    QLabel *dateReturn;
    QWidget *widget_5;
    QLabel *label_10;
    QLabel *passenger;
    QComboBox *comboBox;
    QPushButton *btnSearch;
    QWidget *tab_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit_3;
    QWidget *page_2;
    QWidget *widget_7;
    QLabel *label_14;
    QLineEdit *lineEdit_Depart_2;
    QWidget *widget_10;
    QLabel *label_15;
    QLineEdit *lineEdit_Arrive_2;
    QPushButton *btnSearch_2;
    QWidget *widget_11;
    QLabel *label_16;
    QLabel *dateDepart_2;
    QLabel *label_2;
    ClickableLabel *label_3;
    ClickableLabel *label_5;
    QWidget *passengerWidget;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCalendarWidget *calendarWidget_3;
    QCalendarWidget *calendarWidget_2;
    QTabWidget *tabWidget_2;
    QWidget *widget_6;
    QWidget *widget_8;
    QComboBox *comboBox_3;
    ClickableLabel *ontime;
    ClickableLabel *depart;
    ClickableLabel *dijia;
    QListWidget *listWidgetGoing;
    QWidget *tab_8;
    QListWidget *listWidgetReturn;
    QWidget *widget_9;
    QComboBox *comboBox_4;
    ClickableLabel *ontime_2;
    ClickableLabel *depart_2;
    ClickableLabel *dijia_2;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *FlightSearchWidget)
    {
        if (FlightSearchWidget->objectName().isEmpty())
            FlightSearchWidget->setObjectName("FlightSearchWidget");
        FlightSearchWidget->resize(989, 878);
        FlightSearchWidget->setMinimumSize(QSize(989, 878));
        FlightSearchWidget->setMaximumSize(QSize(989, 878));
        FlightSearchWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget = new QTabWidget(FlightSearchWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 40, 971, 221));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar {\n"
"    alignment: center;\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    text-align: center;\n"
"    min-width: 80px;\n"
"    height: 40px;\n"
"    padding: 0px;\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom: 2px solid #4186ea;\n"
"    border-left: 1px solid #e0e0e0;\n"
"    border-right: 1px solid #e0e0e0;\n"
"    border-top: 1px solid #e0e0e0;\n"
"}\n"
"\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #f8f9fa;\n"
"    border: 1px solid #99c1ff;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    top: -1px;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        radioOneWay = new QRadioButton(tab);
        radioOneWay->setObjectName("radioOneWay");
        radioOneWay->setGeometry(QRect(30, 20, 96, 21));
        radioOneWay->setChecked(true);
        radioRoundTrip = new QRadioButton(tab);
        radioRoundTrip->setObjectName("radioRoundTrip");
        radioRoundTrip->setGeometry(QRect(120, 20, 96, 21));
        widget = new QWidget(tab);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 70, 151, 51));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget { \n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 0, 54, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        lineEdit_Depart = new QLineEdit(widget);
        lineEdit_Depart->setObjectName("lineEdit_Depart");
        lineEdit_Depart->setGeometry(QRect(10, 20, 131, 23));
        lineEdit_Depart->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(170, 70, 151, 51));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2 { \n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 0, 54, 16));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        lineEdit_Arrive = new QLineEdit(widget_2);
        lineEdit_Arrive->setObjectName("lineEdit_Arrive");
        lineEdit_Arrive->setGeometry(QRect(10, 20, 131, 23));
        lineEdit_Arrive->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(360, 70, 151, 51));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget#widget_3 {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 0, 54, 16));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        dateDepart = new QLabel(widget_3);
        dateDepart->setObjectName("dateDepart");
        dateDepart->setGeometry(QRect(20, 20, 111, 21));
        widget_4 = new QWidget(tab);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(510, 70, 151, 51));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget#widget_4 { \n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_9 = new QLabel(widget_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 0, 54, 16));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        dateReturn = new QLabel(widget_4);
        dateReturn->setObjectName("dateReturn");
        dateReturn->setGeometry(QRect(20, 20, 121, 21));
        widget_5 = new QWidget(tab);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(760, 70, 181, 51));
        widget_5->setStyleSheet(QString::fromUtf8("QWidget#widget_5 {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_10 = new QLabel(widget_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 0, 54, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        passenger = new QLabel(widget_5);
        passenger->setObjectName("passenger");
        passenger->setGeometry(QRect(10, 20, 141, 21));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(860, 20, 101, 24));
        btnSearch = new QPushButton(tab);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(450, 140, 111, 31));
        btnSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px;\n"
"    background-color: #ff7d00;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    height: 44px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #ff6600;\n"
"    background-color: #ff6600;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-color: #e65c00;\n"
"    background-color: #e65c00;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    border-color: #cccccc;\n"
"    background-color: #cccccc;\n"
"    color: #ffffff;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        radioButton_4 = new QRadioButton(tab_3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(20, 20, 96, 21));
        radioButton_4->setTabletTracking(false);
        radioButton_4->setChecked(true);
        radioButton_5 = new QRadioButton(tab_3);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(140, 20, 96, 21));
        stackedWidget = new QStackedWidget(tab_3);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(19, 59, 591, 71));
        page = new QWidget();
        page->setObjectName("page");
        lineEdit_3 = new QLineEdit(page);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 10, 581, 51));
        QFont font;
        font.setPointSize(12);
        lineEdit_3->setFont(font);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widget_7 = new QWidget(page_2);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(10, 10, 291, 51));
        widget_7->setStyleSheet(QString::fromUtf8("QWidget#widget_7 { \n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_14 = new QLabel(widget_7);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 0, 54, 16));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        lineEdit_Depart_2 = new QLineEdit(widget_7);
        lineEdit_Depart_2->setObjectName("lineEdit_Depart_2");
        lineEdit_Depart_2->setGeometry(QRect(10, 20, 271, 23));
        lineEdit_Depart_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
        widget_10 = new QWidget(page_2);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(300, 10, 281, 51));
        widget_10->setStyleSheet(QString::fromUtf8("QWidget#widget_10 { \n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_15 = new QLabel(widget_10);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 0, 54, 16));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        lineEdit_Arrive_2 = new QLineEdit(widget_10);
        lineEdit_Arrive_2->setObjectName("lineEdit_Arrive_2");
        lineEdit_Arrive_2->setGeometry(QRect(10, 20, 261, 23));
        lineEdit_Arrive_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
        stackedWidget->addWidget(page_2);
        btnSearch_2 = new QPushButton(tab_3);
        btnSearch_2->setObjectName("btnSearch_2");
        btnSearch_2->setGeometry(QRect(450, 140, 111, 31));
        btnSearch_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px;\n"
"    background-color: #ff7d00;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    height: 44px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #ff6600;\n"
"    background-color: #ff6600;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-color: #e65c00;\n"
"    background-color: #e65c00;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    border-color: #cccccc;\n"
"    background-color: #cccccc;\n"
"    color: #ffffff;\n"
"}"));
        widget_11 = new QWidget(tab_3);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(650, 70, 161, 51));
        widget_11->setStyleSheet(QString::fromUtf8("QWidget#widget_11 { \n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_16 = new QLabel(widget_11);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 0, 54, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        dateDepart_2 = new QLabel(widget_11);
        dateDepart_2->setObjectName("dateDepart_2");
        dateDepart_2->setGeometry(QRect(20, 20, 111, 21));
        tabWidget->addTab(tab_3, QString());
        label_2 = new QLabel(FlightSearchWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(900, 10, 16, 16));
        label_3 = new ClickableLabel(FlightSearchWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(920, 10, 54, 16));
        label_5 = new ClickableLabel(FlightSearchWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(840, 10, 61, 20));
        passengerWidget = new QWidget(FlightSearchWidget);
        passengerWidget->setObjectName("passengerWidget");
        passengerWidget->setGeometry(QRect(740, 210, 241, 221));
        passengerWidget->setStyleSheet(QString::fromUtf8("QWidget#passengerWidget{\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}"));
        label_11 = new QLabel(passengerWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 10, 91, 41));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/images/1.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(passengerWidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 70, 91, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/images/images/3.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(passengerWidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 130, 91, 41));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/images/images/2.png")));
        label_13->setScaledContents(true);
        spinBox = new QSpinBox(passengerWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(140, 20, 91, 31));
        spinBox_2 = new QSpinBox(passengerWidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(140, 80, 91, 31));
        spinBox_3 = new QSpinBox(passengerWidget);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(140, 140, 91, 31));
        pushButton = new QPushButton(passengerWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 180, 61, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007fff;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    color: white;\n"
"    padding: 6px 16px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0066cc;\n"
"}"));
        pushButton_2 = new QPushButton(passengerWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 180, 61, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    color: #333333;\n"
"    padding: 6px 16px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #999999;\n"
"}"));
        calendarWidget_3 = new QCalendarWidget(passengerWidget);
        calendarWidget_3->setObjectName("calendarWidget_3");
        calendarWidget_3->setEnabled(true);
        calendarWidget_3->setGeometry(QRect(-100, 0, 341, 211));
        calendarWidget_2 = new QCalendarWidget(FlightSearchWidget);
        calendarWidget_2->setObjectName("calendarWidget_2");
        calendarWidget_2->setEnabled(true);
        calendarWidget_2->setGeometry(QRect(400, 210, 341, 211));
        tabWidget_2 = new QTabWidget(FlightSearchWidget);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(10, 310, 971, 521));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabBar {\n"
"    alignment: center;\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    text-align: center;\n"
"    min-width: 80px;\n"
"    height: 40px;\n"
"    padding: 0px;\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom: 2px solid #4186ea;\n"
"    border-left: 1px solid #e0e0e0;\n"
"    border-right: 1px solid #e0e0e0;\n"
"    border-top: 1px solid #e0e0e0;\n"
"}\n"
"\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #f8f9fa;\n"
"    border: 1px solid #99c1ff;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    top: -1px;\n"
"}"));
        widget_6 = new QWidget();
        widget_6->setObjectName("widget_6");
        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(0, 0, 961, 51));
        comboBox_3 = new QComboBox(widget_8);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(860, 20, 101, 24));
        ontime = new ClickableLabel(widget_8);
        ontime->setObjectName("ontime");
        ontime->setGeometry(QRect(630, 20, 71, 16));
        depart = new ClickableLabel(widget_8);
        depart->setObjectName("depart");
        depart->setGeometry(QRect(730, 20, 101, 16));
        dijia = new ClickableLabel(widget_8);
        dijia->setObjectName("dijia");
        dijia->setGeometry(QRect(550, 20, 71, 16));
        listWidgetGoing = new QListWidget(widget_6);
        listWidgetGoing->setObjectName("listWidgetGoing");
        listWidgetGoing->setGeometry(QRect(0, 40, 971, 441));
        listWidgetGoing->setStyleSheet(QString::fromUtf8("QListWidget { border: none; background-color: #F5F5F5; }\357\274\233\n"
"setSpacing(2)\357\274\233"));
        tabWidget_2->addTab(widget_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        listWidgetReturn = new QListWidget(tab_8);
        listWidgetReturn->setObjectName("listWidgetReturn");
        listWidgetReturn->setGeometry(QRect(0, 50, 971, 451));
        listWidgetReturn->setStyleSheet(QString::fromUtf8("QListWidget { border: none; background-color: #F5F5F5; }\357\274\233\n"
"setSpacing(8)\357\274\233\n"
""));
        widget_9 = new QWidget(tab_8);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(0, 0, 961, 51));
        comboBox_4 = new QComboBox(widget_9);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(860, 20, 101, 24));
        ontime_2 = new ClickableLabel(widget_9);
        ontime_2->setObjectName("ontime_2");
        ontime_2->setGeometry(QRect(630, 20, 71, 16));
        depart_2 = new ClickableLabel(widget_9);
        depart_2->setObjectName("depart_2");
        depart_2->setGeometry(QRect(730, 20, 101, 16));
        dijia_2 = new ClickableLabel(widget_9);
        dijia_2->setObjectName("dijia_2");
        dijia_2->setGeometry(QRect(550, 20, 71, 16));
        tabWidget_2->addTab(tab_8, QString());
        calendarWidget = new QCalendarWidget(FlightSearchWidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setEnabled(true);
        calendarWidget->setGeometry(QRect(400, 210, 341, 211));
        tabWidget_2->raise();
        label_2->raise();
        label_3->raise();
        label_5->raise();
        tabWidget->raise();
        calendarWidget_2->raise();
        passengerWidget->raise();
        calendarWidget->raise();

        retranslateUi(FlightSearchWidget);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FlightSearchWidget);
    } // setupUi

    void retranslateUi(QWidget *FlightSearchWidget)
    {
        FlightSearchWidget->setWindowTitle(QCoreApplication::translate("FlightSearchWidget", "\350\210\252\347\251\272\347\256\241\347\220\206\347\263\273\347\273\237-\351\246\226\351\241\265", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        radioOneWay->setText(QCoreApplication::translate("FlightSearchWidget", "\345\215\225\347\250\213", nullptr));
        radioRoundTrip->setText(QCoreApplication::translate("FlightSearchWidget", "\345\276\200\350\277\224", nullptr));
        label_6->setText(QCoreApplication::translate("FlightSearchWidget", "\345\207\272\345\217\221\345\234\260", nullptr));
        lineEdit_Depart->setPlaceholderText(QCoreApplication::translate("FlightSearchWidget", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        label_7->setText(QCoreApplication::translate("FlightSearchWidget", "\347\233\256\347\232\204\345\234\260", nullptr));
        lineEdit_Arrive->setPlaceholderText(QCoreApplication::translate("FlightSearchWidget", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        label_8->setText(QCoreApplication::translate("FlightSearchWidget", "\345\207\272\345\217\221\346\227\245\346\234\237", nullptr));
        dateDepart->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\346\227\245\346\234\237</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("FlightSearchWidget", "\350\277\224\345\233\236\346\227\245\346\234\237", nullptr));
        dateReturn->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\346\227\245\346\234\237</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("FlightSearchWidget", "\344\271\230\345\256\242\347\261\273\345\236\213", nullptr));
        passenger->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">1 \346\210\220\344\272\272 0 \345\204\277\347\253\245 0 \345\251\264\345\204\277</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("FlightSearchWidget", "\344\270\215\351\231\220\350\210\261\347\255\211", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("FlightSearchWidget", "\347\273\217\346\265\216\350\210\261", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("FlightSearchWidget", "\345\205\254\345\212\241\350\210\261", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("FlightSearchWidget", "\345\244\264\347\255\211\350\210\261", nullptr));

        btnSearch->setText(QCoreApplication::translate("FlightSearchWidget", "\347\241\256\350\256\244\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FlightSearchWidget", "         \345\233\275\345\206\205\343\200\201\345\233\275\351\231\205/\344\270\255\345\233\275\346\270\257\346\276\263\345\217\260                               ", nullptr));
        radioButton_4->setText(QCoreApplication::translate("FlightSearchWidget", "\346\220\234\350\210\252\347\217\255\345\217\267", nullptr));
        radioButton_5->setText(QCoreApplication::translate("FlightSearchWidget", "\346\220\234\350\265\267\351\231\215\345\234\260", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("FlightSearchWidget", "  \350\257\267\345\241\253\345\206\231\350\210\252\347\217\255\345\217\267\357\274\214\345\246\202MU1234", nullptr));
        label_14->setText(QCoreApplication::translate("FlightSearchWidget", "\345\207\272\345\217\221\345\234\260", nullptr));
        lineEdit_Depart_2->setPlaceholderText(QCoreApplication::translate("FlightSearchWidget", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        label_15->setText(QCoreApplication::translate("FlightSearchWidget", "\347\233\256\347\232\204\345\234\260", nullptr));
        lineEdit_Arrive_2->setPlaceholderText(QCoreApplication::translate("FlightSearchWidget", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        btnSearch_2->setText(QCoreApplication::translate("FlightSearchWidget", "\347\241\256\350\256\244\346\220\234\347\264\242", nullptr));
        label_16->setText(QCoreApplication::translate("FlightSearchWidget", "\345\207\272\345\217\221\346\227\245\346\234\237", nullptr));
        dateDepart_2->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\346\227\245\346\234\237</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("FlightSearchWidget", "                  \350\210\252\347\217\255\345\212\250\346\200\201                         ", nullptr));
        label_2->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" color:#000000;\">|</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" color:#000000;\">\346\210\221\347\232\204\350\256\242\345\215\225</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" color:#000000;\">\344\270\252\344\272\272\344\270\255\345\277\203</span></p></body></html>", nullptr));
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        pushButton->setText(QCoreApplication::translate("FlightSearchWidget", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FlightSearchWidget", "\345\217\226\346\266\210", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("FlightSearchWidget", "\346\233\264\345\244\232\346\216\222\345\272\217", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("FlightSearchWidget", "\350\200\227\346\227\266\347\237\255-\351\225\277", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("FlightSearchWidget", "\350\200\227\346\227\266\351\225\277-\347\237\255", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("FlightSearchWidget", "\344\273\267\346\240\274\351\253\230-\344\275\216", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("FlightSearchWidget", "\345\210\260\350\276\276\346\227\251-\346\231\232", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("FlightSearchWidget", "\345\210\260\350\276\276\346\231\232-\346\227\251", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("FlightSearchWidget", "\350\265\267\351\243\236\346\231\232-\346\227\251", nullptr));

        ontime->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\207\206\347\202\271\347\216\207\351\253\230-\344\275\216</span></p></body></html>", nullptr));
        depart->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\351\243\236\346\227\266\351\227\264\346\227\251-\346\231\232</span></p></body></html>", nullptr));
        dijia->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\275\216\344\273\267\344\274\230\345\205\210</span></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(widget_6), QCoreApplication::translate("FlightSearchWidget", "\345\216\273\347\250\213", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("FlightSearchWidget", "\346\233\264\345\244\232\346\216\222\345\272\217", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("FlightSearchWidget", "\350\200\227\346\227\266\347\237\255-\351\225\277", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("FlightSearchWidget", "\350\200\227\346\227\266\351\225\277-\347\237\255", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("FlightSearchWidget", "\344\273\267\346\240\274\351\253\230-\344\275\216", nullptr));
        comboBox_4->setItemText(4, QCoreApplication::translate("FlightSearchWidget", "\345\210\260\350\276\276\346\227\251-\346\231\232", nullptr));
        comboBox_4->setItemText(5, QCoreApplication::translate("FlightSearchWidget", "\345\210\260\350\276\276\346\231\232-\346\227\251", nullptr));
        comboBox_4->setItemText(6, QCoreApplication::translate("FlightSearchWidget", "\350\265\267\351\243\236\346\231\232-\346\227\251", nullptr));

        ontime_2->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\207\206\347\202\271\347\216\207\351\253\230-\344\275\216</span></p></body></html>", nullptr));
        depart_2->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\351\243\236\346\227\266\351\227\264\346\227\251-\346\231\232</span></p></body></html>", nullptr));
        dijia_2->setText(QCoreApplication::translate("FlightSearchWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\275\216\344\273\267\344\274\230\345\205\210</span></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("FlightSearchWidget", "\350\277\224\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightSearchWidget: public Ui_FlightSearchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTSEARCHWIDGET_H
