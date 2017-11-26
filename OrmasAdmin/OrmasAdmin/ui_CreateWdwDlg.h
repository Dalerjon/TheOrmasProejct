/********************************************************************************
** Form generated from reading UI file 'CreateWdwDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWDWDLG_H
#define UI_CREATEWDWDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateWithdrawal
{
public:
    QGridLayout *gridLayout;
    QPushButton *currencyBtn;
    QLineEdit *valueEdit;
    QLineEdit *currencyNameEdit;
    QLabel *label;
    QCheckBox *yesCheckBox;
    QLabel *allLb;
    QLineEdit *employeeEdit;
    QPushButton *employeeBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *currencyEdit;
    QLabel *isBonusLb;
    QLabel *balanceLb;
    QLineEdit *balanceEdit;
    QLabel *dateLb;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateWithdrawal)
    {
        if (CreateWithdrawal->objectName().isEmpty())
            CreateWithdrawal->setObjectName(QStringLiteral("CreateWithdrawal"));
        CreateWithdrawal->resize(400, 232);
        CreateWithdrawal->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWithdrawal->setModal(false);
        gridLayout = new QGridLayout(CreateWithdrawal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyBtn = new QPushButton(CreateWithdrawal);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 8, 1, 1, 1);

        valueEdit = new QLineEdit(CreateWithdrawal);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 16, 2, 1, 1);

        currencyNameEdit = new QLineEdit(CreateWithdrawal);
        currencyNameEdit->setObjectName(QStringLiteral("currencyNameEdit"));
        currencyNameEdit->setReadOnly(true);

        gridLayout->addWidget(currencyNameEdit, 12, 2, 1, 1);

        label = new QLabel(CreateWithdrawal);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 12, 1, 1, 1);

        yesCheckBox = new QCheckBox(CreateWithdrawal);
        yesCheckBox->setObjectName(QStringLiteral("yesCheckBox"));

        gridLayout->addWidget(yesCheckBox, 15, 2, 1, 1);

        allLb = new QLabel(CreateWithdrawal);
        allLb->setObjectName(QStringLiteral("allLb"));

        gridLayout->addWidget(allLb, 15, 1, 1, 1);

        employeeEdit = new QLineEdit(CreateWithdrawal);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 2, 1, 1);

        employeeBtn = new QPushButton(CreateWithdrawal);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWithdrawal);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWithdrawal);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 17, 1, 1, 2);

        currencyEdit = new QLineEdit(CreateWithdrawal);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 8, 2, 1, 1);

        isBonusLb = new QLabel(CreateWithdrawal);
        isBonusLb->setObjectName(QStringLiteral("isBonusLb"));

        gridLayout->addWidget(isBonusLb, 16, 1, 1, 1);

        balanceLb = new QLabel(CreateWithdrawal);
        balanceLb->setObjectName(QStringLiteral("balanceLb"));

        gridLayout->addWidget(balanceLb, 11, 1, 1, 1);

        balanceEdit = new QLineEdit(CreateWithdrawal);
        balanceEdit->setObjectName(QStringLiteral("balanceEdit"));
        balanceEdit->setReadOnly(true);

        gridLayout->addWidget(balanceEdit, 11, 2, 1, 1);

        dateLb = new QLabel(CreateWithdrawal);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 10, 1, 1, 1);

        dateEdit = new QDateTimeEdit(CreateWithdrawal);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 10, 2, 1, 1);

        QWidget::setTabOrder(employeeBtn, employeeEdit);
        QWidget::setTabOrder(employeeEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, currencyNameEdit);
        QWidget::setTabOrder(currencyNameEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateWithdrawal);

        QMetaObject::connectSlotsByName(CreateWithdrawal);
    } // setupUi

    void retranslateUi(QDialog *CreateWithdrawal)
    {
        CreateWithdrawal->setWindowTitle(QApplication::translate("CreateWithdrawal", "Create/Update withdrawal", 0));
        currencyBtn->setText(QApplication::translate("CreateWithdrawal", "Select currency", 0));
        label->setText(QApplication::translate("CreateWithdrawal", "Currency name:", 0));
        yesCheckBox->setText(QApplication::translate("CreateWithdrawal", "Yes", 0));
        allLb->setText(QApplication::translate("CreateWithdrawal", "Payout full amount?", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateWithdrawal", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        employeeBtn->setText(QApplication::translate("CreateWithdrawal", "Select employee", 0));
        okBtn->setText(QApplication::translate("CreateWithdrawal", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWithdrawal", "Cancel", 0));
        isBonusLb->setText(QApplication::translate("CreateWithdrawal", "Payment amount:", 0));
        balanceLb->setText(QApplication::translate("CreateWithdrawal", "Balance:", 0));
#ifndef QT_NO_TOOLTIP
        balanceEdit->setToolTip(QApplication::translate("CreateWithdrawal", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        dateLb->setText(QApplication::translate("CreateWithdrawal", "Date:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWithdrawal: public Ui_CreateWithdrawal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWDWDLG_H
