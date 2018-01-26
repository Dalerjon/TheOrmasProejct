/********************************************************************************
** Form generated from reading UI file 'CreateTrsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETRSDLG_H
#define UI_CREATETRSDLG_H

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

class Ui_CreateTransport
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

    void setupUi(QDialog *CreateTransport)
    {
        if (CreateTransport->objectName().isEmpty())
            CreateTransport->setObjectName(QStringLiteral("CreateTransport"));
        CreateTransport->resize(379, 270);
        CreateTransport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateTransport->setModal(false);
        gridLayout = new QGridLayout(CreateTransport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyEdit = new QLineEdit(CreateTransport);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 7, 1, 1, 2);

        sumLb = new QLabel(CreateTransport);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 6, 0, 1, 1);

        dateLb = new QLabel(CreateTransport);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        stockEmployeeEdit = new QLineEdit(CreateTransport);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 3, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateTransport);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateTransport);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        employeeEdit = new QLineEdit(CreateTransport);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 1, 1, 2);

        dateEdit = new QDateTimeEdit(CreateTransport);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        prodCountLb = new QLabel(CreateTransport);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 4, 1, 1, 1);

        currencyBtn = new QPushButton(CreateTransport);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 7, 0, 1, 1);

        employeeBtn = new QPushButton(CreateTransport);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 1);

        addProdBtn = new QPushButton(CreateTransport);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 4, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateTransport);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 4, 2, 1, 1);

        sumEdit = new QLineEdit(CreateTransport);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 6, 1, 1, 2);

        execDateWidget = new QWidget(CreateTransport);
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

        stockEmployeeBtn = new QPushButton(CreateTransport);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 3, 0, 1, 1);

        statusWidget = new QWidget(CreateTransport);
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

        retranslateUi(CreateTransport);

        QMetaObject::connectSlotsByName(CreateTransport);
    } // setupUi

    void retranslateUi(QDialog *CreateTransport)
    {
        CreateTransport->setWindowTitle(QApplication::translate("CreateTransport", "Create/Update transport", 0));
        sumLb->setText(QApplication::translate("CreateTransport", "Total amount:", 0));
        dateLb->setText(QApplication::translate("CreateTransport", "Transportation date:", 0));
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateTransport", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateTransport", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateTransport", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateTransport", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        prodCountLb->setText(QApplication::translate("CreateTransport", "Count of products:", 0));
        currencyBtn->setText(QApplication::translate("CreateTransport", "Select currency", 0));
        employeeBtn->setText(QApplication::translate("CreateTransport", "Select employee", 0));
        addProdBtn->setText(QApplication::translate("CreateTransport", "Add products", 0));
        execDateLb->setText(QApplication::translate("CreateTransport", "Execution date:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateTransport", "Select stock employee", 0));
        statusBtn->setText(QApplication::translate("CreateTransport", "Change status", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateTransport: public Ui_CreateTransport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETRSDLG_H
