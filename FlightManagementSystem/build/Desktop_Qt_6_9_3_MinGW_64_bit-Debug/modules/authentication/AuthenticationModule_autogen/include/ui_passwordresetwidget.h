/********************************************************************************
** Form generated from reading UI file 'passwordresetwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRESETWIDGET_H
#define UI_PASSWORDRESETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_PasswordResetWidget
{
public:
    QStackedWidget *pwdstackedWidget;
    QWidget *page;
    QLabel *label_8;
    QLineEdit *usernameEdit;
    QPushButton *pushButton_2;
    QLabel *tip1Label;
    QWidget *page_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *nameshow;
    QLabel *phoneshow;
    QLabel *label_4;
    QLineEdit *codeEdit;
    QPushButton *pushButton_3;
    ClickableLabel *getcodeLabel1;
    QLabel *tip2Label;
    QLabel *tip3Label;
    ClickableLabel *backLabel_2;
    QWidget *page_3;
    QLabel *label_9;
    QLineEdit *pwdEdit;
    QLabel *label_10;
    QLineEdit *pwdEdit_2;
    QPushButton *pushButton_4;
    ClickableLabel *backLabel;
    QLabel *label_11;
    QLabel *tip4Label;
    QLabel *tip5Label;
    ClickableLabel *backLabel_3;

    void setupUi(QWidget *PasswordResetWidget)
    {
        if (PasswordResetWidget->objectName().isEmpty())
            PasswordResetWidget->setObjectName("PasswordResetWidget");
        PasswordResetWidget->resize(400, 300);
        PasswordResetWidget->setMinimumSize(QSize(400, 300));
        PasswordResetWidget->setMaximumSize(QSize(400, 300));
        PasswordResetWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pwdstackedWidget = new QStackedWidget(PasswordResetWidget);
        pwdstackedWidget->setObjectName("pwdstackedWidget");
        pwdstackedWidget->setGeometry(QRect(10, 30, 381, 261));
        page = new QWidget();
        page->setObjectName("page");
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 90, 41, 16));
        usernameEdit = new QLineEdit(page);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setEnabled(true);
        usernameEdit->setGeometry(QRect(60, 80, 271, 31));
        usernameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; \n"
"    border-radius: 4px; \n"
"    padding: 0 10px;\n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc;\n"
"}"));
        usernameEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(60, 160, 191, 31));
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
        tip1Label = new QLabel(page);
        tip1Label->setObjectName("tip1Label");
        tip1Label->setEnabled(true);
        tip1Label->setGeometry(QRect(60, 120, 91, 16));
        tip1Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        pwdstackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 54, 16));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 54, 16));
        nameshow = new QLabel(page_2);
        nameshow->setObjectName("nameshow");
        nameshow->setGeometry(QRect(110, 40, 101, 16));
        phoneshow = new QLabel(page_2);
        phoneshow->setObjectName("phoneshow");
        phoneshow->setGeometry(QRect(110, 90, 111, 16));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 54, 16));
        codeEdit = new QLineEdit(page_2);
        codeEdit->setObjectName("codeEdit");
        codeEdit->setEnabled(true);
        codeEdit->setGeometry(QRect(110, 130, 221, 31));
        codeEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc; \n"
"    border-radius: 4px; \n"
"    padding: 0 10px;\n"
"    height: 40px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        codeEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(110, 190, 191, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        getcodeLabel1 = new ClickableLabel(page_2);
        getcodeLabel1->setObjectName("getcodeLabel1");
        getcodeLabel1->setGeometry(QRect(240, 140, 81, 20));
        tip2Label = new QLabel(page_2);
        tip2Label->setObjectName("tip2Label");
        tip2Label->setEnabled(true);
        tip2Label->setGeometry(QRect(110, 170, 91, 16));
        tip2Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        tip3Label = new QLabel(page_2);
        tip3Label->setObjectName("tip3Label");
        tip3Label->setEnabled(true);
        tip3Label->setGeometry(QRect(110, 170, 91, 16));
        tip3Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        backLabel_2 = new ClickableLabel(page_2);
        backLabel_2->setObjectName("backLabel_2");
        backLabel_2->setGeometry(QRect(110, 230, 81, 16));
        pwdstackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 70, 41, 16));
        pwdEdit = new QLineEdit(page_3);
        pwdEdit->setObjectName("pwdEdit");
        pwdEdit->setEnabled(true);
        pwdEdit->setGeometry(QRect(80, 60, 271, 31));
        pwdEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 0 10px; \n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        pwdEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_10 = new QLabel(page_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 130, 71, 16));
        pwdEdit_2 = new QLineEdit(page_3);
        pwdEdit_2->setObjectName("pwdEdit_2");
        pwdEdit_2->setGeometry(QRect(80, 120, 271, 31));
        pwdEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 0 10px; \n"
"    height: 40px; \n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0066cc; \n"
"}"));
        pwdEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(80, 200, 161, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        backLabel = new ClickableLabel(page_3);
        backLabel->setObjectName("backLabel");
        backLabel->setGeometry(QRect(80, 240, 81, 16));
        label_11 = new QLabel(page_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(80, 160, 291, 16));
        tip4Label = new QLabel(page_3);
        tip4Label->setObjectName("tip4Label");
        tip4Label->setEnabled(true);
        tip4Label->setGeometry(QRect(80, 100, 91, 16));
        tip4Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        tip5Label = new QLabel(page_3);
        tip5Label->setObjectName("tip5Label");
        tip5Label->setEnabled(true);
        tip5Label->setGeometry(QRect(80, 180, 301, 16));
        tip5Label->setStyleSheet(QString::fromUtf8("color: red; font-size: 12px; visibility: hidden;"));
        pwdstackedWidget->addWidget(page_3);
        backLabel_3 = new ClickableLabel(PasswordResetWidget);
        backLabel_3->setObjectName("backLabel_3");
        backLabel_3->setGeometry(QRect(300, 260, 81, 16));

        retranslateUi(PasswordResetWidget);

        pwdstackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PasswordResetWidget);
    } // setupUi

    void retranslateUi(QWidget *PasswordResetWidget)
    {
        PasswordResetWidget->setWindowTitle(QString());
#if QT_CONFIG(whatsthis)
        pwdstackedWidget->setWhatsThis(QCoreApplication::translate("PasswordResetWidget", "\345\277\230\350\256\260\345\257\206\347\240\201-\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_8->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">\350\264\246\345\217\267</span></p></body></html>", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("PasswordResetWidget", "\346\211\213\346\234\272\345\217\267/\347\224\250\346\210\267\345\220\215/\351\202\256\347\256\261/\345\215\241\345\217\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PasswordResetWidget", "\344\270\213\344\270\200\346\255\245\357\274\214\351\252\214\350\257\201", nullptr));
        tip1Label->setText(QCoreApplication::translate("PasswordResetWidget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\357\274\201", nullptr));
        label->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">\350\264\246\345\217\267</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">\347\273\221\345\256\232\346\211\213\346\234\272</span></p></body></html>", nullptr));
        nameshow->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" color:#000000;\"><br/></span></p></body></html>", nullptr));
        phoneshow->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" color:#000000;\"><br/></span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        codeEdit->setPlaceholderText(QCoreApplication::translate("PasswordResetWidget", "6\344\275\215\346\225\260\345\255\227", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PasswordResetWidget", "\344\270\213\344\270\200\346\255\245\357\274\214\351\252\214\350\257\201", nullptr));
        getcodeLabel1->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" color:#00aaff;\">\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        tip2Label->setText(QCoreApplication::translate("PasswordResetWidget", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201\357\274\201", nullptr));
        tip3Label->setText(QCoreApplication::translate("PasswordResetWidget", "\351\252\214\350\257\201\347\240\201\351\224\231\350\257\257\357\274\201", nullptr));
        backLabel_2->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:#adadad;\">&lt;\350\277\224\345\233\236\344\270\212\344\270\200\346\255\245</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">\346\226\260\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pwdEdit->setPlaceholderText(QCoreApplication::translate("PasswordResetWidget", "\350\257\267\350\256\276\347\275\256\346\226\260\345\257\206\347\240\201", nullptr));
        label_10->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#000000;\">\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pwdEdit_2->setPlaceholderText(QCoreApplication::translate("PasswordResetWidget", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PasswordResetWidget", "\345\256\214\346\210\220", nullptr));
        backLabel->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:#adadad;\">&lt;\350\277\224\345\233\236\344\270\212\344\270\200\346\255\245</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-family:'Noto Sans SC'; font-size:12px; color:#666666;\">\345\257\206\347\240\201\351\234\200\344\270\272 8-20 \344\275\215\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\345\222\214\347\254\246\345\217\267\347\232\204\347\273\204\345\220\210\357\274\214\344\270\215\345\220\253\347\251\272\346\240\274</span></p></body></html>", nullptr));
        tip4Label->setText(QCoreApplication::translate("PasswordResetWidget", "\345\257\206\347\240\201\346\240\274\345\274\217\344\270\215\346\255\243\347\241\256\357\274\201", nullptr));
        tip5Label->setText(QCoreApplication::translate("PasswordResetWidget", "\344\270\244\346\254\241\345\257\206\347\240\201\350\276\223\345\205\245\344\270\215\344\270\200\350\207\264\357\274\201", nullptr));
        backLabel_3->setText(QCoreApplication::translate("PasswordResetWidget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#00ffff;\">\350\277\224\345\233\236\347\231\273\345\275\225</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordResetWidget: public Ui_PasswordResetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRESETWIDGET_H
