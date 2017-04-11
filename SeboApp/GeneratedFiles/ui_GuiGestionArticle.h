/********************************************************************************
** Form generated from reading UI file 'GuiGestionArticle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONARTICLE_H
#define UI_GUIGESTIONARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGestionArticle
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitreArticle;
    QGroupBox *gbFiltrer;
    QHBoxLayout *horizontalLayout;
    QLabel *lblFiltreCategorie;
    QComboBox *cbFiltreCategorie;
    QLabel *lblFiltreGenre;
    QComboBox *cbFiltreGenre;
    QLabel *lblFiltreLibelle;
    QLineEdit *leFiltreLibelle;
    QPushButton *btnToutAfficher;
    QTableView *tvArticle;
    QGroupBox *gbDetailArticle;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblReference;
    QLineEdit *leReference;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QCheckBox *ckReapprovisionable;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblGenre;
    QComboBox *cbGenre;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lblCategorie;
    QComboBox *cbCategorie;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lblFournisseur;
    QComboBox *cbFournisseur;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lblPrixVente;
    QDoubleSpinBox *dspPrixVente;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lblPrixAchat;
    QDoubleSpinBox *dspPrixAchat;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gbDescription;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *teDescription;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *gbPhoto;
    QHBoxLayout *horizontalLayout_6;
    QGraphicsView *gvPhoto;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnAjouter;
    QPushButton *btnValider;
    QPushButton *btnModifier;
    QPushButton *btnAnnuler;
    QPushButton *btnSupprimer;

    void setupUi(QWidget *GuiGestionArticle)
    {
        if (GuiGestionArticle->objectName().isEmpty())
            GuiGestionArticle->setObjectName(QStringLiteral("GuiGestionArticle"));
        GuiGestionArticle->resize(971, 889);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiGestionArticle->setFont(font);
        verticalLayout = new QVBoxLayout(GuiGestionArticle);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblTitreArticle = new QLabel(GuiGestionArticle);
        lblTitreArticle->setObjectName(QStringLiteral("lblTitreArticle"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblTitreArticle->setFont(font1);
        lblTitreArticle->setAlignment(Qt::AlignCenter);
        lblTitreArticle->setMargin(10);

        verticalLayout->addWidget(lblTitreArticle);

        gbFiltrer = new QGroupBox(GuiGestionArticle);
        gbFiltrer->setObjectName(QStringLiteral("gbFiltrer"));
        gbFiltrer->setFlat(false);
        gbFiltrer->setCheckable(false);
        horizontalLayout = new QHBoxLayout(gbFiltrer);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblFiltreCategorie = new QLabel(gbFiltrer);
        lblFiltreCategorie->setObjectName(QStringLiteral("lblFiltreCategorie"));
        lblFiltreCategorie->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblFiltreCategorie);

        cbFiltreCategorie = new QComboBox(gbFiltrer);
        cbFiltreCategorie->setObjectName(QStringLiteral("cbFiltreCategorie"));

        horizontalLayout->addWidget(cbFiltreCategorie);

        lblFiltreGenre = new QLabel(gbFiltrer);
        lblFiltreGenre->setObjectName(QStringLiteral("lblFiltreGenre"));
        lblFiltreGenre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblFiltreGenre);

        cbFiltreGenre = new QComboBox(gbFiltrer);
        cbFiltreGenre->setObjectName(QStringLiteral("cbFiltreGenre"));

        horizontalLayout->addWidget(cbFiltreGenre);

        lblFiltreLibelle = new QLabel(gbFiltrer);
        lblFiltreLibelle->setObjectName(QStringLiteral("lblFiltreLibelle"));
        lblFiltreLibelle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblFiltreLibelle);

        leFiltreLibelle = new QLineEdit(gbFiltrer);
        leFiltreLibelle->setObjectName(QStringLiteral("leFiltreLibelle"));

        horizontalLayout->addWidget(leFiltreLibelle);

        btnToutAfficher = new QPushButton(gbFiltrer);
        btnToutAfficher->setObjectName(QStringLiteral("btnToutAfficher"));
        btnToutAfficher->setCheckable(true);
        btnToutAfficher->setChecked(false);

        horizontalLayout->addWidget(btnToutAfficher);


        verticalLayout->addWidget(gbFiltrer);

        tvArticle = new QTableView(GuiGestionArticle);
        tvArticle->setObjectName(QStringLiteral("tvArticle"));
        tvArticle->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvArticle->setAlternatingRowColors(true);
        tvArticle->setSelectionMode(QAbstractItemView::SingleSelection);
        tvArticle->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvArticle->setSortingEnabled(true);
        tvArticle->horizontalHeader()->setStretchLastSection(true);
        tvArticle->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvArticle);

        gbDetailArticle = new QGroupBox(GuiGestionArticle);
        gbDetailArticle->setObjectName(QStringLiteral("gbDetailArticle"));
        verticalLayout_3 = new QVBoxLayout(gbDetailArticle);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblReference = new QLabel(gbDetailArticle);
        lblReference->setObjectName(QStringLiteral("lblReference"));
        lblReference->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblReference);

        leReference = new QLineEdit(gbDetailArticle);
        leReference->setObjectName(QStringLiteral("leReference"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leReference->sizePolicy().hasHeightForWidth());
        leReference->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(leReference);

        lblLibelle = new QLabel(gbDetailArticle);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));
        lblLibelle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblLibelle);

        leSaisieLibelle = new QLineEdit(gbDetailArticle);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        horizontalLayout_2->addWidget(leSaisieLibelle);

        ckReapprovisionable = new QCheckBox(gbDetailArticle);
        ckReapprovisionable->setObjectName(QStringLiteral("ckReapprovisionable"));

        horizontalLayout_2->addWidget(ckReapprovisionable);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblGenre = new QLabel(gbDetailArticle);
        lblGenre->setObjectName(QStringLiteral("lblGenre"));
        lblGenre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblGenre);

        cbGenre = new QComboBox(gbDetailArticle);
        cbGenre->setObjectName(QStringLiteral("cbGenre"));

        horizontalLayout_4->addWidget(cbGenre);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        lblCategorie = new QLabel(gbDetailArticle);
        lblCategorie->setObjectName(QStringLiteral("lblCategorie"));
        lblCategorie->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblCategorie);

        cbCategorie = new QComboBox(gbDetailArticle);
        cbCategorie->setObjectName(QStringLiteral("cbCategorie"));

        horizontalLayout_4->addWidget(cbCategorie);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        lblFournisseur = new QLabel(gbDetailArticle);
        lblFournisseur->setObjectName(QStringLiteral("lblFournisseur"));
        lblFournisseur->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblFournisseur);

        cbFournisseur = new QComboBox(gbDetailArticle);
        cbFournisseur->setObjectName(QStringLiteral("cbFournisseur"));

        horizontalLayout_4->addWidget(cbFournisseur);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        lblPrixVente = new QLabel(gbDetailArticle);
        lblPrixVente->setObjectName(QStringLiteral("lblPrixVente"));
        lblPrixVente->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblPrixVente);

        dspPrixVente = new QDoubleSpinBox(gbDetailArticle);
        dspPrixVente->setObjectName(QStringLiteral("dspPrixVente"));
        dspPrixVente->setEnabled(true);
        dspPrixVente->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dspPrixVente->setMaximum(100);
        dspPrixVente->setSingleStep(5);

        horizontalLayout_4->addWidget(dspPrixVente);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        lblPrixAchat = new QLabel(gbDetailArticle);
        lblPrixAchat->setObjectName(QStringLiteral("lblPrixAchat"));

        horizontalLayout_4->addWidget(lblPrixAchat);

        dspPrixAchat = new QDoubleSpinBox(gbDetailArticle);
        dspPrixAchat->setObjectName(QStringLiteral("dspPrixAchat"));
        dspPrixAchat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dspPrixAchat->setMaximum(50);
        dspPrixAchat->setSingleStep(5);

        horizontalLayout_4->addWidget(dspPrixAchat);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        gbDescription = new QGroupBox(gbDetailArticle);
        gbDescription->setObjectName(QStringLiteral("gbDescription"));
        horizontalLayout_5 = new QHBoxLayout(gbDescription);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        teDescription = new QTextEdit(gbDescription);
        teDescription->setObjectName(QStringLiteral("teDescription"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(teDescription->sizePolicy().hasHeightForWidth());
        teDescription->setSizePolicy(sizePolicy1);
        teDescription->setMinimumSize(QSize(450, 0));

        horizontalLayout_5->addWidget(teDescription);


        horizontalLayout_3->addWidget(gbDescription);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        gbPhoto = new QGroupBox(gbDetailArticle);
        gbPhoto->setObjectName(QStringLiteral("gbPhoto"));
        gbPhoto->setMinimumSize(QSize(50, 0));
        gbPhoto->setMaximumSize(QSize(461, 231));
        horizontalLayout_6 = new QHBoxLayout(gbPhoto);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gvPhoto = new QGraphicsView(gbPhoto);
        gvPhoto->setObjectName(QStringLiteral("gvPhoto"));
        sizePolicy1.setHeightForWidth(gvPhoto->sizePolicy().hasHeightForWidth());
        gvPhoto->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(gvPhoto);


        horizontalLayout_3->addWidget(gbPhoto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(gbDetailArticle);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        btnAjouter = new QPushButton(GuiGestionArticle);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouter->setIcon(icon);

        horizontalLayout_8->addWidget(btnAjouter);

        btnValider = new QPushButton(GuiGestionArticle);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon1);

        horizontalLayout_8->addWidget(btnValider);

        btnModifier = new QPushButton(GuiGestionArticle);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon2);

        horizontalLayout_8->addWidget(btnModifier);

        btnAnnuler = new QPushButton(GuiGestionArticle);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon3);

        horizontalLayout_8->addWidget(btnAnnuler);

        btnSupprimer = new QPushButton(GuiGestionArticle);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/SeboApp/Resources/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon4);

        horizontalLayout_8->addWidget(btnSupprimer);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(GuiGestionArticle);

        QMetaObject::connectSlotsByName(GuiGestionArticle);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionArticle)
    {
        GuiGestionArticle->setWindowTitle(QApplication::translate("GuiGestionArticle", "GuiGestionArticle", Q_NULLPTR));
        lblTitreArticle->setText(QApplication::translate("GuiGestionArticle", "Gestion des articles :", Q_NULLPTR));
        gbFiltrer->setTitle(QApplication::translate("GuiGestionArticle", "Filtrer par :", Q_NULLPTR));
        lblFiltreCategorie->setText(QApplication::translate("GuiGestionArticle", "Cat\303\251gorie :", Q_NULLPTR));
        lblFiltreGenre->setText(QApplication::translate("GuiGestionArticle", "Genre :", Q_NULLPTR));
        lblFiltreLibelle->setText(QApplication::translate("GuiGestionArticle", "Libell\303\251 :", Q_NULLPTR));
        btnToutAfficher->setText(QApplication::translate("GuiGestionArticle", "Tout Afficher", Q_NULLPTR));
        btnToutAfficher->setShortcut(QString());
        gbDetailArticle->setTitle(QApplication::translate("GuiGestionArticle", "D\303\251tail :", Q_NULLPTR));
        lblReference->setText(QApplication::translate("GuiGestionArticle", "R\303\251f\303\251rence :", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiGestionArticle", "Libell\303\251 :", Q_NULLPTR));
        ckReapprovisionable->setText(QApplication::translate("GuiGestionArticle", "R\303\251approvisionnable", Q_NULLPTR));
        lblGenre->setText(QApplication::translate("GuiGestionArticle", "Genre:", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("GuiGestionArticle", "Cat\303\251gorie :", Q_NULLPTR));
        lblFournisseur->setText(QApplication::translate("GuiGestionArticle", "Fournisseur :", Q_NULLPTR));
        lblPrixVente->setText(QApplication::translate("GuiGestionArticle", "Prix de vente :", Q_NULLPTR));
        dspPrixVente->setSuffix(QApplication::translate("GuiGestionArticle", " \342\202\254", Q_NULLPTR));
        lblPrixAchat->setText(QApplication::translate("GuiGestionArticle", "Prix d'achat :", Q_NULLPTR));
        dspPrixAchat->setSuffix(QApplication::translate("GuiGestionArticle", " \342\202\254", Q_NULLPTR));
        gbDescription->setTitle(QApplication::translate("GuiGestionArticle", "Description :", Q_NULLPTR));
        gbPhoto->setTitle(QApplication::translate("GuiGestionArticle", "Photo :", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("GuiGestionArticle", "Ajouter", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiGestionArticle", "Valider", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("GuiGestionArticle", "Modifier", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiGestionArticle", "Annuler", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("GuiGestionArticle", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionArticle: public Ui_GuiGestionArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONARTICLE_H
