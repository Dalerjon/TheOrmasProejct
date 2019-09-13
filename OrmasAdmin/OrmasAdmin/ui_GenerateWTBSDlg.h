/********************************************************************************
** Form generated from reading UI file 'GenerateWTBSDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEWTBSDLG_H
#define UI_GENERATEWTBSDLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GenerateWarehouseTurnover
{
public:
    QGridLayout *gridLayout;
    QDateEdit *tillDateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *label_2;
    QDateEdit *fromDateEdit;
    QLabel *fromLb;
    QLabel *warehouseLB;
    QComboBox *warehouseCmb;

    void setupUi(QDialog *GenerateWarehouseTurnover)
    {
        if (GenerateWarehouseTurnover->objectName().isEmpty())
            GenerateWarehouseTurnover->setObjectName(QStringLiteral("GenerateWarehouseTurnover"));
        GenerateWarehouseTurnover->resize(501, 99);
        GenerateWarehouseTurnover->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateWarehouseTurnover->setModal(false);
        gridLayout = new QGridLayout(GenerateWarehouseTurnover);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillDateEdit = new QDateEdit(GenerateWarehouseTurnover);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateWarehouseTurnover);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateWarehouseTurnover);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 4);

        label_2 = new QLabel(GenerateWarehouseTurnover);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        fromDateEdit = new QDateEdit(GenerateWarehouseTurnover);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(GenerateWarehouseTurnover);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        warehouseLB = new QLabel(GenerateWarehouseTurnover);
        warehouseLB->setObjectName(QStringLiteral("warehouseLB"));

        gridLayout->addWidget(warehouseLB, 1, 1, 1, 1);

        warehouseCmb = new QComboBox(GenerateWarehouseTurnover);
        warehouseCmb->setObjectName(QStringLiteral("warehouseCmb"));

        gridLayout->addWidget(warehouseCmb, 1, 2, 1, 3);

        QWidget::setTabOrder(fromDateEdit, tillDateEdit);
        QWidget::setTabOrder(tillDateEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(GenerateWarehouseTurnover);

        QMetaObject::connectSlotsByName(GenerateWarehouseTurnover);
    } // setupUi

    void retranslateUi(QDialog *GenerateWarehouseTurnover)
    {
        GenerateWarehouseTurnover->setWindowTitle(QApplication::translate("GenerateWarehouseTurnover", "Generate warehouse turnover balance sheet", 0));
        okBtn->setText(QApplication::translate("GenerateWarehouseTurnover", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateWarehouseTurnover", "Cancel", 0));
        label_2->setText(QApplication::translate("GenerateWarehouseTurnover", "Till date:", 0));
        fromLb->setText(QApplication::translate("GenerateWarehouseTurnover", "From date:", 0));
        warehouseLB->setText(QApplication::translate("GenerateWarehouseTurnover", "Select warehouse:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateWarehouseTurnover: public Ui_GenerateWarehouseTurnover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEWTBSDLG_H
