/********************************************************************************
** Form generated from reading UI file 'CreateCARDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECARDLG_H
#define UI_CREATECARDLG_H

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

class Ui_CreateCompanyAccount
{
public:
    QGridLayout *gridLayout;
    QLabel *numberLb;
    QLineEdit *accountEdit;
    QLabel *companyLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QComboBox *companyCmb;
    QPushButton *accountBtn;
    QLabel *numberPh;

    void setupUi(QDialog *CreateCompanyAccount)
    {
        if (CreateCompanyAccount->objectName().isEmpty())
            CreateCompanyAccount->setObjectName(QStringLiteral("CreateCompanyAccount"));
        CreateCompanyAccount->resize(551, 144);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCompanyAccount->sizePolicy().hasHeightForWidth());
        CreateCompanyAccount->setSizePolicy(sizePolicy);
        CreateCompanyAccount->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCompanyAccount->setModal(false);
        gridLayout = new QGridLayout(CreateCompanyAccount);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        numberLb = new QLabel(CreateCompanyAccount);
        numberLb->setObjectName(QStringLiteral("numberLb"));
        numberLb->setMinimumSize(QSize(0, 0));
        numberLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(numberLb, 2, 0, 1, 1);

        accountEdit = new QLineEdit(CreateCompanyAccount);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));
        accountEdit->setReadOnly(true);

        gridLayout->addWidget(accountEdit, 1, 2, 1, 1);

        companyLb = new QLabel(CreateCompanyAccount);
        companyLb->setObjectName(QStringLiteral("companyLb"));

        gridLayout->addWidget(companyLb, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCompanyAccount);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCompanyAccount);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 4);

        companyCmb = new QComboBox(CreateCompanyAccount);
        companyCmb->setObjectName(QStringLiteral("companyCmb"));

        gridLayout->addWidget(companyCmb, 0, 2, 1, 1);

        accountBtn = new QPushButton(CreateCompanyAccount);
        accountBtn->setObjectName(QStringLiteral("accountBtn"));
        accountBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(accountBtn, 1, 0, 1, 2);

        numberPh = new QLabel(CreateCompanyAccount);
        numberPh->setObjectName(QStringLiteral("numberPh"));
        numberPh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        numberPh->setFont(font);

        gridLayout->addWidget(numberPh, 2, 1, 1, 2);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateCompanyAccount);

        QMetaObject::connectSlotsByName(CreateCompanyAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateCompanyAccount)
    {
        CreateCompanyAccount->setWindowTitle(QApplication::translate("CreateCompanyAccount", "Create company-account relation", 0));
        numberLb->setText(QApplication::translate("CreateCompanyAccount", "Number:", 0));
        companyLb->setText(QApplication::translate("CreateCompanyAccount", "Select company:", 0));
        okBtn->setText(QApplication::translate("CreateCompanyAccount", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCompanyAccount", "Cancel", 0));
        accountBtn->setText(QApplication::translate("CreateCompanyAccount", "Select account", 0));
        numberPh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateCompanyAccount: public Ui_CreateCompanyAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECARDLG_H
