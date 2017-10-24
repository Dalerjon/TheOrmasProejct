/********************************************************************************
** Form generated from reading UI file 'CreateLcnDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATELCNDLG_H
#define UI_CREATELCNDLG_H

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

class Ui_CreateLocation
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *countryCodeEdit;
    QLineEdit *countryNameEdit;
    QLabel *countryCode;
    QLabel *countryName;
    QLabel *regionName;
    QLabel *cityName;
    QLineEdit *regionNameEdit;
    QLineEdit *cityNameEdit;

    void setupUi(QDialog *CreateLocation)
    {
        if (CreateLocation->objectName().isEmpty())
            CreateLocation->setObjectName(QStringLiteral("CreateLocation"));
        CreateLocation->resize(400, 151);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateLocation->sizePolicy().hasHeightForWidth());
        CreateLocation->setSizePolicy(sizePolicy);
        CreateLocation->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateLocation->setModal(false);
        gridLayout = new QGridLayout(CreateLocation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateLocation);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateLocation);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);

        countryCodeEdit = new QLineEdit(CreateLocation);
        countryCodeEdit->setObjectName(QStringLiteral("countryCodeEdit"));

        gridLayout->addWidget(countryCodeEdit, 1, 1, 1, 1);

        countryNameEdit = new QLineEdit(CreateLocation);
        countryNameEdit->setObjectName(QStringLiteral("countryNameEdit"));

        gridLayout->addWidget(countryNameEdit, 0, 1, 1, 1);

        countryCode = new QLabel(CreateLocation);
        countryCode->setObjectName(QStringLiteral("countryCode"));

        gridLayout->addWidget(countryCode, 1, 0, 1, 1);

        countryName = new QLabel(CreateLocation);
        countryName->setObjectName(QStringLiteral("countryName"));
        countryName->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(countryName, 0, 0, 1, 1);

        regionName = new QLabel(CreateLocation);
        regionName->setObjectName(QStringLiteral("regionName"));

        gridLayout->addWidget(regionName, 2, 0, 1, 1);

        cityName = new QLabel(CreateLocation);
        cityName->setObjectName(QStringLiteral("cityName"));

        gridLayout->addWidget(cityName, 3, 0, 1, 1);

        regionNameEdit = new QLineEdit(CreateLocation);
        regionNameEdit->setObjectName(QStringLiteral("regionNameEdit"));

        gridLayout->addWidget(regionNameEdit, 2, 1, 1, 1);

        cityNameEdit = new QLineEdit(CreateLocation);
        cityNameEdit->setObjectName(QStringLiteral("cityNameEdit"));

        gridLayout->addWidget(cityNameEdit, 3, 1, 1, 1);

        QWidget::setTabOrder(countryNameEdit, countryCodeEdit);
        QWidget::setTabOrder(countryCodeEdit, regionNameEdit);
        QWidget::setTabOrder(regionNameEdit, cityNameEdit);
        QWidget::setTabOrder(cityNameEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateLocation);

        QMetaObject::connectSlotsByName(CreateLocation);
    } // setupUi

    void retranslateUi(QDialog *CreateLocation)
    {
        CreateLocation->setWindowTitle(QApplication::translate("CreateLocation", "Create/Update location", 0));
        okBtn->setText(QApplication::translate("CreateLocation", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateLocation", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        countryCodeEdit->setToolTip(QApplication::translate("CreateLocation", "<html><head/><body><p>For example : 9999</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        countryNameEdit->setToolTip(QApplication::translate("CreateLocation", "<html><head/><body><p>For example: Russia</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        countryCode->setText(QApplication::translate("CreateLocation", "Country code:", 0));
        countryName->setText(QApplication::translate("CreateLocation", "Country name:", 0));
        regionName->setText(QApplication::translate("CreateLocation", "Region name:", 0));
        cityName->setText(QApplication::translate("CreateLocation", "City name:", 0));
#ifndef QT_NO_TOOLTIP
        regionNameEdit->setToolTip(QApplication::translate("CreateLocation", "<html><head/><body><p>For example: Novosibirsk</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cityNameEdit->setToolTip(QApplication::translate("CreateLocation", "<html><head/><body><p>For example: Tomsk</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CreateLocation: public Ui_CreateLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATELCNDLG_H
