/********************************************************************************
** Form generated from reading UI file 'GenerateAccDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEACCDLG_H
#define UI_GENERATEACCDLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GenerateAccounts
{
public:
    QGridLayout *gridLayout;
    QLabel *companyLb;
    QComboBox *currencyCmb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *generateBtn;
    QPushButton *cancelBtn;
    QLabel *currencyLb;
    QComboBox *companyCmb;

    void setupUi(QDialog *GenerateAccounts)
    {
        if (GenerateAccounts->objectName().isEmpty())
            GenerateAccounts->setObjectName(QStringLiteral("GenerateAccounts"));
        GenerateAccounts->resize(551, 99);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GenerateAccounts->sizePolicy().hasHeightForWidth());
        GenerateAccounts->setSizePolicy(sizePolicy);
        GenerateAccounts->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateAccounts->setModal(false);
        gridLayout = new QGridLayout(GenerateAccounts);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        companyLb = new QLabel(GenerateAccounts);
        companyLb->setObjectName(QStringLiteral("companyLb"));

        gridLayout->addWidget(companyLb, 0, 0, 1, 1);

        currencyCmb = new QComboBox(GenerateAccounts);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        generateBtn = new QPushButton(GenerateAccounts);
        generateBtn->setObjectName(QStringLiteral("generateBtn"));

        horizontalLayout->addWidget(generateBtn);

        cancelBtn = new QPushButton(GenerateAccounts);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);

        currencyLb = new QLabel(GenerateAccounts);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));
        currencyLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(currencyLb, 1, 0, 1, 1);

        companyCmb = new QComboBox(GenerateAccounts);
        companyCmb->setObjectName(QStringLiteral("companyCmb"));

        gridLayout->addWidget(companyCmb, 0, 1, 1, 2);

        QWidget::setTabOrder(generateBtn, cancelBtn);

        retranslateUi(GenerateAccounts);

        QMetaObject::connectSlotsByName(GenerateAccounts);
    } // setupUi

    void retranslateUi(QDialog *GenerateAccounts)
    {
        GenerateAccounts->setWindowTitle(QApplication::translate("GenerateAccounts", "Generate all accounts for  selected company and currency", 0));
        companyLb->setText(QApplication::translate("GenerateAccounts", "Select company:", 0));
        generateBtn->setText(QApplication::translate("GenerateAccounts", "Generate", 0));
        cancelBtn->setText(QApplication::translate("GenerateAccounts", "Cancel", 0));
        currencyLb->setText(QApplication::translate("GenerateAccounts", "Select currency:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateAccounts: public Ui_GenerateAccounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEACCDLG_H
