/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    ClickableLabel *label_2;
    QLabel *bottomImgLabel_2;
    QWidget *loginDialogWidget;
    ClickableLabel *switchLabel;
    QRadioButton *radioButton;
    ClickableLabel *label_4;
    QLabel *label_5;
    ClickableLabel *label_6;
    QLabel *tip4Label;
    ClickableLabel *registerLabel;
    QStackedWidget *loginStackWidget;
    QWidget *page;
    QLabel *tip2Label;
    QLabel *tip1Label;
    QLineEdit *pwdEdit;
    ClickableLabel *label_9;
    QPushButton *pushButton;
    QLineEdit *userEdit;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QLineEdit *codeEdit;
    QPushButton *pushButton_2;
    ClickableLabel *getCode;
    QLabel *tip3Label;
    QLabel *tip5Label;
    QCheckBox *checkBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(920, 551);
        Widget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 121, 111));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new ClickableLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 20, 111, 61));
        bottomImgLabel_2 = new QLabel(Widget);
        bottomImgLabel_2->setObjectName("bottomImgLabel_2");
        bottomImgLabel_2->setGeometry(QRect(0, 90, 921, 471));
        bottomImgLabel_2->setScaledContents(true);
        bottomImgLabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        loginDialogWidget = new QWidget(Widget);
        loginDialogWidget->setObjectName("loginDialogWidget");
        loginDialogWidget->setGeometry(QRect(540, 140, 321, 381));
        loginDialogWidget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px; \n"
