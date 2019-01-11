/********************************************************************************
** Form generated from reading UI file 'CreateCASHERDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECASHERDLG_H
#define UI_CREATECASHERDLG_H

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

class Ui_CreateCashboxEmployee
{
public:
    QGridLayout *gridLayout;
    QLabel *empPhoneLb;
    QLabel *empSurnamePh;
    QLabel *empNameLb;
    QLabel *empNamePh;
    QLabel *empSurnameLb;
    QLabel *empPhonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *employeeEdit;
    QPushButton *employeeBtn;
    QLabel *cashboxLb;
    QComboBox *cashboxCmb;

    void setupUi(QDialog *CreateCashboxEmployee)
    {
        if (CreateCashboxEmployee->objectName().isEmpty())
            CreateCashboxEmployee->setObjectName(QStringLiteral("CreateCashboxEmployee"));
        CreateCashboxEmployee->resize(551, 144);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCashboxEmployee->sizePolicy().hasHeightForWidth());
        CreateCashboxEmployee->setSizePolicy(sizePolicy);
        CreateCashboxEmployee->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCashboxEmployee->setModal(false);
        gridLayout = new QGridLayout(CreateCashboxEmployee);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empPhoneLb = new QLabel(CreateCashboxEmployee);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 2, 4, 1, 1);

        empSurnamePh = new QLabel(CreateCashboxEmployee);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 2, 3, 1, 1);

        empNameLb = new QLabel(CreateCashboxEmployee);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(0, 0));
        empNameLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(empNameLb, 2, 0, 1, 1);

        empNamePh = new QLabel(CreateCashboxEmployee);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 2, 1, 1, 1);

        empSurnameLb = new QLabel(CreateCashboxEmployee);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 2, 2, 1, 1);

        empPhonePh = new QLabel(CreateCashboxEmployee);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCashboxEmployee);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCashboxEmployee);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 6);

        employeeEdit = new QLineEdit(CreateCashboxEmployee);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 3, 1, 1);

        employeeBtn = new QPushButton(CreateCashboxEmployee);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 1, 0, 1, 2);

        cashboxLb = new QLabel(CreateCashboxEmployee);
        cashboxLb->setObjectName(QStringLiteral("cashboxLb"));

        gridLayout->addWidget(cashboxLb, 0, 0, 1, 2);

        cashboxCmb = new QComboBox(CreateCashboxEmployee);
        cashboxCmb->setObjectName(QStringLiteral("cashboxCmb"));

        gridLayout->addWidget(cashboxCmb, 0, 3, 1, 3);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateCashboxEmployee);

        QMetaObject::connectSlotsByName(CreateCashboxEmployee);
    } // setupUi

    void retranslateUi(QDialog *CreateCashboxEmployee)
    {
        CreateCashboxEmployee->setWindowTitle(QApplication::translate("CreateCashboxEmployee", "Create cashbox-employee relation", 0));
        empPhoneLb->setText(QApplication::translate("CreateCashboxEmployee", "Phone:", 0));
        empSurnamePh->setText(QString());
        empNameLb->setText(QApplication::translate("CreateCashboxEmployee", "Name:", 0));
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateCashboxEmployee", "Surname:", 0));
        empPhonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateCashboxEmployee", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCashboxEmployee", "Cancel", 0));
        employeeBtn->setText(QApplication::translate("CreateCashboxEmployee", "Select Employee", 0));
        cashboxLb->setText(QApplication::translate("CreateCashboxEmployee", "Select cashbox:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateCashboxEmployee: public Ui_CreateCashboxEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECASHERDLG_H
