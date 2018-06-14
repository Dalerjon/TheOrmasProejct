/********************************************************************************
** Form generated from reading UI file 'CreateSpecDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESPECDLG_H
#define UI_CREATESPECDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
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

class Ui_CreateSpecification
{
public:
    QGridLayout *gridLayout;
    QLineEdit *sumEdit;
    QLabel *sumLb;
    QLabel *dateLb;
    QGroupBox *ingrGbx;
    QGridLayout *gridLayout_3;
    QPushButton *addProdBtn;
    QLabel *prodCountLb;
    QLabel *prodCountPh;
    QGroupBox *prodGbx;
    QGridLayout *gridLayout_2;
    QPushButton *productBtn;
    QLineEdit *productEdit;
    QLabel *prodNameLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *measurePh;
    QComboBox *currencyCmb;
    QLabel *currencyLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QGroupBox *techGbx;
    QGridLayout *gridLayout_4;
    QPushButton *employeeBtn;
    QLabel *empNameLb;
    QLabel *empNamePh;
    QLabel *empSurnameLb;
    QLabel *empSurnamePh;
    QLabel *empPhoneLb;
    QLabel *empPhonePh;
    QLineEdit *employeeEdit;
    QDateTimeEdit *dateEdit;

    void setupUi(QDialog *CreateSpecification)
    {
        if (CreateSpecification->objectName().isEmpty())
            CreateSpecification->setObjectName(QStringLiteral("CreateSpecification"));
        CreateSpecification->resize(696, 415);
        CreateSpecification->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSpecification->setModal(false);
        gridLayout = new QGridLayout(CreateSpecification);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        sumEdit = new QLineEdit(CreateSpecification);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(200, 16777215));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 4, 2, 1, 1);

        sumLb = new QLabel(CreateSpecification);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(sumLb, 4, 0, 1, 2);

        dateLb = new QLabel(CreateSpecification);
        dateLb->setObjectName(QStringLiteral("dateLb"));
        dateLb->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(dateLb, 0, 0, 1, 2);

        ingrGbx = new QGroupBox(CreateSpecification);
        ingrGbx->setObjectName(QStringLiteral("ingrGbx"));
        gridLayout_3 = new QGridLayout(ingrGbx);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        addProdBtn = new QPushButton(ingrGbx);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));
        addProdBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(addProdBtn, 0, 0, 1, 1);

        prodCountLb = new QLabel(ingrGbx);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout_3->addWidget(prodCountLb, 0, 1, 1, 1);

        prodCountPh = new QLabel(ingrGbx);
        prodCountPh->setObjectName(QStringLiteral("prodCountPh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        prodCountPh->setFont(font);

        gridLayout_3->addWidget(prodCountPh, 0, 2, 1, 1);


        gridLayout->addWidget(ingrGbx, 2, 0, 1, 4);

        prodGbx = new QGroupBox(CreateSpecification);
        prodGbx->setObjectName(QStringLiteral("prodGbx"));
        gridLayout_2 = new QGridLayout(prodGbx);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        productBtn = new QPushButton(prodGbx);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(productBtn, 0, 0, 1, 1);

        productEdit = new QLineEdit(prodGbx);
        productEdit->setObjectName(QStringLiteral("productEdit"));

        gridLayout_2->addWidget(productEdit, 0, 1, 1, 1);

        prodNameLb = new QLabel(prodGbx);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(0, 0));
        prodNameLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(prodNameLb, 1, 0, 1, 1);

        prodNamePh = new QLabel(prodGbx);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout_2->addWidget(prodNamePh, 1, 1, 1, 1);

        volumeLb = new QLabel(prodGbx);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(0, 0));
        volumeLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(volumeLb, 2, 0, 1, 1);

        volumePh = new QLabel(prodGbx);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout_2->addWidget(volumePh, 2, 1, 1, 1);

        measureLb = new QLabel(prodGbx);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout_2->addWidget(measureLb, 3, 0, 1, 1);

        measurePh = new QLabel(prodGbx);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout_2->addWidget(measurePh, 3, 1, 1, 1);

        measurePh->raise();
        productBtn->raise();
        volumeLb->raise();
        measureLb->raise();
        prodNameLb->raise();
        productEdit->raise();
        prodNamePh->raise();
        volumePh->raise();

        gridLayout->addWidget(prodGbx, 1, 0, 1, 4);

        currencyCmb = new QComboBox(CreateSpecification);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 5, 2, 1, 1);

        currencyLb = new QLabel(CreateSpecification);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));
        currencyLb->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(currencyLb, 5, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateSpecification);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateSpecification);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 4);

        techGbx = new QGroupBox(CreateSpecification);
        techGbx->setObjectName(QStringLiteral("techGbx"));
        gridLayout_4 = new QGridLayout(techGbx);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        employeeBtn = new QPushButton(techGbx);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout_4->addWidget(employeeBtn, 0, 0, 1, 2);

        empNameLb = new QLabel(techGbx);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(0, 0));
        empNameLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(empNameLb, 1, 0, 1, 1);

        empNamePh = new QLabel(techGbx);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(0, 0));
        empNamePh->setFont(font);

        gridLayout_4->addWidget(empNamePh, 1, 1, 1, 1);

        empSurnameLb = new QLabel(techGbx);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(0, 0));
        empSurnameLb->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(empSurnameLb, 1, 2, 1, 1);

        empSurnamePh = new QLabel(techGbx);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(0, 0));
        empSurnamePh->setFont(font);

        gridLayout_4->addWidget(empSurnamePh, 1, 3, 1, 1);

        empPhoneLb = new QLabel(techGbx);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout_4->addWidget(empPhoneLb, 1, 4, 1, 1);

        empPhonePh = new QLabel(techGbx);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(0, 0));
        empPhonePh->setFont(font);

        gridLayout_4->addWidget(empPhonePh, 1, 5, 1, 1);

        employeeEdit = new QLineEdit(techGbx);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(employeeEdit->sizePolicy().hasHeightForWidth());
        employeeEdit->setSizePolicy(sizePolicy);
        employeeEdit->setReadOnly(true);

        gridLayout_4->addWidget(employeeEdit, 0, 3, 1, 1);


        gridLayout->addWidget(techGbx, 3, 0, 1, 4);

        dateEdit = new QDateTimeEdit(CreateSpecification);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateSpecification);

        QMetaObject::connectSlotsByName(CreateSpecification);
    } // setupUi

    void retranslateUi(QDialog *CreateSpecification)
    {
        CreateSpecification->setWindowTitle(QApplication::translate("CreateSpecification", "Create/Update specification", 0));
        sumLb->setText(QApplication::translate("CreateSpecification", "Sum:", 0));
        dateLb->setText(QApplication::translate("CreateSpecification", "Specification date:", 0));
        ingrGbx->setTitle(QApplication::translate("CreateSpecification", "Composition", 0));
        addProdBtn->setText(QApplication::translate("CreateSpecification", "Add products", 0));
        prodCountLb->setText(QApplication::translate("CreateSpecification", "Count of products:", 0));
        prodCountPh->setText(QString());
        prodGbx->setTitle(QApplication::translate("CreateSpecification", "Product information", 0));
        productBtn->setText(QApplication::translate("CreateSpecification", "Select product", 0));
        prodNameLb->setText(QApplication::translate("CreateSpecification", "Product name:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateSpecification", "Volume:", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateSpecification", "Measure:", 0));
        measurePh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateSpecification", "Select currency:", 0));
        okBtn->setText(QApplication::translate("CreateSpecification", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSpecification", "Cancel", 0));
        techGbx->setTitle(QApplication::translate("CreateSpecification", "Technologist", 0));
        employeeBtn->setText(QApplication::translate("CreateSpecification", "Select employee", 0));
        empNameLb->setText(QApplication::translate("CreateSpecification", "Name:", 0));
        empNamePh->setText(QString());
        empSurnameLb->setText(QApplication::translate("CreateSpecification", "Surname:", 0));
        empSurnamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateSpecification", "Phone:", 0));
        empPhonePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        employeeEdit->setToolTip(QApplication::translate("CreateSpecification", "<html><head/><body><p>Enter employee ID</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateSpecification: public Ui_CreateSpecification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESPECDLG_H
