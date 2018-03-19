/********************************************************************************
** Form generated from reading UI file 'CreateAccTPDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCTPDLG_H
#define UI_CREATEACCTPDLG_H

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

class Ui_CreateAccountType
{
public:
    QGridLayout *gridLayout;
    QLineEdit *nameEdit;
    QLineEdit *numberEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *label_4;
    QLabel *numberLb;
    QLineEdit *commentEdit;

    void setupUi(QDialog *CreateAccountType)
    {
        if (CreateAccountType->objectName().isEmpty())
            CreateAccountType->setObjectName(QStringLiteral("CreateAccountType"));
        CreateAccountType->resize(461, 125);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateAccountType->sizePolicy().hasHeightForWidth());
        CreateAccountType->setSizePolicy(sizePolicy);
        CreateAccountType->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateAccountType->setModal(false);
        gridLayout = new QGridLayout(CreateAccountType);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        nameEdit = new QLineEdit(CreateAccountType);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        numberEdit = new QLineEdit(CreateAccountType);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));

        gridLayout->addWidget(numberEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateAccountType);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateAccountType);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        nameLb = new QLabel(CreateAccountType);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLb->sizePolicy().hasHeightForWidth());
        nameLb->setSizePolicy(sizePolicy1);
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        label_4 = new QLabel(CreateAccountType);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        numberLb = new QLabel(CreateAccountType);
        numberLb->setObjectName(QStringLiteral("numberLb"));

        gridLayout->addWidget(numberLb, 1, 0, 1, 1);

        commentEdit = new QLineEdit(CreateAccountType);
        commentEdit->setObjectName(QStringLiteral("commentEdit"));
        commentEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(commentEdit, 2, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, numberEdit);
        QWidget::setTabOrder(numberEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateAccountType);

        QMetaObject::connectSlotsByName(CreateAccountType);
    } // setupUi

    void retranslateUi(QDialog *CreateAccountType)
    {
        CreateAccountType->setWindowTitle(QApplication::translate("CreateAccountType", "Create/Update account type", 0));
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateAccountType", "<html><head/><body><p>For example: &quot;River Co.&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        numberEdit->setToolTip(QApplication::translate("CreateAccountType", "<html><head/><body><p>For example: Main St. 99</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateAccountType", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateAccountType", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateAccountType", "Name:", 0));
        label_4->setText(QApplication::translate("CreateAccountType", "Comment:", 0));
        numberLb->setText(QApplication::translate("CreateAccountType", "Number:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAccountType: public Ui_CreateAccountType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCTPDLG_H
