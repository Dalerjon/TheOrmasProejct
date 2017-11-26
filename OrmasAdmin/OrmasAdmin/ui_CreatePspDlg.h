/********************************************************************************
** Form generated from reading UI file 'CreatePspDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPSPDLG_H
#define UI_CREATEPSPDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_CreatePayslip
{
public:
    QGridLayout *gridLayout;
    QLineEdit *salaryEdit;
    QLineEdit *valueEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *currencyEdit;
    QLabel *valieLb;
    QPushButton *currencyBtn;
    QLabel *dateLb;
    QPushButton *salaryBtn;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreatePayslip)
    {
        if (CreatePayslip->objectName().isEmpty())
            CreatePayslip->setObjectName(QStringLiteral("CreatePayslip"));
        CreatePayslip->resize(400, 157);
        CreatePayslip->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePayslip->setModal(false);
        gridLayout = new QGridLayout(CreatePayslip);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        salaryEdit = new QLineEdit(CreatePayslip);
        salaryEdit->setObjectName(QStringLiteral("salaryEdit"));
        salaryEdit->setReadOnly(true);

        gridLayout->addWidget(salaryEdit, 4, 1, 1, 1);

        valueEdit = new QLineEdit(CreatePayslip);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePayslip);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePayslip);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        currencyEdit = new QLineEdit(CreatePayslip);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 5, 1, 1, 1);

        valieLb = new QLabel(CreatePayslip);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        currencyBtn = new QPushButton(CreatePayslip);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 5, 0, 1, 1);

        dateLb = new QLabel(CreatePayslip);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        salaryBtn = new QPushButton(CreatePayslip);
        salaryBtn->setObjectName(QStringLiteral("salaryBtn"));
        salaryBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(salaryBtn, 4, 0, 1, 1);

        dateEdit = new QDateTimeEdit(CreatePayslip);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

        QWidget::setTabOrder(valueEdit, salaryBtn);
        QWidget::setTabOrder(salaryBtn, salaryEdit);
        QWidget::setTabOrder(salaryEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePayslip);

        QMetaObject::connectSlotsByName(CreatePayslip);
    } // setupUi

    void retranslateUi(QDialog *CreatePayslip)
    {
        CreatePayslip->setWindowTitle(QApplication::translate("CreatePayslip", "Create/Update payslip", 0));
#ifndef QT_NO_TOOLTIP
        salaryEdit->setToolTip(QApplication::translate("CreatePayslip", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePayslip", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreatePayslip", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePayslip", "Cancel", 0));
        valieLb->setText(QApplication::translate("CreatePayslip", "Sum:", 0));
        currencyBtn->setText(QApplication::translate("CreatePayslip", "Select currency", 0));
        dateLb->setText(QApplication::translate("CreatePayslip", "Date:", 0));
        salaryBtn->setText(QApplication::translate("CreatePayslip", "Select salary", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePayslip: public Ui_CreatePayslip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPSPDLG_H
