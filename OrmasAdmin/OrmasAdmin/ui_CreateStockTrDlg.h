/********************************************************************************
** Form generated from reading UI file 'CreateStockTrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESTOCKTRDLG_H
#define UI_CREATESTOCKTRDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateStockTransfer
{
public:
    QGridLayout *gridLayout;
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
    QGroupBox *fromBox;
    QGridLayout *gridLayout_3;
    QLineEdit *fromStkEmpEdit;
    QPushButton *stockEmpFromBtn;
    QLabel *empSurnamePh;
    QLabel *empSurnameLb;
    QLabel *empNamePh;
    QLabel *empPhoneLb;
    QLabel *empNameLb;
    QLabel *empPhonePh;
    QLabel *fromWrhName;
    QLabel *fromWrhNamePh;
    QComboBox *currencyCmb;
    QLineEdit *sumEdit;
    QPushButton *addProdBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QGroupBox *toBox;
    QGridLayout *gridLayout_2;
    QPushButton *stockEmpToBtn;
    QLineEdit *toStkEmpEdit;
    QLabel *empStockNamePh;
    QLabel *empStockNameLb;
    QLabel *empStockPhonePh;
    QLabel *empStockPhoneLb;
    QLabel *empStockSurnameLb;
    QLabel *empStockSurnamePh;
    QLabel *fromWrhName_2;
    QLabel *toWrhNamePh;
    QLabel *currencyLb;
    QLabel *sumLb;
    QDateTimeEdit *dateEdit;
    QLabel *dateLb;
    QLabel *sumLb2;
    QLabel *priceSumLb;

    void setupUi(QDialog *CreateStockTransfer)
    {
        if (CreateStockTransfer->objectName().isEmpty())
            CreateStockTransfer->setObjectName(QStringLiteral("CreateStockTransfer"));
        CreateStockTransfer->resize(675, 447);
        CreateStockTransfer->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateStockTransfer->setModal(false);
        gridLayout = new QGridLayout(CreateStockTransfer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        statusWidget = new QWidget(CreateStockTransfer);
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


        gridLayout->addWidget(statusWidget, 5, 0, 1, 5);

        execDateWidget = new QWidget(CreateStockTransfer);
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


        gridLayout->addWidget(execDateWidget, 2, 0, 1, 4);

        fromBox = new QGroupBox(CreateStockTransfer);
        fromBox->setObjectName(QStringLiteral("fromBox"));
        gridLayout_3 = new QGridLayout(fromBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        fromStkEmpEdit = new QLineEdit(fromBox);
        fromStkEmpEdit->setObjectName(QStringLiteral("fromStkEmpEdit"));
        fromStkEmpEdit->setReadOnly(true);

        gridLayout_3->addWidget(fromStkEmpEdit, 0, 5, 1, 1);

        stockEmpFromBtn = new QPushButton(fromBox);
        stockEmpFromBtn->setObjectName(QStringLiteral("stockEmpFromBtn"));
        stockEmpFromBtn->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(stockEmpFromBtn, 0, 1, 1, 3);

        empSurnamePh = new QLabel(fromBox);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout_3->addWidget(empSurnamePh, 1, 5, 2, 1);

        empSurnameLb = new QLabel(fromBox);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(empSurnameLb, 1, 4, 2, 1);

        empNamePh = new QLabel(fromBox);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout_3->addWidget(empNamePh, 1, 2, 2, 2);

        empPhoneLb = new QLabel(fromBox);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout_3->addWidget(empPhoneLb, 1, 6, 2, 1);

        empNameLb = new QLabel(fromBox);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(empNameLb, 1, 1, 2, 1);

        empPhonePh = new QLabel(fromBox);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout_3->addWidget(empPhonePh, 1, 7, 2, 1);

        fromWrhName = new QLabel(fromBox);
        fromWrhName->setObjectName(QStringLiteral("fromWrhName"));

        gridLayout_3->addWidget(fromWrhName, 3, 1, 1, 1);

        fromWrhNamePh = new QLabel(fromBox);
        fromWrhNamePh->setObjectName(QStringLiteral("fromWrhNamePh"));

        gridLayout_3->addWidget(fromWrhNamePh, 3, 4, 1, 2);


        gridLayout->addWidget(fromBox, 0, 0, 1, 5);

        currencyCmb = new QComboBox(CreateStockTransfer);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 8, 2, 1, 1);

        sumEdit = new QLineEdit(CreateStockTransfer);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 7, 2, 1, 1);

        addProdBtn = new QPushButton(CreateStockTransfer);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 4, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateStockTransfer);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateStockTransfer);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 5);

        prodCountEdit = new QLineEdit(CreateStockTransfer);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 4, 3, 1, 1);

        prodCountLb = new QLabel(CreateStockTransfer);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 4, 2, 1, 1);

        toBox = new QGroupBox(CreateStockTransfer);
        toBox->setObjectName(QStringLiteral("toBox"));
        gridLayout_2 = new QGridLayout(toBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stockEmpToBtn = new QPushButton(toBox);
        stockEmpToBtn->setObjectName(QStringLiteral("stockEmpToBtn"));

        gridLayout_2->addWidget(stockEmpToBtn, 0, 1, 1, 2);

        toStkEmpEdit = new QLineEdit(toBox);
        toStkEmpEdit->setObjectName(QStringLiteral("toStkEmpEdit"));
        toStkEmpEdit->setReadOnly(true);

        gridLayout_2->addWidget(toStkEmpEdit, 0, 5, 1, 1);

        empStockNamePh = new QLabel(toBox);
        empStockNamePh->setObjectName(QStringLiteral("empStockNamePh"));
        empStockNamePh->setMinimumSize(QSize(100, 0));
        empStockNamePh->setFont(font);

        gridLayout_2->addWidget(empStockNamePh, 1, 2, 1, 1);

        empStockNameLb = new QLabel(toBox);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(empStockNameLb, 1, 1, 1, 1);

        empStockPhonePh = new QLabel(toBox);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout_2->addWidget(empStockPhonePh, 1, 7, 1, 1);

        empStockPhoneLb = new QLabel(toBox);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout_2->addWidget(empStockPhoneLb, 1, 6, 1, 1);

        empStockSurnameLb = new QLabel(toBox);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(empStockSurnameLb, 1, 3, 1, 1);

        empStockSurnamePh = new QLabel(toBox);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout_2->addWidget(empStockSurnamePh, 1, 4, 1, 2);

        fromWrhName_2 = new QLabel(toBox);
        fromWrhName_2->setObjectName(QStringLiteral("fromWrhName_2"));

        gridLayout_2->addWidget(fromWrhName_2, 2, 1, 1, 1);

        toWrhNamePh = new QLabel(toBox);
        toWrhNamePh->setObjectName(QStringLiteral("toWrhNamePh"));

        gridLayout_2->addWidget(toWrhNamePh, 2, 3, 1, 3);


        gridLayout->addWidget(toBox, 3, 0, 1, 5);

        currencyLb = new QLabel(CreateStockTransfer);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 8, 0, 1, 2);

        sumLb = new QLabel(CreateStockTransfer);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 7, 0, 1, 2);

        dateEdit = new QDateTimeEdit(CreateStockTransfer);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 1, 3, 1, 1);

        dateLb = new QLabel(CreateStockTransfer);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 1, 0, 1, 2);

        sumLb2 = new QLabel(CreateStockTransfer);
        sumLb2->setObjectName(QStringLiteral("sumLb2"));

        gridLayout->addWidget(sumLb2, 6, 0, 1, 1);

        priceSumLb = new QLabel(CreateStockTransfer);
        priceSumLb->setObjectName(QStringLiteral("priceSumLb"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        priceSumLb->setFont(font1);

        gridLayout->addWidget(priceSumLb, 6, 2, 1, 1);

        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateStockTransfer);

        QMetaObject::connectSlotsByName(CreateStockTransfer);
    } // setupUi

    void retranslateUi(QDialog *CreateStockTransfer)
    {
        CreateStockTransfer->setWindowTitle(QApplication::translate("CreateStockTransfer", "Create/Update stock transfer", 0));
        statusBtn->setText(QApplication::translate("CreateStockTransfer", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateStockTransfer", "Status name:", 0));
        statusPh->setText(QString());
        execDateLb->setText(QApplication::translate("CreateStockTransfer", "Execution date:", 0));
        fromBox->setTitle(QApplication::translate("CreateStockTransfer", "From stock", 0));
#ifndef QT_NO_TOOLTIP
        fromStkEmpEdit->setToolTip(QApplication::translate("CreateStockTransfer", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        stockEmpFromBtn->setText(QApplication::translate("CreateStockTransfer", "Select stock employee", 0));
        empSurnamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateStockTransfer", "Surname:", 0));
        empNamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateStockTransfer", "Phone:", 0));
        empNameLb->setText(QApplication::translate("CreateStockTransfer", "Name:", 0));
        empPhonePh->setText(QString());
        fromWrhName->setText(QApplication::translate("CreateStockTransfer", "Warehouse Name:", 0));
        fromWrhNamePh->setText(QString());
        addProdBtn->setText(QApplication::translate("CreateStockTransfer", "Add products", 0));
        okBtn->setText(QApplication::translate("CreateStockTransfer", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateStockTransfer", "Cancel", 0));
        prodCountLb->setText(QApplication::translate("CreateStockTransfer", "Count of products:", 0));
        toBox->setTitle(QApplication::translate("CreateStockTransfer", "To stock", 0));
        stockEmpToBtn->setText(QApplication::translate("CreateStockTransfer", "Select stock employee", 0));
#ifndef QT_NO_TOOLTIP
        toStkEmpEdit->setToolTip(QApplication::translate("CreateStockTransfer", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        empStockNamePh->setText(QString());
        empStockNameLb->setText(QApplication::translate("CreateStockTransfer", "Name:", 0));
        empStockPhonePh->setText(QString());
        empStockPhoneLb->setText(QApplication::translate("CreateStockTransfer", "Phone:", 0));
        empStockSurnameLb->setText(QApplication::translate("CreateStockTransfer", "Surname:", 0));
        empStockSurnamePh->setText(QString());
        fromWrhName_2->setText(QApplication::translate("CreateStockTransfer", "Warehouse Name:", 0));
        toWrhNamePh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateStockTransfer", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateStockTransfer", "Total amount:", 0));
        dateLb->setText(QApplication::translate("CreateStockTransfer", "Consume receipt raw date:", 0));
        sumLb2->setText(QApplication::translate("CreateStockTransfer", "Sum:", 0));
        priceSumLb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateStockTransfer: public Ui_CreateStockTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESTOCKTRDLG_H
