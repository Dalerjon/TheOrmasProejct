/********************************************************************************
** Form generated from reading UI file 'CreateRelTypeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERELTYPEDLG_H
#define UI_CREATERELTYPEDLG_H

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

class Ui_CreateRelationType
{
public:
    QGridLayout *gridLayout;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *commentLb;
    QTextEdit *commentTextEdit;

    void setupUi(QDialog *CreateRelationType)
    {
        if (CreateRelationType->objectName().isEmpty())
            CreateRelationType->setObjectName(QStringLiteral("CreateRelationType"));
        CreateRelationType->resize(400, 150);
        CreateRelationType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRelationType->setModal(false);
        gridLayout = new QGridLayout(CreateRelationType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        nameEdit = new QLineEdit(CreateRelationType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateRelationType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateRelationType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        nameLb = new QLabel(CreateRelationType);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 1, 0, 1, 1);

        commentLb = new QLabel(CreateRelationType);
        commentLb->setObjectName(QStringLiteral("commentLb"));

        gridLayout->addWidget(commentLb, 4, 0, 1, 1);

        commentTextEdit = new QTextEdit(CreateRelationType);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));

        gridLayout->addWidget(commentTextEdit, 4, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, commentTextEdit);
        QWidget::setTabOrder(commentTextEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateRelationType);

        QMetaObject::connectSlotsByName(CreateRelationType);
    } // setupUi

    void retranslateUi(QDialog *CreateRelationType)
    {
        CreateRelationType->setWindowTitle(QApplication::translate("CreateRelationType", "Create/Update relation type", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateRelationType", "<html><head/><body><p>For example: EXPEDITOR FOR</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateRelationType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateRelationType", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateRelationType", "Name:", 0));
        commentLb->setText(QApplication::translate("CreateRelationType", "Comment", 0));
#ifndef QT_NO_TOOLTIP
        commentTextEdit->setToolTip(QApplication::translate("CreateRelationType", "<html><head/><body><p>Does not mandatory field</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateRelationType: public Ui_CreateRelationType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERELTYPEDLG_H
