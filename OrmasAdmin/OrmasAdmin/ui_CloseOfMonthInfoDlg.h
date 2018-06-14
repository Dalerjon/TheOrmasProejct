/********************************************************************************
** Form generated from reading UI file 'CloseOfMonthInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSEOFMONTHINFODLG_H
#define UI_CLOSEOFMONTHINFODLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CloseOfMonthState
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *closeLb;

    void setupUi(QDialog *CloseOfMonthState)
    {
        if (CloseOfMonthState->objectName().isEmpty())
            CloseOfMonthState->setObjectName(QStringLiteral("CloseOfMonthState"));
        CloseOfMonthState->resize(659, 419);
        CloseOfMonthState->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CloseOfMonthState->setModal(false);
        gridLayout = new QGridLayout(CloseOfMonthState);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        textEdit = new QTextEdit(CloseOfMonthState);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CloseOfMonthState);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CloseOfMonthState);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 2);

        closeLb = new QLabel(CloseOfMonthState);
        closeLb->setObjectName(QStringLiteral("closeLb"));

        gridLayout->addWidget(closeLb, 0, 1, 1, 1);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CloseOfMonthState);

        QMetaObject::connectSlotsByName(CloseOfMonthState);
    } // setupUi

    void retranslateUi(QDialog *CloseOfMonthState)
    {
        CloseOfMonthState->setWindowTitle(QApplication::translate("CloseOfMonthState", "Close of month state info", 0));
        okBtn->setText(QApplication::translate("CloseOfMonthState", "OK", 0));
        cancelBtn->setText(QApplication::translate("CloseOfMonthState", "Cancel", 0));
        closeLb->setText(QApplication::translate("CloseOfMonthState", "Close of Month state information:", 0));
    } // retranslateUi

};

namespace Ui {
    class CloseOfMonthState: public Ui_CloseOfMonthState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSEOFMONTHINFODLG_H
