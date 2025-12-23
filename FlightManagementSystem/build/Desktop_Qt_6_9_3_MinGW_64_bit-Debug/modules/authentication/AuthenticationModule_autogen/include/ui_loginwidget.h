/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QLabel *label;
    ClickableLabel *label_2;
    QLabel *bottomImgLabel_2;
    QWidget *loginDialogWidget;
    ClickableLabel *switchLabel;
    ClickableLabel *registerLabel;
    QStackedWidget *loginStackWidget;
    QWidget *page;
    QLabel *tip2Label;
    QLabel *tip1Label;
    QLineEdit *pwdEdit;
    ClickableLabel *label_9;
    QPushButton *pushButton;
    QPushButton *adminLoginBtn;
    QLineEdit *userEdit;
    QLabel *label_3;
    QRadioButton *radioButton;
    QLabel *tip4Label;
    ClickableLabel *label_4;
    ClickableLabel *label_6;
    QLabel *label_5;
    QWidget *page_2;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QLineEdit *codeEdit;
    QPushButton *pushButton_2;
    ClickableLabel *getCode;
    QLabel *tip3Label;
    QLabel *tip5Label;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(920, 551);
        LoginWidget->setMinimumSize(QSize(920, 551));
        LoginWidget->setMaximumSize(QSize(920, 551));
        LoginWidget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(LoginWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 121, 111));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new ClickableLabel(LoginWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 30, 271, 61));
        bottomImgLabel_2 = new QLabel(LoginWidget);
        bottomImgLabel_2->setObjectName("bottomImgLabel_2");
        bottomImgLabel_2->setGeometry(QRect(0, 0, 921, 561));
        bottomImgLabel_2->setPixmap(QPixmap(QString::fromUtf8(":/newimages/newimages/background.png")));
        bottomImgLabel_2->setScaledContents(true);
        bottomImgLabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        loginDialogWidget = new QWidget(LoginWidget);
        loginDialogWidget->setObjectName("loginDialogWidget");
        loginDialogWidget->setGeometry(QRect(520, 120, 321, 381));
        loginDialogWidget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px; \n"
"box-shadow: 0 0 20px rgba(0,0,0,0.1); "));
        switchLabel = new ClickableLabel(loginDialogWidget);
        switchLabel->setObjectName("switchLabel");
        switchLabel->setGeometry(QRect(30, 360, 71, 16));
        switchLabel->setStyleSheet(QString::fromUtf8("color: #0066cc; text-decoration: underline; cursor: pointer;"));
        registerLabel = new ClickableLabel(loginDialogWidget);
        registerLabel->setObjectName("registerLabel");
        registerLabel->setGeometry(QRect(250, 360, 71, 16));
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
"    border: 1px solid #cccccc; \n"
"    border-radius: 4px; \n"
"    padding: 0 10px; \n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        pwdEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_9 = new ClickableLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(220, 170, 54, 16));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 220, 271, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px;\n"
"    background-color: #ff7d00;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    height: 44px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #ff6600;\n"
"    background-color: #ff6600;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-color: #e65c00;\n"
"    background-color: #e65c00;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    border-color: #cccccc;\n"
"    background-color: #cccccc;\n"
"    color: #ffffff;\n"
"}"));
        adminLoginBtn = new QPushButton(page);
        adminLoginBtn->setObjectName("adminLoginBtn");
        adminLoginBtn->setGeometry(QRect(10, 260, 271, 31));
        adminLoginBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #2196F3; \n"
"    border-radius: 4px;\n"
"    background-color: #2196F3;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    height: 44px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #1976D2;\n"
"    background-color: #1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-color: #0D47A1;\n"
"    background-color: #0D47A1;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    border-color: #cccccc;\n"
"    background-color: #cccccc;\n"
"    color: #ffffff;\n"
"}"));
        userEdit = new QLineEdit(page);
        userEdit->setObjectName("userEdit");
        userEdit->setGeometry(QRect(10, 90, 271, 31));
        userEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; \n"
