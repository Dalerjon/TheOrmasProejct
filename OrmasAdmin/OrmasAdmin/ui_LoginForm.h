/********************************************************************************
** Form generated from reading UI file 'LoginForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
    QSpacerItem *verticalSpacer;
    QLabel *messageLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *passwordEdit;
    QLineEdit *userEdit;
    QLabel *PasswordLb;
    QLabel *UserNameLb;
    QSpacerItem *horizontalSpacer;
    QLabel *iconLb;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(491, 172);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginDlg->sizePolicy().hasHeightForWidth());
        LoginDlg->setSizePolicy(sizePolicy);
        LoginDlg->setMinimumSize(QSize(400, 170));
        LoginDlg->setMaximumSize(QSize(16777215, 172));
        LoginDlg->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        LoginDlg->setModal(true);
        gridLayout = new QGridLayout(LoginDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 10, 20, 20);
        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 5, 1, 1);

        messageLb = new QLabel(LoginDlg);
        messageLb->setObjectName(QStringLiteral("messageLb"));

        gridLayout->addWidget(messageLb, 3, 1, 1, 5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okBtn = new QPushButton(LoginDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(LoginDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 5);

        passwordEdit = new QLineEdit(LoginDlg);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setMinimumSize(QSize(180, 0));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 2, 5, 1, 1);

        userEdit = new QLineEdit(LoginDlg);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setMinimumSize(QSize(180, 0));

        gridLayout->addWidget(userEdit, 1, 5, 1, 1);

        PasswordLb = new QLabel(LoginDlg);
        PasswordLb->setObjectName(QStringLiteral("PasswordLb"));
        PasswordLb->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(PasswordLb, 2, 4, 1, 1);

        UserNameLb = new QLabel(LoginDlg);
        UserNameLb->setObjectName(QStringLiteral("UserNameLb"));
        UserNameLb->setMinimumSize(QSize(70, 0));

        gridLayout->addWidget(UserNameLb, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 2, 1);

        iconLb = new QLabel(LoginDlg);
        iconLb->setObjectName(QStringLiteral("iconLb"));
        iconLb->setMinimumSize(QSize(120, 120));

        gridLayout->addWidget(iconLb, 0, 0, 5, 1);

        QWidget::setTabOrder(userEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "Login to Ormas", 0));
        messageLb->setText(QString());
        okBtn->setText(QApplication::translate("LoginDlg", "OK", 0));
        cancelBtn->setText(QApplication::translate("LoginDlg", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("LoginDlg", "<html><head/><body><p>At least 6 characters!</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("LoginDlg", "<html><head/><body><p>For example: 929999999 or John.Doe@gmail.com</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        PasswordLb->setText(QApplication::translate("LoginDlg", "Password:", 0));
        UserNameLb->setText(QApplication::translate("LoginDlg", "Phone or email:", 0));
        iconLb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
