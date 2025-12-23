/********************************************************************************
** Form generated from reading UI file 'mymsgdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMSGDIALOG_H
#define UI_MYMSGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_mymsgdialog
{
public:
    QPushButton *allMsgBtn;
    QPushButton *unreadMsgBtn;
    QTableWidget *msgTable;
    QPushButton *markReadBtn;
    QPushButton *deleteBtn;

    void setupUi(QDialog *mymsgdialog)
    {
        if (mymsgdialog->objectName().isEmpty())
            mymsgdialog->setObjectName("mymsgdialog");
        mymsgdialog->resize(400, 300);
        allMsgBtn = new QPushButton(mymsgdialog);
        allMsgBtn->setObjectName("allMsgBtn");
        allMsgBtn->setGeometry(QRect(50, 10, 56, 18));
        unreadMsgBtn = new QPushButton(mymsgdialog);
        unreadMsgBtn->setObjectName("unreadMsgBtn");
        unreadMsgBtn->setGeometry(QRect(290, 10, 56, 18));
        msgTable = new QTableWidget(mymsgdialog);
        if (msgTable->columnCount() < 4)
            msgTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        msgTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        msgTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        msgTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        msgTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        msgTable->setObjectName("msgTable");
        msgTable->setGeometry(QRect(0, 30, 400, 270));
        msgTable->setMinimumSize(QSize(400, 270));
        msgTable->setMaximumSize(QSize(400, 270));
        msgTable->setAutoScroll(true);
        msgTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        msgTable->setColumnCount(4);
        msgTable->verticalHeader()->setStretchLastSection(false);
        markReadBtn = new QPushButton(mymsgdialog);
        markReadBtn->setObjectName("markReadBtn");
        markReadBtn->setGeometry(QRect(210, 270, 56, 18));
        deleteBtn = new QPushButton(mymsgdialog);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setGeometry(QRect(340, 270, 56, 18));

        retranslateUi(mymsgdialog);

        QMetaObject::connectSlotsByName(mymsgdialog);
    } // setupUi

    void retranslateUi(QDialog *mymsgdialog)
    {
        mymsgdialog->setWindowTitle(QCoreApplication::translate("mymsgdialog", "Dialog", nullptr));
        allMsgBtn->setText(QCoreApplication::translate("mymsgdialog", "\345\205\250\351\203\250\346\266\210\346\201\257", nullptr));
        unreadMsgBtn->setText(QCoreApplication::translate("mymsgdialog", "\346\234\252\350\257\273\346\266\210\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem = msgTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mymsgdialog", "\346\240\207\351\242\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = msgTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mymsgdialog", "\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = msgTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("mymsgdialog", "\345\217\221\351\200\201\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = msgTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("mymsgdialog", "\347\212\266\346\200\201", nullptr));
        markReadBtn->setText(QCoreApplication::translate("mymsgdialog", "\346\240\207\350\256\260\345\267\262\350\257\273", nullptr));
        deleteBtn->setText(QCoreApplication::translate("mymsgdialog", "\345\210\240\351\231\244\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mymsgdialog: public Ui_mymsgdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMSGDIALOG_H
