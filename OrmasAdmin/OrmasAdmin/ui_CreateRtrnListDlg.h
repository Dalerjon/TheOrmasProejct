/********************************************************************************
** Form generated from reading UI file 'CreateRtrnListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERTRNLISTDLG_H
#define UI_CREATERTRNLISTDLG_H

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

class Ui_CreateRtrnList
{
public:
    QGridLayout *gridLayout;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLineEdit *sumEdit;
    QLabel *sumLb;
    QLineEdit *returnEdit;
    QPushButton *returnBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *currencyLb;
    QComboBox *currencyCmb;
    QSpacerItem *horizontalSpacer_4;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *statusBtn;
    QLineEdit *statusEdit;
    QLabel *statusLb;
    QLabel *statusPh;
    QLabel *prodNameLb;
    QLabel *volumeLb;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *prodNamePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QLabel *measurePh;
    QPushButton *productBtn;
    QLabel *countLb;
    QLineEdit *productEdit;
    QLineEdit *countEdit;

    void setupUi(QDialog *CreateRtrnList)
    {
        if (CreateRtrnList->objectName().isEmpty())
            CreateRtrnList->setObjectName(QStringLiteral("CreateRtrnList"));
        CreateRtrnList->resize(635, 244);
        CreateRtrnList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRtrnList->setModal(false);
        gridLayout = new QGridLayout(CreateRtrnList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        editSectionWgt = new QWidget(CreateRtrnList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        sumEdit = new QLineEdit(editSectionWgt);
        sumEdit->setObjectName(QStringLiteral("sumEdit"));
        sumEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(sumEdit, 2, 1, 1, 1);

        sumLb = new QLabel(editSectionWgt);
        sumLb->setObjectName(QStringLiteral("sumLb"));
        sumLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(sumLb, 2, 0, 1, 1);

        returnEdit = new QLineEdit(editSectionWgt);
        returnEdit->setObjectName(QStringLiteral("returnEdit"));
        returnEdit->setMaximumSize(QSize(150, 16777215));
        returnEdit->setReadOnly(true);

        gridLayout_3->addWidget(returnEdit, 0, 1, 1, 1);

        returnBtn = new QPushButton(editSectionWgt);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(returnBtn, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        currencyLb = new QLabel(editSectionWgt);
        currencyLb->setObjectName(QStringLiteral("currencyLb"));

        gridLayout_3->addWidget(currencyLb, 3, 0, 1, 1);

        currencyCmb = new QComboBox(editSectionWgt);
        currencyCmb->setObjectName(QStringLiteral("currencyCmb"));
        currencyCmb->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(currencyCmb, 3, 1, 1, 1);

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
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        statusPh->setFont(font);

        horizontalLayout_3->addWidget(statusPh);


        gridLayout_3->addWidget(statusWidget, 1, 0, 1, 3);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        prodNameLb = new QLabel(CreateRtrnList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        volumeLb = new QLabel(CreateRtrnList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        volumePh = new QLabel(CreateRtrnList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        measureLb = new QLabel(CreateRtrnList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        prodNamePh = new QLabel(CreateRtrnList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateRtrnList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateRtrnList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        measurePh = new QLabel(CreateRtrnList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        productBtn = new QPushButton(CreateRtrnList);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        countLb = new QLabel(CreateRtrnList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        productEdit = new QLineEdit(CreateRtrnList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        countEdit = new QLineEdit(CreateRtrnList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        QWidget::setTabOrder(productBtn, returnBtn);
        QWidget::setTabOrder(returnBtn, returnEdit);
        QWidget::setTabOrder(returnEdit, sumEdit);
        QWidget::setTabOrder(sumEdit, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);

        retranslateUi(CreateRtrnList);

        QMetaObject::connectSlotsByName(CreateRtrnList);
    } // setupUi

    void retranslateUi(QDialog *CreateRtrnList)
    {
        CreateRtrnList->setWindowTitle(QApplication::translate("CreateRtrnList", "Create/Update product in return list", 0));
#ifndef QT_NO_TOOLTIP
        sumEdit->setToolTip(QApplication::translate("CreateRtrnList", "<html><head/><body><p>For example: 1000 (depends on currency, 1000 USD)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sumLb->setText(QApplication::translate("CreateRtrnList", "Sum:", 0));
        returnEdit->setText(QString());
        returnBtn->setText(QApplication::translate("CreateRtrnList", "Select return", 0));
        currencyLb->setText(QApplication::translate("CreateRtrnList", "Select currency:", 0));
        statusBtn->setText(QApplication::translate("CreateRtrnList", "Change status", 0));
        statusLb->setText(QApplication::translate("CreateRtrnList", "Status name:", 0));
        statusPh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateRtrnList", "Product name:", 0));
        volumeLb->setText(QApplication::translate("CreateRtrnList", "Volume:", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateRtrnList", "Measure:", 0));
        prodNamePh->setText(QString());
        addBtn->setText(QApplication::translate("CreateRtrnList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateRtrnList", "Cancel", 0));
        measurePh->setText(QString());
        productBtn->setText(QApplication::translate("CreateRtrnList", "Select product", 0));
        countLb->setText(QApplication::translate("CreateRtrnList", "Count:", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateRtrnList", "<html><head/><body><p>For example: 10</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateRtrnList: public Ui_CreateRtrnList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERTRNLISTDLG_H
