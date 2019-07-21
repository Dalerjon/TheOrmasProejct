/********************************************************************************
** Form generated from reading UI file 'CreateShrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESHRDLG_H
#define UI_CREATESHRDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateShareholder
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLb;
    QLabel *phoneLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *infoLB;
    QLineEdit *infoEdit;
    QLabel *phonePh;
    QPushButton *userBtn;
    QLabel *surnameLb;
    QLabel *namePh;
    QLabel *surnamePh;
    QLineEdit *userEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *countOfStockEdit;
    QLabel *cosLb;

    void setupUi(QDialog *CreateShareholder)
    {
        if (CreateShareholder->objectName().isEmpty())
            CreateShareholder->setObjectName(QStringLiteral("CreateShareholder"));
        CreateShareholder->resize(685, 160);
        CreateShareholder->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateShareholder->setModal(false);
        gridLayout = new QGridLayout(CreateShareholder);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        nameLb = new QLabel(CreateShareholder);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 2, 1, 1, 1);

        phoneLb = new QLabel(CreateShareholder);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(50, 0));
        phoneLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(phoneLb, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateShareholder);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateShareholder);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 13, 1, 1, 6);

        infoLB = new QLabel(CreateShareholder);
        infoLB->setObjectName(QStringLiteral("infoLB"));

        gridLayout->addWidget(infoLB, 4, 1, 1, 1);

        infoEdit = new QLineEdit(CreateShareholder);
        infoEdit->setObjectName(QStringLiteral("infoEdit"));

        gridLayout->addWidget(infoEdit, 4, 2, 1, 5);

        phonePh = new QLabel(CreateShareholder);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 2, 6, 1, 1);

        userBtn = new QPushButton(CreateShareholder);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 1, 1, 1, 2);

        surnameLb = new QLabel(CreateShareholder);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 2, 3, 1, 1);

        namePh = new QLabel(CreateShareholder);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 2, 2, 1, 1);

        surnamePh = new QLabel(CreateShareholder);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 2, 4, 1, 1);

        userEdit = new QLineEdit(CreateShareholder);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 1, 3, 1, 2);

        statusWidget = new QWidget(CreateShareholder);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(statusWidget, 12, 1, 1, 6);

        countOfStockEdit = new QLineEdit(CreateShareholder);
        countOfStockEdit->setObjectName(QStringLiteral("countOfStockEdit"));

        gridLayout->addWidget(countOfStockEdit, 3, 2, 1, 5);

        cosLb = new QLabel(CreateShareholder);
        cosLb->setObjectName(QStringLiteral("cosLb"));
        cosLb->setMinimumSize(QSize(60, 0));

        gridLayout->addWidget(cosLb, 3, 1, 1, 1);

        QWidget::setTabOrder(userBtn, infoEdit);
        QWidget::setTabOrder(infoEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, userEdit);

        retranslateUi(CreateShareholder);

        QMetaObject::connectSlotsByName(CreateShareholder);
    } // setupUi

    void retranslateUi(QDialog *CreateShareholder)
    {
        CreateShareholder->setWindowTitle(QApplication::translate("CreateShareholder", "Create/Update shareholder", 0));
        nameLb->setText(QApplication::translate("CreateShareholder", "Name:", 0));
        phoneLb->setText(QApplication::translate("CreateShareholder", "Phone:", 0));
        okBtn->setText(QApplication::translate("CreateShareholder", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateShareholder", "Cancel", 0));
        infoLB->setText(QApplication::translate("CreateShareholder", "Information:", 0));
        phonePh->setText(QString());
        userBtn->setText(QApplication::translate("CreateShareholder", "Select user", 0));
        surnameLb->setText(QApplication::translate("CreateShareholder", "Surname:", 0));
        namePh->setText(QString());
        surnamePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateShareholder", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        cosLb->setText(QApplication::translate("CreateShareholder", "Count of stock:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateShareholder: public Ui_CreateShareholder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESHRDLG_H
