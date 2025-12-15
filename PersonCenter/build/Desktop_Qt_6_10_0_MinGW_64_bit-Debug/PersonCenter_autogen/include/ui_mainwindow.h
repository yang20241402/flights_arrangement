/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PcMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *topUserWidget;
    QLabel *label;
    QLabel *labNickname;
    QLabel *userIdLabel;
    QPushButton *editBtn;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QPushButton *myPointsBtn;
    QPushButton *myOrderBtn;
    QPushButton *myMsgBtn;
    QPushButton *commonInfoBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PcMainWindow)
    {
        if (PcMainWindow->objectName().isEmpty())
            PcMainWindow->setObjectName("PcMainWindow");
        PcMainWindow->resize(800, 600);
        PcMainWindow->setMinimumSize(QSize(800, 600));
        PcMainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(PcMainWindow);
        centralwidget->setObjectName("centralwidget");
        topUserWidget = new QWidget(centralwidget);
        topUserWidget->setObjectName("topUserWidget");
        topUserWidget->setGeometry(QRect(0, 0, 800, 120));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topUserWidget->sizePolicy().hasHeightForWidth());
        topUserWidget->setSizePolicy(sizePolicy);
        topUserWidget->setMinimumSize(QSize(400, 0));
        label = new QLabel(topUserWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 80, 80));
        label->setStyleSheet(QString::fromUtf8("border-radius: 40px; \n"
"border: 2px solid #E0E0E0;\n"
"background-image: url(E:/QtProject/PersonCenter/avatar.png); \n"
"background-repeat: no-repeat;\n"
"background-size: cover;"));
        labNickname = new QLabel(topUserWidget);
        labNickname->setObjectName("labNickname");
        labNickname->setGeometry(QRect(110, 20, 400, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        font.setBold(true);
        labNickname->setFont(font);
        userIdLabel = new QLabel(topUserWidget);
        userIdLabel->setObjectName("userIdLabel");
        userIdLabel->setGeometry(QRect(110, 50, 400, 16));
        sizePolicy.setHeightForWidth(userIdLabel->sizePolicy().hasHeightForWidth());
        userIdLabel->setSizePolicy(sizePolicy);
        userIdLabel->setMinimumSize(QSize(400, 0));
        QFont font1;
        font1.setPointSize(12);
        userIdLabel->setFont(font1);
        userIdLabel->setStyleSheet(QString::fromUtf8("color: #888888;"));
        editBtn = new QPushButton(topUserWidget);
        editBtn->setObjectName("editBtn");
        editBtn->setGeometry(QRect(690, 50, 100, 30));
        editBtn->setFont(font1);
        editBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #1E90FF;\n"
"    color: #1E90FF;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"}"));
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setGeometry(QRect(0, 120, 800, 120));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy1);
        gridWidget->setMinimumSize(QSize(800, 120));
        gridWidget->setMaximumSize(QSize(800, 120));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, -1, 20, -1);
        myPointsBtn = new QPushButton(gridWidget);
        myPointsBtn->setObjectName("myPointsBtn");
        sizePolicy1.setHeightForWidth(myPointsBtn->sizePolicy().hasHeightForWidth());
        myPointsBtn->setSizePolicy(sizePolicy1);
        myPointsBtn->setMinimumSize(QSize(120, 50));
        myPointsBtn->setMaximumSize(QSize(120, 50));
        myPointsBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; /* \346\226\207\345\255\227\345\261\205\344\270\255 */\n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"    border-radius: 8px;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 002708.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myPointsBtn->setIcon(icon);
        myPointsBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(myPointsBtn, 0, 2, 1, 1);

        myOrderBtn = new QPushButton(gridWidget);
        myOrderBtn->setObjectName("myOrderBtn");
        sizePolicy1.setHeightForWidth(myOrderBtn->sizePolicy().hasHeightForWidth());
        myOrderBtn->setSizePolicy(sizePolicy1);
        myOrderBtn->setMinimumSize(QSize(120, 50));
        myOrderBtn->setMaximumSize(QSize(120, 50));
        myOrderBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"	padding 8px 0;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 002625.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myOrderBtn->setIcon(icon1);
        myOrderBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(myOrderBtn, 0, 0, 1, 1);

        myMsgBtn = new QPushButton(gridWidget);
        myMsgBtn->setObjectName("myMsgBtn");
        sizePolicy1.setHeightForWidth(myMsgBtn->sizePolicy().hasHeightForWidth());
        myMsgBtn->setSizePolicy(sizePolicy1);
        myMsgBtn->setMinimumSize(QSize(120, 50));
        myMsgBtn->setMaximumSize(QSize(120, 50));
        myMsgBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\276\256\344\277\241\345\233\276\347\211\207_20251201200211_148_9.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myMsgBtn->setIcon(icon2);
        myMsgBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(myMsgBtn, 0, 3, 1, 1);

        commonInfoBtn = new QPushButton(gridWidget);
        commonInfoBtn->setObjectName("commonInfoBtn");
        sizePolicy1.setHeightForWidth(commonInfoBtn->sizePolicy().hasHeightForWidth());
        commonInfoBtn->setSizePolicy(sizePolicy1);
        commonInfoBtn->setMinimumSize(QSize(120, 50));
        commonInfoBtn->setMaximumSize(QSize(120, 50));
        commonInfoBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 002743.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        commonInfoBtn->setIcon(icon3);
        commonInfoBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(commonInfoBtn, 0, 1, 1, 1);

        PcMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PcMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        PcMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PcMainWindow);
        statusbar->setObjectName("statusbar");
        PcMainWindow->setStatusBar(statusbar);

        retranslateUi(PcMainWindow);

        QMetaObject::connectSlotsByName(PcMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PcMainWindow)
    {
        PcMainWindow->setWindowTitle(QCoreApplication::translate("PcMainWindow", "MainWindow", nullptr));
        label->setText(QString());
        labNickname->setText(QString());
        userIdLabel->setText(QCoreApplication::translate("PcMainWindow", "\347\224\250\346\210\267 ID\357\274\232FS2024001", nullptr));
        editBtn->setText(QCoreApplication::translate("PcMainWindow", "\347\274\226\350\276\221\350\265\204\346\226\231", nullptr));
        myPointsBtn->setText(QCoreApplication::translate("PcMainWindow", "\346\210\221\347\232\204\347\247\257\345\210\206", nullptr));
        myOrderBtn->setText(QCoreApplication::translate("PcMainWindow", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        myMsgBtn->setText(QCoreApplication::translate("PcMainWindow", "\346\210\221\347\232\204\346\266\210\346\201\257", nullptr));
        commonInfoBtn->setText(QCoreApplication::translate("PcMainWindow", "\345\270\270\347\224\250\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PcMainWindow: public Ui_PcMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
