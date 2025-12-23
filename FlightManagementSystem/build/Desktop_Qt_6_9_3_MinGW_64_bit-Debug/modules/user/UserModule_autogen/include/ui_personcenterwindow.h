/********************************************************************************
** Form generated from reading UI file 'personcenterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONCENTERWINDOW_H
#define UI_PERSONCENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonCenterWindow
{
public:
    QWidget *centralwidget;
    QWidget *topUserWidget;
    QLabel *Labavatar;
    QLabel *labNickname;
    QLabel *userIdLabel;
    QPushButton *editBtn;
    QWidget *gridWidget;
    QPushButton *myPointsBtn;
    QPushButton *myMsgBtn;
    QPushButton *commonInfoBtn;
    QPushButton *myOrderBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PersonCenterWindow)
    {
        if (PersonCenterWindow->objectName().isEmpty())
            PersonCenterWindow->setObjectName("PersonCenterWindow");
        PersonCenterWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PersonCenterWindow->sizePolicy().hasHeightForWidth());
        PersonCenterWindow->setSizePolicy(sizePolicy);
        PersonCenterWindow->setMinimumSize(QSize(0, 0));
        PersonCenterWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(PersonCenterWindow);
        centralwidget->setObjectName("centralwidget");
        topUserWidget = new QWidget(centralwidget);
        topUserWidget->setObjectName("topUserWidget");
        topUserWidget->setGeometry(QRect(0, 0, 800, 120));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topUserWidget->sizePolicy().hasHeightForWidth());
        topUserWidget->setSizePolicy(sizePolicy1);
        topUserWidget->setMinimumSize(QSize(400, 0));
        Labavatar = new QLabel(topUserWidget);
        Labavatar->setObjectName("Labavatar");
        Labavatar->setGeometry(QRect(10, 20, 80, 80));
        Labavatar->setStyleSheet(QString::fromUtf8("border-radius: 40px; \n"
"border: 2px solid #E0E0E0;\n"
"background-image: url(:/images/images/logo1.png); \n"
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
        sizePolicy1.setHeightForWidth(userIdLabel->sizePolicy().hasHeightForWidth());
        userIdLabel->setSizePolicy(sizePolicy1);
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
        gridWidget->setGeometry(QRect(0, 120, 800, 261));
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridWidget->setMinimumSize(QSize(0, 0));
        gridWidget->setMaximumSize(QSize(16777215, 16777215));
        myPointsBtn = new QPushButton(gridWidget);
        myPointsBtn->setObjectName("myPointsBtn");
        myPointsBtn->setGeometry(QRect(0, 100, 800, 50));
        sizePolicy.setHeightForWidth(myPointsBtn->sizePolicy().hasHeightForWidth());
        myPointsBtn->setSizePolicy(sizePolicy);
        myPointsBtn->setMinimumSize(QSize(0, 0));
        myPointsBtn->setMaximumSize(QSize(16777215, 16777215));
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
        icon.addFile(QString::fromUtf8(":/images/images/1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myPointsBtn->setIcon(icon);
        myPointsBtn->setIconSize(QSize(35, 35));
        myMsgBtn = new QPushButton(gridWidget);
        myMsgBtn->setObjectName("myMsgBtn");
        myMsgBtn->setGeometry(QRect(0, 150, 800, 50));
        sizePolicy.setHeightForWidth(myMsgBtn->sizePolicy().hasHeightForWidth());
        myMsgBtn->setSizePolicy(sizePolicy);
        myMsgBtn->setMinimumSize(QSize(0, 0));
        myMsgBtn->setMaximumSize(QSize(16777215, 16777215));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myMsgBtn->setIcon(icon1);
        myMsgBtn->setIconSize(QSize(35, 35));
        commonInfoBtn = new QPushButton(gridWidget);
        commonInfoBtn->setObjectName("commonInfoBtn");
        commonInfoBtn->setGeometry(QRect(0, 50, 800, 50));
        sizePolicy.setHeightForWidth(commonInfoBtn->sizePolicy().hasHeightForWidth());
        commonInfoBtn->setSizePolicy(sizePolicy);
        commonInfoBtn->setMinimumSize(QSize(0, 0));
        commonInfoBtn->setMaximumSize(QSize(16777215, 16777215));
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
        icon2.addFile(QString::fromUtf8(":/images/images/3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        commonInfoBtn->setIcon(icon2);
        commonInfoBtn->setIconSize(QSize(35, 35));
        myOrderBtn = new QPushButton(gridWidget);
        myOrderBtn->setObjectName("myOrderBtn");
        myOrderBtn->setGeometry(QRect(0, 0, 800, 50));
        sizePolicy.setHeightForWidth(myOrderBtn->sizePolicy().hasHeightForWidth());
        myOrderBtn->setSizePolicy(sizePolicy);
        myOrderBtn->setMinimumSize(QSize(0, 0));
        myOrderBtn->setMaximumSize(QSize(16777215, 16777215));
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/11.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myOrderBtn->setIcon(icon3);
        myOrderBtn->setIconSize(QSize(35, 35));
        PersonCenterWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PersonCenterWindow);
        statusbar->setObjectName("statusbar");
        PersonCenterWindow->setStatusBar(statusbar);

        retranslateUi(PersonCenterWindow);

        QMetaObject::connectSlotsByName(PersonCenterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PersonCenterWindow)
    {
        PersonCenterWindow->setWindowTitle(QCoreApplication::translate("PersonCenterWindow", "MainWindow", nullptr));
        Labavatar->setText(QString());
        labNickname->setText(QCoreApplication::translate("PersonCenterWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        userIdLabel->setText(QCoreApplication::translate("PersonCenterWindow", "\347\224\250\346\210\267 ID\357\274\232FS2024001", nullptr));
        editBtn->setText(QCoreApplication::translate("PersonCenterWindow", "\347\274\226\350\276\221\350\265\204\346\226\231", nullptr));
        myPointsBtn->setText(QCoreApplication::translate("PersonCenterWindow", "\346\210\221\347\232\204\347\247\257\345\210\206", nullptr));
        myMsgBtn->setText(QCoreApplication::translate("PersonCenterWindow", "\346\210\221\347\232\204\346\266\210\346\201\257", nullptr));
        commonInfoBtn->setText(QCoreApplication::translate("PersonCenterWindow", "\345\270\270\347\224\250\344\277\241\346\201\257", nullptr));
        myOrderBtn->setText(QCoreApplication::translate("PersonCenterWindow", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonCenterWindow: public Ui_PersonCenterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONCENTERWINDOW_H
