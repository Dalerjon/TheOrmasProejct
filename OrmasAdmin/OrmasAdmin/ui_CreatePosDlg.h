/********************************************************************************
** Form generated from reading UI file 'CreatePosDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPOSDLG_H
#define UI_CREATEPOSDLG_H

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

class Ui_CreatePosition
{
public:
    QGridLayout *gridLayout;
    QLabel *positionLb;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CreatePosition)
    {
        if (CreatePosition->objectName().isEmpty())
            CreatePosition->setObjectName(QStringLiteral("CreatePosition"));
        CreatePosition->resize(400, 73);
        CreatePosition->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePosition->setModal(false);
        gridLayout = new QGridLayout(CreatePosition);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        positionLb = new QLabel(CreatePosition);
        positionLb->setObjectName(QStringLiteral("positionLb"));
        positionLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(positionLb, 1, 0, 1, 1);

        nameEdit = new QLineEdit(CreatePosition);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePosition);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePosition);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        QWidget::setTabOrder(nameEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePosition);

        QMetaObject::connectSlotsByName(CreatePosition);
    } // setupUi

    void retranslateUi(QDialog *CreatePosition)
    {
        CreatePosition->setWindowTitle(QApplication::translate("CreatePosition", "Create/Update position", 0));
        positionLb->setText(QApplication::translate("CreatePosition", "Position:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreatePosition", "<html><head/><body><p>For example: HR</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreatePosition", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePosition", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePosition: public Ui_CreatePosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPOSDLG_H
