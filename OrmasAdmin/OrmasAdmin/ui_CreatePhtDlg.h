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
    QLabel *phonePh;
    QLabel *nameLb;
    QLabel *namePh;
    QLabel *surnameLb;
    QLabel *surnamePh;
    QLabel *phoneLb;
    QLabel *prodNameLb;
    QLabel *prodNamePh;
    QLabel *volumeLb;
    QLabel *volumePh;
    QLabel *measureLb;
    QLabel *measurePh;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *productEdit;
    QLineEdit *userEdit;
    QLineEdit *sourceEdit;
    QLabel *sourceLb;
    QPushButton *userBtn;
    QPushButton *productBtn;

    void setupUi(QDialog *CreatePhoto)
    {
        if (CreatePhoto->objectName().isEmpty())
            CreatePhoto->setObjectName(QStringLiteral("CreatePhoto"));
        CreatePhoto->resize(637, 183);
        CreatePhoto->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreatePhoto->setModal(false);
        gridLayout = new QGridLayout(CreatePhoto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        phonePh = new QLabel(CreatePhoto);
        phonePh->setObjectName(QStringLiteral("phonePh"));
        phonePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        phonePh->setFont(font);

        gridLayout->addWidget(phonePh, 4, 5, 1, 1);

        nameLb = new QLabel(CreatePhoto);
        nameLb->setObjectName(QStringLiteral("nameLb"));
        nameLb->setMinimumSize(QSize(50, 0));
        nameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(nameLb, 4, 0, 1, 1);

        namePh = new QLabel(CreatePhoto);
        namePh->setObjectName(QStringLiteral("namePh"));
        namePh->setMinimumSize(QSize(100, 0));
        namePh->setFont(font);

        gridLayout->addWidget(namePh, 4, 1, 1, 1);

        surnameLb = new QLabel(CreatePhoto);
        surnameLb->setObjectName(QStringLiteral("surnameLb"));
        surnameLb->setMinimumSize(QSize(50, 0));
        surnameLb->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(surnameLb, 4, 2, 1, 1);

        surnamePh = new QLabel(CreatePhoto);
        surnamePh->setObjectName(QStringLiteral("surnamePh"));
        surnamePh->setMinimumSize(QSize(100, 0));
        surnamePh->setFont(font);

        gridLayout->addWidget(surnamePh, 4, 3, 1, 1);

        phoneLb = new QLabel(CreatePhoto);
        phoneLb->setObjectName(QStringLiteral("phoneLb"));

        gridLayout->addWidget(phoneLb, 4, 4, 1, 1);

        prodNameLb = new QLabel(CreatePhoto);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 6, 0, 1, 1);

        prodNamePh = new QLabel(CreatePhoto);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(150, 0));
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 6, 1, 1, 1);

        volumeLb = new QLabel(CreatePhoto);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 6, 2, 1, 1);

        volumePh = new QLabel(CreatePhoto);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 6, 3, 1, 1);

        measureLb = new QLabel(CreatePhoto);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 6, 4, 1, 1);

        measurePh = new QLabel(CreatePhoto);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 6, 5, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 6);

        productEdit = new QLineEdit(CreatePhoto);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 5, 3, 1, 1);

        userEdit = new QLineEdit(CreatePhoto);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setReadOnly(true);

        gridLayout->addWidget(userEdit, 3, 3, 1, 1);

        sourceEdit = new QLineEdit(CreatePhoto);
        sourceEdit->setObjectName(QStringLiteral("sourceEdit"));

        gridLayout->addWidget(sourceEdit, 7, 3, 1, 1);

        sourceLb = new QLabel(CreatePhoto);
        sourceLb->setObjectName(QStringLiteral("sourceLb"));

        gridLayout->addWidget(sourceLb, 7, 0, 1, 2);

        userBtn = new QPushButton(CreatePhoto);
        userBtn->setObjectName(QStringLiteral("userBtn"));
        userBtn->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(userBtn, 3, 0, 1, 2);

        productBtn = new QPushButton(CreatePhoto);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 5, 0, 1, 2);

        QWidget::setTabOrder(userBtn, productBtn);
        QWidget::setTabOrder(productBtn, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreatePhoto);

        QMetaObject::connectSlotsByName(CreatePhoto);
    } // setupUi

    void retranslateUi(QDialog *CreatePhoto)
    {
        CreatePhoto->setWindowTitle(QApplication::translate("CreatePhoto", "Create/Update photo", 0));
        phonePh->setText(QString());
        nameLb->setText(QApplication::translate("CreatePhoto", "Name:", 0));
        namePh->setText(QString());
        surnameLb->setText(QApplication::translate("CreatePhoto", "Surname:", 0));
        surnamePh->setText(QString());
        phoneLb->setText(QApplication::translate("CreatePhoto", "Phone:", 0));
        prodNameLb->setText(QApplication::translate("CreatePhoto", "Product name:", 0));
        prodNamePh->setText(QString());
        volumeLb->setText(QApplication::translate("CreatePhoto", "Volume:", 0));
        volumePh->setText(QString());
        measureLb->setText(QApplication::translate("CreatePhoto", "Measure:", 0));
        measurePh->setText(QString());
        okBtn->setText(QApplication::translate("CreatePhoto", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreatePhoto", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        userEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        sourceEdit->setToolTip(QApplication::translate("CreatePhoto", "<html><head/><body><p>For example: C:\\My Documents\\User\\Photo\\Milk.jpeg</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sourceLb->setText(QApplication::translate("CreatePhoto", "Source:", 0));
        userBtn->setText(QApplication::translate("CreatePhoto", "Select user", 0));
        productBtn->setText(QApplication::translate("CreatePhoto", "Select product", 0));
    } // retranslateUi

};

namespace Ui {
    class CreatePhoto: public Ui_CreatePhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPHTDLG_H
