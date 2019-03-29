/********************************************************************************
** Form generated from reading UI file 'CreateSAccDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESACCDLG_H
#define UI_CREATESACCDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateSubaccount
{
public:
    QGridLayout *gridLayout;
    QLabel *numberLb;
    QDateEdit *openedDateEdit;
    QLineEdit *chartOfAccEdit;
    QLabel *accNamePh;
    QPushButton *chartOfAccBtn;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *numberEdit;
    QLabel *cBalanceLb;
    QLabel *currencyLb;
    QComboBox *currencyCmb;
    QLabel *accNameLb;
    QLabel *sBalanceLb;
    QLineEdit *startBalanceEdit;
    QLabel *firmLb;
    QLabel *oDateLb;
    QLineEdit *detailsEdit;
    QLineEdit *currentBalanceEdit;
    QLabel *label;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;

    void setupUi(QDialog *CreateSubaccount)
    {
        if (CreateSubaccount->objectName().isEmpty())
            CreateSubaccount->setObjectName(QStringLiteral("CreateSubaccount"));
        CreateSubaccount->resize(593, 287);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateSubaccount->sizePolicy().hasHeightForWidth());
        CreateSubaccount->setSizePolicy(sizePolicy);
        CreateSubaccount->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSubaccount->setModal(false);
        gridLayout = new QGridLayout(CreateSubaccount);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        numberLb = new QLabel(CreateSubaccount);
        numberLb->setObjectName(QStringLiteral("numberLb"));
        numberLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(numberLb, 0, 0, 1, 1);

        openedDateEdit = new QDateEdit(CreateSubaccount);
        openedDateEdit->setObjectName(QStringLiteral("openedDateEdit"));
        openedDateEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(openedDateEdit, 8, 1, 1, 1);

        chartOfAccEdit = new QLineEdit(CreateSubaccount);
        chartOfAccEdit->setObjectName(QStringLiteral("chartOfAccEdit"));
        chartOfAccEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(chartOfAccEdit, 1, 1, 1, 1);

        accNamePh = new QLabel(CreateSubaccount);
        accNamePh->setObjectName(QStringLiteral("accNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        accNamePh->setFont(font);

        gridLayout->addWidget(accNamePh, 2, 1, 1, 3);

        chartOfAccBtn = new QPushButton(CreateSubaccount);
        chartOfAccBtn->setObjectName(QStringLiteral("chartOfAccBtn"));

        gridLayout->addWidget(chartOfAccBtn, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateSubaccount);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateSubaccount);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 4);

        numberEdit = new QLineEdit(CreateSubaccount);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setMinimumSize(QSize(150, 0));
        numberEdit->setMaximumSize(QSize(150, 16777215));
        numberEdit->setReadOnly(true);

        gridLayout->addWidget(numberEdit, 0, 1, 1, 1);

        cBalanceLb = new QLabel(CreateSubaccount);
        cBalanceLb->setObjectName(QStringLiteral("cBalanceLb"));

        gridLayout->addWidget(cBalanceLb, 5, 0, 1, 1);

        currencyLb = new QLabel(CreateSubaccount);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));
        currencyLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 1);

        currencyCmb = new QComboBox(CreateSubaccount);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 6, 1, 1, 1);

        accNameLb = new QLabel(CreateSubaccount);
        accNameLb->setObjectName(QStringLiteral("accNameLb"));

        gridLayout->addWidget(accNameLb, 2, 0, 1, 1);

        sBalanceLb = new QLabel(CreateSubaccount);
        sBalanceLb->setObjectName(QStringLiteral("sBalanceLb"));

        gridLayout->addWidget(sBalanceLb, 3, 0, 1, 1);

        startBalanceEdit = new QLineEdit(CreateSubaccount);
        startBalanceEdit->setObjectName(QStringLiteral("startBalanceEdit"));
        startBalanceEdit->setMinimumSize(QSize(150, 0));
        startBalanceEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(startBalanceEdit, 3, 1, 1, 1);

        firmLb = new QLabel(CreateSubaccount);
        firmLb->setObjectName(QStringLiteral("firmLb"));

        gridLayout->addWidget(firmLb, 9, 0, 1, 1);

        oDateLb = new QLabel(CreateSubaccount);
        oDateLb->setObjectName(QStringLiteral("oDateLb"));

        gridLayout->addWidget(oDateLb, 8, 0, 1, 1);

        detailsEdit = new QLineEdit(CreateSubaccount);
        detailsEdit->setObjectName(QStringLiteral("detailsEdit"));
        detailsEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(detailsEdit, 9, 1, 1, 1);

        currentBalanceEdit = new QLineEdit(CreateSubaccount);
        currentBalanceEdit->setObjectName(QStringLiteral("currentBalanceEdit"));
        currentBalanceEdit->setMinimumSize(QSize(150, 0));
        currentBalanceEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currentBalanceEdit, 5, 1, 1, 1);

        label = new QLabel(CreateSubaccount);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        statusWidget = new QWidget(CreateSubaccount);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBtn = new QPushButton(statusWidget);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        sizePolicy.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy);
        statusBtn->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(statusBtn);

        statusEdit = new QLineEdit(statusWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setMinimumSize(QSize(150, 0));
        statusEdit->setMaximumSize(QSize(150, 16777215));
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


        gridLayout->addWidget(statusWidget, 7, 0, 1, 4);

        QWidget::setTabOrder(numberEdit, chartOfAccBtn);
        QWidget::setTabOrder(chartOfAccBtn, startBalanceEdit);
        QWidget::setTabOrder(startBalanceEdit, currentBalanceEdit);
        QWidget::setTabOrder(currentBalanceEdit, currencyCmb);
        QWidget::setTabOrder(currencyCmb, statusBtn);
        QWidget::setTabOrder(statusBtn, openedDateEdit);
        QWidget::setTabOrder(openedDateEdit, detailsEdit);
        QWidget::setTabOrder(detailsEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, chartOfAccEdit);
        QWidget::setTabOrder(chartOfAccEdit, statusEdit);

        retranslateUi(CreateSubaccount);

        QMetaObject::connectSlotsByName(CreateSubaccount);
    } // setupUi

    void retranslateUi(QDialog *CreateSubaccount)
    {
        CreateSubaccount->setWindowTitle(QApplication::translate("CreateSubaccount", "Create/Update subaccount", 0));
        numberLb->setText(QApplication::translate("CreateSubaccount", "Number:", 0));
        accNamePh->setText(QString());
        chartOfAccBtn->setText(QApplication::translate("CreateSubaccount", "Select accout from chart", 0));
        okBtn->setText(QApplication::translate("CreateSubaccount", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSubaccount", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        numberEdit->setToolTip(QApplication::translate("CreateSubaccount", "<html><head/><body><p>For example: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cBalanceLb->setText(QApplication::translate("CreateSubaccount", "Current balance:", 0));
        currencyLb->setText(QApplication::translate("CreateSubaccount", "Select currency:", 0));
        accNameLb->setText(QApplication::translate("CreateSubaccount", "Account name:", 0));
        sBalanceLb->setText(QApplication::translate("CreateSubaccount", "Start balance:", 0));
#ifndef QT_NO_TOOLTIP
        startBalanceEdit->setToolTip(QApplication::translate("CreateSubaccount", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        firmLb->setText(QApplication::translate("CreateSubaccount", "Details:", 0));
        oDateLb->setText(QApplication::translate("CreateSubaccount", "Opened date:", 0));
#ifndef QT_NO_TOOLTIP
        detailsEdit->setToolTip(QApplication::translate("CreateSubaccount", "<html><head/><body><p>For example: &quot;Mango Company&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        currentBalanceEdit->setToolTip(QApplication::translate("CreateSubaccount", "<html><head/><body><p>For example: John.Doe@gmail.com (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("CreateSubaccount", "Number will generate from other parameters", 0));
        statusBtn->setText(QApplication::translate("CreateSubaccount", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateSubaccount", "Status name:", 0));
        statusPh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateSubaccount: public Ui_CreateSubaccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESACCDLG_H
