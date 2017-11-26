/********************************************************************************
** Form generated from reading UI file 'CreateRfdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERFDDLG_H
#define UI_CREATERFDDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_CreateRefund
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
    QPushButton *userBtn;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateRefund)
    {
        if (CreateRefund->objectName().isEmpty())
            CreateRefund->setObjectName(QStringLiteral("CreateRefund"));
        CreateRefund->resize(400, 157);
        CreateRefund->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRefund->setModal(false);
        gridLayout = new QGridLayout(CreateRefund);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        userEdit = new QLineEdit(CreateRefund);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 4, 1, 1, 1);

        valueEdit = new QLineEdit(CreateRefund);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateRefund);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateRefund);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        currencyEdit = new QLineEdit(CreateRefund);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 5, 1, 1, 1);

        valieLb = new QLabel(CreateRefund);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        currencyBtn = new QPushButton(CreateRefund);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 5, 0, 1, 1);

        dateLb = new QLabel(CreateRefund);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        userBtn = new QPushButton(CreateRefund);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 4, 0, 1, 1);

        dateEdit = new QDateTimeEdit(CreateRefund);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

        QWidget::setTabOrder(valueEdit, userBtn);
        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateRefund);

        QMetaObject::connectSlotsByName(CreateRefund);
    } // setupUi

    void retranslateUi(QDialog *CreateRefund)
    {
        CreateRefund->setWindowTitle(QApplication::translate("CreateRefund", "Create/Update refund", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateRefund", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateRefund", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateRefund", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateRefund", "Cancel", 0));
        valieLb->setText(QApplication::translate("CreateRefund", "Sum:", 0));
        currencyBtn->setText(QApplication::translate("CreateRefund", "Select currency", 0));
        dateLb->setText(QApplication::translate("CreateRefund", "Date:", 0));
        userBtn->setText(QApplication::translate("CreateRefund", "Select user", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateRefund: public Ui_CreateRefund {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERFDDLG_H
