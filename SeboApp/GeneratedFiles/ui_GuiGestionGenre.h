/********************************************************************************
** Form generated from reading UI file 'GuiGestionGenre.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONGENRE_H
#define UI_GUIGESTIONGENRE_H

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

class Ui_GuiGestionGenre
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitreGenre;
    QHBoxLayout *horizontalLayout;
    QTableView *tvGenre;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;

    void setupUi(QWidget *GuiGestionGenre)
    {
        if (GuiGestionGenre->objectName().isEmpty())
            GuiGestionGenre->setObjectName(QStringLiteral("GuiGestionGenre"));
        GuiGestionGenre->resize(430, 320);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiGestionGenre->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuiGestionGenre->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(GuiGestionGenre);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblTitreGenre = new QLabel(GuiGestionGenre);
        lblTitreGenre->setObjectName(QStringLiteral("lblTitreGenre"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblTitreGenre->setFont(font1);
        lblTitreGenre->setAlignment(Qt::AlignCenter);
        lblTitreGenre->setMargin(10);

        verticalLayout->addWidget(lblTitreGenre);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvGenre = new QTableView(GuiGestionGenre);
        tvGenre->setObjectName(QStringLiteral("tvGenre"));

        horizontalLayout->addWidget(tvGenre);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnAjouter = new QPushButton(GuiGestionGenre);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouter->setIcon(icon1);

        verticalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(GuiGestionGenre);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon2);

        verticalLayout_2->addWidget(btnModifier);

        btnSupprimer = new QPushButton(GuiGestionGenre);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon3);

        verticalLayout_2->addWidget(btnSupprimer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiGestionGenre);

        QMetaObject::connectSlotsByName(GuiGestionGenre);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionGenre)
    {
        GuiGestionGenre->setWindowTitle(QApplication::translate("GuiGestionGenre", "Gestion des genres", Q_NULLPTR));
        lblTitreGenre->setText(QApplication::translate("GuiGestionGenre", "Liste des genres :", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("GuiGestionGenre", "Ajouter", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("GuiGestionGenre", "Modifier", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("GuiGestionGenre", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionGenre: public Ui_GuiGestionGenre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONGENRE_H
