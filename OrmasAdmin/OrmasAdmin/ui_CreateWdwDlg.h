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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateWithdrawal
{
public:
    QGridLayout *gridLayout;
    QDateTimeEdit *dateEdit;
    QLabel *nameLb;
    QLabel *surnameLb;
    QLabel *namePh;
    QLabel *label;
    QLabel *surnamePh;
    QLabel *allLb;
    QLabel *currencyLb;
    QLineEdit *balanceEdit;
    QComboBox *currencyCmb;
    QLineEdit *userEdit;
    QLineEdit *valueEdit;
    QPushButton *userBtn;
    QLabel *isBonusLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *currencyNameEdit;
    QLabel *phoneLb;
    QLabel *phonePh;
    QCheckBox *yesCheckBox;
    QLabel *balanceLb;
    QLabel *dateLb;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QComboBox *accountCmb;
    QLabel *accountNameLb;
    QLineEdit *saNumberEdit;
    QPushButton *subAccBtn;
    QLineEdit *saIDEdit;
    QLabel *targetLB;
    QLineEdit *targetEdit;
    QPushButton *accBtn;
    QLineEdit *accIDEdit;
    QLineEdit *accNumberEdit;
    QLabel *daLb_2;
    QLabel *daLb;

    void setupUi(QDialog *CreateWithdrawal)
    {
        if (CreateWithdrawal->objectName().isEmpty())
            CreateWithdrawal->setObjectName(QStringLiteral("CreateWithdrawal"));
        CreateWithdrawal->resize(685, 394);
        CreateWithdrawal->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWithdrawal->setModal(false);
        gridLayout = new QGridLayout(CreateWithdrawal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        dateEdit = new QDateTimeEdit(CreateWithdrawal);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 7, 3, 1, 2);

        nameLb = new QLabel(CreateWithdrawal);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 3, 1, 1, 1);

        surnameLb = new QLabel(CreateWithdrawal);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 3, 3, 1, 1);

        namePh = new QLabel(CreateWithdrawal);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 3, 2, 1, 1);

        label = new QLabel(CreateWithdrawal);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 15, 1, 1, 2);

        surnamePh = new QLabel(CreateWithdrawal);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 3, 4, 1, 1);

        allLb = new QLabel(CreateWithdrawal);
        allLb->setObjectName(QStringLiteral("allLb"));

        gridLayout->addWidget(allLb, 18, 1, 1, 2);

        currencyLb = new QLabel(CreateWithdrawal);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 11, 1, 1, 2);

        balanceEdit = new QLineEdit(CreateWithdrawal);
        balanceEdit->setObjectName(QStringLiteral("balanceEdit"));
        balanceEdit->setReadOnly(true);

        gridLayout->addWidget(balanceEdit, 14, 3, 1, 2);

        currencyCmb = new QComboBox(CreateWithdrawal);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 11, 3, 1, 2);

        userEdit = new QLineEdit(CreateWithdrawal);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 2, 3, 1, 2);

        valueEdit = new QLineEdit(CreateWithdrawal);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 19, 3, 1, 2);

        userBtn = new QPushButton(CreateWithdrawal);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 2, 1, 1, 2);

        isBonusLb = new QLabel(CreateWithdrawal);
        isBonusLb->setObjectName(QStringLiteral("isBonusLb"));

        gridLayout->addWidget(isBonusLb, 19, 1, 1, 2);

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


        gridLayout->addLayout(horizontalLayout, 21, 1, 1, 6);

        currencyNameEdit = new QLineEdit(CreateWithdrawal);
        currencyNameEdit->setObjectName(QStringLiteral("currencyNameEdit"));
        currencyNameEdit->setReadOnly(true);

        gridLayout->addWidget(currencyNameEdit, 15, 3, 1, 2);

        phoneLb = new QLabel(CreateWithdrawal);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(50, 0));
        phoneLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(phoneLb, 3, 5, 1, 1);

        phonePh = new QLabel(CreateWithdrawal);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 3, 6, 1, 1);

        yesCheckBox = new QCheckBox(CreateWithdrawal);
        yesCheckBox->setObjectName(QStringLiteral("yesCheckBox"));

        gridLayout->addWidget(yesCheckBox, 18, 3, 1, 2);

        balanceLb = new QLabel(CreateWithdrawal);
        balanceLb->setObjectName(QStringLiteral("balanceLb"));

        gridLayout->addWidget(balanceLb, 14, 1, 1, 2);

        dateLb = new QLabel(CreateWithdrawal);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 7, 1, 1, 1);

        statusWidget = new QWidget(CreateWithdrawal);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBtn = new QPushButton(statusWidget);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy);
        statusBtn->setMinimumSize(QSize(197, 0));

        horizontalLayout_3->addWidget(statusBtn);

        statusEdit = new QLineEdit(statusWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(statusEdit);

        statusLb = new QLabel(statusWidget);
        statusLb->setObjectName(QStringLiteral("statusLb"));

        horizontalLayout_3->addWidget(statusLb);

        statusPh = new QLabel(statusWidget);
        statusPh->setObjectName(QStringLiteral("statusPh"));
        statusPh->setMinimumSize(QSize(120, 0));
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout->addWidget(statusWidget, 20, 1, 1, 6);

        accountCmb = new QComboBox(CreateWithdrawal);
        accountCmb->setObjectName(QStringLiteral("accountCmb"));

        gridLayout->addWidget(accountCmb, 1, 2, 1, 5);

        accountNameLb = new QLabel(CreateWithdrawal);
        accountNameLb->setObjectName(QStringLiteral("accountNameLb"));

        gridLayout->addWidget(accountNameLb, 1, 1, 1, 1);

        saNumberEdit = new QLineEdit(CreateWithdrawal);
        saNumberEdit->setObjectName(QStringLiteral("saNumberEdit"));
        saNumberEdit->setMinimumSize(QSize(150, 0));
        saNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(saNumberEdit, 4, 6, 1, 1);

        subAccBtn = new QPushButton(CreateWithdrawal);
        subAccBtn->setObjectName(QStringLiteral("subAccBtn"));

        gridLayout->addWidget(subAccBtn, 4, 1, 1, 1);

        saIDEdit = new QLineEdit(CreateWithdrawal);
        saIDEdit->setObjectName(QStringLiteral("saIDEdit"));
        saIDEdit->setMaximumSize(QSize(120, 16777215));
        saIDEdit->setReadOnly(true);

        gridLayout->addWidget(saIDEdit, 4, 2, 1, 1);

        targetLB = new QLabel(CreateWithdrawal);
        targetLB->setObjectName(QStringLiteral("targetLB"));

        gridLayout->addWidget(targetLB, 6, 1, 1, 1);

        targetEdit = new QLineEdit(CreateWithdrawal);
        targetEdit->setObjectName(QStringLiteral("targetEdit"));

        gridLayout->addWidget(targetEdit, 6, 2, 1, 5);

        accBtn = new QPushButton(CreateWithdrawal);
        accBtn->setObjectName(QStringLiteral("accBtn"));

        gridLayout->addWidget(accBtn, 5, 1, 1, 1);

        accIDEdit = new QLineEdit(CreateWithdrawal);
        accIDEdit->setObjectName(QStringLiteral("accIDEdit"));
        accIDEdit->setMaximumSize(QSize(120, 16777215));
        accIDEdit->setReadOnly(true);

        gridLayout->addWidget(accIDEdit, 5, 2, 1, 1);

        accNumberEdit = new QLineEdit(CreateWithdrawal);
        accNumberEdit->setObjectName(QStringLiteral("accNumberEdit"));
        accNumberEdit->setMinimumSize(QSize(150, 0));
        accNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(accNumberEdit, 5, 6, 1, 1);

        daLb_2 = new QLabel(CreateWithdrawal);
        daLb_2->setObjectName(QStringLiteral("daLb_2"));

        gridLayout->addWidget(daLb_2, 5, 4, 1, 1);

        daLb = new QLabel(CreateWithdrawal);
        daLb->setObjectName(QStringLiteral("daLb"));

        gridLayout->addWidget(daLb, 4, 4, 1, 1);

        QWidget::setTabOrder(userBtn, subAccBtn);
        QWidget::setTabOrder(subAccBtn, saNumberEdit);
        QWidget::setTabOrder(saNumberEdit, targetEdit);
        QWidget::setTabOrder(targetEdit, currencyCmb);
        QWidget::setTabOrder(currencyCmb, balanceEdit);
        QWidget::setTabOrder(balanceEdit, currencyNameEdit);
        QWidget::setTabOrder(currencyNameEdit, yesCheckBox);
        QWidget::setTabOrder(yesCheckBox, valueEdit);
        QWidget::setTabOrder(valueEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, userEdit);
        QWidget::setTabOrder(userEdit, saIDEdit);

        retranslateUi(CreateWithdrawal);

        QMetaObject::connectSlotsByName(CreateWithdrawal);
    } // setupUi

    void retranslateUi(QDialog *CreateWithdrawal)
    {
        CreateWithdrawal->setWindowTitle(QApplication::translate("CreateWithdrawal", "Create/Update withdrawal", 0));
        nameLb->setText(QApplication::translate("CreateWithdrawal", "Name:", 0));
        surnameLb->setText(QApplication::translate("CreateWithdrawal", "Surname:", 0));
        namePh->setText(QString());
        label->setText(QApplication::translate("CreateWithdrawal", "Currency name:", 0));
        surnamePh->setText(QString());
        allLb->setText(QApplication::translate("CreateWithdrawal", "Payout full amount?", 0));
        currencyLb->setText(QApplication::translate("CreateWithdrawal", "Select currency:", 0));
#ifndef QT_NO_TOOLTIP
        balanceEdit->setToolTip(QApplication::translate("CreateWithdrawal", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateWithdrawal", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        userBtn->setText(QApplication::translate("CreateWithdrawal", "Select user", 0));
        isBonusLb->setText(QApplication::translate("CreateWithdrawal", "Payment amount:", 0));
        okBtn->setText(QApplication::translate("CreateWithdrawal", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWithdrawal", "Cancel", 0));
        phoneLb->setText(QApplication::translate("CreateWithdrawal", "Phone:", 0));
        phonePh->setText(QString());
        yesCheckBox->setText(QApplication::translate("CreateWithdrawal", "Yes", 0));
        balanceLb->setText(QApplication::translate("CreateWithdrawal", "Balance:", 0));
        dateLb->setText(QApplication::translate("CreateWithdrawal", "Date:", 0));
        statusBtn->setText(QApplication::translate("CreateWithdrawal", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateWithdrawal", "Status name:", 0));
        statusPh->setText(QString());
        accountNameLb->setText(QApplication::translate("CreateWithdrawal", "Account name:", 0));
        saNumberEdit->setText(QString());
        subAccBtn->setText(QApplication::translate("CreateWithdrawal", "Select subaccount", 0));
        targetLB->setText(QApplication::translate("CreateWithdrawal", "Target:", 0));
        accBtn->setText(QApplication::translate("CreateWithdrawal", "Select account", 0));
        accNumberEdit->setText(QString());
        daLb_2->setText(QApplication::translate("CreateWithdrawal", "Enter account number:", 0));
        daLb->setText(QApplication::translate("CreateWithdrawal", "Enter subaccount number:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWithdrawal: public Ui_CreateWithdrawal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWDWDLG_H
