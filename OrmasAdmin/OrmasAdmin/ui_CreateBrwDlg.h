/********************************************************************************
** Form generated from reading UI file 'CreateBrwDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBRWDLG_H
#define UI_CREATEBRWDLG_H

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

class Ui_CreateBorrower
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
    QLineEdit *commnetEdit;
    QLabel *phonePh;
    QPushButton *userBtn;
    QLabel *surnameLb;
    QLabel *namePh;
    QLabel *surnamePh;
    QLineEdit *userEdit;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QDialog *CreateBorrower)
    {
        if (CreateBorrower->objectName().isEmpty())
            CreateBorrower->setObjectName(QStringLiteral("CreateBorrower"));
        CreateBorrower->resize(685, 134);
        CreateBorrower->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateBorrower->setModal(false);
        gridLayout = new QGridLayout(CreateBorrower);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        nameLb = new QLabel(CreateBorrower);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 2, 1, 1, 1);

        phoneLb = new QLabel(CreateBorrower);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));
        phoneLb->setMinimumSize(QSize(50, 0));
        phoneLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(phoneLb, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateBorrower);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateBorrower);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 12, 1, 1, 6);

        infoLB = new QLabel(CreateBorrower);
        infoLB->setObjectName(QStringLiteral("infoLB"));

        gridLayout->addWidget(infoLB, 3, 1, 1, 1);

        commnetEdit = new QLineEdit(CreateBorrower);
        commnetEdit->setObjectName(QStringLiteral("commnetEdit"));

        gridLayout->addWidget(commnetEdit, 3, 2, 1, 5);

        phonePh = new QLabel(CreateBorrower);
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

        userBtn = new QPushButton(CreateBorrower);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 1, 1, 1, 2);

        surnameLb = new QLabel(CreateBorrower);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 2, 3, 1, 1);

        namePh = new QLabel(CreateBorrower);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 2, 2, 1, 1);

        surnamePh = new QLabel(CreateBorrower);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 2, 4, 1, 1);

        userEdit = new QLineEdit(CreateBorrower);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 1, 3, 1, 2);

        statusWidget = new QWidget(CreateBorrower);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        horizontalLayout_3 = new QHBoxLayout(statusWidget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(statusWidget, 11, 1, 1, 6);

        QWidget::setTabOrder(userBtn, commnetEdit);
        QWidget::setTabOrder(commnetEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, userEdit);

        retranslateUi(CreateBorrower);

        QMetaObject::connectSlotsByName(CreateBorrower);
    } // setupUi

    void retranslateUi(QDialog *CreateBorrower)
    {
        CreateBorrower->setWindowTitle(QApplication::translate("CreateBorrower", "Create/Update borrower", 0));
        nameLb->setText(QApplication::translate("CreateBorrower", "Name:", 0));
        phoneLb->setText(QApplication::translate("CreateBorrower", "Phone:", 0));
        okBtn->setText(QApplication::translate("CreateBorrower", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateBorrower", "Cancel", 0));
        infoLB->setText(QApplication::translate("CreateBorrower", "Comment:", 0));
        phonePh->setText(QString());
        userBtn->setText(QApplication::translate("CreateBorrower", "Select user", 0));
        surnameLb->setText(QApplication::translate("CreateBorrower", "Surname:", 0));
        namePh->setText(QString());
        surnamePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QApplication::translate("CreateBorrower", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateBorrower: public Ui_CreateBorrower {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBRWDLG_H
