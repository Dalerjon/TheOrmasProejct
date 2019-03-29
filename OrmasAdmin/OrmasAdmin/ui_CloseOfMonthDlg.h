/********************************************************************************
** Form generated from reading UI file 'CloseOfMonthDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSEOFMONTHDLG_H
#define UI_CLOSEOFMONTHDLG_H

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

class Ui_CloseOfMonth
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QDateEdit *tillDateEdit;
    QLabel *label_2;
    QDateEdit *fromDateEdit;
    QLabel *fromLb;
    QLabel *calcTaxLb;
    QCheckBox *taxYesCbx;

    void setupUi(QDialog *CloseOfMonth)
    {
        if (CloseOfMonth->objectName().isEmpty())
            CloseOfMonth->setObjectName(QStringLiteral("CloseOfMonth"));
        CloseOfMonth->resize(501, 96);
        CloseOfMonth->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CloseOfMonth->setModal(false);
        gridLayout = new QGridLayout(CloseOfMonth);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CloseOfMonth);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CloseOfMonth);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 4);

        tillDateEdit = new QDateEdit(CloseOfMonth);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        label_2 = new QLabel(CloseOfMonth);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        fromDateEdit = new QDateEdit(CloseOfMonth);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(CloseOfMonth);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        calcTaxLb = new QLabel(CloseOfMonth);
        calcTaxLb->setObjectName(QStringLiteral("calcTaxLb"));

        gridLayout->addWidget(calcTaxLb, 1, 1, 1, 1);

        taxYesCbx = new QCheckBox(CloseOfMonth);
        taxYesCbx->setObjectName(QStringLiteral("taxYesCbx"));

        gridLayout->addWidget(taxYesCbx, 1, 2, 1, 1);

        QWidget::setTabOrder(fromDateEdit, tillDateEdit);
        QWidget::setTabOrder(tillDateEdit, taxYesCbx);
        QWidget::setTabOrder(taxYesCbx, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CloseOfMonth);

        QMetaObject::connectSlotsByName(CloseOfMonth);
    } // setupUi

    void retranslateUi(QDialog *CloseOfMonth)
    {
        CloseOfMonth->setWindowTitle(QApplication::translate("CloseOfMonth", "Close of month", 0));
        okBtn->setText(QApplication::translate("CloseOfMonth", "OK", 0));
        cancelBtn->setText(QApplication::translate("CloseOfMonth", "Cancel", 0));
        label_2->setText(QApplication::translate("CloseOfMonth", "Till date:", 0));
        fromLb->setText(QApplication::translate("CloseOfMonth", "From date:", 0));
        calcTaxLb->setText(QApplication::translate("CloseOfMonth", "Claculate taxes?", 0));
        taxYesCbx->setText(QApplication::translate("CloseOfMonth", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class CloseOfMonth: public Ui_CloseOfMonth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSEOFMONTHDLG_H
