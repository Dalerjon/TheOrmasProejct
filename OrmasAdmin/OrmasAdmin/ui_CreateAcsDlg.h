/********************************************************************************
** Form generated from reading UI file 'CreateAcsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACSDLG_H
#define UI_CREATEACSDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateAccess
{
public:
    QGridLayout *gridLayout;
    QLineEdit *roleEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *acsItemEdit;
    QPushButton *roleBtn;
    QPushButton *acsItemBtn;

    void setupUi(QDialog *CreateAccess)
    {
        if (CreateAccess->objectName().isEmpty())
            CreateAccess->setObjectName(QStringLiteral("CreateAccess"));
        CreateAccess->resize(400, 105);
        CreateAccess->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateAccess->setModal(false);
        gridLayout = new QGridLayout(CreateAccess);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        roleEdit = new QLineEdit(CreateAccess);
        roleEdit->setObjectName(QStringLiteral("roleEdit"));
        roleEdit->setReadOnly(true);

        gridLayout->addWidget(roleEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateAccess);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateAccess);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        acsItemEdit = new QLineEdit(CreateAccess);
        acsItemEdit->setObjectName(QStringLiteral("acsItemEdit"));
        acsItemEdit->setReadOnly(true);

        gridLayout->addWidget(acsItemEdit, 1, 1, 1, 1);

        roleBtn = new QPushButton(CreateAccess);
        roleBtn->setObjectName(QStringLiteral("roleBtn"));
        roleBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(roleBtn, 0, 0, 1, 1);

        acsItemBtn = new QPushButton(CreateAccess);
        acsItemBtn->setObjectName(QStringLiteral("acsItemBtn"));

        gridLayout->addWidget(acsItemBtn, 1, 0, 1, 1);

        QWidget::setTabOrder(roleBtn, roleEdit);
        QWidget::setTabOrder(roleEdit, acsItemBtn);
        QWidget::setTabOrder(acsItemBtn, acsItemEdit);
        QWidget::setTabOrder(acsItemEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateAccess);

        QMetaObject::connectSlotsByName(CreateAccess);
    } // setupUi

    void retranslateUi(QDialog *CreateAccess)
    {
        CreateAccess->setWindowTitle(QApplication::translate("CreateAccess", "Create/Update access", 0));
#ifndef QT_NO_TOOLTIP
        roleEdit->setToolTip(QApplication::translate("CreateAccess", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateAccess", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateAccess", "Cancel", 0));
        roleBtn->setText(QApplication::translate("CreateAccess", "Select role", 0));
        acsItemBtn->setText(QApplication::translate("CreateAccess", "Select access item", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAccess: public Ui_CreateAccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACSDLG_H
