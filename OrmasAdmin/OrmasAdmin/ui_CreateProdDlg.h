/********************************************************************************
** Form generated from reading UI file 'CreateProdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPRODDLG_H
#define UI_CREATEPRODDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_CreateProduct
{
public:
    QGridLayout *gridLayout;
    QPushButton *companyBtn;
    QLineEdit *companyEdit;
    QLineEdit *shelfLifeEdit;
    QLabel *volumeLb;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *currencyLb;
    QLineEdit *volumeEdit;
    QLabel *shelfLifeLb;
    QLabel *priceLb;
    QComboBox *measureCmb;
    QLabel *companyNameLb;
    QComboBox *currencyCmb;
    QLabel *measureLb;
    QLabel *companyNamePh;
    QLabel *prodTypeLb;
    QComboBox *prodTypeCmb;
    QLabel *nameLb;
    QLineEdit *priceEdit;

    void setupUi(QDialog *CreateProduct)
    {
        if (CreateProduct->objectName().isEmpty())
            CreateProduct->setObjectName(QStringLiteral("CreateProduct"));
        CreateProduct->resize(636, 284);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateProduct->sizePolicy().hasHeightForWidth());
        CreateProduct->setSizePolicy(sizePolicy);
        CreateProduct->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateProduct->setModal(false);
        gridLayout = new QGridLayout(CreateProduct);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        companyBtn = new QPushButton(CreateProduct);
        companyBtn->setObjectName(QStringLiteral("companyBtn"));
        companyBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(companyBtn, 0, 0, 1, 1);

        companyEdit = new QLineEdit(CreateProduct);
        companyEdit->setObjectName(QStringLiteral("companyEdit"));
        companyEdit->setReadOnly(true);

        gridLayout->addWidget(companyEdit, 0, 1, 1, 1);

        shelfLifeEdit = new QLineEdit(CreateProduct);
        shelfLifeEdit->setObjectName(QStringLiteral("shelfLifeEdit"));

        gridLayout->addWidget(shelfLifeEdit, 8, 1, 1, 1);

        volumeLb = new QLabel(CreateProduct);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));

        gridLayout->addWidget(volumeLb, 3, 0, 1, 1);

        nameEdit = new QLineEdit(CreateProduct);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateProduct);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout_2->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateProduct);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout_2->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout_2, 9, 0, 1, 2);

        currencyLb = new QLabel(CreateProduct);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 1);

        volumeEdit = new QLineEdit(CreateProduct);
        volumeEdit->setObjectName(QStringLiteral("volumeEdit"));

        gridLayout->addWidget(volumeEdit, 3, 1, 1, 1);

        shelfLifeLb = new QLabel(CreateProduct);
        shelfLifeLb->setObjectName(QStringLiteral("shelfLifeLb"));

        gridLayout->addWidget(shelfLifeLb, 8, 0, 1, 1);

        priceLb = new QLabel(CreateProduct);
        priceLb->setObjectName(QStringLiteral("priceLb"));

        gridLayout->addWidget(priceLb, 5, 0, 1, 1);

        measureCmb = new QComboBox(CreateProduct);
        measureCmb->setObjectName(QStringLiteral("measureCmb"));
        measureCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(measureCmb, 4, 1, 1, 1);

        companyNameLb = new QLabel(CreateProduct);
        companyNameLb->setObjectName(QStringLiteral("companyNameLb"));

        gridLayout->addWidget(companyNameLb, 1, 0, 1, 1);

        currencyCmb = new QComboBox(CreateProduct);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 6, 1, 1, 1);

        measureLb = new QLabel(CreateProduct);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 4, 0, 1, 1);

        companyNamePh = new QLabel(CreateProduct);
        companyNamePh->setObjectName(QStringLiteral("companyNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        companyNamePh->setFont(font);

        gridLayout->addWidget(companyNamePh, 1, 1, 1, 1);

        prodTypeLb = new QLabel(CreateProduct);
        prodTypeLb->setObjectName(QStringLiteral("prodTypeLb"));

        gridLayout->addWidget(prodTypeLb, 7, 0, 1, 1);

        prodTypeCmb = new QComboBox(CreateProduct);
        prodTypeCmb->setObjectName(QStringLiteral("prodTypeCmb"));
        prodTypeCmb->setMinimumSize(QSize(150, 0));
        prodTypeCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(prodTypeCmb, 7, 1, 1, 1);

        nameLb = new QLabel(CreateProduct);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 2, 0, 1, 1);

        priceEdit = new QLineEdit(CreateProduct);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));

        gridLayout->addWidget(priceEdit, 5, 1, 1, 1);

        QWidget::setTabOrder(companyBtn, companyEdit);
        QWidget::setTabOrder(companyEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, volumeEdit);
        QWidget::setTabOrder(volumeEdit, priceEdit);
        QWidget::setTabOrder(priceEdit, shelfLifeEdit);
        QWidget::setTabOrder(shelfLifeEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateProduct);

        QMetaObject::connectSlotsByName(CreateProduct);
    } // setupUi

    void retranslateUi(QDialog *CreateProduct)
    {
        CreateProduct->setWindowTitle(QApplication::translate("CreateProduct", "Create/Update product", 0));
        companyBtn->setText(QApplication::translate("CreateProduct", "Select company", 0));
#ifndef QT_NO_TOOLTIP
        shelfLifeEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: 4 (in days, in that case 4 days)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        volumeLb->setText(QApplication::translate("CreateProduct", "Volume:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: Milk</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateProduct", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateProduct", "Cancel", 0));
        currencyLb->setText(QApplication::translate("CreateProduct", "Select currency:", 0));
#ifndef QT_NO_TOOLTIP
        volumeEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: 1 (depending on measure, in that case = 1 liter)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        shelfLifeLb->setText(QApplication::translate("CreateProduct", "Shelf life(in days):", 0));
        priceLb->setText(QApplication::translate("CreateProduct", "Price:", 0));
        companyNameLb->setText(QApplication::translate("CreateProduct", "Company name:", 0));
        measureLb->setText(QApplication::translate("CreateProduct", "Select measure:", 0));
        companyNamePh->setText(QString());
        prodTypeLb->setText(QApplication::translate("CreateProduct", "Select product type:", 0));
        nameLb->setText(QApplication::translate("CreateProduct", "Product name:", 0));
#ifndef QT_NO_TOOLTIP
        priceEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: 3.5 (depending on currency, in that case 3.5 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateProduct: public Ui_CreateProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRODDLG_H
