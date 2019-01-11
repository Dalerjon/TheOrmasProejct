/********************************************************************************
** Form generated from reading UI file 'CashBookListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHBOOKLISTDLG_H
#define UI_CASHBOOKLISTDLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CashBookList
{
public:
    QGridLayout *gridLayout;
    QLabel *forDateLb;
    QDateEdit *forDateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CashBookList)
    {
        if (CashBookList->objectName().isEmpty())
            CashBookList->setObjectName(QStringLiteral("CashBookList"));
        CashBookList->resize(501, 73);
        CashBookList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CashBookList->setModal(false);
        gridLayout = new QGridLayout(CashBookList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        forDateLb = new QLabel(CashBookList);
        forDateLb->setObjectName(QStringLiteral("forDateLb"));

        gridLayout->addWidget(forDateLb, 0, 1, 1, 1);

        forDateEdit = new QDateEdit(CashBookList);
        forDateEdit->setObjectName(QStringLiteral("forDateEdit"));

        gridLayout->addWidget(forDateEdit, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CashBookList);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CashBookList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 3);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CashBookList);

        QMetaObject::connectSlotsByName(CashBookList);
    } // setupUi

    void retranslateUi(QDialog *CashBookList)
    {
        CashBookList->setWindowTitle(QApplication::translate("CashBookList", "Cash book list", 0));
        forDateLb->setText(QApplication::translate("CashBookList", "For date:", 0));
        okBtn->setText(QApplication::translate("CashBookList", "OK", 0));
        cancelBtn->setText(QApplication::translate("CashBookList", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CashBookList: public Ui_CashBookList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHBOOKLISTDLG_H
