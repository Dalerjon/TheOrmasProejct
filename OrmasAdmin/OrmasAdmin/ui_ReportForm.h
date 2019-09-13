/********************************************************************************
** Form generated from reading UI file 'ReportForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTFORM_H
#define UI_REPORTFORM_H

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

class Ui_ReportForm
{
public:
    QGridLayout *gridLayout;
    QWidget *functionWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *viewBtn;
    QPushButton *closeBtn;
    QTableView *tableView;

    void setupUi(QWidget *ReportForm)
    {
        if (ReportForm->objectName().isEmpty())
            ReportForm->setObjectName(QStringLiteral("ReportForm"));
        ReportForm->resize(800, 600);
        ReportForm->setMinimumSize(QSize(800, 600));
        ReportForm->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(ReportForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(12, 12, 12, 12);
        functionWidget = new QWidget(ReportForm);
        functionWidget->setObjectName(QStringLiteral("functionWidget"));
        functionWidget->setMaximumSize(QSize(16777215, 55));
        gridLayout_2 = new QGridLayout(functionWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(functionWidget, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        viewBtn = new QPushButton(ReportForm);
        viewBtn->setObjectName(QStringLiteral("viewBtn"));

        horizontalLayout->addWidget(viewBtn);

        closeBtn = new QPushButton(ReportForm);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(75, 0));

        horizontalLayout->addWidget(closeBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        tableView = new QTableView(ReportForm);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(tableView, 1, 0, 1, 2);

        QWidget::setTabOrder(tableView, closeBtn);

        retranslateUi(ReportForm);

        QMetaObject::connectSlotsByName(ReportForm);
    } // setupUi

    void retranslateUi(QWidget *ReportForm)
    {
        ReportForm->setWindowTitle(QString());
        viewBtn->setText(QApplication::translate("ReportForm", "View", 0));
        closeBtn->setText(QApplication::translate("ReportForm", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ReportForm: public Ui_ReportForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTFORM_H