"    border-radius: 4px; \n"
"    padding: 0 10px; \n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 141, 41));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(10, 300, 124, 21));
        tip4Label = new QLabel(page);
        tip4Label->setObjectName("tip4Label");
        tip4Label->setEnabled(true);
        tip4Label->setGeometry(QRect(10, 200, 231, 16));
        tip4Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        label_4 = new ClickableLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 300, 44, 16));
        label_6 = new ClickableLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(160, 300, 88, 16));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 300, 16, 16));
        loginStackWidget->addWidget(page);
        tip2Label->raise();
        tip1Label->raise();
        pwdEdit->raise();
        label_9->raise();
        pushButton->raise();
        adminLoginBtn->raise();
        userEdit->raise();
        label_3->raise();
        radioButton->raise();
        label_4->raise();
        label_6->raise();
        label_5->raise();
        tip4Label->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 30, 141, 41));
        phoneEdit = new QLineEdit(page_2);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(10, 90, 271, 31));
        phoneEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; \n"
"    border-radius: 4px; \n"
"    padding: 0 10px; \n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        codeEdit = new QLineEdit(page_2);
        codeEdit->setObjectName("codeEdit");
        codeEdit->setGeometry(QRect(10, 160, 271, 31));
        codeEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; \n"
"    border-radius: 4px; \n"
"    padding: 0 10px; \n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        codeEdit->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 220, 271, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #ff7d00; \n"
"    border-radius: 4px;\n"
"    background-color: #ff7d00;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    height: 44px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #ff6600;\n"
"    background-color: #ff6600;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-color: #e65c00;\n"
"    background-color: #e65c00;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
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
        loginStackWidget->raise();
        switchLabel->raise();
        registerLabel->raise();
        bottomImgLabel_2->raise();
        label->raise();
        label_2->raise();
        loginDialogWidget->raise();

        retranslateUi(LoginWidget);

        loginStackWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "\350\210\252\347\251\272\347\256\241\347\220\206\347\263\273\347\273\237-\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><img src=\":/newimages/newimages/logo1.png\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:700;\">\350\210\252\347\251\272\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        bottomImgLabel_2->setText(QString());
        switchLabel->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" color:#00aaff;\">\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225</span></p></body></html>", nullptr));
        registerLabel->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" color:#00aaff;\">\345\205\215\350\264\271\346\263\250\345\206\214</span></p></body></html>", nullptr));
        tip2Label->setText(QCoreApplication::translate("LoginWidget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        tip1Label->setText(QCoreApplication::translate("LoginWidget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pwdEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225\345\257\206\347\240\201", nullptr));
        label_9->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" color:#000000;\">\345\277\230\350\256\260\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        adminLoginBtn->setText(QCoreApplication::translate("LoginWidget", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        userEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\345\233\275\345\206\205\346\211\213\346\234\272\345\217\267/\347\224\250\346\210\267\345\220\215/\351\202\256\347\256\261/\345\215\241\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#000000;\">\350\264\246\345\217\267\345\257\206\347\240\201\347\231\273\345\275\225</span></p></body></html>", nullptr));
        radioButton->setText(QCoreApplication::translate("LoginWidget", "\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217 ", nullptr));
        tip4Label->setText(QCoreApplication::translate("LoginWidget", "\350\257\267\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\347\224\250\346\210\267\345\215\217\350\256\256\345\222\214\351\232\220\347\247\201\346\224\277\347\255\226\357\274\201", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-size:8pt; color:#00aaff;\">\346\234\215\345\212\241\345\215\217\350\256\256</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-size:8pt; color:#00aaff;\">\344\270\252\344\272\272\344\277\241\346\201\257\344\277\235\346\212\244\346\224\277\347\255\226</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-size:8pt; color:#000000;\">\345\222\214</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#000000;\">\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225</span></p></body></html>", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        codeEdit->setPlaceholderText(QCoreApplication::translate("LoginWidget", "\347\237\255\344\277\241\351\252\214\350\257\201\347\240\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        getCode->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" color:#00aaff;\">\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        tip3Label->setText(QCoreApplication::translate("LoginWidget", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        tip5Label->setText(QCoreApplication::translate("LoginWidget", "\346\211\213\346\234\272\345\217\267\346\240\274\345\274\217\351\224\231\350\257\257\357\274\21011\344\275\215\346\234\211\346\225\210\345\217\267\347\240\201\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
