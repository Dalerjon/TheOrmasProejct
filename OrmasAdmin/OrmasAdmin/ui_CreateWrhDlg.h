/********************************************************************************
** Form generated from reading UI file 'CreateWrhDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWRHDLG_H
#define UI_CREATEWRHDLG_H

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

class Ui_CreateWarehouse
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLb;
    QLabel *wTypeLb;
    QLabel *label;
    QLineEdit *nameEdit;
    QLineEdit *addressEdit;
    QComboBox *wTypeCmb;
    QLabel *accNameLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *numberEdit;
    QLabel *addressLb;
    QSpacerItem *horizontalSpacer_2;
    QLabel *numberLb;
    QLabel *accNamePh;
    QLineEdit *phoneEdit;
    QLabel *phoneLb;

    void setupUi(QDialog *CreateWarehouse)
    {
        if (CreateWarehouse->objectName().isEmpty())
            CreateWarehouse->setObjectName(QStringLiteral("CreateWarehouse"));
        CreateWarehouse->resize(593, 203);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateWarehouse->sizePolicy().hasHeightForWidth());
        CreateWarehouse->setSizePolicy(sizePolicy);
        CreateWarehouse->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateWarehouse->setModal(false);
        gridLayout = new QGridLayout(CreateWarehouse);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        nameLb = new QLabel(CreateWarehouse);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 2, 0, 1, 1);

        wTypeLb = new QLabel(CreateWarehouse);
        wTypeLb->setObjectName(QStringLiteral("wTypeLb"));
        wTypeLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(wTypeLb, 6, 0, 1, 1);

        label = new QLabel(CreateWarehouse);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        nameEdit = new QLineEdit(CreateWarehouse);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setMinimumSize(QSize(150, 0));
        nameEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        addressEdit = new QLineEdit(CreateWarehouse);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setMinimumSize(QSize(150, 0));
        addressEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(addressEdit, 4, 1, 1, 1);

        wTypeCmb = new QComboBox(CreateWarehouse);
        wTypeCmb->setObjectName(QStringLiteral("wTypeCmb"));
        wTypeCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(wTypeCmb, 6, 1, 1, 1);

        accNameLb = new QLabel(CreateWarehouse);
        accNameLb->setObjectName(QStringLiteral("accNameLb"));

        gridLayout->addWidget(accNameLb, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateWarehouse);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateWarehouse);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 4);

        numberEdit = new QLineEdit(CreateWarehouse);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setMinimumSize(QSize(150, 0));
        numberEdit->setMaximumSize(QSize(150, 16777215));
        numberEdit->setReadOnly(true);

        gridLayout->addWidget(numberEdit, 0, 1, 1, 1);

        addressLb = new QLabel(CreateWarehouse);
        addressLb->setObjectName(QStringLiteral("addressLb"));

        gridLayout->addWidget(addressLb, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        numberLb = new QLabel(CreateWarehouse);
        numberLb->setObjectName(QStringLiteral("numberLb"));
        numberLb->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(numberLb, 0, 0, 1, 1);

        accNamePh = new QLabel(CreateWarehouse);
        accNamePh->setObjectName(QStringLiteral("accNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        accNamePh->setFont(font);

        gridLayout->addWidget(accNamePh, 1, 1, 1, 3);

        phoneEdit = new QLineEdit(CreateWarehouse);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 5, 1, 1, 1);

        phoneLb = new QLabel(CreateWarehouse);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 5, 0, 1, 1);

        QWidget::setTabOrder(nameEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, wTypeCmb);
        QWidget::setTabOrder(wTypeCmb, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, numberEdit);

        retranslateUi(CreateWarehouse);

        QMetaObject::connectSlotsByName(CreateWarehouse);
    } // setupUi

    void retranslateUi(QDialog *CreateWarehouse)
    {
        CreateWarehouse->setWindowTitle(QApplication::translate("CreateWarehouse", "Create/Update warehouse", 0));
        nameLb->setText(QApplication::translate("CreateWarehouse", "Warehouse name:", 0));
        wTypeLb->setText(QApplication::translate("CreateWarehouse", "Select warehouse type:", 0));
        label->setText(QApplication::translate("CreateWarehouse", "Number will generate from other parameters", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateWarehouse", "<html><head/><body><p>For example: Doe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateWarehouse", "<html><head/><body><p>For example: John.Doe@gmail.com (does not mandatory field)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        accNameLb->setText(QApplication::translate("CreateWarehouse", "Account name:", 0));
        okBtn->setText(QApplication::translate("CreateWarehouse", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateWarehouse", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        numberEdit->setToolTip(QApplication::translate("CreateWarehouse", "<html><head/><body><p>For example: John</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addressLb->setText(QApplication::translate("CreateWarehouse", "Address:", 0));
        numberLb->setText(QApplication::translate("CreateWarehouse", "Number:", 0));
        accNamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateWarehouse", "Phone:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateWarehouse: public Ui_CreateWarehouse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWRHDLG_H
