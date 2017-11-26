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
    QLineEdit *measureEdit;
    QPushButton *prodTypeBtn;
    QLabel *priceLb;
    QLineEdit *volumeEdit;
    QLabel *shelfLifeLb;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *companyEdit;
    QLabel *volumeLb;
    QLineEdit *shelfLifeEdit;
    QLineEdit *priceEdit;
    QLabel *nameLb;
    QPushButton *measureBtn;
    QLineEdit *prodTypeEdit;
    QPushButton *companyBtn;
    QLineEdit *nameEdit;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateProduct)
    {
        if (CreateProduct->objectName().isEmpty())
            CreateProduct->setObjectName(QStringLiteral("CreateProduct"));
        CreateProduct->resize(430, 267);
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
        measureEdit = new QLineEdit(CreateProduct);
        measureEdit->setObjectName(QStringLiteral("measureEdit"));
        measureEdit->setReadOnly(true);

        gridLayout->addWidget(measureEdit, 3, 1, 1, 1);

        prodTypeBtn = new QPushButton(CreateProduct);
        prodTypeBtn->setObjectName(QStringLiteral("prodTypeBtn"));

        gridLayout->addWidget(prodTypeBtn, 6, 0, 1, 1);

        priceLb = new QLabel(CreateProduct);
        priceLb->setObjectName(QStringLiteral("priceLb"));

        gridLayout->addWidget(priceLb, 4, 0, 1, 1);

        volumeEdit = new QLineEdit(CreateProduct);
        volumeEdit->setObjectName(QStringLiteral("volumeEdit"));

        gridLayout->addWidget(volumeEdit, 2, 1, 1, 1);

        shelfLifeLb = new QLabel(CreateProduct);
        shelfLifeLb->setObjectName(QStringLiteral("shelfLifeLb"));

        gridLayout->addWidget(shelfLifeLb, 7, 0, 1, 1);

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


        gridLayout->addLayout(horizontalLayout_2, 8, 0, 1, 2);

        companyEdit = new QLineEdit(CreateProduct);
        companyEdit->setObjectName(QStringLiteral("companyEdit"));
        companyEdit->setReadOnly(true);

        gridLayout->addWidget(companyEdit, 0, 1, 1, 1);

        volumeLb = new QLabel(CreateProduct);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));

        gridLayout->addWidget(volumeLb, 2, 0, 1, 1);

        shelfLifeEdit = new QLineEdit(CreateProduct);
        shelfLifeEdit->setObjectName(QStringLiteral("shelfLifeEdit"));

        gridLayout->addWidget(shelfLifeEdit, 7, 1, 1, 1);

        priceEdit = new QLineEdit(CreateProduct);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));

        gridLayout->addWidget(priceEdit, 4, 1, 1, 1);

        nameLb = new QLabel(CreateProduct);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        measureBtn = new QPushButton(CreateProduct);
        measureBtn->setObjectName(QStringLiteral("measureBtn"));

        gridLayout->addWidget(measureBtn, 3, 0, 1, 1);

        prodTypeEdit = new QLineEdit(CreateProduct);
        prodTypeEdit->setObjectName(QStringLiteral("prodTypeEdit"));
        prodTypeEdit->setReadOnly(true);

        gridLayout->addWidget(prodTypeEdit, 6, 1, 1, 1);

        companyBtn = new QPushButton(CreateProduct);
        companyBtn->setObjectName(QStringLiteral("companyBtn"));
        companyBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(companyBtn, 0, 0, 1, 1);

        nameEdit = new QLineEdit(CreateProduct);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        currencyBtn = new QPushButton(CreateProduct);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 5, 0, 1, 1);

        currencyEdit = new QLineEdit(CreateProduct);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 5, 1, 1, 1);

        QWidget::setTabOrder(companyBtn, companyEdit);
        QWidget::setTabOrder(companyEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, volumeEdit);
        QWidget::setTabOrder(volumeEdit, measureBtn);
        QWidget::setTabOrder(measureBtn, measureEdit);
        QWidget::setTabOrder(measureEdit, priceEdit);
        QWidget::setTabOrder(priceEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, prodTypeBtn);
        QWidget::setTabOrder(prodTypeBtn, prodTypeEdit);
        QWidget::setTabOrder(prodTypeEdit, shelfLifeEdit);
        QWidget::setTabOrder(shelfLifeEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateProduct);

        QMetaObject::connectSlotsByName(CreateProduct);
    } // setupUi

    void retranslateUi(QDialog *CreateProduct)
    {
        CreateProduct->setWindowTitle(QApplication::translate("CreateProduct", "Create/Update product", 0));
        prodTypeBtn->setText(QApplication::translate("CreateProduct", "Select product type", 0));
        priceLb->setText(QApplication::translate("CreateProduct", "Price:", 0));
#ifndef QT_NO_TOOLTIP
        volumeEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: 1 (depending on measure, in that case = 1 liter)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        shelfLifeLb->setText(QApplication::translate("CreateProduct", "Shelf life(in days):", 0));
        okBtn->setText(QApplication::translate("CreateProduct", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateProduct", "Cancel", 0));
        volumeLb->setText(QApplication::translate("CreateProduct", "Volume:", 0));
#ifndef QT_NO_TOOLTIP
        shelfLifeEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: 4 (in days, in that case 4 days)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        priceEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: 3.5 (depending on currency, in that case 3.5 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreateProduct", "Product name:", 0));
        measureBtn->setText(QApplication::translate("CreateProduct", "Select measure", 0));
        companyBtn->setText(QApplication::translate("CreateProduct", "Select company", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateProduct", "<html><head/><body><p>For example: Milk</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currencyBtn->setText(QApplication::translate("CreateProduct", "Select currency", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateProduct: public Ui_CreateProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRODDLG_H
