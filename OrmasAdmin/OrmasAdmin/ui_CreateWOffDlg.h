/********************************************************************************
** Form generated from reading UI file 'CreateWOffDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWOFFDLG_H
#define UI_CREATEWOFFDLG_H

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

class Ui_CreateWriteOff
{
public:
    QGridLayout *gridLayout;
    QLabel *clNameLb;
    QLabel *clPhonePh;
    QLabel *clNamePh;
    QLabel *clPhoneLb;
    QLabel *clSurnameLb;
    QLabel *clSurnamePh;
    QLabel *dateLb;
    QLabel *empNameLb;
    QLabel *empNamePh;
    QLabel *empSurnameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *empPhonePh;
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
    QComboBox *currencyCmb;
    QDateTimeEdit *dateEdit;
    QLabel *currencyLb;
    QLabel *sumLb;
    QPushButton *employeeBtn;
    QPushButton *clientBtn;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QPushButton *addProdBtn;
    QLineEdit *clientEdit;
    QLineEdit *employeeEdit;

    void setupUi(QDialog *CreateWriteOff)
    {
        if (CreateWriteOff->objectName().isEmpty())
            CreateWriteOff->setObjectName(QStringLiteral("CreateWriteOff"));
        CreateWriteOff->resize(633, 293);
        CreateWriteOff->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWriteOff->setModal(false);
        gridLayout = new QGridLayout(CreateWriteOff);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        clNameLb = new QLabel(CreateWriteOff);
        clNameLb->setObjectName(QStringLiteral("clNameLb"));
        clNameLb->setMinimumSize(QSize(50, 0));
        clNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(clNameLb, 1, 0, 1, 1);

        clPhonePh = new QLabel(CreateWriteOff);
        clPhonePh->setObjectName(QStringLiteral("clPhonePh"));
        clPhonePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        clPhonePh->setFont(font);

        gridLayout->addWidget(clPhonePh, 1, 5, 1, 1);

        clNamePh = new QLabel(CreateWriteOff);
        clNamePh->setObjectName(QStringLiteral("clNamePh"));
        clNamePh->setMinimumSize(QSize(100, 0));
        clNamePh->setFont(font);

        gridLayout->addWidget(clNamePh, 1, 1, 1, 1);

        clPhoneLb = new QLabel(CreateWriteOff);
        clPhoneLb->setObjectName(QStringLiteral("clPhoneLb"));

        gridLayout->addWidget(clPhoneLb, 1, 4, 1, 1);

        clSurnameLb = new QLabel(CreateWriteOff);
        clSurnameLb->setObjectName(QStringLiteral("clSurnameLb"));
        clSurnameLb->setMinimumSize(QSize(50, 0));
        clSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(clSurnameLb, 1, 2, 1, 1);

        clSurnamePh = new QLabel(CreateWriteOff);
        clSurnamePh->setObjectName(QStringLiteral("clSurnamePh"));
        clSurnamePh->setMinimumSize(QSize(100, 0));
        clSurnamePh->setFont(font);

        gridLayout->addWidget(clSurnamePh, 1, 3, 1, 1);

        dateLb = new QLabel(CreateWriteOff);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 2, 0, 1, 1);

        empNameLb = new QLabel(CreateWriteOff);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 4, 0, 1, 1);

        empNamePh = new QLabel(CreateWriteOff);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 4, 1, 1, 1);

        empSurnameLb = new QLabel(CreateWriteOff);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 4, 2, 1, 1);

        empSurnamePh = new QLabel(CreateWriteOff);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 4, 3, 1, 1);

        empPhoneLb = new QLabel(CreateWriteOff);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 4, 4, 1, 1);

        empPhonePh = new QLabel(CreateWriteOff);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 4, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWriteOff);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWriteOff);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 6);

        statusWidget = new QWidget(CreateWriteOff);
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


        gridLayout->addWidget(statusWidget, 6, 0, 1, 6);

        sumEdit = new QLineEdit(CreateWriteOff);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 7, 2, 1, 1);

        currencyCmb = new QComboBox(CreateWriteOff);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 8, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateWriteOff);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 2, 1, 1);

        currencyLb = new QLabel(CreateWriteOff);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 8, 0, 1, 2);

        sumLb = new QLabel(CreateWriteOff);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 7, 0, 1, 2);

        employeeBtn = new QPushButton(CreateWriteOff);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 3, 0, 1, 2);

        clientBtn = new QPushButton(CreateWriteOff);
        clientBtn->setObjectName(QStringLiteral("clientBtn"));
        clientBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(clientBtn, 0, 0, 1, 2);

        prodCountEdit = new QLineEdit(CreateWriteOff);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 5, 3, 1, 1);

        prodCountLb = new QLabel(CreateWriteOff);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 5, 2, 1, 1);

        addProdBtn = new QPushButton(CreateWriteOff);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 5, 0, 1, 2);

        clientEdit = new QLineEdit(CreateWriteOff);
        clientEdit->setObjectName(QStringLiteral("clientEdit"));
        clientEdit->setReadOnly(true);

        gridLayout->addWidget(clientEdit, 0, 2, 1, 2);

        employeeEdit = new QLineEdit(CreateWriteOff);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 3, 2, 1, 2);

        QWidget::setTabOrder(clientBtn, employeeBtn);
        QWidget::setTabOrder(employeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateWriteOff);

        QMetaObject::connectSlotsByName(CreateWriteOff);
    } // setupUi

    void retranslateUi(QDialog *CreateWriteOff)
    {
        CreateWriteOff->setWindowTitle(QApplication::translate("CreateWriteOff", "Create/Update write-off", 0));
        clNameLb->setText(QApplication::translate("CreateWriteOff", "Name:", 0));
        clPhonePh->setText(QString());
        clNamePh->setText(QString());
        clPhoneLb->setText(QApplication::translate("CreateWriteOff", "Phone:", 0));
        clSurnameLb->setText(QApplication::translate("CreateWriteOff", "Surname:", 0));
        clSurnamePh->setText(QString());
        dateLb->setText(QApplication::translate("CreateWriteOff", "Date of write-off:", 0));
        empNameLb->setText(QApplication::translate("CreateWriteOff", "Name:", 0));
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateWriteOff", "Surname:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateWriteOff", "Phone:", 0));
        empPhonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateWriteOff", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWriteOff", "Cancel", 0));
        statusBtn->setText(QApplication::translate("CreateWriteOff", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateWriteOff", "Status name:", 0));
        statusPh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateWriteOff", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateWriteOff", "Total amount:", 0));
        employeeBtn->setText(QApplication::translate("CreateWriteOff", "Select employee", 0));
        clientBtn->setText(QApplication::translate("CreateWriteOff", "Select client", 0));
        prodCountLb->setText(QApplication::translate("CreateWriteOff", "Count of products:", 0));
        addProdBtn->setText(QApplication::translate("CreateWriteOff", "Add products", 0));
#ifndef QT_NO_TOOLTIP
        clientEdit->setToolTip(QApplication::translate("CreateWriteOff", "<html><head/><body><p>Enter client ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateWriteOff", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateWriteOff: public Ui_CreateWriteOff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWOFFDLG_H
