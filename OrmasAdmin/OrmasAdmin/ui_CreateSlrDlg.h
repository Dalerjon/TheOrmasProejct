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
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *employeeEdit;
    QLabel *dateLb;
    QPushButton *employeeBtn;
    QPushButton *slrTypeBtn;
    QLineEdit *salaryTypeEdit;
    QLineEdit *valueEdit;
    QComboBox *bonusCmb;
    QLabel *phonePh;
    QLabel *nameLb;
    QLabel *surnamePh;
    QLabel *surnameLb;
    QLabel *valueLb;
    QLabel *isBonusLb;
    QLabel *namePh;
    QLabel *phoneLb;
    QLabel *currencyLb;
    QComboBox *currencyCmb;
    QLabel *salaryTypeNameLb;
    QLabel *salaryTypeNamePh;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateSalary)
    {
        if (CreateSalary->objectName().isEmpty())
            CreateSalary->setObjectName(QStringLiteral("CreateSalary"));
        CreateSalary->resize(666, 235);
        CreateSalary->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSalary->setModal(false);
        gridLayout = new QGridLayout(CreateSalary);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
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


        gridLayout->addLayout(horizontalLayout, 14, 1, 1, 6);

        employeeEdit = new QLineEdit(CreateSalary);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 2, 1, 1);

        dateLb = new QLabel(CreateSalary);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 12, 1, 1, 1);

        employeeBtn = new QPushButton(CreateSalary);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 1, 1, 1, 1);

        slrTypeBtn = new QPushButton(CreateSalary);
        slrTypeBtn->setObjectName(QStringLiteral("slrTypeBtn"));

        gridLayout->addWidget(slrTypeBtn, 9, 1, 1, 1);

        salaryTypeEdit = new QLineEdit(CreateSalary);
        salaryTypeEdit->setObjectName(QStringLiteral("salaryTypeEdit"));
        salaryTypeEdit->setReadOnly(true);

        gridLayout->addWidget(salaryTypeEdit, 9, 2, 1, 1);

        valueEdit = new QLineEdit(CreateSalary);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 5, 2, 1, 1);

        bonusCmb = new QComboBox(CreateSalary);
        bonusCmb->setObjectName(QStringLiteral("bonusCmb"));

        gridLayout->addWidget(bonusCmb, 13, 2, 1, 1);

        phonePh = new QLabel(CreateSalary);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 2, 6, 1, 1);

        nameLb = new QLabel(CreateSalary);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 2, 1, 1, 1);

        surnamePh = new QLabel(CreateSalary);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(120, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 2, 4, 1, 1);

        surnameLb = new QLabel(CreateSalary);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 2, 3, 1, 1);

        valueLb = new QLabel(CreateSalary);
        valueLb->setObjectName(QStringLiteral("valueLb"));

        gridLayout->addWidget(valueLb, 5, 1, 1, 1);

        isBonusLb = new QLabel(CreateSalary);
        isBonusLb->setObjectName(QStringLiteral("isBonusLb"));

        gridLayout->addWidget(isBonusLb, 13, 1, 1, 1);

        namePh = new QLabel(CreateSalary);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(120, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 2, 2, 1, 1);

        phoneLb = new QLabel(CreateSalary);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 2, 5, 1, 1);

        currencyLb = new QLabel(CreateSalary);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 8, 1, 1, 1);

        currencyCmb = new QComboBox(CreateSalary);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 8, 2, 1, 1);

        salaryTypeNameLb = new QLabel(CreateSalary);
        salaryTypeNameLb->setObjectName(QStringLiteral("salaryTypeNameLb"));

        gridLayout->addWidget(salaryTypeNameLb, 9, 3, 1, 1);

        salaryTypeNamePh = new QLabel(CreateSalary);
        salaryTypeNamePh->setObjectName(QStringLiteral("salaryTypeNamePh"));
        salaryTypeNamePh->setFont(font);

        gridLayout->addWidget(salaryTypeNamePh, 9, 4, 1, 1);

        dateEdit = new QDateTimeEdit(CreateSalary);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 12, 2, 1, 1);

        QWidget::setTabOrder(employeeBtn, employeeEdit);
        QWidget::setTabOrder(employeeEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, slrTypeBtn);
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
        okBtn->setText(QApplication::translate("CreateSalary", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSalary", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateSalary", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        dateLb->setText(QApplication::translate("CreateSalary", "Date:", 0));
        employeeBtn->setText(QApplication::translate("CreateSalary", "Select employee", 0));
        slrTypeBtn->setText(QApplication::translate("CreateSalary", "Select salary type", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateSalary", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        phonePh->setText(QString());
        nameLb->setText(QApplication::translate("CreateSalary", "Name:", 0));
        surnamePh->setText(QString());
        surnameLb->setText(QApplication::translate("CreateSalary", "Surname:", 0));
        valueLb->setText(QApplication::translate("CreateSalary", "Value:", 0));
        isBonusLb->setText(QApplication::translate("CreateSalary", "Is bonus?", 0));
        namePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateSalary", "Phone:", 0));
        currencyLb->setText(QApplication::translate("CreateSalary", "Select currency:", 0));
        salaryTypeNameLb->setText(QApplication::translate("CreateSalary", "Salary type name:", 0));
        salaryTypeNamePh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateSalary: public Ui_CreateSalary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESLRDLG_H
