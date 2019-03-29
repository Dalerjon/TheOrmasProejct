/********************************************************************************
** Form generated from reading UI file 'CreateSpecListDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESPECLISTDLG_H
#define UI_CREATESPECLISTDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_CreateSpecList
{
public:
    QGridLayout *gridLayout;
    QLabel *prodNameLb;
    QLabel *measurePh;
    QLabel *measureLb;
    QLabel *volumeLb;
    QLabel *volumePh;
    QLabel *prodNamePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLineEdit *specEdit;
    QPushButton *specBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *countLb;
    QPushButton *productBtn;
    QLineEdit *productEdit;
    QLineEdit *countEdit;

    void setupUi(QDialog *CreateSpecList)
    {
        if (CreateSpecList->objectName().isEmpty())
            CreateSpecList->setObjectName(QStringLiteral("CreateSpecList"));
        CreateSpecList->resize(585, 163);
        CreateSpecList->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateSpecList->setModal(false);
        gridLayout = new QGridLayout(CreateSpecList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        prodNameLb = new QLabel(CreateSpecList);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        measurePh = new QLabel(CreateSpecList);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        measureLb = new QLabel(CreateSpecList);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        volumeLb = new QLabel(CreateSpecList);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        volumePh = new QLabel(CreateSpecList);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        prodNamePh = new QLabel(CreateSpecList);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(CreateSpecList);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        cancelBtn = new QPushButton(CreateSpecList);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        editSectionWgt = new QWidget(CreateSpecList);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        specEdit = new QLineEdit(editSectionWgt);
        specEdit->setObjectName(QStringLiteral("specEdit"));
        specEdit->setReadOnly(true);

        gridLayout_3->addWidget(specEdit, 0, 1, 1, 1);

        specBtn = new QPushButton(editSectionWgt);
        specBtn->setObjectName(QStringLiteral("specBtn"));
        specBtn->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(specBtn, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 6);

        countLb = new QLabel(CreateSpecList);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        productBtn = new QPushButton(CreateSpecList);
        productBtn->setObjectName(QStringLiteral("productBtn"));
        productBtn->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        productEdit = new QLineEdit(CreateSpecList);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 2, 1, 1);

        countEdit = new QLineEdit(CreateSpecList);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 2, 1, 1);

        QWidget::setTabOrder(productBtn, countEdit);
        QWidget::setTabOrder(countEdit, specBtn);
        QWidget::setTabOrder(specBtn, addBtn);
        QWidget::setTabOrder(addBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, productEdit);
        QWidget::setTabOrder(productEdit, specEdit);

        retranslateUi(CreateSpecList);

        QMetaObject::connectSlotsByName(CreateSpecList);
    } // setupUi

    void retranslateUi(QDialog *CreateSpecList)
    {
        CreateSpecList->setWindowTitle(QApplication::translate("CreateSpecList", "Create/Update product in specification list", 0));
        prodNameLb->setText(QApplication::translate("CreateSpecList", "Product name:", 0));
        measurePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateSpecList", "Measure:", 0));
        volumeLb->setText(QApplication::translate("CreateSpecList", "Volume:", 0));
        volumePh->setText(QString());
        prodNamePh->setText(QString());
        addBtn->setText(QApplication::translate("CreateSpecList", "Add", 0));
        cancelBtn->setText(QApplication::translate("CreateSpecList", "Cancel", 0));
        specEdit->setText(QString());
        specBtn->setText(QApplication::translate("CreateSpecList", "Select specification", 0));
        countLb->setText(QApplication::translate("CreateSpecList", "Count:", 0));
        productBtn->setText(QApplication::translate("CreateSpecList", "Select product", 0));
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateSpecList", "<html><head/><body><p>For example: 10.5</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateSpecList: public Ui_CreateSpecList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESPECLISTDLG_H
