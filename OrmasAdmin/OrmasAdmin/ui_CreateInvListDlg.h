/********************************************************************************
** Form generated from reading UI file 'CreateInvListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEINVLISTDLG_H
#define UI_CREATEINVLISTDLG_H

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

class Ui_CreateInvList
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLabel *countLb;
    QPushButton *productBtn;
    QLineEdit *countEdit;
    QLineEdit *productEdit;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLineEdit *inventorizationEdit;
    QLabel *sumLb;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *sumEdit;
    QPushButton *inventorizationBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QComboBox *currencyCmb;
    QLabel *currencyLb;
    QLabel *measurePh;
    QLabel *measureLb;
    QLabel *volumePh;
    QLabel *volumeLb;
    QLabel *prodNamePh;
    QLabel *prodNameLb;

    void setupUi(QDialog *CreateInvList)
    {
        if (CreateInvList->objectName().isEmpty())
            CreateInvList->setObjectName(QStringLiteral("CreateInvList"));
        CreateInvList->resize(633, 244);
        CreateInvList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateInvList->setModal(false);
        gridLayout = new QGridLayout(CreateInvList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateInvList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateInvList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        countLb = new QLabel(CreateInvList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        productBtn = new QPushButton(CreateInvList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        countEdit = new QLineEdit(CreateInvList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        productEdit = new QLineEdit(CreateInvList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        editSectionWgt = new QWidget(CreateInvList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        inventorizationEdit = new QLineEdit(editSectionWgt);
        inventorizationEdit->setObjectName(QStringLiteral("inventorizationEdit"));
        inventorizationEdit->setMaximumSize(QSize(150, 16777215));
        inventorizationEdit->setReadOnly(true);

        gridLayout_3->addWidget(inventorizationEdit, 0, 1, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        inventorizationBtn = new QPushButton(editSectionWgt);
        inventorizationBtn->setObjectName(QStringLiteral("inventorizationBtn"));
        inventorizationBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(inventorizationBtn, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 2, 1, 1);

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
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout_3->addWidget(statusWidget, 1, 0, 1, 3);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 3, 1, 1, 1);

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 3, 0, 1, 1);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        measurePh = new QLabel(CreateInvList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        measureLb = new QLabel(CreateInvList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        volumePh = new QLabel(CreateInvList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        volumeLb = new QLabel(CreateInvList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        prodNamePh = new QLabel(CreateInvList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        prodNameLb = new QLabel(CreateInvList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        QWidget::setTabOrder(productBtn, inventorizationBtn);
        QWidget::setTabOrder(inventorizationBtn, inventorizationEdit);
        QWidget::setTabOrder(inventorizationEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateInvList);

        QMetaObject::connectSlotsByName(CreateInvList);
    } // setupUi

    void retranslateUi(QDialog *CreateInvList)
    {
        CreateInvList->setWindowTitle(QApplication::translate("CreateInvList", "Create/Update product in inventorization list", 0));
        addBtn->setText(QApplication::translate("CreateInvList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateInvList", "Cancel", 0));
        countLb->setText(QApplication::translate("CreateInvList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateInvList", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateInvList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        inventorizationEdit->setText(QString());
        sumLb->setText(QApplication::translate("CreateInvList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateInvList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        inventorizationBtn->setText(QApplication::translate("CreateInvList", "Select inventorization", 0));
        statusBtn->setText(QApplication::translate("CreateInvList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateInvList", "Status name:", 0));
        statusPh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateInvList", "Select currency:", 0));
        measurePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateInvList", "Measure:", 0));
        volumePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateInvList", "Volume:", 0));
        prodNamePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateInvList", "Product name:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateInvList: public Ui_CreateInvList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEINVLISTDLG_H
