/********************************************************************************
** Form generated from reading UI file 'SearchDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDLG_H
#define UI_SEARCHDLG_H

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

class Ui_SearchInTable
{
public:
    QGridLayout *gridLayout;
    QLineEdit *searchEdit;
    QLabel *searchLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *SearchInTable)
    {
        if (SearchInTable->objectName().isEmpty())
            SearchInTable->setObjectName(QStringLiteral("SearchInTable"));
        SearchInTable->resize(501, 73);
        SearchInTable->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        SearchInTable->setModal(true);
        gridLayout = new QGridLayout(SearchInTable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        searchEdit = new QLineEdit(SearchInTable);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        gridLayout->addWidget(searchEdit, 0, 1, 1, 1);

        searchLb = new QLabel(SearchInTable);
        searchLb->setObjectName(QStringLiteral("searchLb"));
        searchLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(searchLb, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchBtn = new QPushButton(SearchInTable);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));

        horizontalLayout->addWidget(searchBtn);

        cancelBtn = new QPushButton(SearchInTable);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);

        QWidget::setTabOrder(searchBtn, cancelBtn);

        retranslateUi(SearchInTable);

        QMetaObject::connectSlotsByName(SearchInTable);
    } // setupUi

    void retranslateUi(QDialog *SearchInTable)
    {
        SearchInTable->setWindowTitle(QApplication::translate("SearchInTable", "Search in table", 0));
        searchLb->setText(QApplication::translate("SearchInTable", "Key word:", 0));
        searchBtn->setText(QApplication::translate("SearchInTable", "Search", 0));
        cancelBtn->setText(QApplication::translate("SearchInTable", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchInTable: public Ui_SearchInTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDLG_H
