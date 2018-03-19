/********************************************************************************
** Form generated from reading UI file 'CreateRfdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERFDDLG_H
#define UI_CREATERFDDLG_H

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

class Ui_CreateRefund
{
public:
    QGridLayout *gridLayout;
    QLabel *namePh;
    QLabel *phoneLb;
    QLabel *nameLb;
    QLabel *surnameLb;
    QLabel *surnamePh;
    QLabel *valieLb;
    QLabel *dateLb;
    QLabel *phonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *currencyLb;
    QComboBox *currencyCmb;
    QLineEdit *userEdit;
    QLineEdit *valueEdit;
    QDateTimeEdit *dateEdit;
    QPushButton *userBtn;

    void setupUi(QDialog *CreateRefund)
    {
        if (CreateRefund->objectName().isEmpty())
            CreateRefund->setObjectName(QStringLiteral("CreateRefund"));
        CreateRefund->resize(555, 198);
        CreateRefund->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRefund->setModal(false);
        gridLayout = new QGridLayout(CreateRefund);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        namePh = new QLabel(CreateRefund);
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

        phoneLb = new QLabel(CreateRefund);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(60, 0));
        phoneLb->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(phoneLb, 5, 4, 1, 1);

        nameLb = new QLabel(CreateRefund);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 5, 0, 1, 1);

        surnameLb = new QLabel(CreateRefund);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 5, 2, 1, 1);

        surnamePh = new QLabel(CreateRefund);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 5, 3, 1, 1);

        valieLb = new QLabel(CreateRefund);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        dateLb = new QLabel(CreateRefund);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        phonePh = new QLabel(CreateRefund);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 5, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateRefund);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateRefund);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 6);

        currencyLb = new QLabel(CreateRefund);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 6, 0, 1, 2);

        currencyCmb = new QComboBox(CreateRefund);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 6, 2, 1, 2);

        userEdit = new QLineEdit(CreateRefund);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 4, 2, 1, 2);

        valueEdit = new QLineEdit(CreateRefund);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 2, 1, 2);

        dateEdit = new QDateTimeEdit(CreateRefund);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 2);

        userBtn = new QPushButton(CreateRefund);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 4, 0, 1, 2);

        QWidget::setTabOrder(userBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateRefund);

        QMetaObject::connectSlotsByName(CreateRefund);
    } // setupUi

    void retranslateUi(QDialog *CreateRefund)
    {
        CreateRefund->setWindowTitle(QApplication::translate("CreateRefund", "Create/Update refund", 0));
        namePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateRefund", "Phone:", 0));
        nameLb->setText(QApplication::translate("CreateRefund", "Name:", 0));
        surnameLb->setText(QApplication::translate("CreateRefund", "Surname:", 0));
        surnamePh->setText(QString());
        valieLb->setText(QApplication::translate("CreateRefund", "Sum:", 0));
        dateLb->setText(QApplication::translate("CreateRefund", "Date:", 0));
        phonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateRefund", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateRefund", "Cancel", 0));
        currencyLb->setText(QApplication::translate("CreateRefund", "Select currency:", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateRefund", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateRefund", "<html><head/><body><p>For example: 300 (depending on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        userBtn->setText(QApplication::translate("CreateRefund", "Select user", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateRefund: public Ui_CreateRefund {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERFDDLG_H
