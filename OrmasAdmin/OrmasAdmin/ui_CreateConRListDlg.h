/********************************************************************************
** Form generated from reading UI file 'CreateConRListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONRLISTDLG_H
#define UI_CREATECONRLISTDLG_H

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

class Ui_CreateConRList
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
    QPushButton *consumeRawBtn;
    QLineEdit *statusEdit;
    QLineEdit *consumeRawEdit;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateConRList)
    {
        if (CreateConRList->objectName().isEmpty())
            CreateConRList->setObjectName(QStringLiteral("CreateConRList"));
        CreateConRList->resize(396, 221);
        CreateConRList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConRList->setModal(false);
        gridLayout = new QGridLayout(CreateConRList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(CreateConRList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 1, 0, 1, 1);

        productEdit = new QLineEdit(CreateConRList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 1, 1, 1);

        productBtn = new QPushButton(CreateConRList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateConRList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateConRList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        countEdit = new QLineEdit(CreateConRList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 1, 1, 1, 1);

        editSectionWgt = new QWidget(CreateConRList);
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

        consumeRawBtn = new QPushButton(editSectionWgt);
        consumeRawBtn->setObjectName(QStringLiteral("consumeRawBtn"));
        consumeRawBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(consumeRawBtn, 0, 0, 1, 1);

        statusEdit = new QLineEdit(editSectionWgt);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout_3->addWidget(statusEdit, 1, 1, 1, 1);

        consumeRawEdit = new QLineEdit(editSectionWgt);
        consumeRawEdit->setObjectName(QStringLiteral("consumeRawEdit"));
        consumeRawEdit->setReadOnly(true);

        gridLayout_3->addWidget(consumeRawEdit, 0, 1, 1, 1);

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
        QWidget::setTabOrder(countEdit, consumeRawBtn);
        QWidget::setTabOrder(consumeRawBtn, consumeRawEdit);
        QWidget::setTabOrder(consumeRawEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateConRList);

        QMetaObject::connectSlotsByName(CreateConRList);
    } // setupUi

    void retranslateUi(QDialog *CreateConRList)
    {
        CreateConRList->setWindowTitle(QApplication::translate("CreateConRList", "Create/Update raw in consume list", 0));
        countLb->setText(QApplication::translate("CreateConRList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateConRList", "Select product", 0));
        addBtn->setText(QApplication::translate("CreateConRList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateConRList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateConRList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateConRList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateConRList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        statusBtn->setText(QApplication::translate("CreateConRList", "Select status", 0));
        consumeRawBtn->setText(QApplication::translate("CreateConRList", "Select consume raw", 0));
        consumeRawEdit->setText(QString());
        currencyBtn->setText(QApplication::translate("CreateConRList", "Select currency", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateConRList: public Ui_CreateConRList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONRLISTDLG_H
