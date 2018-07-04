/********************************************************************************
** Form generated from reading UI file 'DocForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCFORM_H
#define UI_DOCFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveBtn;
    QPushButton *closeBtn;
    QWebEngineView *webEngineView;

    void setupUi(QWidget *DocumentForm)
    {
        if (DocumentForm->objectName().isEmpty())
            DocumentForm->setObjectName(QStringLiteral("DocumentForm"));
        DocumentForm->resize(1000, 599);
        DocumentForm->setMinimumSize(QSize(800, 500));
        DocumentForm->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(DocumentForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(12, 12, 12, 12);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveBtn = new QPushButton(DocumentForm);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));

        horizontalLayout->addWidget(saveBtn);

        closeBtn = new QPushButton(DocumentForm);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(75, 0));

        horizontalLayout->addWidget(closeBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        webEngineView = new QWebEngineView(DocumentForm);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webEngineView, 0, 0, 1, 1);


        retranslateUi(DocumentForm);

        QMetaObject::connectSlotsByName(DocumentForm);
    } // setupUi

    void retranslateUi(QWidget *DocumentForm)
    {
        DocumentForm->setWindowTitle(QApplication::translate("DocumentForm", "Document", 0));
        saveBtn->setText(QApplication::translate("DocumentForm", "Save", 0));
        closeBtn->setText(QApplication::translate("DocumentForm", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class DocumentForm: public Ui_DocumentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCFORM_H
