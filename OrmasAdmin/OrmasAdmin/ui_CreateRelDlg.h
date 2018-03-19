/********************************************************************************
** Form generated from reading UI file 'CreateRelDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERELDLG_H
#define UI_CREATERELDLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CreateRelation
{
public:
    QGridLayout *gridLayout;
    QLabel *user1SurnameLb;
    QLabel *user1PhoneLb;
    QLabel *user1NameLb;
    QLabel *user1SurnamePh;
    QLabel *user1PhonePh;
    QPushButton *user2Btn;
    QLabel *user1NamePh;
    QPushButton *user1Btn;
    QLabel *user2NameLb;
    QLabel *user2NamePh;
    QLabel *user2SurnameLb;
    QLabel *user2SurnamePh;
    QLabel *user2PhoneLb;
    QLabel *user2PhonePh;
    QLabel *relTypeLb;
    QComboBox *relTypeCmb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *user1Edit;
    QLineEdit *user2Edit;

    void setupUi(QDialog *CreateRelation)
    {
        if (CreateRelation->objectName().isEmpty())
            CreateRelation->setObjectName(QStringLiteral("CreateRelation"));
        CreateRelation->resize(589, 211);
        CreateRelation->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        CreateRelation->setModal(false);
        gridLayout = new QGridLayout(CreateRelation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        user1SurnameLb = new QLabel(CreateRelation);
        user1SurnameLb->setObjectName(QStringLiteral("user1SurnameLb"));
        user1SurnameLb->setMinimumSize(QSize(70, 0));
        user1SurnameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(user1SurnameLb, 2, 2, 1, 1);

        user1PhoneLb = new QLabel(CreateRelation);
        user1PhoneLb->setObjectName(QStringLiteral("user1PhoneLb"));
        user1PhoneLb->setMinimumSize(QSize(70, 0));
        user1PhoneLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(user1PhoneLb, 2, 4, 1, 1);

        user1NameLb = new QLabel(CreateRelation);
        user1NameLb->setObjectName(QStringLiteral("user1NameLb"));
        user1NameLb->setMinimumSize(QSize(70, 0));
        user1NameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(user1NameLb, 2, 0, 1, 1);

        user1SurnamePh = new QLabel(CreateRelation);
        user1SurnamePh->setObjectName(QStringLiteral("user1SurnamePh"));
        user1SurnamePh->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        user1SurnamePh->setFont(font);

        gridLayout->addWidget(user1SurnamePh, 2, 3, 1, 1);

        user1PhonePh = new QLabel(CreateRelation);
        user1PhonePh->setObjectName(QStringLiteral("user1PhonePh"));
        user1PhonePh->setMinimumSize(QSize(100, 0));
        user1PhonePh->setFont(font);

        gridLayout->addWidget(user1PhonePh, 2, 5, 1, 1);

        user2Btn = new QPushButton(CreateRelation);
        user2Btn->setObjectName(QStringLiteral("user2Btn"));
        user2Btn->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(user2Btn, 5, 0, 1, 3);

        user1NamePh = new QLabel(CreateRelation);
        user1NamePh->setObjectName(QStringLiteral("user1NamePh"));
        user1NamePh->setMinimumSize(QSize(100, 0));
        user1NamePh->setFont(font);

        gridLayout->addWidget(user1NamePh, 2, 1, 1, 1);

        user1Btn = new QPushButton(CreateRelation);
        user1Btn->setObjectName(QStringLiteral("user1Btn"));
        user1Btn->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(user1Btn, 1, 0, 1, 3);

        user2NameLb = new QLabel(CreateRelation);
        user2NameLb->setObjectName(QStringLiteral("user2NameLb"));
        user2NameLb->setMinimumSize(QSize(70, 0));
        user2NameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(user2NameLb, 6, 0, 1, 1);

        user2NamePh = new QLabel(CreateRelation);
        user2NamePh->setObjectName(QStringLiteral("user2NamePh"));
        user2NamePh->setFont(font);

        gridLayout->addWidget(user2NamePh, 6, 1, 1, 1);

        user2SurnameLb = new QLabel(CreateRelation);
        user2SurnameLb->setObjectName(QStringLiteral("user2SurnameLb"));
        user2SurnameLb->setMinimumSize(QSize(70, 0));
        user2SurnameLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(user2SurnameLb, 6, 2, 1, 1);

        user2SurnamePh = new QLabel(CreateRelation);
        user2SurnamePh->setObjectName(QStringLiteral("user2SurnamePh"));
        user2SurnamePh->setFont(font);

        gridLayout->addWidget(user2SurnamePh, 6, 3, 1, 1);

        user2PhoneLb = new QLabel(CreateRelation);
        user2PhoneLb->setObjectName(QStringLiteral("user2PhoneLb"));
        user2PhoneLb->setMinimumSize(QSize(70, 0));
        user2PhoneLb->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(user2PhoneLb, 6, 4, 1, 1);

        user2PhonePh = new QLabel(CreateRelation);
        user2PhonePh->setObjectName(QStringLiteral("user2PhonePh"));
        user2PhonePh->setFont(font);

        gridLayout->addWidget(user2PhonePh, 6, 5, 1, 1);

        relTypeLb = new QLabel(CreateRelation);
        relTypeLb->setObjectName(QStringLiteral("relTypeLb"));

        gridLayout->addWidget(relTypeLb, 3, 0, 1, 1);

        relTypeCmb = new QComboBox(CreateRelation);
        relTypeCmb->setObjectName(QStringLiteral("relTypeCmb"));

        gridLayout->addWidget(relTypeCmb, 3, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QPushButton(CreateRelation);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QPushButton(CreateRelation);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 6);

        user1Edit = new QLineEdit(CreateRelation);
        user1Edit->setObjectName(QStringLiteral("user1Edit"));
        user1Edit->setMaximumSize(QSize(100, 16777215));
        user1Edit->setReadOnly(true);
        user1Edit->setClearButtonEnabled(false);

        gridLayout->addWidget(user1Edit, 1, 3, 1, 2);

        user2Edit = new QLineEdit(CreateRelation);
        user2Edit->setObjectName(QStringLiteral("user2Edit"));
        user2Edit->setMaximumSize(QSize(100, 16777215));
        user2Edit->setReadOnly(true);

        gridLayout->addWidget(user2Edit, 5, 3, 1, 1);

        QWidget::setTabOrder(user1Btn, user1Edit);
        QWidget::setTabOrder(user1Edit, relTypeCmb);
        QWidget::setTabOrder(relTypeCmb, user2Btn);
        QWidget::setTabOrder(user2Btn, user2Edit);
        QWidget::setTabOrder(user2Edit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(CreateRelation);

        QMetaObject::connectSlotsByName(CreateRelation);
    } // setupUi

    void retranslateUi(QDialog *CreateRelation)
    {
        CreateRelation->setWindowTitle(QApplication::translate("CreateRelation", "Create/Update relation", 0));
        user1SurnameLb->setText(QApplication::translate("CreateRelation", "Surname:", 0));
        user1PhoneLb->setText(QApplication::translate("CreateRelation", "Phone:", 0));
        user1NameLb->setText(QApplication::translate("CreateRelation", "Name:", 0));
        user1SurnamePh->setText(QString());
        user1PhonePh->setText(QString());
        user2Btn->setText(QApplication::translate("CreateRelation", "Select second user", 0));
        user1NamePh->setText(QString());
        user1Btn->setText(QApplication::translate("CreateRelation", "Select first user", 0));
        user2NameLb->setText(QApplication::translate("CreateRelation", "Name:", 0));
        user2NamePh->setText(QString());
        user2SurnameLb->setText(QApplication::translate("CreateRelation", "Surname:", 0));
        user2SurnamePh->setText(QString());
        user2PhoneLb->setText(QApplication::translate("CreateRelation", "Phone:", 0));
        user2PhonePh->setText(QString());
        relTypeLb->setText(QApplication::translate("CreateRelation", "Select relation type:", 0));
        okBtn->setText(QApplication::translate("CreateRelation", "OK", 0));
        cancelBtn->setText(QApplication::translate("CreateRelation", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateRelation: public Ui_CreateRelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERELDLG_H
