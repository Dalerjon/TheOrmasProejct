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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
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
    QLabel *empNameLb;
    QLabel *empNamePh;
    QLabel *empPhoneLb;
    QLabel *empSurnameLb;
    QLabel *empSurnamePh;
    QLabel *empPhonePh;
    QLabel *prodNameLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *measurePh;
    QPushButton *addProdBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *prodCountLb;
    QLabel *prodCountPh;
    QLabel *currencyLb;
    QLabel *sumLb;
    QPushButton *employeeBtn;
    QPushButton *productBtn;
    QLabel *dateLb;
    QComboBox *currencyCmb;
    QLineEdit *sumEdit;
    QLineEdit *employeeEdit;
    QLineEdit *productEdit;
    QDateEdit *dateEdit;

    void setupUi(QDialog *CreateSpecification)
    {
        if (CreateSpecification->objectName().isEmpty())
            CreateSpecification->setObjectName(QStringLiteral("CreateSpecification"));
        CreateSpecification->resize(584, 264);
        CreateSpecification->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSpecification->setModal(false);
        gridLayout = new QGridLayout(CreateSpecification);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        empNameLb = new QLabel(CreateSpecification);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 5, 0, 1, 1);

        empNamePh = new QLabel(CreateSpecification);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 5, 1, 1, 1);

        empPhoneLb = new QLabel(CreateSpecification);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 5, 4, 1, 1);

        empSurnameLb = new QLabel(CreateSpecification);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 5, 2, 1, 1);

        empSurnamePh = new QLabel(CreateSpecification);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 5, 3, 1, 1);

        empPhonePh = new QLabel(CreateSpecification);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 5, 5, 1, 1);

        prodNameLb = new QLabel(CreateSpecification);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 2, 0, 1, 1);

        prodNamePh = new QLabel(CreateSpecification);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 2, 1, 1, 1);

        volumeLb = new QLabel(CreateSpecification);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 2, 2, 1, 1);

        volumePh = new QLabel(CreateSpecification);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 2, 3, 1, 1);

        measureLb = new QLabel(CreateSpecification);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 2, 4, 1, 1);

        measurePh = new QLabel(CreateSpecification);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 2, 5, 1, 1);

        addProdBtn = new QPushButton(CreateSpecification);
        addProdBtn->setObjectName(QStringLiteral("addProdBtn"));
        addProdBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(addProdBtn, 3, 0, 1, 2);

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


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 6);

        prodCountLb = new QLabel(CreateSpecification);
        prodCountLb->setObjectName(QStringLiteral("prodCountLb"));

        gridLayout->addWidget(prodCountLb, 3, 2, 1, 1);

        prodCountPh = new QLabel(CreateSpecification);
        prodCountPh->setObjectName(QStringLiteral("prodCountPh"));
        prodCountPh->setFont(font);

        gridLayout->addWidget(prodCountPh, 3, 3, 1, 1);

        currencyLb = new QLabel(CreateSpecification);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 7, 0, 1, 2);

        sumLb = new QLabel(CreateSpecification);
        sumLb->setObjectName(QStringLiteral("sumLb"));

        gridLayout->addWidget(sumLb, 6, 0, 1, 2);

        employeeBtn = new QPushButton(CreateSpecification);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 4, 0, 1, 2);

        productBtn = new QPushButton(CreateSpecification);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(productBtn, 1, 0, 1, 2);

        dateLb = new QLabel(CreateSpecification);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 2);

        currencyCmb = new QComboBox(CreateSpecification);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 7, 2, 1, 1);

        sumEdit = new QLineEdit(CreateSpecification);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setReadOnly(true);

        gridLayout->addWidget(sumEdit, 6, 2, 1, 1);

        employeeEdit = new QLineEdit(CreateSpecification);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 4, 2, 1, 1);

        productEdit = new QLineEdit(CreateSpecification);
        productEdit->setObjectName(QStringLiteral("productEdit"));

        gridLayout->addWidget(productEdit, 1, 2, 1, 1);

        dateEdit = new QDateEdit(CreateSpecification);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 2, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateSpecification);

        QMetaObject::connectSlotsByName(CreateSpecification);
    } // setupUi

    void retranslateUi(QDialog *CreateSpecification)
    {
        CreateSpecification->setWindowTitle(QApplication::translate("CreateSpecification", "Create/Update specification", 0));
        empNameLb->setText(QApplication::translate("CreateSpecification", "Name:", 0));
        empNamePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateSpecification", "Phone:", 0));
        empSurnameLb->setText(QApplication::translate("CreateSpecification", "Surname:", 0));
        empSurnamePh->setText(QString());
        empPhonePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateSpecification", "Product name:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateSpecification", "Volume:", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateSpecification", "Measure:", 0));
        measurePh->setText(QString());
        addProdBtn->setText(QApplication::translate("CreateSpecification", "Add products", 0));
        okBtn->setText(QApplication::translate("CreateSpecification", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateSpecification", "Cancel", 0));
        prodCountLb->setText(QApplication::translate("CreateSpecification", "Count of products:", 0));
        prodCountPh->setText(QString());
        currencyLb->setText(QApplication::translate("CreateSpecification", "Select currency:", 0));
        sumLb->setText(QApplication::translate("CreateSpecification", "Sum:", 0));
        employeeBtn->setText(QApplication::translate("CreateSpecification", "Select employee", 0));
        productBtn->setText(QApplication::translate("CreateSpecification", "Select product", 0));
        dateLb->setText(QApplication::translate("CreateSpecification", "Specification date:", 0));
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
