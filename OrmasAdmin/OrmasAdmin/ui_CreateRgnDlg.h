/********************************************************************************
** Form generated from reading UI file 'CreateRgnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERGNDLG_H
#define UI_CREATERGNDLG_H

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

class Ui_CreateRegion
{
public:
    QGridLayout *gridLayout;
    QLabel *codeLb;
    QLabel *nameLb;
    QLineEdit *CodeEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cencalBtn;
    QLineEdit *nameEdit;

    void setupUi(QDialog *CreateRegion)
    {
        if (CreateRegion->objectName().isEmpty())
            CreateRegion->setObjectName(QStringLiteral("CreateRegion"));
        CreateRegion->resize(400, 99);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateRegion->sizePolicy().hasHeightForWidth());
        CreateRegion->setSizePolicy(sizePolicy);
        CreateRegion->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRegion->setModal(true);
        gridLayout = new QGridLayout(CreateRegion);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        codeLb = new QLabel(CreateRegion);
        codeLb->setObjectName(QStringLiteral("codeLb"));
        codeLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(codeLb, 0, 0, 1, 1);

        nameLb = new QLabel(CreateRegion);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        CodeEdit = new QLineEdit(CreateRegion);
        CodeEdit->setObjectName(QStringLiteral("CodeEdit"));

        gridLayout->addWidget(CodeEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateRegion);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cencalBtn = new QPushButton(CreateRegion);
        cencalBtn->setObjectName(QStringLiteral("cencalBtn"));

        horizontalLayout->addWidget(cencalBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        nameEdit = new QLineEdit(CreateRegion);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);


        retranslateUi(CreateRegion);

        QMetaObject::connectSlotsByName(CreateRegion);
    } // setupUi

    void retranslateUi(QDialog *CreateRegion)
    {
        CreateRegion->setWindowTitle(QApplication::translate("CreateRegion", "Create/Update region", 0));
        codeLb->setText(QApplication::translate("CreateRegion", "Code:", 0));
        nameLb->setText(QApplication::translate("CreateRegion", "Name:", 0));
        okBtn->setText(QApplication::translate("CreateRegion", "OK", 0));
        cencalBtn->setText(QApplication::translate("CreateRegion", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateRegion: public Ui_CreateRegion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERGNDLG_H
