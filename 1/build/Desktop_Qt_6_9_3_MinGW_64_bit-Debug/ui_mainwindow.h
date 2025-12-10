/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *radioOneWay;
    QRadioButton *radioRoundTrip;
    QRadioButton *radioButton_3;
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
    QWidget *tab_2;
    QWidget *tab_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QWidget *widget_7;
    QLabel *label_17;
    QLineEdit *lineEdit_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit_3;
    QWidget *page_2;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
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
    QCalendarWidget *calendarWidget;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(989, 878);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(110, 40, 881, 201));
        tab = new QWidget();
        tab->setObjectName("tab");
        radioOneWay = new QRadioButton(tab);
        radioOneWay->setObjectName("radioOneWay");
        radioOneWay->setGeometry(QRect(30, 20, 96, 21));
        radioOneWay->setChecked(true);
        radioRoundTrip = new QRadioButton(tab);
        radioRoundTrip->setObjectName("radioRoundTrip");
        radioRoundTrip->setGeometry(QRect(120, 20, 96, 21));
        radioButton_3 = new QRadioButton(tab);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(210, 20, 111, 21));
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
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2 { /* #\345\220\216\346\230\257\345\275\223\345\211\215QWidget\347\232\204objectName\357\274\210\345\246\202widget\343\200\201widget_1\357\274\211 */\n"
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
        widget_3->setStyleSheet(QString::fromUtf8("QWidget#widget_3 { /* #\345\220\216\346\230\257\345\275\223\345\211\215QWidget\347\232\204objectName\357\274\210\345\246\202widget\343\200\201widget_1\357\274\211 */\n"
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
        widget_4->setStyleSheet(QString::fromUtf8("QWidget#widget_4 { /* #\345\220\216\346\230\257\345\275\223\345\211\215QWidget\347\232\204objectName\357\274\210\345\246\202widget\343\200\201widget_1\357\274\211 */\n"
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
        widget_5->setGeometry(QRect(690, 70, 181, 51));
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
        comboBox->setGeometry(QRect(740, 20, 101, 24));
        btnSearch = new QPushButton(tab);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(350, 140, 111, 31));
        btnSearch->setStyleSheet(QString::fromUtf8("/* \347\231\273\345\275\225\346\214\211\351\222\256\345\237\272\347\241\200\346\240\267\345\274\217\357\274\210\346\251\231\350\211\262\350\276\271\346\241\206+\346\251\231\350\211\262\350\203\214\346\231\257\357\274\214\346\220\255\351\205\215\347\231\275\350\211\262\346\226\207\345\255\227\357\274\211 */\n"
"QPushButton {\n"
"    /* \346\251\231\350\211\262\350\276\271\346\241\206\357\274\232#ff7d00 \346\230\257\345\270\270\347\224\250\347\231\273\345\275\225\351\241\265\346\251\231\350\211\262\357\274\214\345\217\257\346\233\277\346\215\242\344\270\272 #ff9900\357\274\210\346\265\205\346\251\231\357\274\211\343\200\201#ff6600\357\274\210\346\267\261\346\251\231\357\274\211 */\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px; /* \345\234\206\350\247\222\357\274\210\345\222\214\350\276\223\345\205\245\346\241\206\344\277\235\346\214\201\344\270\200\350\207\264\357\274\214\346\233\264\345\215\217\350\260\203\357\274\211 */\n"
"    background-color: #ff7d00; /* \346\214\211\351\222\256\350\203\214"
                        "\346\231\257\350\211\262\357\274\210\345\222\214\350\276\271\346\241\206\345\220\214\350\211\262\357\274\214\344\270\200\344\275\223\345\214\226\346\225\210\346\236\234\357\274\211 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    font-size: 16px; /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    height: 44px; /* \346\214\211\351\222\256\351\253\230\345\272\246\357\274\210\345\222\214\350\276\223\345\205\245\346\241\206\345\221\274\345\272\224\357\274\211 */\n"
"}\n"
"\n"
"/* \346\202\254\346\265\256\347\212\266\346\200\201\357\274\210\350\276\271\346\241\206\345\212\240\346\267\261+\350\203\214\346\231\257\350\211\262\345\217\230\346\267\261\357\274\214\346\233\264\346\234\211\344\272\244\344\272\222\346\204\237\357\274\211 */\n"
"QPushButton:hover {\n"
"    border-color: #ff6600; /* \346\202\254\346\265\256\346\227\266\350\276\271\346\241\206\346\267\261\346\251\231\350\211\262 */\n"
"    background-color: #ff6600; /* \346\202\254\346\265\256\346\227\266\350"
                        "\203\214\346\231\257\346\267\261\346\251\231\350\211\262 */\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\347\212\266\346\200\201\357\274\210\350\276\271\346\241\206\345\206\215\345\212\240\346\267\261+\350\203\214\346\231\257\350\211\262\345\216\213\346\232\227\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213\346\225\210\346\236\234\357\274\211 */\n"
"QPushButton:pressed {\n"
"    border-color: #e65c00; /* \347\202\271\345\207\273\346\227\266\350\276\271\346\241\206\346\233\264\346\267\261\346\251\231\350\211\262 */\n"
"    background-color: #e65c00; /* \347\202\271\345\207\273\346\227\266\350\203\214\346\231\257\346\233\264\346\267\261\346\251\231\350\211\262 */\n"
"}\n"
"\n"
"/* \347\246\201\347\224\250\347\212\266\346\200\201\357\274\210\345\217\257\351\200\211\357\274\232\345\246\202\346\236\234\346\214\211\351\222\256\351\234\200\350\246\201\347\246\201\347\224\250\357\274\214\350\276\271\346\241\206\345\222\214\350\203\214\346\231\257\345\217\230\347\201\260\350\211\262\357\274\211 */\n"
"QPushB"
                        "utton:disabled {\n"
"    border-color: #cccccc;\n"
"    background-color: #cccccc;\n"
"    color: #ffffff;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        radioButton_4 = new QRadioButton(tab_3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(20, 20, 96, 21));
        radioButton_5 = new QRadioButton(tab_3);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(140, 20, 96, 21));
        widget_7 = new QWidget(tab_3);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(620, 70, 231, 51));
        label_17 = new QLabel(widget_7);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 0, 54, 16));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(153, 153, 153);\n"
"border: none;\n"
"background-color: transparent;"));
        lineEdit_5 = new QLineEdit(widget_7);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(10, 20, 141, 23));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-weight: bold;\n"
