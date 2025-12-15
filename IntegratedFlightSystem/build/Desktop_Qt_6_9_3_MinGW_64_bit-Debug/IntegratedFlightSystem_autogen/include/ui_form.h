/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

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

class Ui_Form
{
public:
    QLabel *label_3;
    QStackedWidget *registerstackedWidget;
    QWidget *page;
    QLabel *label;
    QLineEdit *phoneEdit;
    QLabel *tip5Label;
    QLineEdit *codeEdit;
    ClickableLabel *getcodeLabel1;
    QPushButton *pushButton_2;
    QLabel *tip3Label;
    QLabel *label_2;
    QRadioButton *radioButton;
    ClickableLabel *label_4;
    QLabel *label_5;
    ClickableLabel *label_6;
    QLabel *tip4Label;
    QWidget *page_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *pwdEdit;
    QLineEdit *pwdEdit_2;
    QPushButton *pushButton_3;
    QLabel *phoneshow;
    QLabel *tip6Label;
    QLabel *tip7Label;
    ClickableLabel *backLabel;
    ClickableLabel *backLabel_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(431, 340);
        Form->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 161, 41));
        registerstackedWidget = new QStackedWidget(Form);
        registerstackedWidget->setObjectName("registerstackedWidget");
        registerstackedWidget->setGeometry(QRect(20, 70, 391, 241));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 41, 16));
        phoneEdit = new QLineEdit(page);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(90, 10, 271, 31));
        phoneEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        tip5Label = new QLabel(page);
        tip5Label->setObjectName("tip5Label");
        tip5Label->setEnabled(true);
        tip5Label->setGeometry(QRect(90, 50, 231, 16));
        tip5Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        codeEdit = new QLineEdit(page);
        codeEdit->setObjectName("codeEdit");
        codeEdit->setGeometry(QRect(90, 80, 271, 31));
        codeEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        getcodeLabel1 = new ClickableLabel(page);
        getcodeLabel1->setObjectName("getcodeLabel1");
        getcodeLabel1->setGeometry(QRect(270, 90, 81, 20));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 200, 191, 31));
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
        tip3Label = new QLabel(page);
        tip3Label->setObjectName("tip3Label");
        tip3Label->setEnabled(true);
        tip3Label->setGeometry(QRect(90, 50, 91, 16));
        tip3Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 71, 20));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(90, 130, 124, 21));
        label_4 = new ClickableLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 130, 61, 16));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(230, 130, 16, 16));
        label_6 = new ClickableLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 130, 88, 16));
        tip4Label = new QLabel(page);
        tip4Label->setObjectName("tip4Label");
        tip4Label->setEnabled(true);
        tip4Label->setGeometry(QRect(90, 160, 231, 16));
        tip4Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        registerstackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 10, 91, 16));
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 50, 41, 16));
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 110, 71, 16));
        pwdEdit = new QLineEdit(page_2);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setEnabled(true);
        pwdEdit->setGeometry(QRect(100, 40, 271, 31));
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
        pwdEdit_2 = new QLineEdit(page_2);
        pwdEdit_2->setObjectName("pwdEdit_2");
        pwdEdit_2->setGeometry(QRect(100, 100, 271, 31));
        pwdEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206\357\274\210\351\273\230\350\256\244\345\217\257\350\247\201\357\274\211 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\345\234\206\350\247\222\346\233\264\347\276\216\350\247\202 */\n"
