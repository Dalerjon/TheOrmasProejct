/********************************************************************************
** Form generated from reading UI file 'CreatePrdTpDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPRDTPDLG_H
#define UI_CREATEPRDTPDLG_H

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

class Ui_CreateProductType
{
public:
    QGridLayout *gridLayout;
    QLabel *shortNameLb;
    QLabel *nameLb;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *shortNameEdit;

    void setupUi(QDialog *CreateProductType)
    {
        if (CreateProductType->objectName().isEmpty())
            CreateProductType->setObjectName(QStringLiteral("CreateProductType"));
        CreateProductType->resize(400, 99);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateProductType->sizePolicy().hasHeightForWidth());
        CreateProductType->setSizePolicy(sizePolicy);
        CreateProductType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateProductType->setModal(true);
        gridLayout = new QGridLayout(CreateProductType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        shortNameLb = new QLabel(CreateProductType);
        shortNameLb->setObjectName(QStringLiteral("shortNameLb"));

        gridLayout->addWidget(shortNameLb, 1, 0, 1, 1);

        nameLb = new QLabel(CreateProductType);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        nameEdit = new QLineEdit(CreateProductType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateProductType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateProductType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        shortNameEdit = new QLineEdit(CreateProductType);
        shortNameEdit->setObjectName(QStringLiteral("shortNameEdit"));

        gridLayout->addWidget(shortNameEdit, 1, 1, 1, 1);


        retranslateUi(CreateProductType);

        QMetaObject::connectSlotsByName(CreateProductType);
    } // setupUi

    void retranslateUi(QDialog *CreateProductType)
    {
        CreateProductType->setWindowTitle(QApplication::translate("CreateProductType", "Create/Update product type", 0));
        shortNameLb->setText(QApplication::translate("CreateProductType", "Short name", 0));
        nameLb->setText(QApplication::translate("CreateProductType", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateProductType", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateProductType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateProductType", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        shortNameEdit->setToolTip(QApplication::translate("CreateProductType", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateProductType: public Ui_CreateProductType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRDTPDLG_H
