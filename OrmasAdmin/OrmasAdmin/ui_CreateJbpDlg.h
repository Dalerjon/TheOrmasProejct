/********************************************************************************
** Form generated from reading UI file 'CreateJbpDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEJBPDLG_H
#define UI_CREATEJBPDLG_H

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

class Ui_CreateJobprice
{
public:
    QGridLayout *gridLayout;
    QLineEdit *valueEdit;
    QLabel *positionPh;
    QLabel *valueLb;
    QLabel *currencyLb;
    QPushButton *productBtn;
    QLineEdit *productEdit;
    QComboBox *currencyCmb;
    QLineEdit *volumeEdit;
    QLabel *measureLb_2;
    QLabel *measurePh;
    QLabel *measureLb;
    QLabel *volumePh;
    QLabel *volumeLb_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *prodNameLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QComboBox *measureCmb;
    QLineEdit *positionEdit;
    QLabel *positionLb;
    QPushButton *positionBtn;

    void setupUi(QDialog *CreateJobprice)
    {
        if (CreateJobprice->objectName().isEmpty())
            CreateJobprice->setObjectName(QStringLiteral("CreateJobprice"));
        CreateJobprice->resize(641, 238);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateJobprice->sizePolicy().hasHeightForWidth());
        CreateJobprice->setSizePolicy(sizePolicy);
        CreateJobprice->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateJobprice->setModal(false);
        gridLayout = new QGridLayout(CreateJobprice);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        valueEdit = new QLineEdit(CreateJobprice);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout->addWidget(valueEdit, 2, 2, 1, 2);

        positionPh = new QLabel(CreateJobprice);
        positionPh->setObjectName(QStringLiteral("positionPh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        positionPh->setFont(font);

        gridLayout->addWidget(positionPh, 8, 5, 1, 1);

        valueLb = new QLabel(CreateJobprice);
        valueLb->setObjectName(QStringLiteral("valueLb"));

        gridLayout->addWidget(valueLb, 2, 0, 1, 2);

        currencyLb = new QLabel(CreateJobprice);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout->addWidget(currencyLb, 3, 0, 1, 2);

        productBtn = new QPushButton(CreateJobprice);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        productEdit = new QLineEdit(CreateJobprice);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 2, 1, 2);

        currencyCmb = new QComboBox(CreateJobprice);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));

        gridLayout->addWidget(currencyCmb, 3, 2, 1, 2);

        volumeEdit = new QLineEdit(CreateJobprice);
        volumeEdit->setObjectName(QStringLiteral("volumeEdit"));

        gridLayout->addWidget(volumeEdit, 4, 2, 1, 2);

        measureLb_2 = new QLabel(CreateJobprice);
        measureLb_2->setObjectName(QStringLiteral("measureLb_2"));

        gridLayout->addWidget(measureLb_2, 5, 0, 1, 2);

        measurePh = new QLabel(CreateJobprice);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        measureLb = new QLabel(CreateJobprice);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        volumePh = new QLabel(CreateJobprice);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        volumeLb_2 = new QLabel(CreateJobprice);
        volumeLb_2->setObjectName(QStringLiteral("volumeLb_2"));
        volumeLb_2->setMinimumSize(QSize(70, 0));
        volumeLb_2->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb_2, 1, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateJobprice);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout_2->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateJobprice);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout_2->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout_2, 9, 0, 1, 6);

        prodNameLb = new QLabel(CreateJobprice);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        prodNamePh = new QLabel(CreateJobprice);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        volumeLb = new QLabel(CreateJobprice);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));

        gridLayout->addWidget(volumeLb, 4, 0, 1, 2);

        measureCmb = new QComboBox(CreateJobprice);
        measureCmb->setObjectName(QStringLiteral("measureCmb"));
        measureCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(measureCmb, 5, 2, 1, 1);

        positionEdit = new QLineEdit(CreateJobprice);
        positionEdit->setObjectName(QStringLiteral("positionEdit"));
        positionEdit->setReadOnly(true);

        gridLayout->addWidget(positionEdit, 8, 2, 1, 1);

        positionLb = new QLabel(CreateJobprice);
        positionLb->setObjectName(QStringLiteral("positionLb"));

        gridLayout->addWidget(positionLb, 8, 3, 1, 1);

        positionBtn = new QPushButton(CreateJobprice);
        positionBtn->setObjectName(QStringLiteral("positionBtn"));

        gridLayout->addWidget(positionBtn, 8, 0, 1, 2);

        QWidget::setTabOrder(productBtn, positionBtn);
        QWidget::setTabOrder(positionBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateJobprice);

        QMetaObject::connectSlotsByName(CreateJobprice);
    } // setupUi

    void retranslateUi(QDialog *CreateJobprice)
    {
        CreateJobprice->setWindowTitle(QApplication::translate("CreateJobprice", "Create/Update jobprice", 0));
#ifndef QT_NO_TOOLTIP
        valueEdit->setToolTip(QApplication::translate("CreateJobprice", "<html><head/><body><p>For example: 1 (depending on measure, in that case = 1 liter)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        positionPh->setText(QString());
        valueLb->setText(QApplication::translate("CreateJobprice", "Value:", 0));
        currencyLb->setText(QApplication::translate("CreateJobprice", "Select currency:", 0));
        productBtn->setText(QApplication::translate("CreateJobprice", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        volumeEdit->setToolTip(QApplication::translate("CreateJobprice", "<html><head/><body><p>For example: 3.5 (depending on currency, in that case 3.5 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        measureLb_2->setText(QApplication::translate("CreateJobprice", "Select measure:", 0));
        measurePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateJobprice", "Measure:", 0));
        volumePh->setText(QString());
        volumeLb_2->setText(QApplication::translate("CreateJobprice", "Volume:", 0));
        okBtn->setText(QApplication::translate("CreateJobprice", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateJobprice", "Cancel", 0));
        prodNameLb->setText(QApplication::translate("CreateJobprice", "Product name:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateJobprice", "Volume:", 0));
        positionLb->setText(QApplication::translate("CreateJobprice", "Position name:", 0));
        positionBtn->setText(QApplication::translate("CreateJobprice", "Select position", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateJobprice: public Ui_CreateJobprice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEJBPDLG_H
