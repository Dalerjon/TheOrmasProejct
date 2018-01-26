/********************************************************************************
** Form generated from reading UI file 'CreateConPListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONPLISTDLG_H
#define UI_CREATECONPLISTDLG_H

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

class Ui_CreateConPList
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
    QPushButton *consumeProductBtn;
    QLineEdit *statusEdit;
    QLineEdit *consumeProductEdit;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateConPList)
    {
        if (CreateConPList->objectName().isEmpty())
            CreateConPList->setObjectName(QStringLiteral("CreateConPList"));
        CreateConPList->resize(396, 221);
        CreateConPList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConPList->setModal(false);
        gridLayout = new QGridLayout(CreateConPList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(CreateConPList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 1, 0, 1, 1);

        productEdit = new QLineEdit(CreateConPList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 1, 1, 1);

        productBtn = new QPushButton(CreateConPList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateConPList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateConPList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        countEdit = new QLineEdit(CreateConPList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 1, 1, 1, 1);

        editSectionWgt = new QWidget(CreateConPList);
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

        consumeProductBtn = new QPushButton(editSectionWgt);
        consumeProductBtn->setObjectName(QStringLiteral("consumeProductBtn"));
        consumeProductBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(consumeProductBtn, 0, 0, 1, 1);

        statusEdit = new QLineEdit(editSectionWgt);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout_3->addWidget(statusEdit, 1, 1, 1, 1);

        consumeProductEdit = new QLineEdit(editSectionWgt);
        consumeProductEdit->setObjectName(QStringLiteral("consumeProductEdit"));
        consumeProductEdit->setReadOnly(true);

        gridLayout_3->addWidget(consumeProductEdit, 0, 1, 1, 1);

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
        QWidget::setTabOrder(countEdit, consumeProductBtn);
        QWidget::setTabOrder(consumeProductBtn, consumeProductEdit);
        QWidget::setTabOrder(consumeProductEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateConPList);

        QMetaObject::connectSlotsByName(CreateConPList);
    } // setupUi

    void retranslateUi(QDialog *CreateConPList)
    {
        CreateConPList->setWindowTitle(QApplication::translate("CreateConPList", "Create/Update product in consume list", 0));
        countLb->setText(QApplication::translate("CreateConPList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateConPList", "Select product", 0));
        addBtn->setText(QApplication::translate("CreateConPList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateConPList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateConPList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateConPList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateConPList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        statusBtn->setText(QApplication::translate("CreateConPList", "Select status", 0));
        consumeProductBtn->setText(QApplication::translate("CreateConPList", "Select consume product", 0));
        consumeProductEdit->setText(QString());
        currencyBtn->setText(QApplication::translate("CreateConPList", "Select currency", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateConPList: public Ui_CreateConPList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONPLISTDLG_H
