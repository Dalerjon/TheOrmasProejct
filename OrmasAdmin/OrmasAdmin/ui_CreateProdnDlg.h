/********************************************************************************
** Form generated from reading UI file 'CreateProdnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPRODNDLG_H
#define UI_CREATEPRODNDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateProduction
{
public:
    QGridLayout *gridLayout;
    QLineEdit *prodCountEdit;
    QLabel *expiryDateLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *sessionStartLb;
    QLabel *SessionEndLb;
    QPushButton *addProdBtn;
    QLabel *productionDateLb;
    QLabel *prodCountLb;
    QTimeEdit *sesEndTimeEdit;
    QTimeEdit *sesStartTimeEdit;
    QDateEdit *prdDateEdit;
    QDateEdit *expiryDateEdit;

    void setupUi(QDialog *CreateProduction)
    {
        if (CreateProduction->objectName().isEmpty())
            CreateProduction->setObjectName(QStringLiteral("CreateProduction"));
        CreateProduction->resize(396, 176);
        CreateProduction->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateProduction->setModal(false);
        gridLayout = new QGridLayout(CreateProduction);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        prodCountEdit = new QLineEdit(CreateProduction);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 4, 2, 1, 1);

        expiryDateLb = new QLabel(CreateProduction);
        expiryDateLb->setObjectName(QStringLiteral("expiryDateLb"));
        expiryDateLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(expiryDateLb, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateProduction);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateProduction);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 3);

        sessionStartLb = new QLabel(CreateProduction);
        sessionStartLb->setObjectName(QStringLiteral("sessionStartLb"));

        gridLayout->addWidget(sessionStartLb, 2, 0, 1, 1);

        SessionEndLb = new QLabel(CreateProduction);
        SessionEndLb->setObjectName(QStringLiteral("SessionEndLb"));

        gridLayout->addWidget(SessionEndLb, 3, 0, 1, 1);

        addProdBtn = new QPushButton(CreateProduction);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 4, 0, 1, 1);

        productionDateLb = new QLabel(CreateProduction);
        productionDateLb->setObjectName(QStringLiteral("productionDateLb"));

        gridLayout->addWidget(productionDateLb, 0, 0, 1, 1);

        prodCountLb = new QLabel(CreateProduction);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));
        prodCountLb->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(prodCountLb, 4, 1, 1, 1);

        sesEndTimeEdit = new QTimeEdit(CreateProduction);
        sesEndTimeEdit->setObjectName(QStringLiteral("sesEndTimeEdit"));

        gridLayout->addWidget(sesEndTimeEdit, 3, 1, 1, 2);

        sesStartTimeEdit = new QTimeEdit(CreateProduction);
        sesStartTimeEdit->setObjectName(QStringLiteral("sesStartTimeEdit"));

        gridLayout->addWidget(sesStartTimeEdit, 2, 1, 1, 2);

        prdDateEdit = new QDateEdit(CreateProduction);
        prdDateEdit->setObjectName(QStringLiteral("prdDateEdit"));

        gridLayout->addWidget(prdDateEdit, 0, 1, 1, 2);

        expiryDateEdit = new QDateEdit(CreateProduction);
        expiryDateEdit->setObjectName(QStringLiteral("expiryDateEdit"));

        gridLayout->addWidget(expiryDateEdit, 1, 1, 1, 2);

        QWidget::setTabOrder(sesStartTimeEdit, sesEndTimeEdit);
        QWidget::setTabOrder(sesEndTimeEdit, addProdBtn);
        QWidget::setTabOrder(addProdBtn, prodCountEdit);
        QWidget::setTabOrder(prodCountEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateProduction);

        QMetaObject::connectSlotsByName(CreateProduction);
    } // setupUi

    void retranslateUi(QDialog *CreateProduction)
    {
        CreateProduction->setWindowTitle(QApplication::translate("CreateProduction", "Create/Update production", 0));
        expiryDateLb->setText(QApplication::translate("CreateProduction", "Expiry date:", 0));
        okBtn->setText(QApplication::translate("CreateProduction", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateProduction", "Cancel", 0));
        sessionStartLb->setText(QApplication::translate("CreateProduction", "Session start time:", 0));
        SessionEndLb->setText(QApplication::translate("CreateProduction", "Session end time:", 0));
        addProdBtn->setText(QApplication::translate("CreateProduction", "Add products", 0));
        productionDateLb->setText(QApplication::translate("CreateProduction", "Production date:", 0));
        prodCountLb->setText(QApplication::translate("CreateProduction", "Product count:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateProduction: public Ui_CreateProduction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRODNDLG_H
