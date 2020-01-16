/********************************************************************************
** Form generated from reading UI file 'CreateInveDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEINVEDLG_H
#define UI_CREATEINVEDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_CreateInventory
{
public:
    QGridLayout *gridLayout;
    QPushButton *statusBtn;
    QCheckBox *newInvCxb;
    QLineEdit *locationEdit;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *label_4;
    QLineEdit *numberEdit;
    QLabel *label_5;
    QComboBox *divisionCmb;
    QLabel *label_6;
    QLineEdit *barcodeEdit;
    QLabel *label_7;
    QDateEdit *startDateEdit;
    QLabel *label_8;
    QDateEdit *endDateEdit;
    QLineEdit *costEdit;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *statusEdit;
    QGroupBox *sourceGbx;
    QGridLayout *gridLayout_5;
    QPushButton *accableBtn;
    QLabel *surnameLb;
    QPushButton *purveyorBtn;
    QLabel *label_9;
    QLineEdit *accID;
    QLineEdit *purEditID;
    QLineEdit *accableIDEdit;
    QPushButton *accountBtn;
    QLabel *label_10;
    QLabel *accountName;

    void setupUi(QDialog *CreateInventory)
    {
        if (CreateInventory->objectName().isEmpty())
            CreateInventory->setObjectName(QStringLiteral("CreateInventory"));
        CreateInventory->resize(694, 471);
        CreateInventory->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateInventory->setModal(false);
        gridLayout = new QGridLayout(CreateInventory);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        statusBtn = new QPushButton(CreateInventory);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));

        gridLayout->addWidget(statusBtn, 10, 0, 1, 1);

        newInvCxb = new QCheckBox(CreateInventory);
        newInvCxb->setObjectName(QStringLiteral("newInvCxb"));

        gridLayout->addWidget(newInvCxb, 0, 0, 1, 1);

        locationEdit = new QLineEdit(CreateInventory);
        locationEdit->setObjectName(QStringLiteral("locationEdit"));

        gridLayout->addWidget(locationEdit, 4, 1, 1, 1);

        label = new QLabel(CreateInventory);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(CreateInventory);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateInventory);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateInventory);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 11, 0, 1, 2);

        label_4 = new QLabel(CreateInventory);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        numberEdit = new QLineEdit(CreateInventory);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setReadOnly(true);

        gridLayout->addWidget(numberEdit, 5, 1, 1, 1);

        label_5 = new QLabel(CreateInventory);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        divisionCmb = new QComboBox(CreateInventory);
        divisionCmb->setObjectName(QStringLiteral("divisionCmb"));

        gridLayout->addWidget(divisionCmb, 6, 1, 1, 1);

        label_6 = new QLabel(CreateInventory);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        barcodeEdit = new QLineEdit(CreateInventory);
        barcodeEdit->setObjectName(QStringLiteral("barcodeEdit"));

        gridLayout->addWidget(barcodeEdit, 7, 1, 1, 1);

        label_7 = new QLabel(CreateInventory);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        startDateEdit = new QDateEdit(CreateInventory);
        startDateEdit->setObjectName(QStringLiteral("startDateEdit"));

        gridLayout->addWidget(startDateEdit, 8, 1, 1, 1);

        label_8 = new QLabel(CreateInventory);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 9, 0, 1, 1);

        endDateEdit = new QDateEdit(CreateInventory);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));

        gridLayout->addWidget(endDateEdit, 9, 1, 1, 1);

        costEdit = new QLineEdit(CreateInventory);
        costEdit->setObjectName(QStringLiteral("costEdit"));

        gridLayout->addWidget(costEdit, 3, 1, 1, 1);

        nameEdit = new QLineEdit(CreateInventory);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        label_3 = new QLabel(CreateInventory);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        statusEdit = new QLineEdit(CreateInventory);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setReadOnly(true);

        gridLayout->addWidget(statusEdit, 10, 1, 1, 1);

        sourceGbx = new QGroupBox(CreateInventory);
        sourceGbx->setObjectName(QStringLiteral("sourceGbx"));
        gridLayout_5 = new QGridLayout(sourceGbx);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        accableBtn = new QPushButton(sourceGbx);
        accableBtn->setObjectName(QStringLiteral("accableBtn"));

        gridLayout_5->addWidget(accableBtn, 0, 0, 1, 1);

        surnameLb = new QLabel(sourceGbx);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));

        gridLayout_5->addWidget(surnameLb, 2, 1, 1, 1);

        purveyorBtn = new QPushButton(sourceGbx);
        purveyorBtn->setObjectName(QStringLiteral("purveyorBtn"));

        gridLayout_5->addWidget(purveyorBtn, 1, 0, 1, 1);

        label_9 = new QLabel(sourceGbx);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        accID = new QLineEdit(sourceGbx);
        accID->setObjectName(QStringLiteral("accID"));
        accID->setReadOnly(true);

        gridLayout_5->addWidget(accID, 3, 1, 1, 1);

        purEditID = new QLineEdit(sourceGbx);
        purEditID->setObjectName(QStringLiteral("purEditID"));
        purEditID->setReadOnly(true);

        gridLayout_5->addWidget(purEditID, 1, 1, 1, 1);

        accableIDEdit = new QLineEdit(sourceGbx);
        accableIDEdit->setObjectName(QStringLiteral("accableIDEdit"));
        accableIDEdit->setReadOnly(true);

        gridLayout_5->addWidget(accableIDEdit, 0, 1, 1, 1);

        accountBtn = new QPushButton(sourceGbx);
        accountBtn->setObjectName(QStringLiteral("accountBtn"));

        gridLayout_5->addWidget(accountBtn, 3, 0, 1, 1);

        label_10 = new QLabel(sourceGbx);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 4, 0, 1, 1);

        accountName = new QLabel(sourceGbx);
        accountName->setObjectName(QStringLiteral("accountName"));

        gridLayout_5->addWidget(accountName, 4, 1, 1, 1);


        gridLayout->addWidget(sourceGbx, 1, 0, 1, 2);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateInventory);

        QMetaObject::connectSlotsByName(CreateInventory);
    } // setupUi

    void retranslateUi(QDialog *CreateInventory)
    {
        CreateInventory->setWindowTitle(QApplication::translate("CreateInventory", "Create/Update inventory", 0));
        statusBtn->setText(QApplication::translate("CreateInventory", "Select status", 0));
        newInvCxb->setText(QApplication::translate("CreateInventory", "Posting a new fixed assets?", 0));
        label->setText(QApplication::translate("CreateInventory", "Name:", 0));
        label_2->setText(QApplication::translate("CreateInventory", "Cost:", 0));
        okBtn->setText(QApplication::translate("CreateInventory", "Ok", 0));
        cancelBtn->setText(QApplication::translate("CreateInventory", "Cancel", 0));
        label_4->setText(QApplication::translate("CreateInventory", "Inventory number:", 0));
        label_5->setText(QApplication::translate("CreateInventory", "Division:", 0));
        label_6->setText(QApplication::translate("CreateInventory", "Barcode number:", 0));
        label_7->setText(QApplication::translate("CreateInventory", "Start of operation date:", 0));
        label_8->setText(QApplication::translate("CreateInventory", "End of operation date:", 0));
        label_3->setText(QApplication::translate("CreateInventory", "Location:", 0));
        sourceGbx->setTitle(QApplication::translate("CreateInventory", "Source account:", 0));
        accableBtn->setText(QApplication::translate("CreateInventory", "Select accountable", 0));
        surnameLb->setText(QString());
        purveyorBtn->setText(QApplication::translate("CreateInventory", "Select purveyor", 0));
        label_9->setText(QApplication::translate("CreateInventory", "Surname:", 0));
        accountBtn->setText(QApplication::translate("CreateInventory", "Select account", 0));
        label_10->setText(QApplication::translate("CreateInventory", "Account name:", 0));
        accountName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateInventory: public Ui_CreateInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEINVEDLG_H
