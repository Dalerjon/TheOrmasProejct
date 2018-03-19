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

class Ui_CreateConRList
{
public:
    QGridLayout *gridLayout;
    QLabel *prodNameLb;
    QLabel *prodNamePh;
    QLabel *volumePh;
    QLabel *volumeLb;
    QLabel *measureLb;
    QLabel *measurePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLineEdit *productEdit;
    QLineEdit *countEdit;
    QPushButton *productBtn;
    QLabel *countLb;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *consumeRawBtn;
    QLineEdit *consumeRawEdit;
    QComboBox *currencyCmb;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *currencyLb;
    QSpacerItem *horizontalSpacer_4;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;

    void setupUi(QDialog *CreateConRList)
    {
        if (CreateConRList->objectName().isEmpty())
            CreateConRList->setObjectName(QStringLiteral("CreateConRList"));
        CreateConRList->resize(631, 244);
        CreateConRList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConRList->setModal(false);
        gridLayout = new QGridLayout(CreateConRList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        prodNameLb = new QLabel(CreateConRList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        prodNamePh = new QLabel(CreateConRList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        volumePh = new QLabel(CreateConRList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        volumeLb = new QLabel(CreateConRList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        measureLb = new QLabel(CreateConRList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        measurePh = new QLabel(CreateConRList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        productEdit = new QLineEdit(CreateConRList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countEdit = new QLineEdit(CreateConRList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        productBtn = new QPushButton(CreateConRList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        countLb = new QLabel(CreateConRList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

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
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        consumeRawBtn = new QPushButton(editSectionWgt);
        consumeRawBtn->setObjectName(QStringLiteral("consumeRawBtn"));
        consumeRawBtn->setMinimumSize(QSize(150, 0));
        consumeRawBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(consumeRawBtn, 0, 0, 1, 1);

        consumeRawEdit = new QLineEdit(editSectionWgt);
        consumeRawEdit->setObjectName(QStringLiteral("consumeRawEdit"));
        consumeRawEdit->setMaximumSize(QSize(150, 16777215));
        consumeRawEdit->setReadOnly(true);

        gridLayout_3->addWidget(consumeRawEdit, 0, 1, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 3, 2, 1, 1);

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


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        QWidget::setTabOrder(productBtn, consumeRawBtn);
        QWidget::setTabOrder(consumeRawBtn, consumeRawEdit);
        QWidget::setTabOrder(consumeRawEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateConRList);

        QMetaObject::connectSlotsByName(CreateConRList);
    } // setupUi

    void retranslateUi(QDialog *CreateConRList)
    {
        CreateConRList->setWindowTitle(QApplication::translate("CreateConRList", "Create/Update raw in consume list", 0));
        prodNameLb->setText(QApplication::translate("CreateConRList", "Product name:", 0));
        prodNamePh->setText(QString());
        volumePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateConRList", "Volume:", 0));
        measureLb->setText(QApplication::translate("CreateConRList", "Measure:", 0));
        measurePh->setText(QString());
        addBtn->setText(QApplication::translate("CreateConRList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateConRList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateConRList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        productBtn->setText(QApplication::translate("CreateConRList", "Select product", 0));
        countLb->setText(QApplication::translate("CreateConRList", "Count:", 0));
        sumLb->setText(QApplication::translate("CreateConRList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateConRList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        consumeRawBtn->setText(QApplication::translate("CreateConRList", "Select consume raw", 0));
        consumeRawEdit->setText(QString());
        currencyLb->setText(QApplication::translate("CreateConRList", "Select currency:", 0));
        statusBtn->setText(QApplication::translate("CreateConRList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateConRList", "Status name:", 0));
        statusPh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateConRList: public Ui_CreateConRList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONRLISTDLG_H
