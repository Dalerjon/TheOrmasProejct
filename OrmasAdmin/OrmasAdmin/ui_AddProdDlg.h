/********************************************************************************
** Form generated from reading UI file 'AddProdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODDLG_H
#define UI_ADDPRODDLG_H

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

class Ui_AddProdDlg
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
    QLineEdit *productionEdit;
    QPushButton *productionBtn;
    QPushButton *statusBtn;
    QLineEdit *orderEdit;
    QLineEdit *returnEdit;
    QPushButton *orderBtn;
    QLineEdit *statusEdit;
    QPushButton *returnBtn;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *AddProdDlg)
    {
        if (AddProdDlg->objectName().isEmpty())
            AddProdDlg->setObjectName(QStringLiteral("AddProdDlg"));
        AddProdDlg->resize(396, 279);
        AddProdDlg->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        AddProdDlg->setModal(false);
        gridLayout = new QGridLayout(AddProdDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(AddProdDlg);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 1, 0, 1, 1);

        productEdit = new QLineEdit(AddProdDlg);
        productEdit->setObjectName(QStringLiteral("productEdit"));

        gridLayout->addWidget(productEdit, 0, 1, 1, 1);

        productBtn = new QPushButton(AddProdDlg);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(AddProdDlg);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(AddProdDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        countEdit = new QLineEdit(AddProdDlg);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 1, 1, 1, 1);

        editSectionWgt = new QWidget(AddProdDlg);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        productionEdit = new QLineEdit(editSectionWgt);
        productionEdit->setObjectName(QStringLiteral("productionEdit"));

        gridLayout_3->addWidget(productionEdit, 2, 1, 1, 1);

        productionBtn = new QPushButton(editSectionWgt);
        productionBtn->setObjectName(QStringLiteral("productionBtn"));

        gridLayout_3->addWidget(productionBtn, 2, 0, 1, 1);

        statusBtn = new QPushButton(editSectionWgt);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout_3->addWidget(statusBtn, 3, 0, 1, 1);

        orderEdit = new QLineEdit(editSectionWgt);
        orderEdit->setObjectName(QStringLiteral("orderEdit"));

        gridLayout_3->addWidget(orderEdit, 0, 1, 1, 1);

        returnEdit = new QLineEdit(editSectionWgt);
        returnEdit->setObjectName(QStringLiteral("returnEdit"));

        gridLayout_3->addWidget(returnEdit, 1, 1, 1, 1);

        orderBtn = new QPushButton(editSectionWgt);
        orderBtn->setObjectName(QStringLiteral("orderBtn"));

        gridLayout_3->addWidget(orderBtn, 0, 0, 1, 1);

        statusEdit = new QLineEdit(editSectionWgt);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        gridLayout_3->addWidget(statusEdit, 3, 1, 1, 1);

        returnBtn = new QPushButton(editSectionWgt);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));

        gridLayout_3->addWidget(returnBtn, 1, 0, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 4, 0, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout_3->addWidget(sumEdit, 4, 1, 1, 1);

        currencyBtn = new QPushButton(editSectionWgt);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout_3->addWidget(currencyBtn, 5, 0, 1, 1);

        currencyEdit = new QLineEdit(editSectionWgt);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));

        gridLayout_3->addWidget(currencyEdit, 5, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 2, 0, 1, 2);

        QWidget::setTabOrder(productBtn, productEdit);
        QWidget::setTabOrder(productEdit, countEdit);
        QWidget::setTabOrder(countEdit, orderBtn);
        QWidget::setTabOrder(orderBtn, orderEdit);
        QWidget::setTabOrder(orderEdit, returnBtn);
        QWidget::setTabOrder(returnBtn, returnEdit);
        QWidget::setTabOrder(returnEdit, productionBtn);
        QWidget::setTabOrder(productionBtn, productionEdit);
        QWidget::setTabOrder(productionEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(AddProdDlg);

        QMetaObject::connectSlotsByName(AddProdDlg);
    } // setupUi

    void retranslateUi(QDialog *AddProdDlg)
    {
        AddProdDlg->setWindowTitle(QApplication::translate("AddProdDlg", "Create/Update product in list", 0));
        countLb->setText(QApplication::translate("AddProdDlg", "Count:", 0));
        productBtn->setText(QApplication::translate("AddProdDlg", "Select product", 0));
        addBtn->setText(QApplication::translate("AddProdDlg", "Add", 0));
        cancelBtn->setText(QApplication::translate("AddProdDlg", "Cancel", 0));
        productionEdit->setText(QString());
        productionBtn->setText(QApplication::translate("AddProdDlg", "Select production", 0));
        statusBtn->setText(QApplication::translate("AddProdDlg", "Select status", 0));
        orderEdit->setText(QString());
        returnEdit->setText(QString());
        orderBtn->setText(QApplication::translate("AddProdDlg", "Select order", 0));
        returnBtn->setText(QApplication::translate("AddProdDlg", "Select return", 0));
        sumLb->setText(QApplication::translate("AddProdDlg", "Sum:", 0));
        currencyBtn->setText(QApplication::translate("AddProdDlg", "Select currency", 0));
    } // retranslateUi

};

namespace Ui {
    class AddProdDlg: public Ui_AddProdDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODDLG_H
