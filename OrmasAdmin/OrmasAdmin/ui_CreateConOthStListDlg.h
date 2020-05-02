/********************************************************************************
** Form generated from reading UI file 'CreateConOthStListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONOTHSTLISTDLG_H
#define UI_CREATECONOTHSTLISTDLG_H

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

class Ui_CreateConOthStList
{
public:
    QGridLayout *gridLayout;
    QLabel *volumePh;
    QLabel *othStNameLb;
    QLabel *othStNamePh;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *consumeOthStBtn;
    QLineEdit *consumeOthStEdit;
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
    QLabel *volumeLb;
    QLabel *measureLb;
    QLabel *measurePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QPushButton *otherStocksBtn;
    QLabel *countLb;
    SearchBox *searchEdit;
    QLineEdit *otherStocksEdit;
    QLineEdit *countEdit;

    void setupUi(QDialog *CreateConOthStList)
    {
        if (CreateConOthStList->objectName().isEmpty())
            CreateConOthStList->setObjectName(QStringLiteral("CreateConOthStList"));
        CreateConOthStList->resize(631, 294);
        CreateConOthStList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConOthStList->setModal(false);
        gridLayout = new QGridLayout(CreateConOthStList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        volumePh = new QLabel(CreateConOthStList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 2, 3, 1, 1);

        othStNameLb = new QLabel(CreateConOthStList);
        othStNameLb->setObjectName(QStringLiteral("othStNameLb"));
        othStNameLb->setMinimumSize(QSize(100, 0));
        othStNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(othStNameLb, 2, 0, 1, 1);

        othStNamePh = new QLabel(CreateConOthStList);
        othStNamePh->setObjectName(QStringLiteral("othStNamePh"));
        othStNamePh->setMinimumSize(QSize(130, 0));
        othStNamePh->setFont(font);

        gridLayout->addWidget(othStNamePh, 2, 1, 1, 1);

        editSectionWgt = new QWidget(CreateConOthStList);
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

        consumeOthStBtn = new QPushButton(editSectionWgt);
        consumeOthStBtn->setObjectName(QStringLiteral("consumeOthStBtn"));
        consumeOthStBtn->setMinimumSize(QSize(150, 0));
        consumeOthStBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(consumeOthStBtn, 0, 0, 1, 1);

        consumeOthStEdit = new QLineEdit(editSectionWgt);
        consumeOthStEdit->setObjectName(QStringLiteral("consumeOthStEdit"));
        consumeOthStEdit->setMaximumSize(QSize(150, 16777215));
        consumeOthStEdit->setReadOnly(true);

        gridLayout_3->addWidget(consumeOthStEdit, 0, 1, 1, 1);

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


        gridLayout->addWidget(editSectionWgt, 4, 0, 1, 6);

        volumeLb = new QLabel(CreateConOthStList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 2, 2, 1, 1);

        measureLb = new QLabel(CreateConOthStList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 2, 4, 1, 1);

        measurePh = new QLabel(CreateConOthStList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateConOthStList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateConOthStList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 6);

        otherStocksBtn = new QPushButton(CreateConOthStList);
        otherStocksBtn->setObjectName(QStringLiteral("otherStocksBtn"));

        gridLayout->addWidget(otherStocksBtn, 1, 0, 1, 2);

        countLb = new QLabel(CreateConOthStList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 3, 0, 1, 2);

        searchEdit = new SearchBox(CreateConOthStList);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        gridLayout->addWidget(searchEdit, 0, 0, 1, 6);

        otherStocksEdit = new QLineEdit(CreateConOthStList);
        otherStocksEdit->setObjectName(QStringLiteral("otherStocksEdit"));
        otherStocksEdit->setReadOnly(true);

        gridLayout->addWidget(otherStocksEdit, 1, 2, 1, 1);

        countEdit = new QLineEdit(CreateConOthStList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 3, 2, 1, 1);

        QWidget::setTabOrder(otherStocksBtn, consumeOthStBtn);
        QWidget::setTabOrder(consumeOthStBtn, statusBtn);
        QWidget::setTabOrder(statusBtn, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, consumeOthStEdit);
        QWidget::setTabOrder(consumeOthStEdit, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyCmb);

        retranslateUi(CreateConOthStList);

        QMetaObject::connectSlotsByName(CreateConOthStList);
    } // setupUi

    void retranslateUi(QDialog *CreateConOthStList)
    {
        CreateConOthStList->setWindowTitle(QApplication::translate("CreateConOthStList", "Create/Update other stocks in consume list", 0));
        volumePh->setText(QString());
        othStNameLb->setText(QApplication::translate("CreateConOthStList", "Other stocks name:", 0));
        othStNamePh->setText(QString());
        sumLb->setText(QApplication::translate("CreateConOthStList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateConOthStList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        consumeOthStBtn->setText(QApplication::translate("CreateConOthStList", "Select consume other stocks", 0));
        consumeOthStEdit->setText(QString());
        currencyLb->setText(QApplication::translate("CreateConOthStList", "Select currency:", 0));
        statusBtn->setText(QApplication::translate("CreateConOthStList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateConOthStList", "Status name:", 0));
        statusPh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateConOthStList", "Volume:", 0));
        measureLb->setText(QApplication::translate("CreateConOthStList", "Measure:", 0));
        measurePh->setText(QString());
        addBtn->setText(QApplication::translate("CreateConOthStList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateConOthStList", "Cancel", 0));
        otherStocksBtn->setText(QApplication::translate("CreateConOthStList", "Select product", 0));
        countLb->setText(QApplication::translate("CreateConOthStList", "Count:", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateConOthStList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateConOthStList: public Ui_CreateConOthStList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONOTHSTLISTDLG_H
