/********************************************************************************
** Form generated from reading UI file 'GuiGenre.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGENRE_H
#define UI_GUIGENRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGenre
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *view;

    void setupUi(QWidget *GuiGenre)
    {
        if (GuiGenre->objectName().isEmpty())
            GuiGenre->setObjectName(QStringLiteral("GuiGenre"));
        GuiGenre->resize(400, 300);
        horizontalLayout = new QHBoxLayout(GuiGenre);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        view = new QTableView(GuiGenre);
        view->setObjectName(QStringLiteral("view"));

        horizontalLayout->addWidget(view);


        retranslateUi(GuiGenre);

        QMetaObject::connectSlotsByName(GuiGenre);
    } // setupUi

    void retranslateUi(QWidget *GuiGenre)
    {
        GuiGenre->setWindowTitle(QApplication::translate("GuiGenre", "GuiGenre", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGenre: public Ui_GuiGenre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGENRE_H
