/********************************************************************************
** Form generated from reading UI file 'CloseOfMonthDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSEOFMONTHDLG_H
#define UI_CLOSEOFMONTHDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CloseOfMonth
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QTextEdit *textEdit;

    void setupUi(QDialog *CloseOfMonth)
    {
        if (CloseOfMonth->objectName().isEmpty())
            CloseOfMonth->setObjectName(QStringLiteral("CloseOfMonth"));
        CloseOfMonth->resize(501, 188);
        CloseOfMonth->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CloseOfMonth->setModal(false);
        gridLayout = new QGridLayout(CloseOfMonth);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CloseOfMonth);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CloseOfMonth);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 2);

        textEdit = new QTextEdit(CloseOfMonth);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CloseOfMonth);

        QMetaObject::connectSlotsByName(CloseOfMonth);
    } // setupUi

    void retranslateUi(QDialog *CloseOfMonth)
    {
        CloseOfMonth->setWindowTitle(QApplication::translate("CloseOfMonth", "Close of month", 0));
        okBtn->setText(QApplication::translate("CloseOfMonth", "OK", 0));
        cancelBtn->setText(QApplication::translate("CloseOfMonth", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CloseOfMonth: public Ui_CloseOfMonth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSEOFMONTHDLG_H
