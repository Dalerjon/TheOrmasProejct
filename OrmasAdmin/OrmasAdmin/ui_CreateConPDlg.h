/********************************************************************************
** Form generated from reading UI file 'CreateConPDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONPDLG_H
#define UI_CREATECONPDLG_H

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

class Ui_CreateConsumeProduct
{
public:
    QGridLayout *gridLayout;
    QLineEdit *employeeEdit;
    QLabel *sumLb;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QLabel *currencyLb;
    QLabel *empStockNamePh;
    QLabel *empStockPhonePh;
    QLabel *empPhoneLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QDateTimeEdit *dateEdit;
    QLabel *prodCountLb;
    QLineEdit *prodCountEdit;
    QLabel *empSurnamePh;
    QPushButton *employeeBtn;
    QLabel *empNameLb;
    QLabel *empStockSurnamePh;
    QLabel *empStockNameLb;
    QPushButton *addProdBtn;
    QLineEdit *stockEmployeeEdit;
    QComboBox *currencyCmb;
    QLabel *empNamePh;
    QLabel *empStockSurnameLb;
    QLabel *empStockPhoneLb;
    QLabel *dateLb;
    QLabel *empSurnameLb;
    QLineEdit *sumEdit;
    QLabel *empPhonePh;
    QPushButton *stockEmployeeBtn;
    QLabel *sumLb2;
    QLabel *priceSumLb;

    void setupUi(QDialog *CreateConsumeProduct)
    {
        if (CreateConsumeProduct->objectName().isEmpty())
            CreateConsumeProduct->setObjectName(QStringLiteral("CreateConsumeProduct"));
        CreateConsumeProduct->resize(631, 343);
        CreateConsumeProduct->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConsumeProduct->setModal(false);
        gridLayout = new QGridLayout(CreateConsumeProduct);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        employeeEdit = new QLineEdit(CreateConsumeProduct);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

        sumLb = new QLabel(CreateConsumeProduct);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 9, 0, 1, 2);

        statusWidget = new QWidget(CreateConsumeProduct);
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
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout->addWidget(statusWidget, 7, 0, 1, 6);

        execDateWidget = new QWidget(CreateConsumeProduct);
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

        currencyLb = new QLabel(CreateConsumeProduct);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 10, 0, 1, 2);

        empStockNamePh = new QLabel(CreateConsumeProduct);
        empStockNamePh->setObjectName(QStringLiteral("empStockNamePh"));
        empStockNamePh->setMinimumSize(QSize(100, 0));
        empStockNamePh->setFont(font);

        gridLayout->addWidget(empStockNamePh, 5, 1, 1, 1);

        empStockPhonePh = new QLabel(CreateConsumeProduct);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout->addWidget(empStockPhonePh, 5, 5, 1, 1);

        empPhoneLb = new QLabel(CreateConsumeProduct);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateConsumeProduct);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateConsumeProduct);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 11, 0, 1, 6);

        dateEdit = new QDateTimeEdit(CreateConsumeProduct);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        prodCountLb = new QLabel(CreateConsumeProduct);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        prodCountEdit = new QLineEdit(CreateConsumeProduct);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        empSurnamePh = new QLabel(CreateConsumeProduct);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        employeeBtn = new QPushButton(CreateConsumeProduct);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        empNameLb = new QLabel(CreateConsumeProduct);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        empStockSurnamePh = new QLabel(CreateConsumeProduct);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout->addWidget(empStockSurnamePh, 5, 3, 1, 1);

        empStockNameLb = new QLabel(CreateConsumeProduct);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockNameLb, 5, 0, 1, 1);

        addProdBtn = new QPushButton(CreateConsumeProduct);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        stockEmployeeEdit = new QLineEdit(CreateConsumeProduct);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 4, 2, 1, 2);

        currencyCmb = new QComboBox(CreateConsumeProduct);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 10, 2, 1, 1);

        empNamePh = new QLabel(CreateConsumeProduct);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 1, 1, 1, 1);

        empStockSurnameLb = new QLabel(CreateConsumeProduct);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockSurnameLb, 5, 2, 1, 1);

        empStockPhoneLb = new QLabel(CreateConsumeProduct);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout->addWidget(empStockPhoneLb, 5, 4, 1, 1);

        dateLb = new QLabel(CreateConsumeProduct);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        empSurnameLb = new QLabel(CreateConsumeProduct);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        sumEdit = new QLineEdit(CreateConsumeProduct);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 9, 2, 1, 1);

        empPhonePh = new QLabel(CreateConsumeProduct);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        stockEmployeeBtn = new QPushButton(CreateConsumeProduct);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 4, 0, 1, 2);

        sumLb2 = new QLabel(CreateConsumeProduct);
        sumLb2->setObjectName(QStringLiteral("sumLb2"));

        gridLayout->addWidget(sumLb2, 8, 0, 1, 1);

        priceSumLb = new QLabel(CreateConsumeProduct);
        priceSumLb->setObjectName(QStringLiteral("priceSumLb"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        priceSumLb->setFont(font1);

        gridLayout->addWidget(priceSumLb, 8, 2, 1, 1);

        QWidget::setTabOrder(employeeBtn, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateConsumeProduct);

        QMetaObject::connectSlotsByName(CreateConsumeProduct);
    } // setupUi

    void retranslateUi(QDialog *CreateConsumeProduct)
    {
        CreateConsumeProduct->setWindowTitle(QApplication::translate("CreateConsumeProduct", "Create/Update consume product", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateConsumeProduct", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateConsumeProduct", "Total amount:", 0));
        statusBtn->setText(QApplication::translate("CreateConsumeProduct", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateConsumeProduct", "Status name:", 0));
        statusPh->setText(QString());
        execDateLb->setText(QApplication::translate("CreateConsumeProduct", "Execution date:", 0));
        currencyLb->setText(QApplication::translate("CreateConsumeProduct", "Select currency:", 0));
        empStockNamePh->setText(QString());
        empStockPhonePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateConsumeProduct", "Phone:", 0));
        okBtn->setText(QApplication::translate("CreateConsumeProduct", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateConsumeProduct", "Cancel", 0));
        prodCountLb->setText(QApplication::translate("CreateConsumeProduct", "Count of products:", 0));
        empSurnamePh->setText(QString());
        employeeBtn->setText(QApplication::translate("CreateConsumeProduct", "Select employee", 0));
        empNameLb->setText(QApplication::translate("CreateConsumeProduct", "Name:", 0));
        empStockSurnamePh->setText(QString());
        empStockNameLb->setText(QApplication::translate("CreateConsumeProduct", "Name:", 0));
        addProdBtn->setText(QApplication::translate("CreateConsumeProduct", "Add products", 0));
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateConsumeProduct", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        empNamePh->setText(QString());
        empStockSurnameLb->setText(QApplication::translate("CreateConsumeProduct", "Surname:", 0));
        empStockPhoneLb->setText(QApplication::translate("CreateConsumeProduct", "Phone:", 0));
        dateLb->setText(QApplication::translate("CreateConsumeProduct", "Consume product date:", 0));
        empSurnameLb->setText(QApplication::translate("CreateConsumeProduct", "Surname:", 0));
        empPhonePh->setText(QString());
        stockEmployeeBtn->setText(QApplication::translate("CreateConsumeProduct", "Select stock employee", 0));
        sumLb2->setText(QApplication::translate("CreateConsumeProduct", "Sum:", 0));
        priceSumLb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateConsumeProduct: public Ui_CreateConsumeProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONPDLG_H
