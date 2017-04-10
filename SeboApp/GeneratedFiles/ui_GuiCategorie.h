/********************************************************************************
** Form generated from reading UI file 'GuiCategorie.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUICATEGORIE_H
#define UI_GUICATEGORIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiCategorie
{
public:

    void setupUi(QWidget *GuiCategorie)
    {
        if (GuiCategorie->objectName().isEmpty())
            GuiCategorie->setObjectName(QStringLiteral("GuiCategorie"));
        GuiCategorie->resize(400, 300);

        retranslateUi(GuiCategorie);

        QMetaObject::connectSlotsByName(GuiCategorie);
    } // setupUi

    void retranslateUi(QWidget *GuiCategorie)
    {
        GuiCategorie->setWindowTitle(QApplication::translate("GuiCategorie", "GuiCategorie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiCategorie: public Ui_GuiCategorie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUICATEGORIE_H
