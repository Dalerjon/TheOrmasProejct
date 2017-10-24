/********************************************************************************
** Form generated from reading UI file 'CreateSlrTypeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESLRTYPEDLG_H
#define UI_CREATESLRTYPEDLG_H

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

class Ui_CreateSalaryType
{
public:
    QGridLayout *gridLayout;
    QLabel *codeLb;
    QLineEdit *codeEdit;
    QLabel *nameLb;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CreateSalaryType)
    {
        if (CreateSalaryType->objectName().isEmpty())
            CreateSalaryType->setObjectName(QStringLiteral("CreateSalaryType"));
        CreateSalaryType->resize(400, 99);
        CreateSalaryType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSalaryType->setModal(false);
        gridLayout = new QGridLayout(CreateSalaryType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        codeLb = new QLabel(CreateSalaryType);
        codeLb->setObjectName(QStringLiteral("codeLb"));

        gridLayout->addWidget(codeLb, 0, 0, 1, 1);

        codeEdit = new QLineEdit(CreateSalaryType);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));
        codeEdit->setReadOnly(false);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        nameLb = new QLabel(CreateSalaryType);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        nameEdit = new QLineEdit(CreateSalaryType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateSalaryType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateSalaryType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateSalaryType);

        QMetaObject::connectSlotsByName(CreateSalaryType);
    } // setupUi

    void retranslateUi(QDialog *CreateSalaryType)
    {
        CreateSalaryType->setWindowTitle(QApplication::translate("CreateSalaryType", "Create/Update salary type", 0));
        codeLb->setText(QApplication::translate("CreateSalaryType", "Code:", 0));
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateSalaryType", "<html><head/><body><p>For example: Fixed</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreateSalaryType", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateSalaryType", "<html><head/><body><p>For example: fixed value</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateSalaryType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSalaryType", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateSalaryType: public Ui_CreateSalaryType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESLRTYPEDLG_H
