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
#include <QtWidgets/QPushButton>
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
    QPushButton *btnSelect;
    QLabel *labelNextDay;
    QLabel *label;
    QLabel *duration;
    QLabel *labelremain;

    void setupUi(QWidget *FlightItemWidget)
    {
        if (FlightItemWidget->objectName().isEmpty())
            FlightItemWidget->setObjectName("FlightItemWidget");
        FlightItemWidget->resize(858, 55);
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
        labelArriveTime->setGeometry(QRect(480, 10, 101, 31));
        labelArriveTime->setFont(font1);
        labelArriveAirport = new QLabel(FlightItemWidget);
        labelArriveAirport->setObjectName("labelArriveAirport");
        labelArriveAirport->setGeometry(QRect(480, 40, 131, 16));
        labelPrice = new QLabel(FlightItemWidget);
        labelPrice->setObjectName("labelPrice");
        labelPrice->setGeometry(QRect(670, 10, 101, 31));
        labelPrice->setFont(font1);
        label_31 = new QLabel(FlightItemWidget);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(710, 30, 61, 16));
        btnSelect = new QPushButton(FlightItemWidget);
        btnSelect->setObjectName("btnSelect");
        btnSelect->setGeometry(QRect(790, 20, 61, 31));
        btnSelect->setStyleSheet(QString::fromUtf8("/* \347\231\273\345\275\225\346\214\211\351\222\256\345\237\272\347\241\200\346\240\267\345\274\217\357\274\210\346\251\231\350\211\262\350\276\271\346\241\206+\346\251\231\350\211\262\350\203\214\346\231\257\357\274\214\346\220\255\351\205\215\347\231\275\350\211\262\346\226\207\345\255\227\357\274\211 */\n"
"QPushButton {\n"
"    /* \346\251\231\350\211\262\350\276\271\346\241\206\357\274\232#ff7d00 \346\230\257\345\270\270\347\224\250\347\231\273\345\275\225\351\241\265\346\251\231\350\211\262\357\274\214\345\217\257\346\233\277\346\215\242\344\270\272 #ff9900\357\274\210\346\265\205\346\251\231\357\274\211\343\200\201#ff6600\357\274\210\346\267\261\346\251\231\357\274\211 */\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px; /* \345\234\206\350\247\222\357\274\210\345\222\214\350\276\223\345\205\245\346\241\206\344\277\235\346\214\201\344\270\200\350\207\264\357\274\214\346\233\264\345\215\217\350\260\203\357\274\211 */\n"
"    background-color: #ff7d00; /* \346\214\211\351\222\256\350\203\214"
                        "\346\231\257\350\211\262\357\274\210\345\222\214\350\276\271\346\241\206\345\220\214\350\211\262\357\274\214\344\270\200\344\275\223\345\214\226\346\225\210\346\236\234\357\274\211 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    font-size: 14px; /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
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
        labelNextDay = new QLabel(FlightItemWidget);
        labelNextDay->setObjectName("labelNextDay");
        labelNextDay->setGeometry(QRect(580, 10, 51, 16));
        label = new QLabel(FlightItemWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 20, 121, 20));
        label->setPixmap(QPixmap(QString::fromUtf8(":/newimages/newimages/arrow.jpg")));
        label->setScaledContents(true);
        duration = new QLabel(FlightItemWidget);
        duration->setObjectName("duration");
        duration->setGeometry(QRect(380, 10, 71, 16));
        labelremain = new QLabel(FlightItemWidget);
        labelremain->setObjectName("labelremain");
        labelremain->setGeometry(QRect(680, 40, 81, 16));

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
        btnSelect->setText(QCoreApplication::translate("FlightItemWidget", "\351\200\211\344\270\272\345\216\273\347\250\213", nullptr));
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
