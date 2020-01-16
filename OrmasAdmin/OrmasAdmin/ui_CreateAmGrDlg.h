/********************************************************************************
** Form generated from reading UI file 'CreateAmGrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEAMGRDLG_H
#define UI_CREATEAMGRDLG_H

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

class Ui_CreateAmortizeGroup
{
public:
    QGridLayout *gridLayout;
    QLabel *tillMonthLb;
    QLabel *fromMonthLb;
    QLineEdit *fromMonthEdit;
    QLineEdit *gNumberEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *gNumberLb;
    QLineEdit *toMonthEdit;

    void setupUi(QDialog *CreateAmortizeGroup)
    {
        if (CreateAmortizeGroup->objectName().isEmpty())
            CreateAmortizeGroup->setObjectName(QStringLiteral("CreateAmortizeGroup"));
        CreateAmortizeGroup->resize(461, 125);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateAmortizeGroup->sizePolicy().hasHeightForWidth());
        CreateAmortizeGroup->setSizePolicy(sizePolicy);
        CreateAmortizeGroup->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateAmortizeGroup->setModal(false);
        gridLayout = new QGridLayout(CreateAmortizeGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        tillMonthLb = new QLabel(CreateAmortizeGroup);
        tillMonthLb->setObjectName(QStringLiteral("tillMonthLb"));

        gridLayout->addWidget(tillMonthLb, 2, 0, 1, 1);

        fromMonthLb = new QLabel(CreateAmortizeGroup);
        fromMonthLb->setObjectName(QStringLiteral("fromMonthLb"));

        gridLayout->addWidget(fromMonthLb, 1, 0, 1, 1);

        fromMonthEdit = new QLineEdit(CreateAmortizeGroup);
        fromMonthEdit->setObjectName(QStringLiteral("fromMonthEdit"));

        gridLayout->addWidget(fromMonthEdit, 1, 1, 1, 1);

        gNumberEdit = new QLineEdit(CreateAmortizeGroup);
        gNumberEdit->setObjectName(QStringLiteral("gNumberEdit"));

        gridLayout->addWidget(gNumberEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateAmortizeGroup);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateAmortizeGroup);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        gNumberLb = new QLabel(CreateAmortizeGroup);
        gNumberLb->setObjectName(QStringLiteral("gNumberLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gNumberLb->sizePolicy().hasHeightForWidth());
        gNumberLb->setSizePolicy(sizePolicy1);
        gNumberLb->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(gNumberLb, 0, 0, 1, 1);

        toMonthEdit = new QLineEdit(CreateAmortizeGroup);
        toMonthEdit->setObjectName(QStringLiteral("toMonthEdit"));

        gridLayout->addWidget(toMonthEdit, 2, 1, 1, 1);

        QWidget::setTabOrder(gNumberEdit, fromMonthEdit);
        QWidget::setTabOrder(fromMonthEdit, toMonthEdit);
        QWidget::setTabOrder(toMonthEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateAmortizeGroup);

        QMetaObject::connectSlotsByName(CreateAmortizeGroup);
    } // setupUi

    void retranslateUi(QDialog *CreateAmortizeGroup)
    {
        CreateAmortizeGroup->setWindowTitle(QApplication::translate("CreateAmortizeGroup", "Create/Update amortize group", 0));
        tillMonthLb->setText(QApplication::translate("CreateAmortizeGroup", "Till month:", 0));
        fromMonthLb->setText(QApplication::translate("CreateAmortizeGroup", "From month:", 0));
#ifndef QT_NO_TOOLTIP
        fromMonthEdit->setToolTip(QApplication::translate("CreateAmortizeGroup", "<html><head/><body><p>For example: Main St. 99</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        gNumberEdit->setToolTip(QApplication::translate("CreateAmortizeGroup", "<html><head/><body><p>For example: &quot;River Co.&quot;</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("CreateAmortizeGroup", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateAmortizeGroup", "Cancel", 0));
        gNumberLb->setText(QApplication::translate("CreateAmortizeGroup", "Group number:", 0));
#ifndef QT_NO_TOOLTIP
        toMonthEdit->setToolTip(QApplication::translate("CreateAmortizeGroup", "<html><head/><body><p>For example: 929999999 (only digits)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateAmortizeGroup: public Ui_CreateAmortizeGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEAMGRDLG_H
