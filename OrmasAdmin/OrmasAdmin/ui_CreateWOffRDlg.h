/********************************************************************************
** Form generated from reading UI file 'CreateWOffRDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWOFFRDLG_H
#define UI_CREATEWOFFRDLG_H

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

class Ui_CreateWriteOffR
{
public:
    QGridLayout *gridLayout;
    QLineEdit *currencyEdit;
    QLabel *sumLb;
    QLabel *dateLb;
    QLineEdit *stockEmployeeEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *employeeEdit;
    QDateTimeEdit *dateEdit;
    QLabel *prodCountLb;
    QPushButton *currencyBtn;
    QPushButton *employeeBtn;
    QPushButton *addProdBtn;
    QLineEdit *prodCountEdit;
    QLineEdit *sumEdit;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *stockEmployeeBtn;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;

    void setupUi(QDialog *CreateWriteOffR)
    {
        if (CreateWriteOffR->objectName().isEmpty())
            CreateWriteOffR->setObjectName(QStringLiteral("CreateWriteOffR"));
        CreateWriteOffR->resize(379, 250);
        CreateWriteOffR->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWriteOffR->setModal(false);
        gridLayout = new QGridLayout(CreateWriteOffR);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyEdit = new QLineEdit(CreateWriteOffR);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 7, 1, 1, 2);

        sumLb = new QLabel(CreateWriteOffR);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 6, 0, 1, 1);

        dateLb = new QLabel(CreateWriteOffR);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        stockEmployeeEdit = new QLineEdit(CreateWriteOffR);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 3, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWriteOffR);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWriteOffR);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        employeeEdit = new QLineEdit(CreateWriteOffR);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 1, 1, 2);

        dateEdit = new QDateTimeEdit(CreateWriteOffR);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        prodCountLb = new QLabel(CreateWriteOffR);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 4, 1, 1, 1);

        currencyBtn = new QPushButton(CreateWriteOffR);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 7, 0, 1, 1);

        employeeBtn = new QPushButton(CreateWriteOffR);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 1);

        addProdBtn = new QPushButton(CreateWriteOffR);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 4, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateWriteOffR);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 4, 2, 1, 1);

        sumEdit = new QLineEdit(CreateWriteOffR);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 6, 1, 1, 2);

        execDateWidget = new QWidget(CreateWriteOffR);
        execDateWidget->setObjectName(QStringLiteral("execDateWidget"));
        horizontalLayout_2 = new QHBoxLayout(execDateWidget);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(execDateWidget, 2, 0, 1, 3);

        stockEmployeeBtn = new QPushButton(CreateWriteOffR);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 3, 0, 1, 1);

        statusWidget = new QWidget(CreateWriteOffR);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBtn = new QPushButton(statusWidget);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy);
        statusBtn->setMinimumSize(QSize(197, 0));

        horizontalLayout_3->addWidget(statusBtn);

        statusEdit = new QLineEdit(statusWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(statusEdit);


        gridLayout->addWidget(statusWidget, 5, 0, 1, 3);

        QWidget::setTabOrder(employeeBtn, employeeEdit);
        QWidget::setTabOrder(employeeEdit, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, stockEmployeeEdit);
        QWidget::setTabOrder(stockEmployeeEdit, addProdBtn);
        QWidget::setTabOrder(addProdBtn, prodCountEdit);
        QWidget::setTabOrder(prodCountEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateWriteOffR);

        QMetaObject::connectSlotsByName(CreateWriteOffR);
    } // setupUi

    void retranslateUi(QDialog *CreateWriteOffR)
    {
        CreateWriteOffR->setWindowTitle(QApplication::translate("CreateWriteOffR", "Create/Update write-off raw", 0));
        sumLb->setText(QApplication::translate("CreateWriteOffR", "Total amount:", 0));
        dateLb->setText(QApplication::translate("CreateWriteOffR", "Write-off raw date:", 0));
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateWriteOffR", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateWriteOffR", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWriteOffR", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateWriteOffR", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        prodCountLb->setText(QApplication::translate("CreateWriteOffR", "Count of products:", 0));
        currencyBtn->setText(QApplication::translate("CreateWriteOffR", "Select currency", 0));
        employeeBtn->setText(QApplication::translate("CreateWriteOffR", "Select employee", 0));
        addProdBtn->setText(QApplication::translate("CreateWriteOffR", "Add products", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateWriteOffR", "Select stock employee", 0));
        statusBtn->setText(QApplication::translate("CreateWriteOffR", "Change status", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWriteOffR: public Ui_CreateWriteOffR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWOFFRDLG_H
