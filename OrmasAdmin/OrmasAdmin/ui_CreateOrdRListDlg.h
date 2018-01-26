/********************************************************************************
** Form generated from reading UI file 'CreateOrdRListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDRLISTDLG_H
#define UI_CREATEORDRLISTDLG_H

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

class Ui_CreateOrdRList
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
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *statusBtn;
    QPushButton *orderRawBtn;
    QLineEdit *statusEdit;
    QLineEdit *orderRawEdit;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateOrdRList)
    {
        if (CreateOrdRList->objectName().isEmpty())
            CreateOrdRList->setObjectName(QStringLiteral("CreateOrdRList"));
        CreateOrdRList->resize(396, 221);
        CreateOrdRList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOrdRList->setModal(false);
        gridLayout = new QGridLayout(CreateOrdRList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(CreateOrdRList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 1, 0, 1, 1);

        productEdit = new QLineEdit(CreateOrdRList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 1, 1, 1);

        productBtn = new QPushButton(CreateOrdRList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateOrdRList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateOrdRList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        countEdit = new QLineEdit(CreateOrdRList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 1, 1, 1, 1);

        editSectionWgt = new QWidget(CreateOrdRList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        statusBtn = new QPushButton(editSectionWgt);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout_3->addWidget(statusBtn, 1, 0, 1, 1);

        orderRawBtn = new QPushButton(editSectionWgt);
        orderRawBtn->setObjectName(QStringLiteral("orderRawBtn"));
        orderRawBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(orderRawBtn, 0, 0, 1, 1);

        statusEdit = new QLineEdit(editSectionWgt);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout_3->addWidget(statusEdit, 1, 1, 1, 1);

        orderRawEdit = new QLineEdit(editSectionWgt);
        orderRawEdit->setObjectName(QStringLiteral("orderRawEdit"));
        orderRawEdit->setReadOnly(true);

        gridLayout_3->addWidget(orderRawEdit, 0, 1, 1, 1);

        currencyBtn = new QPushButton(editSectionWgt);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout_3->addWidget(currencyBtn, 3, 0, 1, 1);

        currencyEdit = new QLineEdit(editSectionWgt);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout_3->addWidget(currencyEdit, 3, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 2, 0, 1, 2);

        QWidget::setTabOrder(productBtn, productEdit);
        QWidget::setTabOrder(productEdit, countEdit);
        QWidget::setTabOrder(countEdit, orderRawBtn);
        QWidget::setTabOrder(orderRawBtn, orderRawEdit);
        QWidget::setTabOrder(orderRawEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateOrdRList);

        QMetaObject::connectSlotsByName(CreateOrdRList);
    } // setupUi

    void retranslateUi(QDialog *CreateOrdRList)
    {
        CreateOrdRList->setWindowTitle(QApplication::translate("CreateOrdRList", "Create/Update raw in order list", 0));
        countLb->setText(QApplication::translate("CreateOrdRList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateOrdRList", "Select product", 0));
        addBtn->setText(QApplication::translate("CreateOrdRList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateOrdRList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateOrdRList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateOrdRList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateOrdRList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        statusBtn->setText(QApplication::translate("CreateOrdRList", "Select status", 0));
        orderRawBtn->setText(QApplication::translate("CreateOrdRList", "Select order raw", 0));
        orderRawEdit->setText(QString());
        currencyBtn->setText(QApplication::translate("CreateOrdRList", "Select currency", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOrdRList: public Ui_CreateOrdRList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDRLISTDLG_H
