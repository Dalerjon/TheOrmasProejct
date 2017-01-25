/********************************************************************************
** Form generated from reading UI file 'CreateRtrnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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

class Ui_CreateReturn
{
public:
    QGridLayout *gridLayout;
    QPushButton *addProdBtn;
    QLineEdit *prodCountEdit;
    QLabel *sumLb;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *userEdit;
    QLabel *dateLb;
    QPushButton *userBtn;
    QPushButton *workerBtn;
    QLineEdit *statusEdit;
    QPushButton *statusBtn;
    QLineEdit *workerEdit;
    QLineEdit *sumEdit;
    QPushButton *currencyBtn;
    QLabel *prodCountLb;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateReturn)
    {
        if (CreateReturn->objectName().isEmpty())
            CreateReturn->setObjectName(QStringLiteral("CreateReturn"));
        CreateReturn->resize(422, 244);
        CreateReturn->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateReturn->setModal(false);
        gridLayout = new QGridLayout(CreateReturn);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        addProdBtn = new QPushButton(CreateReturn);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 3, 0, 1, 1);

        prodCountEdit = new QLineEdit(CreateReturn);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 3, 2, 1, 1);

        sumLb = new QLabel(CreateReturn);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 5, 0, 1, 1);

        dateEdit = new QDateEdit(CreateReturn);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 2);

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


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 3);

        userEdit = new QLineEdit(CreateReturn);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 0, 1, 1, 2);

        dateLb = new QLabel(CreateReturn);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 1);

        userBtn = new QPushButton(CreateReturn);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(userBtn, 0, 0, 1, 1);

        workerBtn = new QPushButton(CreateReturn);
        workerBtn->setObjectName(QStringLiteral("workerBtn"));

        gridLayout->addWidget(workerBtn, 2, 0, 1, 1);

        statusEdit = new QLineEdit(CreateReturn);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        gridLayout->addWidget(statusEdit, 4, 1, 1, 2);

        statusBtn = new QPushButton(CreateReturn);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout->addWidget(statusBtn, 4, 0, 1, 1);

        workerEdit = new QLineEdit(CreateReturn);
        workerEdit->setObjectName(QStringLiteral("workerEdit"));
        workerEdit->setReadOnly(true);

        gridLayout->addWidget(workerEdit, 2, 1, 1, 2);

        sumEdit = new QLineEdit(CreateReturn);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout->addWidget(sumEdit, 5, 1, 1, 2);

        currencyBtn = new QPushButton(CreateReturn);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout->addWidget(currencyBtn, 6, 0, 1, 1);

        prodCountLb = new QLabel(CreateReturn);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 3, 1, 1, 1);

        currencyEdit = new QLineEdit(CreateReturn);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));

        gridLayout->addWidget(currencyEdit, 6, 1, 1, 2);

        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, workerBtn);
        QWidget::setTabOrder(workerBtn, workerEdit);
        QWidget::setTabOrder(workerEdit, addProdBtn);
        QWidget::setTabOrder(addProdBtn, prodCountEdit);
        QWidget::setTabOrder(prodCountEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateReturn);

        QMetaObject::connectSlotsByName(CreateReturn);
    } // setupUi

    void retranslateUi(QDialog *CreateReturn)
    {
        CreateReturn->setWindowTitle(QApplication::translate("CreateReturn", "Create/Update Return", 0));
        addProdBtn->setText(QApplication::translate("CreateReturn", "Add products", 0));
        sumLb->setText(QApplication::translate("CreateReturn", "Total amount:", 0));
        okBtn->setText(QApplication::translate("CreateReturn", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateReturn", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateReturn", "Enter user ID", 0));
#endif // QT_NO_TOOLTIP
        dateLb->setText(QApplication::translate("CreateReturn", "Date of order:", 0));
        userBtn->setText(QApplication::translate("CreateReturn", "Select user", 0));
        workerBtn->setText(QApplication::translate("CreateReturn", "Select worker", 0));
        statusBtn->setText(QApplication::translate("CreateReturn", "Change status", 0));
#ifndef QT_NO_TOOLTIP
        workerEdit->setToolTip(QApplication::translate("CreateReturn", "Enter worker ID", 0));
#endif // QT_NO_TOOLTIP
        currencyBtn->setText(QApplication::translate("CreateReturn", "Select currency", 0));
        prodCountLb->setText(QApplication::translate("CreateReturn", "Count of products:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateReturn: public Ui_CreateReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERTRNDLG_H
