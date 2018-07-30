/********************************************************************************
** Form generated from reading UI file 'CreateEmpDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEEMPDLG_H
#define UI_CREATEEMPDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateEmployee
{
public:
    QGridLayout *gridLayout;
    QComboBox *activatedCmbBox;
    QLabel *addressLb;
    QLabel *nameLb;
    QPushButton *positionBtn;
    QLineEdit *passwordEdit;
    QLineEdit *nameEdit;
    QLineEdit *positionEdit;
    QLabel *activatedLb;
    QLabel *passworLb;
    QLineEdit *surnameEdit;
    QLabel *positionNamePh;
    QLabel *positionNameLb;
    QLabel *hireLb;
    QLabel *roleNameLb;
    QDateEdit *birthDateEdit;
    QPushButton *roleBtn;
    QLineEdit *roleEdit;
    QLabel *birthLb;
    QDateEdit *hireDateEdit;
    QLineEdit *emailEdit;
    QLabel *roleNamePh;
    QLabel *phoneLb;
    QLineEdit *addressEdit;
    QLabel *surnameLb;
    QLineEdit *phoneEdit;
    QLabel *emailLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QComboBox *divisionCmbBox;
    QLabel *divisionLb;
    QLabel *label;
    QCheckBox *isContractChkBox;

    void setupUi(QDialog *CreateEmployee)
    {
        if (CreateEmployee->objectName().isEmpty())
            CreateEmployee->setObjectName(QStringLiteral("CreateEmployee"));
        CreateEmployee->resize(381, 448);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateEmployee->sizePolicy().hasHeightForWidth());
        CreateEmployee->setSizePolicy(sizePolicy);
        CreateEmployee->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateEmployee->setModal(false);
        gridLayout = new QGridLayout(CreateEmployee);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        activatedCmbBox = new QComboBox(CreateEmployee);
        activatedCmbBox->setObjectName(QStringLiteral("activatedCmbBox"));

        gridLayout->addWidget(activatedCmbBox, 8, 1, 1, 1);

        addressLb = new QLabel(CreateEmployee);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 3, 0, 1, 1);

        nameLb = new QLabel(CreateEmployee);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        positionBtn = new QPushButton(CreateEmployee);
        positionBtn->setObjectName(QStringLiteral("positionBtn"));

        gridLayout->addWidget(positionBtn, 11, 0, 1, 1);

        passwordEdit = new QLineEdit(CreateEmployee);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 7, 1, 1, 1);

        nameEdit = new QLineEdit(CreateEmployee);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        positionEdit = new QLineEdit(CreateEmployee);
        positionEdit->setObjectName(QStringLiteral("positionEdit"));
        positionEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);
        positionEdit->setReadOnly(true);

        gridLayout->addWidget(positionEdit, 11, 1, 1, 1);

        activatedLb = new QLabel(CreateEmployee);
        activatedLb->setObjectName(QStringLiteral("activatedLb"));

        gridLayout->addWidget(activatedLb, 8, 0, 1, 1);

        passworLb = new QLabel(CreateEmployee);
        passworLb->setObjectName(QStringLiteral("passworLb"));

        gridLayout->addWidget(passworLb, 7, 0, 1, 1);

        surnameEdit = new QLineEdit(CreateEmployee);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        gridLayout->addWidget(surnameEdit, 1, 1, 1, 1);

        positionNamePh = new QLabel(CreateEmployee);
        positionNamePh->setObjectName(QStringLiteral("positionNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        positionNamePh->setFont(font);

        gridLayout->addWidget(positionNamePh, 12, 1, 1, 1);

        positionNameLb = new QLabel(CreateEmployee);
        positionNameLb->setObjectName(QStringLiteral("positionNameLb"));

        gridLayout->addWidget(positionNameLb, 12, 0, 1, 1);

        hireLb = new QLabel(CreateEmployee);
        hireLb->setObjectName(QStringLiteral("hireLb"));

        gridLayout->addWidget(hireLb, 6, 0, 1, 1);

        roleNameLb = new QLabel(CreateEmployee);
        roleNameLb->setObjectName(QStringLiteral("roleNameLb"));

        gridLayout->addWidget(roleNameLb, 10, 0, 1, 1);

        birthDateEdit = new QDateEdit(CreateEmployee);
        birthDateEdit->setObjectName(QStringLiteral("birthDateEdit"));

        gridLayout->addWidget(birthDateEdit, 5, 1, 1, 1);

        roleBtn = new QPushButton(CreateEmployee);
        roleBtn->setObjectName(QStringLiteral("roleBtn"));

        gridLayout->addWidget(roleBtn, 9, 0, 1, 1);

        roleEdit = new QLineEdit(CreateEmployee);
        roleEdit->setObjectName(QStringLiteral("roleEdit"));
        roleEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);
        roleEdit->setReadOnly(true);

        gridLayout->addWidget(roleEdit, 9, 1, 1, 1);

        birthLb = new QLabel(CreateEmployee);
        birthLb->setObjectName(QStringLiteral("birthLb"));

        gridLayout->addWidget(birthLb, 5, 0, 1, 1);

        hireDateEdit = new QDateEdit(CreateEmployee);
        hireDateEdit->setObjectName(QStringLiteral("hireDateEdit"));

        gridLayout->addWidget(hireDateEdit, 6, 1, 1, 1);

        emailEdit = new QLineEdit(CreateEmployee);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        gridLayout->addWidget(emailEdit, 2, 1, 1, 1);

        roleNamePh = new QLabel(CreateEmployee);
        roleNamePh->setObjectName(QStringLiteral("roleNamePh"));
        roleNamePh->setFont(font);

        gridLayout->addWidget(roleNamePh, 10, 1, 1, 1);

        phoneLb = new QLabel(CreateEmployee);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 4, 0, 1, 1);

        addressEdit = new QLineEdit(CreateEmployee);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 3, 1, 1, 1);

        surnameLb = new QLabel(CreateEmployee);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));

        gridLayout->addWidget(surnameLb, 1, 0, 1, 1);

        phoneEdit = new QLineEdit(CreateEmployee);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));
        phoneEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);

        gridLayout->addWidget(phoneEdit, 4, 1, 1, 1);

        emailLb = new QLabel(CreateEmployee);
        emailLb->setObjectName(QStringLiteral("emailLb"));

        gridLayout->addWidget(emailLb, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateEmployee);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateEmployee);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 15, 0, 1, 2);

        divisionCmbBox = new QComboBox(CreateEmployee);
        divisionCmbBox->setObjectName(QStringLiteral("divisionCmbBox"));

        gridLayout->addWidget(divisionCmbBox, 13, 1, 1, 1);

        divisionLb = new QLabel(CreateEmployee);
        divisionLb->setObjectName(QStringLiteral("divisionLb"));

        gridLayout->addWidget(divisionLb, 13, 0, 1, 1);

        label = new QLabel(CreateEmployee);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 14, 0, 1, 1);

        isContractChkBox = new QCheckBox(CreateEmployee);
        isContractChkBox->setObjectName(QStringLiteral("isContractChkBox"));

        gridLayout->addWidget(isContractChkBox, 14, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, surnameEdit);
        QWidget::setTabOrder(surnameEdit, emailEdit);
        QWidget::setTabOrder(emailEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, birthDateEdit);
        QWidget::setTabOrder(birthDateEdit, hireDateEdit);
        QWidget::setTabOrder(hireDateEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, activatedCmbBox);
        QWidget::setTabOrder(activatedCmbBox, roleBtn);
        QWidget::setTabOrder(roleBtn, roleEdit);
        QWidget::setTabOrder(roleEdit, positionBtn);
        QWidget::setTabOrder(positionBtn, positionEdit);
        QWidget::setTabOrder(positionEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateEmployee);

        QMetaObject::connectSlotsByName(CreateEmployee);
    } // setupUi

    void retranslateUi(QDialog *CreateEmployee)
    {
        CreateEmployee->setWindowTitle(QApplication::translate("CreateEmployee", "Create/Update employee", 0));
        addressLb->setText(QApplication::translate("CreateEmployee", "Address:", 0));
        nameLb->setText(QApplication::translate("CreateEmployee", "Name:", 0));
        positionBtn->setText(QApplication::translate("CreateEmployee", "Select position", 0));
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>At least 6 characters!</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For expamle: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        activatedLb->setText(QApplication::translate("CreateEmployee", "Activated:", 0));
        passworLb->setText(QApplication::translate("CreateEmployee", "Password:", 0));
#ifndef QT_NO_TOOLTIP
        surnameEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        positionNamePh->setText(QString());
        positionNameLb->setText(QApplication::translate("CreateEmployee", "Position name:", 0));
        hireLb->setText(QApplication::translate("CreateEmployee", "Hire date:", 0));
        roleNameLb->setText(QApplication::translate("CreateEmployee", "Role name:", 0));
#ifndef QT_NO_TOOLTIP
        birthDateEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>Enter your birth date:</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roleBtn->setText(QApplication::translate("CreateEmployee", "Select role", 0));
        birthLb->setText(QApplication::translate("CreateEmployee", "Birth date:", 0));
#ifndef QT_NO_TOOLTIP
        hireDateEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>Enter your hire date</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        emailEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: John.Doe@gmail.com (not a mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roleNamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateEmployee", "Phone:", 0));
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: Downing St. 88</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        surnameLb->setText(QApplication::translate("CreateEmployee", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        emailLb->setText(QApplication::translate("CreateEmployee", "Email:", 0));
        okBtn->setText(QApplication::translate("CreateEmployee", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateEmployee", "Cancel", 0));
        divisionLb->setText(QApplication::translate("CreateEmployee", "Division:", 0));
        label->setText(QApplication::translate("CreateEmployee", "Is contract?", 0));
        isContractChkBox->setText(QApplication::translate("CreateEmployee", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateEmployee: public Ui_CreateEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEEMPDLG_H
