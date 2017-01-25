/********************************************************************************
** Form generated from reading UI file 'CreateMsrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEMSRDLG_H
#define UI_CREATEMSRDLG_H

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

QT_BEGIN_NAMESPACE

class Ui_CreateMeasure
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *nameEdit;
    QLineEdit *shortNameEdit;
    QLabel *nameLb;
    QLabel *shortNameLb;
    QLabel *unitLb;
    QLineEdit *unitEdit;

    void setupUi(QDialog *CreateMeasure)
    {
        if (CreateMeasure->objectName().isEmpty())
            CreateMeasure->setObjectName(QStringLiteral("CreateMeasure"));
        CreateMeasure->resize(400, 125);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateMeasure->sizePolicy().hasHeightForWidth());
        CreateMeasure->setSizePolicy(sizePolicy);
        CreateMeasure->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateMeasure->setModal(false);
        gridLayout = new QGridLayout(CreateMeasure);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateMeasure);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateMeasure);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        nameEdit = new QLineEdit(CreateMeasure);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        shortNameEdit = new QLineEdit(CreateMeasure);
        shortNameEdit->setObjectName(QStringLiteral("shortNameEdit"));

        gridLayout->addWidget(shortNameEdit, 1, 1, 1, 1);

        nameLb = new QLabel(CreateMeasure);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        shortNameLb = new QLabel(CreateMeasure);
        shortNameLb->setObjectName(QStringLiteral("shortNameLb"));

        gridLayout->addWidget(shortNameLb, 1, 0, 1, 1);

        unitLb = new QLabel(CreateMeasure);
        unitLb->setObjectName(QStringLiteral("unitLb"));

        gridLayout->addWidget(unitLb, 2, 0, 1, 1);

        unitEdit = new QLineEdit(CreateMeasure);
        unitEdit->setObjectName(QStringLiteral("unitEdit"));

        gridLayout->addWidget(unitEdit, 2, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, shortNameEdit);
        QWidget::setTabOrder(shortNameEdit, unitEdit);
        QWidget::setTabOrder(unitEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateMeasure);

        QMetaObject::connectSlotsByName(CreateMeasure);
    } // setupUi

    void retranslateUi(QDialog *CreateMeasure)
    {
        CreateMeasure->setWindowTitle(QApplication::translate("CreateMeasure", "Create/Update Measure", 0));
        okBtn->setText(QApplication::translate("CreateMeasure", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateMeasure", "Cencel", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateMeasure", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        shortNameEdit->setToolTip(QApplication::translate("CreateMeasure", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreateMeasure", "Name:", 0));
        shortNameLb->setText(QApplication::translate("CreateMeasure", "Short name:", 0));
        unitLb->setText(QApplication::translate("CreateMeasure", "Change unit", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateMeasure: public Ui_CreateMeasure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMSRDLG_H
