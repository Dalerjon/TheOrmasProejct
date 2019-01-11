/********************************************************************************
** Form generated from reading UI file 'GenerateSpecRepDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATESPECREPDLG_H
#define UI_GENERATESPECREPDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GenerateSpecificationReport
{
public:
    QGridLayout *gridLayout;
    QDateEdit *tillDateEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *label_2;
    QDateEdit *fromDateEdit;
    QLabel *fromLb;

    void setupUi(QDialog *GenerateSpecificationReport)
    {
        if (GenerateSpecificationReport->objectName().isEmpty())
            GenerateSpecificationReport->setObjectName(QStringLiteral("GenerateSpecificationReport"));
        GenerateSpecificationReport->resize(501, 73);
        GenerateSpecificationReport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateSpecificationReport->setModal(false);
        gridLayout = new QGridLayout(GenerateSpecificationReport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillDateEdit = new QDateEdit(GenerateSpecificationReport);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateSpecificationReport);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateSpecificationReport);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 4);

        label_2 = new QLabel(GenerateSpecificationReport);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        fromDateEdit = new QDateEdit(GenerateSpecificationReport);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(GenerateSpecificationReport);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(GenerateSpecificationReport);

        QMetaObject::connectSlotsByName(GenerateSpecificationReport);
    } // setupUi

    void retranslateUi(QDialog *GenerateSpecificationReport)
    {
        GenerateSpecificationReport->setWindowTitle(QApplication::translate("GenerateSpecificationReport", "Generate specification report", 0));
        okBtn->setText(QApplication::translate("GenerateSpecificationReport", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateSpecificationReport", "Cancel", 0));
        label_2->setText(QApplication::translate("GenerateSpecificationReport", "Till date:", 0));
        fromLb->setText(QApplication::translate("GenerateSpecificationReport", "From date:", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateSpecificationReport: public Ui_GenerateSpecificationReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATESPECREPDLG_H
