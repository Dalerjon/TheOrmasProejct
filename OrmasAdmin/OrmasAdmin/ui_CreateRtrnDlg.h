/********************************************************************************
** Form generated from reading UI file 'CreateRtrnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERTRNDLG_H
#define UI_CREATERTRNDLG_H

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

class Ui_CreateReturn
{
public:
    QGridLayout *gridLayout;
    QPushButton *addProdBtn;
    QLabel *empPhonePh;
    QLabel *empPhoneLb;
    QLabel *empSurnamePh;
    QLabel *empNamePh;
    QLabel *empSurnameLb;
    QLabel *empNameLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *sumLb;
    QPushButton *clientBtn;
    QLabel *clPhonePh;
    QLabel *clPhoneLb;
    QLabel *clSurnamePh;
    QLabel *clSurnameLb;
    QLabel *clNamePh;
    QLabel *clNameLb;
    QLineEdit *employeeEdit;
    QLineEdit *clientEdit;
    QLabel *currencyLb;
    QLabel *dateLb;
    QWidget *execDateWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *execDateLb;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *execDateEdit;
    QLabel *prodCountLb;
    QLineEdit *prodCountEdit;
    QPushButton *employeeBtn;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QComboBox *currencyCmb;
    QLineEdit *sumEdit;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateReturn)
    {
        if (CreateReturn->objectName().isEmpty())
            CreateReturn->setObjectName(QStringLiteral("CreateReturn"));
        CreateReturn->resize(700, 320);
        CreateReturn->setMinimumSize(QSize(150, 0));
        CreateReturn->setMaximumSize(QSize(16777215, 16777215));
        CreateReturn->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateReturn->setModal(false);
        gridLayout = new QGridLayout(CreateReturn);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        addProdBtn = new QPushButton(CreateReturn);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 6, 0, 1, 2);

        empPhonePh = new QLabel(CreateReturn);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 5, 5, 1, 1);

        empPhoneLb = new QLabel(CreateReturn);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 5, 4, 1, 1);

        empSurnamePh = new QLabel(CreateReturn);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 5, 3, 1, 1);

        empNamePh = new QLabel(CreateReturn);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 5, 1, 1, 1);

        empSurnameLb = new QLabel(CreateReturn);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 5, 2, 1, 1);

        empNameLb = new QLabel(CreateReturn);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateReturn);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateReturn);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 6);

        sumLb = new QLabel(CreateReturn);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 8, 0, 1, 2);

        clientBtn = new QPushButton(CreateReturn);
        clientBtn->setObjectName(QStringLiteral("clientBtn"));
        clientBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(clientBtn, 0, 0, 1, 2);

        clPhonePh = new QLabel(CreateReturn);
        clPhonePh->setObjectName(QStringLiteral("clPhonePh"));
        clPhonePh->setMinimumSize(QSize(100, 0));
        clPhonePh->setFont(font);

        gridLayout->addWidget(clPhonePh, 1, 5, 1, 1);

        clPhoneLb = new QLabel(CreateReturn);
        clPhoneLb->setObjectName(QStringLiteral("clPhoneLb"));

        gridLayout->addWidget(clPhoneLb, 1, 4, 1, 1);

        clSurnamePh = new QLabel(CreateReturn);
        clSurnamePh->setObjectName(QStringLiteral("clSurnamePh"));
        clSurnamePh->setMinimumSize(QSize(100, 0));
        clSurnamePh->setFont(font);

        gridLayout->addWidget(clSurnamePh, 1, 3, 1, 1);

        clSurnameLb = new QLabel(CreateReturn);
        clSurnameLb->setObjectName(QStringLiteral("clSurnameLb"));
        clSurnameLb->setMinimumSize(QSize(50, 0));
        clSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(clSurnameLb, 1, 2, 1, 1);

        clNamePh = new QLabel(CreateReturn);
        clNamePh->setObjectName(QStringLiteral("clNamePh"));
        clNamePh->setMinimumSize(QSize(100, 0));
        clNamePh->setFont(font);

        gridLayout->addWidget(clNamePh, 1, 1, 1, 1);

        clNameLb = new QLabel(CreateReturn);
        clNameLb->setObjectName(QStringLiteral("clNameLb"));
        clNameLb->setMinimumSize(QSize(50, 0));
        clNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(clNameLb, 1, 0, 1, 1);

        employeeEdit = new QLineEdit(CreateReturn);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 4, 2, 1, 2);

        clientEdit = new QLineEdit(CreateReturn);
        clientEdit->setObjectName(QStringLiteral("clientEdit"));
        clientEdit->setReadOnly(true);

        gridLayout->addWidget(clientEdit, 0, 2, 1, 2);

        currencyLb = new QLabel(CreateReturn);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 9, 0, 1, 2);

        dateLb = new QLabel(CreateReturn);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 2);

        execDateWidget = new QWidget(CreateReturn);
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

        prodCountLb = new QLabel(CreateReturn);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 6, 2, 1, 1);

        prodCountEdit = new QLineEdit(CreateReturn);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 6, 3, 1, 1);

        employeeBtn = new QPushButton(CreateReturn);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 4, 0, 1, 2);

        statusWidget = new QWidget(CreateReturn);
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

        currencyCmb = new QComboBox(CreateReturn);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 9, 2, 1, 1);

        sumEdit = new QLineEdit(CreateReturn);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 8, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateReturn);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(dateEdit, 2, 3, 1, 1);

        QWidget::setTabOrder(clientBtn, employeeBtn);
        QWidget::setTabOrder(employeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateReturn);

        QMetaObject::connectSlotsByName(CreateReturn);
    } // setupUi

    void retranslateUi(QDialog *CreateReturn)
    {
        CreateReturn->setWindowTitle(QApplication::translate("CreateReturn", "Create/Update return", 0));
        addProdBtn->setText(QApplication::translate("CreateReturn", "Add products", 0));
        empPhonePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateReturn", "Phone:", 0));
        empSurnamePh->setText(QString());
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateReturn", "Surname:", 0));
        empNameLb->setText(QApplication::translate("CreateReturn", "Name:", 0));
        okBtn->setText(QApplication::translate("CreateReturn", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateReturn", "Cancel", 0));
        sumLb->setText(QApplication::translate("CreateReturn", "Total amount:", 0));
        clientBtn->setText(QApplication::translate("CreateReturn", "Select client", 0));
        clPhonePh->setText(QString());
        clPhoneLb->setText(QApplication::translate("CreateReturn", "Phone:", 0));
        clSurnamePh->setText(QString());
        clSurnameLb->setText(QApplication::translate("CreateReturn", "Surname:", 0));
        clNamePh->setText(QString());
        clNameLb->setText(QApplication::translate("CreateReturn", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateReturn", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        clientEdit->setToolTip(QApplication::translate("CreateReturn", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currencyLb->setText(QApplication::translate("CreateReturn", "Select currency:", 0));
        dateLb->setText(QApplication::translate("CreateReturn", "Return date:", 0));
        execDateLb->setText(QApplication::translate("CreateReturn", "Execution date:", 0));
        prodCountLb->setText(QApplication::translate("CreateReturn", "Count of products:", 0));
        employeeBtn->setText(QApplication::translate("CreateReturn", "Select employee", 0));
        statusBtn->setText(QApplication::translate("CreateReturn", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateReturn", "Status name:", 0));
        statusPh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateReturn: public Ui_CreateReturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERTRNDLG_H