"    padding: 0 10px; /* \345\217\257\351\200\211\357\274\232\350\276\223\345\205\245\345\206\205\345\256\271\344\270\215\350\264\264\350\276\271 */\n"
"    height: 40px; /* \345\217\257\351\200\211\357\274\232\347\273\237\344\270\200\351\253\230\345\272\246 */\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; /* \350\201\232\347\204\246\346\227\266\345\217\230\350\223\235\350\211\262\350\276\271\346\241\206\357\274\210\346\233\264\351\206\222\347\233\256\357\274\211 */\n"
"}"));
        pwdEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(100, 170, 161, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("/* \347\231\273\345\275\225\346\214\211\351\222\256\345\237\272\347\241\200\346\240\267\345\274\217\357\274\210\346\251\231\350\211\262\350\276\271\346\241\206+\346\251\231\350\211\262\350\203\214\346\231\257\357\274\214\346\220\255\351\205\215\347\231\275\350\211\262\346\226\207\345\255\227\357\274\211 */\n"
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
        phoneshow = new QLabel(page_2);
        phoneshow->setObjectName("phoneshow");
        phoneshow->setGeometry(QRect(80, 10, 141, 16));
        phoneshow->setStyleSheet(QString::fromUtf8("color: black;"));
        phoneshow->setMidLineWidth(-2);
        tip6Label = new QLabel(page_2);
        tip6Label->setObjectName("tip6Label");
        tip6Label->setEnabled(true);
        tip6Label->setGeometry(QRect(100, 80, 301, 16));
        tip6Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        tip7Label = new QLabel(page_2);
        tip7Label->setObjectName("tip7Label");
        tip7Label->setEnabled(true);
        tip7Label->setGeometry(QRect(100, 140, 301, 16));
        tip7Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        backLabel = new ClickableLabel(page_2);
        backLabel->setObjectName("backLabel");
        backLabel->setGeometry(QRect(100, 220, 81, 16));
        registerstackedWidget->addWidget(page_2);
        backLabel_2 = new ClickableLabel(Form);
        backLabel_2->setObjectName("backLabel_2");
        backLabel_2->setGeometry(QRect(340, 290, 81, 16));
        registerstackedWidget->raise();
        label_3->raise();
        backLabel_2->raise();

        retranslateUi(Form);

        registerstackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; color:#000000;\">\347\224\250\346\210\267\346\263\250\345\206\214</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">\346\211\213\346\234\272\345\217\267</span></p></body></html>", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("Form", "\350\257\267\350\276\223\345\205\245\346\234\211\346\225\210\346\211\213\346\234\272\345\217\267", nullptr));
        tip5Label->setText(QCoreApplication::translate("Form", "\346\211\213\346\234\272\345\217\267\346\240\274\345\274\217\351\224\231\350\257\257\357\274\21011\344\275\215\346\234\211\346\225\210\345\217\267\347\240\201\357\274\211", nullptr));
        codeEdit->setPlaceholderText(QCoreApplication::translate("Form", "\345\205\255\344\275\215\346\225\260\345\255\227", nullptr));
        getcodeLabel1->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" color:#00aaff;\">\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "\344\270\213\344\270\200\346\255\245\357\274\214\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        tip3Label->setText(QCoreApplication::translate("Form", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">\347\237\255\344\277\241\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        radioButton->setText(QCoreApplication::translate("Form", "\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217 ", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:8pt; color:#00aaff;\">\346\234\215\345\212\241\345\215\217\350\256\256</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:8pt; color:#000000;\">\345\222\214</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:8pt; color:#00aaff;\">\344\270\252\344\272\272\344\277\241\346\201\257\344\277\235\346\212\244\346\224\277\347\255\226</span></p></body></html>", nullptr));
        tip4Label->setText(QCoreApplication::translate("Form", "\350\257\267\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\347\224\250\346\210\267\345\215\217\350\256\256\345\222\214\351\232\220\347\247\201\346\224\277\347\255\226\357\274\201", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" color:#000000;\">\346\263\250\345\206\214\346\211\213\346\234\272\345\217\267     </span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">\347\241\256\350\256\244\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pwdEdit->setPlaceholderText(QCoreApplication::translate("Form", "8-20\344\275\215\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\345\222\214\347\254\246\345\217\267", nullptr));
        pwdEdit_2->setPlaceholderText(QCoreApplication::translate("Form", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "\345\256\214\346\210\220", nullptr));
        phoneshow->setText(QCoreApplication::translate("Form", "<html><head/><body><p><br/></p></body></html>", nullptr));
        tip6Label->setText(QCoreApplication::translate("Form", "\345\257\206\347\240\201\346\240\274\345\274\217\351\224\231\350\257\257\357\274\210\345\277\205\351\241\273\346\230\2578-20\344\275\215\345\214\205\345\220\253\345\255\227\346\257\215\357\274\214\346\225\260\345\255\227\345\222\214\347\254\246\345\217\267\357\274\211", nullptr));
        tip7Label->setText(QCoreApplication::translate("Form", "\344\270\244\346\254\241\345\257\206\347\240\201\350\276\223\345\205\245\344\270\215\344\270\200\350\207\264\357\274\201", nullptr));
        backLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:10pt; color:#adadad;\">&lt;\350\277\224\345\233\236\344\270\212\344\270\200\346\255\245</span></p></body></html>", nullptr));
        backLabel_2->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#00ffff;\">\350\277\224\345\233\236\347\231\273\345\275\225</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
