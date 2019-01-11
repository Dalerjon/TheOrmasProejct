/********************************************************************************
** Form generated from reading UI file 'CreateBrhDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBRHDLG_H
#define UI_CREATEBRHDLG_H

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

class Ui_CreateBranch
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

    void setupUi(QDialog *CreateBranch)
    {
        if (CreateBranch->objectName().isEmpty())
            CreateBranch->setObjectName(QStringLiteral("CreateBranch"));
        CreateBranch->resize(461, 323);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateBranch->sizePolicy().hasHeightForWidth());
        CreateBranch->setSizePolicy(sizePolicy);
        CreateBranch->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateBranch->setModal(false);
        gridLayout = new QGridLayout(CreateBranch);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        phoneEdit = new QLineEdit(CreateBranch);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 2, 1, 1, 1);

        phoneLb = new QLabel(CreateBranch);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 2, 0, 1, 1);

        addresLb = new QLabel(CreateBranch);
        addresLb->setObjectName(QStringLiteral("addresLb"));

        gridLayout->addWidget(addresLb, 1, 0, 1, 1);

        addressEdit = new QLineEdit(CreateBranch);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout->addWidget(addressEdit, 1, 1, 1, 1);

        nameEdit = new QLineEdit(CreateBranch);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateBranch);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateBranch);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        nameLb = new QLabel(CreateBranch);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameLb->sizePolicy().hasHeightForWidth());
        nameLb->setSizePolicy(sizePolicy1);
        nameLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLb, 0, 0, 1, 1);

        label_4 = new QLabel(CreateBranch);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        commentTextEdit = new QTextEdit(CreateBranch);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));

        gridLayout->addWidget(commentTextEdit, 3, 1, 1, 1);

        QWidget::setTabOrder(nameEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, commentTextEdit);
        QWidget::setTabOrder(commentTextEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateBranch);

        QMetaObject::connectSlotsByName(CreateBranch);
    } // setupUi

    void retranslateUi(QDialog *CreateBranch)
    {
        CreateBranch->setWindowTitle(QApplication::translate("CreateBranch", "Create/Update branch", 0));
#ifndef QT_NO_TOOLTIP
        phoneEdit->setToolTip(QApplication::translate("CreateBranch", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        phoneLb->setText(QApplication::translate("CreateBranch", "Phone:", 0));
        addresLb->setText(QApplication::translate("CreateBranch", "Address:", 0));
#ifndef QT_NO_TOOLTIP
        addressEdit->setToolTip(QApplication::translate("CreateBranch", "<html><head/><body><p>For example: Main St. 99</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        nameEdit->setToolTip(QApplication::translate("CreateBranch", "<html><head/><body><p>For example: &quot;River Co.&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateBranch", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateBranch", "Cancel", 0));
        nameLb->setText(QApplication::translate("CreateBranch", "Name:", 0));
        label_4->setText(QApplication::translate("CreateBranch", "Comment:", 0));
#ifndef QT_NO_TOOLTIP
        commentTextEdit->setToolTip(QApplication::translate("CreateBranch", "<html><head/><body><p>Does not mandatory field! If you want, than add some comments</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateBranch: public Ui_CreateBranch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBRHDLG_H
