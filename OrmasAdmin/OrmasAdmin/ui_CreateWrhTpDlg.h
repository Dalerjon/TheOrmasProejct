/********************************************************************************
** Form generated from reading UI file 'CreateWrhTpDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWRHTPDLG_H
#define UI_CREATEWRHTPDLG_H

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

class Ui_CreateWarehouseType
{
public:
    QGridLayout *gridLayout;
    QLabel *CodeLb;
    QLabel *nameLb;
    QLineEdit *nameEdit;
    QLineEdit *codeEdit;
    QLineEdit *purposeEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *purposeLb;

    void setupUi(QDialog *CreateWarehouseType)
    {
        if (CreateWarehouseType->objectName().isEmpty())
            CreateWarehouseType->setObjectName(QStringLiteral("CreateWarehouseType"));
        CreateWarehouseType->resize(415, 151);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateWarehouseType->sizePolicy().hasHeightForWidth());
        CreateWarehouseType->setSizePolicy(sizePolicy);
        CreateWarehouseType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWarehouseType->setModal(false);
        gridLayout = new QGridLayout(CreateWarehouseType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        CodeLb = new QLabel(CreateWarehouseType);
        CodeLb->setObjectName(QStringLiteral("CodeLb"));
        CodeLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(CodeLb, 0, 0, 1, 1);

        nameLb = new QLabel(CreateWarehouseType);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 3, 0, 1, 1);

        nameEdit = new QLineEdit(CreateWarehouseType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(nameEdit, 3, 1, 1, 1);

        codeEdit = new QLineEdit(CreateWarehouseType);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));
        codeEdit->setMinimumSize(QSize(150, 0));
        codeEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        purposeEdit = new QLineEdit(CreateWarehouseType);
        purposeEdit->setObjectName(QStringLiteral("purposeEdit"));
        purposeEdit->setMinimumSize(QSize(150, 0));
        purposeEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(purposeEdit, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWarehouseType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWarehouseType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 3);

        purposeLb = new QLabel(CreateWarehouseType);
        purposeLb->setObjectName(QStringLiteral("purposeLb"));

        gridLayout->addWidget(purposeLb, 2, 0, 1, 1);

        QWidget::setTabOrder(codeEdit, purposeEdit);
        QWidget::setTabOrder(purposeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateWarehouseType);

        QMetaObject::connectSlotsByName(CreateWarehouseType);
    } // setupUi

    void retranslateUi(QDialog *CreateWarehouseType)
    {
        CreateWarehouseType->setWindowTitle(QApplication::translate("CreateWarehouseType", "Create/Update warehouse type", 0));
        CodeLb->setText(QApplication::translate("CreateWarehouseType", "Code:", 0));
        nameLb->setText(QApplication::translate("CreateWarehouseType", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateWarehouseType", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        purposeEdit->setToolTip(QApplication::translate("CreateWarehouseType", "<html><head/><body><p>For example: John.Doe@gmail.com (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateWarehouseType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWarehouseType", "Cancel", 0));
        purposeLb->setText(QApplication::translate("CreateWarehouseType", "Purpose:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWarehouseType: public Ui_CreateWarehouseType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWRHTPDLG_H
