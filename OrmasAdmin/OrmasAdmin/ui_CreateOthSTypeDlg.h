/********************************************************************************
** Form generated from reading UI file 'CreateOthSTypeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEOTHSTYPEDLG_H
#define UI_CREATEOTHSTYPEDLG_H

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

class Ui_CreateOthSType
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
    QLineEdit *codeEdit;
    QLabel *codeLb;

    void setupUi(QDialog *CreateOthSType)
    {
        if (CreateOthSType->objectName().isEmpty())
            CreateOthSType->setObjectName(QStringLiteral("CreateOthSType"));
        CreateOthSType->resize(400, 127);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateOthSType->sizePolicy().hasHeightForWidth());
        CreateOthSType->setSizePolicy(sizePolicy);
        CreateOthSType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOthSType->setModal(false);
        gridLayout = new QGridLayout(CreateOthSType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        shortNameLb = new QLabel(CreateOthSType);
        shortNameLb->setObjectName(QStringLiteral("shortNameLb"));

        gridLayout->addWidget(shortNameLb, 1, 0, 1, 1);

        nameLb = new QLabel(CreateOthSType);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        nameEdit = new QLineEdit(CreateOthSType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateOthSType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateOthSType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        shortNameEdit = new QLineEdit(CreateOthSType);
        shortNameEdit->setObjectName(QStringLiteral("shortNameEdit"));

        gridLayout->addWidget(shortNameEdit, 1, 1, 1, 1);

        codeEdit = new QLineEdit(CreateOthSType);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        gridLayout->addWidget(codeEdit, 2, 1, 1, 1);

        codeLb = new QLabel(CreateOthSType);
        codeLb->setObjectName(QStringLiteral("codeLb"));

        gridLayout->addWidget(codeLb, 2, 0, 1, 1);

        QWidget::setTabOrder(nameEdit, shortNameEdit);
        QWidget::setTabOrder(shortNameEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateOthSType);

        QMetaObject::connectSlotsByName(CreateOthSType);
    } // setupUi

    void retranslateUi(QDialog *CreateOthSType)
    {
        CreateOthSType->setWindowTitle(QApplication::translate("CreateOthSType", "Create/Update other stocks type", 0));
        shortNameLb->setText(QApplication::translate("CreateOthSType", "Short name:", 0));
        nameLb->setText(QApplication::translate("CreateOthSType", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateOthSType", "<html><head/><body><p>For example: Dairy products</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateOthSType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateOthSType", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        shortNameEdit->setToolTip(QApplication::translate("CreateOthSType", "<html><head/><body><p>For example: Dairy</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateOthSType", "<html><head/><body><p>For example: PRODUCT</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        codeLb->setText(QApplication::translate("CreateOthSType", "Code:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOthSType: public Ui_CreateOthSType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEOTHSTYPEDLG_H
