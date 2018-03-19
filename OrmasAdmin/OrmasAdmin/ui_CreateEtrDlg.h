/********************************************************************************
** Form generated from reading UI file 'CreateEtrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEETRDLG_H
#define UI_CREATEETRDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateEntry
{
public:
    QGridLayout *gridLayout;
    QLineEdit *valueEdit;
    QDateTimeEdit *dateEdit;
    QPushButton *cAccBtn;
    QLabel *caLb;
    QLabel *valueLb;
    QLabel *orLb_2;
    QLineEdit *caIDEdit;
    QLineEdit *caNumberEdit;
    QLabel *daNameLb;
    QLabel *daNamePh;
    QLabel *dateLb;
    QLabel *orLb;
    QLabel *daLb;
    QLineEdit *daIDEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *dAccBtn;
    QLineEdit *daNumberEdit;
    QLabel *caNameLb;
    QLabel *caNamePh;

    void setupUi(QDialog *CreateEntry)
    {
        if (CreateEntry->objectName().isEmpty())
            CreateEntry->setObjectName(QStringLiteral("CreateEntry"));
        CreateEntry->resize(660, 207);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateEntry->sizePolicy().hasHeightForWidth());
        CreateEntry->setSizePolicy(sizePolicy);
        CreateEntry->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateEntry->setModal(false);
        gridLayout = new QGridLayout(CreateEntry);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        valueEdit = new QLineEdit(CreateEntry);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));
        valueEdit->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(valueEdit, 3, 1, 1, 2);

        dateEdit = new QDateTimeEdit(CreateEntry);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 2);

        cAccBtn = new QPushButton(CreateEntry);
        cAccBtn->setObjectName(QStringLiteral("cAccBtn"));

        gridLayout->addWidget(cAccBtn, 4, 0, 1, 1);

        caLb = new QLabel(CreateEntry);
        caLb->setObjectName(QStringLiteral("caLb"));

        gridLayout->addWidget(caLb, 4, 3, 1, 1);

        valueLb = new QLabel(CreateEntry);
        valueLb->setObjectName(QStringLiteral("valueLb"));
        valueLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(valueLb, 3, 0, 1, 1);

        orLb_2 = new QLabel(CreateEntry);
        orLb_2->setObjectName(QStringLiteral("orLb_2"));
        orLb_2->setMinimumSize(QSize(40, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        orLb_2->setFont(font);
        orLb_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(orLb_2, 4, 2, 1, 1);

        caIDEdit = new QLineEdit(CreateEntry);
        caIDEdit->setObjectName(QStringLiteral("caIDEdit"));
        caIDEdit->setMaximumSize(QSize(120, 16777215));
        caIDEdit->setReadOnly(true);

        gridLayout->addWidget(caIDEdit, 4, 1, 1, 1);

        caNumberEdit = new QLineEdit(CreateEntry);
        caNumberEdit->setObjectName(QStringLiteral("caNumberEdit"));
        caNumberEdit->setMinimumSize(QSize(150, 0));
        caNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(caNumberEdit, 4, 4, 1, 1);

        daNameLb = new QLabel(CreateEntry);
        daNameLb->setObjectName(QStringLiteral("daNameLb"));

        gridLayout->addWidget(daNameLb, 2, 0, 1, 1);

        daNamePh = new QLabel(CreateEntry);
        daNamePh->setObjectName(QStringLiteral("daNamePh"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        daNamePh->setFont(font1);

        gridLayout->addWidget(daNamePh, 2, 1, 1, 4);

        dateLb = new QLabel(CreateEntry);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        orLb = new QLabel(CreateEntry);
        orLb->setObjectName(QStringLiteral("orLb"));
        orLb->setMinimumSize(QSize(40, 0));
        orLb->setFont(font);
        orLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(orLb, 1, 2, 1, 1);

        daLb = new QLabel(CreateEntry);
        daLb->setObjectName(QStringLiteral("daLb"));

        gridLayout->addWidget(daLb, 1, 3, 1, 1);

        daIDEdit = new QLineEdit(CreateEntry);
        daIDEdit->setObjectName(QStringLiteral("daIDEdit"));
        daIDEdit->setMaximumSize(QSize(120, 16777215));
        daIDEdit->setReadOnly(true);

        gridLayout->addWidget(daIDEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateEntry);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateEntry);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 5);

        dAccBtn = new QPushButton(CreateEntry);
        dAccBtn->setObjectName(QStringLiteral("dAccBtn"));

        gridLayout->addWidget(dAccBtn, 1, 0, 1, 1);

        daNumberEdit = new QLineEdit(CreateEntry);
        daNumberEdit->setObjectName(QStringLiteral("daNumberEdit"));
        daNumberEdit->setMinimumSize(QSize(150, 0));
        daNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(daNumberEdit, 1, 4, 1, 1);

        caNameLb = new QLabel(CreateEntry);
        caNameLb->setObjectName(QStringLiteral("caNameLb"));

        gridLayout->addWidget(caNameLb, 5, 0, 1, 1);

        caNamePh = new QLabel(CreateEntry);
        caNamePh->setObjectName(QStringLiteral("caNamePh"));
        caNamePh->setFont(font1);

        gridLayout->addWidget(caNamePh, 5, 1, 1, 4);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateEntry);

        QMetaObject::connectSlotsByName(CreateEntry);
    } // setupUi

    void retranslateUi(QDialog *CreateEntry)
    {
        CreateEntry->setWindowTitle(QApplication::translate("CreateEntry", "Create account for  selected company, currency and type", 0));
        cAccBtn->setText(QApplication::translate("CreateEntry", "Select crediting account", 0));
        caLb->setText(QApplication::translate("CreateEntry", "Enter crediting account number:", 0));
        valueLb->setText(QApplication::translate("CreateEntry", "Value:", 0));
        orLb_2->setText(QApplication::translate("CreateEntry", "OR", 0));
        caNumberEdit->setText(QString());
        daNameLb->setText(QApplication::translate("CreateEntry", "Debiting account name:", 0));
        daNamePh->setText(QString());
        dateLb->setText(QApplication::translate("CreateEntry", "Date:", 0));
        orLb->setText(QApplication::translate("CreateEntry", "OR", 0));
        daLb->setText(QApplication::translate("CreateEntry", "Enter debiting account number:", 0));
        okBtn->setText(QApplication::translate("CreateEntry", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateEntry", "Cancel", 0));
        dAccBtn->setText(QApplication::translate("CreateEntry", "Select debiting account", 0));
        daNumberEdit->setText(QString());
        caNameLb->setText(QApplication::translate("CreateEntry", "Crediting account name:", 0));
        caNamePh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateEntry: public Ui_CreateEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEETRDLG_H
