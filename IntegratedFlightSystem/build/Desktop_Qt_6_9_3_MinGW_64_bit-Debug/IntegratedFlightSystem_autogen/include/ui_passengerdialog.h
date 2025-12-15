/********************************************************************************
** Form generated from reading UI file 'passengerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERDIALOG_H
#define UI_PASSENGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PassengerDialog
{
public:
    QTableWidget *passengerTable;
    QPushButton *addBtn;
    QPushButton *editBtn;
    QPushButton *deleteBtn;

    void setupUi(QDialog *PassengerDialog)
    {
        if (PassengerDialog->objectName().isEmpty())
            PassengerDialog->setObjectName("PassengerDialog");
        PassengerDialog->resize(400, 300);
        passengerTable = new QTableWidget(PassengerDialog);
        if (passengerTable->columnCount() < 4)
            passengerTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        passengerTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        passengerTable->setObjectName("passengerTable");
        passengerTable->setGeometry(QRect(0, 0, 401, 261));
        passengerTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        passengerTable->setColumnCount(4);
        passengerTable->horizontalHeader()->setStretchLastSection(true);
        addBtn = new QPushButton(PassengerDialog);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(101, 271, 50, 24));
        addBtn->setStyleSheet(QString::fromUtf8("background:#1E90FF;\n"
"color:white;\n"
"border:none;\n"
"border-radius:4px;\n"
"padding:6px 12px;\n"
"text-align: center; "));
        editBtn = new QPushButton(PassengerDialog);
        editBtn->setObjectName("editBtn");
        editBtn->setGeometry(QRect(223, 271, 50, 24));
        editBtn->setStyleSheet(QString::fromUtf8("background:#1E90FF;\n"
"color:white;\n"
"border:none;\n"
"border-radius:4px;\n"
"padding:6px 12px;\n"
"text-align: center; "));
        deleteBtn = new QPushButton(PassengerDialog);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setGeometry(QRect(345, 271, 50, 24));
        deleteBtn->setStyleSheet(QString::fromUtf8("background:#FF4444;\n"
"color:white;\n"
"border:none;\n"
"border-radius:4px;\n"
"padding:6px 12px;\n"
"text-align: center; "));

        retranslateUi(PassengerDialog);

        QMetaObject::connectSlotsByName(PassengerDialog);
    } // setupUi

    void retranslateUi(QDialog *PassengerDialog)
    {
        PassengerDialog->setWindowTitle(QCoreApplication::translate("PassengerDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = passengerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PassengerDialog", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = passengerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PassengerDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = passengerTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PassengerDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = passengerTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PassengerDialog", "\346\223\215\344\275\234", nullptr));
        addBtn->setText(QCoreApplication::translate("PassengerDialog", "\346\267\273\345\212\240", nullptr));
        editBtn->setText(QCoreApplication::translate("PassengerDialog", "\344\277\256\346\224\271", nullptr));
        deleteBtn->setText(QCoreApplication::translate("PassengerDialog", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassengerDialog: public Ui_PassengerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERDIALOG_H
