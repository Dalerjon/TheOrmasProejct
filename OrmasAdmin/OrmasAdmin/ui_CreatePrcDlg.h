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
#include <QtWidgets/QDateEdit>
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
    QPushButton *currencyBtn;
    QLabel *dateLb;
    QLineEdit *currencyEdit;
    QLabel *valieLb;
    QLineEdit *valueEdit;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *productBtn;
    QLineEdit *productEdit;

    void setupUi(QDialog *CreatePrice)
    {
        if (CreatePrice->objectName().isEmpty())
            CreatePrice->setObjectName(QStringLiteral("CreatePrice"));
        CreatePrice->resize(400, 157);
        CreatePrice->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePrice->setModal(false);
        gridLayout = new QGridLayout(CreatePrice);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyBtn = new QPushButton(CreatePrice);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 5, 0, 1, 1);

        dateLb = new QLabel(CreatePrice);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        currencyEdit = new QLineEdit(CreatePrice);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 5, 1, 1, 1);

        valieLb = new QLabel(CreatePrice);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        valueEdit = new QLineEdit(CreatePrice);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 1, 1, 1);

        dateEdit = new QDateEdit(CreatePrice);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 2);

        productBtn = new QPushButton(CreatePrice);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(productBtn, 6, 0, 1, 1);

        productEdit = new QLineEdit(CreatePrice);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 6, 1, 1, 1);

        QWidget::setTabOrder(dateEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, productBtn);
        QWidget::setTabOrder(productBtn, productEdit);
        QWidget::setTabOrder(productEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePrice);

        QMetaObject::connectSlotsByName(CreatePrice);
    } // setupUi

    void retranslateUi(QDialog *CreatePrice)
    {
        CreatePrice->setWindowTitle(QApplication::translate("CreatePrice", "Create/Update price", 0));
        currencyBtn->setText(QApplication::translate("CreatePrice", "Select currency", 0));
        dateLb->setText(QApplication::translate("CreatePrice", "Date:", 0));
        valieLb->setText(QApplication::translate("CreatePrice", "Value:", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePrice", "<html><head/><body><p>For example: 1000 (depends on currency, in that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreatePrice", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePrice", "Cancel", 0));
        productBtn->setText(QApplication::translate("CreatePrice", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        productEdit->setToolTip(QApplication::translate("CreatePrice", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreatePrice: public Ui_CreatePrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRCDLG_H
