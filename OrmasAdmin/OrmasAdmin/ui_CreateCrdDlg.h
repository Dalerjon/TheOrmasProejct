/********************************************************************************
** Form generated from reading UI file 'CreateCrdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECRDDLG_H
#define UI_CREATECRDDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateCreditor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLineEdit *addressEdit;
    QLineEdit *phoneEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *namePh;
    QLabel *surnameLb;
    QLabel *phoneLb;
    QLabel *nameLb;
    QLabel *surnamePh;
    QLabel *phonePh;
    QPushButton *userBtn;
    QLineEdit *userEdit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *phoneLb_2;
    QLabel *surnameLb_2;
    QLabel *bankNamePh;
    QLabel *bNameLb;
    QLabel *addressPh;
    QLabel *bankPhonePh;
    QLineEdit *bankEdit;
    QPushButton *bankBtn;

    void setupUi(QDialog *CreateCreditor)
    {
        if (CreateCreditor->objectName().isEmpty())
            CreateCreditor->setObjectName(QStringLiteral("CreateCreditor"));
        CreateCreditor->resize(685, 334);
        CreateCreditor->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCreditor->setModal(false);
        gridLayout = new QGridLayout(CreateCreditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCreditor);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCreditor);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 11, 1, 1, 2);

        groupBox = new QGroupBox(CreateCreditor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout_2->addWidget(nameEdit, 0, 1, 1, 1);

        addressEdit = new QLineEdit(groupBox);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout_2->addWidget(addressEdit, 1, 1, 1, 1);

        phoneEdit = new QLineEdit(groupBox);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout_2->addWidget(phoneEdit, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 2);

        groupBox_2 = new QGroupBox(CreateCreditor);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        namePh = new QLabel(groupBox_2);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        namePh->setFont(font);

        gridLayout_3->addWidget(namePh, 1, 1, 1, 1);

        surnameLb = new QLabel(groupBox_2);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(surnameLb, 1, 2, 1, 1);

        phoneLb = new QLabel(groupBox_2);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(50, 0));
        phoneLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(phoneLb, 1, 4, 1, 1);

        nameLb = new QLabel(groupBox_2);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(80, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(nameLb, 1, 0, 1, 1);

        surnamePh = new QLabel(groupBox_2);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout_3->addWidget(surnamePh, 1, 3, 1, 1);

        phonePh = new QLabel(groupBox_2);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout_3->addWidget(phonePh, 1, 5, 1, 1);

        userBtn = new QPushButton(groupBox_2);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(userBtn, 0, 0, 1, 2);

        userEdit = new QLineEdit(groupBox_2);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout_3->addWidget(userEdit, 0, 3, 1, 2);


        gridLayout->addWidget(groupBox_2, 1, 1, 1, 2);

        groupBox_3 = new QGroupBox(CreateCreditor);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        phoneLb_2 = new QLabel(groupBox_3);
        phoneLb_2->setObjectName(QStringLiteral("phoneLb_2"));
        phoneLb_2->setMinimumSize(QSize(50, 0));
        phoneLb_2->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(phoneLb_2, 1, 4, 1, 1);

        surnameLb_2 = new QLabel(groupBox_3);
        surnameLb_2->setObjectName(QStringLiteral("surnameLb_2"));
        surnameLb_2->setMinimumSize(QSize(50, 0));
        surnameLb_2->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(surnameLb_2, 1, 2, 1, 1);

        bankNamePh = new QLabel(groupBox_3);
        bankNamePh->setObjectName(QStringLiteral("bankNamePh"));
        bankNamePh->setMinimumSize(QSize(100, 0));
        bankNamePh->setFont(font);

        gridLayout_4->addWidget(bankNamePh, 1, 1, 1, 1);

        bNameLb = new QLabel(groupBox_3);
        bNameLb->setObjectName(QStringLiteral("bNameLb"));
        bNameLb->setMinimumSize(QSize(80, 0));
        bNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(bNameLb, 1, 0, 1, 1);

        addressPh = new QLabel(groupBox_3);
        addressPh->setObjectName(QStringLiteral("addressPh"));
        addressPh->setMinimumSize(QSize(100, 0));
        addressPh->setFont(font);

        gridLayout_4->addWidget(addressPh, 1, 3, 1, 1);

        bankPhonePh = new QLabel(groupBox_3);
        bankPhonePh->setObjectName(QStringLiteral("bankPhonePh"));
        bankPhonePh->setMinimumSize(QSize(100, 0));
        bankPhonePh->setFont(font);

        gridLayout_4->addWidget(bankPhonePh, 1, 5, 1, 1);

        bankEdit = new QLineEdit(groupBox_3);
        bankEdit->setObjectName(QStringLiteral("bankEdit"));
        bankEdit->setReadOnly(true);

        gridLayout_4->addWidget(bankEdit, 0, 3, 1, 2);

        bankBtn = new QPushButton(groupBox_3);
        bankBtn->setObjectName(QStringLiteral("bankBtn"));
        bankBtn->setMinimumSize(QSize(150, 0));

        gridLayout_4->addWidget(bankBtn, 0, 0, 1, 2);

        bankBtn->raise();
        bNameLb->raise();
        bankNamePh->raise();
        surnameLb_2->raise();
        addressPh->raise();
        phoneLb_2->raise();
        bankPhonePh->raise();
        bankEdit->raise();

        gridLayout->addWidget(groupBox_3, 2, 1, 1, 2);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateCreditor);

        QMetaObject::connectSlotsByName(CreateCreditor);
    } // setupUi

    void retranslateUi(QDialog *CreateCreditor)
    {
        CreateCreditor->setWindowTitle(QApplication::translate("CreateCreditor", "Create/Update creadiotr", 0));
        okBtn->setText(QApplication::translate("CreateCreditor", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCreditor", "Cancel", 0));
        groupBox->setTitle(QApplication::translate("CreateCreditor", "Enter creditor data:", 0));
        label_2->setText(QApplication::translate("CreateCreditor", "Address:", 0));
        label->setText(QApplication::translate("CreateCreditor", "Name/Surname:", 0));
        label_3->setText(QApplication::translate("CreateCreditor", "Phone:", 0));
        groupBox_2->setTitle(QApplication::translate("CreateCreditor", "Or select user:", 0));
        namePh->setText(QString());
        surnameLb->setText(QApplication::translate("CreateCreditor", "Surname:", 0));
        phoneLb->setText(QApplication::translate("CreateCreditor", "Phone:", 0));
        nameLb->setText(QApplication::translate("CreateCreditor", "Name:", 0));
        surnamePh->setText(QString());
        phonePh->setText(QString());
        userBtn->setText(QApplication::translate("CreateCreditor", "Select user", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateCreditor", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("CreateCreditor", "Or select bank:", 0));
        phoneLb_2->setText(QApplication::translate("CreateCreditor", "Phone:", 0));
        surnameLb_2->setText(QApplication::translate("CreateCreditor", "Address:", 0));
        bankNamePh->setText(QString());
        bNameLb->setText(QApplication::translate("CreateCreditor", "Bank name:", 0));
        addressPh->setText(QString());
        bankPhonePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        bankEdit->setToolTip(QApplication::translate("CreateCreditor", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        bankBtn->setText(QApplication::translate("CreateCreditor", "Select bank", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateCreditor: public Ui_CreateCreditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECRDDLG_H
