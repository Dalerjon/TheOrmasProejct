/********************************************************************************
** Form generated from reading UI file 'CreateRcpOthStListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERCPOTHSTLISTDLG_H
#define UI_CREATERCPOTHSTLISTDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "searchbox.h"

QT_BEGIN_NAMESPACE

class Ui_CreateRcpOthStList
{
public:
    QGridLayout *gridLayout;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *receiptOthStEdit;
    QComboBox *currencyCmb;
    QPushButton *receiptOthStBtn;
    QLabel *currencyLb;
    QLabel *measureLb;
    QLineEdit *productEdit;
    QLabel *volumeLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLabel *label_3;
    QLabel *newPriceLb;
    QLabel *prodNameLb;
    QLabel *countLb;
    QPushButton *otherStocksBtn;
    QLabel *label;
    QLabel *oldPriceLb;
    QLineEdit *sumEdit;
    QLabel *sumLb;
    QLabel *measurePh;
    QLineEdit *countEdit;
    QLabel *othStNamePh;
    QLabel *volumePh;
    SearchBox *searchEdit;

    void setupUi(QDialog *CreateRcpOthStList)
    {
        if (CreateRcpOthStList->objectName().isEmpty())
            CreateRcpOthStList->setObjectName(QStringLiteral("CreateRcpOthStList"));
        CreateRcpOthStList->resize(671, 380);
        CreateRcpOthStList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRcpOthStList->setModal(false);
        gridLayout = new QGridLayout(CreateRcpOthStList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        editSectionWgt = new QWidget(CreateRcpOthStList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        statusWidget = new QWidget(editSectionWgt);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBtn = new QPushButton(statusWidget);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy);
        statusBtn->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(statusBtn);

        statusEdit = new QLineEdit(statusWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setMaximumSize(QSize(150, 16777215));
        statusEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(statusEdit);

        statusLb = new QLabel(statusWidget);
        statusLb->setObjectName(QStringLiteral("statusLb"));

        horizontalLayout_3->addWidget(statusLb);

        statusPh = new QLabel(statusWidget);
        statusPh->setObjectName(QStringLiteral("statusPh"));
        statusPh->setMinimumSize(QSize(120, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout_3->addWidget(statusWidget, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        receiptOthStEdit = new QLineEdit(editSectionWgt);
        receiptOthStEdit->setObjectName(QStringLiteral("receiptOthStEdit"));
        receiptOthStEdit->setMaximumSize(QSize(150, 16777215));
        receiptOthStEdit->setReadOnly(true);

        gridLayout_3->addWidget(receiptOthStEdit, 0, 1, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 2, 1, 1, 1);

        receiptOthStBtn = new QPushButton(editSectionWgt);
        receiptOthStBtn->setObjectName(QStringLiteral("receiptOthStBtn"));
        receiptOthStBtn->setMinimumSize(QSize(150, 0));
        receiptOthStBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(receiptOthStBtn, 0, 0, 1, 1);

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 2, 0, 1, 1);


        gridLayout->addWidget(editSectionWgt, 7, 0, 1, 6);

        measureLb = new QLabel(CreateRcpOthStList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 2, 4, 1, 1);

        productEdit = new QLineEdit(CreateRcpOthStList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 1, 3, 1, 1);

        volumeLb = new QLabel(CreateRcpOthStList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateRcpOthStList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateRcpOthStList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 6);

        label_3 = new QLabel(CreateRcpOthStList);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        newPriceLb = new QLabel(CreateRcpOthStList);
        newPriceLb->setObjectName(QStringLiteral("newPriceLb"));
        QFont font1;
        font1.setFamily(QStringLiteral("Tahoma"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        newPriceLb->setFont(font1);

        gridLayout->addWidget(newPriceLb, 6, 1, 1, 1);

        prodNameLb = new QLabel(CreateRcpOthStList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 2, 0, 1, 1);

        countLb = new QLabel(CreateRcpOthStList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 4, 0, 1, 2);

        otherStocksBtn = new QPushButton(CreateRcpOthStList);
        otherStocksBtn->setObjectName(QStringLiteral("otherStocksBtn"));

        gridLayout->addWidget(otherStocksBtn, 1, 0, 1, 2);

        label = new QLabel(CreateRcpOthStList);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        oldPriceLb = new QLabel(CreateRcpOthStList);
        oldPriceLb->setObjectName(QStringLiteral("oldPriceLb"));
        oldPriceLb->setFont(font1);

        gridLayout->addWidget(oldPriceLb, 3, 1, 1, 1);

        sumEdit = new QLineEdit(CreateRcpOthStList);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout->addWidget(sumEdit, 5, 3, 1, 1);

        sumLb = new QLabel(CreateRcpOthStList);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 5, 0, 1, 2);

        measurePh = new QLabel(CreateRcpOthStList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 2, 5, 1, 1);

        countEdit = new QLineEdit(CreateRcpOthStList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 4, 3, 1, 1);

        othStNamePh = new QLabel(CreateRcpOthStList);
        othStNamePh->setObjectName(QStringLiteral("othStNamePh"));
        othStNamePh->setMinimumSize(QSize(100, 0));
        othStNamePh->setFont(font);

        gridLayout->addWidget(othStNamePh, 2, 1, 1, 1);

        volumePh = new QLabel(CreateRcpOthStList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 2, 3, 1, 1);

        searchEdit = new SearchBox(CreateRcpOthStList);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        gridLayout->addWidget(searchEdit, 0, 0, 1, 6);

        QWidget::setTabOrder(otherStocksBtn, countEdit);
        QWidget::setTabOrder(countEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, receiptOthStBtn);
        QWidget::setTabOrder(receiptOthStBtn, statusBtn);
        QWidget::setTabOrder(statusBtn, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, productEdit);
        QWidget::setTabOrder(productEdit, receiptOthStEdit);
        QWidget::setTabOrder(receiptOthStEdit, statusEdit);
        QWidget::setTabOrder(statusEdit, currencyCmb);

        retranslateUi(CreateRcpOthStList);

        QMetaObject::connectSlotsByName(CreateRcpOthStList);
    } // setupUi

    void retranslateUi(QDialog *CreateRcpOthStList)
    {
        CreateRcpOthStList->setWindowTitle(QApplication::translate("CreateRcpOthStList", "Create/Update other stocks in receipt list", 0));
        statusBtn->setText(QApplication::translate("CreateRcpOthStList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateRcpOthStList", "Status name:", 0));
        statusPh->setText(QString());
        receiptOthStEdit->setText(QString());
        receiptOthStBtn->setText(QApplication::translate("CreateRcpOthStList", "Select receipt other stocks", 0));
        currencyLb->setText(QApplication::translate("CreateRcpOthStList", "Select currency:", 0));
        measureLb->setText(QApplication::translate("CreateRcpOthStList", "Measure:", 0));
        volumeLb->setText(QApplication::translate("CreateRcpOthStList", "Volume:", 0));
        addBtn->setText(QApplication::translate("CreateRcpOthStList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateRcpOthStList", "Cancel", 0));
        label_3->setText(QApplication::translate("CreateRcpOthStList", "New price:", 0));
        newPriceLb->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateRcpOthStList", "Product name:", 0));
        countLb->setText(QApplication::translate("CreateRcpOthStList", "Count:", 0));
        otherStocksBtn->setText(QApplication::translate("CreateRcpOthStList", "Select other stocks", 0));
        label->setText(QApplication::translate("CreateRcpOthStList", "Previous price:", 0));
        oldPriceLb->setText(QString());
        sumLb->setText(QApplication::translate("CreateRcpOthStList", "Sum:", 0));
        measurePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateRcpOthStList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        othStNamePh->setText(QString());
        volumePh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateRcpOthStList: public Ui_CreateRcpOthStList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERCPOTHSTLISTDLG_H
