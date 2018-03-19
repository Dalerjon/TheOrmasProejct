/********************************************************************************
** Form generated from reading UI file 'CreateConRDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONRDLG_H
#define UI_CREATECONRDLG_H

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

class Ui_CreateConsumeRaw
{
public:
    QGridLayout *gridLayout;
    QLabel *empNamePh;
    QLabel *empStockSurnamePh;
    QLabel *empStockPhoneLb;
    QLabel *empStockPhonePh;
    QLineEdit *sumEdit;
    QLabel *empNameLb;
    QComboBox *currencyCmb;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QLabel *currencyLb;
    QLabel *sumLb;
    QLabel *empStockNamePh;
    QLabel *empStockSurnameLb;
    QLabel *empStockNameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *empSurnameLb;
    QLabel *empPhonePh;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QDateTimeEdit *dateEdit;
    QPushButton *employeeBtn;
    QLabel *dateLb;
    QPushButton *stockEmployeeBtn;
    QPushButton *addProdBtn;
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
    QLineEdit *employeeEdit;
    QLineEdit *stockEmployeeEdit;

    void setupUi(QDialog *CreateConsumeRaw)
    {
        if (CreateConsumeRaw->objectName().isEmpty())
            CreateConsumeRaw->setObjectName(QStringLiteral("CreateConsumeRaw"));
        CreateConsumeRaw->resize(628, 319);
        CreateConsumeRaw->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConsumeRaw->setModal(false);
        gridLayout = new QGridLayout(CreateConsumeRaw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empNamePh = new QLabel(CreateConsumeRaw);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 1, 1, 1, 1);

        empStockSurnamePh = new QLabel(CreateConsumeRaw);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout->addWidget(empStockSurnamePh, 5, 3, 1, 1);

        empStockPhoneLb = new QLabel(CreateConsumeRaw);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout->addWidget(empStockPhoneLb, 5, 4, 1, 1);

        empStockPhonePh = new QLabel(CreateConsumeRaw);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout->addWidget(empStockPhonePh, 5, 5, 1, 1);

        sumEdit = new QLineEdit(CreateConsumeRaw);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        empNameLb = new QLabel(CreateConsumeRaw);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        currencyCmb = new QComboBox(CreateConsumeRaw);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        prodCountEdit = new QLineEdit(CreateConsumeRaw);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        prodCountLb = new QLabel(CreateConsumeRaw);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        currencyLb = new QLabel(CreateConsumeRaw);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 1);

        sumLb = new QLabel(CreateConsumeRaw);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 1);

        empStockNamePh = new QLabel(CreateConsumeRaw);
        empStockNamePh->setObjectName(QStringLiteral("empStockNamePh"));
        empStockNamePh->setMinimumSize(QSize(100, 0));
        empStockNamePh->setFont(font);

        gridLayout->addWidget(empStockNamePh, 5, 1, 1, 1);

        empStockSurnameLb = new QLabel(CreateConsumeRaw);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockSurnameLb, 5, 2, 1, 1);

        empStockNameLb = new QLabel(CreateConsumeRaw);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockNameLb, 5, 0, 1, 1);

        empSurnamePh = new QLabel(CreateConsumeRaw);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        empPhoneLb = new QLabel(CreateConsumeRaw);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        empSurnameLb = new QLabel(CreateConsumeRaw);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        empPhonePh = new QLabel(CreateConsumeRaw);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        execDateWidget = new QWidget(CreateConsumeRaw);
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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        execDateEdit = new QDateTimeEdit(execDateWidget);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));
        execDateEdit->setMinimumSize(QSize(127, 0));

        horizontalLayout_2->addWidget(execDateEdit);


        gridLayout->addWidget(execDateWidget, 3, 0, 1, 4);

        dateEdit = new QDateTimeEdit(CreateConsumeRaw);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        employeeBtn = new QPushButton(CreateConsumeRaw);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        dateLb = new QLabel(CreateConsumeRaw);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        stockEmployeeBtn = new QPushButton(CreateConsumeRaw);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 4, 0, 1, 2);

        addProdBtn = new QPushButton(CreateConsumeRaw);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        statusWidget = new QWidget(CreateConsumeRaw);
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

        okBtn = new QPushButton(CreateConsumeRaw);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateConsumeRaw);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        employeeEdit = new QLineEdit(CreateConsumeRaw);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

        stockEmployeeEdit = new QLineEdit(CreateConsumeRaw);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 4, 2, 1, 2);

        QWidget::setTabOrder(employeeBtn, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateConsumeRaw);

        QMetaObject::connectSlotsByName(CreateConsumeRaw);
    } // setupUi

    void retranslateUi(QDialog *CreateConsumeRaw)
    {
        CreateConsumeRaw->setWindowTitle(QApplication::translate("CreateConsumeRaw", "Create/Update consume raw", 0));
        empNamePh->setText(QString());
        empStockSurnamePh->setText(QString());
        empStockPhoneLb->setText(QApplication::translate("CreateConsumeRaw", "Phone:", 0));
        empStockPhonePh->setText(QString());
        empNameLb->setText(QApplication::translate("CreateConsumeRaw", "Name:", 0));
        prodCountLb->setText(QApplication::translate("CreateConsumeRaw", "Count of products:", 0));
        currencyLb->setText(QApplication::translate("CreateConsumeRaw", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateConsumeRaw", "Total amount:", 0));
        empStockNamePh->setText(QString());
        empStockSurnameLb->setText(QApplication::translate("CreateConsumeRaw", "Surname:", 0));
        empStockNameLb->setText(QApplication::translate("CreateConsumeRaw", "Name:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateConsumeRaw", "Phone:", 0));
        empSurnameLb->setText(QApplication::translate("CreateConsumeRaw", "Surname:", 0));
        empPhonePh->setText(QString());
        execDateLb->setText(QApplication::translate("CreateConsumeRaw", "Execution date:", 0));
        employeeBtn->setText(QApplication::translate("CreateConsumeRaw", "Select employee", 0));
        dateLb->setText(QApplication::translate("CreateConsumeRaw", "Consume raw date:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateConsumeRaw", "Select stock employee", 0));
        addProdBtn->setText(QApplication::translate("CreateConsumeRaw", "Add products", 0));
        statusBtn->setText(QApplication::translate("CreateConsumeRaw", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateConsumeRaw", "Status name:", 0));
        statusPh->setText(QString());
        okBtn->setText(QApplication::translate("CreateConsumeRaw", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateConsumeRaw", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateConsumeRaw", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateConsumeRaw", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateConsumeRaw: public Ui_CreateConsumeRaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONRDLG_H
