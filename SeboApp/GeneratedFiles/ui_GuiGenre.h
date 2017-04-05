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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGenre
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QTableView *view;
    QTableView *view2;

    void setupUi(QWidget *GuiGenre)
    {
        if (GuiGenre->objectName().isEmpty())
            GuiGenre->setObjectName(QStringLiteral("GuiGenre"));
        GuiGenre->resize(630, 300);
        verticalLayout = new QVBoxLayout(GuiGenre);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(GuiGenre);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        view = new QTableView(GuiGenre);
        view->setObjectName(QStringLiteral("view"));

        horizontalLayout->addWidget(view);

        view2 = new QTableView(GuiGenre);
        view2->setObjectName(QStringLiteral("view2"));

        horizontalLayout->addWidget(view2);


        verticalLayout->addLayout(horizontalLayout);


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
