/********************************************************************************
** Form generated from reading UI file 'SeboApp.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEBOAPP_H
#define UI_SEBOAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeboAppClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SeboAppClass)
    {
        if (SeboAppClass->objectName().isEmpty())
            SeboAppClass->setObjectName(QStringLiteral("SeboAppClass"));
        SeboAppClass->resize(600, 400);
        centralWidget = new QWidget(SeboAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SeboAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SeboAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        SeboAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SeboAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SeboAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SeboAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SeboAppClass->setStatusBar(statusBar);

        retranslateUi(SeboAppClass);

        QMetaObject::connectSlotsByName(SeboAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *SeboAppClass)
    {
        SeboAppClass->setWindowTitle(QApplication::translate("SeboAppClass", "SeboApp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SeboAppClass: public Ui_SeboAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEBOAPP_H
