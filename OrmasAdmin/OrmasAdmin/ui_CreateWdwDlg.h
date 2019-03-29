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

QT_BEGIN_NAMESPACE

class Ui_CreateWithdrawal
{
public:
    QGridLayout *gridLayout;
    QLabel *currencyLb;
    QLineEdit *balanceEdit;
    QLabel *namePh;
    QLabel *nameLb;
    QLabel *surnameLb;
    QLabel *surnamePh;
    QLabel *phoneLb;
    QLabel *phonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *isBonusLb;
    QLabel *allLb;
    QLabel *label;
    QLabel *balanceLb;
    QLabel *dateLb;
    QPushButton *userBtn;
    QLineEdit *valueEdit;
    QCheckBox *yesCheckBox;
    QLineEdit *currencyNameEdit;
    QDateTimeEdit *dateEdit;
    QComboBox *currencyCmb;
    QLineEdit *userEdit;
    QPushButton *subAccBtn;
    QLineEdit *saIDEdit;
    QLabel *daLb;
    QLineEdit *saNumberEdit;
    QLabel *targetLB;
    QLineEdit *targetEdit;

    void setupUi(QDialog *CreateWithdrawal)
    {
        if (CreateWithdrawal->objectName().isEmpty())
            CreateWithdrawal->setObjectName(QStringLiteral("CreateWithdrawal"));
        CreateWithdrawal->resize(657, 318);
        CreateWithdrawal->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWithdrawal->setModal(false);
        gridLayout = new QGridLayout(CreateWithdrawal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyLb = new QLabel(CreateWithdrawal);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 1, 1, 2);

        balanceEdit = new QLineEdit(CreateWithdrawal);
        balanceEdit->setObjectName(QStringLiteral("balanceEdit"));
        balanceEdit->setReadOnly(true);

        gridLayout->addWidget(balanceEdit, 12, 3, 1, 2);

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

        gridLayout->addWidget(namePh, 2, 2, 1, 1);

        nameLb = new QLabel(CreateWithdrawal);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 2, 1, 1, 1);

