/********************************************************************************
** Form generated from reading UI file 'CreatePPlanListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPPLANLISTDLG_H
#define UI_CREATEPPLANLISTDLG_H

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

class Ui_CreatePPlanList
{
public:
    QGridLayout *gridLayout;
    QLabel *countLb;
    QLineEdit *productEdit;
    QLineEdit *countEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QPushButton *productBtn;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *currencyLb;
    QLineEdit *productionPlanEdit;
    QPushButton *productionPlanBtn;
    QLineEdit *sumEdit;
    QLabel *sumLb;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *currencyCmb;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *measurePh;
    QLabel *measureLb;
    QLabel *volumePh;
    QLabel *volumeLb;
    QLabel *prodNamePh;
    QLabel *prodNameLb;

    void setupUi(QDialog *CreatePPlanList)
    {
        if (CreatePPlanList->objectName().isEmpty())
            CreatePPlanList->setObjectName(QStringLiteral("CreatePPlanList"));
        CreatePPlanList->resize(633, 244);
        CreatePPlanList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePPlanList->setModal(false);
        gridLayout = new QGridLayout(CreatePPlanList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(CreatePPlanList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        productEdit = new QLineEdit(CreatePPlanList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countEdit = new QLineEdit(CreatePPlanList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreatePPlanList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreatePPlanList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        productBtn = new QPushButton(CreatePPlanList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        editSectionWgt = new QWidget(CreatePPlanList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 3, 0, 1, 1);

        productionPlanEdit = new QLineEdit(editSectionWgt);
        productionPlanEdit->setObjectName(QStringLiteral("productionPlanEdit"));
        productionPlanEdit->setMaximumSize(QSize(150, 16777215));
        productionPlanEdit->setReadOnly(true);

        gridLayout_3->addWidget(productionPlanEdit, 0, 1, 1, 1);

        productionPlanBtn = new QPushButton(editSectionWgt);
        productionPlanBtn->setObjectName(QStringLiteral("productionPlanBtn"));
        productionPlanBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(productionPlanBtn, 0, 0, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 2, 1, 1);

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


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        measurePh = new QLabel(CreatePPlanList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        measureLb = new QLabel(CreatePPlanList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        volumePh = new QLabel(CreatePPlanList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        volumeLb = new QLabel(CreatePPlanList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        prodNamePh = new QLabel(CreatePPlanList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        prodNameLb = new QLabel(CreatePPlanList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        QWidget::setTabOrder(productBtn, productionPlanBtn);
        QWidget::setTabOrder(productionPlanBtn, productionPlanEdit);
        QWidget::setTabOrder(productionPlanEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreatePPlanList);

        QMetaObject::connectSlotsByName(CreatePPlanList);
    } // setupUi

    void retranslateUi(QDialog *CreatePPlanList)
    {
        CreatePPlanList->setWindowTitle(QApplication::translate("CreatePPlanList", "Create/Update product in production plan list", 0));
        countLb->setText(QApplication::translate("CreatePPlanList", "Count:", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreatePPlanList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addBtn->setText(QApplication::translate("CreatePPlanList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreatePPlanList", "Cancel", 0));
        productBtn->setText(QApplication::translate("CreatePPlanList", "Select product", 0));
        currencyLb->setText(QApplication::translate("CreatePPlanList", "Select currency:", 0));
        productionPlanEdit->setText(QString());
        productionPlanBtn->setText(QApplication::translate("CreatePPlanList", "Select production plan", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreatePPlanList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreatePPlanList", "Sum:", 0));
        statusBtn->setText(QApplication::translate("CreatePPlanList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreatePPlanList", "Status name:", 0));
        statusPh->setText(QString());
        measurePh->setText(QString());
        measureLb->setText(QApplication::translate("CreatePPlanList", "Measure:", 0));
        volumePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreatePPlanList", "Volume:", 0));
        prodNamePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreatePPlanList", "Product name:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePPlanList: public Ui_CreatePPlanList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPPLANLISTDLG_H
