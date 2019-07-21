/********************************************************************************
** Form generated from reading UI file 'CreateStockTrListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEStockTrLISTDLG_H
#define UI_CREATEStockTrLISTDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_CreateStockTrList
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLineEdit *productEdit;
    QLineEdit *countEdit;
    QLabel *countLb;
    QLabel *volumeLb;
    QLabel *measureLb;
    QLabel *prodNamePh;
    QLabel *volumePh;
    QLabel *prodNameLb;
    QLabel *measurePh;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *currencyLb;
    QPushButton *StockTransferBtn;
    QComboBox *currencyCmb;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *StockTransferEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *productBtn;

    void setupUi(QDialog *CreateStockTrList)
    {
        if (CreateStockTrList->objectName().isEmpty())
            CreateStockTrList->setObjectName(QStringLiteral("CreateStockTrList"));
        CreateStockTrList->resize(660, 244);
        CreateStockTrList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateStockTrList->setModal(false);
        gridLayout = new QGridLayout(CreateStockTrList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateStockTrList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateStockTrList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        productEdit = new QLineEdit(CreateStockTrList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countEdit = new QLineEdit(CreateStockTrList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        countLb = new QLabel(CreateStockTrList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        volumeLb = new QLabel(CreateStockTrList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        measureLb = new QLabel(CreateStockTrList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        prodNamePh = new QLabel(CreateStockTrList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(150, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        volumePh = new QLabel(CreateStockTrList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        prodNameLb = new QLabel(CreateStockTrList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        measurePh = new QLabel(CreateStockTrList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        editSectionWgt = new QWidget(CreateStockTrList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 4, 0, 1, 1);

        StockTransferBtn = new QPushButton(editSectionWgt);
        StockTransferBtn->setObjectName(QStringLiteral("StockTransferBtn"));
        StockTransferBtn->setMinimumSize(QSize(150, 0));
        StockTransferBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(StockTransferBtn, 0, 0, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 4, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        StockTransferEdit = new QLineEdit(editSectionWgt);
        StockTransferEdit->setObjectName(QStringLiteral("StockTransferEdit"));
        StockTransferEdit->setMaximumSize(QSize(150, 16777215));
        StockTransferEdit->setReadOnly(true);

        gridLayout_3->addWidget(StockTransferEdit, 0, 1, 1, 1);

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
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout_3->addWidget(statusWidget, 1, 0, 1, 3);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        productBtn = new QPushButton(CreateStockTrList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        QWidget::setTabOrder(productBtn, countEdit);
        QWidget::setTabOrder(countEdit, StockTransferBtn);
        QWidget::setTabOrder(StockTransferBtn, statusBtn);
        QWidget::setTabOrder(statusBtn, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, productEdit);
        QWidget::setTabOrder(productEdit, StockTransferEdit);
        QWidget::setTabOrder(StockTransferEdit, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyCmb);

        retranslateUi(CreateStockTrList);

        QMetaObject::connectSlotsByName(CreateStockTrList);
    } // setupUi

    void retranslateUi(QDialog *CreateStockTrList)
    {
        CreateStockTrList->setWindowTitle(QApplication::translate("CreateStockTrList", "Create/Update raw in receipt list", 0));
        addBtn->setText(QApplication::translate("CreateStockTrList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateStockTrList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateStockTrList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        countLb->setText(QApplication::translate("CreateStockTrList", "Count:", 0));
        volumeLb->setText(QApplication::translate("CreateStockTrList", "Volume:", 0));
        measureLb->setText(QApplication::translate("CreateStockTrList", "Measure:", 0));
        prodNamePh->setText(QString());
        volumePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateStockTrList", "Product name:", 0));
        measurePh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateStockTrList", "Select currency:", 0));
        StockTransferBtn->setText(QApplication::translate("CreateStockTrList", "Select stock transfer", 0));
        StockTransferEdit->setText(QString());
        statusBtn->setText(QApplication::translate("CreateStockTrList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateStockTrList", "Status name:", 0));
        statusPh->setText(QString());
        sumLb->setText(QApplication::translate("CreateStockTrList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateStockTrList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        productBtn->setText(QApplication::translate("CreateStockTrList", "Select product", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateStockTrList: public Ui_CreateStockTrList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEStockTrLISTDLG_H
