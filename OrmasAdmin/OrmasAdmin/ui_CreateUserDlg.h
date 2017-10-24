/********************************************************************************
** Form generated from reading UI file 'CreateUserDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSERDLG_H
#define UI_CREATEUSERDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateUser
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *nameEdit;
    QLabel *activatedLb;
    QLabel *nameLb;
    QLabel *phoneLb;
    QLabel *addressLb;
    QLineEdit *phoneEdit;
    QLineEdit *roleEdit;
    QLabel *surnameLb;
    QLineEdit *surnameEdit;
    QPushButton *roleBtn;
    QLabel *passworLb;
    QComboBox *activatedCmbBox;
    QLineEdit *passwordEdit;
    QLineEdit *addressEdit;
    QLabel *emailLb;
    QLineEdit *emailEdit;

    void setupUi(QDialog *CreateUser)
    {
        if (CreateUser->objectName().isEmpty())
            CreateUser->setObjectName(QStringLiteral("CreateUser"));
        CreateUser->resize(400, 258);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateUser->sizePolicy().hasHeightForWidth());
        CreateUser->setSizePolicy(sizePolicy);
        CreateUser->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateUser->setModal(false);
        gridLayout = new QGridLayout(CreateUser);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateUser);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateUser);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 2);

        nameEdit = new QLineEdit(CreateUser);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        activatedLb = new QLabel(CreateUser);
        activatedLb->setObjectName(QStringLiteral("activatedLb"));

        gridLayout->addWidget(activatedLb, 6, 0, 1, 1);

        nameLb = new QLabel(CreateUser);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        phoneLb = new QLabel(CreateUser);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 3, 0, 1, 1);

        addressLb = new QLabel(CreateUser);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 2, 0, 1, 1);

        phoneEdit = new QLineEdit(CreateUser);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));
        phoneEdit->setInputMethodHints(Qt::ImhNone);

        gridLayout->addWidget(phoneEdit, 3, 1, 1, 1);

        roleEdit = new QLineEdit(CreateUser);
        roleEdit->setObjectName(QStringLiteral("roleEdit"));
        roleEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);
        roleEdit->setEchoMode(QLineEdit::Normal);
        roleEdit->setReadOnly(true);

        gridLayout->addWidget(roleEdit, 7, 1, 1, 1);

        surnameLb = new QLabel(CreateUser);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));

        gridLayout->addWidget(surnameLb, 1, 0, 1, 1);

        surnameEdit = new QLineEdit(CreateUser);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        gridLayout->addWidget(surnameEdit, 1, 1, 1, 1);

        roleBtn = new QPushButton(CreateUser);
        roleBtn->setObjectName(QStringLiteral("roleBtn"));

        gridLayout->addWidget(roleBtn, 7, 0, 1, 1);

        passworLb = new QLabel(CreateUser);
        passworLb->setObjectName(QStringLiteral("passworLb"));

        gridLayout->addWidget(passworLb, 5, 0, 1, 1);

        activatedCmbBox = new QComboBox(CreateUser);
        activatedCmbBox->setObjectName(QStringLiteral("activatedCmbBox"));

        gridLayout->addWidget(activatedCmbBox, 6, 1, 1, 1);

        passwordEdit = new QLineEdit(CreateUser);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 5, 1, 1, 1);

        addressEdit = new QLineEdit(CreateUser);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 2, 1, 1, 1);

        emailLb = new QLabel(CreateUser);
        emailLb->setObjectName(QStringLiteral("emailLb"));

        gridLayout->addWidget(emailLb, 4, 0, 1, 1);

        emailEdit = new QLineEdit(CreateUser);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));
        emailEdit->setInputMethodHints(Qt::ImhEmailCharactersOnly);

        gridLayout->addWidget(emailEdit, 4, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, surnameEdit);
        QWidget::setTabOrder(surnameEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, emailEdit);
        QWidget::setTabOrder(emailEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, activatedCmbBox);
        QWidget::setTabOrder(activatedCmbBox, roleBtn);
        QWidget::setTabOrder(roleBtn, roleEdit);
        QWidget::setTabOrder(roleEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateUser);

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QDialog *CreateUser)
    {
        CreateUser->setWindowTitle(QApplication::translate("CreateUser", "Create/Update User", 0));
        okBtn->setText(QApplication::translate("CreateUser", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateUser", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateUser", "<html><head/><body><p>For expamle: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        activatedLb->setText(QApplication::translate("CreateUser", "Activated:", 0));
        nameLb->setText(QApplication::translate("CreateUser", "Name:", 0));
        phoneLb->setText(QApplication::translate("CreateUser", "Phone:", 0));
        addressLb->setText(QApplication::translate("CreateUser", "Address:", 0));
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreateUser", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        surnameLb->setText(QApplication::translate("CreateUser", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        surnameEdit->setToolTip(QApplication::translate("CreateUser", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roleBtn->setText(QApplication::translate("CreateUser", "Select role", 0));
        passworLb->setText(QApplication::translate("CreateUser", "Password:", 0));
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("CreateUser", "<html><head/><body><p>At least 6 characters</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateUser", "<html><head/><body><p>For example: Downing St. 88</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        emailLb->setText(QApplication::translate("CreateUser", "Email:", 0));
#ifndef QT_NO_TOOLTIP
        emailEdit->setToolTip(QApplication::translate("CreateUser", "<html><head/><body><p>For example: John.Doe@gmail.com (not a mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSERDLG_H
