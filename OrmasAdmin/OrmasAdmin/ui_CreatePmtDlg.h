/********************************************************************************
** Form generated from reading UI file 'CreatePmtDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPMTDLG_H
#define UI_CREATEPMTDLG_H

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

class Ui_CreatePayment
{
public:
    QGridLayout *gridLayout;
    QLineEdit *userEdit;
    QLineEdit *valueEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *currencyEdit;
    QLabel *valieLb;
    QPushButton *currencyBtn;
    QLabel *dateLb;
    QDateEdit *dateEdit;
    QPushButton *userBtn;

    void setupUi(QDialog *CreatePayment)
    {
        if (CreatePayment->objectName().isEmpty())
            CreatePayment->setObjectName(QStringLiteral("CreatePayment"));
        CreatePayment->resize(400, 157);
        CreatePayment->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePayment->setModal(false);
        gridLayout = new QGridLayout(CreatePayment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        userEdit = new QLineEdit(CreatePayment);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 4, 1, 1, 1);

        valueEdit = new QLineEdit(CreatePayment);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePayment);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePayment);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        currencyEdit = new QLineEdit(CreatePayment);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 5, 1, 1, 1);

        valieLb = new QLabel(CreatePayment);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        currencyBtn = new QPushButton(CreatePayment);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 5, 0, 1, 1);

        dateLb = new QLabel(CreatePayment);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        dateEdit = new QDateEdit(CreatePayment);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

        userBtn = new QPushButton(CreatePayment);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 4, 0, 1, 1);

        QWidget::setTabOrder(dateEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, userBtn);
        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePayment);

        QMetaObject::connectSlotsByName(CreatePayment);
    } // setupUi

    void retranslateUi(QDialog *CreatePayment)
    {
        CreatePayment->setWindowTitle(QApplication::translate("CreatePayment", "Create/Update payment", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreatePayment", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePayment", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreatePayment", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePayment", "Cancel", 0));
        valieLb->setText(QApplication::translate("CreatePayment", "Value:", 0));
        currencyBtn->setText(QApplication::translate("CreatePayment", "Select currency", 0));
        dateLb->setText(QApplication::translate("CreatePayment", "Date:", 0));
        userBtn->setText(QApplication::translate("CreatePayment", "Select user", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePayment: public Ui_CreatePayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPMTDLG_H
