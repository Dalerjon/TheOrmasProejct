/********************************************************************************
** Form generated from reading UI file 'CreateWOffDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWOFFDLG_H
#define UI_CREATEWOFFDLG_H

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

class Ui_CreateWriteOff
{
public:
    QGridLayout *gridLayout;
    QDateEdit *dateEdit;
    QPushButton *clientBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *clientEdit;
    QLabel *dateLb;
    QPushButton *addProdBtn;
    QLineEdit *prodCountEdit;
    QPushButton *employeeBtn;
    QPushButton *statusBtn;
    QLabel *prodCountLb;
    QPushButton *currencyBtn;
    QLineEdit *employeeEdit;
    QLineEdit *sumEdit;
    QLineEdit *statusEdit;
    QLineEdit *currencyEdit;
    QLabel *sumLb;

    void setupUi(QDialog *CreateWriteOff)
    {
        if (CreateWriteOff->objectName().isEmpty())
            CreateWriteOff->setObjectName(QStringLiteral("CreateWriteOff"));
        CreateWriteOff->resize(422, 244);
        CreateWriteOff->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWriteOff->setModal(false);
        gridLayout = new QGridLayout(CreateWriteOff);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        dateEdit = new QDateEdit(CreateWriteOff);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        clientBtn = new QPushButton(CreateWriteOff);
        clientBtn->setObjectName(QStringLiteral("clientBtn"));
        clientBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(clientBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWriteOff);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWriteOff);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 3);

        clientEdit = new QLineEdit(CreateWriteOff);
        clientEdit->setObjectName(QStringLiteral("clientEdit"));
        clientEdit->setReadOnly(true);

        gridLayout->addWidget(clientEdit, 0, 1, 1, 2);

        dateLb = new QLabel(CreateWriteOff);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        addProdBtn = new QPushButton(CreateWriteOff);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 3, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateWriteOff);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 3, 2, 1, 1);

        employeeBtn = new QPushButton(CreateWriteOff);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 2, 0, 1, 1);

        statusBtn = new QPushButton(CreateWriteOff);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout->addWidget(statusBtn, 4, 0, 1, 1);

        prodCountLb = new QLabel(CreateWriteOff);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 3, 1, 1, 1);

        currencyBtn = new QPushButton(CreateWriteOff);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 6, 0, 1, 1);

        employeeEdit = new QLineEdit(CreateWriteOff);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 2, 1, 1, 2);

        sumEdit = new QLineEdit(CreateWriteOff);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 5, 1, 1, 2);

        statusEdit = new QLineEdit(CreateWriteOff);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout->addWidget(statusEdit, 4, 1, 1, 2);

        currencyEdit = new QLineEdit(CreateWriteOff);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout->addWidget(currencyEdit, 6, 1, 1, 2);

        sumLb = new QLabel(CreateWriteOff);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 5, 0, 1, 1);

        QWidget::setTabOrder(clientBtn, clientEdit);
        QWidget::setTabOrder(clientEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, employeeBtn);
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

        retranslateUi(CreateWriteOff);

        QMetaObject::connectSlotsByName(CreateWriteOff);
    } // setupUi

    void retranslateUi(QDialog *CreateWriteOff)
    {
        CreateWriteOff->setWindowTitle(QApplication::translate("CreateWriteOff", "Create/Update Write-off", 0));
        clientBtn->setText(QApplication::translate("CreateWriteOff", "Select client", 0));
        okBtn->setText(QApplication::translate("CreateWriteOff", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWriteOff", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        clientEdit->setToolTip(QApplication::translate("CreateWriteOff", "Enter user ID", 0));
#endif // QT_NO_TOOLTIP
        dateLb->setText(QApplication::translate("CreateWriteOff", "Date of write-off:", 0));
        addProdBtn->setText(QApplication::translate("CreateWriteOff", "Add products", 0));
        employeeBtn->setText(QApplication::translate("CreateWriteOff", "Select employee", 0));
        statusBtn->setText(QApplication::translate("CreateWriteOff", "Change status", 0));
        prodCountLb->setText(QApplication::translate("CreateWriteOff", "Count of products:", 0));
        currencyBtn->setText(QApplication::translate("CreateWriteOff", "Select currency", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateWriteOff", "Enter worker ID", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateWriteOff", "Total amount:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWriteOff: public Ui_CreateWriteOff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWOFFDLG_H
