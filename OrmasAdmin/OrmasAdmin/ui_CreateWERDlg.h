/********************************************************************************
** Form generated from reading UI file 'CreateWERDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWERDLG_H
#define UI_CREATEWERDLG_H

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

class Ui_CreateWarehouseEmployee
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
    QLabel *warehouseLb;
    QComboBox *warehouseCmb;

    void setupUi(QDialog *CreateWarehouseEmployee)
    {
        if (CreateWarehouseEmployee->objectName().isEmpty())
            CreateWarehouseEmployee->setObjectName(QStringLiteral("CreateWarehouseEmployee"));
        CreateWarehouseEmployee->resize(551, 144);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateWarehouseEmployee->sizePolicy().hasHeightForWidth());
        CreateWarehouseEmployee->setSizePolicy(sizePolicy);
        CreateWarehouseEmployee->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWarehouseEmployee->setModal(false);
        gridLayout = new QGridLayout(CreateWarehouseEmployee);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empPhoneLb = new QLabel(CreateWarehouseEmployee);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 2, 4, 1, 1);

        empSurnamePh = new QLabel(CreateWarehouseEmployee);
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

        empNameLb = new QLabel(CreateWarehouseEmployee);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(0, 0));
        empNameLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(empNameLb, 2, 0, 1, 1);

        empNamePh = new QLabel(CreateWarehouseEmployee);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 2, 1, 1, 1);

        empSurnameLb = new QLabel(CreateWarehouseEmployee);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 2, 2, 1, 1);

        empPhonePh = new QLabel(CreateWarehouseEmployee);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWarehouseEmployee);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWarehouseEmployee);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 6);

        employeeEdit = new QLineEdit(CreateWarehouseEmployee);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 3, 1, 1);

        employeeBtn = new QPushButton(CreateWarehouseEmployee);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(employeeBtn, 1, 0, 1, 2);

        warehouseLb = new QLabel(CreateWarehouseEmployee);
        warehouseLb->setObjectName(QStringLiteral("warehouseLb"));

        gridLayout->addWidget(warehouseLb, 0, 0, 1, 2);

        warehouseCmb = new QComboBox(CreateWarehouseEmployee);
        warehouseCmb->setObjectName(QStringLiteral("warehouseCmb"));

        gridLayout->addWidget(warehouseCmb, 0, 3, 1, 3);

        QWidget::setTabOrder(warehouseCmb, employeeBtn);
        QWidget::setTabOrder(employeeBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, employeeEdit);

        retranslateUi(CreateWarehouseEmployee);

        QMetaObject::connectSlotsByName(CreateWarehouseEmployee);
    } // setupUi

    void retranslateUi(QDialog *CreateWarehouseEmployee)
    {
        CreateWarehouseEmployee->setWindowTitle(QApplication::translate("CreateWarehouseEmployee", "Create warehouse-employee relation", 0));
        empPhoneLb->setText(QApplication::translate("CreateWarehouseEmployee", "Phone:", 0));
        empSurnamePh->setText(QString());
        empNameLb->setText(QApplication::translate("CreateWarehouseEmployee", "Name:", 0));
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateWarehouseEmployee", "Surname:", 0));
        empPhonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateWarehouseEmployee", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWarehouseEmployee", "Cancel", 0));
        employeeBtn->setText(QApplication::translate("CreateWarehouseEmployee", "Select Employee", 0));
        warehouseLb->setText(QApplication::translate("CreateWarehouseEmployee", "Select warehouse:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWarehouseEmployee: public Ui_CreateWarehouseEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWERDLG_H
