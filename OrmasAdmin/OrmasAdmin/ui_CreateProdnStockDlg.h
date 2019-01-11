/********************************************************************************
** Form generated from reading UI file 'CreateProdnStockDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPRODNSTOCKDLG_H
#define UI_CREATEPRODNSTOCKDLG_H

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

class Ui_CreateProdnStock
{
public:
    QGridLayout *gridLayout;
    QLabel *measurePh;
    QLabel *prodNamePh;
    QLabel *prodNameLb;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QLabel *currencyLb;
    QComboBox *currencyCmb;
    QSpacerItem *horizontalSpacer_2;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *productBtn;
    QLabel *measureLb;
    QLabel *countLb;
    QLabel *volumePh;
    QLineEdit *productEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLineEdit *countEdit;
    QLabel *volumeLb;
    QLabel *warehouseLb;
    QComboBox *warehouseCmb;

    void setupUi(QDialog *CreateProdnStock)
    {
        if (CreateProdnStock->objectName().isEmpty())
            CreateProdnStock->setObjectName(QStringLiteral("CreateProdnStock"));
        CreateProdnStock->resize(636, 241);
        CreateProdnStock->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateProdnStock->setModal(false);
        gridLayout = new QGridLayout(CreateProdnStock);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        measurePh = new QLabel(CreateProdnStock);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        prodNamePh = new QLabel(CreateProdnStock);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        prodNameLb = new QLabel(CreateProdnStock);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        editSectionWgt = new QWidget(CreateProdnStock);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 1, 0, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 1, 1, 1, 1);

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 4, 0, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

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


        gridLayout_3->addWidget(statusWidget, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 4, 2, 1, 1);


        gridLayout->addWidget(editSectionWgt, 5, 0, 1, 6);

        productBtn = new QPushButton(CreateProdnStock);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        measureLb = new QLabel(CreateProdnStock);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        countLb = new QLabel(CreateProdnStock);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        volumePh = new QLabel(CreateProdnStock);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        productEdit = new QLineEdit(CreateProdnStock);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateProdnStock);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateProdnStock);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 6);

        countEdit = new QLineEdit(CreateProdnStock);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        volumeLb = new QLabel(CreateProdnStock);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        warehouseLb = new QLabel(CreateProdnStock);
        warehouseLb->setObjectName(QStringLiteral("warehouseLb"));

        gridLayout->addWidget(warehouseLb, 3, 0, 1, 1);

        warehouseCmb = new QComboBox(CreateProdnStock);
        warehouseCmb->setObjectName(QStringLiteral("warehouseCmb"));

        gridLayout->addWidget(warehouseCmb, 3, 3, 1, 1);

        QWidget::setTabOrder(productBtn, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateProdnStock);

        QMetaObject::connectSlotsByName(CreateProdnStock);
    } // setupUi

    void retranslateUi(QDialog *CreateProdnStock)
    {
        CreateProdnStock->setWindowTitle(QApplication::translate("CreateProdnStock", "Create/Update product in production stock", 0));
        measurePh->setText(QString());
        prodNamePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateProdnStock", "Product name:", 0));
        sumLb->setText(QApplication::translate("CreateProdnStock", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateProdnStock", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currencyLb->setText(QApplication::translate("CreateProdnStock", "Select currency:", 0));
        statusBtn->setText(QApplication::translate("CreateProdnStock", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateProdnStock", "Status name:", 0));
        statusPh->setText(QString());
        productBtn->setText(QApplication::translate("CreateProdnStock", "Select product", 0));
        measureLb->setText(QApplication::translate("CreateProdnStock", "Measure:", 0));
        countLb->setText(QApplication::translate("CreateProdnStock", "Count:", 0));
        volumePh->setText(QString());
        addBtn->setText(QApplication::translate("CreateProdnStock", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateProdnStock", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateProdnStock", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        volumeLb->setText(QApplication::translate("CreateProdnStock", "Volume:", 0));
        warehouseLb->setText(QApplication::translate("CreateProdnStock", "Select warehouse:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateProdnStock: public Ui_CreateProdnStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRODNSTOCKDLG_H
