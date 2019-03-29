/********************************************************************************
** Form generated from reading UI file 'GenerateAccRepDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEACCREPDLG_H
#define UI_GENERATEACCREPDLG_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GenerateAccountCardReport
{
public:
    QGridLayout *gridLayout;
    QLabel *accNamePh;
    QLabel *orLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *accIDEdit;
    QLabel *accLb;
    QDateEdit *tillDateEdit;
    QDateEdit *fromDateEdit;
    QLabel *fromLb;
    QLabel *label_2;
    QLineEdit *accNumberEdit;
    QLabel *accNameLb;
    QPushButton *accBtn;
    QPushButton *sAccBtn;

    void setupUi(QDialog *GenerateAccountCardReport)
    {
        if (GenerateAccountCardReport->objectName().isEmpty())
            GenerateAccountCardReport->setObjectName(QStringLiteral("GenerateAccountCardReport"));
        GenerateAccountCardReport->resize(634, 190);
        GenerateAccountCardReport->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GenerateAccountCardReport->setModal(false);
        gridLayout = new QGridLayout(GenerateAccountCardReport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        accNamePh = new QLabel(GenerateAccountCardReport);
        accNamePh->setObjectName(QStringLiteral("accNamePh"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accNamePh->sizePolicy().hasHeightForWidth());
        accNamePh->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        accNamePh->setFont(font);
        accNamePh->setTextFormat(Qt::RichText);
        accNamePh->setScaledContents(true);

        gridLayout->addWidget(accNamePh, 4, 1, 1, 5);

        orLb = new QLabel(GenerateAccountCardReport);
        orLb->setObjectName(QStringLiteral("orLb"));
        orLb->setMinimumSize(QSize(40, 0));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        orLb->setFont(font1);
        orLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(orLb, 1, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(GenerateAccountCardReport);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(GenerateAccountCardReport);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 5);

        accIDEdit = new QLineEdit(GenerateAccountCardReport);
        accIDEdit->setObjectName(QStringLiteral("accIDEdit"));
        accIDEdit->setMaximumSize(QSize(120, 16777215));
        accIDEdit->setReadOnly(true);

        gridLayout->addWidget(accIDEdit, 1, 2, 1, 1);

        accLb = new QLabel(GenerateAccountCardReport);
        accLb->setObjectName(QStringLiteral("accLb"));

        gridLayout->addWidget(accLb, 1, 4, 1, 1);

        tillDateEdit = new QDateEdit(GenerateAccountCardReport);
        tillDateEdit->setObjectName(QStringLiteral("tillDateEdit"));

        gridLayout->addWidget(tillDateEdit, 0, 4, 1, 1);

        fromDateEdit = new QDateEdit(GenerateAccountCardReport);
        fromDateEdit->setObjectName(QStringLiteral("fromDateEdit"));

        gridLayout->addWidget(fromDateEdit, 0, 2, 1, 1);

        fromLb = new QLabel(GenerateAccountCardReport);
        fromLb->setObjectName(QStringLiteral("fromLb"));

        gridLayout->addWidget(fromLb, 0, 1, 1, 1);

        label_2 = new QLabel(GenerateAccountCardReport);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        accNumberEdit = new QLineEdit(GenerateAccountCardReport);
        accNumberEdit->setObjectName(QStringLiteral("accNumberEdit"));
        accNumberEdit->setMinimumSize(QSize(150, 0));
        accNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(accNumberEdit, 1, 5, 1, 1);

        accNameLb = new QLabel(GenerateAccountCardReport);
        accNameLb->setObjectName(QStringLiteral("accNameLb"));

        gridLayout->addWidget(accNameLb, 3, 1, 1, 1);

        accBtn = new QPushButton(GenerateAccountCardReport);
        accBtn->setObjectName(QStringLiteral("accBtn"));

        gridLayout->addWidget(accBtn, 1, 1, 1, 1);

        sAccBtn = new QPushButton(GenerateAccountCardReport);
        sAccBtn->setObjectName(QStringLiteral("sAccBtn"));

        gridLayout->addWidget(sAccBtn, 2, 1, 1, 1);

        QWidget::setTabOrder(fromDateEdit, tillDateEdit);
        QWidget::setTabOrder(tillDateEdit, accBtn);
        QWidget::setTabOrder(accBtn, accNumberEdit);
        QWidget::setTabOrder(accNumberEdit, sAccBtn);
        QWidget::setTabOrder(sAccBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, accIDEdit);

        retranslateUi(GenerateAccountCardReport);

        QMetaObject::connectSlotsByName(GenerateAccountCardReport);
    } // setupUi

    void retranslateUi(QDialog *GenerateAccountCardReport)
    {
        GenerateAccountCardReport->setWindowTitle(QApplication::translate("GenerateAccountCardReport", "Generate account card report", 0));
        accNamePh->setText(QString());
        orLb->setText(QApplication::translate("GenerateAccountCardReport", "OR", 0));
        okBtn->setText(QApplication::translate("GenerateAccountCardReport", "OK", 0));
        cancelBtn->setText(QApplication::translate("GenerateAccountCardReport", "Cancel", 0));
        accLb->setText(QApplication::translate("GenerateAccountCardReport", "Enter account number:", 0));
        fromLb->setText(QApplication::translate("GenerateAccountCardReport", "From date:", 0));
        label_2->setText(QApplication::translate("GenerateAccountCardReport", "Till date:", 0));
        accNumberEdit->setText(QString());
        accNameLb->setText(QApplication::translate("GenerateAccountCardReport", "Account name:", 0));
        accBtn->setText(QApplication::translate("GenerateAccountCardReport", "Select account", 0));
        sAccBtn->setText(QApplication::translate("GenerateAccountCardReport", "Select subaccount", 0));
    } // retranslateUi

};

namespace Ui {
    class GenerateAccountCardReport: public Ui_GenerateAccountCardReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEACCREPDLG_H
