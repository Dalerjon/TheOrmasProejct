/********************************************************************************
** Form generated from reading UI file 'ReworkRawDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REWORKRAWDLG_H
#define UI_REWORKRAWDLG_H

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

class Ui_ReworkRaw
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *createBtn;
    QPushButton *cancelBtn;
    QPushButton *productBtn;
    QLabel *prodNamePh;
    QLabel *measurePh;
    QLabel *prodNameLb;
    QLabel *volumePh;
    QLineEdit *countEdit;
    QLabel *countLb;
    QLabel *measureLb;
    QLineEdit *productEdit;
    QLabel *volumeLb;

    void setupUi(QDialog *ReworkRaw)
    {
        if (ReworkRaw->objectName().isEmpty())
            ReworkRaw->setObjectName(QStringLiteral("ReworkRaw"));
        ReworkRaw->resize(634, 134);
        ReworkRaw->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        ReworkRaw->setModal(false);
        gridLayout = new QGridLayout(ReworkRaw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 17);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        createBtn = new QPushButton(ReworkRaw);
        createBtn->setObjectName(QStringLiteral("createBtn"));

        horizontalLayout->addWidget(createBtn);

        cancelBtn = new QPushButton(ReworkRaw);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 6);

        productBtn = new QPushButton(ReworkRaw);
        productBtn->setObjectName(QStringLiteral("productBtn"));

        gridLayout->addWidget(productBtn, 0, 0, 1, 2);

        prodNamePh = new QLabel(ReworkRaw);
        prodNamePh->setObjectName(QStringLiteral("prodNamePh"));
        prodNamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        prodNamePh->setFont(font);

        gridLayout->addWidget(prodNamePh, 1, 1, 1, 1);

        measurePh = new QLabel(ReworkRaw);
        measurePh->setObjectName(QStringLiteral("measurePh"));
        measurePh->setMinimumSize(QSize(100, 0));
        measurePh->setFont(font);

        gridLayout->addWidget(measurePh, 1, 5, 1, 1);

        prodNameLb = new QLabel(ReworkRaw);
        prodNameLb->setObjectName(QStringLiteral("prodNameLb"));
        prodNameLb->setMinimumSize(QSize(70, 0));
        prodNameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(prodNameLb, 1, 0, 1, 1);

        volumePh = new QLabel(ReworkRaw);
        volumePh->setObjectName(QStringLiteral("volumePh"));
        volumePh->setMinimumSize(QSize(100, 0));
        volumePh->setFont(font);

        gridLayout->addWidget(volumePh, 1, 3, 1, 1);

        countEdit = new QLineEdit(ReworkRaw);
        countEdit->setObjectName(QStringLiteral("countEdit"));

        gridLayout->addWidget(countEdit, 2, 3, 1, 1);

        countLb = new QLabel(ReworkRaw);
        countLb->setObjectName(QStringLiteral("countLb"));
        countLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(countLb, 2, 0, 1, 2);

        measureLb = new QLabel(ReworkRaw);
        measureLb->setObjectName(QStringLiteral("measureLb"));

        gridLayout->addWidget(measureLb, 1, 4, 1, 1);

        productEdit = new QLineEdit(ReworkRaw);
        productEdit->setObjectName(QStringLiteral("productEdit"));
        productEdit->setReadOnly(true);

        gridLayout->addWidget(productEdit, 0, 3, 1, 1);

        volumeLb = new QLabel(ReworkRaw);
        volumeLb->setObjectName(QStringLiteral("volumeLb"));
        volumeLb->setMinimumSize(QSize(70, 0));
        volumeLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(volumeLb, 1, 2, 1, 1);

        QWidget::setTabOrder(productBtn, createBtn);
        QWidget::setTabOrder(createBtn, cancelBtn);

        retranslateUi(ReworkRaw);

        QMetaObject::connectSlotsByName(ReworkRaw);
    } // setupUi

    void retranslateUi(QDialog *ReworkRaw)
    {
        ReworkRaw->setWindowTitle(QApplication::translate("ReworkRaw", "Rework raw", 0));
        createBtn->setText(QApplication::translate("ReworkRaw", "Create", 0));
        cancelBtn->setText(QApplication::translate("ReworkRaw", "Cancel", 0));
        productBtn->setText(QApplication::translate("ReworkRaw", "Select product", 0));
        prodNamePh->setText(QString());
        measurePh->setText(QString());
        prodNameLb->setText(QApplication::translate("ReworkRaw", "Product name:", 0));
        volumePh->setText(QString());
#ifndef QT_NO_TOOLTIP
        countEdit->setToolTip(QApplication::translate("ReworkRaw", "<html><head/><body><p>For example: 100</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        countLb->setText(QApplication::translate("ReworkRaw", "Count:", 0));
        measureLb->setText(QApplication::translate("ReworkRaw", "Measure:", 0));
        volumeLb->setText(QApplication::translate("ReworkRaw", "Volume:", 0));
    } // retranslateUi

};

namespace Ui {
    class ReworkRaw: public Ui_ReworkRaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REWORKRAWDLG_H
