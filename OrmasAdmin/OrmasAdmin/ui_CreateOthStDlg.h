/********************************************************************************
** Form generated from reading UI file 'CreateOthStDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEOTHSTDLG_H
#define UI_CREATEOTHSTDLG_H

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

class Ui_CreateOtherStocks
{
public:
    QGridLayout *gridLayout;
    QComboBox *currencyCmb;
    QLabel *priceLb;
    QLineEdit *volumeEdit;
    QLabel *currencyLb;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QComboBox *measureCmb;
    QPushButton *companyBtn;
    QLineEdit *companyEdit;
    QLabel *volumeLb;
    QLineEdit *nameEdit;
    QLabel *companyNameLb;
    QLabel *measureLb;
    QLabel *companyNamePh;
    QLabel *nameLb;
    QLineEdit *priceEdit;

    void setupUi(QDialog *CreateOtherStocks)
    {
        if (CreateOtherStocks->objectName().isEmpty())
            CreateOtherStocks->setObjectName(QStringLiteral("CreateOtherStocks"));
        CreateOtherStocks->resize(636, 232);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateOtherStocks->sizePolicy().hasHeightForWidth());
        CreateOtherStocks->setSizePolicy(sizePolicy);
        CreateOtherStocks->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOtherStocks->setModal(false);
        gridLayout = new QGridLayout(CreateOtherStocks);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyCmb = new QComboBox(CreateOtherStocks);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 6, 1, 1, 1);

        priceLb = new QLabel(CreateOtherStocks);
        priceLb->setObjectName(QStringLiteral("priceLb"));

        gridLayout->addWidget(priceLb, 5, 0, 1, 1);

        volumeEdit = new QLineEdit(CreateOtherStocks);
        volumeEdit->setObjectName(QStringLiteral("volumeEdit"));

        gridLayout->addWidget(volumeEdit, 3, 1, 1, 1);

        currencyLb = new QLabel(CreateOtherStocks);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateOtherStocks);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout_2->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateOtherStocks);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout_2->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 2);

        measureCmb = new QComboBox(CreateOtherStocks);
        measureCmb->setObjectName(QStringLiteral("measureCmb"));
        measureCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(measureCmb, 4, 1, 1, 1);

        companyBtn = new QPushButton(CreateOtherStocks);
        companyBtn->setObjectName(QStringLiteral("companyBtn"));
        companyBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(companyBtn, 0, 0, 1, 1);

        companyEdit = new QLineEdit(CreateOtherStocks);
        companyEdit->setObjectName(QStringLiteral("companyEdit"));
        companyEdit->setReadOnly(true);

        gridLayout->addWidget(companyEdit, 0, 1, 1, 1);

        volumeLb = new QLabel(CreateOtherStocks);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));

        gridLayout->addWidget(volumeLb, 3, 0, 1, 1);

        nameEdit = new QLineEdit(CreateOtherStocks);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        companyNameLb = new QLabel(CreateOtherStocks);
        companyNameLb->setObjectName(QStringLiteral("companyNameLb"));

        gridLayout->addWidget(companyNameLb, 1, 0, 1, 1);

        measureLb = new QLabel(CreateOtherStocks);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 4, 0, 1, 1);

        companyNamePh = new QLabel(CreateOtherStocks);
        companyNamePh->setObjectName(QStringLiteral("companyNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        companyNamePh->setFont(font);

        gridLayout->addWidget(companyNamePh, 1, 1, 1, 1);

        nameLb = new QLabel(CreateOtherStocks);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 2, 0, 1, 1);

        priceEdit = new QLineEdit(CreateOtherStocks);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));

        gridLayout->addWidget(priceEdit, 5, 1, 1, 1);

        QWidget::setTabOrder(companyBtn, companyEdit);
        QWidget::setTabOrder(companyEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, volumeEdit);
        QWidget::setTabOrder(volumeEdit, priceEdit);
        QWidget::setTabOrder(priceEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateOtherStocks);

        QMetaObject::connectSlotsByName(CreateOtherStocks);
    } // setupUi

    void retranslateUi(QDialog *CreateOtherStocks)
    {
        CreateOtherStocks->setWindowTitle(QApplication::translate("CreateOtherStocks", "Create/Update other stocks", 0));
        priceLb->setText(QApplication::translate("CreateOtherStocks", "Price:", 0));
#ifndef QT_NO_TOOLTIP
        volumeEdit->setToolTip(QApplication::translate("CreateOtherStocks", "<html><head/><body><p>For example: 1 (depending on measure, in that case = 1 liter)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currencyLb->setText(QApplication::translate("CreateOtherStocks", "Select currency:", 0));
        okBtn->setText(QApplication::translate("CreateOtherStocks", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateOtherStocks", "Cancel", 0));
        companyBtn->setText(QApplication::translate("CreateOtherStocks", "Select company", 0));
        volumeLb->setText(QApplication::translate("CreateOtherStocks", "Volume:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateOtherStocks", "<html><head/><body><p>For example: Milk</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        companyNameLb->setText(QApplication::translate("CreateOtherStocks", "Company name:", 0));
        measureLb->setText(QApplication::translate("CreateOtherStocks", "Select measure:", 0));
        companyNamePh->setText(QString());
        nameLb->setText(QApplication::translate("CreateOtherStocks", "Other stocks name:", 0));
#ifndef QT_NO_TOOLTIP
        priceEdit->setToolTip(QApplication::translate("CreateOtherStocks", "<html><head/><body><p>For example: 3.5 (depending on currency, in that case 3.5 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateOtherStocks: public Ui_CreateOtherStocks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEOTHSTDLG_H
