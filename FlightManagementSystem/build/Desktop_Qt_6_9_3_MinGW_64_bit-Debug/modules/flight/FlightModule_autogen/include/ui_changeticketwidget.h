/********************************************************************************
** Form generated from reading UI file 'changeticketwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGETICKETWIDGET_H
#define UI_CHANGETICKETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_ChangeTicketWidget
{
public:
    QLabel *label;
    QWidget *widget;
    QLabel *label_6;
    QLabel *lblDepart;
    QWidget *widget_2;
    QLabel *label_7;
    QLabel *lblArrive;
    QWidget *widget_3;
    QLabel *label_8;
    QLabel *lineEditDate;
    QWidget *widget_8;
    QComboBox *comboBox_3;
    ClickableLabel *ontime;
    ClickableLabel *depart;
    ClickableLabel *dijia;
    QListWidget *listWidgetNewFlight;
    QCalendarWidget *calendarWidget;
    QLabel *label_4;
    QLabel *lblOldFlight;
    QPushButton *btnSearch;

    void setupUi(QWidget *ChangeTicketWidget)
    {
        if (ChangeTicketWidget->objectName().isEmpty())
            ChangeTicketWidget->setObjectName("ChangeTicketWidget");
        ChangeTicketWidget->resize(988, 704);
        label = new QLabel(ChangeTicketWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 161, 51));
        widget = new QWidget(ChangeTicketWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 90, 151, 51));
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
        lblDepart = new QLabel(widget);
        lblDepart->setObjectName("lblDepart");
        lblDepart->setGeometry(QRect(10, 20, 91, 31));
        widget_2 = new QWidget(ChangeTicketWidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(180, 90, 151, 51));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2 {\n"
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
        lblArrive = new QLabel(widget_2);
        lblArrive->setObjectName("lblArrive");
        lblArrive->setGeometry(QRect(10, 20, 91, 31));
        widget_3 = new QWidget(ChangeTicketWidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(580, 90, 151, 51));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget#widget_3 { \n"
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
        lineEditDate = new QLabel(widget_3);
        lineEditDate->setObjectName("lineEditDate");
        lineEditDate->setGeometry(QRect(20, 20, 111, 21));
        widget_8 = new QWidget(ChangeTicketWidget);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(10, 210, 961, 51));
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
        listWidgetNewFlight = new QListWidget(ChangeTicketWidget);
        listWidgetNewFlight->setObjectName("listWidgetNewFlight");
        listWidgetNewFlight->setGeometry(QRect(10, 260, 971, 441));
        listWidgetNewFlight->setStyleSheet(QString::fromUtf8("QListWidget { border: none; background-color: #F5F5F5; }\357\274\233\n"
"setSpacing(2)\357\274\233"));
        calendarWidget = new QCalendarWidget(ChangeTicketWidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setEnabled(true);
        calendarWidget->setGeometry(QRect(560, 150, 341, 211));
        label_4 = new QLabel(ChangeTicketWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 160, 71, 21));
        lblOldFlight = new QLabel(ChangeTicketWidget);
        lblOldFlight->setObjectName("lblOldFlight");
        lblOldFlight->setGeometry(QRect(110, 160, 221, 21));
        btnSearch = new QPushButton(ChangeTicketWidget);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(390, 170, 111, 31));
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
        label->raise();
        widget->raise();
        widget_2->raise();
        widget_3->raise();
        widget_8->raise();
        listWidgetNewFlight->raise();
        label_4->raise();
        lblOldFlight->raise();
        btnSearch->raise();
        calendarWidget->raise();

        retranslateUi(ChangeTicketWidget);

        QMetaObject::connectSlotsByName(ChangeTicketWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangeTicketWidget)
    {
        ChangeTicketWidget->setWindowTitle(QCoreApplication::translate("ChangeTicketWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700;\">\350\210\252\347\217\255\346\224\271\347\255\276</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("ChangeTicketWidget", "\345\207\272\345\217\221\345\234\260", nullptr));
        lblDepart->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">TextLabel</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("ChangeTicketWidget", "\347\233\256\347\232\204\345\234\260", nullptr));
        lblArrive->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">TextLabel</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("ChangeTicketWidget", "\345\207\272\345\217\221\346\227\245\346\234\237", nullptr));
        lineEditDate->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\346\227\245\346\234\237</span></p></body></html>", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("ChangeTicketWidget", "\346\233\264\345\244\232\346\216\222\345\272\217", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("ChangeTicketWidget", "\350\200\227\346\227\266\347\237\255-\351\225\277", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("ChangeTicketWidget", "\350\200\227\346\227\266\351\225\277-\347\237\255", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("ChangeTicketWidget", "\344\273\267\346\240\274\351\253\230-\344\275\216", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("ChangeTicketWidget", "\345\210\260\350\276\276\346\227\251-\346\231\232", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("ChangeTicketWidget", "\345\210\260\350\276\276\346\231\232-\346\227\251", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("ChangeTicketWidget", "\350\265\267\351\243\236\346\231\232-\346\227\251", nullptr));

        ontime->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\207\206\347\202\271\347\216\207\351\253\230-\344\275\216</span></p></body></html>", nullptr));
        depart->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\351\243\236\346\227\266\351\227\264\346\227\251-\346\231\232</span></p></body></html>", nullptr));
        dijia->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\275\216\344\273\267\344\274\230\345\205\210</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ChangeTicketWidget", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">\345\216\237\350\210\252\347\217\255\357\274\232</span></p></body></html>", nullptr));
        lblOldFlight->setText(QCoreApplication::translate("ChangeTicketWidget", "TextLabel", nullptr));
        btnSearch->setText(QCoreApplication::translate("ChangeTicketWidget", "\347\241\256\350\256\244\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeTicketWidget: public Ui_ChangeTicketWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGETICKETWIDGET_H
