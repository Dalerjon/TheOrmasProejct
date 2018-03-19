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

class Ui_CreateReceiptRaw
{
public:
    QGridLayout *gridLayout;
    QLabel *empStockNamePh;
    QLabel *empStockSurnamePh;
    QLabel *empStockSurnameLb;
    QLabel *empStockPhoneLb;
    QLabel *empStockPhonePh;
    QLabel *empStockNameLb;
    QLabel *empNameLb;
    QLabel *empNamePh;
    QLabel *empSurnameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *empPhonePh;
    QComboBox *currencyCmb;
    QLineEdit *sumEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QLabel *currencyLb;
    QLabel *sumLb;
    QPushButton *stockEmployeeBtn;
    QPushButton *employeeBtn;
    QDateTimeEdit *dateEdit;
    QLabel *dateLb;
    QLineEdit *employeeEdit;
    QLineEdit *stockEmployeeEdit;
    QPushButton *addProdBtn;

    void setupUi(QDialog *CreateReceiptRaw)
    {
        if (CreateReceiptRaw->objectName().isEmpty())
            CreateReceiptRaw->setObjectName(QStringLiteral("CreateReceiptRaw"));
        CreateReceiptRaw->resize(633, 319);
        CreateReceiptRaw->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateReceiptRaw->setModal(false);
        gridLayout = new QGridLayout(CreateReceiptRaw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empStockNamePh = new QLabel(CreateReceiptRaw);
        empStockNamePh->setObjectName(QStringLiteral("empStockNamePh"));
        empStockNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empStockNamePh->setFont(font);

        gridLayout->addWidget(empStockNamePh, 5, 1, 1, 1);

        empStockSurnamePh = new QLabel(CreateReceiptRaw);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout->addWidget(empStockSurnamePh, 5, 3, 1, 1);

        empStockSurnameLb = new QLabel(CreateReceiptRaw);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockSurnameLb, 5, 2, 1, 1);

        empStockPhoneLb = new QLabel(CreateReceiptRaw);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout->addWidget(empStockPhoneLb, 5, 4, 1, 1);

        empStockPhonePh = new QLabel(CreateReceiptRaw);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout->addWidget(empStockPhonePh, 5, 5, 1, 1);

        empStockNameLb = new QLabel(CreateReceiptRaw);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockNameLb, 5, 0, 1, 1);

        empNameLb = new QLabel(CreateReceiptRaw);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        empNamePh = new QLabel(CreateReceiptRaw);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 1, 1, 1, 1);

        empSurnameLb = new QLabel(CreateReceiptRaw);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        empSurnamePh = new QLabel(CreateReceiptRaw);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        empPhoneLb = new QLabel(CreateReceiptRaw);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        empPhonePh = new QLabel(CreateReceiptRaw);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        currencyCmb = new QComboBox(CreateReceiptRaw);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        sumEdit = new QLineEdit(CreateReceiptRaw);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        statusWidget = new QWidget(CreateReceiptRaw);
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


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        prodCountEdit = new QLineEdit(CreateReceiptRaw);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        prodCountLb = new QLabel(CreateReceiptRaw);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        execDateWidget = new QWidget(CreateReceiptRaw);
        execDateWidget->setObjectName(QStringLiteral("execDateWidget"));
        horizontalLayout_2 = new QHBoxLayout(execDateWidget);
        horizontalLayout_2->setSpacing(9);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        execDateLb = new QLabel(execDateWidget);
        execDateLb->setObjectName(QStringLiteral("execDateLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(execDateLb->sizePolicy().hasHeightForWidth());
        execDateLb->setSizePolicy(sizePolicy1);
        execDateLb->setMinimumSize(QSize(197, 0));

        horizontalLayout_2->addWidget(execDateLb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        execDateEdit = new QDateTimeEdit(execDateWidget);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));
        execDateEdit->setMinimumSize(QSize(127, 0));

        horizontalLayout_2->addWidget(execDateEdit);


        gridLayout->addWidget(execDateWidget, 3, 0, 1, 4);

        currencyLb = new QLabel(CreateReceiptRaw);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 2);

        sumLb = new QLabel(CreateReceiptRaw);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 2);

        stockEmployeeBtn = new QPushButton(CreateReceiptRaw);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 4, 0, 1, 2);

        employeeBtn = new QPushButton(CreateReceiptRaw);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        dateEdit = new QDateTimeEdit(CreateReceiptRaw);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        dateLb = new QLabel(CreateReceiptRaw);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        employeeEdit = new QLineEdit(CreateReceiptRaw);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

        stockEmployeeEdit = new QLineEdit(CreateReceiptRaw);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 4, 2, 1, 2);

        addProdBtn = new QPushButton(CreateReceiptRaw);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        QWidget::setTabOrder(employeeBtn, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateReceiptRaw);

        QMetaObject::connectSlotsByName(CreateReceiptRaw);
    } // setupUi

    void retranslateUi(QDialog *CreateReceiptRaw)
    {
        CreateReceiptRaw->setWindowTitle(QApplication::translate("CreateReceiptRaw", "Create/Update receipt raw", 0));
        empStockNamePh->setText(QString());
        empStockSurnamePh->setText(QString());
        empStockSurnameLb->setText(QApplication::translate("CreateReceiptRaw", "Surname:", 0));
        empStockPhoneLb->setText(QApplication::translate("CreateReceiptRaw", "Phone:", 0));
        empStockPhonePh->setText(QString());
        empStockNameLb->setText(QApplication::translate("CreateReceiptRaw", "Name:", 0));
        empNameLb->setText(QApplication::translate("CreateReceiptRaw", "Name:", 0));
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateReceiptRaw", "Surname:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateReceiptRaw", "Phone:", 0));
        empPhonePh->setText(QString());
        statusBtn->setText(QApplication::translate("CreateReceiptRaw", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateReceiptRaw", "Status name:", 0));
        statusPh->setText(QString());
        okBtn->setText(QApplication::translate("CreateReceiptRaw", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateReceiptRaw", "Cancel", 0));
        prodCountLb->setText(QApplication::translate("CreateReceiptRaw", "Count of products:", 0));
        execDateLb->setText(QApplication::translate("CreateReceiptRaw", "Execution date:", 0));
        currencyLb->setText(QApplication::translate("CreateReceiptRaw", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateReceiptRaw", "Total amount:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateReceiptRaw", "Select stock employee", 0));
        employeeBtn->setText(QApplication::translate("CreateReceiptRaw", "Select employee", 0));
        dateLb->setText(QApplication::translate("CreateReceiptRaw", "Consume receipt raw date:", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateReceiptRaw", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateReceiptRaw", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addProdBtn->setText(QApplication::translate("CreateReceiptRaw", "Add products", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateReceiptRaw: public Ui_CreateReceiptRaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERCPRDLG_H
