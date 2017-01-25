/********************************************************************************
** Form generated from reading UI file 'CreateUserDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
    QLabel *passworLb;
    QLineEdit *firmEdit;
    QLineEdit *passwordEdit;
    QPushButton *roleBtn;
    QComboBox *activaredCmbBox;
    QPushButton *locationBtn;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *firmNumLb;
    QLineEdit *nameEdit;
    QLabel *firmLb;
    QLabel *activatedLb;
    QLabel *nameLb;
    QLabel *phoneLb;
    QLabel *addressLb;
    QLineEdit *phoneEdit;
    QLineEdit *firmNumEdit;
    QLineEdit *roleEdit;
    QLineEdit *locationEdit;

    void setupUi(QDialog *CreateUser)
    {
        if (CreateUser->objectName().isEmpty())
            CreateUser->setObjectName(QStringLiteral("CreateUser"));
        CreateUser->resize(400, 287);
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
        passworLb = new QLabel(CreateUser);
        passworLb->setObjectName(QStringLiteral("passworLb"));

        gridLayout->addWidget(passworLb, 5, 0, 1, 1);

        firmEdit = new QLineEdit(CreateUser);
        firmEdit->setObjectName(QStringLiteral("firmEdit"));

        gridLayout->addWidget(firmEdit, 3, 1, 1, 1);

        passwordEdit = new QLineEdit(CreateUser);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));

        gridLayout->addWidget(passwordEdit, 5, 1, 1, 1);

        roleBtn = new QPushButton(CreateUser);
        roleBtn->setObjectName(QStringLiteral("roleBtn"));

        gridLayout->addWidget(roleBtn, 7, 0, 1, 1);

        activaredCmbBox = new QComboBox(CreateUser);
        activaredCmbBox->setObjectName(QStringLiteral("activaredCmbBox"));

        gridLayout->addWidget(activaredCmbBox, 6, 1, 1, 1);

        locationBtn = new QPushButton(CreateUser);
        locationBtn->setObjectName(QStringLiteral("locationBtn"));

        gridLayout->addWidget(locationBtn, 8, 0, 1, 1);

        addressEdit = new QLineEdit(CreateUser);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 1, 1, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 2);

        firmNumLb = new QLabel(CreateUser);
        firmNumLb->setObjectName(QStringLiteral("firmNumLb"));

        gridLayout->addWidget(firmNumLb, 4, 0, 1, 1);

        nameEdit = new QLineEdit(CreateUser);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        firmLb = new QLabel(CreateUser);
        firmLb->setObjectName(QStringLiteral("firmLb"));

        gridLayout->addWidget(firmLb, 3, 0, 1, 1);

        activatedLb = new QLabel(CreateUser);
        activatedLb->setObjectName(QStringLiteral("activatedLb"));

        gridLayout->addWidget(activatedLb, 6, 0, 1, 1);

        nameLb = new QLabel(CreateUser);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        phoneLb = new QLabel(CreateUser);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 2, 0, 1, 1);

        addressLb = new QLabel(CreateUser);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 1, 0, 1, 1);

        phoneEdit = new QLineEdit(CreateUser);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 2, 1, 1, 1);

        firmNumEdit = new QLineEdit(CreateUser);
        firmNumEdit->setObjectName(QStringLiteral("firmNumEdit"));

        gridLayout->addWidget(firmNumEdit, 4, 1, 1, 1);

        roleEdit = new QLineEdit(CreateUser);
        roleEdit->setObjectName(QStringLiteral("roleEdit"));

        gridLayout->addWidget(roleEdit, 7, 1, 1, 1);

        locationEdit = new QLineEdit(CreateUser);
        locationEdit->setObjectName(QStringLiteral("locationEdit"));

        gridLayout->addWidget(locationEdit, 8, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, firmEdit);
        QWidget::setTabOrder(firmEdit, firmNumEdit);
        QWidget::setTabOrder(firmNumEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, activaredCmbBox);
        QWidget::setTabOrder(activaredCmbBox, roleBtn);
        QWidget::setTabOrder(roleBtn, roleEdit);
        QWidget::setTabOrder(roleEdit, locationBtn);
        QWidget::setTabOrder(locationBtn, locationEdit);
        QWidget::setTabOrder(locationEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateUser);

        QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QDialog *CreateUser)
    {
        CreateUser->setWindowTitle(QApplication::translate("CreateUser", "Create/Update User", 0));
        passworLb->setText(QApplication::translate("CreateUser", "Password:", 0));
        roleBtn->setText(QApplication::translate("CreateUser", "Select role", 0));
        locationBtn->setText(QApplication::translate("CreateUser", "Select location", 0));
        okBtn->setText(QApplication::translate("CreateUser", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateUser", "Cancel", 0));
        firmNumLb->setText(QApplication::translate("CreateUser", "Firm number:", 0));
        firmLb->setText(QApplication::translate("CreateUser", "Firm:", 0));
        activatedLb->setText(QApplication::translate("CreateUser", "Activated:", 0));
        nameLb->setText(QApplication::translate("CreateUser", "Name:", 0));
        phoneLb->setText(QApplication::translate("CreateUser", "Phone:", 0));
        addressLb->setText(QApplication::translate("CreateUser", "Address:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSERDLG_H
