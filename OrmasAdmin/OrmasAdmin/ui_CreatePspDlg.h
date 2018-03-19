/********************************************************************************
** Form generated from reading UI file 'CreatePspDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPSPDLG_H
#define UI_CREATEPSPDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_CreatePayslip
{
public:
    QGridLayout *gridLayout;
    QLabel *valieLb;
    QLabel *namePh;
    QLabel *dateLb;
    QLabel *surnameLb;
    QLabel *surnamePh;
    QLabel *phoneLb;
    QLabel *nameLb;
    QLabel *phonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *salaryBtn;
    QLabel *currencyLb;
    QLineEdit *salaryEdit;
    QLineEdit *valueEdit;
    QDateTimeEdit *dateEdit;
    QComboBox *currencyCmb;

    void setupUi(QDialog *CreatePayslip)
    {
        if (CreatePayslip->objectName().isEmpty())
            CreatePayslip->setObjectName(QStringLiteral("CreatePayslip"));
        CreatePayslip->resize(554, 182);
        CreatePayslip->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePayslip->setModal(false);
        gridLayout = new QGridLayout(CreatePayslip);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        valieLb = new QLabel(CreatePayslip);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        namePh = new QLabel(CreatePayslip);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 5, 1, 1, 1);

        dateLb = new QLabel(CreatePayslip);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        surnameLb = new QLabel(CreatePayslip);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 5, 2, 1, 1);

        surnamePh = new QLabel(CreatePayslip);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 5, 3, 1, 1);

        phoneLb = new QLabel(CreatePayslip);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 5, 4, 1, 1);

        nameLb = new QLabel(CreatePayslip);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 5, 0, 1, 1);

        phonePh = new QLabel(CreatePayslip);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 5, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePayslip);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePayslip);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 6);

        salaryBtn = new QPushButton(CreatePayslip);
        salaryBtn->setObjectName(QStringLiteral("salaryBtn"));
        salaryBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(salaryBtn, 4, 0, 1, 2);

        currencyLb = new QLabel(CreatePayslip);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 2);

        salaryEdit = new QLineEdit(CreatePayslip);
        salaryEdit->setObjectName(QStringLiteral("salaryEdit"));
        salaryEdit->setReadOnly(true);

        gridLayout->addWidget(salaryEdit, 4, 2, 1, 2);

        valueEdit = new QLineEdit(CreatePayslip);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 2, 1, 2);

        dateEdit = new QDateTimeEdit(CreatePayslip);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 2);

        currencyCmb = new QComboBox(CreatePayslip);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 6, 2, 1, 2);

        QWidget::setTabOrder(salaryBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePayslip);

        QMetaObject::connectSlotsByName(CreatePayslip);
    } // setupUi

    void retranslateUi(QDialog *CreatePayslip)
    {
        CreatePayslip->setWindowTitle(QApplication::translate("CreatePayslip", "Create/Update payslip", 0));
        valieLb->setText(QApplication::translate("CreatePayslip", "Sum:", 0));
        namePh->setText(QString());
        dateLb->setText(QApplication::translate("CreatePayslip", "Date:", 0));
        surnameLb->setText(QApplication::translate("CreatePayslip", "Surname:", 0));
        surnamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreatePayslip", "Phone:", 0));
        nameLb->setText(QApplication::translate("CreatePayslip", "Name:", 0));
        phonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreatePayslip", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePayslip", "Cancel", 0));
        salaryBtn->setText(QApplication::translate("CreatePayslip", "Select salary", 0));
        currencyLb->setText(QApplication::translate("CreatePayslip", "Select currency:", 0));
#ifndef QT_NO_TOOLTIP
        salaryEdit->setToolTip(QApplication::translate("CreatePayslip", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePayslip", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreatePayslip: public Ui_CreatePayslip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPSPDLG_H
