/********************************************************************************
** Form generated from reading UI file 'CreateOrdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDDLG_H
#define UI_CREATEORDDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_CreateOrder
{
public:
    QGridLayout *gridLayout;
    QDateEdit *dateEdit;
    QPushButton *userBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *userEdit;
    QLabel *dateLb;
    QPushButton *addProdBtn;
    QLineEdit *prodCountEdit;
    QPushButton *workerBtn;
    QPushButton *statusBtn;
    QLabel *prodCountLb;
    QPushButton *currencyBtn;
    QLineEdit *workerEdit;
    QLineEdit *sumEdit;
    QLineEdit *statusEdit;
    QLineEdit *currencyEdit;
    QLabel *sumLb;

    void setupUi(QDialog *CreateOrder)
    {
        if (CreateOrder->objectName().isEmpty())
            CreateOrder->setObjectName(QStringLiteral("CreateOrder"));
        CreateOrder->resize(422, 244);
        CreateOrder->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOrder->setModal(false);
        gridLayout = new QGridLayout(CreateOrder);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        dateEdit = new QDateEdit(CreateOrder);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        userBtn = new QPushButton(CreateOrder);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(userBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateOrder);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateOrder);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 3);

        userEdit = new QLineEdit(CreateOrder);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 0, 1, 1, 2);

        dateLb = new QLabel(CreateOrder);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        addProdBtn = new QPushButton(CreateOrder);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 3, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateOrder);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 3, 2, 1, 1);

        workerBtn = new QPushButton(CreateOrder);
        workerBtn->setObjectName(QStringLiteral("workerBtn"));

        gridLayout->addWidget(workerBtn, 2, 0, 1, 1);

        statusBtn = new QPushButton(CreateOrder);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout->addWidget(statusBtn, 4, 0, 1, 1);

        prodCountLb = new QLabel(CreateOrder);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 3, 1, 1, 1);

        currencyBtn = new QPushButton(CreateOrder);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 6, 0, 1, 1);

        workerEdit = new QLineEdit(CreateOrder);
        workerEdit->setObjectName(QStringLiteral("workerEdit"));
        workerEdit->setReadOnly(true);

        gridLayout->addWidget(workerEdit, 2, 1, 1, 2);

        sumEdit = new QLineEdit(CreateOrder);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout->addWidget(sumEdit, 5, 1, 1, 2);

        statusEdit = new QLineEdit(CreateOrder);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        gridLayout->addWidget(statusEdit, 4, 1, 1, 2);

        currencyEdit = new QLineEdit(CreateOrder);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));

        gridLayout->addWidget(currencyEdit, 6, 1, 1, 2);

        sumLb = new QLabel(CreateOrder);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 5, 0, 1, 1);

        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, workerBtn);
        QWidget::setTabOrder(workerBtn, workerEdit);
        QWidget::setTabOrder(workerEdit, addProdBtn);
        QWidget::setTabOrder(addProdBtn, prodCountEdit);
        QWidget::setTabOrder(prodCountEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateOrder);

        QMetaObject::connectSlotsByName(CreateOrder);
    } // setupUi

    void retranslateUi(QDialog *CreateOrder)
    {
        CreateOrder->setWindowTitle(QApplication::translate("CreateOrder", "Create/Update Order", 0));
        userBtn->setText(QApplication::translate("CreateOrder", "Select user", 0));
        okBtn->setText(QApplication::translate("CreateOrder", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateOrder", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateOrder", "Enter user ID", 0));
#endif // QT_NO_TOOLTIP
        dateLb->setText(QApplication::translate("CreateOrder", "Date of order:", 0));
        addProdBtn->setText(QApplication::translate("CreateOrder", "Add products", 0));
        workerBtn->setText(QApplication::translate("CreateOrder", "Select worker", 0));
        statusBtn->setText(QApplication::translate("CreateOrder", "Change status", 0));
        prodCountLb->setText(QApplication::translate("CreateOrder", "Count of products:", 0));
        currencyBtn->setText(QApplication::translate("CreateOrder", "Select currency", 0));
#ifndef QT_NO_TOOLTIP
        workerEdit->setToolTip(QApplication::translate("CreateOrder", "Enter worker ID", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateOrder", "Total amount:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOrder: public Ui_CreateOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDDLG_H
