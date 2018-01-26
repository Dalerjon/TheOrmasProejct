/********************************************************************************
** Form generated from reading UI file 'CreateRcpRDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERCPRDLG_H
#define UI_CREATERCPRDLG_H

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

class Ui_CreateReceiptRaw
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
    QLabel *execDateLb;
    QDateTimeEdit *execDateEdit;
    QPushButton *stockEmployeeBtn;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;

    void setupUi(QDialog *CreateReceiptRaw)
    {
        if (CreateReceiptRaw->objectName().isEmpty())
            CreateReceiptRaw->setObjectName(QStringLiteral("CreateReceiptRaw"));
        CreateReceiptRaw->resize(379, 270);
        CreateReceiptRaw->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateReceiptRaw->setModal(false);
        gridLayout = new QGridLayout(CreateReceiptRaw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyEdit = new QLineEdit(CreateReceiptRaw);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 7, 1, 1, 2);

        sumLb = new QLabel(CreateReceiptRaw);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 6, 0, 1, 1);

        dateLb = new QLabel(CreateReceiptRaw);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        stockEmployeeEdit = new QLineEdit(CreateReceiptRaw);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 3, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateReceiptRaw);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateReceiptRaw);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        employeeEdit = new QLineEdit(CreateReceiptRaw);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 1, 1, 2);

        dateEdit = new QDateTimeEdit(CreateReceiptRaw);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        prodCountLb = new QLabel(CreateReceiptRaw);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 4, 1, 1, 1);

        currencyBtn = new QPushButton(CreateReceiptRaw);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 7, 0, 1, 1);

        employeeBtn = new QPushButton(CreateReceiptRaw);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 1);

        addProdBtn = new QPushButton(CreateReceiptRaw);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 4, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateReceiptRaw);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 4, 2, 1, 1);

        sumEdit = new QLineEdit(CreateReceiptRaw);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 6, 1, 1, 2);

        execDateWidget = new QWidget(CreateReceiptRaw);
        execDateWidget->setObjectName(QStringLiteral("execDateWidget"));
        horizontalLayout_2 = new QHBoxLayout(execDateWidget);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        execDateLb = new QLabel(execDateWidget);
        execDateLb->setObjectName(QStringLiteral("execDateLb"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(execDateLb->sizePolicy().hasHeightForWidth());
        execDateLb->setSizePolicy(sizePolicy);
        execDateLb->setMinimumSize(QSize(197, 0));

        horizontalLayout_2->addWidget(execDateLb);

        execDateEdit = new QDateTimeEdit(execDateWidget);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));

        horizontalLayout_2->addWidget(execDateEdit);


        gridLayout->addWidget(execDateWidget, 2, 0, 1, 3);

        stockEmployeeBtn = new QPushButton(CreateReceiptRaw);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 3, 0, 1, 1);

        statusWidget = new QWidget(CreateReceiptRaw);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBtn = new QPushButton(statusWidget);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy1);
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

        retranslateUi(CreateReceiptRaw);

        QMetaObject::connectSlotsByName(CreateReceiptRaw);
    } // setupUi

    void retranslateUi(QDialog *CreateReceiptRaw)
    {
        CreateReceiptRaw->setWindowTitle(QApplication::translate("CreateReceiptRaw", "Create/Update receipt raw", 0));
        sumLb->setText(QApplication::translate("CreateReceiptRaw", "Total amount:", 0));
        dateLb->setText(QApplication::translate("CreateReceiptRaw", "Consume receipt raw date:", 0));
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateReceiptRaw", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateReceiptRaw", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateReceiptRaw", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateReceiptRaw", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        prodCountLb->setText(QApplication::translate("CreateReceiptRaw", "Count of products:", 0));
        currencyBtn->setText(QApplication::translate("CreateReceiptRaw", "Select currency", 0));
        employeeBtn->setText(QApplication::translate("CreateReceiptRaw", "Select employee", 0));
        addProdBtn->setText(QApplication::translate("CreateReceiptRaw", "Add products", 0));
        execDateLb->setText(QApplication::translate("CreateReceiptRaw", "Execution date:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateReceiptRaw", "Select stock employee", 0));
        statusBtn->setText(QApplication::translate("CreateReceiptRaw", "Change status", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateReceiptRaw: public Ui_CreateReceiptRaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERCPRDLG_H
