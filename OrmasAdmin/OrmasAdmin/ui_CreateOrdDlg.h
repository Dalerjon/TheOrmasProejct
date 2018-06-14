/********************************************************************************
** Form generated from reading UI file 'CreateOrdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDDLG_H
#define UI_CREATEORDDLG_H

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

class Ui_CreateOrder
{
public:
    QGridLayout *gridLayout;
    QLabel *clNamePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *empNamePh;
    QLabel *empNameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *clSurnamePh;
    QLabel *clPhonePh;
    QLabel *clPhoneLb;
    QLabel *empSurnameLb;
    QLabel *empPhonePh;
    QLabel *clNameLb;
    QLabel *nlSurnameLb;
    QLabel *dateLb;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *currencyLb;
    QLabel *sumLb;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QDateTimeEdit *dateEdit;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QPushButton *addProdBtn;
    QPushButton *employeeBtn;
    QPushButton *clientBtn;
    QComboBox *currencyCmb;
    QLineEdit *sumEdit;
    QLineEdit *employeeEdit;
    QLineEdit *clientEdit;

    void setupUi(QDialog *CreateOrder)
    {
        if (CreateOrder->objectName().isEmpty())
            CreateOrder->setObjectName(QStringLiteral("CreateOrder"));
        CreateOrder->resize(700, 320);
        CreateOrder->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateOrder->setModal(false);
        gridLayout = new QGridLayout(CreateOrder);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        clNamePh = new QLabel(CreateOrder);
        clNamePh->setObjectName(QStringLiteral("clNamePh"));
        clNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        clNamePh->setFont(font);

        gridLayout->addWidget(clNamePh, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateOrder);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateOrder);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        empNamePh = new QLabel(CreateOrder);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 5, 1, 1, 1);

        empNameLb = new QLabel(CreateOrder);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 5, 0, 1, 1);

        empSurnamePh = new QLabel(CreateOrder);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 5, 3, 1, 1);

        empPhoneLb = new QLabel(CreateOrder);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 5, 4, 1, 1);

        clSurnamePh = new QLabel(CreateOrder);
        clSurnamePh->setObjectName(QStringLiteral("clSurnamePh"));
        clSurnamePh->setMinimumSize(QSize(100, 0));
        clSurnamePh->setFont(font);

        gridLayout->addWidget(clSurnamePh, 1, 3, 1, 1);

        clPhonePh = new QLabel(CreateOrder);
        clPhonePh->setObjectName(QStringLiteral("clPhonePh"));
        clPhonePh->setMinimumSize(QSize(100, 0));
        clPhonePh->setFont(font);

        gridLayout->addWidget(clPhonePh, 1, 5, 1, 1);

        clPhoneLb = new QLabel(CreateOrder);
        clPhoneLb->setObjectName(QStringLiteral("clPhoneLb"));

        gridLayout->addWidget(clPhoneLb, 1, 4, 1, 1);

        empSurnameLb = new QLabel(CreateOrder);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 5, 2, 1, 1);

        empPhonePh = new QLabel(CreateOrder);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 5, 5, 1, 1);

        clNameLb = new QLabel(CreateOrder);
        clNameLb->setObjectName(QStringLiteral("clNameLb"));
        clNameLb->setMinimumSize(QSize(50, 0));
        clNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(clNameLb, 1, 0, 1, 1);

        nlSurnameLb = new QLabel(CreateOrder);
        nlSurnameLb->setObjectName(QStringLiteral("nlSurnameLb"));
        nlSurnameLb->setMinimumSize(QSize(50, 0));
        nlSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nlSurnameLb, 1, 2, 1, 1);

        dateLb = new QLabel(CreateOrder);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 1);

        statusWidget = new QWidget(CreateOrder);
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

        currencyLb = new QLabel(CreateOrder);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 2);

        sumLb = new QLabel(CreateOrder);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 2);

        prodCountEdit = new QLineEdit(CreateOrder);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        prodCountLb = new QLabel(CreateOrder);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateOrder);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        execDateWidget = new QWidget(CreateOrder);
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
        execDateLb->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(execDateLb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        execDateEdit = new QDateTimeEdit(execDateWidget);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));
        execDateEdit->setMinimumSize(QSize(155, 0));

        horizontalLayout_2->addWidget(execDateEdit);


        gridLayout->addWidget(execDateWidget, 3, 0, 1, 4);

        addProdBtn = new QPushButton(CreateOrder);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        employeeBtn = new QPushButton(CreateOrder);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 4, 0, 1, 2);

        clientBtn = new QPushButton(CreateOrder);
        clientBtn->setObjectName(QStringLiteral("clientBtn"));
        clientBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(clientBtn, 0, 0, 1, 2);

        currencyCmb = new QComboBox(CreateOrder);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        sumEdit = new QLineEdit(CreateOrder);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        employeeEdit = new QLineEdit(CreateOrder);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 4, 2, 1, 2);

        clientEdit = new QLineEdit(CreateOrder);
        clientEdit->setObjectName(QStringLiteral("clientEdit"));
        clientEdit->setReadOnly(true);

        gridLayout->addWidget(clientEdit, 0, 2, 1, 2);

        QWidget::setTabOrder(clientBtn, employeeBtn);
        QWidget::setTabOrder(employeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateOrder);

        QMetaObject::connectSlotsByName(CreateOrder);
    } // setupUi

    void retranslateUi(QDialog *CreateOrder)
    {
        CreateOrder->setWindowTitle(QApplication::translate("CreateOrder", "Create/Update order", 0));
        clNamePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateOrder", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateOrder", "Cancel", 0));
        empNamePh->setText(QString());
        empNameLb->setText(QApplication::translate("CreateOrder", "Name:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateOrder", "Phone:", 0));
        clSurnamePh->setText(QString());
        clPhonePh->setText(QString());
        clPhoneLb->setText(QApplication::translate("CreateOrder", "Phone:", 0));
        empSurnameLb->setText(QApplication::translate("CreateOrder", "Surname:", 0));
        empPhonePh->setText(QString());
        clNameLb->setText(QApplication::translate("CreateOrder", "Name:", 0));
        nlSurnameLb->setText(QApplication::translate("CreateOrder", "Surname:", 0));
        dateLb->setText(QApplication::translate("CreateOrder", "Order date:", 0));
        statusBtn->setText(QApplication::translate("CreateOrder", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateOrder", "Status name:", 0));
        statusPh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateOrder", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateOrder", "Total amount:", 0));
        prodCountLb->setText(QApplication::translate("CreateOrder", "Count of products:", 0));
        execDateLb->setText(QApplication::translate("CreateOrder", "Execution date:", 0));
        addProdBtn->setText(QApplication::translate("CreateOrder", "Add products", 0));
        employeeBtn->setText(QApplication::translate("CreateOrder", "Select employee", 0));
        clientBtn->setText(QApplication::translate("CreateOrder", "Select client", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateOrder", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        clientEdit->setToolTip(QApplication::translate("CreateOrder", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateOrder: public Ui_CreateOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDDLG_H
