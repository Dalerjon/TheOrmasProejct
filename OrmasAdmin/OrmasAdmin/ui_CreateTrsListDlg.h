/********************************************************************************
** Form generated from reading UI file 'CreateTrsListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETRSLISTDLG_H
#define UI_CREATETRSLISTDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTrsList
{
public:
    QGridLayout *gridLayout;
    QLabel *prodNameLb;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QLabel *measurePh;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLineEdit *sumEdit;
    QPushButton *transportBtn;
    QLineEdit *transportEdit;
    QComboBox *currencyCmb;
    QLabel *sumLb;
    QLabel *currencyLb;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLineEdit *productEdit;
    QLineEdit *countEdit;
    QLabel *countLb;
    QPushButton *productBtn;

    void setupUi(QDialog *CreateTrsList)
    {
        if (CreateTrsList->objectName().isEmpty())
            CreateTrsList->setObjectName(QStringLiteral("CreateTrsList"));
        CreateTrsList->resize(634, 252);
        CreateTrsList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateTrsList->setModal(false);
        gridLayout = new QGridLayout(CreateTrsList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        prodNameLb = new QLabel(CreateTrsList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        volumePh = new QLabel(CreateTrsList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        measureLb = new QLabel(CreateTrsList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        prodNamePh = new QLabel(CreateTrsList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        volumeLb = new QLabel(CreateTrsList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        measurePh = new QLabel(CreateTrsList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        editSectionWgt = new QWidget(CreateTrsList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        transportBtn = new QPushButton(editSectionWgt);
        transportBtn->setObjectName(QStringLiteral("transportBtn"));
        transportBtn->setMinimumSize(QSize(150, 0));
        transportBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(transportBtn, 0, 0, 1, 1);

        transportEdit = new QLineEdit(editSectionWgt);
        transportEdit->setObjectName(QStringLiteral("transportEdit"));
        transportEdit->setMaximumSize(QSize(150, 16777215));
        transportEdit->setReadOnly(true);

        gridLayout_3->addWidget(transportEdit, 0, 1, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 3, 1, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        statusWidget = new QWidget(editSectionWgt);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBtn = new QPushButton(statusWidget);
        statusBtn->setObjectName(QStringLiteral("statusBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusBtn->sizePolicy().hasHeightForWidth());
        statusBtn->setSizePolicy(sizePolicy);
        statusBtn->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(statusBtn);

        statusEdit = new QLineEdit(statusWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setMaximumSize(QSize(150, 16777215));
        statusEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(statusEdit);

        statusLb = new QLabel(statusWidget);
        statusLb->setObjectName(QStringLiteral("statusLb"));

        horizontalLayout_3->addWidget(statusLb);

        statusPh = new QLabel(statusWidget);
        statusPh->setObjectName(QStringLiteral("statusPh"));
        statusPh->setMinimumSize(QSize(120, 0));
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout_3->addWidget(statusWidget, 1, 0, 1, 3);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateTrsList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateTrsList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        productEdit = new QLineEdit(CreateTrsList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countEdit = new QLineEdit(CreateTrsList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        countLb = new QLabel(CreateTrsList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        productBtn = new QPushButton(CreateTrsList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        QWidget::setTabOrder(productBtn, transportBtn);
        QWidget::setTabOrder(transportBtn, transportEdit);
        QWidget::setTabOrder(transportEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateTrsList);

        QMetaObject::connectSlotsByName(CreateTrsList);
    } // setupUi

    void retranslateUi(QDialog *CreateTrsList)
    {
        CreateTrsList->setWindowTitle(QApplication::translate("CreateTrsList", "Create/Update product in transport list", 0));
        prodNameLb->setText(QApplication::translate("CreateTrsList", "Product name:", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateTrsList", "Measure:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateTrsList", "Volume:", 0));
        measurePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateTrsList", "<html><head/><body><p>For example: 300 (pedends on currency, in that case 300 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        transportBtn->setText(QApplication::translate("CreateTrsList", "Select transport", 0));
        transportEdit->setText(QString());
        sumLb->setText(QApplication::translate("CreateTrsList", "Sum:", 0));
        currencyLb->setText(QApplication::translate("CreateTrsList", "Select currency:", 0));
        statusBtn->setText(QApplication::translate("CreateTrsList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateTrsList", "Status name:", 0));
        statusPh->setText(QString());
        addBtn->setText(QApplication::translate("CreateTrsList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateTrsList", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateTrsList", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        countLb->setText(QApplication::translate("CreateTrsList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateTrsList", "Select product", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateTrsList: public Ui_CreateTrsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETRSLISTDLG_H
