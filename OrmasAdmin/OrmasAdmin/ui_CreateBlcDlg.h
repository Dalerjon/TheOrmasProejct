/********************************************************************************
** Form generated from reading UI file 'CreateBlcDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBLCDLG_H
#define UI_CREATEBLCDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateBalance
{
public:
    QGridLayout *gridLayout;
    QLabel *surnameLb;
    QLineEdit *valueEdit;
    QLabel *valieLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *surnamePh;
    QLabel *phoneLb;
    QLabel *phonePh;
    QLineEdit *userEdit;
    QLabel *namePh;
    QPushButton *userBtn;
    QLabel *currencyLb;
    QComboBox *currencyCmb;

    void setupUi(QDialog *CreateBalance)
    {
        if (CreateBalance->objectName().isEmpty())
            CreateBalance->setObjectName(QStringLiteral("CreateBalance"));
        CreateBalance->resize(550, 186);
        CreateBalance->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateBalance->setModal(false);
        gridLayout = new QGridLayout(CreateBalance);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        surnameLb = new QLabel(CreateBalance);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 1, 3, 1, 1);

        valueEdit = new QLineEdit(CreateBalance);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 3, 1, 1);

        valieLb = new QLabel(CreateBalance);
        valieLb->setObjectName(QStringLiteral("valieLb"));

        gridLayout->addWidget(valieLb, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateBalance);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateBalance);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 7);

        nameLb = new QLabel(CreateBalance);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        surnamePh = new QLabel(CreateBalance);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 1, 4, 1, 1);

        phoneLb = new QLabel(CreateBalance);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 1, 5, 1, 1);

        phonePh = new QLabel(CreateBalance);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 1, 6, 1, 1);

        userEdit = new QLineEdit(CreateBalance);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 0, 3, 1, 1);

        namePh = new QLabel(CreateBalance);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 1, 2, 1, 1);

        userBtn = new QPushButton(CreateBalance);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 0, 0, 1, 3);

        currencyLb = new QLabel(CreateBalance);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 3, 0, 1, 3);

        currencyCmb = new QComboBox(CreateBalance);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 3, 3, 1, 3);

        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, currencyCmb);
        QWidget::setTabOrder(currencyCmb, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateBalance);

        QMetaObject::connectSlotsByName(CreateBalance);
    } // setupUi

    void retranslateUi(QDialog *CreateBalance)
    {
        CreateBalance->setWindowTitle(QApplication::translate("CreateBalance", "Create/Update balance", 0));
        surnameLb->setText(QApplication::translate("CreateBalance", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateBalance", "<html><head/><body><p>For example: 1000 (depends on currency, for that case 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        valieLb->setText(QApplication::translate("CreateBalance", "Value:", 0));
        okBtn->setText(QApplication::translate("CreateBalance", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateBalance", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateBalance", "Name:", 0));
        surnamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateBalance", "Phone:", 0));
        phonePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateBalance", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        namePh->setText(QString());
        userBtn->setText(QApplication::translate("CreateBalance", "Select user", 0));
        currencyLb->setText(QApplication::translate("CreateBalance", "Select currency:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateBalance: public Ui_CreateBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBLCDLG_H
