/********************************************************************************
** Form generated from reading UI file 'CreateCltDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECLTDLG_H
#define UI_CREATECLTDLG_H

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

class Ui_CreateClient
{
public:
    QGridLayout *gridLayout;
    QLineEdit *emailEdit;
    QLabel *surnameLb;
    QLabel *passworLb;
    QLineEdit *firmEdit;
    QComboBox *activatedCmbBox;
    QPushButton *locationBtn;
    QLineEdit *passwordEdit;
    QLabel *nameLb;
    QLabel *phoneLb;
    QLineEdit *locationEdit;
    QLineEdit *surnameEdit;
    QLabel *emailLb;
    QLabel *activatedLb;
    QLineEdit *nameEdit;
    QLabel *firmLb;
    QLineEdit *firmNumEdit;
    QLabel *addressLb;
    QLineEdit *phoneEdit;
    QLineEdit *addressEdit;
    QLabel *firmNumLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CreateClient)
    {
        if (CreateClient->objectName().isEmpty())
            CreateClient->setObjectName(QStringLiteral("CreateClient"));
        CreateClient->resize(400, 310);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateClient->sizePolicy().hasHeightForWidth());
        CreateClient->setSizePolicy(sizePolicy);
        CreateClient->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateClient->setModal(false);
        gridLayout = new QGridLayout(CreateClient);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        emailEdit = new QLineEdit(CreateClient);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        gridLayout->addWidget(emailEdit, 2, 1, 1, 1);

        surnameLb = new QLabel(CreateClient);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));

        gridLayout->addWidget(surnameLb, 1, 0, 1, 1);

        passworLb = new QLabel(CreateClient);
        passworLb->setObjectName(QStringLiteral("passworLb"));

        gridLayout->addWidget(passworLb, 7, 0, 1, 1);

        firmEdit = new QLineEdit(CreateClient);
        firmEdit->setObjectName(QStringLiteral("firmEdit"));

        gridLayout->addWidget(firmEdit, 5, 1, 1, 1);

        activatedCmbBox = new QComboBox(CreateClient);
        activatedCmbBox->setObjectName(QStringLiteral("activatedCmbBox"));

        gridLayout->addWidget(activatedCmbBox, 8, 1, 1, 1);

        locationBtn = new QPushButton(CreateClient);
        locationBtn->setObjectName(QStringLiteral("locationBtn"));

        gridLayout->addWidget(locationBtn, 9, 0, 1, 1);

        passwordEdit = new QLineEdit(CreateClient);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));

        gridLayout->addWidget(passwordEdit, 7, 1, 1, 1);

        nameLb = new QLabel(CreateClient);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        phoneLb = new QLabel(CreateClient);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 4, 0, 1, 1);

        locationEdit = new QLineEdit(CreateClient);
        locationEdit->setObjectName(QStringLiteral("locationEdit"));
        locationEdit->setReadOnly(true);

        gridLayout->addWidget(locationEdit, 9, 1, 1, 1);

        surnameEdit = new QLineEdit(CreateClient);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        gridLayout->addWidget(surnameEdit, 1, 1, 1, 1);

        emailLb = new QLabel(CreateClient);
        emailLb->setObjectName(QStringLiteral("emailLb"));

        gridLayout->addWidget(emailLb, 2, 0, 1, 1);

        activatedLb = new QLabel(CreateClient);
        activatedLb->setObjectName(QStringLiteral("activatedLb"));

        gridLayout->addWidget(activatedLb, 8, 0, 1, 1);

        nameEdit = new QLineEdit(CreateClient);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        firmLb = new QLabel(CreateClient);
        firmLb->setObjectName(QStringLiteral("firmLb"));

        gridLayout->addWidget(firmLb, 5, 0, 1, 1);

        firmNumEdit = new QLineEdit(CreateClient);
        firmNumEdit->setObjectName(QStringLiteral("firmNumEdit"));

        gridLayout->addWidget(firmNumEdit, 6, 1, 1, 1);

        addressLb = new QLabel(CreateClient);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 3, 0, 1, 1);

        phoneEdit = new QLineEdit(CreateClient);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 4, 1, 1, 1);

        addressEdit = new QLineEdit(CreateClient);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 3, 1, 1, 1);

        firmNumLb = new QLabel(CreateClient);
        firmNumLb->setObjectName(QStringLiteral("firmNumLb"));

        gridLayout->addWidget(firmNumLb, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateClient);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateClient);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 2);

        QWidget::setTabOrder(nameEdit, surnameEdit);
        QWidget::setTabOrder(surnameEdit, emailEdit);
        QWidget::setTabOrder(emailEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, firmEdit);
        QWidget::setTabOrder(firmEdit, firmNumEdit);
        QWidget::setTabOrder(firmNumEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, activatedCmbBox);
        QWidget::setTabOrder(activatedCmbBox, locationBtn);
        QWidget::setTabOrder(locationBtn, locationEdit);
        QWidget::setTabOrder(locationEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateClient);

        QMetaObject::connectSlotsByName(CreateClient);
    } // setupUi

    void retranslateUi(QDialog *CreateClient)
    {
        CreateClient->setWindowTitle(QApplication::translate("CreateClient", "Create/Update client", 0));
#ifndef QT_NO_TOOLTIP
        emailEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: John.Doe@gmail.com (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        surnameLb->setText(QApplication::translate("CreateClient", "Surname:", 0));
        passworLb->setText(QApplication::translate("CreateClient", "Password:", 0));
#ifndef QT_NO_TOOLTIP
        firmEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: &quot;Mango Company&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        locationBtn->setText(QApplication::translate("CreateClient", "Select location", 0));
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>At least 6 characters!</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreateClient", "Name:", 0));
        phoneLb->setText(QApplication::translate("CreateClient", "Phone:", 0));
#ifndef QT_NO_TOOLTIP
        surnameEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        emailLb->setText(QApplication::translate("CreateClient", "Email:", 0));
        activatedLb->setText(QApplication::translate("CreateClient", "Activated:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        firmLb->setText(QApplication::translate("CreateClient", "Firm:", 0));
#ifndef QT_NO_TOOLTIP
        firmNumEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: 5 (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addressLb->setText(QApplication::translate("CreateClient", "Address:", 0));
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateClient", "<html><head/><body><p>For example: Downing St. 88</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        firmNumLb->setText(QApplication::translate("CreateClient", "Firm number:", 0));
        okBtn->setText(QApplication::translate("CreateClient", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateClient", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateClient: public Ui_CreateClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECLTDLG_H
