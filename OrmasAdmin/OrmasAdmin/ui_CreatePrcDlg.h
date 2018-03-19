/********************************************************************************
** Form generated from reading UI file 'CreatePrcDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPRCDLG_H
#define UI_CREATEPRCDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreatePrice
{
public:
    QGridLayout *gridLayout;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QLabel *valieLb;
    QLabel *dateLb;
    QLabel *currencyLb;
    QLabel *measurePh;
    QLabel *prodNameLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *valueEdit;
    QComboBox *currencyCmb;
    QPushButton *productBtn;
    QDateTimeEdit *dateEdit;
    QLineEdit *productEdit;
    QLabel *isOutdatedLb;
    QComboBox *isOutdatedCmb;

    void setupUi(QDialog *CreatePrice)
    {
        if (CreatePrice->objectName().isEmpty())
            CreatePrice->setObjectName(QStringLiteral("CreatePrice"));
        CreatePrice->resize(618, 210);
        CreatePrice->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePrice->setModal(false);
        gridLayout = new QGridLayout(CreatePrice);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        volumePh = new QLabel(CreatePrice);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 7, 3, 1, 1);

        measureLb = new QLabel(CreatePrice);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 7, 4, 1, 1);

        prodNamePh = new QLabel(CreatePrice);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 7, 1, 1, 1);

        volumeLb = new QLabel(CreatePrice);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 7, 2, 1, 1);

        valieLb = new QLabel(CreatePrice);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        dateLb = new QLabel(CreatePrice);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        currencyLb = new QLabel(CreatePrice);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 5, 0, 1, 1);

        measurePh = new QLabel(CreatePrice);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 7, 5, 1, 1);

        prodNameLb = new QLabel(CreatePrice);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePrice);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePrice);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 6);

        valueEdit = new QLineEdit(CreatePrice);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 2, 1, 2);

        currencyCmb = new QComboBox(CreatePrice);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 5, 2, 1, 2);

        productBtn = new QPushButton(CreatePrice);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(productBtn, 6, 0, 1, 2);

        dateEdit = new QDateTimeEdit(CreatePrice);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 2);

        productEdit = new QLineEdit(CreatePrice);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 6, 2, 1, 2);

        isOutdatedLb = new QLabel(CreatePrice);
        isOutdatedLb->setObjectName(QStringLiteral("isOutdatedLb"));

        gridLayout->addWidget(isOutdatedLb, 8, 0, 1, 2);

        isOutdatedCmb = new QComboBox(CreatePrice);
        isOutdatedCmb->setObjectName(QStringLiteral("isOutdatedCmb"));

        gridLayout->addWidget(isOutdatedCmb, 8, 2, 1, 2);

        QWidget::setTabOrder(productBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePrice);

        QMetaObject::connectSlotsByName(CreatePrice);
    } // setupUi

    void retranslateUi(QDialog *CreatePrice)
    {
        CreatePrice->setWindowTitle(QApplication::translate("CreatePrice", "Create/Update price", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreatePrice", "Measure:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreatePrice", "Volume:", 0));
        valieLb->setText(QApplication::translate("CreatePrice", "Value:", 0));
        dateLb->setText(QApplication::translate("CreatePrice", "Date:", 0));
        currencyLb->setText(QApplication::translate("CreatePrice", "Select currency:", 0));
        measurePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreatePrice", "Product name:", 0));
        okBtn->setText(QApplication::translate("CreatePrice", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePrice", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePrice", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        productBtn->setText(QApplication::translate("CreatePrice", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        productEdit->setToolTip(QApplication::translate("CreatePrice", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        isOutdatedLb->setText(QApplication::translate("CreatePrice", "Is out of date?", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePrice: public Ui_CreatePrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRCDLG_H
