/********************************************************************************
** Form generated from reading UI file 'CreateNetCDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENETCDLG_H
#define UI_CREATENETCDLG_H

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

class Ui_CreateNetCost
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

    void setupUi(QDialog *CreateNetCost)
    {
        if (CreateNetCost->objectName().isEmpty())
            CreateNetCost->setObjectName(QStringLiteral("CreateNetCost"));
        CreateNetCost->resize(618, 210);
        CreateNetCost->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateNetCost->setModal(false);
        gridLayout = new QGridLayout(CreateNetCost);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        volumePh = new QLabel(CreateNetCost);
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

        measureLb = new QLabel(CreateNetCost);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 7, 4, 1, 1);

        prodNamePh = new QLabel(CreateNetCost);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 7, 1, 1, 1);

        volumeLb = new QLabel(CreateNetCost);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 7, 2, 1, 1);

        valieLb = new QLabel(CreateNetCost);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        dateLb = new QLabel(CreateNetCost);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        currencyLb = new QLabel(CreateNetCost);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 5, 0, 1, 1);

        measurePh = new QLabel(CreateNetCost);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 7, 5, 1, 1);

        prodNameLb = new QLabel(CreateNetCost);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateNetCost);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateNetCost);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 6);

        valueEdit = new QLineEdit(CreateNetCost);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 2, 1, 2);

        currencyCmb = new QComboBox(CreateNetCost);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 5, 2, 1, 2);

        productBtn = new QPushButton(CreateNetCost);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(productBtn, 6, 0, 1, 2);

        dateEdit = new QDateTimeEdit(CreateNetCost);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 2);

        productEdit = new QLineEdit(CreateNetCost);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 6, 2, 1, 2);

        isOutdatedLb = new QLabel(CreateNetCost);
        isOutdatedLb->setObjectName(QStringLiteral("isOutdatedLb"));

        gridLayout->addWidget(isOutdatedLb, 8, 0, 1, 2);

        isOutdatedCmb = new QComboBox(CreateNetCost);
        isOutdatedCmb->setObjectName(QStringLiteral("isOutdatedCmb"));

        gridLayout->addWidget(isOutdatedCmb, 8, 2, 1, 2);

        QWidget::setTabOrder(productBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateNetCost);

        QMetaObject::connectSlotsByName(CreateNetCost);
    } // setupUi

    void retranslateUi(QDialog *CreateNetCost)
    {
        CreateNetCost->setWindowTitle(QApplication::translate("CreateNetCost", "Create/Update net cost", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateNetCost", "Measure:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateNetCost", "Volume:", 0));
        valieLb->setText(QApplication::translate("CreateNetCost", "Value:", 0));
        dateLb->setText(QApplication::translate("CreateNetCost", "Date:", 0));
        currencyLb->setText(QApplication::translate("CreateNetCost", "Select currency:", 0));
        measurePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateNetCost", "Product name:", 0));
        okBtn->setText(QApplication::translate("CreateNetCost", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateNetCost", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateNetCost", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        productBtn->setText(QApplication::translate("CreateNetCost", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        productEdit->setToolTip(QApplication::translate("CreateNetCost", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        isOutdatedLb->setText(QApplication::translate("CreateNetCost", "Is out of date?", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNetCost: public Ui_CreateNetCost {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENETCDLG_H
