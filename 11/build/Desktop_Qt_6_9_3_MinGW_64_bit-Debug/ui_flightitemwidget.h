/********************************************************************************
** Form generated from reading UI file 'flightitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTITEMWIDGET_H
#define UI_FLIGHTITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightItemWidget
{
public:
    QLabel *labelLogo;
    QLabel *labelAirline;
    QLabel *Airname;
    QLabel *labelDepartTime;
    QLabel *labelDepartAirport;
    QLabel *labelArriveTime;
    QLabel *labelArriveAirport;
    QLabel *labelPrice;
    QLabel *label_31;
    QLabel *labelNextDay;
    QLabel *label;
    QLabel *duration;
    QLabel *labelremain;

    void setupUi(QWidget *FlightItemWidget)
    {
        if (FlightItemWidget->objectName().isEmpty())
            FlightItemWidget->setObjectName("FlightItemWidget");
        FlightItemWidget->resize(959, 55);
        labelLogo = new QLabel(FlightItemWidget);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setGeometry(QRect(10, 10, 41, 41));
        labelAirline = new QLabel(FlightItemWidget);
        labelAirline->setObjectName("labelAirline");
        labelAirline->setGeometry(QRect(80, 10, 131, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        labelAirline->setFont(font);
        Airname = new QLabel(FlightItemWidget);
        Airname->setObjectName("Airname");
        Airname->setGeometry(QRect(80, 40, 191, 16));
        labelDepartTime = new QLabel(FlightItemWidget);
        labelDepartTime->setObjectName("labelDepartTime");
        labelDepartTime->setGeometry(QRect(260, 10, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        labelDepartTime->setFont(font1);
        labelDepartAirport = new QLabel(FlightItemWidget);
        labelDepartAirport->setObjectName("labelDepartAirport");
        labelDepartAirport->setGeometry(QRect(260, 40, 131, 16));
        labelArriveTime = new QLabel(FlightItemWidget);
        labelArriveTime->setObjectName("labelArriveTime");
        labelArriveTime->setGeometry(QRect(610, 10, 101, 31));
        labelArriveTime->setFont(font1);
        labelArriveAirport = new QLabel(FlightItemWidget);
        labelArriveAirport->setObjectName("labelArriveAirport");
        labelArriveAirport->setGeometry(QRect(610, 40, 131, 16));
        labelPrice = new QLabel(FlightItemWidget);
        labelPrice->setObjectName("labelPrice");
        labelPrice->setGeometry(QRect(830, 0, 101, 31));
        labelPrice->setFont(font1);
        label_31 = new QLabel(FlightItemWidget);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(710, 30, 61, 16));
        labelNextDay = new QLabel(FlightItemWidget);
        labelNextDay->setObjectName("labelNextDay");
        labelNextDay->setGeometry(QRect(710, 10, 51, 16));
        label = new QLabel(FlightItemWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 20, 121, 20));
        label->setPixmap(QPixmap(QString::fromUtf8(":/newimages/newimages/arrow.jpg")));
        label->setScaledContents(true);
        duration = new QLabel(FlightItemWidget);
        duration->setObjectName("duration");
        duration->setGeometry(QRect(450, 10, 71, 16));
        labelremain = new QLabel(FlightItemWidget);
        labelremain->setObjectName("labelremain");
        labelremain->setGeometry(QRect(830, 40, 81, 16));

        retranslateUi(FlightItemWidget);

        QMetaObject::connectSlotsByName(FlightItemWidget);
    } // setupUi

    void retranslateUi(QWidget *FlightItemWidget)
    {
        FlightItemWidget->setWindowTitle(QCoreApplication::translate("FlightItemWidget", "Form", nullptr));
        labelLogo->setText(QString());
        labelAirline->setText(QString());
        Airname->setText(QCoreApplication::translate("FlightItemWidget", "<html><head/><body><p><span style=\" color:#4186ea;\"><br/></span></p></body></html>", nullptr));
        labelDepartTime->setText(QString());
        labelDepartAirport->setText(QString());
        labelArriveTime->setText(QString());
        labelArriveAirport->setText(QString());
        labelPrice->setText(QCoreApplication::translate("FlightItemWidget", "<html><head/><body><p><span style=\" color:#3a84ee;\"><br/></span></p></body></html>", nullptr));
        label_31->setText(QString());
        labelNextDay->setText(QCoreApplication::translate("FlightItemWidget", "<html><head/><body><p><span style=\" font-weight:700; color:#00aaff;\">+1</span></p></body></html>", nullptr));
        label->setText(QString());
        duration->setText(QCoreApplication::translate("FlightItemWidget", "TextLabel", nullptr));
        labelremain->setText(QCoreApplication::translate("FlightItemWidget", "<html><head/><body><p>remain</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightItemWidget: public Ui_FlightItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTITEMWIDGET_H
