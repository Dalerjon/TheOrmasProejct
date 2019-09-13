/********************************************************************************
** Form generated from reading UI file 'CreatePmtDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPMTDLG_H
#define UI_CREATEPMTDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_CreatePayment
{
public:
    QGridLayout *gridLayout;
    QLineEdit *targetEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *accountNameLb;
    QLabel *targetLB;
    QLabel *surnameLb;
    QLineEdit *userEdit;
    QComboBox *accountCmb;
    QLineEdit *whoEdit;
    QLabel *whoLB;
    QLabel *phoneLb;
    QLineEdit *accNumberEdit;
    QLabel *valieLb;
    QDateTimeEdit *dateEdit;
    QLineEdit *valueEdit;
    QLabel *currencyLb;
    QPushButton *userBtn;
    QComboBox *currencyCmb;
    QLineEdit *accIDEdit;
    QLabel *daLb_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *dateLb;
    QLabel *surnamePh;
    QLabel *namePh;
    QLabel *phonePh;
    QPushButton *accBtn;
    QPushButton *subAccBtn;
    QLineEdit *saIDEdit;
    QLabel *daLb;
    QLineEdit *saNumberEdit;

    void setupUi(QDialog *CreatePayment)
    {
        if (CreatePayment->objectName().isEmpty())
            CreatePayment->setObjectName(QStringLiteral("CreatePayment"));
        CreatePayment->resize(687, 345);
        CreatePayment->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePayment->setModal(false);
        gridLayout = new QGridLayout(CreatePayment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        targetEdit = new QLineEdit(CreatePayment);
        targetEdit->setObjectName(QStringLiteral("targetEdit"));

        gridLayout->addWidget(targetEdit, 10, 1, 1, 5);

        statusWidget = new QWidget(CreatePayment);
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
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout->addWidget(statusWidget, 14, 0, 1, 6);

        accountNameLb = new QLabel(CreatePayment);
        accountNameLb->setObjectName(QStringLiteral("accountNameLb"));

        gridLayout->addWidget(accountNameLb, 1, 0, 1, 1);

        targetLB = new QLabel(CreatePayment);
        targetLB->setObjectName(QStringLiteral("targetLB"));

        gridLayout->addWidget(targetLB, 10, 0, 1, 1);

        surnameLb = new QLabel(CreatePayment);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 7, 2, 1, 1);

        userEdit = new QLineEdit(CreatePayment);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 6, 2, 1, 2);

        accountCmb = new QComboBox(CreatePayment);
        accountCmb->setObjectName(QStringLiteral("accountCmb"));

        gridLayout->addWidget(accountCmb, 1, 1, 1, 5);

        whoEdit = new QLineEdit(CreatePayment);
        whoEdit->setObjectName(QStringLiteral("whoEdit"));

        gridLayout->addWidget(whoEdit, 0, 1, 1, 5);

        whoLB = new QLabel(CreatePayment);
        whoLB->setObjectName(QStringLiteral("whoLB"));

        gridLayout->addWidget(whoLB, 0, 0, 1, 1);

        phoneLb = new QLabel(CreatePayment);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 7, 4, 1, 1);

        accNumberEdit = new QLineEdit(CreatePayment);
        accNumberEdit->setObjectName(QStringLiteral("accNumberEdit"));
        accNumberEdit->setMinimumSize(QSize(150, 0));
        accNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(accNumberEdit, 9, 5, 1, 1);

        valieLb = new QLabel(CreatePayment);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 12, 0, 1, 1);

        dateEdit = new QDateTimeEdit(CreatePayment);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 11, 2, 1, 2);

        valueEdit = new QLineEdit(CreatePayment);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 12, 2, 1, 2);

        currencyLb = new QLabel(CreatePayment);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 13, 0, 1, 2);

        userBtn = new QPushButton(CreatePayment);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 6, 0, 1, 2);

        currencyCmb = new QComboBox(CreatePayment);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 13, 2, 1, 2);

        accIDEdit = new QLineEdit(CreatePayment);
        accIDEdit->setObjectName(QStringLiteral("accIDEdit"));
        accIDEdit->setMaximumSize(QSize(120, 16777215));
        accIDEdit->setReadOnly(true);

        gridLayout->addWidget(accIDEdit, 9, 1, 1, 1);

        daLb_2 = new QLabel(CreatePayment);
        daLb_2->setObjectName(QStringLiteral("daLb_2"));

        gridLayout->addWidget(daLb_2, 9, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePayment);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePayment);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 15, 0, 1, 6);

        nameLb = new QLabel(CreatePayment);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 7, 0, 1, 1);

        dateLb = new QLabel(CreatePayment);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 11, 0, 1, 1);

        surnamePh = new QLabel(CreatePayment);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 7, 3, 1, 1);

        namePh = new QLabel(CreatePayment);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 7, 1, 1, 1);

        phonePh = new QLabel(CreatePayment);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 7, 5, 1, 1);

        accBtn = new QPushButton(CreatePayment);
        accBtn->setObjectName(QStringLiteral("accBtn"));

        gridLayout->addWidget(accBtn, 9, 0, 1, 1);

        subAccBtn = new QPushButton(CreatePayment);
        subAccBtn->setObjectName(QStringLiteral("subAccBtn"));

        gridLayout->addWidget(subAccBtn, 8, 0, 1, 1);

        saIDEdit = new QLineEdit(CreatePayment);
        saIDEdit->setObjectName(QStringLiteral("saIDEdit"));
        saIDEdit->setMaximumSize(QSize(120, 16777215));
        saIDEdit->setReadOnly(true);

        gridLayout->addWidget(saIDEdit, 8, 1, 1, 1);

        daLb = new QLabel(CreatePayment);
        daLb->setObjectName(QStringLiteral("daLb"));

        gridLayout->addWidget(daLb, 8, 3, 1, 1);

        saNumberEdit = new QLineEdit(CreatePayment);
        saNumberEdit->setObjectName(QStringLiteral("saNumberEdit"));
        saNumberEdit->setMinimumSize(QSize(150, 0));
        saNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(saNumberEdit, 8, 5, 1, 1);

        QWidget::setTabOrder(userBtn, statusBtn);
        QWidget::setTabOrder(statusBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, currencyCmb);
        QWidget::setTabOrder(currencyCmb, statusEdit);

        retranslateUi(CreatePayment);

        QMetaObject::connectSlotsByName(CreatePayment);
    } // setupUi

    void retranslateUi(QDialog *CreatePayment)
    {
        CreatePayment->setWindowTitle(QApplication::translate("CreatePayment", "Create/Update payment", 0));
        statusBtn->setText(QApplication::translate("CreatePayment", "Change status", 0));
        statusLb->setText(QApplication::translate("CreatePayment", "Status name:", 0));
        statusPh->setText(QString());
        accountNameLb->setText(QApplication::translate("CreatePayment", "Account name:", 0));
        targetLB->setText(QApplication::translate("CreatePayment", "Target:", 0));
        surnameLb->setText(QApplication::translate("CreatePayment", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreatePayment", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        whoLB->setText(QApplication::translate("CreatePayment", "From who:", 0));
        phoneLb->setText(QApplication::translate("CreatePayment", "Phone:", 0));
        accNumberEdit->setText(QString());
        valieLb->setText(QApplication::translate("CreatePayment", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePayment", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currencyLb->setText(QApplication::translate("CreatePayment", "Select currency:", 0));
        userBtn->setText(QApplication::translate("CreatePayment", "Select user", 0));
        daLb_2->setText(QApplication::translate("CreatePayment", "Enter account number:", 0));
        okBtn->setText(QApplication::translate("CreatePayment", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePayment", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreatePayment", "Name:", 0));
        dateLb->setText(QApplication::translate("CreatePayment", "Date:", 0));
        surnamePh->setText(QString());
        namePh->setText(QString());
        phonePh->setText(QString());
        accBtn->setText(QApplication::translate("CreatePayment", "Select account", 0));
        subAccBtn->setText(QApplication::translate("CreatePayment", "Select subaccount", 0));
        daLb->setText(QApplication::translate("CreatePayment", "Enter subaccount number:", 0));
        saNumberEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreatePayment: public Ui_CreatePayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPMTDLG_H
