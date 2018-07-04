/********************************************************************************
** Form generated from reading UI file 'GenerateCmpBlcDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATECMPBLCDLG_H
#define UI_GENERATECMPBLCDLG_H

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

class Ui_GenerateCompanyBalance
{
public:
    QGridLayout *gridLayout;
    QDateEdit *tillDateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *label_2;
    QDateEdit *fromDateEdit;
    QLabel *fromLb;

    void setupUi(QDialog *GenerateCompanyBalance)
    {
        if (GenerateCompanyBalance->objectName().isEmpty())
            GenerateCompanyBalance->setObjectName(QStringLiteral("GenerateCompanyBalance"));
        GenerateCompanyBalance->resize(501, 73);
        GenerateCompanyBalance->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateCompanyBalance->setModal(false);
        gridLayout = new QGridLayout(GenerateCompanyBalance);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillDateEdit = new QDateEdit(GenerateCompanyBalance);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateCompanyBalance);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateCompanyBalance);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 4);

        label_2 = new QLabel(GenerateCompanyBalance);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        fromDateEdit = new QDateEdit(GenerateCompanyBalance);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(GenerateCompanyBalance);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(GenerateCompanyBalance);

        QMetaObject::connectSlotsByName(GenerateCompanyBalance);
    } // setupUi

    void retranslateUi(QDialog *GenerateCompanyBalance)
    {
        GenerateCompanyBalance->setWindowTitle(QApplication::translate("GenerateCompanyBalance", "Generate company balance", 0));
        okBtn->setText(QApplication::translate("GenerateCompanyBalance", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateCompanyBalance", "Cancel", 0));
        label_2->setText(QApplication::translate("GenerateCompanyBalance", "Till date:", 0));
        fromLb->setText(QApplication::translate("GenerateCompanyBalance", "From date:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateCompanyBalance: public Ui_GenerateCompanyBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATECMPBLCDLG_H
