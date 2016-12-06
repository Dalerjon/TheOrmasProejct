/********************************************************************************
** Form generated from reading UI file 'CreateStsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESTSDLG_H
#define UI_CREATESTSDLG_H

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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateStatus
{
public:
    QGridLayout *gridLayout;
    QLabel *codeLb;
    QLabel *nameLb;
    QLabel *commentLb;
    QLineEdit *codeEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *nameEdit;
    QTextEdit *commentTextEdit;

    void setupUi(QDialog *CreateStatus)
    {
        if (CreateStatus->objectName().isEmpty())
            CreateStatus->setObjectName(QStringLiteral("CreateStatus"));
        CreateStatus->resize(400, 176);
        CreateStatus->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateStatus->setModal(true);
        gridLayout = new QGridLayout(CreateStatus);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        codeLb = new QLabel(CreateStatus);
        codeLb->setObjectName(QStringLiteral("codeLb"));
        codeLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(codeLb, 0, 0, 1, 1);

        nameLb = new QLabel(CreateStatus);
        nameLb->setObjectName(QStringLiteral("nameLb"));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        commentLb = new QLabel(CreateStatus);
        commentLb->setObjectName(QStringLiteral("commentLb"));

        gridLayout->addWidget(commentLb, 2, 0, 1, 1);

        codeEdit = new QLineEdit(CreateStatus);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateStatus);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateStatus);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        nameEdit = new QLineEdit(CreateStatus);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        commentTextEdit = new QTextEdit(CreateStatus);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));

        gridLayout->addWidget(commentTextEdit, 2, 1, 1, 1);


        retranslateUi(CreateStatus);

        QMetaObject::connectSlotsByName(CreateStatus);
    } // setupUi

    void retranslateUi(QDialog *CreateStatus)
    {
        CreateStatus->setWindowTitle(QApplication::translate("CreateStatus", "Create/Update status", 0));
        codeLb->setText(QApplication::translate("CreateStatus", "Code:", 0));
        nameLb->setText(QApplication::translate("CreateStatus", "Name:", 0));
        commentLb->setText(QApplication::translate("CreateStatus", "Comment:", 0));
#ifndef QT_NO_TOOLTIP
        codeEdit->setToolTip(QApplication::translate("CreateStatus", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateStatus", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateStatus", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateStatus", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        commentTextEdit->setToolTip(QApplication::translate("CreateStatus", "Can leave it an empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateStatus: public Ui_CreateStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESTSDLG_H
