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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *topUserWidget;
    QLabel *label;
    QLabel *nicknameLabel;
    QLabel *userIdLabel;
    QPushButton *editBtn;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QPushButton *couponBtn;
    QPushButton *helpCenterBtn;
    QPushButton *commonInfoBtn;
    QPushButton *flightStatusBtn;
    QPushButton *settingBtn;
    QPushButton *feedbackBtn;
    QPushButton *myPointsBtn;
    QPushButton *myOrderBtn;
    QWidget *statsWidget;
    QVBoxLayout *verticalLayout;
    QWidget *tripWidget;
    QLabel *tripNumLabel;
    QLabel *label_3;
    QWidget *pointWidget;
    QWidget *couponStatsWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
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
        nicknameLabel = new QLabel(topUserWidget);
        nicknameLabel->setObjectName("nicknameLabel");
        nicknameLabel->setGeometry(QRect(110, 20, 400, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        font.setBold(true);
        nicknameLabel->setFont(font);
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
        couponBtn = new QPushButton(gridWidget);
        couponBtn->setObjectName("couponBtn");
        sizePolicy1.setHeightForWidth(couponBtn->sizePolicy().hasHeightForWidth());
        couponBtn->setSizePolicy(sizePolicy1);
        couponBtn->setMinimumSize(QSize(120, 50));
        couponBtn->setMaximumSize(QSize(120, 50));
        couponBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 011126.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        couponBtn->setIcon(icon);
        couponBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(couponBtn, 1, 0, 1, 1);

        helpCenterBtn = new QPushButton(gridWidget);
        helpCenterBtn->setObjectName("helpCenterBtn");
        sizePolicy1.setHeightForWidth(helpCenterBtn->sizePolicy().hasHeightForWidth());
        helpCenterBtn->setSizePolicy(sizePolicy1);
        helpCenterBtn->setMinimumSize(QSize(120, 50));
        helpCenterBtn->setMaximumSize(QSize(120, 50));
        helpCenterBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:#F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Downloads/\346\214\211\347\211\271\345\256\232\351\243\216\346\240\274\347\224\237\346\210\220\345\233\276\346\241\210 (2).png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        helpCenterBtn->setIcon(icon1);
        helpCenterBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(helpCenterBtn, 1, 2, 1, 1);

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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 002743.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        commonInfoBtn->setIcon(icon2);
        commonInfoBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(commonInfoBtn, 0, 1, 1, 1);

        flightStatusBtn = new QPushButton(gridWidget);
        flightStatusBtn->setObjectName("flightStatusBtn");
        sizePolicy1.setHeightForWidth(flightStatusBtn->sizePolicy().hasHeightForWidth());
        flightStatusBtn->setSizePolicy(sizePolicy1);
        flightStatusBtn->setMinimumSize(QSize(120, 50));
        flightStatusBtn->setMaximumSize(QSize(120, 50));
        flightStatusBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon3.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-26 235831.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        flightStatusBtn->setIcon(icon3);
        flightStatusBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(flightStatusBtn, 0, 3, 1, 1);

        settingBtn = new QPushButton(gridWidget);
        settingBtn->setObjectName("settingBtn");
        sizePolicy1.setHeightForWidth(settingBtn->sizePolicy().hasHeightForWidth());
        settingBtn->setSizePolicy(sizePolicy1);
        settingBtn->setMinimumSize(QSize(120, 50));
        settingBtn->setMaximumSize(QSize(120, 50));
        settingBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Downloads/\346\214\211\347\211\271\345\256\232\351\243\216\346\240\274\347\224\237\346\210\220\345\233\276\346\241\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingBtn->setIcon(icon4);
        settingBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(settingBtn, 1, 1, 1, 1);

        feedbackBtn = new QPushButton(gridWidget);
        feedbackBtn->setObjectName("feedbackBtn");
        sizePolicy1.setHeightForWidth(feedbackBtn->sizePolicy().hasHeightForWidth());
        feedbackBtn->setSizePolicy(sizePolicy1);
        feedbackBtn->setMinimumSize(QSize(120, 50));
        feedbackBtn->setMaximumSize(QSize(120, 50));
        feedbackBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    text-align: center; \n"
"    font-size: 15px;\n"
"    color: #333333;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:#F0F8FF;\n"
"    border-radius: 8px;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Downloads/\346\214\211\347\211\271\345\256\232\351\243\216\346\240\274\347\224\237\346\210\220\345\233\276\346\241\210 (3).png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        feedbackBtn->setIcon(icon5);
        feedbackBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(feedbackBtn, 1, 3, 1, 1);

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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 002708.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myPointsBtn->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("C:/Users/\346\235\250\346\226\207\347\216\262/Pictures/Screenshots/\345\261\217\345\271\225\346\210\252\345\233\276 2025-11-27 002625.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myOrderBtn->setIcon(icon7);
        myOrderBtn->setIconSize(QSize(35, 35));

        gridLayout->addWidget(myOrderBtn, 0, 0, 1, 1);

        statsWidget = new QWidget(centralwidget);
        statsWidget->setObjectName("statsWidget");
        statsWidget->setGeometry(QRect(0, 240, 800, 100));
        statsWidget->setMinimumSize(QSize(800, 100));
        statsWidget->setMaximumSize(QSize(800, 100));
        verticalLayout = new QVBoxLayout(statsWidget);
        verticalLayout->setObjectName("verticalLayout");
        tripWidget = new QWidget(statsWidget);
        tripWidget->setObjectName("tripWidget");
        tripWidget->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"border-radius: 8px;\n"
"box-shadow: 0 2px 4px rgba(0,0,0,0.05); "));
        tripNumLabel = new QLabel(tripWidget);
        tripNumLabel->setObjectName("tripNumLabel");
        tripNumLabel->setGeometry(QRect(30, 10, 40, 12));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(24);
        font2.setBold(true);
        tripNumLabel->setFont(font2);
        label_3 = new QLabel(tripWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 10, 40, 12));

        verticalLayout->addWidget(tripWidget);

        pointWidget = new QWidget(statsWidget);
        pointWidget->setObjectName("pointWidget");
        pointWidget->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"border-radius: 8px;\n"
