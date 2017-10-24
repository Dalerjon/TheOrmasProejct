/********************************************************************************
** Form generated from reading UI file 'CreateAcsItemDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACSITEMDLG_H
#define UI_CREATEACSITEMDLG_H

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

class Ui_CreateAccessItem
{
public:
    QGridLayout *gridLayout;
    QLabel *ruNameLb;
    QLineEdit *nameEngEdit;
    QLabel *engNameLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *nameRuEdit;
    QLabel *divisionLb;
    QLineEdit *divisionEdit;

    void setupUi(QDialog *CreateAccessItem)
    {
        if (CreateAccessItem->objectName().isEmpty())
            CreateAccessItem->setObjectName(QStringLiteral("CreateAccessItem"));
        CreateAccessItem->resize(400, 125);
        CreateAccessItem->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateAccessItem->setModal(false);
        gridLayout = new QGridLayout(CreateAccessItem);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        ruNameLb = new QLabel(CreateAccessItem);
        ruNameLb->setObjectName(QStringLiteral("ruNameLb"));

        gridLayout->addWidget(ruNameLb, 1, 0, 1, 1);

        nameEngEdit = new QLineEdit(CreateAccessItem);
        nameEngEdit->setObjectName(QStringLiteral("nameEngEdit"));

        gridLayout->addWidget(nameEngEdit, 0, 1, 1, 1);

        engNameLb = new QLabel(CreateAccessItem);
        engNameLb->setObjectName(QStringLiteral("engNameLb"));
        engNameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(engNameLb, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateAccessItem);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateAccessItem);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        nameRuEdit = new QLineEdit(CreateAccessItem);
        nameRuEdit->setObjectName(QStringLiteral("nameRuEdit"));

        gridLayout->addWidget(nameRuEdit, 1, 1, 1, 1);

        divisionLb = new QLabel(CreateAccessItem);
        divisionLb->setObjectName(QStringLiteral("divisionLb"));

        gridLayout->addWidget(divisionLb, 2, 0, 1, 1);

        divisionEdit = new QLineEdit(CreateAccessItem);
        divisionEdit->setObjectName(QStringLiteral("divisionEdit"));

        gridLayout->addWidget(divisionEdit, 2, 1, 1, 1);

        QWidget::setTabOrder(nameEngEdit, nameRuEdit);
        QWidget::setTabOrder(nameRuEdit, divisionEdit);
        QWidget::setTabOrder(divisionEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateAccessItem);

        QMetaObject::connectSlotsByName(CreateAccessItem);
    } // setupUi

    void retranslateUi(QDialog *CreateAccessItem)
    {
        CreateAccessItem->setWindowTitle(QApplication::translate("CreateAccessItem", "Create/Update access item", 0));
        ruNameLb->setText(QApplication::translate("CreateAccessItem", "Russian Name:", 0));
#ifndef QT_NO_TOOLTIP
        nameEngEdit->setToolTip(QApplication::translate("CreateAccessItem", "<html><head/><body><p>For example: Creation</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        engNameLb->setText(QApplication::translate("CreateAccessItem", "English name:", 0));
        okBtn->setText(QApplication::translate("CreateAccessItem", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateAccessItem", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        nameRuEdit->setToolTip(QApplication::translate("CreateAccessItem", "<html><head/><body><p>For example: \321\201\320\276\320\267\320\264\320\260\320\275\320\270\320\265</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        divisionLb->setText(QApplication::translate("CreateAccessItem", "Division", 0));
#ifndef QT_NO_TOOLTIP
        divisionEdit->setToolTip(QApplication::translate("CreateAccessItem", "<html><head/><body><p>For example: ACTION</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateAccessItem: public Ui_CreateAccessItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACSITEMDLG_H
