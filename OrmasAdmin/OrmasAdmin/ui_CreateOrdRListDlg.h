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

class Ui_CreateOrdRList
{
public:
    QGridLayout *gridLayout;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLineEdit *sumEdit;
    QLabel *sumLb;
    QLineEdit *orderRawEdit;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *orderRawBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *currencyCmb;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *currencyLb;
    QLineEdit *productEdit;
    QLabel *countLb;
    QPushButton *productBtn;
    QLineEdit *countEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLabel *measurePh;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *volumeLb;
    QLabel *prodNamePh;
    QLabel *prodNameLb;

    void setupUi(QDialog *CreateOrdRList)
    {
        if (CreateOrdRList->objectName().isEmpty())
            CreateOrdRList->setObjectName(QStringLiteral("CreateOrdRList"));
        CreateOrdRList->resize(634, 244);
        CreateOrdRList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOrdRList->setModal(false);
        gridLayout = new QGridLayout(CreateOrdRList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        editSectionWgt = new QWidget(CreateOrdRList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        orderRawEdit = new QLineEdit(editSectionWgt);
        orderRawEdit->setObjectName(QStringLiteral("orderRawEdit"));
        orderRawEdit->setMaximumSize(QSize(150, 16777215));
        orderRawEdit->setReadOnly(true);

        gridLayout_3->addWidget(orderRawEdit, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        orderRawBtn = new QPushButton(editSectionWgt);
        orderRawBtn->setObjectName(QStringLiteral("orderRawBtn"));
        orderRawBtn->setMinimumSize(QSize(0, 0));
        orderRawBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(orderRawBtn, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 3, 1, 1, 1);

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

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 3, 0, 1, 1);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        productEdit = new QLineEdit(CreateOrdRList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countLb = new QLabel(CreateOrdRList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        productBtn = new QPushButton(CreateOrdRList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        countEdit = new QLineEdit(CreateOrdRList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        measurePh = new QLabel(CreateOrdRList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        volumePh = new QLabel(CreateOrdRList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        measureLb = new QLabel(CreateOrdRList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        volumeLb = new QLabel(CreateOrdRList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        prodNamePh = new QLabel(CreateOrdRList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        prodNameLb = new QLabel(CreateOrdRList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        QWidget::setTabOrder(productBtn, orderRawBtn);
        QWidget::setTabOrder(orderRawBtn, orderRawEdit);
        QWidget::setTabOrder(orderRawEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateOrdRList);

        QMetaObject::connectSlotsByName(CreateOrdRList);
    } // setupUi

    void retranslateUi(QDialog *CreateOrdRList)
    {
        CreateOrdRList->setWindowTitle(QApplication::translate("CreateOrdRList", "Create/Update raw in order list", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateOrdRList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateOrdRList", "Sum:", 0));
        orderRawEdit->setText(QString());
        orderRawBtn->setText(QApplication::translate("CreateOrdRList", "Select order raw", 0));
        statusBtn->setText(QApplication::translate("CreateOrdRList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateOrdRList", "Status name:", 0));
        statusPh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateOrdRList", "Select currency:", 0));
        countLb->setText(QApplication::translate("CreateOrdRList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateOrdRList", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateOrdRList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addBtn->setText(QApplication::translate("CreateOrdRList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateOrdRList", "Cancel", 0));
        measurePh->setText(QString());
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateOrdRList", "Measure:", 0));
        volumeLb->setText(QApplication::translate("CreateOrdRList", "Volume:", 0));
        prodNamePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateOrdRList", "Product name:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOrdRList: public Ui_CreateOrdRList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDRLISTDLG_H
