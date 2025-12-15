/********************************************************************************
** Form generated from reading UI file 'profileeditwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEEDITWIDGET_H
#define UI_PROFILEEDITWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileEditWidget
{
public:
    QLabel *labUsername;
    QLabel *labNickname;
    QLabel *labPhone;
    QLineEdit *leUsername;
    QLineEdit *leNickname;
    QLineEdit *lePhone;
    QLineEdit *leEmail;
    QLabel *labEmail;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QWidget *ProfileEditWidget)
    {
        if (ProfileEditWidget->objectName().isEmpty())
            ProfileEditWidget->setObjectName("ProfileEditWidget");
        ProfileEditWidget->resize(400, 300);
        labUsername = new QLabel(ProfileEditWidget);
        labUsername->setObjectName("labUsername");
        labUsername->setGeometry(QRect(30, 30, 40, 12));
        labNickname = new QLabel(ProfileEditWidget);
        labNickname->setObjectName("labNickname");
        labNickname->setGeometry(QRect(40, 100, 40, 12));
        labPhone = new QLabel(ProfileEditWidget);
        labPhone->setObjectName("labPhone");
        labPhone->setGeometry(QRect(60, 160, 40, 12));
        leUsername = new QLineEdit(ProfileEditWidget);
        leUsername->setObjectName("leUsername");
        leUsername->setGeometry(QRect(130, 30, 113, 20));
        leNickname = new QLineEdit(ProfileEditWidget);
        leNickname->setObjectName("leNickname");
        leNickname->setGeometry(QRect(130, 80, 113, 20));
        lePhone = new QLineEdit(ProfileEditWidget);
        lePhone->setObjectName("lePhone");
        lePhone->setGeometry(QRect(140, 160, 113, 20));
        leEmail = new QLineEdit(ProfileEditWidget);
        leEmail->setObjectName("leEmail");
        leEmail->setGeometry(QRect(170, 220, 113, 20));
        labEmail = new QLabel(ProfileEditWidget);
        labEmail->setObjectName("labEmail");
        labEmail->setGeometry(QRect(60, 210, 40, 12));
        btnSave = new QPushButton(ProfileEditWidget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(70, 250, 56, 18));
        btnCancel = new QPushButton(ProfileEditWidget);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(210, 270, 56, 18));

        retranslateUi(ProfileEditWidget);

        QMetaObject::connectSlotsByName(ProfileEditWidget);
    } // setupUi

    void retranslateUi(QWidget *ProfileEditWidget)
    {
        ProfileEditWidget->setWindowTitle(QCoreApplication::translate("ProfileEditWidget", "Dialog", nullptr));
        labUsername->setText(QCoreApplication::translate("ProfileEditWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labNickname->setText(QCoreApplication::translate("ProfileEditWidget", "\346\230\265\347\247\260\357\274\232", nullptr));
        labPhone->setText(QCoreApplication::translate("ProfileEditWidget", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        labEmail->setText(QCoreApplication::translate("ProfileEditWidget", "\351\202\256\347\256\261\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("ProfileEditWidget", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("ProfileEditWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileEditWidget: public Ui_ProfileEditWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEEDITWIDGET_H
