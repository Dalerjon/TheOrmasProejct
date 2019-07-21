/********************************************************************************
** Form generated from reading UI file 'CreatePrdBrnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPRDBRNDLG_H
#define UI_CREATEPRDBRNDLG_H

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

class Ui_CreateProductBranch
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLabel *addressLb;
    QLabel *branchNamePh;
    QLineEdit *branchEdit;
    QLabel *bNameLb_2;
    QPushButton *branchBtn;
    QLabel *addressPh;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLineEdit *productEdit;
    QLabel *productNamePh;
    QLabel *priceLb;
    QLabel *bNameLb;
    QPushButton *productBtn;
    QLabel *pricePh;

    void setupUi(QDialog *CreateProductBranch)
    {
        if (CreateProductBranch->objectName().isEmpty())
            CreateProductBranch->setObjectName(QStringLiteral("CreateProductBranch"));
        CreateProductBranch->resize(685, 223);
        CreateProductBranch->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateProductBranch->setModal(false);
        gridLayout = new QGridLayout(CreateProductBranch);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateProductBranch);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateProductBranch);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 2);

        groupBox_4 = new QGroupBox(CreateProductBranch);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        addressLb = new QLabel(groupBox_4);
        addressLb->setObjectName(QStringLiteral("addressLb"));
        addressLb->setMinimumSize(QSize(50, 0));
        addressLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_5->addWidget(addressLb, 1, 4, 1, 1);

        branchNamePh = new QLabel(groupBox_4);
        branchNamePh->setObjectName(QStringLiteral("branchNamePh"));
        branchNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        branchNamePh->setFont(font);

        gridLayout_5->addWidget(branchNamePh, 1, 1, 1, 2);

        branchEdit = new QLineEdit(groupBox_4);
        branchEdit->setObjectName(QStringLiteral("branchEdit"));
        branchEdit->setReadOnly(true);

        gridLayout_5->addWidget(branchEdit, 0, 3, 1, 2);

        bNameLb_2 = new QLabel(groupBox_4);
        bNameLb_2->setObjectName(QStringLiteral("bNameLb_2"));
        bNameLb_2->setMinimumSize(QSize(80, 0));
        bNameLb_2->setMaximumSize(QSize(50, 16777215));

        gridLayout_5->addWidget(bNameLb_2, 1, 0, 1, 1);

        branchBtn = new QPushButton(groupBox_4);
        branchBtn->setObjectName(QStringLiteral("branchBtn"));
        branchBtn->setMinimumSize(QSize(150, 0));

        gridLayout_5->addWidget(branchBtn, 0, 0, 1, 2);

        addressPh = new QLabel(groupBox_4);
        addressPh->setObjectName(QStringLiteral("addressPh"));
        addressPh->setMinimumSize(QSize(100, 0));
        addressPh->setFont(font);

        gridLayout_5->addWidget(addressPh, 1, 5, 1, 1);

        branchEdit->raise();
        branchNamePh->raise();
        addressLb->raise();
        bNameLb_2->raise();
        addressPh->raise();
        branchBtn->raise();

        gridLayout->addWidget(groupBox_4, 2, 0, 1, 2);

        groupBox_3 = new QGroupBox(CreateProductBranch);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        productEdit = new QLineEdit(groupBox_3);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout_4->addWidget(productEdit, 0, 3, 1, 2);

        productNamePh = new QLabel(groupBox_3);
        productNamePh->setObjectName(QStringLiteral("productNamePh"));
        productNamePh->setMinimumSize(QSize(100, 0));
        productNamePh->setFont(font);

        gridLayout_4->addWidget(productNamePh, 1, 1, 1, 2);

        priceLb = new QLabel(groupBox_3);
        priceLb->setObjectName(QStringLiteral("priceLb"));
        priceLb->setMinimumSize(QSize(50, 0));
        priceLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(priceLb, 1, 4, 1, 1);

        bNameLb = new QLabel(groupBox_3);
        bNameLb->setObjectName(QStringLiteral("bNameLb"));
        bNameLb->setMinimumSize(QSize(80, 0));
        bNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(bNameLb, 1, 0, 1, 1);

        productBtn = new QPushButton(groupBox_3);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(150, 0));

        gridLayout_4->addWidget(productBtn, 0, 0, 1, 2);

        pricePh = new QLabel(groupBox_3);
        pricePh->setObjectName(QStringLiteral("pricePh"));
        pricePh->setMinimumSize(QSize(100, 0));
        pricePh->setFont(font);

        gridLayout_4->addWidget(pricePh, 1, 5, 1, 1);

        productBtn->raise();
        bNameLb->raise();
        productNamePh->raise();
        productEdit->raise();
        priceLb->raise();
        pricePh->raise();

        gridLayout->addWidget(groupBox_3, 1, 0, 1, 2);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateProductBranch);

        QMetaObject::connectSlotsByName(CreateProductBranch);
    } // setupUi

    void retranslateUi(QDialog *CreateProductBranch)
    {
        CreateProductBranch->setWindowTitle(QApplication::translate("CreateProductBranch", "Create/Update product-branch relation", 0));
        okBtn->setText(QApplication::translate("CreateProductBranch", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateProductBranch", "Cancel", 0));
        groupBox_4->setTitle(QApplication::translate("CreateProductBranch", "Select branch:", 0));
        addressLb->setText(QApplication::translate("CreateProductBranch", "Address:", 0));
        branchNamePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        branchEdit->setToolTip(QApplication::translate("CreateProductBranch", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        bNameLb_2->setText(QApplication::translate("CreateProductBranch", "Branch name:", 0));
        branchBtn->setText(QApplication::translate("CreateProductBranch", "Select branch", 0));
        addressPh->setText(QString());
        groupBox_3->setTitle(QApplication::translate("CreateProductBranch", "Select product:", 0));
#ifndef QT_NO_TOOLTIP
        productEdit->setToolTip(QApplication::translate("CreateProductBranch", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        productNamePh->setText(QString());
        priceLb->setText(QApplication::translate("CreateProductBranch", "Price:", 0));
        bNameLb->setText(QApplication::translate("CreateProductBranch", "Product name:", 0));
        productBtn->setText(QApplication::translate("CreateProductBranch", "Select product", 0));
        pricePh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateProductBranch: public Ui_CreateProductBranch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPRDBRNDLG_H
