/********************************************************************************
** Form generated from reading UI file 'CreateCurDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECURDLG_H
#define UI_CREATECURDLG_H

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

class Ui_CreateCurrency
{
public:
    QGridLayout *gridLayout;
    QLabel *shortNameLb;
    QLabel *nameLb;
    QLineEdit *shortNameEdit;
    QLabel *unitLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *unitEdit;
    QLabel *codeLb;
    QLineEdit *codeEdit;
    QLineEdit *nameEdit;
    QLabel *mainTradeLb;
    QComboBox *mainTradeCmbBox;

    void setupUi(QDialog *CreateCurrency)
    {
        if (CreateCurrency->objectName().isEmpty())
            CreateCurrency->setObjectName(QStringLiteral("CreateCurrency"));
        CreateCurrency->resize(400, 177);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCurrency->sizePolicy().hasHeightForWidth());
        CreateCurrency->setSizePolicy(sizePolicy);
        CreateCurrency->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCurrency->setModal(false);
        gridLayout = new QGridLayout(CreateCurrency);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        shortNameLb = new QLabel(CreateCurrency);
        shortNameLb->setObjectName(QStringLiteral("shortNameLb"));

        gridLayout->addWidget(shortNameLb, 1, 0, 1, 1);

        nameLb = new QLabel(CreateCurrency);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 2, 0, 1, 1);

        shortNameEdit = new QLineEdit(CreateCurrency);
        shortNameEdit->setObjectName(QStringLiteral("shortNameEdit"));

        gridLayout->addWidget(shortNameEdit, 1, 1, 1, 1);

        unitLb = new QLabel(CreateCurrency);
        unitLb->setObjectName(QStringLiteral("unitLb"));

        gridLayout->addWidget(unitLb, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCurrency);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCurrency);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);

        unitEdit = new QLineEdit(CreateCurrency);
        unitEdit->setObjectName(QStringLiteral("unitEdit"));

        gridLayout->addWidget(unitEdit, 3, 1, 1, 1);

        codeLb = new QLabel(CreateCurrency);
        codeLb->setObjectName(QStringLiteral("codeLb"));
        codeLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(codeLb, 0, 0, 1, 1);

        codeEdit = new QLineEdit(CreateCurrency);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        nameEdit = new QLineEdit(CreateCurrency);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 1, 1, 1);

        mainTradeLb = new QLabel(CreateCurrency);
        mainTradeLb->setObjectName(QStringLiteral("mainTradeLb"));
        mainTradeLb->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(mainTradeLb, 4, 0, 1, 1);

        mainTradeCmbBox = new QComboBox(CreateCurrency);
        mainTradeCmbBox->setObjectName(QStringLiteral("mainTradeCmbBox"));

        gridLayout->addWidget(mainTradeCmbBox, 4, 1, 1, 1);

        QWidget::setTabOrder(codeEdit, shortNameEdit);
        QWidget::setTabOrder(shortNameEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, unitEdit);
        QWidget::setTabOrder(unitEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateCurrency);

        QMetaObject::connectSlotsByName(CreateCurrency);
    } // setupUi

    void retranslateUi(QDialog *CreateCurrency)
    {
        CreateCurrency->setWindowTitle(QApplication::translate("CreateCurrency", "Create/Update Currency", 0));
        shortNameLb->setText(QApplication::translate("CreateCurrency", "Short name:", 0));
        nameLb->setText(QApplication::translate("CreateCurrency", "Name:", 0));
#ifndef QT_NO_TOOLTIP
        shortNameEdit->setToolTip(QApplication::translate("CreateCurrency", "The length must be equal to 3", 0));
#endif // QT_NO_TOOLTIP
        unitLb->setText(QApplication::translate("CreateCurrency", "Change unit:", 0));
        okBtn->setText(QApplication::translate("CreateCurrency", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCurrency", "Cancel", 0));
        codeLb->setText(QApplication::translate("CreateCurrency", "Code:", 0));
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateCurrency", "Only digits. The length must be equal to 3", 0));
#endif // QT_NO_TOOLTIP
        codeEdit->setInputMask(QApplication::translate("CreateCurrency", "000", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateCurrency", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        mainTradeLb->setText(QApplication::translate("CreateCurrency", "Main trade:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateCurrency: public Ui_CreateCurrency {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECURDLG_H
