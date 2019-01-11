/********************************************************************************
** Form generated from reading UI file 'CreateCERDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECERDLG_H
#define UI_CREATECERDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateCompanyEmployee
{
public:
    QGridLayout *gridLayout;
    QLabel *companyLb;
    QComboBox *companyCmb;
    QLabel *empSurnamePh;
    QLabel *empNameLb;
    QLabel *empPhoneLb;
    QLabel *empSurnameLb;
    QLabel *empNamePh;
    QLabel *empPhonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *employeeEdit;
    QPushButton *employeeBtn;
    QLabel *branchLb;
    QComboBox *branchCmb;

    void setupUi(QDialog *CreateCompanyEmployee)
    {
        if (CreateCompanyEmployee->objectName().isEmpty())
            CreateCompanyEmployee->setObjectName(QStringLiteral("CreateCompanyEmployee"));
        CreateCompanyEmployee->resize(551, 154);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCompanyEmployee->sizePolicy().hasHeightForWidth());
        CreateCompanyEmployee->setSizePolicy(sizePolicy);
        CreateCompanyEmployee->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCompanyEmployee->setModal(false);
        gridLayout = new QGridLayout(CreateCompanyEmployee);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        companyLb = new QLabel(CreateCompanyEmployee);
        companyLb->setObjectName(QStringLiteral("companyLb"));

        gridLayout->addWidget(companyLb, 0, 0, 1, 2);

        companyCmb = new QComboBox(CreateCompanyEmployee);
        companyCmb->setObjectName(QStringLiteral("companyCmb"));

        gridLayout->addWidget(companyCmb, 0, 3, 1, 3);

        empSurnamePh = new QLabel(CreateCompanyEmployee);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 3, 3, 1, 1);

        empNameLb = new QLabel(CreateCompanyEmployee);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(0, 0));
        empNameLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(empNameLb, 3, 0, 1, 1);

        empPhoneLb = new QLabel(CreateCompanyEmployee);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 3, 4, 1, 1);

        empSurnameLb = new QLabel(CreateCompanyEmployee);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 3, 2, 1, 1);

        empNamePh = new QLabel(CreateCompanyEmployee);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 3, 1, 1, 1);

        empPhonePh = new QLabel(CreateCompanyEmployee);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 3, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCompanyEmployee);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCompanyEmployee);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        employeeEdit = new QLineEdit(CreateCompanyEmployee);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 2, 3, 1, 1);

        employeeBtn = new QPushButton(CreateCompanyEmployee);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 2, 0, 1, 2);

        branchLb = new QLabel(CreateCompanyEmployee);
        branchLb->setObjectName(QStringLiteral("branchLb"));

        gridLayout->addWidget(branchLb, 1, 0, 1, 1);

        branchCmb = new QComboBox(CreateCompanyEmployee);
        branchCmb->setObjectName(QStringLiteral("branchCmb"));

        gridLayout->addWidget(branchCmb, 1, 3, 1, 3);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateCompanyEmployee);

        QMetaObject::connectSlotsByName(CreateCompanyEmployee);
    } // setupUi

    void retranslateUi(QDialog *CreateCompanyEmployee)
    {
        CreateCompanyEmployee->setWindowTitle(QApplication::translate("CreateCompanyEmployee", "Create company-employee relation", 0));
        companyLb->setText(QApplication::translate("CreateCompanyEmployee", "Select company:", 0));
        empSurnamePh->setText(QString());
        empNameLb->setText(QApplication::translate("CreateCompanyEmployee", "Name:", 0));
        empPhoneLb->setText(QApplication::translate("CreateCompanyEmployee", "Phone:", 0));
        empSurnameLb->setText(QApplication::translate("CreateCompanyEmployee", "Surname:", 0));
        empNamePh->setText(QString());
        empPhonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateCompanyEmployee", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCompanyEmployee", "Cancel", 0));
        employeeBtn->setText(QApplication::translate("CreateCompanyEmployee", "Select Employee", 0));
        branchLb->setText(QApplication::translate("CreateCompanyEmployee", "Select branch:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateCompanyEmployee: public Ui_CreateCompanyEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECERDLG_H
