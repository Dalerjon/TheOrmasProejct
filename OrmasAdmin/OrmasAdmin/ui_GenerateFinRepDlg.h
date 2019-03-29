/********************************************************************************
** Form generated from reading UI file 'GenerateFinRepDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEFINREPDLG_H
#define UI_GENERATEFINREPDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GenerateFinancialReport
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

    void setupUi(QDialog *GenerateFinancialReport)
    {
        if (GenerateFinancialReport->objectName().isEmpty())
            GenerateFinancialReport->setObjectName(QStringLiteral("GenerateFinancialReport"));
        GenerateFinancialReport->resize(501, 73);
        GenerateFinancialReport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateFinancialReport->setModal(false);
        gridLayout = new QGridLayout(GenerateFinancialReport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillDateEdit = new QDateEdit(GenerateFinancialReport);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateFinancialReport);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateFinancialReport);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 4);

        label_2 = new QLabel(GenerateFinancialReport);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        fromDateEdit = new QDateEdit(GenerateFinancialReport);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(GenerateFinancialReport);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        QWidget::setTabOrder(fromDateEdit, tillDateEdit);
        QWidget::setTabOrder(tillDateEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(GenerateFinancialReport);

        QMetaObject::connectSlotsByName(GenerateFinancialReport);
    } // setupUi

    void retranslateUi(QDialog *GenerateFinancialReport)
    {
        GenerateFinancialReport->setWindowTitle(QApplication::translate("GenerateFinancialReport", "Generate financial report", 0));
        okBtn->setText(QApplication::translate("GenerateFinancialReport", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateFinancialReport", "Cancel", 0));
        label_2->setText(QApplication::translate("GenerateFinancialReport", "Till date:", 0));
        fromLb->setText(QApplication::translate("GenerateFinancialReport", "From date:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateFinancialReport: public Ui_GenerateFinancialReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEFINREPDLG_H
