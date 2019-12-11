/********************************************************************************
** Form generated from reading UI file 'GenerateSalesRepDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATESALESREPDLG_H
#define UI_GENERATESALESREPDLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GenerateSalesReport
{
public:
    QGridLayout *gridLayout;
    QDateEdit *tillDateEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *fromLb;
    QDateEdit *fromDateEdit;
    QCheckBox *allSalesChb;

    void setupUi(QDialog *GenerateSalesReport)
    {
        if (GenerateSalesReport->objectName().isEmpty())
            GenerateSalesReport->setObjectName(QStringLiteral("GenerateSalesReport"));
        GenerateSalesReport->resize(501, 98);
        GenerateSalesReport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateSalesReport->setModal(false);
        gridLayout = new QGridLayout(GenerateSalesReport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillDateEdit = new QDateEdit(GenerateSalesReport);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        label_2 = new QLabel(GenerateSalesReport);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateSalesReport);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateSalesReport);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 4);

        fromLb = new QLabel(GenerateSalesReport);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        fromDateEdit = new QDateEdit(GenerateSalesReport);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        allSalesChb = new QCheckBox(GenerateSalesReport);
        allSalesChb->setObjectName(QStringLiteral("allSalesChb"));

        gridLayout->addWidget(allSalesChb, 1, 1, 1, 4);

        QWidget::setTabOrder(fromDateEdit, tillDateEdit);
        QWidget::setTabOrder(tillDateEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(GenerateSalesReport);

        QMetaObject::connectSlotsByName(GenerateSalesReport);
    } // setupUi

    void retranslateUi(QDialog *GenerateSalesReport)
    {
        GenerateSalesReport->setWindowTitle(QApplication::translate("GenerateSalesReport", "Generate sales report", 0));
        label_2->setText(QApplication::translate("GenerateSalesReport", "Till date:", 0));
        okBtn->setText(QApplication::translate("GenerateSalesReport", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateSalesReport", "Cancel", 0));
        fromLb->setText(QApplication::translate("GenerateSalesReport", "From date:", 0));
        allSalesChb->setText(QApplication::translate("GenerateSalesReport", "All sales report", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateSalesReport: public Ui_GenerateSalesReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATESALESREPDLG_H