"box-shadow: 0 2px 4px rgba(0,0,0,0.05); "));

        verticalLayout->addWidget(pointWidget);

        couponStatsWidget = new QWidget(statsWidget);
        couponStatsWidget->setObjectName("couponStatsWidget");
        couponStatsWidget->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"border-radius: 8px;\n"
"box-shadow: 0 2px 4px rgba(0,0,0,0.05); "));

        verticalLayout->addWidget(couponStatsWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        nicknameLabel->setText(QCoreApplication::translate("MainWindow", "\345\274\240\344\270\211\357\274\210\346\231\256\351\200\232\344\274\232\345\221\230\357\274\211", nullptr));
        userIdLabel->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267 ID\357\274\232FS2024001", nullptr));
        editBtn->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\265\204\346\226\231", nullptr));
        couponBtn->setText(QCoreApplication::translate("MainWindow", " \344\274\230\346\203\240\345\210\270", nullptr));
        helpCenterBtn->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251\344\270\255\345\277\203", nullptr));
        commonInfoBtn->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\224\250\344\277\241\346\201\257", nullptr));
        flightStatusBtn->setText(QCoreApplication::translate("MainWindow", "\350\210\252\347\217\255\345\212\250\346\200\201", nullptr));
        settingBtn->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        feedbackBtn->setText(QCoreApplication::translate("MainWindow", "\346\204\217\350\247\201\345\217\215\351\246\210", nullptr));
        myPointsBtn->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\347\247\257\345\210\206", nullptr));
        myOrderBtn->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        tripNumLabel->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
