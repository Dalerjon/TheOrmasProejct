/********************************************************************************
** Form generated from reading UI file 'CreateBlcDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBLCDLG_H
#define UI_CREATEBLCDLG_H

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

class Ui_CreateBalance
{
public:
    QGridLayout *gridLayout;
    QPushButton *userBtn;
    QLineEdit *userEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *currencyEdit;
    QPushButton *currencyBtn;
    QLabel *valieLb;
    QLineEdit *valueEdit;

    void setupUi(QDialog *CreateBalance)
    {
        if (CreateBalance->objectName().isEmpty())
            CreateBalance->setObjectName(QStringLiteral("CreateBalance"));
        CreateBalance->resize(400, 131);
        CreateBalance->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateBalance->setModal(false);
        gridLayout = new QGridLayout(CreateBalance);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        userBtn = new QPushButton(CreateBalance);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 0, 0, 1, 1);

        userEdit = new QLineEdit(CreateBalance);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateBalance);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateBalance);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        currencyEdit = new QLineEdit(CreateBalance);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 2, 1, 1, 1);

        currencyBtn = new QPushButton(CreateBalance);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 2, 0, 1, 1);

        valieLb = new QLabel(CreateBalance);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 1, 0, 1, 1);

        valueEdit = new QLineEdit(CreateBalance);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 1, 1, 1, 1);

        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateBalance);

        QMetaObject::connectSlotsByName(CreateBalance);
    } // setupUi

    void retranslateUi(QDialog *CreateBalance)
    {
        CreateBalance->setWindowTitle(QApplication::translate("CreateBalance", "Create/Update balance", 0));
        userBtn->setText(QApplication::translate("CreateBalance", "Select user", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateBalance", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateBalance", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateBalance", "Cancel", 0));
        currencyBtn->setText(QApplication::translate("CreateBalance", "Select currency", 0));
        valieLb->setText(QApplication::translate("CreateBalance", "Value:", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateBalance", "<html><head/><body><p>For example: 1000 (depends on currency, for that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateBalance: public Ui_CreateBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBLCDLG_H
