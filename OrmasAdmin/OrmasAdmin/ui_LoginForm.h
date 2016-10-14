/********************************************************************************
** Form generated from reading UI file 'LoginForm.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QGridLayout *gridLayout;
    QLineEdit *passwordEdit;
    QLineEdit *userEdit;
    QLabel *IconLb;
    QLabel *PasswordLb;
    QLabel *UserNameLb;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *OKBtn;
    QPushButton *CancelBtn;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(400, 150);
        LoginDlg->setMinimumSize(QSize(400, 150));
        LoginDlg->setMaximumSize(QSize(16777215, 150));
        LoginDlg->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(LoginDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 20, 20, 20);
        passwordEdit = new QLineEdit(LoginDlg);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setMinimumSize(QSize(180, 0));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 1, 3, 1, 1);

        userEdit = new QLineEdit(LoginDlg);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(userEdit, 0, 3, 1, 1);

        IconLb = new QLabel(LoginDlg);
        IconLb->setObjectName(QStringLiteral("IconLb"));
        IconLb->setMinimumSize(QSize(80, 80));

        gridLayout->addWidget(IconLb, 0, 0, 2, 1);

        PasswordLb = new QLabel(LoginDlg);
        PasswordLb->setObjectName(QStringLiteral("PasswordLb"));
        PasswordLb->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(PasswordLb, 1, 2, 1, 1);

        UserNameLb = new QLabel(LoginDlg);
        UserNameLb->setObjectName(QStringLiteral("UserNameLb"));
        UserNameLb->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(UserNameLb, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        OKBtn = new QPushButton(LoginDlg);
        OKBtn->setObjectName(QStringLiteral("OKBtn"));

        horizontalLayout->addWidget(OKBtn);

        CancelBtn = new QPushButton(LoginDlg);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));

        horizontalLayout->addWidget(CancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 4);


        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "Login", 0));
        IconLb->setText(QString());
        PasswordLb->setText(QApplication::translate("LoginDlg", "Passord:", 0));
        UserNameLb->setText(QApplication::translate("LoginDlg", "User name:", 0));
        OKBtn->setText(QApplication::translate("LoginDlg", "OK", 0));
        CancelBtn->setText(QApplication::translate("LoginDlg", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
