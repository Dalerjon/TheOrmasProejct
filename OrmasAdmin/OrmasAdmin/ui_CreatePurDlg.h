/********************************************************************************
** Form generated from reading UI file 'CreatePurDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPURDLG_H
#define UI_CREATEPURDLG_H

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

class Ui_CreatePurveyor
{
public:
    QGridLayout *gridLayout;
    QLineEdit *companyEdit;
    QComboBox *activatedCmbBox;
    QPushButton *locationBtn;
    QLabel *roleNameLb;
    QLabel *roleNamePh;
    QLabel *companyLb;
    QLineEdit *locationEdit;
    QLineEdit *surnameEdit;
    QLineEdit *passwordEdit;
    QLabel *nameLb;
    QLabel *phoneLb;
    QLineEdit *emailEdit;
    QLabel *surnameLb;
    QLineEdit *nameEdit;
    QLabel *activatedLb;
    QLineEdit *addressEdit;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *emailLb;
    QLabel *addressLb;
    QLabel *passworLb;

    void setupUi(QDialog *CreatePurveyor)
    {
        if (CreatePurveyor->objectName().isEmpty())
            CreatePurveyor->setObjectName(QStringLiteral("CreatePurveyor"));
        CreatePurveyor->resize(400, 310);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreatePurveyor->sizePolicy().hasHeightForWidth());
        CreatePurveyor->setSizePolicy(sizePolicy);
        CreatePurveyor->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePurveyor->setModal(false);
        gridLayout = new QGridLayout(CreatePurveyor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        companyEdit = new QLineEdit(CreatePurveyor);
        companyEdit->setObjectName(QStringLiteral("companyEdit"));

        gridLayout->addWidget(companyEdit, 5, 1, 1, 1);

        activatedCmbBox = new QComboBox(CreatePurveyor);
        activatedCmbBox->setObjectName(QStringLiteral("activatedCmbBox"));

        gridLayout->addWidget(activatedCmbBox, 7, 1, 1, 1);

        locationBtn = new QPushButton(CreatePurveyor);
        locationBtn->setObjectName(QStringLiteral("locationBtn"));

        gridLayout->addWidget(locationBtn, 8, 0, 1, 1);

        roleNameLb = new QLabel(CreatePurveyor);
        roleNameLb->setObjectName(QStringLiteral("roleNameLb"));

        gridLayout->addWidget(roleNameLb, 9, 0, 1, 1);

        roleNamePh = new QLabel(CreatePurveyor);
        roleNamePh->setObjectName(QStringLiteral("roleNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        roleNamePh->setFont(font);

        gridLayout->addWidget(roleNamePh, 9, 1, 1, 1);

        companyLb = new QLabel(CreatePurveyor);
        companyLb->setObjectName(QStringLiteral("companyLb"));

        gridLayout->addWidget(companyLb, 5, 0, 1, 1);

        locationEdit = new QLineEdit(CreatePurveyor);
        locationEdit->setObjectName(QStringLiteral("locationEdit"));
        locationEdit->setReadOnly(true);

        gridLayout->addWidget(locationEdit, 8, 1, 1, 1);

        surnameEdit = new QLineEdit(CreatePurveyor);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        gridLayout->addWidget(surnameEdit, 1, 1, 1, 1);

        passwordEdit = new QLineEdit(CreatePurveyor);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 6, 1, 1, 1);

        nameLb = new QLabel(CreatePurveyor);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        phoneLb = new QLabel(CreatePurveyor);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 4, 0, 1, 1);

        emailEdit = new QLineEdit(CreatePurveyor);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        gridLayout->addWidget(emailEdit, 2, 1, 1, 1);

        surnameLb = new QLabel(CreatePurveyor);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));

        gridLayout->addWidget(surnameLb, 1, 0, 1, 1);

        nameEdit = new QLineEdit(CreatePurveyor);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        activatedLb = new QLabel(CreatePurveyor);
        activatedLb->setObjectName(QStringLiteral("activatedLb"));

        gridLayout->addWidget(activatedLb, 7, 0, 1, 1);

        addressEdit = new QLineEdit(CreatePurveyor);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 3, 1, 1, 1);

        phoneEdit = new QLineEdit(CreatePurveyor);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePurveyor);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePurveyor);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 2);

        emailLb = new QLabel(CreatePurveyor);
        emailLb->setObjectName(QStringLiteral("emailLb"));

        gridLayout->addWidget(emailLb, 2, 0, 1, 1);

        addressLb = new QLabel(CreatePurveyor);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 3, 0, 1, 1);

        passworLb = new QLabel(CreatePurveyor);
        passworLb->setObjectName(QStringLiteral("passworLb"));

        gridLayout->addWidget(passworLb, 6, 0, 1, 1);

        QWidget::setTabOrder(nameEdit, surnameEdit);
        QWidget::setTabOrder(surnameEdit, emailEdit);
        QWidget::setTabOrder(emailEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, companyEdit);
        QWidget::setTabOrder(companyEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, activatedCmbBox);
        QWidget::setTabOrder(activatedCmbBox, locationBtn);
        QWidget::setTabOrder(locationBtn, locationEdit);
        QWidget::setTabOrder(locationEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePurveyor);

        QMetaObject::connectSlotsByName(CreatePurveyor);
    } // setupUi

    void retranslateUi(QDialog *CreatePurveyor)
    {
        CreatePurveyor->setWindowTitle(QApplication::translate("CreatePurveyor", "Create/Update purveyor", 0));
#ifndef QT_NO_TOOLTIP
        companyEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>For example: &quot;Mango Company&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        locationBtn->setText(QApplication::translate("CreatePurveyor", "Select location", 0));
        roleNameLb->setText(QApplication::translate("CreatePurveyor", "Role name:", 0));
        roleNamePh->setText(QString());
        companyLb->setText(QApplication::translate("CreatePurveyor", "Company:", 0));
#ifndef QT_NO_TOOLTIP
        surnameEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>At least 6 characters!</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreatePurveyor", "Name:", 0));
        phoneLb->setText(QApplication::translate("CreatePurveyor", "Phone:", 0));
#ifndef QT_NO_TOOLTIP
        emailEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>For example: John.Doe@gmail.com (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        surnameLb->setText(QApplication::translate("CreatePurveyor", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>For example: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        activatedLb->setText(QApplication::translate("CreatePurveyor", "Activated:", 0));
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>For example: Downing St. 88</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreatePurveyor", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreatePurveyor", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePurveyor", "Cancel", 0));
        emailLb->setText(QApplication::translate("CreatePurveyor", "Email:", 0));
        addressLb->setText(QApplication::translate("CreatePurveyor", "Address:", 0));
        passworLb->setText(QApplication::translate("CreatePurveyor", "Password:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePurveyor: public Ui_CreatePurveyor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPURDLG_H
