/********************************************************************************
** Form generated from reading UI file 'CreateSplDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESPLDLG_H
#define UI_CREATESPLDLG_H

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

class Ui_CreateSpoilage
{
public:
    QGridLayout *gridLayout;
    QLineEdit *sumEdit;
    QLineEdit *employeeEdit;
    QLabel *empNamePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *empNameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *empSurnameLb;
    QLabel *empPhonePh;
    QLabel *currencyLb;
    QLabel *sumLb;
    QLineEdit *prodCountEdit;
    QLabel *prodCountLb;
    QPushButton *employeeBtn;
    QComboBox *currencyCmb;
    QDateTimeEdit *dateEdit;
    QPushButton *addProdBtn;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *dateLb;

    void setupUi(QDialog *CreateSpoilage)
    {
        if (CreateSpoilage->objectName().isEmpty())
            CreateSpoilage->setObjectName(QStringLiteral("CreateSpoilage"));
        CreateSpoilage->resize(633, 238);
        CreateSpoilage->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSpoilage->setModal(false);
        gridLayout = new QGridLayout(CreateSpoilage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        sumEdit = new QLineEdit(CreateSpoilage);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 5, 2, 1, 1);

        employeeEdit = new QLineEdit(CreateSpoilage);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 1, 2, 1, 2);

        empNamePh = new QLabel(CreateSpoilage);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateSpoilage);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateSpoilage);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 6);

        empNameLb = new QLabel(CreateSpoilage);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 2, 0, 1, 1);

        empSurnamePh = new QLabel(CreateSpoilage);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 2, 3, 1, 1);

        empPhoneLb = new QLabel(CreateSpoilage);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 2, 4, 1, 1);

        empSurnameLb = new QLabel(CreateSpoilage);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 2, 2, 1, 1);

        empPhonePh = new QLabel(CreateSpoilage);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 2, 5, 1, 1);

        currencyLb = new QLabel(CreateSpoilage);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 2);

        sumLb = new QLabel(CreateSpoilage);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 5, 0, 1, 2);

        prodCountEdit = new QLineEdit(CreateSpoilage);
        prodCountEdit->setObjectName(QStringLiteral("prodCountEdit"));
        prodCountEdit->setReadOnly(true);

        gridLayout->addWidget(prodCountEdit, 3, 3, 1, 1);

        prodCountLb = new QLabel(CreateSpoilage);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 3, 2, 1, 1);

        employeeBtn = new QPushButton(CreateSpoilage);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 1, 0, 1, 2);

        currencyCmb = new QComboBox(CreateSpoilage);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 6, 2, 1, 1);

        dateEdit = new QDateTimeEdit(CreateSpoilage);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 3, 1, 1);

        addProdBtn = new QPushButton(CreateSpoilage);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));

        gridLayout->addWidget(addProdBtn, 3, 0, 1, 2);

        statusWidget = new QWidget(CreateSpoilage);
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


        gridLayout->addWidget(statusWidget, 4, 0, 1, 6);

        dateLb = new QLabel(CreateSpoilage);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 2);

        QWidget::setTabOrder(employeeBtn, addProdBtn);
        QWidget::setTabOrder(addProdBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateSpoilage);

        QMetaObject::connectSlotsByName(CreateSpoilage);
    } // setupUi

    void retranslateUi(QDialog *CreateSpoilage)
    {
        CreateSpoilage->setWindowTitle(QApplication::translate("CreateSpoilage", "Create/Update spoilage", 0));
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateSpoilage", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        empNamePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateSpoilage", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSpoilage", "Cancel", 0));
        empNameLb->setText(QApplication::translate("CreateSpoilage", "Name:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateSpoilage", "Phone:", 0));
        empSurnameLb->setText(QApplication::translate("CreateSpoilage", "Surname:", 0));
        empPhonePh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateSpoilage", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateSpoilage", "Total amount:", 0));
        prodCountLb->setText(QApplication::translate("CreateSpoilage", "Count of products:", 0));
        employeeBtn->setText(QApplication::translate("CreateSpoilage", "Select employee", 0));
        addProdBtn->setText(QApplication::translate("CreateSpoilage", "Add products", 0));
        statusBtn->setText(QApplication::translate("CreateSpoilage", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateSpoilage", "Status name:", 0));
        statusPh->setText(QString());
        dateLb->setText(QApplication::translate("CreateSpoilage", "Spoilage date:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateSpoilage: public Ui_CreateSpoilage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESPLDLG_H
