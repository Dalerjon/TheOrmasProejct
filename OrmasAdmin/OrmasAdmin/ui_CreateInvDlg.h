/********************************************************************************
** Form generated from reading UI file 'CreateInvDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEINVDLG_H
#define UI_CREATEINVDLG_H

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

class Ui_CreateInventorization
{
public:
    QGridLayout *gridLayout;
    QLabel *currencyLb;
    QLabel *empStockNamePh;
    QLabel *empStockSurnamePh;
    QLabel *empStockPhonePh;
    QLabel *sumLb;
    QLabel *empStockSurnameLb;
    QLabel *empStockPhoneLb;
    QLabel *empStockNameLb;
    QLabel *empNameLb;
    QLabel *empNamePh;
    QLabel *empSurnameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *empPhonePh;
    QComboBox *currencyCmb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLineEdit *sumEdit;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QDateTimeEdit *dateEdit;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QPushButton *employeeBtn;
    QLabel *dateLb;
    QPushButton *stockEmployeeBtn;
    QLineEdit *employeeEdit;
    QLineEdit *stockEmployeeEdit;
    QPushButton *addProdBtn;

    void setupUi(QDialog *CreateInventorization)
    {
        if (CreateInventorization->objectName().isEmpty())
            CreateInventorization->setObjectName(QStringLiteral("CreateInventorization"));
        CreateInventorization->resize(631, 319);
        CreateInventorization->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateInventorization->setModal(false);
        gridLayout = new QGridLayout(CreateInventorization);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        currencyLb = new QLabel(CreateInventorization);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 1);

        empStockNamePh = new QLabel(CreateInventorization);
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

        empStockSurnamePh = new QLabel(CreateInventorization);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout->addWidget(empStockSurnamePh, 5, 3, 1, 1);

        empStockPhonePh = new QLabel(CreateInventorization);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout->addWidget(empStockPhonePh, 5, 5, 1, 1);

        sumLb = new QLabel(CreateInventorization);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 1);

        empStockSurnameLb = new QLabel(CreateInventorization);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockSurnameLb, 5, 2, 1, 1);

        empStockPhoneLb = new QLabel(CreateInventorization);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout->addWidget(empStockPhoneLb, 5, 4, 1, 1);

        empStockNameLb = new QLabel(CreateInventorization);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockNameLb, 5, 0, 1, 1);

        empNameLb = new QLabel(CreateInventorization);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        empNamePh = new QLabel(CreateInventorization);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 1, 1, 1, 1);

        empSurnameLb = new QLabel(CreateInventorization);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        empSurnamePh = new QLabel(CreateInventorization);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        empPhoneLb = new QLabel(CreateInventorization);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        empPhonePh = new QLabel(CreateInventorization);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        currencyCmb = new QComboBox(CreateInventorization);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateInventorization);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateInventorization);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        statusWidget = new QWidget(CreateInventorization);
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

        sumEdit = new QLineEdit(CreateInventorization);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        prodCountEdit = new QLineEdit(CreateInventorization);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        prodCountLb = new QLabel(CreateInventorization);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateInventorization);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        execDateWidget = new QWidget(CreateInventorization);
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

        employeeBtn = new QPushButton(CreateInventorization);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        dateLb = new QLabel(CreateInventorization);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        stockEmployeeBtn = new QPushButton(CreateInventorization);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 4, 0, 1, 2);

        employeeEdit = new QLineEdit(CreateInventorization);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

        stockEmployeeEdit = new QLineEdit(CreateInventorization);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 4, 2, 1, 2);

        addProdBtn = new QPushButton(CreateInventorization);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        QWidget::setTabOrder(employeeBtn, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateInventorization);

        QMetaObject::connectSlotsByName(CreateInventorization);
    } // setupUi

    void retranslateUi(QDialog *CreateInventorization)
    {
        CreateInventorization->setWindowTitle(QApplication::translate("CreateInventorization", "Create/Update inventorization", 0));
        currencyLb->setText(QApplication::translate("CreateInventorization", "Select currency:", 0));
        empStockNamePh->setText(QString());
        empStockSurnamePh->setText(QString());
        empStockPhonePh->setText(QString());
        sumLb->setText(QApplication::translate("CreateInventorization", "Total amount:", 0));
        empStockSurnameLb->setText(QApplication::translate("CreateInventorization", "Surname:", 0));
        empStockPhoneLb->setText(QApplication::translate("CreateInventorization", "Phone:", 0));
        empStockNameLb->setText(QApplication::translate("CreateInventorization", "Name:", 0));
        empNameLb->setText(QApplication::translate("CreateInventorization", "Name:", 0));
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateInventorization", "Surname:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateInventorization", "Phone:", 0));
        empPhonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateInventorization", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateInventorization", "Cancel", 0));
        statusBtn->setText(QApplication::translate("CreateInventorization", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateInventorization", "Status name:", 0));
        statusPh->setText(QString());
        prodCountLb->setText(QApplication::translate("CreateInventorization", "Count of products:", 0));
        execDateLb->setText(QApplication::translate("CreateInventorization", "Execution date:", 0));
        employeeBtn->setText(QApplication::translate("CreateInventorization", "Select employee", 0));
        dateLb->setText(QApplication::translate("CreateInventorization", "Inventorization date:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateInventorization", "Select stock employee", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateInventorization", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateInventorization", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addProdBtn->setText(QApplication::translate("CreateInventorization", "Add products", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateInventorization: public Ui_CreateInventorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEINVDLG_H
