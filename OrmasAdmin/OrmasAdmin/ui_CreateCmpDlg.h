/********************************************************************************
** Form generated from reading UI file 'CreateCmpDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECMPDLG_H
#define UI_CREATECMPDLG_H

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

class Ui_CreateCompany
{
public:
    QGridLayout *gridLayout;
    QLineEdit *phoneEdit;
    QLabel *phoneLb;
    QLabel *addresLb;
    QLineEdit *addressEdit;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *nameLb;
    QLabel *label_4;
    QTextEdit *commentTextEdit;

    void setupUi(QDialog *CreateCompany)
    {
        if (CreateCompany->objectName().isEmpty())
            CreateCompany->setObjectName(QStringLiteral("CreateCompany"));
        CreateCompany->resize(461, 323);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCompany->sizePolicy().hasHeightForWidth());
        CreateCompany->setSizePolicy(sizePolicy);
        CreateCompany->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateCompany->setModal(false);
        gridLayout = new QGridLayout(CreateCompany);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        phoneEdit = new QLineEdit(CreateCompany);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 2, 1, 1, 1);

        phoneLb = new QLabel(CreateCompany);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 2, 0, 1, 1);

        addresLb = new QLabel(CreateCompany);
        addresLb->setObjectName(QStringLiteral("addresLb"));

        gridLayout->addWidget(addresLb, 1, 0, 1, 1);

        addressEdit = new QLineEdit(CreateCompany);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 1, 1, 1, 1);

        nameEdit = new QLineEdit(CreateCompany);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateCompany);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateCompany);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        nameLb = new QLabel(CreateCompany);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLb->sizePolicy().hasHeightForWidth());
        nameLb->setSizePolicy(sizePolicy1);
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        label_4 = new QLabel(CreateCompany);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        commentTextEdit = new QTextEdit(CreateCompany);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));

        gridLayout->addWidget(commentTextEdit, 3, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, commentTextEdit);
        QWidget::setTabOrder(commentTextEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateCompany);

        QMetaObject::connectSlotsByName(CreateCompany);
    } // setupUi

    void retranslateUi(QDialog *CreateCompany)
    {
        CreateCompany->setWindowTitle(QApplication::translate("CreateCompany", "Create/Update company", 0));
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreateCompany", "Must not be an empty", 0));
#endif // QT_NO_TOOLTIP
        phoneLb->setText(QApplication::translate("CreateCompany", "Phone:", 0));
        addresLb->setText(QApplication::translate("CreateCompany", "Address:", 0));
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateCompany", "Must not be an empty", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateCompany", "Must not be empty", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateCompany", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateCompany", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateCompany", "Name:", 0));
        label_4->setText(QApplication::translate("CreateCompany", "Comment:", 0));
#ifndef QT_NO_TOOLTIP
        commentTextEdit->setToolTip(QApplication::translate("CreateCompany", "Can leave it an empty", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateCompany: public Ui_CreateCompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECMPDLG_H
