/********************************************************************************
** Form generated from reading UI file 'myorderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYORDERDIALOG_H
#define UI_MYORDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyOrderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *menuWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *allOrderBtn;
    QPushButton *unpaidOrderBtn;
    QPushButton *upcomingOrderBtn;
    QPushButton *finishedOrderBtn;
    QPushButton *cancelledOrderBtn;
    QTableWidget *orderTable;

    void setupUi(QDialog *MyOrderDialog)
    {
        if (MyOrderDialog->objectName().isEmpty())
            MyOrderDialog->setObjectName("MyOrderDialog");
        MyOrderDialog->resize(462, 299);
        verticalLayout = new QVBoxLayout(MyOrderDialog);
        verticalLayout->setObjectName("verticalLayout");
        menuWidget = new QWidget(MyOrderDialog);
        menuWidget->setObjectName("menuWidget");
        menuWidget->setMinimumSize(QSize(450, 40));
        menuWidget->setMaximumSize(QSize(450, 40));
        menuWidget->setStyleSheet(QString::fromUtf8("color:#FF6700"));
        horizontalLayout = new QHBoxLayout(menuWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        allOrderBtn = new QPushButton(menuWidget);
        allOrderBtn->setObjectName("allOrderBtn");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        allOrderBtn->setFont(font);
        allOrderBtn->setStyleSheet(QString::fromUtf8("background:transparent;color:#333;border:none;padding:4px 12px;"));

        horizontalLayout->addWidget(allOrderBtn);

        unpaidOrderBtn = new QPushButton(menuWidget);
        unpaidOrderBtn->setObjectName("unpaidOrderBtn");
        unpaidOrderBtn->setFont(font);
        unpaidOrderBtn->setStyleSheet(QString::fromUtf8("background:transparent;color:#333;border:none;padding:4px 12px;"));

        horizontalLayout->addWidget(unpaidOrderBtn);

        upcomingOrderBtn = new QPushButton(menuWidget);
        upcomingOrderBtn->setObjectName("upcomingOrderBtn");
        upcomingOrderBtn->setFont(font);
        upcomingOrderBtn->setStyleSheet(QString::fromUtf8("background:transparent;color:#333;border:none;padding:4px 12px;"));

        horizontalLayout->addWidget(upcomingOrderBtn);

        finishedOrderBtn = new QPushButton(menuWidget);
        finishedOrderBtn->setObjectName("finishedOrderBtn");
        finishedOrderBtn->setFont(font);
        finishedOrderBtn->setStyleSheet(QString::fromUtf8("background:transparent;color:#333;border:none;padding:4px 12px;"));

        horizontalLayout->addWidget(finishedOrderBtn);

        cancelledOrderBtn = new QPushButton(menuWidget);
        cancelledOrderBtn->setObjectName("cancelledOrderBtn");
        cancelledOrderBtn->setFont(font);
        cancelledOrderBtn->setStyleSheet(QString::fromUtf8("background:transparent;color:#333;border:none;padding:4px 12px;"));

        horizontalLayout->addWidget(cancelledOrderBtn);


        verticalLayout->addWidget(menuWidget);

        orderTable = new QTableWidget(MyOrderDialog);
        if (orderTable->columnCount() < 6)
            orderTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        orderTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        orderTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        orderTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        orderTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        orderTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        orderTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        orderTable->setObjectName("orderTable");
        orderTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        orderTable->setColumnCount(6);

        verticalLayout->addWidget(orderTable);


        retranslateUi(MyOrderDialog);

        QMetaObject::connectSlotsByName(MyOrderDialog);
    } // setupUi

    void retranslateUi(QDialog *MyOrderDialog)
    {
        MyOrderDialog->setWindowTitle(QCoreApplication::translate("MyOrderDialog", "Dialog", nullptr));
        allOrderBtn->setText(QCoreApplication::translate("MyOrderDialog", "\345\205\250\351\203\250\350\256\242\345\215\225", nullptr));
        unpaidOrderBtn->setText(QCoreApplication::translate("MyOrderDialog", "\346\234\252\346\224\257\344\273\230", nullptr));
        upcomingOrderBtn->setText(QCoreApplication::translate("MyOrderDialog", "\345\276\205\345\207\272\350\241\214", nullptr));
        finishedOrderBtn->setText(QCoreApplication::translate("MyOrderDialog", "\345\267\262\345\256\214\346\210\220", nullptr));
        cancelledOrderBtn->setText(QCoreApplication::translate("MyOrderDialog", "\345\267\262\345\217\226\346\266\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem = orderTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MyOrderDialog", "\350\256\242\345\215\225\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = orderTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MyOrderDialog", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = orderTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MyOrderDialog", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = orderTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MyOrderDialog", "\347\233\256\347\232\204\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = orderTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MyOrderDialog", "\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = orderTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MyOrderDialog", "\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyOrderDialog: public Ui_MyOrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYORDERDIALOG_H
