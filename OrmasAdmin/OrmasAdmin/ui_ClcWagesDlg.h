/********************************************************************************
** Form generated from reading UI file 'ClcWagesDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLCWAGESDLG_H
#define UI_CLCWAGESDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_CalculateWages
{
public:
    QGridLayout *gridLayout;
    QDateEdit *startDateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QCheckBox *employeeChkBox;
    QDateEdit *endDateEdit;
    QWidget *singleEmployeeWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *employeeBtn;
    QLineEdit *employeeEdit;
    QLabel *startLb;
    QLabel *endLb;

    void setupUi(QDialog *CalculateWages)
    {
        if (CalculateWages->objectName().isEmpty())
            CalculateWages->setObjectName(QStringLiteral("CalculateWages"));
        CalculateWages->resize(400, 162);
        CalculateWages->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CalculateWages->setModal(false);
        gridLayout = new QGridLayout(CalculateWages);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        startDateEdit = new QDateEdit(CalculateWages);
        startDateEdit->setObjectName(QStringLiteral("startDateEdit"));

        gridLayout->addWidget(startDateEdit, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CalculateWages);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CalculateWages);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        employeeChkBox = new QCheckBox(CalculateWages);
        employeeChkBox->setObjectName(QStringLiteral("employeeChkBox"));
        employeeChkBox->setChecked(true);

        gridLayout->addWidget(employeeChkBox, 2, 0, 1, 2);

        endDateEdit = new QDateEdit(CalculateWages);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));

        gridLayout->addWidget(endDateEdit, 1, 1, 1, 1);

        singleEmployeeWidget = new QWidget(CalculateWages);
        singleEmployeeWidget->setObjectName(QStringLiteral("singleEmployeeWidget"));
        horizontalLayout_2 = new QHBoxLayout(singleEmployeeWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        employeeBtn = new QPushButton(singleEmployeeWidget);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(employeeBtn);

        employeeEdit = new QLineEdit(singleEmployeeWidget);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(employeeEdit);


        gridLayout->addWidget(singleEmployeeWidget, 3, 0, 1, 2);

        startLb = new QLabel(CalculateWages);
        startLb->setObjectName(QStringLiteral("startLb"));

        gridLayout->addWidget(startLb, 0, 0, 1, 1);

        endLb = new QLabel(CalculateWages);
        endLb->setObjectName(QStringLiteral("endLb"));

        gridLayout->addWidget(endLb, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CalculateWages);

        QMetaObject::connectSlotsByName(CalculateWages);
    } // setupUi

    void retranslateUi(QDialog *CalculateWages)
    {
        CalculateWages->setWindowTitle(QApplication::translate("CalculateWages", "Calculate wages", 0));
        okBtn->setText(QApplication::translate("CalculateWages", "OK", 0));
        cancelBtn->setText(QApplication::translate("CalculateWages", "Cancel", 0));
        employeeChkBox->setText(QApplication::translate("CalculateWages", "For all employees", 0));
        employeeBtn->setText(QApplication::translate("CalculateWages", "Select employee", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CalculateWages", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        startLb->setText(QApplication::translate("CalculateWages", "From:", 0));
        endLb->setText(QApplication::translate("CalculateWages", "Till:", 0));
    } // retranslateUi

};

namespace Ui {
    class CalculateWages: public Ui_CalculateWages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLCWAGESDLG_H
