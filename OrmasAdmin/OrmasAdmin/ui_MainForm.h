/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShowAllUser;
    QAction *actionCreateUser;
    QAction *actionRights;
    QAction *actionDeleteUser;
    QAction *actionProductsType;
    QAction *actionProducts;
    QAction *actionShowAllOrders;
    QAction *actionProductsList;
    QAction *actionCreateOrder;
    QAction *actionDeleteOrder;
    QAction *actionShowAllReturns;
    QAction *actionCreateReturn;
    QAction *actionDeleteReturn;
    QAction *actionCompany;
    QAction *actionCurrency;
    QAction *actionMeasure;
    QAction *actionLocation;
    QAction *actionRoles;
    QAction *actionStatus;
    QAction *actionAbout;
    QAction *actionProduction;
    QWidget *centrWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuUsers;
    QMenu *menuProduct;
    QMenu *menuOrder;
    QMenu *menuReturns;
    QMenu *menuReference;
    QMenu *menuHelp;
    QMenu *menuProduction;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionShowAllUser = new QAction(MainWindow);
        actionShowAllUser->setObjectName(QStringLiteral("actionShowAllUser"));
        actionCreateUser = new QAction(MainWindow);
        actionCreateUser->setObjectName(QStringLiteral("actionCreateUser"));
        actionRights = new QAction(MainWindow);
        actionRights->setObjectName(QStringLiteral("actionRights"));
        actionDeleteUser = new QAction(MainWindow);
        actionDeleteUser->setObjectName(QStringLiteral("actionDeleteUser"));
        actionProductsType = new QAction(MainWindow);
        actionProductsType->setObjectName(QStringLiteral("actionProductsType"));
        actionProducts = new QAction(MainWindow);
        actionProducts->setObjectName(QStringLiteral("actionProducts"));
        actionShowAllOrders = new QAction(MainWindow);
        actionShowAllOrders->setObjectName(QStringLiteral("actionShowAllOrders"));
        actionProductsList = new QAction(MainWindow);
        actionProductsList->setObjectName(QStringLiteral("actionProductsList"));
        actionCreateOrder = new QAction(MainWindow);
        actionCreateOrder->setObjectName(QStringLiteral("actionCreateOrder"));
        actionDeleteOrder = new QAction(MainWindow);
        actionDeleteOrder->setObjectName(QStringLiteral("actionDeleteOrder"));
        actionShowAllReturns = new QAction(MainWindow);
        actionShowAllReturns->setObjectName(QStringLiteral("actionShowAllReturns"));
        actionCreateReturn = new QAction(MainWindow);
        actionCreateReturn->setObjectName(QStringLiteral("actionCreateReturn"));
        actionDeleteReturn = new QAction(MainWindow);
        actionDeleteReturn->setObjectName(QStringLiteral("actionDeleteReturn"));
        actionCompany = new QAction(MainWindow);
        actionCompany->setObjectName(QStringLiteral("actionCompany"));
        actionCurrency = new QAction(MainWindow);
        actionCurrency->setObjectName(QStringLiteral("actionCurrency"));
        actionMeasure = new QAction(MainWindow);
        actionMeasure->setObjectName(QStringLiteral("actionMeasure"));
        actionLocation = new QAction(MainWindow);
        actionLocation->setObjectName(QStringLiteral("actionLocation"));
        actionRoles = new QAction(MainWindow);
        actionRoles->setObjectName(QStringLiteral("actionRoles"));
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName(QStringLiteral("actionStatus"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionProduction = new QAction(MainWindow);
        actionProduction->setObjectName(QStringLiteral("actionProduction"));
        centrWidget = new QWidget(MainWindow);
        centrWidget->setObjectName(QStringLiteral("centrWidget"));
        gridLayout = new QGridLayout(centrWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centrWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centrWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuUsers = new QMenu(menuBar);
        menuUsers->setObjectName(QStringLiteral("menuUsers"));
        menuUsers->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        menuProduct = new QMenu(menuBar);
        menuProduct->setObjectName(QStringLiteral("menuProduct"));
        menuOrder = new QMenu(menuBar);
        menuOrder->setObjectName(QStringLiteral("menuOrder"));
        menuReturns = new QMenu(menuBar);
        menuReturns->setObjectName(QStringLiteral("menuReturns"));
        menuReference = new QMenu(menuBar);
        menuReference->setObjectName(QStringLiteral("menuReference"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuProduction = new QMenu(menuBar);
        menuProduction->setObjectName(QStringLiteral("menuProduction"));
        MainWindow->setMenuBar(menuBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menuBar->addAction(menuUsers->menuAction());
        menuBar->addAction(menuProduct->menuAction());
        menuBar->addAction(menuOrder->menuAction());
        menuBar->addAction(menuReturns->menuAction());
        menuBar->addAction(menuProduction->menuAction());
        menuBar->addAction(menuReference->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuUsers->addAction(actionShowAllUser);
        menuUsers->addAction(actionCreateUser);
        menuUsers->addAction(actionRights);
        menuUsers->addAction(actionDeleteUser);
        menuProduct->addAction(actionProductsType);
        menuProduct->addAction(actionProducts);
        menuProduct->addAction(actionProductsList);
        menuOrder->addAction(actionShowAllOrders);
        menuOrder->addAction(actionCreateOrder);
        menuOrder->addAction(actionDeleteOrder);
        menuReturns->addAction(actionShowAllReturns);
        menuReturns->addAction(actionCreateReturn);
        menuReturns->addAction(actionDeleteReturn);
        menuReference->addAction(actionCompany);
        menuReference->addAction(actionCurrency);
        menuReference->addAction(actionMeasure);
        menuReference->addAction(actionLocation);
        menuReference->addAction(actionRoles);
        menuReference->addAction(actionStatus);
        menuHelp->addAction(actionAbout);
        menuProduction->addAction(actionProduction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ormas Admin Panel", 0));
        actionShowAllUser->setText(QApplication::translate("MainWindow", "Show all users", 0));
        actionCreateUser->setText(QApplication::translate("MainWindow", "Create user", 0));
        actionRights->setText(QApplication::translate("MainWindow", "Check rights", 0));
        actionDeleteUser->setText(QApplication::translate("MainWindow", "Delete user", 0));
        actionProductsType->setText(QApplication::translate("MainWindow", "Products type", 0));
        actionProducts->setText(QApplication::translate("MainWindow", "Products", 0));
        actionShowAllOrders->setText(QApplication::translate("MainWindow", "Show all orders", 0));
        actionProductsList->setText(QApplication::translate("MainWindow", "Products list", 0));
        actionCreateOrder->setText(QApplication::translate("MainWindow", "Create order", 0));
        actionDeleteOrder->setText(QApplication::translate("MainWindow", "Delete order", 0));
        actionShowAllReturns->setText(QApplication::translate("MainWindow", "Show all returns", 0));
        actionCreateReturn->setText(QApplication::translate("MainWindow", "Create return", 0));
        actionDeleteReturn->setText(QApplication::translate("MainWindow", "Delete return", 0));
        actionCompany->setText(QApplication::translate("MainWindow", "Company", 0));
        actionCurrency->setText(QApplication::translate("MainWindow", "Currency", 0));
        actionMeasure->setText(QApplication::translate("MainWindow", "Measure", 0));
        actionLocation->setText(QApplication::translate("MainWindow", "Location", 0));
        actionRoles->setText(QApplication::translate("MainWindow", "Roles", 0));
        actionStatus->setText(QApplication::translate("MainWindow", "Status", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionProduction->setText(QApplication::translate("MainWindow", "Show all products", 0));
        menuUsers->setTitle(QApplication::translate("MainWindow", "Users", 0));
        menuProduct->setTitle(QApplication::translate("MainWindow", "Products", 0));
        menuOrder->setTitle(QApplication::translate("MainWindow", "Orders", 0));
        menuReturns->setTitle(QApplication::translate("MainWindow", "Returns", 0));
        menuReference->setTitle(QApplication::translate("MainWindow", "Reference", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuProduction->setTitle(QApplication::translate("MainWindow", "Production", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
