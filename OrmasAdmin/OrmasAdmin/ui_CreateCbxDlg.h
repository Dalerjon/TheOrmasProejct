/********************************************************************************
** Form generated from reading UI file 'CreateCbxDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECBXDLG_H
#define UI_CREATECBXDLG_H

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

class Ui_CreateCashbox
{
public:
    QGridLayout *gridLayout;
    QLabel *infoLb;
    QLabel *numberLb;
    QLabel *accNamePh;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *numberEdit;
    QLabel *addressLb;
    QLabel *currencyLb;
    QComboBox *currencyCmb;
    QLabel *accNameLb;
    QLineEdit *informationEdit;
    QLineEdit *addressEdit;
    QLabel *label;

    void setupUi(QDialog *CreateCashbox)
    {
        if (CreateCashbox->objectName().isEmpty())
            CreateCashbox->setObjectName(QStringLiteral("CreateCashbox"));
        CreateCashbox->resize(593, 177);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCashbox->sizePolicy().hasHeightForWidth());
        CreateCashbox->setSizePolicy(sizePolicy);
        CreateCashbox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCashbox->setModal(false);
        gridLayout = new QGridLayout(CreateCashbox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        infoLb = new QLabel(CreateCashbox);
        infoLb->setObjectName(QStringLiteral("infoLb"));

        gridLayout->addWidget(infoLb, 2, 0, 1, 1);

        numberLb = new QLabel(CreateCashbox);
        numberLb->setObjectName(QStringLiteral("numberLb"));
        numberLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(numberLb, 0, 0, 1, 1);

        accNamePh = new QLabel(CreateCashbox);
        accNamePh->setObjectName(QStringLiteral("accNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        accNamePh->setFont(font);

        gridLayout->addWidget(accNamePh, 1, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCashbox);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCashbox);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 4);

        numberEdit = new QLineEdit(CreateCashbox);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setMinimumSize(QSize(150, 0));
        numberEdit->setMaximumSize(QSize(150, 16777215));
        numberEdit->setReadOnly(true);

        gridLayout->addWidget(numberEdit, 0, 1, 1, 1);

        addressLb = new QLabel(CreateCashbox);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 4, 0, 1, 1);

        currencyLb = new QLabel(CreateCashbox);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));
        currencyLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(currencyLb, 5, 0, 1, 1);

        currencyCmb = new QComboBox(CreateCashbox);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(currencyCmb, 5, 1, 1, 1);

        accNameLb = new QLabel(CreateCashbox);
        accNameLb->setObjectName(QStringLiteral("accNameLb"));

        gridLayout->addWidget(accNameLb, 1, 0, 1, 1);

        informationEdit = new QLineEdit(CreateCashbox);
        informationEdit->setObjectName(QStringLiteral("informationEdit"));
        informationEdit->setMinimumSize(QSize(150, 0));
        informationEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(informationEdit, 2, 1, 1, 1);

        addressEdit = new QLineEdit(CreateCashbox);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setMinimumSize(QSize(150, 0));
        addressEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(addressEdit, 4, 1, 1, 1);

        label = new QLabel(CreateCashbox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        QWidget::setTabOrder(informationEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, currencyCmb);
        QWidget::setTabOrder(currencyCmb, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, numberEdit);

        retranslateUi(CreateCashbox);

        QMetaObject::connectSlotsByName(CreateCashbox);
    } // setupUi

    void retranslateUi(QDialog *CreateCashbox)
    {
        CreateCashbox->setWindowTitle(QApplication::translate("CreateCashbox", "Create/Update cashbox", 0));
        infoLb->setText(QApplication::translate("CreateCashbox", "Information:", 0));
        numberLb->setText(QApplication::translate("CreateCashbox", "Number:", 0));
        accNamePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateCashbox", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCashbox", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        numberEdit->setToolTip(QApplication::translate("CreateCashbox", "<html><head/><body><p>For example: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addressLb->setText(QApplication::translate("CreateCashbox", "Address:", 0));
        currencyLb->setText(QApplication::translate("CreateCashbox", "Select currency:", 0));
        accNameLb->setText(QApplication::translate("CreateCashbox", "Account name:", 0));
#ifndef QT_NO_TOOLTIP
        informationEdit->setToolTip(QApplication::translate("CreateCashbox", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateCashbox", "<html><head/><body><p>For example: John.Doe@gmail.com (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("CreateCashbox", "Number will generate from other parameters", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateCashbox: public Ui_CreateCashbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECBXDLG_H
