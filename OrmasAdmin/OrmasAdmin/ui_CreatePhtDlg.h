/********************************************************************************
** Form generated from reading UI file 'CreatePhtDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPHTDLG_H
#define UI_CREATEPHTDLG_H

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

class Ui_CreatePhoto
{
public:
    QGridLayout *gridLayout;
    QLineEdit *userEdit;
    QPushButton *userBtn;
    QLineEdit *sourceEdit;
    QLabel *sourceLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *productEdit;
    QPushButton *productBtn;

    void setupUi(QDialog *CreatePhoto)
    {
        if (CreatePhoto->objectName().isEmpty())
            CreatePhoto->setObjectName(QStringLiteral("CreatePhoto"));
        CreatePhoto->resize(400, 131);
        CreatePhoto->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePhoto->setModal(false);
        gridLayout = new QGridLayout(CreatePhoto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        userEdit = new QLineEdit(CreatePhoto);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 3, 1, 1, 1);

        userBtn = new QPushButton(CreatePhoto);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 3, 0, 1, 1);

        sourceEdit = new QLineEdit(CreatePhoto);
        sourceEdit->setObjectName(QStringLiteral("sourceEdit"));

        gridLayout->addWidget(sourceEdit, 5, 1, 1, 1);

        sourceLb = new QLabel(CreatePhoto);
        sourceLb->setObjectName(QStringLiteral("sourceLb"));

        gridLayout->addWidget(sourceLb, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreatePhoto);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreatePhoto);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 2);

        productEdit = new QLineEdit(CreatePhoto);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 4, 1, 1, 1);

        productBtn = new QPushButton(CreatePhoto);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 4, 0, 1, 1);

        QWidget::setTabOrder(userBtn, userEdit);
        QWidget::setTabOrder(userEdit, productBtn);
        QWidget::setTabOrder(productBtn, productEdit);
        QWidget::setTabOrder(productEdit, sourceEdit);
        QWidget::setTabOrder(sourceEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePhoto);

        QMetaObject::connectSlotsByName(CreatePhoto);
    } // setupUi

    void retranslateUi(QDialog *CreatePhoto)
    {
        CreatePhoto->setWindowTitle(QApplication::translate("CreatePhoto", "Create/Update payment", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        userBtn->setText(QApplication::translate("CreatePhoto", "Select user", 0));
#ifndef QT_NO_TOOLTIP
        sourceEdit->setToolTip(QApplication::translate("CreatePhoto", "<html><head/><body><p>For example: C:\\My Documents\\User\\Photo\\Milk.jpeg</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sourceLb->setText(QApplication::translate("CreatePhoto", "Source:", 0));
        okBtn->setText(QApplication::translate("CreatePhoto", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePhoto", "Cancel", 0));
        productBtn->setText(QApplication::translate("CreatePhoto", "Select product", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePhoto: public Ui_CreatePhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPHTDLG_H
