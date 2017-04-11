/********************************************************************************
** Form generated from reading UI file 'GuiGestionCategorie.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONCATEGORIE_H
#define UI_GUIGESTIONCATEGORIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGestionCategorie
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitre;
    QHBoxLayout *horizontalLayout;
    QTableView *tvCategories;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;

    void setupUi(QWidget *GuiGestionCategorie)
    {
        if (GuiGestionCategorie->objectName().isEmpty())
            GuiGestionCategorie->setObjectName(QStringLiteral("GuiGestionCategorie"));
        GuiGestionCategorie->resize(321, 317);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiGestionCategorie->setFont(font);
        verticalLayout = new QVBoxLayout(GuiGestionCategorie);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblTitre = new QLabel(GuiGestionCategorie);
        lblTitre->setObjectName(QStringLiteral("lblTitre"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblTitre->setFont(font1);
        lblTitre->setAlignment(Qt::AlignCenter);
        lblTitre->setMargin(10);

        verticalLayout->addWidget(lblTitre);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvCategories = new QTableView(GuiGestionCategorie);
        tvCategories->setObjectName(QStringLiteral("tvCategories"));

        horizontalLayout->addWidget(tvCategories);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnAjouter = new QPushButton(GuiGestionCategorie);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouter->setIcon(icon);

        verticalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(GuiGestionCategorie);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon1);

        verticalLayout_2->addWidget(btnModifier);

        btnSupprimer = new QPushButton(GuiGestionCategorie);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon2);

        verticalLayout_2->addWidget(btnSupprimer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiGestionCategorie);

        QMetaObject::connectSlotsByName(GuiGestionCategorie);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionCategorie)
    {
        GuiGestionCategorie->setWindowTitle(QApplication::translate("GuiGestionCategorie", "Gestion des cat\303\251gories", Q_NULLPTR));
        lblTitre->setText(QApplication::translate("GuiGestionCategorie", "Liste des cat\303\251gories :", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("GuiGestionCategorie", "Ajouter", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("GuiGestionCategorie", "Modifier", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("GuiGestionCategorie", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionCategorie: public Ui_GuiGestionCategorie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONCATEGORIE_H
