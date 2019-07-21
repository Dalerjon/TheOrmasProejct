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
#include <QtWidgets/QComboBox>
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
    QPushButton *employeeBtn;
    QLabel *empSurnamePh;
    QLabel *empNamePh;
    QComboBox *currencyCmb;
    QLabel *empPhonePh;
    QLabel *empStockNameLb;
    QLabel *empNameLb;
    QLabel *prodCountLb;
    QLineEdit *stockEmployeeEdit;
    QLineEdit *prodCountEdit;
    QLabel *empStockSurnamePh;
    QPushButton *addProdBtn;
    QLabel *empStockSurnameLb;
    QLabel *empSurnameLb;
    QDateTimeEdit *dateEdit;
    QPushButton *stockEmployeeBtn;
    QLineEdit *sumEdit;
    QLabel *currencyLb;
    QLabel *sumLb;
    QLabel *empStockNamePh;
    QLabel *dateLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *empPhoneLb;
    QLineEdit *employeeEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *empStockPhoneLb;
    QLabel *empStockPhonePh;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;

    void setupUi(QDialog *CreateWriteOffR)
    {
        if (CreateWriteOffR->objectName().isEmpty())
            CreateWriteOffR->setObjectName(QStringLiteral("CreateWriteOffR"));
        CreateWriteOffR->resize(708, 319);
        CreateWriteOffR->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWriteOffR->setModal(false);
        gridLayout = new QGridLayout(CreateWriteOffR);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        employeeBtn = new QPushButton(CreateWriteOffR);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        empSurnamePh = new QLabel(CreateWriteOffR);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        empNamePh = new QLabel(CreateWriteOffR);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 1, 1, 1, 1);

        currencyCmb = new QComboBox(CreateWriteOffR);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        empPhonePh = new QLabel(CreateWriteOffR);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        empStockNameLb = new QLabel(CreateWriteOffR);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockNameLb, 5, 0, 1, 1);

        empNameLb = new QLabel(CreateWriteOffR);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        prodCountLb = new QLabel(CreateWriteOffR);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        stockEmployeeEdit = new QLineEdit(CreateWriteOffR);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 4, 2, 1, 2);

        prodCountEdit = new QLineEdit(CreateWriteOffR);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        empStockSurnamePh = new QLabel(CreateWriteOffR);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout->addWidget(empStockSurnamePh, 5, 3, 1, 1);

        addProdBtn = new QPushButton(CreateWriteOffR);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        empStockSurnameLb = new QLabel(CreateWriteOffR);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockSurnameLb, 5, 2, 1, 1);

        empSurnameLb = new QLabel(CreateWriteOffR);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateWriteOffR);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        stockEmployeeBtn = new QPushButton(CreateWriteOffR);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 4, 0, 1, 2);

        sumEdit = new QLineEdit(CreateWriteOffR);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        currencyLb = new QLabel(CreateWriteOffR);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 2);

        sumLb = new QLabel(CreateWriteOffR);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 2);

        empStockNamePh = new QLabel(CreateWriteOffR);
        empStockNamePh->setObjectName(QStringLiteral("empStockNamePh"));
        empStockNamePh->setMinimumSize(QSize(100, 0));
        empStockNamePh->setFont(font);

        gridLayout->addWidget(empStockNamePh, 5, 1, 1, 1);

        dateLb = new QLabel(CreateWriteOffR);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

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


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        empPhoneLb = new QLabel(CreateWriteOffR);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        employeeEdit = new QLineEdit(CreateWriteOffR);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

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

        statusLb = new QLabel(statusWidget);
        statusLb->setObjectName(QStringLiteral("statusLb"));

        horizontalLayout_3->addWidget(statusLb);

        statusPh = new QLabel(statusWidget);
        statusPh->setObjectName(QStringLiteral("statusPh"));
        statusPh->setMinimumSize(QSize(120, 0));
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout->addWidget(statusWidget, 7, 0, 1, 6);

        empStockPhoneLb = new QLabel(CreateWriteOffR);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout->addWidget(empStockPhoneLb, 5, 4, 1, 1);

        empStockPhonePh = new QLabel(CreateWriteOffR);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout->addWidget(empStockPhonePh, 5, 5, 1, 1);

        execDateWidget = new QWidget(CreateWriteOffR);
        execDateWidget->setObjectName(QStringLiteral("execDateWidget"));
        horizontalLayout_2 = new QHBoxLayout(execDateWidget);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        execDateLb = new QLabel(execDateWidget);
        execDateLb->setObjectName(QStringLiteral("execDateLb"));

        horizontalLayout_2->addWidget(execDateLb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        execDateEdit = new QDateTimeEdit(execDateWidget);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));
        execDateEdit->setMinimumSize(QSize(155, 0));

        horizontalLayout_2->addWidget(execDateEdit);


        gridLayout->addWidget(execDateWidget, 3, 0, 1, 4);

        QWidget::setTabOrder(employeeBtn, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateWriteOffR);

        QMetaObject::connectSlotsByName(CreateWriteOffR);
    } // setupUi

    void retranslateUi(QDialog *CreateWriteOffR)
    {
        CreateWriteOffR->setWindowTitle(QApplication::translate("CreateWriteOffR", "Create/Update write-off raw", 0));
        employeeBtn->setText(QApplication::translate("CreateWriteOffR", "Select employee", 0));
        empSurnamePh->setText(QString());
        empNamePh->setText(QString());
        empPhonePh->setText(QString());
        empStockNameLb->setText(QApplication::translate("CreateWriteOffR", "Name:", 0));
        empNameLb->setText(QApplication::translate("CreateWriteOffR", "Name:", 0));
        prodCountLb->setText(QApplication::translate("CreateWriteOffR", "Count of products:", 0));
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateWriteOffR", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        empStockSurnamePh->setText(QString());
        addProdBtn->setText(QApplication::translate("CreateWriteOffR", "Add products", 0));
        empStockSurnameLb->setText(QApplication::translate("CreateWriteOffR", "Surname:", 0));
        empSurnameLb->setText(QApplication::translate("CreateWriteOffR", "Surname:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateWriteOffR", "Select stock employee", 0));
        currencyLb->setText(QApplication::translate("CreateWriteOffR", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateWriteOffR", "Total amount:", 0));
        empStockNamePh->setText(QString());
        dateLb->setText(QApplication::translate("CreateWriteOffR", "Write-off raw date:", 0));
        okBtn->setText(QApplication::translate("CreateWriteOffR", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWriteOffR", "Cancel", 0));
        empPhoneLb->setText(QApplication::translate("CreateWriteOffR", "Phone:", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateWriteOffR", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        statusBtn->setText(QApplication::translate("CreateWriteOffR", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateWriteOffR", "Status name:", 0));
        statusPh->setText(QString());
        empStockPhoneLb->setText(QApplication::translate("CreateWriteOffR", "Phone:", 0));
        empStockPhonePh->setText(QString());
        execDateLb->setText(QApplication::translate("CreateWriteOffR", "Execution date:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWriteOffR: public Ui_CreateWriteOffR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWOFFRDLG_H
