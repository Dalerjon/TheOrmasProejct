/********************************************************************************
** Form generated from reading UI file 'CashInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHINFODLG_H
#define UI_CASHINFODLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CashInfo
{
public:
    QGridLayout *gridLayout;
    QLabel *cashLb;
    QLabel *cashValueLb;
    QLabel *cashCurLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CashInfo)
    {
        if (CashInfo->objectName().isEmpty())
            CashInfo->setObjectName(QStringLiteral("CashInfo"));
        CashInfo->resize(501, 73);
        CashInfo->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CashInfo->setModal(false);
        gridLayout = new QGridLayout(CashInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        cashLb = new QLabel(CashInfo);
        cashLb->setObjectName(QStringLiteral("cashLb"));

        gridLayout->addWidget(cashLb, 0, 1, 1, 1);

        cashValueLb = new QLabel(CashInfo);
        cashValueLb->setObjectName(QStringLiteral("cashValueLb"));

        gridLayout->addWidget(cashValueLb, 0, 2, 1, 1);

        cashCurLb = new QLabel(CashInfo);
        cashCurLb->setObjectName(QStringLiteral("cashCurLb"));

        gridLayout->addWidget(cashCurLb, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CashInfo);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CashInfo);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 3);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CashInfo);

        QMetaObject::connectSlotsByName(CashInfo);
    } // setupUi

    void retranslateUi(QDialog *CashInfo)
    {
        CashInfo->setWindowTitle(QApplication::translate("CashInfo", "Information about cash", 0));
        cashLb->setText(QApplication::translate("CashInfo", "Cash:", 0));
        cashValueLb->setText(QString());
        cashCurLb->setText(QString());
        okBtn->setText(QApplication::translate("CashInfo", "OK", 0));
        cancelBtn->setText(QApplication::translate("CashInfo", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CashInfo: public Ui_CashInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHINFODLG_H
