/********************************************************************************
** Form generated from reading UI file 'DataForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAFORM_H
#define UI_DATAFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataForm
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *createBtn;
    QPushButton *editBtn;
    QPushButton *deleteBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *DataForm)
    {
        if (DataForm->objectName().isEmpty())
            DataForm->setObjectName(QStringLiteral("DataForm"));
        DataForm->resize(600, 300);
        DataForm->setMinimumSize(QSize(600, 300));
        DataForm->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(DataForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(12, 12, 12, 12);
        tableView = new QTableView(DataForm);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        createBtn = new QPushButton(DataForm);
        createBtn->setObjectName(QStringLiteral("createBtn"));

        horizontalLayout->addWidget(createBtn);

        editBtn = new QPushButton(DataForm);
        editBtn->setObjectName(QStringLiteral("editBtn"));

        horizontalLayout->addWidget(editBtn);

        deleteBtn = new QPushButton(DataForm);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));

        horizontalLayout->addWidget(deleteBtn);

        closeBtn = new QPushButton(DataForm);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        QWidget::setTabOrder(tableView, createBtn);
        QWidget::setTabOrder(createBtn, editBtn);
        QWidget::setTabOrder(editBtn, deleteBtn);
        QWidget::setTabOrder(deleteBtn, closeBtn);

        retranslateUi(DataForm);

        QMetaObject::connectSlotsByName(DataForm);
    } // setupUi

    void retranslateUi(QWidget *DataForm)
    {
        DataForm->setWindowTitle(QString());
        createBtn->setText(QApplication::translate("DataForm", "Create", 0));
        editBtn->setText(QApplication::translate("DataForm", "Edit", 0));
        deleteBtn->setText(QApplication::translate("DataForm", "Delete", 0));
        closeBtn->setText(QApplication::translate("DataForm", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class DataForm: public Ui_DataForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAFORM_H
