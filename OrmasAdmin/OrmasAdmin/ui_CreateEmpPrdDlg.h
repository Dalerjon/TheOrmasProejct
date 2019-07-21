/********************************************************************************
** Form generated from reading UI file 'CreateEmpPrdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEEMPPRDDLG_H
#define UI_CREATEEMPPRDDLG_H

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

class Ui_CreateEmployeeProduct
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLineEdit *productEdit;
    QLabel *productNamePh;
    QLabel *priceLb;
    QLabel *bNameLb;
    QPushButton *productBtn;
    QLabel *pricePh;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *userBtn;
    QLabel *phoneLb;
    QLabel *phonePh;
    QLabel *surnamePh;
    QLabel *namePh;
    QLabel *nameLb;
    QLabel *surnameLb;
    QLineEdit *userEdit;

    void setupUi(QDialog *CreateEmployeeProduct)
    {
        if (CreateEmployeeProduct->objectName().isEmpty())
            CreateEmployeeProduct->setObjectName(QStringLiteral("CreateEmployeeProduct"));
        CreateEmployeeProduct->resize(685, 223);
        CreateEmployeeProduct->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateEmployeeProduct->setModal(false);
        gridLayout = new QGridLayout(CreateEmployeeProduct);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateEmployeeProduct);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateEmployeeProduct);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 10, 1, 1, 2);

        groupBox_3 = new QGroupBox(CreateEmployeeProduct);
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
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
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

        gridLayout->addWidget(groupBox_3, 1, 1, 1, 2);

        groupBox_2 = new QGroupBox(CreateEmployeeProduct);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        userBtn = new QPushButton(groupBox_2);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(userBtn, 0, 0, 1, 2);

        phoneLb = new QLabel(groupBox_2);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(50, 0));
        phoneLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(phoneLb, 1, 4, 1, 1);

        phonePh = new QLabel(groupBox_2);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout_3->addWidget(phonePh, 1, 5, 1, 1);

        surnamePh = new QLabel(groupBox_2);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout_3->addWidget(surnamePh, 1, 3, 1, 1);

        namePh = new QLabel(groupBox_2);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout_3->addWidget(namePh, 1, 1, 1, 1);

        nameLb = new QLabel(groupBox_2);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(nameLb, 1, 0, 1, 1);

        surnameLb = new QLabel(groupBox_2);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(surnameLb, 1, 2, 1, 1);

        userEdit = new QLineEdit(groupBox_2);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout_3->addWidget(userEdit, 0, 3, 1, 2);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 2);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateEmployeeProduct);

        QMetaObject::connectSlotsByName(CreateEmployeeProduct);
    } // setupUi

    void retranslateUi(QDialog *CreateEmployeeProduct)
    {
        CreateEmployeeProduct->setWindowTitle(QApplication::translate("CreateEmployeeProduct", "Create/Update employee-product relation", 0));
        okBtn->setText(QApplication::translate("CreateEmployeeProduct", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateEmployeeProduct", "Cancel", 0));
        groupBox_3->setTitle(QApplication::translate("CreateEmployeeProduct", "Select product:", 0));
#ifndef QT_NO_TOOLTIP
        productEdit->setToolTip(QApplication::translate("CreateEmployeeProduct", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        productNamePh->setText(QString());
        priceLb->setText(QApplication::translate("CreateEmployeeProduct", "Price:", 0));
        bNameLb->setText(QApplication::translate("CreateEmployeeProduct", "Product name:", 0));
        productBtn->setText(QApplication::translate("CreateEmployeeProduct", "Select product", 0));
        pricePh->setText(QString());
        groupBox_2->setTitle(QApplication::translate("CreateEmployeeProduct", "Select user:", 0));
        userBtn->setText(QApplication::translate("CreateEmployeeProduct", "Select user", 0));
        phoneLb->setText(QApplication::translate("CreateEmployeeProduct", "Phone:", 0));
        phonePh->setText(QString());
        surnamePh->setText(QString());
        namePh->setText(QString());
        nameLb->setText(QApplication::translate("CreateEmployeeProduct", "Name:", 0));
        surnameLb->setText(QApplication::translate("CreateEmployeeProduct", "Surname:", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateEmployeeProduct", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateEmployeeProduct: public Ui_CreateEmployeeProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEEMPPRDDLG_H
