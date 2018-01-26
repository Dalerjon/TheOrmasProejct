/********************************************************************************
** Form generated from reading UI file 'CreateStockDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESTOCKDLG_H
#define UI_CREATESTOCKDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateStock
{
public:
    QGridLayout *gridLayout;
    QLabel *countLb;
    QLineEdit *productEdit;
    QPushButton *productBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLineEdit *countEdit;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;
    QLineEdit *sumEdit;
    QLabel *sumLb;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;

    void setupUi(QDialog *CreateStock)
    {
        if (CreateStock->objectName().isEmpty())
            CreateStock->setObjectName(QStringLiteral("CreateStock"));
        CreateStock->resize(396, 192);
        CreateStock->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateStock->setModal(false);
        gridLayout = new QGridLayout(CreateStock);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(CreateStock);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 1, 0, 1, 1);

        productEdit = new QLineEdit(CreateStock);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 1, 1, 1);

        productBtn = new QPushButton(CreateStock);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateStock);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateStock);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        countEdit = new QLineEdit(CreateStock);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 1, 1, 1, 1);

        editSectionWgt = new QWidget(CreateStock);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        currencyBtn = new QPushButton(editSectionWgt);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout_3->addWidget(currencyBtn, 2, 0, 1, 1);

        currencyEdit = new QLineEdit(editSectionWgt);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout_3->addWidget(currencyEdit, 2, 1, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout_3->addWidget(sumEdit, 1, 1, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 1, 0, 1, 1);

        statusBtn = new QPushButton(editSectionWgt);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout_3->addWidget(statusBtn, 0, 0, 1, 1);

        statusEdit = new QLineEdit(editSectionWgt);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout_3->addWidget(statusEdit, 0, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 2, 0, 1, 2);

        QWidget::setTabOrder(productBtn, productEdit);
        QWidget::setTabOrder(productEdit, countEdit);
        QWidget::setTabOrder(countEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateStock);

        QMetaObject::connectSlotsByName(CreateStock);
    } // setupUi

    void retranslateUi(QDialog *CreateStock)
    {
        CreateStock->setWindowTitle(QApplication::translate("CreateStock", "Create/Update product/raw in stock", 0));
        countLb->setText(QApplication::translate("CreateStock", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateStock", "Select product", 0));
        addBtn->setText(QApplication::translate("CreateStock", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateStock", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateStock", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currencyBtn->setText(QApplication::translate("CreateStock", "Select currency", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateStock", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateStock", "Sum:", 0));
        statusBtn->setText(QApplication::translate("CreateStock", "Select status", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateStock: public Ui_CreateStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESTOCKDLG_H
