/********************************************************************************
** Form generated from reading UI file 'CreateDivAccDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIVACCDLG_H
#define UI_CREATEDIVACCDLG_H

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

class Ui_CreateDivisionAccount
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *label;
    QLineEdit *codeEdit;
    QPushButton *accountBtn;
    QLineEdit *accountEdit;
    QLabel *label_5;
    QComboBox *divisionCmb;

    void setupUi(QDialog *CreateDivisionAccount)
    {
        if (CreateDivisionAccount->objectName().isEmpty())
            CreateDivisionAccount->setObjectName(QStringLiteral("CreateDivisionAccount"));
        CreateDivisionAccount->resize(595, 134);
        CreateDivisionAccount->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateDivisionAccount->setModal(false);
        gridLayout = new QGridLayout(CreateDivisionAccount);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateDivisionAccount);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateDivisionAccount);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        label = new QLabel(CreateDivisionAccount);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        codeEdit = new QLineEdit(CreateDivisionAccount);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));
        codeEdit->setReadOnly(false);

        gridLayout->addWidget(codeEdit, 3, 1, 1, 1);

        accountBtn = new QPushButton(CreateDivisionAccount);
        accountBtn->setObjectName(QStringLiteral("accountBtn"));

        gridLayout->addWidget(accountBtn, 1, 0, 1, 1);

        accountEdit = new QLineEdit(CreateDivisionAccount);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));
        accountEdit->setReadOnly(true);

        gridLayout->addWidget(accountEdit, 1, 1, 1, 1);

        label_5 = new QLabel(CreateDivisionAccount);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        divisionCmb = new QComboBox(CreateDivisionAccount);
        divisionCmb->setObjectName(QStringLiteral("divisionCmb"));

        gridLayout->addWidget(divisionCmb, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateDivisionAccount);

        QMetaObject::connectSlotsByName(CreateDivisionAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateDivisionAccount)
    {
        CreateDivisionAccount->setWindowTitle(QApplication::translate("CreateDivisionAccount", "Create/Update inventory", 0));
        okBtn->setText(QApplication::translate("CreateDivisionAccount", "Ok", 0));
        cancelBtn->setText(QApplication::translate("CreateDivisionAccount", "Cancel", 0));
        label->setText(QApplication::translate("CreateDivisionAccount", "Code:", 0));
        accountBtn->setText(QApplication::translate("CreateDivisionAccount", "Select account", 0));
        label_5->setText(QApplication::translate("CreateDivisionAccount", "Division:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateDivisionAccount: public Ui_CreateDivisionAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIVACCDLG_H
