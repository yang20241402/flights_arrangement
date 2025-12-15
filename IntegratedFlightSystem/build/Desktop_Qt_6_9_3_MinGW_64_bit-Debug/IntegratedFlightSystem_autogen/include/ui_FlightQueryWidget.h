/********************************************************************************
** Form generated from reading UI file 'flightquerywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTQUERYWIDGET_H
#define UI_FLIGHTQUERYWIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightQueryWidget
{
public:
    QWidget *flightQueryWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_depart;
    QLineEdit *edit_depart;
    QLabel *label_dest;
    QLineEdit *edit_dest;
    QLabel *label_date;
    QDateEdit *dateEdit;
    QPushButton *btn_queryFlight;
    QPushButton *btn_showAllFlights;
    QWidget *flightListWidget;
    QVBoxLayout *verticalLayout_flight;
    QTableWidget *flightTable;
    QLabel *label;

    void setupUi(QDialog *FlightQueryWidget)
    {
        if (FlightQueryWidget->objectName().isEmpty())
            FlightQueryWidget->setObjectName("FlightQueryWidget");
        FlightQueryWidget->resize(1142, 519);
        FlightQueryWidget->setMinimumSize(QSize(800, 320));
        flightQueryWidget = new QWidget(FlightQueryWidget);
        flightQueryWidget->setObjectName("flightQueryWidget");
        flightQueryWidget->setGeometry(QRect(0, 0, 1071, 81));
        flightQueryWidget->setStyleSheet(QString::fromUtf8("background-color: #F8F9FA; border-radius: 8px; margin: 0 10px;"));
        horizontalLayout = new QHBoxLayout(flightQueryWidget);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 15, 20, 15);
        label_depart = new QLabel(flightQueryWidget);
        label_depart->setObjectName("label_depart");
        label_depart->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setPointSize(12);
        label_depart->setFont(font);
        label_depart->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_depart);

        edit_depart = new QLineEdit(flightQueryWidget);
        edit_depart->setObjectName("edit_depart");
        edit_depart->setMinimumSize(QSize(120, 30));
        edit_depart->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(edit_depart);

        label_dest = new QLabel(flightQueryWidget);
        label_dest->setObjectName("label_dest");
        label_dest->setMinimumSize(QSize(60, 0));
        label_dest->setFont(font);
        label_dest->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_dest);

        edit_dest = new QLineEdit(flightQueryWidget);
        edit_dest->setObjectName("edit_dest");
        edit_dest->setMinimumSize(QSize(120, 30));
        edit_dest->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(edit_dest);

        label_date = new QLabel(flightQueryWidget);
        label_date->setObjectName("label_date");
        label_date->setMinimumSize(QSize(70, 0));
        label_date->setFont(font);
        label_date->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_date);

        dateEdit = new QDateEdit(flightQueryWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setMinimumSize(QSize(140, 30));
        dateEdit->setMaximumSize(QSize(150, 30));
        QFont font1;
        font1.setPointSize(9);
        dateEdit->setFont(font1);
        dateEdit->setStyleSheet(QString::fromUtf8("\n"
"        QDateEdit {\n"
"            border: 1px solid #ddd;\n"
"            border-radius: 4px;\n"
"        }\n"
"	QCalendarWidget {\n"
"        font-size: 14px;       \n"
"        min-width: 350px;      \n"
"        min-height: 300px;    \n"
"        selection-background-color: #1E90FF; \n"
"    }\n"
"    QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"        min-height: 40px;      \n"
"        font-size: 16px;      \n"
"    }\n"
"    QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"        min-height: 40px;      \n"
"        font-size: 16px;       \n"
"        background-color: #f8f9fa; \n"
"    }\n"
"    QCalendarWidget QToolButton {\n"
"        color: #333;           \n"
"        font-size: 16px;       \n"
"        border: none;          \n"
"        background: transparent; \n"
"        min-width: 40px;       \n"
"    }\n"
"    QCalendarWidget QHeaderView::section {\n"
"        min-height: 35px;      \n"
"        font-size: 14px;       \n"
"        font-weight: bold;\n"
"    }\n"
"   "
                        " QCalendarWidget QTableView::item {\n"
"        min-height: 35px;      \n"
"        min-width: 35px;     \n"
"        font-size: 14px;       \n"
"    }\n"
"    QCalendarWidget QTableView::item:hover {\n"
"        background-color: #e6f7ff;\n"
"        border-radius: 4px;\n"
"    }\n"
"       "));
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::TimeSpec::UTC);
        dateEdit->setDate(QDate(2025, 11, 13));

        horizontalLayout->addWidget(dateEdit);

        btn_queryFlight = new QPushButton(flightQueryWidget);
        btn_queryFlight->setObjectName("btn_queryFlight");
        btn_queryFlight->setMinimumSize(QSize(100, 30));
        btn_queryFlight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 6px 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4169E1;\n"
"}"));

        horizontalLayout->addWidget(btn_queryFlight);

        btn_showAllFlights = new QPushButton(flightQueryWidget);
        btn_showAllFlights->setObjectName("btn_showAllFlights");
        btn_showAllFlights->setMinimumSize(QSize(100, 30));
        btn_showAllFlights->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2ECC71;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 6px 20px;\n"
"    margin-left: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #27AE60;\n"
"}"));

        horizontalLayout->addWidget(btn_showAllFlights);

        flightListWidget = new QWidget(FlightQueryWidget);
        flightListWidget->setObjectName("flightListWidget");
        flightListWidget->setGeometry(QRect(0, 80, 1071, 361));
        verticalLayout_flight = new QVBoxLayout(flightListWidget);
        verticalLayout_flight->setObjectName("verticalLayout_flight");
        verticalLayout_flight->setContentsMargins(10, 10, 10, -1);
        flightTable = new QTableWidget(flightListWidget);
        if (flightTable->columnCount() < 13)
            flightTable->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        flightTable->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        flightTable->setObjectName("flightTable");
        flightTable->setMinimumSize(QSize(0, 220));
        flightTable->setStyleSheet(QString::fromUtf8(" QTableWidget {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 8px;\n"
"        padding: 5px;\n"
"        gridline-color: #f0f0f0;\n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: #f8f9fa;\n"
"        font-weight: bold;\n"
"        color: #333333;\n"
"        padding: 8px;\n"
"        border: none;\n"
"        border-bottom: 1px solid #e0e0e0;\n"
"    }\n"
"    QTableWidget::item:even {\n"
"        background-color: #fcfcfc;\n"
"    }\n"
"    QTableWidget::item:odd {\n"
"        background-color: #f9f9f9;\n"
"    }\n"
"    QTableWidget::item:hover {\n"
"        background-color: #e6f7ff;\n"
"    }\n"
"    QTableWidget::item {\n"
"        padding: 6px;\n"
"        color: #333333;\n"
"    }"));
        flightTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        flightTable->setAlternatingRowColors(false);
        flightTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        flightTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        flightTable->setColumnCount(13);
        flightTable->horizontalHeader()->setVisible(true);
        flightTable->verticalHeader()->setVisible(false);

        verticalLayout_flight->addWidget(flightTable);

        label = new QLabel(FlightQueryWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 440, 201, 21));

        retranslateUi(FlightQueryWidget);

        QMetaObject::connectSlotsByName(FlightQueryWidget);
    } // setupUi

    void retranslateUi(QDialog *FlightQueryWidget)
    {
        FlightQueryWidget->setWindowTitle(QCoreApplication::translate("FlightQueryWidget", "\350\210\252\347\217\255\345\212\250\346\200\201\346\237\245\350\257\242", nullptr));
        label_depart->setText(QCoreApplication::translate("FlightQueryWidget", " \345\207\272\345\217\221\345\234\260\357\274\232", nullptr));
        edit_depart->setPlaceholderText(QCoreApplication::translate("FlightQueryWidget", "\345\246\202\357\274\232\345\214\227\344\272\254", nullptr));
        label_dest->setText(QCoreApplication::translate("FlightQueryWidget", " \347\233\256\347\232\204\345\234\260\357\274\232", nullptr));
        edit_dest->setPlaceholderText(QCoreApplication::translate("FlightQueryWidget", "\345\246\202\357\274\232\344\270\212\346\265\267", nullptr));
        label_date->setText(QCoreApplication::translate("FlightQueryWidget", " \345\207\272\345\217\221\346\227\245\346\234\237\357\274\232", nullptr));
        btn_queryFlight->setText(QCoreApplication::translate("FlightQueryWidget", " \346\237\245\350\257\242\350\210\252\347\217\255 ", nullptr));
        btn_showAllFlights->setText(QCoreApplication::translate("FlightQueryWidget", " \346\230\276\347\244\272\346\211\200\346\234\211\350\210\252\347\217\255 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flightTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FlightQueryWidget", "\350\210\252\347\217\255ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flightTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FlightQueryWidget", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = flightTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FlightQueryWidget", "\350\210\252\347\251\272\345\205\254\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = flightTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("FlightQueryWidget", "\345\207\272\345\217\221\345\237\216\345\270\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = flightTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("FlightQueryWidget", "\345\207\272\345\217\221\346\234\272\345\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = flightTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("FlightQueryWidget", "\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = flightTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("FlightQueryWidget", "\345\210\260\350\276\276\345\237\216\345\270\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = flightTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("FlightQueryWidget", "\345\210\260\350\276\276\346\234\272\345\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = flightTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("FlightQueryWidget", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = flightTable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("FlightQueryWidget", "\346\234\272\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = flightTable->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("FlightQueryWidget", "\351\243\236\350\241\214\346\227\266\351\225\277(\345\210\206\351\222\237)", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = flightTable->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("FlightQueryWidget", "\346\200\273\345\272\247\344\275\215\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = flightTable->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("FlightQueryWidget", "\345\211\251\344\275\231\345\272\247\344\275\215\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("FlightQueryWidget", "tips:\345\217\214\345\207\273\345\217\257\346\237\245\347\234\213\350\210\252\347\217\255\350\257\246\346\203\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightQueryWidget: public Ui_FlightQueryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTQUERYWIDGET_H
