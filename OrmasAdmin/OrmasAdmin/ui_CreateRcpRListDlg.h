/********************************************************************************
** Form generated from reading UI file 'CreateRcpRListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERCPRLISTDLG_H
#define UI_CREATERCPRLISTDLG_H

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

class Ui_CreateRcpRList
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
    QPushButton *receiptRawBtn;
    QComboBox *currencyCmb;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *receiptRawEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *productBtn;

    void setupUi(QDialog *CreateRcpRList)
    {
        if (CreateRcpRList->objectName().isEmpty())
            CreateRcpRList->setObjectName(QStringLiteral("CreateRcpRList"));
        CreateRcpRList->resize(660, 244);
        CreateRcpRList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRcpRList->setModal(false);
        gridLayout = new QGridLayout(CreateRcpRList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateRcpRList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateRcpRList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        productEdit = new QLineEdit(CreateRcpRList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countEdit = new QLineEdit(CreateRcpRList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        countLb = new QLabel(CreateRcpRList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        volumeLb = new QLabel(CreateRcpRList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        measureLb = new QLabel(CreateRcpRList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        prodNamePh = new QLabel(CreateRcpRList);
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

        volumePh = new QLabel(CreateRcpRList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        prodNameLb = new QLabel(CreateRcpRList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        measurePh = new QLabel(CreateRcpRList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        editSectionWgt = new QWidget(CreateRcpRList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 4, 0, 1, 1);

        receiptRawBtn = new QPushButton(editSectionWgt);
        receiptRawBtn->setObjectName(QStringLiteral("receiptRawBtn"));
        receiptRawBtn->setMinimumSize(QSize(150, 0));
        receiptRawBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(receiptRawBtn, 0, 0, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 4, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        receiptRawEdit = new QLineEdit(editSectionWgt);
        receiptRawEdit->setObjectName(QStringLiteral("receiptRawEdit"));
        receiptRawEdit->setMaximumSize(QSize(150, 16777215));
        receiptRawEdit->setReadOnly(true);

        gridLayout_3->addWidget(receiptRawEdit, 0, 1, 1, 1);

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

        productBtn = new QPushButton(CreateRcpRList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        QWidget::setTabOrder(productBtn, receiptRawBtn);
        QWidget::setTabOrder(receiptRawBtn, receiptRawEdit);
        QWidget::setTabOrder(receiptRawEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateRcpRList);

        QMetaObject::connectSlotsByName(CreateRcpRList);
    } // setupUi

    void retranslateUi(QDialog *CreateRcpRList)
    {
        CreateRcpRList->setWindowTitle(QApplication::translate("CreateRcpRList", "Create/Update raw in receipt list", 0));
        addBtn->setText(QApplication::translate("CreateRcpRList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateRcpRList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateRcpRList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        countLb->setText(QApplication::translate("CreateRcpRList", "Count:", 0));
        volumeLb->setText(QApplication::translate("CreateRcpRList", "Volume:", 0));
        measureLb->setText(QApplication::translate("CreateRcpRList", "Measure:", 0));
        prodNamePh->setText(QString());
        volumePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateRcpRList", "Product name:", 0));
        measurePh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateRcpRList", "Select currency:", 0));
        receiptRawBtn->setText(QApplication::translate("CreateRcpRList", "Select stock transfer", 0));
        receiptRawEdit->setText(QString());
        statusBtn->setText(QApplication::translate("CreateRcpRList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateRcpRList", "Status name:", 0));
        statusPh->setText(QString());
        sumLb->setText(QApplication::translate("CreateRcpRList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateRcpRList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        productBtn->setText(QApplication::translate("CreateRcpRList", "Select product", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateRcpRList: public Ui_CreateRcpRList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERCPRLISTDLG_H
