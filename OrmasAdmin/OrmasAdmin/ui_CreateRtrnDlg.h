/********************************************************************************
** Form generated from reading UI file 'CreateRtrnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERTRNDLG_H
#define UI_CREATERTRNDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateReturn
{
public:
    QGridLayout *gridLayout;
    QLineEdit *currencyEdit;
    QPushButton *currencyBtn;
    QLabel *prodCountLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *clientBtn;
    QPushButton *employeeBtn;
    QLabel *sumLb;
    QLineEdit *employeeEdit;
    QLineEdit *sumEdit;
    QPushButton *addProdBtn;
    QLineEdit *prodCountEdit;
    QLineEdit *clientEdit;
    QLabel *dateLb;
    QLineEdit *statusEdit;
    QPushButton *statusBtn;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QDateTimeEdit *execDateEdit;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateReturn)
    {
        if (CreateReturn->objectName().isEmpty())
            CreateReturn->setObjectName(QStringLiteral("CreateReturn"));
        CreateReturn->resize(422, 270);
        CreateReturn->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateReturn->setModal(false);
        gridLayout = new QGridLayout(CreateReturn);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyEdit = new QLineEdit(CreateReturn);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(false);

        gridLayout->addWidget(currencyEdit, 7, 1, 1, 2);

        currencyBtn = new QPushButton(CreateReturn);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 7, 0, 1, 1);

        prodCountLb = new QLabel(CreateReturn);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateReturn);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateReturn);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        clientBtn = new QPushButton(CreateReturn);
        clientBtn->setObjectName(QStringLiteral("clientBtn"));
        clientBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(clientBtn, 0, 0, 1, 1);

        employeeBtn = new QPushButton(CreateReturn);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 3, 0, 1, 1);

        sumLb = new QLabel(CreateReturn);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 6, 0, 1, 1);

        employeeEdit = new QLineEdit(CreateReturn);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 3, 1, 1, 2);

        sumEdit = new QLineEdit(CreateReturn);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 6, 1, 1, 2);

        addProdBtn = new QPushButton(CreateReturn);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 4, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateReturn);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 4, 2, 1, 1);

        clientEdit = new QLineEdit(CreateReturn);
        clientEdit->setObjectName(QStringLiteral("clientEdit"));
        clientEdit->setReadOnly(true);

        gridLayout->addWidget(clientEdit, 0, 1, 1, 2);

        dateLb = new QLabel(CreateReturn);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        statusEdit = new QLineEdit(CreateReturn);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout->addWidget(statusEdit, 5, 1, 1, 2);

        statusBtn = new QPushButton(CreateReturn);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout->addWidget(statusBtn, 5, 0, 1, 1);

        execDateWidget = new QWidget(CreateReturn);
        execDateWidget->setObjectName(QStringLiteral("execDateWidget"));
        horizontalLayout_2 = new QHBoxLayout(execDateWidget);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        execDateLb = new QLabel(execDateWidget);
        execDateLb->setObjectName(QStringLiteral("execDateLb"));

        horizontalLayout_2->addWidget(execDateLb);

        execDateEdit = new QDateTimeEdit(execDateWidget);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));

        horizontalLayout_2->addWidget(execDateEdit);


        gridLayout->addWidget(execDateWidget, 2, 0, 1, 3);

        dateEdit = new QDateTimeEdit(CreateReturn);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        QWidget::setTabOrder(clientBtn, clientEdit);
        QWidget::setTabOrder(clientEdit, employeeBtn);
        QWidget::setTabOrder(employeeBtn, employeeEdit);
        QWidget::setTabOrder(employeeEdit, addProdBtn);
        QWidget::setTabOrder(addProdBtn, prodCountEdit);
        QWidget::setTabOrder(prodCountEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateReturn);

        QMetaObject::connectSlotsByName(CreateReturn);
    } // setupUi

    void retranslateUi(QDialog *CreateReturn)
    {
        CreateReturn->setWindowTitle(QApplication::translate("CreateReturn", "Create/Update return", 0));
        currencyBtn->setText(QApplication::translate("CreateReturn", "Select currency", 0));
        prodCountLb->setText(QApplication::translate("CreateReturn", "Count of products:", 0));
        okBtn->setText(QApplication::translate("CreateReturn", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateReturn", "Cancel", 0));
        clientBtn->setText(QApplication::translate("CreateReturn", "Select client", 0));
        employeeBtn->setText(QApplication::translate("CreateReturn", "Select employee", 0));
        sumLb->setText(QApplication::translate("CreateReturn", "Total amount:", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateReturn", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addProdBtn->setText(QApplication::translate("CreateReturn", "Add products", 0));
#ifndef QT_NO_TOOLTIP
        clientEdit->setToolTip(QApplication::translate("CreateReturn", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        dateLb->setText(QApplication::translate("CreateReturn", "Return date:", 0));
        statusBtn->setText(QApplication::translate("CreateReturn", "Change status", 0));
        execDateLb->setText(QApplication::translate("CreateReturn", "Execution date:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateReturn: public Ui_CreateReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERTRNDLG_H