"box-shadow: 0 0 20px rgba(0,0,0,0.1); "));
        switchLabel = new ClickableLabel(loginDialogWidget);
        switchLabel->setObjectName("switchLabel");
        switchLabel->setGeometry(QRect(30, 330, 71, 16));
        switchLabel->setStyleSheet(QString::fromUtf8("color: #0066cc; text-decoration: underline; cursor: pointer;"));
        radioButton = new QRadioButton(loginDialogWidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(30, 280, 124, 21));
        label_4 = new ClickableLabel(loginDialogWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 280, 44, 16));
        label_5 = new QLabel(loginDialogWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 280, 16, 16));
        label_6 = new ClickableLabel(loginDialogWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 280, 88, 16));
        tip4Label = new QLabel(loginDialogWidget);
        tip4Label->setObjectName("tip4Label");
        tip4Label->setEnabled(true);
        tip4Label->setGeometry(QRect(30, 300, 231, 16));
        tip4Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        registerLabel = new ClickableLabel(loginDialogWidget);
        registerLabel->setObjectName("registerLabel");
        registerLabel->setGeometry(QRect(250, 330, 71, 16));
        loginStackWidget = new QStackedWidget(loginDialogWidget);
        loginStackWidget->setObjectName("loginStackWidget");
        loginStackWidget->setGeometry(QRect(20, 20, 291, 331));
        page = new QWidget();
        page->setObjectName("page");
        tip2Label = new QLabel(page);
        tip2Label->setObjectName("tip2Label");
        tip2Label->setEnabled(true);
        tip2Label->setGeometry(QRect(10, 190, 91, 16));
        tip2Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        tip1Label = new QLabel(page);
        tip1Label->setObjectName("tip1Label");
        tip1Label->setEnabled(true);
        tip1Label->setGeometry(QRect(10, 130, 91, 16));
        tip1Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        pwdEdit = new QLineEdit(page);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setGeometry(QRect(10, 160, 271, 31));
        pwdEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        pwdEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_9 = new ClickableLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(220, 170, 54, 16));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 220, 271, 31));
        pushButton->setStyleSheet(QString::fromUtf8("/* \347\231\273\345\275\225\346\214\211\351\222\256\345\237\272\347\241\200\346\240\267\345\274\217\357\274\210\346\251\231\350\211\262\350\276\271\346\241\206+\346\251\231\350\211\262\350\203\214\346\231\257\357\274\214\346\220\255\351\205\215\347\231\275\350\211\262\346\226\207\345\255\227\357\274\211 */\n"
"QPushButton {\n"
"    /* \346\251\231\350\211\262\350\276\271\346\241\206\357\274\232#ff7d00 \346\230\257\345\270\270\347\224\250\347\231\273\345\275\225\351\241\265\346\251\231\350\211\262\357\274\214\345\217\257\346\233\277\346\215\242\344\270\272 #ff9900\357\274\210\346\265\205\346\251\231\357\274\211\343\200\201#ff6600\357\274\210\346\267\261\346\251\231\357\274\211 */\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px; /* \345\234\206\350\247\222\357\274\210\345\222\214\350\276\223\345\205\245\346\241\206\344\277\235\346\214\201\344\270\200\350\207\264\357\274\214\346\233\264\345\215\217\350\260\203\357\274\211 */\n"
"    background-color: #ff7d00; /* \346\214\211\351\222\256\350\203\214"
                        "\346\231\257\350\211\262\357\274\210\345\222\214\350\276\271\346\241\206\345\220\214\350\211\262\357\274\214\344\270\200\344\275\223\345\214\226\346\225\210\346\236\234\357\274\211 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    font-size: 16px; /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
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
        userEdit = new QLineEdit(page);
        userEdit->setObjectName("userEdit");
        userEdit->setGeometry(QRect(10, 90, 271, 31));
        userEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 141, 41));
        loginStackWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 30, 141, 41));
        phoneEdit = new QLineEdit(page_2);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(10, 90, 271, 31));
        phoneEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        codeEdit = new QLineEdit(page_2);
        codeEdit->setObjectName("codeEdit");
        codeEdit->setGeometry(QRect(10, 160, 271, 31));
        codeEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        codeEdit->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 220, 271, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("/* \347\231\273\345\275\225\346\214\211\351\222\256\345\237\272\347\241\200\346\240\267\345\274\217\357\274\210\346\251\231\350\211\262\350\276\271\346\241\206+\346\251\231\350\211\262\350\203\214\346\231\257\357\274\214\346\220\255\351\205\215\347\231\275\350\211\262\346\226\207\345\255\227\357\274\211 */\n"
"QPushButton {\n"
"    /* \346\251\231\350\211\262\350\276\271\346\241\206\357\274\232#ff7d00 \346\230\257\345\270\270\347\224\250\347\231\273\345\275\225\351\241\265\346\251\231\350\211\262\357\274\214\345\217\257\346\233\277\346\215\242\344\270\272 #ff9900\357\274\210\346\265\205\346\251\231\357\274\211\343\200\201#ff6600\357\274\210\346\267\261\346\251\231\357\274\211 */\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px; /* \345\234\206\350\247\222\357\274\210\345\222\214\350\276\223\345\205\245\346\241\206\344\277\235\346\214\201\344\270\200\350\207\264\357\274\214\346\233\264\345\215\217\350\260\203\357\274\211 */\n"
"    background-color: #ff7d00; /* \346\214\211\351\222\256\350\203\214"
                        "\346\231\257\350\211\262\357\274\210\345\222\214\350\276\271\346\241\206\345\220\214\350\211\262\357\274\214\344\270\200\344\275\223\345\214\226\346\225\210\346\236\234\357\274\211 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    font-size: 16px; /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
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
        getCode = new ClickableLabel(page_2);
        getCode->setObjectName("getCode");
        getCode->setGeometry(QRect(190, 170, 81, 16));
        tip3Label = new QLabel(page_2);
        tip3Label->setObjectName("tip3Label");
        tip3Label->setEnabled(true);
        tip3Label->setGeometry(QRect(10, 130, 91, 16));
        tip3Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        tip5Label = new QLabel(page_2);
        tip5Label->setObjectName("tip5Label");
        tip5Label->setEnabled(true);
        tip5Label->setGeometry(QRect(10, 130, 231, 16));
        tip5Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        loginStackWidget->addWidget(page_2);
        checkBox = new QCheckBox(loginDialogWidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(30, 360, 80, 21));
        loginStackWidget->raise();
        switchLabel->raise();
        radioButton->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        tip4Label->raise();
        registerLabel->raise();
        checkBox->raise();
        bottomImgLabel_2->raise();
        loginDialogWidget->raise();
        label_2->raise();
        label->raise();

        retranslateUi(Widget);

        loginStackWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><img src=\":/newimages/newimages/logo1.png\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">\351\246\226\351\241\265</span></p></body></html>", nullptr));
        bottomImgLabel_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><img src=\":/newimages/newimages/background.png\"/></p></body></html>", nullptr));
        switchLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#00aaff;\">\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225</span></p></body></html>", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217 ", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:8pt; color:#00aaff;\">\346\234\215\345\212\241\345\215\217\350\256\256</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:8pt; color:#000000;\">\345\222\214</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:8pt; color:#00aaff;\">\344\270\252\344\272\272\344\277\241\346\201\257\344\277\235\346\212\244\346\224\277\347\255\226</span></p></body></html>", nullptr));
        tip4Label->setText(QCoreApplication::translate("Widget", "\350\257\267\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\347\224\250\346\210\267\345\215\217\350\256\256\345\222\214\351\232\220\347\247\201\346\224\277\347\255\226\357\274\201", nullptr));
        registerLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#00aaff;\">\345\205\215\350\264\271\346\263\250\345\206\214</span></p></body></html>", nullptr));
        tip2Label->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        tip1Label->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pwdEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225\345\257\206\347\240\201", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#000000;\">\345\277\230\350\256\260\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        userEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\345\233\275\345\206\205\346\211\213\346\234\272\345\217\267/\347\224\250\346\210\267\345\220\215/\351\202\256\347\256\261/\345\215\241\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#000000;\">\350\264\246\345\217\267\345\257\206\347\240\201\347\231\273\345\275\225</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#000000;\">\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225</span></p></body></html>", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        codeEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\347\237\255\344\277\241\351\252\214\350\257\201\347\240\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        getCode->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#00aaff;\">\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        tip3Label->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        tip5Label->setText(QCoreApplication::translate("Widget", "\346\211\213\346\234\272\345\217\267\346\240\274\345\274\217\351\224\231\350\257\257\357\274\21011\344\275\215\346\234\211\346\225\210\345\217\267\347\240\201\357\274\211", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
