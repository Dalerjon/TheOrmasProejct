/********************************************************************************
** Form generated from reading UI file 'CreateConOthStDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONOTHSTDLG_H
#define UI_CREATECONOTHSTDLG_H

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

class Ui_CreateConsumeOthSt
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
    QLineEdit *othStCountEdit;
    QLabel *othStCountLb;
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
    QPushButton *addOthStBtn;
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

    void setupUi(QDialog *CreateConsumeOthSt)
    {
        if (CreateConsumeOthSt->objectName().isEmpty())
            CreateConsumeOthSt->setObjectName(QStringLiteral("CreateConsumeOthSt"));
        CreateConsumeOthSt->resize(628, 319);
        CreateConsumeOthSt->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateConsumeOthSt->setModal(false);
        gridLayout = new QGridLayout(CreateConsumeOthSt);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empNamePh = new QLabel(CreateConsumeOthSt);
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

        empStockSurnamePh = new QLabel(CreateConsumeOthSt);
        empStockSurnamePh->setObjectName(QStringLiteral("empStockSurnamePh"));
        empStockSurnamePh->setMinimumSize(QSize(100, 0));
        empStockSurnamePh->setFont(font);

        gridLayout->addWidget(empStockSurnamePh, 5, 3, 1, 1);

        empStockPhoneLb = new QLabel(CreateConsumeOthSt);
        empStockPhoneLb->setObjectName(QStringLiteral("empStockPhoneLb"));

        gridLayout->addWidget(empStockPhoneLb, 5, 4, 1, 1);

        empStockPhonePh = new QLabel(CreateConsumeOthSt);
        empStockPhonePh->setObjectName(QStringLiteral("empStockPhonePh"));
        empStockPhonePh->setMinimumSize(QSize(100, 0));
        empStockPhonePh->setFont(font);

        gridLayout->addWidget(empStockPhonePh, 5, 5, 1, 1);

        sumEdit = new QLineEdit(CreateConsumeOthSt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        empNameLb = new QLabel(CreateConsumeOthSt);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        currencyCmb = new QComboBox(CreateConsumeOthSt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        othStCountEdit = new QLineEdit(CreateConsumeOthSt);
        othStCountEdit->setObjectName(QStringLiteral("othStCountEdit"));
        othStCountEdit->setReadOnly(true);

        gridLayout->addWidget(othStCountEdit, 6, 3, 1, 1);

        othStCountLb = new QLabel(CreateConsumeOthSt);
        othStCountLb->setObjectName(QStringLiteral("othStCountLb"));

        gridLayout->addWidget(othStCountLb, 6, 2, 1, 1);

        currencyLb = new QLabel(CreateConsumeOthSt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 1);

        sumLb = new QLabel(CreateConsumeOthSt);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 1);

        empStockNamePh = new QLabel(CreateConsumeOthSt);
        empStockNamePh->setObjectName(QStringLiteral("empStockNamePh"));
        empStockNamePh->setMinimumSize(QSize(100, 0));
        empStockNamePh->setFont(font);

        gridLayout->addWidget(empStockNamePh, 5, 1, 1, 1);

        empStockSurnameLb = new QLabel(CreateConsumeOthSt);
        empStockSurnameLb->setObjectName(QStringLiteral("empStockSurnameLb"));
        empStockSurnameLb->setMinimumSize(QSize(50, 0));
        empStockSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockSurnameLb, 5, 2, 1, 1);

        empStockNameLb = new QLabel(CreateConsumeOthSt);
        empStockNameLb->setObjectName(QStringLiteral("empStockNameLb"));
        empStockNameLb->setMinimumSize(QSize(50, 0));
        empStockNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empStockNameLb, 5, 0, 1, 1);

        empSurnamePh = new QLabel(CreateConsumeOthSt);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        empPhoneLb = new QLabel(CreateConsumeOthSt);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        empSurnameLb = new QLabel(CreateConsumeOthSt);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        empPhonePh = new QLabel(CreateConsumeOthSt);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        execDateWidget = new QWidget(CreateConsumeOthSt);
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

        dateEdit = new QDateTimeEdit(CreateConsumeOthSt);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        employeeBtn = new QPushButton(CreateConsumeOthSt);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));
        employeeBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        dateLb = new QLabel(CreateConsumeOthSt);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        stockEmployeeBtn = new QPushButton(CreateConsumeOthSt);
        stockEmployeeBtn->setObjectName(QStringLiteral("stockEmployeeBtn"));

        gridLayout->addWidget(stockEmployeeBtn, 4, 0, 1, 2);

        addOthStBtn = new QPushButton(CreateConsumeOthSt);
        addOthStBtn->setObjectName(QStringLiteral("addOthStBtn"));

        gridLayout->addWidget(addOthStBtn, 6, 0, 1, 2);

        statusWidget = new QWidget(CreateConsumeOthSt);
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

        okBtn = new QPushButton(CreateConsumeOthSt);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateConsumeOthSt);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        employeeEdit = new QLineEdit(CreateConsumeOthSt);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

        stockEmployeeEdit = new QLineEdit(CreateConsumeOthSt);
        stockEmployeeEdit->setObjectName(QStringLiteral("stockEmployeeEdit"));
        stockEmployeeEdit->setReadOnly(true);

        gridLayout->addWidget(stockEmployeeEdit, 4, 2, 1, 2);

        QWidget::setTabOrder(employeeBtn, stockEmployeeBtn);
        QWidget::setTabOrder(stockEmployeeBtn, addOthStBtn);
        QWidget::setTabOrder(addOthStBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateConsumeOthSt);

        QMetaObject::connectSlotsByName(CreateConsumeOthSt);
    } // setupUi

    void retranslateUi(QDialog *CreateConsumeOthSt)
    {
        CreateConsumeOthSt->setWindowTitle(QApplication::translate("CreateConsumeOthSt", "Create/Update consume other stocks", 0));
        empNamePh->setText(QString());
        empStockSurnamePh->setText(QString());
        empStockPhoneLb->setText(QApplication::translate("CreateConsumeOthSt", "Phone:", 0));
        empStockPhonePh->setText(QString());
        empNameLb->setText(QApplication::translate("CreateConsumeOthSt", "Name:", 0));
        othStCountLb->setText(QApplication::translate("CreateConsumeOthSt", "Count of other stocks:", 0));
        currencyLb->setText(QApplication::translate("CreateConsumeOthSt", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateConsumeOthSt", "Total amount:", 0));
        empStockNamePh->setText(QString());
        empStockSurnameLb->setText(QApplication::translate("CreateConsumeOthSt", "Surname:", 0));
        empStockNameLb->setText(QApplication::translate("CreateConsumeOthSt", "Name:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateConsumeOthSt", "Phone:", 0));
        empSurnameLb->setText(QApplication::translate("CreateConsumeOthSt", "Surname:", 0));
        empPhonePh->setText(QString());
        execDateLb->setText(QApplication::translate("CreateConsumeOthSt", "Execution date:", 0));
        employeeBtn->setText(QApplication::translate("CreateConsumeOthSt", "Select employee", 0));
        dateLb->setText(QApplication::translate("CreateConsumeOthSt", "Consume other stocks date:", 0));
        stockEmployeeBtn->setText(QApplication::translate("CreateConsumeOthSt", "Select stock employee", 0));
        addOthStBtn->setText(QApplication::translate("CreateConsumeOthSt", "Add other stocks", 0));
        statusBtn->setText(QApplication::translate("CreateConsumeOthSt", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateConsumeOthSt", "Status name:", 0));
        statusPh->setText(QString());
        okBtn->setText(QApplication::translate("CreateConsumeOthSt", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateConsumeOthSt", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateConsumeOthSt", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        employeeEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        stockEmployeeEdit->setToolTip(QApplication::translate("CreateConsumeOthSt", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateConsumeOthSt: public Ui_CreateConsumeOthSt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONOTHSTDLG_H
