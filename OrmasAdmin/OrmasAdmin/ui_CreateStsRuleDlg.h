/********************************************************************************
** Form generated from reading UI file 'CreateStsRuleDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESTSRULEDLG_H
#define UI_CREATESTSRULEDLG_H

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

class Ui_CreateStatusRule
{
public:
    QGridLayout *gridLayout;
    QLabel *operationLb;
    QPushButton *statusBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *operationEdit;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;

    void setupUi(QDialog *CreateStatusRule)
    {
        if (CreateStatusRule->objectName().isEmpty())
            CreateStatusRule->setObjectName(QStringLiteral("CreateStatusRule"));
        CreateStatusRule->resize(401, 128);
        CreateStatusRule->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateStatusRule->setModal(false);
        gridLayout = new QGridLayout(CreateStatusRule);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        operationLb = new QLabel(CreateStatusRule);
        operationLb->setObjectName(QStringLiteral("operationLb"));
        operationLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(operationLb, 0, 0, 1, 1);

        statusBtn = new QPushButton(CreateStatusRule);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy);
        statusBtn->setMinimumSize(QSize(197, 0));

        gridLayout->addWidget(statusBtn, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateStatusRule);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateStatusRule);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);

        operationEdit = new QLineEdit(CreateStatusRule);
        operationEdit->setObjectName(QStringLiteral("operationEdit"));

        gridLayout->addWidget(operationEdit, 0, 1, 1, 1);

        statusEdit = new QLineEdit(CreateStatusRule);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout->addWidget(statusEdit, 2, 1, 1, 1);

        statusLb = new QLabel(CreateStatusRule);
        statusLb->setObjectName(QStringLiteral("statusLb"));

        gridLayout->addWidget(statusLb, 3, 0, 1, 1);

        statusPh = new QLabel(CreateStatusRule);
        statusPh->setObjectName(QStringLiteral("statusPh"));
        statusPh->setMinimumSize(QSize(120, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusPh->setFont(font);

        gridLayout->addWidget(statusPh, 3, 1, 1, 1);

        QWidget::setTabOrder(operationEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateStatusRule);

        QMetaObject::connectSlotsByName(CreateStatusRule);
    } // setupUi

    void retranslateUi(QDialog *CreateStatusRule)
    {
        CreateStatusRule->setWindowTitle(QApplication::translate("CreateStatusRule", "Create/Update status rule", 0));
        operationLb->setText(QApplication::translate("CreateStatusRule", "Operation:", 0));
        statusBtn->setText(QApplication::translate("CreateStatusRule", "Select status", 0));
        okBtn->setText(QApplication::translate("CreateStatusRule", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateStatusRule", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        operationEdit->setToolTip(QApplication::translate("CreateStatusRule", "<html><head/><body><p>For example: ORDER</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        statusLb->setText(QApplication::translate("CreateStatusRule", "Status name:", 0));
        statusPh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateStatusRule: public Ui_CreateStatusRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESTSRULEDLG_H
