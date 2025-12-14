/********************************************************************************
** Form generated from reading UI file 'pointsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTSDIALOG_H
#define UI_POINTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PointsDialog
{
public:
    QTableWidget *pointsTable;
    QLabel *totalPointsLabel;
    QLabel *ruleLabel;
    QPushButton *refreshBtn;

    void setupUi(QDialog *PointsDialog)
    {
        if (PointsDialog->objectName().isEmpty())
            PointsDialog->setObjectName("PointsDialog");
        PointsDialog->resize(400, 300);
        pointsTable = new QTableWidget(PointsDialog);
        if (pointsTable->columnCount() < 4)
            pointsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pointsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pointsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        pointsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        pointsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        pointsTable->setObjectName("pointsTable");
        pointsTable->setGeometry(QRect(6, 30, 388, 172));
        pointsTable->setStyleSheet(QString::fromUtf8(" QTableWidget {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 8px;\n"
"        padding: 5px;\n"
"        gridline-color: #f0f0f0;\n"
"    }\n"
"    /* \350\241\250\345\244\264\357\274\232\346\265\205\347\201\260\350\211\262\350\203\214\346\231\257+\345\212\240\347\262\227\346\226\207\345\255\227 */\n"
"    QHeaderView::section {\n"
"        background-color: #f8f9fa;\n"
"        font-weight: bold;\n"
"        color: #333333;\n"
"        padding: 8px;\n"
"        border: none;\n"
"        border-bottom: 1px solid #e0e0e0;\n"
"    }\n"
"    /* \350\241\250\346\240\274\350\241\214\357\274\232\351\232\224\350\241\214\345\217\230\350\211\262 */\n"
"    QTableWidget::item:even {\n"
"        background-color: #fcfcfc;\n"
"    }\n"
"    QTableWidget::item:odd {\n"
"        background-color: #f9f9f9;\n"
"    }\n"
"    /* \351\274\240\346\240\207 hover \350\241\214\357\274\232\351\253\230\344\272\256 */\n"
"    QTableWidget::item:hover {\n"
"        background-c"
                        "olor: #e6f7ff;\n"
"    }\n"
"    /* \350\241\250\346\240\274\346\226\207\345\255\227\357\274\232\347\273\237\344\270\200\345\255\227\344\275\223 */\n"
"    QTableWidget::item {\n"
"        padding: 6px;\n"
"        color: #333333;\n"
"    }"));
        pointsTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        pointsTable->setColumnCount(4);
        pointsTable->horizontalHeader()->setStretchLastSection(true);
        totalPointsLabel = new QLabel(PointsDialog);
        totalPointsLabel->setObjectName("totalPointsLabel");
        totalPointsLabel->setGeometry(QRect(6, 6, 388, 20));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(150);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(totalPointsLabel->sizePolicy().hasHeightForWidth());
        totalPointsLabel->setSizePolicy(sizePolicy);
        totalPointsLabel->setMinimumSize(QSize(150, 20));
        totalPointsLabel->setStyleSheet(QString::fromUtf8("font-size:16px;\n"
"color:#FF6700;\n"
"font-weight:bold;"));
        ruleLabel = new QLabel(PointsDialog);
        ruleLabel->setObjectName("ruleLabel");
        ruleLabel->setGeometry(QRect(0, 190, 321, 50));
        ruleLabel->setStyleSheet(QString::fromUtf8("color:#666;\n"
"line-height:1.5;\n"
"padding: 10px;\n"
"        border-radius: 6px;\n"
"        border: 1px solid #f0f0f0;"));
        refreshBtn = new QPushButton(PointsDialog);
        refreshBtn->setObjectName("refreshBtn");
        refreshBtn->setGeometry(QRect(330, 270, 60, 24));
        refreshBtn->setStyleSheet(QString::fromUtf8("background:#aaffff\357\274\233\n"
"color:white;\n"
"border:none;\n"
"border-radius:4px;\n"
"padding:6px 12px;"));

        retranslateUi(PointsDialog);

        QMetaObject::connectSlotsByName(PointsDialog);
    } // setupUi

    void retranslateUi(QDialog *PointsDialog)
    {
        PointsDialog->setWindowTitle(QCoreApplication::translate("PointsDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = pointsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PointsDialog", "\347\247\257\345\210\206\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = pointsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PointsDialog", "\347\247\257\345\210\206\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = pointsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PointsDialog", "\350\216\267\345\217\226\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = pointsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PointsDialog", "\345\244\207\346\263\250", nullptr));
        totalPointsLabel->setText(QCoreApplication::translate("PointsDialog", "\345\275\223\345\211\215\346\200\273\347\247\257\345\210\206\357\274\2320", nullptr));
        ruleLabel->setText(QCoreApplication::translate("PointsDialog", "<html><head/><body><p>\347\247\257\345\210\206\350\247\204\345\210\231\357\274\2321.\346\263\250\345\206\214\350\265\240\351\200\201100\347\247\257\345\210\206       2.\346\257\217\346\266\210\350\264\2711\345\205\203\347\264\257\347\247\2571\347\247\257\345\210\206      3.\347\247\257\345\210\206\345\217\257\345\205\221\346\215\242\344\274\230\346\203\240\345\210\270/\346\212\265\346\211\243\350\264\271\347\224\250\357\274\233</p></body></html>", nullptr));
        refreshBtn->setText(QCoreApplication::translate("PointsDialog", "\345\210\267\346\226\260\347\247\257\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PointsDialog: public Ui_PointsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTSDIALOG_H
