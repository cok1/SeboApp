/********************************************************************************
** Form generated from reading UI file 'GuiGestionRole.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONROLE_H
#define UI_GUIGESTIONROLE_H

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

class Ui_GuiGestionRole
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbltitre;
    QHBoxLayout *horizontalLayout;
    QTableView *tvRoles;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;

    void setupUi(QWidget *GuiGestionRole)
    {
        if (GuiGestionRole->objectName().isEmpty())
            GuiGestionRole->setObjectName(QStringLiteral("GuiGestionRole"));
        GuiGestionRole->resize(313, 300);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiGestionRole->setFont(font);
        verticalLayout = new QVBoxLayout(GuiGestionRole);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbltitre = new QLabel(GuiGestionRole);
        lbltitre->setObjectName(QStringLiteral("lbltitre"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lbltitre->setFont(font1);
        lbltitre->setAlignment(Qt::AlignCenter);
        lbltitre->setMargin(10);

        verticalLayout->addWidget(lbltitre);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvRoles = new QTableView(GuiGestionRole);
        tvRoles->setObjectName(QStringLiteral("tvRoles"));
        tvRoles->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvRoles->setAlternatingRowColors(true);
        tvRoles->setSelectionMode(QAbstractItemView::SingleSelection);
        tvRoles->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvRoles->setSortingEnabled(true);
        tvRoles->horizontalHeader()->setStretchLastSection(true);
        tvRoles->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tvRoles);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnAjouter = new QPushButton(GuiGestionRole);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouter->setIcon(icon);

        verticalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(GuiGestionRole);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon1);

        verticalLayout_2->addWidget(btnModifier);

        btnSupprimer = new QPushButton(GuiGestionRole);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon2);

        verticalLayout_2->addWidget(btnSupprimer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiGestionRole);

        QMetaObject::connectSlotsByName(GuiGestionRole);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionRole)
    {
        GuiGestionRole->setWindowTitle(QApplication::translate("GuiGestionRole", "Gestion des r\303\264les", Q_NULLPTR));
        lbltitre->setText(QApplication::translate("GuiGestionRole", "Liste des r\303\264les :", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("GuiGestionRole", "Ajouter", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("GuiGestionRole", "Modifier", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("GuiGestionRole", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionRole: public Ui_GuiGestionRole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONROLE_H
