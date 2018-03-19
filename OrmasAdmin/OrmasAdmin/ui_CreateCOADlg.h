/********************************************************************************
** Form generated from reading UI file 'CreateCOADlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECOADLG_H
#define UI_CREATECOADLG_H

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

class Ui_CreateChartOfAccounts
{
public:
    QGridLayout *gridLayout;
    QLabel *numberLb;
    QLineEdit *nameEdit;
    QLineEdit *numberEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QPushButton *accTypeBtn;
    QLineEdit *accTypeEdit;
    QLabel *label;
    QLabel *accTypeNamePh;

    void setupUi(QDialog *CreateChartOfAccounts)
    {
        if (CreateChartOfAccounts->objectName().isEmpty())
            CreateChartOfAccounts->setObjectName(QStringLiteral("CreateChartOfAccounts"));
        CreateChartOfAccounts->resize(461, 147);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateChartOfAccounts->sizePolicy().hasHeightForWidth());
        CreateChartOfAccounts->setSizePolicy(sizePolicy);
        CreateChartOfAccounts->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateChartOfAccounts->setModal(false);
        gridLayout = new QGridLayout(CreateChartOfAccounts);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        numberLb = new QLabel(CreateChartOfAccounts);
        numberLb->setObjectName(QStringLiteral("numberLb"));

        gridLayout->addWidget(numberLb, 0, 0, 1, 1);

        nameEdit = new QLineEdit(CreateChartOfAccounts);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        numberEdit = new QLineEdit(CreateChartOfAccounts);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));

        gridLayout->addWidget(numberEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateChartOfAccounts);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateChartOfAccounts);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        nameLb = new QLabel(CreateChartOfAccounts);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLb->sizePolicy().hasHeightForWidth());
        nameLb->setSizePolicy(sizePolicy1);
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        accTypeBtn = new QPushButton(CreateChartOfAccounts);
        accTypeBtn->setObjectName(QStringLiteral("accTypeBtn"));
        accTypeBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(accTypeBtn, 2, 0, 1, 1);

        accTypeEdit = new QLineEdit(CreateChartOfAccounts);
        accTypeEdit->setObjectName(QStringLiteral("accTypeEdit"));
        accTypeEdit->setReadOnly(true);

        gridLayout->addWidget(accTypeEdit, 2, 1, 1, 1);

        label = new QLabel(CreateChartOfAccounts);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        accTypeNamePh = new QLabel(CreateChartOfAccounts);
        accTypeNamePh->setObjectName(QStringLiteral("accTypeNamePh"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        accTypeNamePh->setFont(font);

        gridLayout->addWidget(accTypeNamePh, 3, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateChartOfAccounts);

        QMetaObject::connectSlotsByName(CreateChartOfAccounts);
    } // setupUi

    void retranslateUi(QDialog *CreateChartOfAccounts)
    {
        CreateChartOfAccounts->setWindowTitle(QApplication::translate("CreateChartOfAccounts", "Create/Update chart of accounts", 0));
        numberLb->setText(QApplication::translate("CreateChartOfAccounts", "Number:", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateChartOfAccounts", "<html><head/><body><p>For example: &quot;River Co.&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        numberEdit->setToolTip(QApplication::translate("CreateChartOfAccounts", "<html><head/><body><p>For example: Main St. 99</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateChartOfAccounts", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateChartOfAccounts", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateChartOfAccounts", "Name:", 0));
        accTypeBtn->setText(QApplication::translate("CreateChartOfAccounts", "Select account type", 0));
        label->setText(QApplication::translate("CreateChartOfAccounts", "Account type name:", 0));
        accTypeNamePh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateChartOfAccounts: public Ui_CreateChartOfAccounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECOADLG_H
