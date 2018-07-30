/********************************************************************************
** Form generated from reading UI file 'CreateDivDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIVDLG_H
#define UI_CREATEDIVDLG_H

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

class Ui_CreateDivision
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLineEdit *nameEdit;
    QLabel *codeLb;
    QLineEdit *codeEdit;

    void setupUi(QDialog *CreateDivision)
    {
        if (CreateDivision->objectName().isEmpty())
            CreateDivision->setObjectName(QStringLiteral("CreateDivision"));
        CreateDivision->resize(461, 99);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateDivision->sizePolicy().hasHeightForWidth());
        CreateDivision->setSizePolicy(sizePolicy);
        CreateDivision->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateDivision->setModal(false);
        gridLayout = new QGridLayout(CreateDivision);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateDivision);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateDivision);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        nameLb = new QLabel(CreateDivision);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLb->sizePolicy().hasHeightForWidth());
        nameLb->setSizePolicy(sizePolicy1);
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        nameEdit = new QLineEdit(CreateDivision);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        codeLb = new QLabel(CreateDivision);
        codeLb->setObjectName(QStringLiteral("codeLb"));

        gridLayout->addWidget(codeLb, 1, 0, 1, 1);

        codeEdit = new QLineEdit(CreateDivision);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        gridLayout->addWidget(codeEdit, 1, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, codeEdit);
        QWidget::setTabOrder(codeEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateDivision);

        QMetaObject::connectSlotsByName(CreateDivision);
    } // setupUi

    void retranslateUi(QDialog *CreateDivision)
    {
        CreateDivision->setWindowTitle(QApplication::translate("CreateDivision", "Create/Update division", 0));
        okBtn->setText(QApplication::translate("CreateDivision", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateDivision", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateDivision", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateDivision", "<html><head/><body><p>For example: &quot;River Co.&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        codeLb->setText(QApplication::translate("CreateDivision", "Code:", 0));
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateDivision", "<html><head/><body><p>For example: RELEASE</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateDivision: public Ui_CreateDivision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIVDLG_H
