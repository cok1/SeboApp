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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiCategorie
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblTauxTva;
    QDoubleSpinBox *spTauxTva;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnMajAffichage;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnValider;
    QLabel *lblTitreListeCategorie;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tvCategorie;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *GuiCategorie)
    {
        if (GuiCategorie->objectName().isEmpty())
            GuiCategorie->setObjectName(QStringLiteral("GuiCategorie"));
        GuiCategorie->resize(324, 416);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiCategorie->setFont(font);
        verticalLayout = new QVBoxLayout(GuiCategorie);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblLibelle = new QLabel(GuiCategorie);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));

        horizontalLayout_2->addWidget(lblLibelle);

        leSaisieLibelle = new QLineEdit(GuiCategorie);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        horizontalLayout_2->addWidget(leSaisieLibelle);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblTauxTva = new QLabel(GuiCategorie);
        lblTauxTva->setObjectName(QStringLiteral("lblTauxTva"));

        horizontalLayout_3->addWidget(lblTauxTva);

        spTauxTva = new QDoubleSpinBox(GuiCategorie);
        spTauxTva->setObjectName(QStringLiteral("spTauxTva"));

        horizontalLayout_3->addWidget(spTauxTva);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnMajAffichage = new QPushButton(GuiCategorie);
        btnMajAffichage->setObjectName(QStringLiteral("btnMajAffichage"));

        horizontalLayout_4->addWidget(btnMajAffichage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnValider = new QPushButton(GuiCategorie);
        btnValider->setObjectName(QStringLiteral("btnValider"));

        horizontalLayout_4->addWidget(btnValider);


        verticalLayout->addLayout(horizontalLayout_4);

        lblTitreListeCategorie = new QLabel(GuiCategorie);
        lblTitreListeCategorie->setObjectName(QStringLiteral("lblTitreListeCategorie"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblTitreListeCategorie->setFont(font1);
        lblTitreListeCategorie->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTitreListeCategorie);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        tvCategorie = new QTableView(GuiCategorie);
        tvCategorie->setObjectName(QStringLiteral("tvCategorie"));
        tvCategorie->setFrameShape(QFrame::StyledPanel);
        tvCategorie->setSelectionMode(QAbstractItemView::SingleSelection);
        tvCategorie->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvCategorie->setTextElideMode(Qt::ElideMiddle);

        horizontalLayout->addWidget(tvCategorie);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiCategorie);

        QMetaObject::connectSlotsByName(GuiCategorie);
    } // setupUi

    void retranslateUi(QWidget *GuiCategorie)
    {
        GuiCategorie->setWindowTitle(QApplication::translate("GuiCategorie", "GuiCategorie", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiCategorie", "Libell\303\251 de la cat\303\251gorie :", Q_NULLPTR));
        lblTauxTva->setText(QApplication::translate("GuiCategorie", "Taux de tva :", Q_NULLPTR));
        btnMajAffichage->setText(QApplication::translate("GuiCategorie", "Refresh", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiCategorie", "Valider", Q_NULLPTR));
        lblTitreListeCategorie->setText(QApplication::translate("GuiCategorie", "Liste des cat\303\251gories :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiCategorie: public Ui_GuiCategorie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUICATEGORIE_H
