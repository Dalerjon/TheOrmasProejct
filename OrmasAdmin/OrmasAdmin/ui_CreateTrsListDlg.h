/********************************************************************************
** Form generated from reading UI file 'CreateTrsListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETRSLISTDLG_H
#define UI_CREATETRSLISTDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTrsList
{
public:
    QGridLayout *gridLayout;
    QLabel *countLb;
    QLineEdit *productEdit;
    QPushButton *productBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLineEdit *countEdit;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *sumLb;
    QLineEdit *sumEdit;
    QPushButton *statusBtn;
    QPushButton *transportBtn;
    QLineEdit *statusEdit;
    QLineEdit *transportEdit;
    QPushButton *currencyBtn;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateTrsList)
    {
        if (CreateTrsList->objectName().isEmpty())
            CreateTrsList->setObjectName(QStringLiteral("CreateTrsList"));
        CreateTrsList->resize(396, 221);
        CreateTrsList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateTrsList->setModal(false);
        gridLayout = new QGridLayout(CreateTrsList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        countLb = new QLabel(CreateTrsList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 1, 0, 1, 1);

        productEdit = new QLineEdit(CreateTrsList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 1, 1, 1);

        productBtn = new QPushButton(CreateTrsList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateTrsList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateTrsList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        countEdit = new QLineEdit(CreateTrsList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 1, 1, 1, 1);

        editSectionWgt = new QWidget(CreateTrsList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        statusBtn = new QPushButton(editSectionWgt);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout_3->addWidget(statusBtn, 1, 0, 1, 1);

        transportBtn = new QPushButton(editSectionWgt);
        transportBtn->setObjectName(QStringLiteral("transportBtn"));
        transportBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(transportBtn, 0, 0, 1, 1);

        statusEdit = new QLineEdit(editSectionWgt);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout_3->addWidget(statusEdit, 1, 1, 1, 1);

        transportEdit = new QLineEdit(editSectionWgt);
        transportEdit->setObjectName(QStringLiteral("transportEdit"));
        transportEdit->setReadOnly(true);

        gridLayout_3->addWidget(transportEdit, 0, 1, 1, 1);

        currencyBtn = new QPushButton(editSectionWgt);
        currencyBtn->setObjectName(QStringLiteral("currencyBtn"));

        gridLayout_3->addWidget(currencyBtn, 3, 0, 1, 1);

        currencyEdit = new QLineEdit(editSectionWgt);
        currencyEdit->setObjectName(QStringLiteral("currencyEdit"));
        currencyEdit->setReadOnly(true);

        gridLayout_3->addWidget(currencyEdit, 3, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 2, 0, 1, 2);

        QWidget::setTabOrder(productBtn, productEdit);
        QWidget::setTabOrder(productEdit, countEdit);
        QWidget::setTabOrder(countEdit, transportBtn);
        QWidget::setTabOrder(transportBtn, transportEdit);
        QWidget::setTabOrder(transportEdit, statusBtn);
        QWidget::setTabOrder(statusBtn, statusEdit);
        QWidget::setTabOrder(statusEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, currencyBtn);
        QWidget::setTabOrder(currencyBtn, currencyEdit);
        QWidget::setTabOrder(currencyEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateTrsList);

        QMetaObject::connectSlotsByName(CreateTrsList);
    } // setupUi

    void retranslateUi(QDialog *CreateTrsList)
    {
        CreateTrsList->setWindowTitle(QApplication::translate("CreateTrsList", "Create/Update product in transport list", 0));
        countLb->setText(QApplication::translate("CreateTrsList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateTrsList", "Select product", 0));
        addBtn->setText(QApplication::translate("CreateTrsList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateTrsList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateTrsList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateTrsList", "Sum:", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateTrsList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        statusBtn->setText(QApplication::translate("CreateTrsList", "Select status", 0));
        transportBtn->setText(QApplication::translate("CreateTrsList", "Select transport", 0));
        transportEdit->setText(QString());
        currencyBtn->setText(QApplication::translate("CreateTrsList", "Select currency", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateTrsList: public Ui_CreateTrsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETRSLISTDLG_H
