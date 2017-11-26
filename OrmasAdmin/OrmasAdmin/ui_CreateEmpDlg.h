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
    QDateEdit *birthDateEdit;
    QLabel *hireLb;
    QLineEdit *nameEdit;
    QLabel *emailLb;
    QLineEdit *surnameEdit;
    QLabel *surnameLb;
    QLineEdit *phoneEdit;
    QLineEdit *emailEdit;
    QLabel *passworLb;
    QLabel *nameLb;
    QLabel *birthLb;
    QLabel *activatedLb;
    QDateEdit *hireDateEdit;
    QLineEdit *positionEdit;
    QComboBox *activatedCmbBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *passwordEdit;
    QLabel *phoneLb;
    QLabel *addressLb;
    QPushButton *positionBtn;
    QLineEdit *addressEdit;
    QPushButton *roleBtn;
    QLineEdit *roleEdit;

    void setupUi(QDialog *CreateEmployee)
    {
        if (CreateEmployee->objectName().isEmpty())
            CreateEmployee->setObjectName(QStringLiteral("CreateEmployee"));
        CreateEmployee->resize(400, 339);
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
        birthDateEdit = new QDateEdit(CreateEmployee);
        birthDateEdit->setObjectName(QStringLiteral("birthDateEdit"));

        gridLayout->addWidget(birthDateEdit, 5, 1, 1, 1);

        hireLb = new QLabel(CreateEmployee);
        hireLb->setObjectName(QStringLiteral("hireLb"));

        gridLayout->addWidget(hireLb, 6, 0, 1, 1);

        nameEdit = new QLineEdit(CreateEmployee);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        emailLb = new QLabel(CreateEmployee);
        emailLb->setObjectName(QStringLiteral("emailLb"));

        gridLayout->addWidget(emailLb, 2, 0, 1, 1);

        surnameEdit = new QLineEdit(CreateEmployee);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        gridLayout->addWidget(surnameEdit, 1, 1, 1, 1);

        surnameLb = new QLabel(CreateEmployee);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));

        gridLayout->addWidget(surnameLb, 1, 0, 1, 1);

        phoneEdit = new QLineEdit(CreateEmployee);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));
        phoneEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);

        gridLayout->addWidget(phoneEdit, 4, 1, 1, 1);

        emailEdit = new QLineEdit(CreateEmployee);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        gridLayout->addWidget(emailEdit, 2, 1, 1, 1);

        passworLb = new QLabel(CreateEmployee);
        passworLb->setObjectName(QStringLiteral("passworLb"));

        gridLayout->addWidget(passworLb, 7, 0, 1, 1);

        nameLb = new QLabel(CreateEmployee);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        birthLb = new QLabel(CreateEmployee);
        birthLb->setObjectName(QStringLiteral("birthLb"));

        gridLayout->addWidget(birthLb, 5, 0, 1, 1);

        activatedLb = new QLabel(CreateEmployee);
        activatedLb->setObjectName(QStringLiteral("activatedLb"));

        gridLayout->addWidget(activatedLb, 8, 0, 1, 1);

        hireDateEdit = new QDateEdit(CreateEmployee);
        hireDateEdit->setObjectName(QStringLiteral("hireDateEdit"));

        gridLayout->addWidget(hireDateEdit, 6, 1, 1, 1);

        positionEdit = new QLineEdit(CreateEmployee);
        positionEdit->setObjectName(QStringLiteral("positionEdit"));
        positionEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);
        positionEdit->setReadOnly(true);

        gridLayout->addWidget(positionEdit, 10, 1, 1, 1);

        activatedCmbBox = new QComboBox(CreateEmployee);
        activatedCmbBox->setObjectName(QStringLiteral("activatedCmbBox"));

        gridLayout->addWidget(activatedCmbBox, 8, 1, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 11, 0, 1, 2);

        passwordEdit = new QLineEdit(CreateEmployee);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 7, 1, 1, 1);

        phoneLb = new QLabel(CreateEmployee);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 4, 0, 1, 1);

        addressLb = new QLabel(CreateEmployee);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 3, 0, 1, 1);

        positionBtn = new QPushButton(CreateEmployee);
        positionBtn->setObjectName(QStringLiteral("positionBtn"));

        gridLayout->addWidget(positionBtn, 10, 0, 1, 1);

        addressEdit = new QLineEdit(CreateEmployee);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 3, 1, 1, 1);

        roleBtn = new QPushButton(CreateEmployee);
        roleBtn->setObjectName(QStringLiteral("roleBtn"));

        gridLayout->addWidget(roleBtn, 9, 0, 1, 1);

        roleEdit = new QLineEdit(CreateEmployee);
        roleEdit->setObjectName(QStringLiteral("roleEdit"));
        roleEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhPreferNumbers);
        roleEdit->setReadOnly(true);

        gridLayout->addWidget(roleEdit, 9, 1, 1, 1);

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
#ifndef QT_NO_TOOLTIP
        birthDateEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>Enter your birth date:</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        hireLb->setText(QApplication::translate("CreateEmployee", "Hire date:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For expamle: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        emailLb->setText(QApplication::translate("CreateEmployee", "Email:", 0));
#ifndef QT_NO_TOOLTIP
        surnameEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        surnameLb->setText(QApplication::translate("CreateEmployee", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        emailEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: John.Doe@gmail.com (not a mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        passworLb->setText(QApplication::translate("CreateEmployee", "Password:", 0));
        nameLb->setText(QApplication::translate("CreateEmployee", "Name:", 0));
        birthLb->setText(QApplication::translate("CreateEmployee", "Birth date:", 0));
        activatedLb->setText(QApplication::translate("CreateEmployee", "Activated:", 0));
#ifndef QT_NO_TOOLTIP
        hireDateEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>Enter your hire date</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateEmployee", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateEmployee", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        passwordEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>At least 6 characters!</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        phoneLb->setText(QApplication::translate("CreateEmployee", "Phone:", 0));
        addressLb->setText(QApplication::translate("CreateEmployee", "Address:", 0));
        positionBtn->setText(QApplication::translate("CreateEmployee", "Select position", 0));
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateEmployee", "<html><head/><body><p>For example: Downing St. 88</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roleBtn->setText(QApplication::translate("CreateEmployee", "Select role", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateEmployee: public Ui_CreateEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEEMPDLG_H
