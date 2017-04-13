/********************************************************************************
** Form generated from reading UI file 'GuiTest.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUITEST_H
#define UI_GUITEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiTest
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tvActeurArticle;

    void setupUi(QWidget *GuiTest)
    {
        if (GuiTest->objectName().isEmpty())
            GuiTest->setObjectName(QStringLiteral("GuiTest"));
        GuiTest->resize(400, 300);
        horizontalLayout = new QHBoxLayout(GuiTest);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvActeurArticle = new QTableView(GuiTest);
        tvActeurArticle->setObjectName(QStringLiteral("tvActeurArticle"));

        horizontalLayout->addWidget(tvActeurArticle);


        retranslateUi(GuiTest);

        QMetaObject::connectSlotsByName(GuiTest);
    } // setupUi

    void retranslateUi(QWidget *GuiTest)
    {
        GuiTest->setWindowTitle(QApplication::translate("GuiTest", "GuiTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiTest: public Ui_GuiTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUITEST_H
