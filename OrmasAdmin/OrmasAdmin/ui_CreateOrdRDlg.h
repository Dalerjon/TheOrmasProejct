/********************************************************************************
** Form generated from reading UI file 'CreateOrdRDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDRDLG_H
#define UI_CREATEORDRDLG_H

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

class Ui_CreateOrderRaw
{
public:
    QGridLayout *gridLayout;
    QLabel *empNameLb;
    QLabel *currencyLb;
    QLabel *empNamePh;
    QLabel *empPhonePh;
    QLabel *empSurnamePh;
    QLabel *empSurnameLb;
    QLabel *empPhoneLb;
    QLabel *sumLb;
    QLabel *prNameLb;
    QLabel *prNamePh;
    QLabel *prSurnameLb;
    QLabel *prSurnamePh;
    QLabel *prPhoneLb;
    QLabel *prPhonePh;
    QComboBox *currencyCmb;
    QLineEdit *sumEdit;
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
    QDateTimeEdit *dateEdit;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QPushButton *purveyorBtn;
    QLabel *dateLb;
    QLineEdit *purveyorEdit;
    QLineEdit *employeeEdit;
    QPushButton *employeeBtn;
    QPushButton *addProdBtn;

    void setupUi(QDialog *CreateOrderRaw)
    {
        if (CreateOrderRaw->objectName().isEmpty())
            CreateOrderRaw->setObjectName(QStringLiteral("CreateOrderRaw"));
        CreateOrderRaw->resize(632, 319);
        CreateOrderRaw->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOrderRaw->setModal(false);
        gridLayout = new QGridLayout(CreateOrderRaw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empNameLb = new QLabel(CreateOrderRaw);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 5, 0, 1, 1);

        currencyLb = new QLabel(CreateOrderRaw);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 1);

        empNamePh = new QLabel(CreateOrderRaw);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 5, 1, 1, 1);

        empPhonePh = new QLabel(CreateOrderRaw);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 5, 5, 1, 1);

        empSurnamePh = new QLabel(CreateOrderRaw);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 5, 3, 1, 1);

        empSurnameLb = new QLabel(CreateOrderRaw);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 5, 2, 1, 1);

        empPhoneLb = new QLabel(CreateOrderRaw);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 5, 4, 1, 1);

        sumLb = new QLabel(CreateOrderRaw);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 1);

        prNameLb = new QLabel(CreateOrderRaw);
        prNameLb->setObjectName(QStringLiteral("prNameLb"));
        prNameLb->setMinimumSize(QSize(50, 0));
        prNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(prNameLb, 1, 0, 1, 1);

        prNamePh = new QLabel(CreateOrderRaw);
        prNamePh->setObjectName(QStringLiteral("prNamePh"));
        prNamePh->setMinimumSize(QSize(100, 0));
        prNamePh->setFont(font);

        gridLayout->addWidget(prNamePh, 1, 1, 1, 1);

        prSurnameLb = new QLabel(CreateOrderRaw);
        prSurnameLb->setObjectName(QStringLiteral("prSurnameLb"));
        prSurnameLb->setMinimumSize(QSize(50, 0));
        prSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(prSurnameLb, 1, 2, 1, 1);

        prSurnamePh = new QLabel(CreateOrderRaw);
        prSurnamePh->setObjectName(QStringLiteral("prSurnamePh"));
        prSurnamePh->setMinimumSize(QSize(100, 0));
        prSurnamePh->setFont(font);

        gridLayout->addWidget(prSurnamePh, 1, 3, 1, 1);

        prPhoneLb = new QLabel(CreateOrderRaw);
        prPhoneLb->setObjectName(QStringLiteral("prPhoneLb"));

        gridLayout->addWidget(prPhoneLb, 1, 4, 1, 1);

        prPhonePh = new QLabel(CreateOrderRaw);
        prPhonePh->setObjectName(QStringLiteral("prPhonePh"));
        prPhonePh->setMinimumSize(QSize(100, 0));
        prPhonePh->setFont(font);

        gridLayout->addWidget(prPhonePh, 1, 5, 1, 1);

        currencyCmb = new QComboBox(CreateOrderRaw);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        sumEdit = new QLineEdit(CreateOrderRaw);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateOrderRaw);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateOrderRaw);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        statusWidget = new QWidget(CreateOrderRaw);
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

        dateEdit = new QDateTimeEdit(CreateOrderRaw);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        execDateWidget = new QWidget(CreateOrderRaw);
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

        prodCountEdit = new QLineEdit(CreateOrderRaw);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        prodCountLb = new QLabel(CreateOrderRaw);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        purveyorBtn = new QPushButton(CreateOrderRaw);
        purveyorBtn->setObjectName(QStringLiteral("purveyorBtn"));
        purveyorBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(purveyorBtn, 0, 0, 1, 2);

        dateLb = new QLabel(CreateOrderRaw);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        purveyorEdit = new QLineEdit(CreateOrderRaw);
        purveyorEdit->setObjectName(QStringLiteral("purveyorEdit"));
        purveyorEdit->setReadOnly(true);

        gridLayout->addWidget(purveyorEdit, 0, 2, 1, 2);

        employeeEdit = new QLineEdit(CreateOrderRaw);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 4, 2, 1, 2);

        employeeBtn = new QPushButton(CreateOrderRaw);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 4, 0, 1, 2);

        addProdBtn = new QPushButton(CreateOrderRaw);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        QWidget::setTabOrder(purveyorBtn, employeeBtn);
        QWidget::setTabOrder(employeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateOrderRaw);

        QMetaObject::connectSlotsByName(CreateOrderRaw);
    } // setupUi

    void retranslateUi(QDialog *CreateOrderRaw)
    {
        CreateOrderRaw->setWindowTitle(QApplication::translate("CreateOrderRaw", "Create/Update order raw", 0));
        empNameLb->setText(QApplication::translate("CreateOrderRaw", "Name:", 0));
        currencyLb->setText(QApplication::translate("CreateOrderRaw", "Select currency:", 0));
        empNamePh->setText(QString());
        empPhonePh->setText(QString());
        empSurnamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateOrderRaw", "Surname:", 0));
        empPhoneLb->setText(QApplication::translate("CreateOrderRaw", "Phone:", 0));
        sumLb->setText(QApplication::translate("CreateOrderRaw", "Total amount:", 0));
        prNameLb->setText(QApplication::translate("CreateOrderRaw", "Name:", 0));
        prNamePh->setText(QString());
        prSurnameLb->setText(QApplication::translate("CreateOrderRaw", "Surname:", 0));
        prSurnamePh->setText(QString());
        prPhoneLb->setText(QApplication::translate("CreateOrderRaw", "Phone:", 0));
        prPhonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateOrderRaw", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateOrderRaw", "Cancel", 0));
        statusBtn->setText(QApplication::translate("CreateOrderRaw", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateOrderRaw", "Status name:", 0));
        statusPh->setText(QString());
        execDateLb->setText(QApplication::translate("CreateOrderRaw", "Execution date:", 0));
        prodCountLb->setText(QApplication::translate("CreateOrderRaw", "Count of products:", 0));
        purveyorBtn->setText(QApplication::translate("CreateOrderRaw", "Select purveyor", 0));
        dateLb->setText(QApplication::translate("CreateOrderRaw", "Consume order raw date:", 0));
#ifndef QT_NO_TOOLTIP
        purveyorEdit->setToolTip(QApplication::translate("CreateOrderRaw", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateOrderRaw", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        employeeBtn->setText(QApplication::translate("CreateOrderRaw", "Select employee", 0));
        addProdBtn->setText(QApplication::translate("CreateOrderRaw", "Add products", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOrderRaw: public Ui_CreateOrderRaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDRDLG_H
