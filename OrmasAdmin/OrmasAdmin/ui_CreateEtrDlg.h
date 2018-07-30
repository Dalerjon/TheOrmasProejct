/********************************************************************************
** Form generated from reading UI file 'CreateEtrDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEETRDLG_H
#define UI_CREATEETRDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
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

class Ui_CreateEntry
{
public:
    QGridLayout *gridLayout;
    QLineEdit *valueEdit;
    QLabel *orLb_2;
    QLabel *daNameLb;
    QLabel *descriptionLb;
    QLabel *orLb;
    QLabel *caLb;
    QLabel *valueLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QDateTimeEdit *dateEdit;
    QLabel *dateLb;
    QPushButton *dAccBtn;
    QLineEdit *caNumberEdit;
    QLabel *caNamePh;
    QPushButton *cSubAccBtn;
    QPushButton *cAccBtn;
    QLineEdit *caIDEdit;
    QLineEdit *daIDEdit;
    QPushButton *dSubAccBtn;
    QLabel *caNameLb;
    QLineEdit *daNumberEdit;
    QLabel *daLb;
    QLabel *daNamePh;
    QTextEdit *descriptionTextEdit;

    void setupUi(QDialog *CreateEntry)
    {
        if (CreateEntry->objectName().isEmpty())
            CreateEntry->setObjectName(QStringLiteral("CreateEntry"));
        CreateEntry->resize(660, 380);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateEntry->sizePolicy().hasHeightForWidth());
        CreateEntry->setSizePolicy(sizePolicy);
        CreateEntry->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateEntry->setModal(false);
        gridLayout = new QGridLayout(CreateEntry);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        valueEdit = new QLineEdit(CreateEntry);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));
        valueEdit->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(valueEdit, 5, 1, 1, 2);

        orLb_2 = new QLabel(CreateEntry);
        orLb_2->setObjectName(QStringLiteral("orLb_2"));
        orLb_2->setMinimumSize(QSize(40, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        orLb_2->setFont(font);
        orLb_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(orLb_2, 6, 2, 1, 1);

        daNameLb = new QLabel(CreateEntry);
        daNameLb->setObjectName(QStringLiteral("daNameLb"));

        gridLayout->addWidget(daNameLb, 3, 0, 1, 1);

        descriptionLb = new QLabel(CreateEntry);
        descriptionLb->setObjectName(QStringLiteral("descriptionLb"));

        gridLayout->addWidget(descriptionLb, 11, 0, 1, 1);

        orLb = new QLabel(CreateEntry);
        orLb->setObjectName(QStringLiteral("orLb"));
        orLb->setMinimumSize(QSize(40, 0));
        orLb->setFont(font);
        orLb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(orLb, 1, 2, 1, 1);

        caLb = new QLabel(CreateEntry);
        caLb->setObjectName(QStringLiteral("caLb"));

        gridLayout->addWidget(caLb, 6, 3, 1, 1);

        valueLb = new QLabel(CreateEntry);
        valueLb->setObjectName(QStringLiteral("valueLb"));
        valueLb->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(valueLb, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateEntry);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateEntry);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 13, 0, 1, 5);

        dateEdit = new QDateTimeEdit(CreateEntry);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 0, 1, 1, 2);

        dateLb = new QLabel(CreateEntry);
        dateLb->setObjectName(QStringLiteral("dateLb"));

        gridLayout->addWidget(dateLb, 0, 0, 1, 1);

        dAccBtn = new QPushButton(CreateEntry);
        dAccBtn->setObjectName(QStringLiteral("dAccBtn"));

        gridLayout->addWidget(dAccBtn, 1, 0, 1, 1);

        caNumberEdit = new QLineEdit(CreateEntry);
        caNumberEdit->setObjectName(QStringLiteral("caNumberEdit"));
        caNumberEdit->setMinimumSize(QSize(150, 0));
        caNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(caNumberEdit, 6, 4, 1, 1);

        caNamePh = new QLabel(CreateEntry);
        caNamePh->setObjectName(QStringLiteral("caNamePh"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(caNamePh->sizePolicy().hasHeightForWidth());
        caNamePh->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        caNamePh->setFont(font1);
        caNamePh->setTextFormat(Qt::RichText);

        gridLayout->addWidget(caNamePh, 10, 0, 1, 5);

        cSubAccBtn = new QPushButton(CreateEntry);
        cSubAccBtn->setObjectName(QStringLiteral("cSubAccBtn"));

        gridLayout->addWidget(cSubAccBtn, 7, 0, 1, 1);

        cAccBtn = new QPushButton(CreateEntry);
        cAccBtn->setObjectName(QStringLiteral("cAccBtn"));

        gridLayout->addWidget(cAccBtn, 6, 0, 1, 1);

        caIDEdit = new QLineEdit(CreateEntry);
        caIDEdit->setObjectName(QStringLiteral("caIDEdit"));
        caIDEdit->setMaximumSize(QSize(120, 16777215));
        caIDEdit->setReadOnly(true);

        gridLayout->addWidget(caIDEdit, 6, 1, 1, 1);

        daIDEdit = new QLineEdit(CreateEntry);
        daIDEdit->setObjectName(QStringLiteral("daIDEdit"));
        daIDEdit->setMaximumSize(QSize(120, 16777215));
        daIDEdit->setReadOnly(true);

        gridLayout->addWidget(daIDEdit, 1, 1, 1, 1);

        dSubAccBtn = new QPushButton(CreateEntry);
        dSubAccBtn->setObjectName(QStringLiteral("dSubAccBtn"));

        gridLayout->addWidget(dSubAccBtn, 2, 0, 1, 1);

        caNameLb = new QLabel(CreateEntry);
        caNameLb->setObjectName(QStringLiteral("caNameLb"));

        gridLayout->addWidget(caNameLb, 8, 0, 1, 1);

        daNumberEdit = new QLineEdit(CreateEntry);
        daNumberEdit->setObjectName(QStringLiteral("daNumberEdit"));
        daNumberEdit->setMinimumSize(QSize(150, 0));
        daNumberEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(daNumberEdit, 1, 4, 1, 1);

        daLb = new QLabel(CreateEntry);
        daLb->setObjectName(QStringLiteral("daLb"));

        gridLayout->addWidget(daLb, 1, 3, 1, 1);

        daNamePh = new QLabel(CreateEntry);
        daNamePh->setObjectName(QStringLiteral("daNamePh"));
        sizePolicy1.setHeightForWidth(daNamePh->sizePolicy().hasHeightForWidth());
        daNamePh->setSizePolicy(sizePolicy1);
        daNamePh->setFont(font1);
        daNamePh->setTextFormat(Qt::RichText);
        daNamePh->setScaledContents(true);

        gridLayout->addWidget(daNamePh, 4, 0, 1, 5);

        descriptionTextEdit = new QTextEdit(CreateEntry);
        descriptionTextEdit->setObjectName(QStringLiteral("descriptionTextEdit"));
        descriptionTextEdit->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(descriptionTextEdit, 12, 0, 1, 5);

        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateEntry);

        QMetaObject::connectSlotsByName(CreateEntry);
    } // setupUi

    void retranslateUi(QDialog *CreateEntry)
    {
        CreateEntry->setWindowTitle(QApplication::translate("CreateEntry", "Create account for  selected company, currency and type", 0));
        orLb_2->setText(QApplication::translate("CreateEntry", "OR", 0));
        daNameLb->setText(QApplication::translate("CreateEntry", "Debiting account name:", 0));
        descriptionLb->setText(QApplication::translate("CreateEntry", "Description:", 0));
        orLb->setText(QApplication::translate("CreateEntry", "OR", 0));
        caLb->setText(QApplication::translate("CreateEntry", "Enter crediting account number:", 0));
        valueLb->setText(QApplication::translate("CreateEntry", "Value:", 0));
        okBtn->setText(QApplication::translate("CreateEntry", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateEntry", "Cancel", 0));
        dateLb->setText(QApplication::translate("CreateEntry", "Date:", 0));
        dAccBtn->setText(QApplication::translate("CreateEntry", "Select debiting account", 0));
        caNumberEdit->setText(QString());
        caNamePh->setText(QString());
        cSubAccBtn->setText(QApplication::translate("CreateEntry", "Select crediting subaccount", 0));
        cAccBtn->setText(QApplication::translate("CreateEntry", "Select crediting account", 0));
        dSubAccBtn->setText(QApplication::translate("CreateEntry", "Select debiting subaccount", 0));
        caNameLb->setText(QApplication::translate("CreateEntry", "Crediting account name:", 0));
        daNumberEdit->setText(QString());
        daLb->setText(QApplication::translate("CreateEntry", "Enter debiting account number:", 0));
        daNamePh->setText(QString());
        descriptionTextEdit->setHtml(QApplication::translate("CreateEntry", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateEntry: public Ui_CreateEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEETRDLG_H