        surnameLb = new QLabel(CreateWithdrawal);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 2, 3, 1, 1);

        surnamePh = new QLabel(CreateWithdrawal);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 2, 4, 1, 1);

        phoneLb = new QLabel(CreateWithdrawal);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(50, 0));
        phoneLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(phoneLb, 2, 5, 1, 1);

        phonePh = new QLabel(CreateWithdrawal);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 2, 6, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 18, 1, 1, 6);

        isBonusLb = new QLabel(CreateWithdrawal);
        isBonusLb->setObjectName(QStringLiteral("isBonusLb"));

        gridLayout->addWidget(isBonusLb, 17, 1, 1, 2);

        allLb = new QLabel(CreateWithdrawal);
        allLb->setObjectName(QStringLiteral("allLb"));

        gridLayout->addWidget(allLb, 16, 1, 1, 2);

        label = new QLabel(CreateWithdrawal);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 13, 1, 1, 2);

        balanceLb = new QLabel(CreateWithdrawal);
        balanceLb->setObjectName(QStringLiteral("balanceLb"));

        gridLayout->addWidget(balanceLb, 12, 1, 1, 2);

        dateLb = new QLabel(CreateWithdrawal);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 11, 1, 1, 2);

        userBtn = new QPushButton(CreateWithdrawal);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 1, 1, 1, 2);

        valueEdit = new QLineEdit(CreateWithdrawal);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 17, 3, 1, 2);

        yesCheckBox = new QCheckBox(CreateWithdrawal);
        yesCheckBox->setObjectName(QStringLiteral("yesCheckBox"));

        gridLayout->addWidget(yesCheckBox, 16, 3, 1, 2);

        currencyNameEdit = new QLineEdit(CreateWithdrawal);
        currencyNameEdit->setObjectName(QStringLiteral("currencyNameEdit"));
        currencyNameEdit->setReadOnly(true);

        gridLayout->addWidget(currencyNameEdit, 13, 3, 1, 2);

        dateEdit = new QDateTimeEdit(CreateWithdrawal);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 11, 3, 1, 2);

        currencyCmb = new QComboBox(CreateWithdrawal);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 3, 1, 2);

        userEdit = new QLineEdit(CreateWithdrawal);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 1, 3, 1, 2);

        subAccBtn = new QPushButton(CreateWithdrawal);
        subAccBtn->setObjectName(QStringLiteral("subAccBtn"));

        gridLayout->addWidget(subAccBtn, 3, 1, 1, 1);

        saIDEdit = new QLineEdit(CreateWithdrawal);
        saIDEdit->setObjectName(QStringLiteral("saIDEdit"));
        saIDEdit->setMaximumSize(QSize(120, 16777215));
        saIDEdit->setReadOnly(true);

        gridLayout->addWidget(saIDEdit, 3, 2, 1, 1);

        daLb = new QLabel(CreateWithdrawal);
        daLb->setObjectName(QStringLiteral("daLb"));

        gridLayout->addWidget(daLb, 3, 3, 1, 1);

        saNumberEdit = new QLineEdit(CreateWithdrawal);
        saNumberEdit->setObjectName(QStringLiteral("saNumberEdit"));
        saNumberEdit->setMinimumSize(QSize(150, 0));
        saNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(saNumberEdit, 3, 6, 1, 1);

        targetLB = new QLabel(CreateWithdrawal);
        targetLB->setObjectName(QStringLiteral("targetLB"));

        gridLayout->addWidget(targetLB, 4, 1, 1, 1);

        targetEdit = new QLineEdit(CreateWithdrawal);
        targetEdit->setObjectName(QStringLiteral("targetEdit"));

        gridLayout->addWidget(targetEdit, 4, 2, 1, 5);

        QWidget::setTabOrder(userBtn, subAccBtn);
        QWidget::setTabOrder(subAccBtn, saNumberEdit);
        QWidget::setTabOrder(saNumberEdit, targetEdit);
        QWidget::setTabOrder(targetEdit, currencyCmb);
        QWidget::setTabOrder(currencyCmb, dateEdit);
        QWidget::setTabOrder(dateEdit, balanceEdit);
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
        currencyLb->setText(QApplication::translate("CreateWithdrawal", "Select currency:", 0));
#ifndef QT_NO_TOOLTIP
        balanceEdit->setToolTip(QApplication::translate("CreateWithdrawal", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        namePh->setText(QString());
        nameLb->setText(QApplication::translate("CreateWithdrawal", "Name:", 0));
        surnameLb->setText(QApplication::translate("CreateWithdrawal", "Surname:", 0));
        surnamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateWithdrawal", "Phone:", 0));
        phonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateWithdrawal", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWithdrawal", "Cancel", 0));
        isBonusLb->setText(QApplication::translate("CreateWithdrawal", "Payment amount:", 0));
        allLb->setText(QApplication::translate("CreateWithdrawal", "Payout full amount?", 0));
        label->setText(QApplication::translate("CreateWithdrawal", "Currency name:", 0));
        balanceLb->setText(QApplication::translate("CreateWithdrawal", "Balance:", 0));
        dateLb->setText(QApplication::translate("CreateWithdrawal", "Date:", 0));
        userBtn->setText(QApplication::translate("CreateWithdrawal", "Select user", 0));
        yesCheckBox->setText(QApplication::translate("CreateWithdrawal", "Yes", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateWithdrawal", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        subAccBtn->setText(QApplication::translate("CreateWithdrawal", "Select subaccount", 0));
        daLb->setText(QApplication::translate("CreateWithdrawal", "Enter account number:", 0));
        saNumberEdit->setText(QString());
        targetLB->setText(QApplication::translate("CreateWithdrawal", "Target:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWithdrawal: public Ui_CreateWithdrawal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWDWDLG_H
