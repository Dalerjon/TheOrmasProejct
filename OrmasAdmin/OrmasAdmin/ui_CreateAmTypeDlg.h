/********************************************************************************
** Form generated from reading UI file 'CreateAmTypeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEAMTYPEDLG_H
#define UI_CREATEAMTYPEDLG_H

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

class Ui_CreateAmortizeType
{
public:
    QGridLayout *gridLayout;
    QLabel *codeLb;
    QLineEdit *codeEdit;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;

    void setupUi(QDialog *CreateAmortizeType)
    {
        if (CreateAmortizeType->objectName().isEmpty())
            CreateAmortizeType->setObjectName(QStringLiteral("CreateAmortizeType"));
        CreateAmortizeType->resize(461, 99);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateAmortizeType->sizePolicy().hasHeightForWidth());
        CreateAmortizeType->setSizePolicy(sizePolicy);
        CreateAmortizeType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateAmortizeType->setModal(false);
        gridLayout = new QGridLayout(CreateAmortizeType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        codeLb = new QLabel(CreateAmortizeType);
        codeLb->setObjectName(QStringLiteral("codeLb"));

        gridLayout->addWidget(codeLb, 1, 0, 1, 1);

        codeEdit = new QLineEdit(CreateAmortizeType);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        gridLayout->addWidget(codeEdit, 1, 1, 1, 1);

        nameEdit = new QLineEdit(CreateAmortizeType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateAmortizeType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateAmortizeType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        nameLb = new QLabel(CreateAmortizeType);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLb->sizePolicy().hasHeightForWidth());
        nameLb->setSizePolicy(sizePolicy1);
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        QWidget::setTabOrder(nameEdit, codeEdit);
        QWidget::setTabOrder(codeEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateAmortizeType);

        QMetaObject::connectSlotsByName(CreateAmortizeType);
    } // setupUi

    void retranslateUi(QDialog *CreateAmortizeType)
    {
        CreateAmortizeType->setWindowTitle(QApplication::translate("CreateAmortizeType", "Create/Update amortize type", 0));
        codeLb->setText(QApplication::translate("CreateAmortizeType", "Code:", 0));
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateAmortizeType", "<html><head/><body><p>For example: Main St. 99</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateAmortizeType", "<html><head/><body><p>For example: &quot;River Co.&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateAmortizeType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateAmortizeType", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateAmortizeType", "Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAmortizeType: public Ui_CreateAmortizeType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEAMTYPEDLG_H
