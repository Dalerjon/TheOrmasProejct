/********************************************************************************
** Form generated from reading UI file 'InfoForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOFORM_H
#define UI_INFOFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AboutDlg
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *copyrightsLb;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *companyLb;
    QLabel *infoLb;
    QPushButton *closeBtn;

    void setupUi(QDialog *AboutDlg)
    {
        if (AboutDlg->objectName().isEmpty())
            AboutDlg->setObjectName(QStringLiteral("AboutDlg"));
        AboutDlg->resize(500, 220);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDlg->sizePolicy().hasHeightForWidth());
        AboutDlg->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(AboutDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        copyrightsLb = new QLabel(AboutDlg);
        copyrightsLb->setObjectName(QStringLiteral("copyrightsLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(copyrightsLb->sizePolicy().hasHeightForWidth());
        copyrightsLb->setSizePolicy(sizePolicy1);
        copyrightsLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(copyrightsLb, 4, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        companyLb = new QLabel(AboutDlg);
        companyLb->setObjectName(QStringLiteral("companyLb"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        companyLb->setFont(font);
        companyLb->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(companyLb, 1, 1, 1, 1);

        infoLb = new QLabel(AboutDlg);
        infoLb->setObjectName(QStringLiteral("infoLb"));
        sizePolicy1.setHeightForWidth(infoLb->sizePolicy().hasHeightForWidth());
        infoLb->setSizePolicy(sizePolicy1);
        infoLb->setTextFormat(Qt::RichText);
        infoLb->setWordWrap(true);

        gridLayout->addWidget(infoLb, 2, 1, 1, 1);

        closeBtn = new QPushButton(AboutDlg);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        gridLayout->addWidget(closeBtn, 5, 2, 1, 1);


        retranslateUi(AboutDlg);

        QMetaObject::connectSlotsByName(AboutDlg);
    } // setupUi

    void retranslateUi(QDialog *AboutDlg)
    {
        AboutDlg->setWindowTitle(QApplication::translate("AboutDlg", "Info", 0));
        copyrightsLb->setText(QApplication::translate("AboutDlg", "All rights reserved. Since 2016", 0));
        companyLb->setText(QApplication::translate("AboutDlg", "ORION MANAGMENT & ANALISYS SYSTEM\n"
"", 0));
        infoLb->setText(QApplication::translate("AboutDlg", "Phone for contact: +92 783 11 66", 0));
        closeBtn->setText(QApplication::translate("AboutDlg", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDlg: public Ui_AboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOFORM_H
