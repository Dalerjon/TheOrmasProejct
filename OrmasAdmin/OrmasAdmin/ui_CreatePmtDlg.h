/********************************************************************************
** Form generated from reading UI file 'CreatePmtDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPMTDLG_H
#define UI_CREATEPMTDLG_H

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

class Ui_CreatePayment
{
public:
    QGridLayout *gridLayout;
    QLabel *surnamePh;
    QLabel *surnameLb;
    QLabel *phoneLb;
    QLabel *phonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *dateLb;
    QLabel *valieLb;
    QLabel *namePh;
    QLabel *currencyLb;
    QPushButton *userBtn;
    QComboBox *currencyCmb;
    QLineEdit *userEdit;
    QLineEdit *valueEdit;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreatePayment)
    {
        if (CreatePayment->objectName().isEmpty())
            CreatePayment->setObjectName(QStringLiteral("CreatePayment"));
        CreatePayment->resize(556, 180);
        CreatePayment->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePayment->setModal(false);
        gridLayout = new QGridLayout(CreatePayment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        surnamePh = new QLabel(CreatePayment);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 5, 3, 1, 1);

        surnameLb = new QLabel(CreatePayment);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 5, 2, 1, 1);

        phoneLb = new QLabel(CreatePayment);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 5, 4, 1, 1);

        phonePh = new QLabel(CreatePayment);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 5, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePayment);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePayment);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 6);

        nameLb = new QLabel(CreatePayment);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 5, 0, 1, 1);

        dateLb = new QLabel(CreatePayment);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        valieLb = new QLabel(CreatePayment);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        namePh = new QLabel(CreatePayment);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 5, 1, 1, 1);

        currencyLb = new QLabel(CreatePayment);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 2);

        userBtn = new QPushButton(CreatePayment);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 4, 0, 1, 2);

        currencyCmb = new QComboBox(CreatePayment);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 6, 2, 1, 2);

        userEdit = new QLineEdit(CreatePayment);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 4, 3, 1, 1);

        valueEdit = new QLineEdit(CreatePayment);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 3, 1, 1);

        dateEdit = new QDateTimeEdit(CreatePayment);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 3, 1, 1);

        QWidget::setTabOrder(userBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePayment);

        QMetaObject::connectSlotsByName(CreatePayment);
    } // setupUi

    void retranslateUi(QDialog *CreatePayment)
    {
        CreatePayment->setWindowTitle(QApplication::translate("CreatePayment", "Create/Update payment", 0));
        surnamePh->setText(QString());
        surnameLb->setText(QApplication::translate("CreatePayment", "Surname:", 0));
        phoneLb->setText(QApplication::translate("CreatePayment", "Phone:", 0));
        phonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreatePayment", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePayment", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreatePayment", "Name:", 0));
        dateLb->setText(QApplication::translate("CreatePayment", "Date:", 0));
        valieLb->setText(QApplication::translate("CreatePayment", "Sum:", 0));
        namePh->setText(QString());
        currencyLb->setText(QApplication::translate("CreatePayment", "Select currency:", 0));
        userBtn->setText(QApplication::translate("CreatePayment", "Select user", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreatePayment", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreatePayment", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreatePayment: public Ui_CreatePayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPMTDLG_H
