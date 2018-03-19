/********************************************************************************
** Form generated from reading UI file 'GenerateOneAccDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEONEACCDLG_H
#define UI_GENERATEONEACCDLG_H

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

class Ui_GenerateOneAccount
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *generateBtn;
    QPushButton *cancelBtn;
    QLabel *companyLb;
    QComboBox *currencyCmb;
    QComboBox *companyCmb;
    QLabel *currencyLb;
    QLineEdit *chartOfAccEdit;
    QPushButton *chartOfAccBtn;
    QLabel *accNameLb;
    QLabel *accNamePh;

    void setupUi(QDialog *GenerateOneAccount)
    {
        if (GenerateOneAccount->objectName().isEmpty())
            GenerateOneAccount->setObjectName(QStringLiteral("GenerateOneAccount"));
        GenerateOneAccount->resize(551, 154);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GenerateOneAccount->sizePolicy().hasHeightForWidth());
        GenerateOneAccount->setSizePolicy(sizePolicy);
        GenerateOneAccount->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateOneAccount->setModal(false);
        gridLayout = new QGridLayout(GenerateOneAccount);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        generateBtn = new QPushButton(GenerateOneAccount);
        generateBtn->setObjectName(QStringLiteral("generateBtn"));

        horizontalLayout->addWidget(generateBtn);

        cancelBtn = new QPushButton(GenerateOneAccount);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 3);

        companyLb = new QLabel(GenerateOneAccount);
        companyLb->setObjectName(QStringLiteral("companyLb"));

        gridLayout->addWidget(companyLb, 0, 0, 1, 1);

        currencyCmb = new QComboBox(GenerateOneAccount);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 1, 1, 1, 1);

        companyCmb = new QComboBox(GenerateOneAccount);
        companyCmb->setObjectName(QStringLiteral("companyCmb"));

        gridLayout->addWidget(companyCmb, 0, 1, 1, 2);

        currencyLb = new QLabel(GenerateOneAccount);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));
        currencyLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(currencyLb, 1, 0, 1, 1);

        chartOfAccEdit = new QLineEdit(GenerateOneAccount);
        chartOfAccEdit->setObjectName(QStringLiteral("chartOfAccEdit"));
        chartOfAccEdit->setMaximumSize(QSize(150, 16777215));
        chartOfAccEdit->setReadOnly(true);

        gridLayout->addWidget(chartOfAccEdit, 2, 1, 1, 1);

        chartOfAccBtn = new QPushButton(GenerateOneAccount);
        chartOfAccBtn->setObjectName(QStringLiteral("chartOfAccBtn"));

        gridLayout->addWidget(chartOfAccBtn, 2, 0, 1, 1);

        accNameLb = new QLabel(GenerateOneAccount);
        accNameLb->setObjectName(QStringLiteral("accNameLb"));

        gridLayout->addWidget(accNameLb, 3, 0, 1, 1);

        accNamePh = new QLabel(GenerateOneAccount);
        accNamePh->setObjectName(QStringLiteral("accNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        accNamePh->setFont(font);

        gridLayout->addWidget(accNamePh, 3, 1, 1, 2);

        QWidget::setTabOrder(generateBtn, cancelBtn);

        retranslateUi(GenerateOneAccount);

        QMetaObject::connectSlotsByName(GenerateOneAccount);
    } // setupUi

    void retranslateUi(QDialog *GenerateOneAccount)
    {
        GenerateOneAccount->setWindowTitle(QApplication::translate("GenerateOneAccount", "Create account for  selected company, currency and type", 0));
        generateBtn->setText(QApplication::translate("GenerateOneAccount", "Generate", 0));
        cancelBtn->setText(QApplication::translate("GenerateOneAccount", "Cancel", 0));
        companyLb->setText(QApplication::translate("GenerateOneAccount", "Select company:", 0));
        currencyLb->setText(QApplication::translate("GenerateOneAccount", "Select currency:", 0));
        chartOfAccBtn->setText(QApplication::translate("GenerateOneAccount", "Select accout from chart", 0));
        accNameLb->setText(QApplication::translate("GenerateOneAccount", "Account name:", 0));
        accNamePh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GenerateOneAccount: public Ui_GenerateOneAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEONEACCDLG_H
