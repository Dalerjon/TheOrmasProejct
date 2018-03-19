/********************************************************************************
** Form generated from reading UI file 'CreatePcrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPCRDLG_H
#define UI_CREATEPCRDLG_H

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

class Ui_CreatePercentRate
{
public:
    QGridLayout *gridLayout;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *valueLb;
    QLineEdit *valueEdit;
    QLabel *positionPh;
    QLineEdit *conditionEdit;
    QLabel *nameLb;
    QLineEdit *positionEdit;
    QLabel *conditionLb;
    QPushButton *positionBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CreatePercentRate)
    {
        if (CreatePercentRate->objectName().isEmpty())
            CreatePercentRate->setObjectName(QStringLiteral("CreatePercentRate"));
        CreatePercentRate->resize(665, 160);
        CreatePercentRate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePercentRate->setModal(false);
        gridLayout = new QGridLayout(CreatePercentRate);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        editSectionWgt = new QWidget(CreatePercentRate);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        valueLb = new QLabel(editSectionWgt);
        valueLb->setObjectName(QStringLiteral("valueLb"));
        valueLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(valueLb, 0, 0, 1, 1);

        valueEdit = new QLineEdit(editSectionWgt);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        gridLayout_3->addWidget(valueEdit, 0, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 2);

        positionPh = new QLabel(CreatePercentRate);
        positionPh->setObjectName(QStringLiteral("positionPh"));
        positionPh->setMinimumSize(QSize(120, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        positionPh->setFont(font);

        gridLayout->addWidget(positionPh, 1, 1, 1, 1);

        conditionEdit = new QLineEdit(CreatePercentRate);
        conditionEdit->setObjectName(QStringLiteral("conditionEdit"));

        gridLayout->addWidget(conditionEdit, 2, 1, 1, 1);

        nameLb = new QLabel(CreatePercentRate);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(150, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        positionEdit = new QLineEdit(CreatePercentRate);
        positionEdit->setObjectName(QStringLiteral("positionEdit"));
        positionEdit->setReadOnly(true);

        gridLayout->addWidget(positionEdit, 0, 1, 1, 1);

        conditionLb = new QLabel(CreatePercentRate);
        conditionLb->setObjectName(QStringLiteral("conditionLb"));
        conditionLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(conditionLb, 2, 0, 1, 1);

        positionBtn = new QPushButton(CreatePercentRate);
        positionBtn->setObjectName(QStringLiteral("positionBtn"));

        gridLayout->addWidget(positionBtn, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePercentRate);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePercentRate);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        QWidget::setTabOrder(positionBtn, positionEdit);
        QWidget::setTabOrder(positionEdit, conditionEdit);
        QWidget::setTabOrder(conditionEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePercentRate);

        QMetaObject::connectSlotsByName(CreatePercentRate);
    } // setupUi

    void retranslateUi(QDialog *CreatePercentRate)
    {
        CreatePercentRate->setWindowTitle(QApplication::translate("CreatePercentRate", "Create/Update percent rate", 0));
        valueLb->setText(QApplication::translate("CreatePercentRate", "Value:", 0));
        positionPh->setText(QString());
#ifndef QT_NO_TOOLTIP
        conditionEdit->setToolTip(QApplication::translate("CreatePercentRate", "<html><head/><body><p>For example: 10.5</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreatePercentRate", "Position name:", 0));
        conditionLb->setText(QApplication::translate("CreatePercentRate", "Condition:", 0));
        positionBtn->setText(QApplication::translate("CreatePercentRate", "Select position", 0));
        okBtn->setText(QApplication::translate("CreatePercentRate", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePercentRate", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePercentRate: public Ui_CreatePercentRate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPCRDLG_H
