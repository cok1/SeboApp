/********************************************************************************
** Form generated from reading UI file 'GuiGestionActeur.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONACTEUR_H
#define UI_GUIGESTIONACTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGestionActeur
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitreGestionActeur;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblFiltrer;
    QComboBox *cbFiltreRole;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnToutAfficher;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QTableView *tvActeur;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;

    void setupUi(QWidget *GuiGestionActeur)
    {
        if (GuiGestionActeur->objectName().isEmpty())
            GuiGestionActeur->setObjectName(QStringLiteral("GuiGestionActeur"));
        GuiGestionActeur->resize(430, 320);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiGestionActeur->setFont(font);
        verticalLayout = new QVBoxLayout(GuiGestionActeur);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblTitreGestionActeur = new QLabel(GuiGestionActeur);
        lblTitreGestionActeur->setObjectName(QStringLiteral("lblTitreGestionActeur"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblTitreGestionActeur->setFont(font1);
        lblTitreGestionActeur->setAlignment(Qt::AlignCenter);
        lblTitreGestionActeur->setMargin(10);

        verticalLayout->addWidget(lblTitreGestionActeur);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lblFiltrer = new QLabel(GuiGestionActeur);
        lblFiltrer->setObjectName(QStringLiteral("lblFiltrer"));

        horizontalLayout_2->addWidget(lblFiltrer);

        cbFiltreRole = new QComboBox(GuiGestionActeur);
        cbFiltreRole->setObjectName(QStringLiteral("cbFiltreRole"));

        horizontalLayout_2->addWidget(cbFiltreRole);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnToutAfficher = new QPushButton(GuiGestionActeur);
        btnToutAfficher->setObjectName(QStringLiteral("btnToutAfficher"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/toutAfficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToutAfficher->setIcon(icon);

        horizontalLayout_2->addWidget(btnToutAfficher);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvActeur = new QTableView(GuiGestionActeur);
        tvActeur->setObjectName(QStringLiteral("tvActeur"));
        tvActeur->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvActeur->setAlternatingRowColors(true);
        tvActeur->setSelectionMode(QAbstractItemView::SingleSelection);
        tvActeur->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvActeur->setSortingEnabled(true);
        tvActeur->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tvActeur);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnAjouter = new QPushButton(GuiGestionActeur);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouter->setIcon(icon1);

        verticalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(GuiGestionActeur);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon2);

        verticalLayout_2->addWidget(btnModifier);

        btnSupprimer = new QPushButton(GuiGestionActeur);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon3);

        verticalLayout_2->addWidget(btnSupprimer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiGestionActeur);

        QMetaObject::connectSlotsByName(GuiGestionActeur);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionActeur)
    {
        GuiGestionActeur->setWindowTitle(QApplication::translate("GuiGestionActeur", "Gestion des acteurs", Q_NULLPTR));
        lblTitreGestionActeur->setText(QApplication::translate("GuiGestionActeur", "Liste des acteurs :", Q_NULLPTR));
        lblFiltrer->setText(QApplication::translate("GuiGestionActeur", "Filtrer par r\303\264le :", Q_NULLPTR));
        btnToutAfficher->setText(QApplication::translate("GuiGestionActeur", "Tout Afficher", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("GuiGestionActeur", "Ajouter", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("GuiGestionActeur", "Modifier", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("GuiGestionActeur", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionActeur: public Ui_GuiGestionActeur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONACTEUR_H
