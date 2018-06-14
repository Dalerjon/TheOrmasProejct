/********************************************************************************
** Form generated from reading UI file 'CreateEtrRtDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEETRRTDLG_H
#define UI_CREATEETRRTDLG_H

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

class Ui_CreateEntryRouting
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *operationLb;
    QLabel *caLb;
    QLineEdit *debitEdit;
    QLabel *daLb;
    QLineEdit *creditEdit;
    QLineEdit *operationEdit;

    void setupUi(QDialog *CreateEntryRouting)
    {
        if (CreateEntryRouting->objectName().isEmpty())
            CreateEntryRouting->setObjectName(QStringLiteral("CreateEntryRouting"));
        CreateEntryRouting->resize(379, 125);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateEntryRouting->sizePolicy().hasHeightForWidth());
        CreateEntryRouting->setSizePolicy(sizePolicy);
        CreateEntryRouting->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateEntryRouting->setModal(false);
        gridLayout = new QGridLayout(CreateEntryRouting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateEntryRouting);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateEntryRouting);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 4);

        operationLb = new QLabel(CreateEntryRouting);
        operationLb->setObjectName(QStringLiteral("operationLb"));
        operationLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(operationLb, 0, 0, 1, 1);

        caLb = new QLabel(CreateEntryRouting);
        caLb->setObjectName(QStringLiteral("caLb"));

        gridLayout->addWidget(caLb, 2, 0, 1, 1);

        debitEdit = new QLineEdit(CreateEntryRouting);
        debitEdit->setObjectName(QStringLiteral("debitEdit"));
        debitEdit->setMinimumSize(QSize(0, 0));
        debitEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(debitEdit, 1, 1, 1, 1);

        daLb = new QLabel(CreateEntryRouting);
        daLb->setObjectName(QStringLiteral("daLb"));

        gridLayout->addWidget(daLb, 1, 0, 1, 1);

        creditEdit = new QLineEdit(CreateEntryRouting);
        creditEdit->setObjectName(QStringLiteral("creditEdit"));
        creditEdit->setMinimumSize(QSize(0, 0));
        creditEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(creditEdit, 2, 1, 1, 1);

        operationEdit = new QLineEdit(CreateEntryRouting);
        operationEdit->setObjectName(QStringLiteral("operationEdit"));

        gridLayout->addWidget(operationEdit, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateEntryRouting);

        QMetaObject::connectSlotsByName(CreateEntryRouting);
    } // setupUi

    void retranslateUi(QDialog *CreateEntryRouting)
    {
        CreateEntryRouting->setWindowTitle(QApplication::translate("CreateEntryRouting", "Create account routing", 0));
        okBtn->setText(QApplication::translate("CreateEntryRouting", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateEntryRouting", "Cancel", 0));
        operationLb->setText(QApplication::translate("CreateEntryRouting", "Operation:", 0));
        caLb->setText(QApplication::translate("CreateEntryRouting", "Credit:", 0));
        debitEdit->setText(QString());
        daLb->setText(QApplication::translate("CreateEntryRouting", "Debit:", 0));
        creditEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateEntryRouting: public Ui_CreateEntryRouting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEETRRTDLG_H
