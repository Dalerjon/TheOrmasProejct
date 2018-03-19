/********************************************************************************
** Form generated from reading UI file 'CreateJbsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEJBSDLG_H
#define UI_CREATEJBSDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
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

class Ui_CreateJobsheet
{
public:
    QGridLayout *gridLayout;
    QLabel *empNameLb;
    QLabel *empSurnameLb;
    QLabel *empSurnamePh;
    QLabel *empPhonePh;
    QLabel *empPhoneLb;
    QLabel *empNamePh;
    QLabel *prodNameLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *measurePh;
    QLineEdit *productEdit;
    QLineEdit *employeeEdit;
    QLineEdit *countEdit;
    QPushButton *productBtn;
    QPushButton *employeeBtn;
    QLabel *countLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QWidget *editSectionWgt;
    QGridLayout *gridLayout_3;
    QDateEdit *dateEdit;
    QLabel *dateLb;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CreateJobsheet)
    {
        if (CreateJobsheet->objectName().isEmpty())
            CreateJobsheet->setObjectName(QStringLiteral("CreateJobsheet"));
        CreateJobsheet->resize(537, 215);
        CreateJobsheet->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateJobsheet->setModal(false);
        gridLayout = new QGridLayout(CreateJobsheet);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        empNameLb = new QLabel(CreateJobsheet);
        empNameLb->setObjectName(QStringLiteral("empNameLb"));
        empNameLb->setMinimumSize(QSize(50, 0));
        empNameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empNameLb, 1, 0, 1, 1);

        empSurnameLb = new QLabel(CreateJobsheet);
        empSurnameLb->setObjectName(QStringLiteral("empSurnameLb"));
        empSurnameLb->setMinimumSize(QSize(50, 0));
        empSurnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(empSurnameLb, 1, 2, 1, 1);

        empSurnamePh = new QLabel(CreateJobsheet);
        empSurnamePh->setObjectName(QStringLiteral("empSurnamePh"));
        empSurnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        empSurnamePh->setFont(font);

        gridLayout->addWidget(empSurnamePh, 1, 3, 1, 1);

        empPhonePh = new QLabel(CreateJobsheet);
        empPhonePh->setObjectName(QStringLiteral("empPhonePh"));
        empPhonePh->setMinimumSize(QSize(100, 0));
        empPhonePh->setFont(font);

        gridLayout->addWidget(empPhonePh, 1, 5, 1, 1);

        empPhoneLb = new QLabel(CreateJobsheet);
        empPhoneLb->setObjectName(QStringLiteral("empPhoneLb"));

        gridLayout->addWidget(empPhoneLb, 1, 4, 1, 1);

        empNamePh = new QLabel(CreateJobsheet);
        empNamePh->setObjectName(QStringLiteral("empNamePh"));
        empNamePh->setMinimumSize(QSize(100, 0));
        empNamePh->setFont(font);

        gridLayout->addWidget(empNamePh, 1, 1, 1, 1);

        prodNameLb = new QLabel(CreateJobsheet);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 3, 0, 1, 1);

        prodNamePh = new QLabel(CreateJobsheet);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 3, 1, 1, 1);

        volumeLb = new QLabel(CreateJobsheet);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 3, 2, 1, 1);

        volumePh = new QLabel(CreateJobsheet);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 3, 3, 1, 1);

        measureLb = new QLabel(CreateJobsheet);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 3, 4, 1, 1);

        measurePh = new QLabel(CreateJobsheet);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 3, 5, 1, 1);

        productEdit = new QLineEdit(CreateJobsheet);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setMaximumSize(QSize(150, 16777215));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 2, 2, 1, 2);

        employeeEdit = new QLineEdit(CreateJobsheet);
        employeeEdit->setObjectName(QStringLiteral("employeeEdit"));
        employeeEdit->setMaximumSize(QSize(150, 16777215));
        employeeEdit->setReadOnly(true);

        gridLayout->addWidget(employeeEdit, 0, 2, 1, 2);

        countEdit = new QLineEdit(CreateJobsheet);
        countEdit->setObjectName(QStringLiteral("countEdit"));
        countEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(countEdit, 4, 2, 1, 2);

        productBtn = new QPushButton(CreateJobsheet);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 2, 0, 1, 2);

        employeeBtn = new QPushButton(CreateJobsheet);
        employeeBtn->setObjectName(QStringLiteral("employeeBtn"));

        gridLayout->addWidget(employeeBtn, 0, 0, 1, 2);

        countLb = new QLabel(CreateJobsheet);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 4, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateJobsheet);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateJobsheet);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 6);

        editSectionWgt = new QWidget(CreateJobsheet);
        editSectionWgt->setObjectName(QStringLiteral("editSectionWgt"));
        gridLayout_3 = new QGridLayout(editSectionWgt);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        dateEdit = new QDateEdit(editSectionWgt);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);
        dateEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_3->addWidget(dateEdit, 0, 1, 1, 1);

        dateLb = new QLabel(editSectionWgt);
        dateLb->setObjectName(QStringLiteral("dateLb"));
        dateLb->setMinimumSize(QSize(175, 0));
        dateLb->setMaximumSize(QSize(300, 16777215));

        gridLayout_3->addWidget(dateLb, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout->addWidget(editSectionWgt, 5, 0, 1, 6);

        QWidget::setTabOrder(employeeBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateJobsheet);

        QMetaObject::connectSlotsByName(CreateJobsheet);
    } // setupUi

    void retranslateUi(QDialog *CreateJobsheet)
    {
        CreateJobsheet->setWindowTitle(QApplication::translate("CreateJobsheet", "Create/Update jobsheet", 0));
        empNameLb->setText(QApplication::translate("CreateJobsheet", "Name:", 0));
        empSurnameLb->setText(QApplication::translate("CreateJobsheet", "Surname:", 0));
        empSurnamePh->setText(QString());
        empPhonePh->setText(QString());
        empPhoneLb->setText(QApplication::translate("CreateJobsheet", "Phone:", 0));
        empNamePh->setText(QString());
        prodNameLb->setText(QApplication::translate("CreateJobsheet", "Product name:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreateJobsheet", "Volume:", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreateJobsheet", "Measure:", 0));
        measurePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("CreateJobsheet", "<html><head/><body><p>For example: 10.5</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        productBtn->setText(QApplication::translate("CreateJobsheet", "Select product:", 0));
        employeeBtn->setText(QApplication::translate("CreateJobsheet", "Select employee", 0));
        countLb->setText(QApplication::translate("CreateJobsheet", "Count:", 0));
        okBtn->setText(QApplication::translate("CreateJobsheet", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateJobsheet", "Cancel", 0));
        dateLb->setText(QApplication::translate("CreateJobsheet", "Date:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateJobsheet: public Ui_CreateJobsheet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEJBSDLG_H