"font-size: 14px;"));
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
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab_3, QString());
        stackedWidget->raise();
        radioButton_4->raise();
        radioButton_5->raise();
        widget_7->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        label_18 = new QLabel(tab_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 110, 54, 16));
        label_19 = new QLabel(tab_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(150, 110, 54, 16));
        label_20 = new QLabel(tab_6);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(250, 110, 91, 16));
        label_21 = new QLabel(tab_6);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(360, 110, 81, 16));
        label_22 = new QLabel(tab_6);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(480, 110, 54, 16));
        tabWidget->addTab(tab_6, QString());
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(770, 0, 54, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(810, 0, 16, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(830, 0, 54, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(890, 0, 54, 16));
        label_5 = new ClickableLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(730, 0, 31, 16));
        passengerWidget = new QWidget(centralwidget);
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
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/newimages/newimages/1.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(passengerWidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 70, 91, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/newimages/newimages/3.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(passengerWidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 130, 91, 41));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/newimages/newimages/2.png")));
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
"    /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    background-color: #007fff;\n"
"    /* \346\227\240\350\276\271\346\241\206\357\274\210\346\210\226\350\223\235\350\211\262\350\276\271\346\241\206\357\274\211 */\n"
"    border: none;\n"
"    /* \350\275\273\345\276\256\345\234\206\350\247\222\357\274\210\344\270\216\345\217\226\346\266\210\346\214\211\351\222\256\344\270\200\350\207\264\357\274\211 */\n"
"    border-radius: 4px;\n"
"    /* \346\226\207\345\255\227\351\242\234\350\211\262\357\274\210\347\231\275\350\211\262\357\274\211 */\n"
"    color: white;\n"
"    /* \345\206\205\350\276\271\350\267\235\357\274\210\344\270\216\345\217\226\346\266\210\346\214\211\351\222\256\344\277\235\346\214\201\344\270\200\350\207\264\357\274\214\345\244\247\345\260\217\347\273\237\344\270\200\357\274\211 */\n"
"    padding: 6px 16px;\n"
"    /* \345\255\227\344\275\223\345\244\247\345\260\217\357\274\210\344\270\216\345\217\226\346\266\210\346\214\211\351\222\256\344\270\200\350\207\264"
                        "\357\274\211 */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\346\265\256\346\225\210\346\236\234\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #0066cc; /* \350\223\235\350\211\262\345\212\240\346\267\261 */\n"
"}"));
        pushButton_2 = new QPushButton(passengerWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 180, 61, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \347\231\275\350\211\262\350\203\214\346\231\257 */\n"
"    background-color: white;\n"
"    /* \347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    border: 1px solid #cccccc;\n"
"    /* \350\275\273\345\276\256\345\234\206\350\247\222\357\274\210\345\217\257\351\200\211\357\274\214\345\233\276\344\270\255\347\225\245\345\234\206\357\274\211 */\n"
"    border-radius: 4px;\n"
"    /* \346\226\207\345\255\227\351\242\234\350\211\262\357\274\210\351\273\221\350\211\262\357\274\211 */\n"
"    color: #333333;\n"
"    /* \345\206\205\350\276\271\350\267\235\357\274\210\346\214\211\351\222\256\345\244\247\345\260\217\351\200\202\344\270\255\357\274\211 */\n"
"    padding: 6px 16px;\n"
"    /* \345\255\227\344\275\223\345\244\247\345\260\217\357\274\210\346\214\211\351\234\200\350\260\203\346\225\264\357\274\211 */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\346\265\256\346\225\210\346\236\234\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"QPu"
                        "shButton:hover {\n"
"    border-color: #999999; /* \350\276\271\346\241\206\345\212\240\346\267\261 */\n"
"}"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setEnabled(true);
        calendarWidget->setGeometry(QRect(350, 210, 341, 211));
        calendarWidget_2 = new QCalendarWidget(centralwidget);
        calendarWidget_2->setObjectName("calendarWidget_2");
        calendarWidget_2->setEnabled(true);
        calendarWidget_2->setGeometry(QRect(400, 210, 341, 211));
        tabWidget_2 = new QTabWidget(centralwidget);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(110, 300, 881, 561));
        widget_6 = new QWidget();
        widget_6->setObjectName("widget_6");
        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(0, 0, 881, 51));
        comboBox_3 = new QComboBox(widget_8);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(770, 20, 101, 24));
        ontime = new ClickableLabel(widget_8);
        ontime->setObjectName("ontime");
        ontime->setGeometry(QRect(570, 20, 71, 16));
        depart = new ClickableLabel(widget_8);
        depart->setObjectName("depart");
        depart->setGeometry(QRect(650, 20, 101, 16));
        dijia = new ClickableLabel(widget_8);
        dijia->setObjectName("dijia");
        dijia->setGeometry(QRect(500, 20, 71, 16));
        listWidgetGoing = new QListWidget(widget_6);
        listWidgetGoing->setObjectName("listWidgetGoing");
        listWidgetGoing->setGeometry(QRect(0, 50, 881, 451));
        listWidgetGoing->setStyleSheet(QString::fromUtf8("QListWidget { border: none; background-color: #F5F5F5; }\357\274\233\n"
"setSpacing(2)\357\274\233"));
        tabWidget_2->addTab(widget_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        listWidgetReturn = new QListWidget(tab_8);
        listWidgetReturn->setObjectName("listWidgetReturn");
        listWidgetReturn->setGeometry(QRect(0, 50, 871, 451));
        listWidgetReturn->setStyleSheet(QString::fromUtf8("QListWidget { border: none; background-color: #F5F5F5; }\357\274\233\n"
"setSpacing(8)\357\274\233\n"
""));
        widget_9 = new QWidget(tab_8);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(0, 0, 881, 51));
        comboBox_4 = new QComboBox(widget_9);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(770, 20, 101, 24));
        ontime_2 = new ClickableLabel(widget_9);
        ontime_2->setObjectName("ontime_2");
        ontime_2->setGeometry(QRect(570, 20, 71, 16));
        depart_2 = new ClickableLabel(widget_9);
        depart_2->setObjectName("depart_2");
        depart_2->setGeometry(QRect(650, 20, 101, 16));
        dijia_2 = new ClickableLabel(widget_9);
        dijia_2->setObjectName("dijia_2");
        dijia_2->setGeometry(QRect(500, 20, 71, 16));
        tabWidget_2->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralwidget);
        tabWidget->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        tabWidget_2->raise();
        calendarWidget->raise();
        calendarWidget_2->raise();
        passengerWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 989, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        radioOneWay->setText(QCoreApplication::translate("MainWindow", "\345\215\225\347\250\213", nullptr));
        radioRoundTrip->setText(QCoreApplication::translate("MainWindow", "\345\276\200\350\277\224", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\345\244\232\347\250\213\357\274\210\345\220\253\347\274\272\345\217\243\347\250\213\357\274\211", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\217\221\345\234\260", nullptr));
        lineEdit_Depart->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260", nullptr));
        lineEdit_Arrive->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\217\221\346\227\245\346\234\237", nullptr));
        dateDepart->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\346\227\245\346\234\237</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\346\227\245\346\234\237", nullptr));
        dateReturn->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\346\227\245\346\234\237</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\271\230\345\256\242\347\261\273\345\236\213", nullptr));
        passenger->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">1 \346\210\220\344\272\272 0 \345\204\277\347\253\245 0 \345\251\264\345\204\277</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\215\351\231\220\350\210\261\347\255\211", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\347\273\217\346\265\216\350\210\261", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\205\254\345\212\241\350\210\261", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\345\244\264\347\255\211\350\210\261", nullptr));

        btnSearch->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "         \345\233\275\345\206\205\343\200\201\345\233\275\351\231\205/\344\270\255\345\233\275\346\270\257\346\276\263\345\217\260     ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "        \347\211\271\344\273\267\346\234\272\347\245\250       ", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\346\220\234\350\210\252\347\217\255\345\217\267", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "\346\220\234\350\265\267\351\231\215\345\234\260", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\217\221\346\227\245\346\234\237", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\217\257\350\276\223\345\205\245\345\237\216\345\270\202\346\210\226\346\234\272\345\234\272", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "  \350\257\267\345\241\253\345\206\231\350\210\252\347\217\255\345\217\267\357\274\214\345\246\202MU1234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "          \350\210\252\347\217\255\345\212\250\346\200\201        ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "              \345\234\250\347\272\277\351\200\211\345\272\247           ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "          \351\200\200\347\245\250\346\224\271\347\255\276            ", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\212\245\351\224\200\345\207\255\350\257\201", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\346\234\272\345\234\272\346\224\273\347\225\245", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\345\233\275\345\206\205\346\234\272\345\234\272\345\244\247\345\205\250", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\345\233\275\351\231\205\346\234\272\345\234\272\345\244\247\345\205\250", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\345\233\242\344\275\223\347\245\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "      \346\233\264\345\244\232\346\234\215\345\212\241    ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">\346\263\250\345\206\214</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">|</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">\346\210\221\347\232\204\350\256\242\345\215\225</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">\350\201\224\347\263\273\345\256\242\346\234\215</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "\346\233\264\345\244\232\346\216\222\345\272\217", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "\350\200\227\346\227\266\347\237\255-\351\225\277", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "\350\200\227\346\227\266\351\225\277-\347\237\255", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "\344\273\267\346\240\274\351\253\230-\344\275\216", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "\345\210\260\350\276\276\346\227\251-\346\231\232", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("MainWindow", "\345\210\260\350\276\276\346\231\232-\346\227\251", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("MainWindow", "\350\265\267\351\243\236\346\231\232-\346\227\251", nullptr));

        ontime->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\207\206\347\202\271\347\216\207\351\253\230-\344\275\216</span></p></body></html>", nullptr));
        depart->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\351\243\236\346\227\266\351\227\264\346\227\251-\346\231\232</span></p></body></html>", nullptr));
        dijia->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\275\216\344\273\267\344\274\230\345\205\210</span></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(widget_6), QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\216\273\347\250\213", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "\346\233\264\345\244\232\346\216\222\345\272\217", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "\350\200\227\346\227\266\347\237\255-\351\225\277", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "\350\200\227\346\227\266\351\225\277-\347\237\255", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("MainWindow", "\344\273\267\346\240\274\351\253\230-\344\275\216", nullptr));
        comboBox_4->setItemText(4, QCoreApplication::translate("MainWindow", "\345\210\260\350\276\276\346\227\251-\346\231\232", nullptr));
        comboBox_4->setItemText(5, QCoreApplication::translate("MainWindow", "\345\210\260\350\276\276\346\231\232-\346\227\251", nullptr));
        comboBox_4->setItemText(6, QCoreApplication::translate("MainWindow", "\350\265\267\351\243\236\346\231\232-\346\227\251", nullptr));

        ontime_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\207\206\347\202\271\347\216\207\351\253\230-\344\275\216</span></p></body></html>", nullptr));
        depart_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\351\243\236\346\227\266\351\227\264\346\227\251-\346\231\232</span></p></body></html>", nullptr));
        dijia_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\275\216\344\273\267\344\274\230\345\205\210</span></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\277\224\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
