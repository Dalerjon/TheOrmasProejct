/********************************************************************************
** Form generated from reading UI file 'CreateRelDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERELDLG_H
#define UI_CREATERELDLG_H

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

class Ui_CreateRelation
{
public:
    QGridLayout *gridLayout;
    QPushButton *user2Btn;
    QLineEdit *user2Edit;
    QLineEdit *user1Edit;
    QPushButton *relTypeBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *user1Btn;
    QLineEdit *relTypeEdit;

    void setupUi(QDialog *CreateRelation)
    {
        if (CreateRelation->objectName().isEmpty())
            CreateRelation->setObjectName(QStringLiteral("CreateRelation"));
        CreateRelation->resize(400, 134);
        CreateRelation->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRelation->setModal(false);
        gridLayout = new QGridLayout(CreateRelation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        user2Btn = new QPushButton(CreateRelation);
        user2Btn->setObjectName(QStringLiteral("user2Btn"));

        gridLayout->addWidget(user2Btn, 4, 0, 1, 1);

        user2Edit = new QLineEdit(CreateRelation);
        user2Edit->setObjectName(QStringLiteral("user2Edit"));
        user2Edit->setReadOnly(true);

        gridLayout->addWidget(user2Edit, 4, 1, 1, 1);

        user1Edit = new QLineEdit(CreateRelation);
        user1Edit->setObjectName(QStringLiteral("user1Edit"));
        user1Edit->setReadOnly(true);

        gridLayout->addWidget(user1Edit, 1, 1, 1, 1);

        relTypeBtn = new QPushButton(CreateRelation);
        relTypeBtn->setObjectName(QStringLiteral("relTypeBtn"));
        relTypeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(relTypeBtn, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateRelation);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateRelation);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 2);

        user1Btn = new QPushButton(CreateRelation);
        user1Btn->setObjectName(QStringLiteral("user1Btn"));

        gridLayout->addWidget(user1Btn, 1, 0, 1, 1);

        relTypeEdit = new QLineEdit(CreateRelation);
        relTypeEdit->setObjectName(QStringLiteral("relTypeEdit"));
        relTypeEdit->setReadOnly(true);

        gridLayout->addWidget(relTypeEdit, 5, 1, 1, 1);

        QWidget::setTabOrder(user1Btn, user1Edit);
        QWidget::setTabOrder(user1Edit, user2Btn);
        QWidget::setTabOrder(user2Btn, user2Edit);
        QWidget::setTabOrder(user2Edit, relTypeBtn);
        QWidget::setTabOrder(relTypeBtn, relTypeEdit);
        QWidget::setTabOrder(relTypeEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateRelation);

        QMetaObject::connectSlotsByName(CreateRelation);
    } // setupUi

    void retranslateUi(QDialog *CreateRelation)
    {
        CreateRelation->setWindowTitle(QApplication::translate("CreateRelation", "Create/Update relation", 0));
        user2Btn->setText(QApplication::translate("CreateRelation", "Select second user", 0));
        relTypeBtn->setText(QApplication::translate("CreateRelation", "Select relation type", 0));
        okBtn->setText(QApplication::translate("CreateRelation", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateRelation", "Cancel", 0));
        user1Btn->setText(QApplication::translate("CreateRelation", "Select first user", 0));
#ifndef QT_NO_TOOLTIP
        relTypeEdit->setToolTip(QApplication::translate("CreateRelation", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateRelation: public Ui_CreateRelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERELDLG_H
