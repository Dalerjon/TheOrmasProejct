/********************************************************************************
** Form generated from reading UI file 'CreateTaxDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETAXDLG_H
#define UI_CREATETAXDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateTax
{
public:
    QGridLayout *gridLayout;
    QLabel *formulaLb;
    QLineEdit *formulaEdit;
    QLabel *codeLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *fixedLb;
    QLabel *percentValue;
    QLineEdit *nameEdit;
    QLineEdit *codeEdit;
    QLineEdit *fixedEdit;
    QLineEdit *percentEdit;

    void setupUi(QDialog *CreateTax)
    {
        if (CreateTax->objectName().isEmpty())
            CreateTax->setObjectName(QStringLiteral("CreateTax"));
        CreateTax->resize(355, 177);
        CreateTax->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateTax->setModal(false);
        gridLayout = new QGridLayout(CreateTax);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        formulaLb = new QLabel(CreateTax);
        formulaLb->setObjectName(QStringLiteral("formulaLb"));

        gridLayout->addWidget(formulaLb, 4, 1, 1, 1);

        formulaEdit = new QLineEdit(CreateTax);
        formulaEdit->setObjectName(QStringLiteral("formulaEdit"));

        gridLayout->addWidget(formulaEdit, 4, 2, 1, 1);

        codeLb = new QLabel(CreateTax);
        codeLb->setObjectName(QStringLiteral("codeLb"));

        gridLayout->addWidget(codeLb, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateTax);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateTax);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 9, 1, 1, 3);

        nameLb = new QLabel(CreateTax);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 1, 1, 1);

        fixedLb = new QLabel(CreateTax);
        fixedLb->setObjectName(QStringLiteral("fixedLb"));

        gridLayout->addWidget(fixedLb, 2, 1, 1, 1);

        percentValue = new QLabel(CreateTax);
        percentValue->setObjectName(QStringLiteral("percentValue"));

        gridLayout->addWidget(percentValue, 3, 1, 1, 1);

        nameEdit = new QLineEdit(CreateTax);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 2, 1, 1);

        codeEdit = new QLineEdit(CreateTax);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        gridLayout->addWidget(codeEdit, 1, 2, 1, 1);

        fixedEdit = new QLineEdit(CreateTax);
        fixedEdit->setObjectName(QStringLiteral("fixedEdit"));

        gridLayout->addWidget(fixedEdit, 2, 2, 1, 1);

        percentEdit = new QLineEdit(CreateTax);
        percentEdit->setObjectName(QStringLiteral("percentEdit"));

        gridLayout->addWidget(percentEdit, 3, 2, 1, 1);

        QWidget::setTabOrder(formulaEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateTax);

        QMetaObject::connectSlotsByName(CreateTax);
    } // setupUi

    void retranslateUi(QDialog *CreateTax)
    {
        CreateTax->setWindowTitle(QApplication::translate("CreateTax", "Create/Update tax", 0));
        formulaLb->setText(QApplication::translate("CreateTax", "Formula value:", 0));
#ifndef QT_NO_TOOLTIP
        formulaEdit->setToolTip(QApplication::translate("CreateTax", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        codeLb->setText(QApplication::translate("CreateTax", "Code:", 0));
        okBtn->setText(QApplication::translate("CreateTax", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateTax", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateTax", "Name:", 0));
        fixedLb->setText(QApplication::translate("CreateTax", "Fixed value:", 0));
        percentValue->setText(QApplication::translate("CreateTax", "Percent value:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateTax: public Ui_CreateTax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETAXDLG_H
