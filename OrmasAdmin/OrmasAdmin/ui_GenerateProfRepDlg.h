/********************************************************************************
** Form generated from reading UI file 'GenerateProfRepDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEPROFREPDLG_H
#define UI_GENERATEPROFREPDLG_H

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

class Ui_GenerateProfitabilityReport
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

    void setupUi(QDialog *GenerateProfitabilityReport)
    {
        if (GenerateProfitabilityReport->objectName().isEmpty())
            GenerateProfitabilityReport->setObjectName(QStringLiteral("GenerateProfitabilityReport"));
        GenerateProfitabilityReport->resize(501, 73);
        GenerateProfitabilityReport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateProfitabilityReport->setModal(false);
        gridLayout = new QGridLayout(GenerateProfitabilityReport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillDateEdit = new QDateEdit(GenerateProfitabilityReport);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateProfitabilityReport);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateProfitabilityReport);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 4);

        label_2 = new QLabel(GenerateProfitabilityReport);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        fromDateEdit = new QDateEdit(GenerateProfitabilityReport);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(GenerateProfitabilityReport);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(GenerateProfitabilityReport);

        QMetaObject::connectSlotsByName(GenerateProfitabilityReport);
    } // setupUi

    void retranslateUi(QDialog *GenerateProfitabilityReport)
    {
        GenerateProfitabilityReport->setWindowTitle(QApplication::translate("GenerateProfitabilityReport", "Generate profitability report", 0));
        okBtn->setText(QApplication::translate("GenerateProfitabilityReport", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateProfitabilityReport", "Cancel", 0));
        label_2->setText(QApplication::translate("GenerateProfitabilityReport", "Till date:", 0));
        fromLb->setText(QApplication::translate("GenerateProfitabilityReport", "From date:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateProfitabilityReport: public Ui_GenerateProfitabilityReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEPROFREPDLG_H
