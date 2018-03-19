/********************************************************************************
** Form generated from reading UI file 'CreateTmsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETMSDLG_H
#define UI_CREATETMSDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTimesheet
{
public:
    QGridLayout *gridLayout;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QLabel *dateLb;
    QDateEdit *dateEdit;
    QLabel *namePh;
    QLabel *surnameLb;
    QLabel *surnamePh;
    QLabel *phoneLb;
    QLabel *workedTimeLb;
    QPushButton *salaryBtn;
    QLineEdit *workedTimeEdit;
    QLineEdit *salaryEdit;
    QLabel *nameLb;
    QLabel *phonePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CreateTimesheet)
    {
        if (CreateTimesheet->objectName().isEmpty())
            CreateTimesheet->setObjectName(QStringLiteral("CreateTimesheet"));
        CreateTimesheet->resize(648, 160);
        CreateTimesheet->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateTimesheet->setModal(false);
        gridLayout = new QGridLayout(CreateTimesheet);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        editSectionWgt = new QWidget(CreateTimesheet);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        dateLb = new QLabel(editSectionWgt);
        dateLb->setObjectName(QStringLiteral("dateLb"));
        dateLb->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(dateLb, 0, 0, 1, 1);

        dateEdit = new QDateEdit(editSectionWgt);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(dateEdit, 0, 1, 1, 1);


        gridLayout->addWidget(editSectionWgt, 3, 0, 1, 2);

        namePh = new QLabel(CreateTimesheet);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(120, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 1, 1, 1, 1);

        surnameLb = new QLabel(CreateTimesheet);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 1, 2, 1, 1);

        surnamePh = new QLabel(CreateTimesheet);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(120, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 1, 3, 1, 1);

        phoneLb = new QLabel(CreateTimesheet);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 1, 4, 1, 1);

        workedTimeLb = new QLabel(CreateTimesheet);
        workedTimeLb->setObjectName(QStringLiteral("workedTimeLb"));
        workedTimeLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(workedTimeLb, 2, 0, 1, 1);

        salaryBtn = new QPushButton(CreateTimesheet);
        salaryBtn->setObjectName(QStringLiteral("salaryBtn"));

        gridLayout->addWidget(salaryBtn, 0, 0, 1, 1);

        workedTimeEdit = new QLineEdit(CreateTimesheet);
        workedTimeEdit->setObjectName(QStringLiteral("workedTimeEdit"));

        gridLayout->addWidget(workedTimeEdit, 2, 1, 1, 1);

        salaryEdit = new QLineEdit(CreateTimesheet);
        salaryEdit->setObjectName(QStringLiteral("salaryEdit"));
        salaryEdit->setReadOnly(true);

        gridLayout->addWidget(salaryEdit, 0, 1, 1, 1);

        nameLb = new QLabel(CreateTimesheet);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        phonePh = new QLabel(CreateTimesheet);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 1, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateTimesheet);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateTimesheet);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 6);

        QWidget::setTabOrder(salaryBtn, salaryEdit);
        QWidget::setTabOrder(salaryEdit, workedTimeEdit);
        QWidget::setTabOrder(workedTimeEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateTimesheet);

        QMetaObject::connectSlotsByName(CreateTimesheet);
    } // setupUi

    void retranslateUi(QDialog *CreateTimesheet)
    {
        CreateTimesheet->setWindowTitle(QApplication::translate("CreateTimesheet", "Create/Update timesheet", 0));
        dateLb->setText(QApplication::translate("CreateTimesheet", "Worked date:", 0));
        namePh->setText(QString());
        surnameLb->setText(QApplication::translate("CreateTimesheet", "Surname:", 0));
        surnamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreateTimesheet", "Phone:", 0));
        workedTimeLb->setText(QApplication::translate("CreateTimesheet", "Worked time:", 0));
        salaryBtn->setText(QApplication::translate("CreateTimesheet", "Select salary", 0));
#ifndef QT_NO_TOOLTIP
        workedTimeEdit->setToolTip(QApplication::translate("CreateTimesheet", "<html><head/><body><p>For example: 10.5</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nameLb->setText(QApplication::translate("CreateTimesheet", "Name:", 0));
        phonePh->setText(QString());
        okBtn->setText(QApplication::translate("CreateTimesheet", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateTimesheet", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateTimesheet: public Ui_CreateTimesheet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETMSDLG_H
