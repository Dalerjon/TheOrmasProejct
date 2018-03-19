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
    QLabel *nameLb;
    QLabel *namePh;
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
    QLabel *currencyLb;
    QPushButton *employeeBtn;
    QLineEdit *valueEdit;
    QCheckBox *yesCheckBox;
    QLineEdit *currencyNameEdit;
    QLineEdit *balanceEdit;
    QDateTimeEdit *dateEdit;
    QComboBox *currencyCmb;
    QLineEdit *employeeEdit;

    void setupUi(QDialog *CreateWithdrawal)
    {
        if (CreateWithdrawal->objectName().isEmpty())
            CreateWithdrawal->setObjectName(QStringLiteral("CreateWithdrawal"));
        CreateWithdrawal->resize(558, 283);
        CreateWithdrawal->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWithdrawal->setModal(false);
        gridLayout = new QGridLayout(CreateWithdrawal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        nameLb = new QLabel(CreateWithdrawal);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 2, 1, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 17, 1, 1, 6);

        isBonusLb = new QLabel(CreateWithdrawal);
        isBonusLb->setObjectName(QStringLiteral("isBonusLb"));

        gridLayout->addWidget(isBonusLb, 16, 1, 1, 2);

        allLb = new QLabel(CreateWithdrawal);
        allLb->setObjectName(QStringLiteral("allLb"));

        gridLayout->addWidget(allLb, 15, 1, 1, 2);

        label = new QLabel(CreateWithdrawal);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 12, 1, 1, 2);

        balanceLb = new QLabel(CreateWithdrawal);
        balanceLb->setObjectName(QStringLiteral("balanceLb"));

        gridLayout->addWidget(balanceLb, 11, 1, 1, 2);

        dateLb = new QLabel(CreateWithdrawal);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 10, 1, 1, 2);

        currencyLb = new QLabel(CreateWithdrawal);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 8, 1, 1, 2);

        employeeBtn = new QPushButton(CreateWithdrawal);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 1, 1, 1, 2);

        valueEdit = new QLineEdit(CreateWithdrawal);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 16, 3, 1, 2);

        yesCheckBox = new QCheckBox(CreateWithdrawal);
        yesCheckBox->setObjectName(QStringLiteral("yesCheckBox"));

        gridLayout->addWidget(yesCheckBox, 15, 3, 1, 2);

        currencyNameEdit = new QLineEdit(CreateWithdrawal);
        currencyNameEdit->setObjectName(QStringLiteral("currencyNameEdit"));
        currencyNameEdit->setReadOnly(true);

        gridLayout->addWidget(currencyNameEdit, 12, 3, 1, 2);

        balanceEdit = new QLineEdit(CreateWithdrawal);
        balanceEdit->setObjectName(QStringLiteral("balanceEdit"));
        balanceEdit->setReadOnly(true);

        gridLayout->addWidget(balanceEdit, 11, 3, 1, 2);

        dateEdit = new QDateTimeEdit(CreateWithdrawal);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 10, 3, 1, 2);

        currencyCmb = new QComboBox(CreateWithdrawal);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 8, 3, 1, 2);

        employeeEdit = new QLineEdit(CreateWithdrawal);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 3, 1, 2);

        QWidget::setTabOrder(employeeBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateWithdrawal);

        QMetaObject::connectSlotsByName(CreateWithdrawal);
    } // setupUi

    void retranslateUi(QDialog *CreateWithdrawal)
    {
        CreateWithdrawal->setWindowTitle(QApplication::translate("CreateWithdrawal", "Create/Update withdrawal", 0));
        nameLb->setText(QApplication::translate("CreateWithdrawal", "Name:", 0));
        namePh->setText(QString());
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
        currencyLb->setText(QApplication::translate("CreateWithdrawal", "Select currency:", 0));
        employeeBtn->setText(QApplication::translate("CreateWithdrawal", "Select employee", 0));
        yesCheckBox->setText(QApplication::translate("CreateWithdrawal", "Yes", 0));
#ifndef QT_NO_TOOLTIP
        balanceEdit->setToolTip(QApplication::translate("CreateWithdrawal", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateWithdrawal", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateWithdrawal: public Ui_CreateWithdrawal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWDWDLG_H
