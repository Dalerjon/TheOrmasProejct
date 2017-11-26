/********************************************************************************
** Form generated from reading UI file 'CreateSlrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESLRDLG_H
#define UI_CREATESLRDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_CreateSalary
{
public:
    QGridLayout *gridLayout;
    QLineEdit *salaryTypeEdit;
    QLabel *dateLb;
    QLineEdit *valueEdit;
    QPushButton *employeeBtn;
    QPushButton *slrTypeBtn;
    QLineEdit *employeeEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *currencyBtn;
    QLabel *valueLb;
    QLineEdit *currencyEdit;
    QLabel *isBonusLb;
    QComboBox *bonusCmb;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateSalary)
    {
        if (CreateSalary->objectName().isEmpty())
            CreateSalary->setObjectName(QStringLiteral("CreateSalary"));
        CreateSalary->resize(400, 212);
        CreateSalary->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSalary->setModal(false);
        gridLayout = new QGridLayout(CreateSalary);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        salaryTypeEdit = new QLineEdit(CreateSalary);
        salaryTypeEdit->setObjectName(QStringLiteral("salaryTypeEdit"));
        salaryTypeEdit->setReadOnly(true);

        gridLayout->addWidget(salaryTypeEdit, 9, 2, 1, 1);

        dateLb = new QLabel(CreateSalary);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 12, 1, 1, 1);

        valueEdit = new QLineEdit(CreateSalary);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 5, 2, 1, 1);

        employeeBtn = new QPushButton(CreateSalary);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 1, 1, 1, 1);

        slrTypeBtn = new QPushButton(CreateSalary);
        slrTypeBtn->setObjectName(QStringLiteral("slrTypeBtn"));

        gridLayout->addWidget(slrTypeBtn, 9, 1, 1, 1);

        employeeEdit = new QLineEdit(CreateSalary);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateSalary);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateSalary);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 14, 1, 1, 2);

        currencyBtn = new QPushButton(CreateSalary);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 8, 1, 1, 1);

        valueLb = new QLabel(CreateSalary);
        valueLb->setObjectName(QStringLiteral("valueLb"));

        gridLayout->addWidget(valueLb, 5, 1, 1, 1);

        currencyEdit = new QLineEdit(CreateSalary);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 8, 2, 1, 1);

        isBonusLb = new QLabel(CreateSalary);
        isBonusLb->setObjectName(QStringLiteral("isBonusLb"));

        gridLayout->addWidget(isBonusLb, 13, 1, 1, 1);

        bonusCmb = new QComboBox(CreateSalary);
        bonusCmb->setObjectName(QStringLiteral("bonusCmb"));

        gridLayout->addWidget(bonusCmb, 13, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateSalary);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 12, 2, 1, 1);

        QWidget::setTabOrder(employeeBtn, employeeEdit);
        QWidget::setTabOrder(employeeEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, slrTypeBtn);
        QWidget::setTabOrder(slrTypeBtn, salaryTypeEdit);
        QWidget::setTabOrder(salaryTypeEdit, bonusCmb);
        QWidget::setTabOrder(bonusCmb, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateSalary);

        QMetaObject::connectSlotsByName(CreateSalary);
    } // setupUi

    void retranslateUi(QDialog *CreateSalary)
    {
        CreateSalary->setWindowTitle(QApplication::translate("CreateSalary", "Create/Update salary", 0));
        dateLb->setText(QApplication::translate("CreateSalary", "Date:", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateSalary", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        employeeBtn->setText(QApplication::translate("CreateSalary", "Select employee", 0));
        slrTypeBtn->setText(QApplication::translate("CreateSalary", "Select salary type", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateSalary", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateSalary", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSalary", "Cancel", 0));
        currencyBtn->setText(QApplication::translate("CreateSalary", "Select currency", 0));
        valueLb->setText(QApplication::translate("CreateSalary", "Value:", 0));
        isBonusLb->setText(QApplication::translate("CreateSalary", "Is bonus?", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateSalary: public Ui_CreateSalary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESLRDLG_H
