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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
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
    QHBoxLayout *hlDetail1;
    QLabel *lblReference;
    QLineEdit *leReference;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QCheckBox *ckReapprovisionable;
    QHBoxLayout *hlDetail2;
    QLabel *lblCategorie;
    QComboBox *cbCategorie;
    QPushButton *btnGererCategorie;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lblGenre;
    QComboBox *cbGenre;
    QPushButton *btnGererGenre;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lblFournisseur;
    QComboBox *cbFournisseur;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lblPrixVente;
    QDoubleSpinBox *dspPrixVente;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lblPrixAchat;
    QDoubleSpinBox *dspPrixAchat;
    QHBoxLayout *hlDetail3;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gbDescription;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *teDescription;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *gbPhoto;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblPhoto;
    QHBoxLayout *hlBoutonsPhoto;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btnAjouterPhoto;
    QPushButton *btnModifierPhoto;
    QPushButton *btnSupprimerPhoto;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *gbRoles;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tvRoles;
    QHBoxLayout *hlBoutonsRoles;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnAjouterRole;
    QPushButton *btnModifierRole;
    QPushButton *btnSupprimerRole;
    QHBoxLayout *hlBoutons;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frGestion;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QFrame *frEdition;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiGestionArticle)
    {
        if (GuiGestionArticle->objectName().isEmpty())
            GuiGestionArticle->setObjectName(QStringLiteral("GuiGestionArticle"));
        GuiGestionArticle->resize(943, 930);
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
        font1.setPointSize(20);
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/toutAfficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToutAfficher->setIcon(icon);
        btnToutAfficher->setCheckable(true);
        btnToutAfficher->setChecked(false);

        horizontalLayout->addWidget(btnToutAfficher);


        verticalLayout->addWidget(gbFiltrer);

        tvArticle = new QTableView(GuiGestionArticle);
        tvArticle->setObjectName(QStringLiteral("tvArticle"));
        tvArticle->setMinimumSize(QSize(0, 350));
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
        hlDetail1 = new QHBoxLayout();
        hlDetail1->setSpacing(6);
        hlDetail1->setObjectName(QStringLiteral("hlDetail1"));
        lblReference = new QLabel(gbDetailArticle);
        lblReference->setObjectName(QStringLiteral("lblReference"));
        lblReference->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hlDetail1->addWidget(lblReference);

        leReference = new QLineEdit(gbDetailArticle);
        leReference->setObjectName(QStringLiteral("leReference"));
        leReference->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leReference->sizePolicy().hasHeightForWidth());
        leReference->setSizePolicy(sizePolicy);

        hlDetail1->addWidget(leReference);

        lblLibelle = new QLabel(gbDetailArticle);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));
        lblLibelle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hlDetail1->addWidget(lblLibelle);

        leSaisieLibelle = new QLineEdit(gbDetailArticle);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        hlDetail1->addWidget(leSaisieLibelle);

        ckReapprovisionable = new QCheckBox(gbDetailArticle);
        ckReapprovisionable->setObjectName(QStringLiteral("ckReapprovisionable"));

        hlDetail1->addWidget(ckReapprovisionable);


        verticalLayout_3->addLayout(hlDetail1);

        hlDetail2 = new QHBoxLayout();
        hlDetail2->setSpacing(6);
        hlDetail2->setObjectName(QStringLiteral("hlDetail2"));
        lblCategorie = new QLabel(gbDetailArticle);
        lblCategorie->setObjectName(QStringLiteral("lblCategorie"));
        lblCategorie->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hlDetail2->addWidget(lblCategorie);

        cbCategorie = new QComboBox(gbDetailArticle);
        cbCategorie->setObjectName(QStringLiteral("cbCategorie"));

        hlDetail2->addWidget(cbCategorie);

        btnGererCategorie = new QPushButton(gbDetailArticle);
        btnGererCategorie->setObjectName(QStringLiteral("btnGererCategorie"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGererCategorie->setIcon(icon1);

        hlDetail2->addWidget(btnGererCategorie);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail2->addItem(horizontalSpacer_6);

        lblGenre = new QLabel(gbDetailArticle);
        lblGenre->setObjectName(QStringLiteral("lblGenre"));
        lblGenre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hlDetail2->addWidget(lblGenre);

        cbGenre = new QComboBox(gbDetailArticle);
        cbGenre->setObjectName(QStringLiteral("cbGenre"));

        hlDetail2->addWidget(cbGenre);

        btnGererGenre = new QPushButton(gbDetailArticle);
        btnGererGenre->setObjectName(QStringLiteral("btnGererGenre"));
        btnGererGenre->setIcon(icon1);

        hlDetail2->addWidget(btnGererGenre);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail2->addItem(horizontalSpacer_5);

        lblFournisseur = new QLabel(gbDetailArticle);
        lblFournisseur->setObjectName(QStringLiteral("lblFournisseur"));
        lblFournisseur->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hlDetail2->addWidget(lblFournisseur);

        cbFournisseur = new QComboBox(gbDetailArticle);
        cbFournisseur->setObjectName(QStringLiteral("cbFournisseur"));

        hlDetail2->addWidget(cbFournisseur);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail2->addItem(horizontalSpacer_7);

        lblPrixVente = new QLabel(gbDetailArticle);
        lblPrixVente->setObjectName(QStringLiteral("lblPrixVente"));
        lblPrixVente->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hlDetail2->addWidget(lblPrixVente);

        dspPrixVente = new QDoubleSpinBox(gbDetailArticle);
        dspPrixVente->setObjectName(QStringLiteral("dspPrixVente"));
        dspPrixVente->setEnabled(true);
        dspPrixVente->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dspPrixVente->setMaximum(100);
        dspPrixVente->setSingleStep(5);

        hlDetail2->addWidget(dspPrixVente);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail2->addItem(horizontalSpacer_8);

        lblPrixAchat = new QLabel(gbDetailArticle);
        lblPrixAchat->setObjectName(QStringLiteral("lblPrixAchat"));

        hlDetail2->addWidget(lblPrixAchat);

        dspPrixAchat = new QDoubleSpinBox(gbDetailArticle);
        dspPrixAchat->setObjectName(QStringLiteral("dspPrixAchat"));
        dspPrixAchat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dspPrixAchat->setMaximum(50);
        dspPrixAchat->setSingleStep(5);

        hlDetail2->addWidget(dspPrixAchat);


        verticalLayout_3->addLayout(hlDetail2);

        hlDetail3 = new QHBoxLayout();
        hlDetail3->setSpacing(6);
        hlDetail3->setObjectName(QStringLiteral("hlDetail3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail3->addItem(horizontalSpacer);

        gbDescription = new QGroupBox(gbDetailArticle);
        gbDescription->setObjectName(QStringLiteral("gbDescription"));
        gbDescription->setMaximumSize(QSize(16777215, 250));
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
        teDescription->setMinimumSize(QSize(450, 200));
        teDescription->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(teDescription);


        hlDetail3->addWidget(gbDescription);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail3->addItem(horizontalSpacer_3);

        gbPhoto = new QGroupBox(gbDetailArticle);
        gbPhoto->setObjectName(QStringLiteral("gbPhoto"));
        gbPhoto->setMinimumSize(QSize(50, 0));
        gbPhoto->setMaximumSize(QSize(461, 250));
        verticalLayout_2 = new QVBoxLayout(gbPhoto);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblPhoto = new QLabel(gbPhoto);
        lblPhoto->setObjectName(QStringLiteral("lblPhoto"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblPhoto->sizePolicy().hasHeightForWidth());
        lblPhoto->setSizePolicy(sizePolicy2);
        lblPhoto->setMinimumSize(QSize(0, 0));
        lblPhoto->setMaximumSize(QSize(250, 250));
        lblPhoto->setSizeIncrement(QSize(0, 0));
        lblPhoto->setBaseSize(QSize(0, 0));
        lblPhoto->setPixmap(QPixmap(QString::fromUtf8(":/SeboApp/Resources/kaaris.png")));
        lblPhoto->setScaledContents(true);
        lblPhoto->setAlignment(Qt::AlignCenter);
        lblPhoto->setMargin(2);
        lblPhoto->setIndent(0);

        verticalLayout_2->addWidget(lblPhoto);

        hlBoutonsPhoto = new QHBoxLayout();
        hlBoutonsPhoto->setSpacing(6);
        hlBoutonsPhoto->setObjectName(QStringLiteral("hlBoutonsPhoto"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlBoutonsPhoto->addItem(horizontalSpacer_10);

        btnAjouterPhoto = new QPushButton(gbPhoto);
        btnAjouterPhoto->setObjectName(QStringLiteral("btnAjouterPhoto"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouterPhoto->setIcon(icon2);

        hlBoutonsPhoto->addWidget(btnAjouterPhoto);

        btnModifierPhoto = new QPushButton(gbPhoto);
        btnModifierPhoto->setObjectName(QStringLiteral("btnModifierPhoto"));
        btnModifierPhoto->setIcon(icon1);

        hlBoutonsPhoto->addWidget(btnModifierPhoto);

        btnSupprimerPhoto = new QPushButton(gbPhoto);
        btnSupprimerPhoto->setObjectName(QStringLiteral("btnSupprimerPhoto"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimerPhoto->setIcon(icon3);

        hlBoutonsPhoto->addWidget(btnSupprimerPhoto);


        verticalLayout_2->addLayout(hlBoutonsPhoto);


        hlDetail3->addWidget(gbPhoto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlDetail3->addItem(horizontalSpacer_2);

        gbRoles = new QGroupBox(gbDetailArticle);
        gbRoles->setObjectName(QStringLiteral("gbRoles"));
        verticalLayout_4 = new QVBoxLayout(gbRoles);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tvRoles = new QTableWidget(gbRoles);
        tvRoles->setObjectName(QStringLiteral("tvRoles"));
        tvRoles->setMinimumSize(QSize(175, 0));

        verticalLayout_4->addWidget(tvRoles);

        hlBoutonsRoles = new QHBoxLayout();
        hlBoutonsRoles->setSpacing(6);
        hlBoutonsRoles->setObjectName(QStringLiteral("hlBoutonsRoles"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlBoutonsRoles->addItem(horizontalSpacer_9);

        btnAjouterRole = new QPushButton(gbRoles);
        btnAjouterRole->setObjectName(QStringLiteral("btnAjouterRole"));
        btnAjouterRole->setIcon(icon2);

        hlBoutonsRoles->addWidget(btnAjouterRole);

        btnModifierRole = new QPushButton(gbRoles);
        btnModifierRole->setObjectName(QStringLiteral("btnModifierRole"));
        btnModifierRole->setIcon(icon1);

        hlBoutonsRoles->addWidget(btnModifierRole);

        btnSupprimerRole = new QPushButton(gbRoles);
        btnSupprimerRole->setObjectName(QStringLiteral("btnSupprimerRole"));
        btnSupprimerRole->setIcon(icon3);

        hlBoutonsRoles->addWidget(btnSupprimerRole);


        verticalLayout_4->addLayout(hlBoutonsRoles);


        hlDetail3->addWidget(gbRoles);


        verticalLayout_3->addLayout(hlDetail3);


        verticalLayout->addWidget(gbDetailArticle);

        hlBoutons = new QHBoxLayout();
        hlBoutons->setSpacing(6);
        hlBoutons->setObjectName(QStringLiteral("hlBoutons"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlBoutons->addItem(horizontalSpacer_4);

        frGestion = new QFrame(GuiGestionArticle);
        frGestion->setObjectName(QStringLiteral("frGestion"));
        frGestion->setFrameShape(QFrame::StyledPanel);
        frGestion->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frGestion);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnAjouter = new QPushButton(frGestion);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        btnAjouter->setIcon(icon2);

        horizontalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(frGestion);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        btnModifier->setIcon(icon1);

        horizontalLayout_2->addWidget(btnModifier);

        btnSupprimer = new QPushButton(frGestion);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        btnSupprimer->setIcon(icon3);

        horizontalLayout_2->addWidget(btnSupprimer);


        hlBoutons->addWidget(frGestion);

        frEdition = new QFrame(GuiGestionArticle);
        frEdition->setObjectName(QStringLiteral("frEdition"));
        frEdition->setFrameShape(QFrame::StyledPanel);
        frEdition->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frEdition);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnValider = new QPushButton(frEdition);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon4);

        horizontalLayout_3->addWidget(btnValider);

        btnAnnuler = new QPushButton(frEdition);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon5);

        horizontalLayout_3->addWidget(btnAnnuler);


        hlBoutons->addWidget(frEdition);


        verticalLayout->addLayout(hlBoutons);


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
#ifndef QT_NO_TOOLTIP
        btnToutAfficher->setToolTip(QApplication::translate("GuiGestionArticle", "Permet de supprimer les filtres de fa\303\247on \303\240 tout afficher.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnToutAfficher->setText(QApplication::translate("GuiGestionArticle", "Tout Afficher", Q_NULLPTR));
        btnToutAfficher->setShortcut(QString());
        gbDetailArticle->setTitle(QApplication::translate("GuiGestionArticle", "D\303\251tail :", Q_NULLPTR));
        lblReference->setText(QApplication::translate("GuiGestionArticle", "R\303\251f\303\251rence :", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiGestionArticle", "Libell\303\251 :", Q_NULLPTR));
        ckReapprovisionable->setText(QApplication::translate("GuiGestionArticle", "R\303\251approvisionnable", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("GuiGestionArticle", "Cat\303\251gorie :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnGererCategorie->setToolTip(QApplication::translate("GuiGestionArticle", "Permet de g\303\251rer les cat\303\251gories", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnGererCategorie->setText(QString());
        lblGenre->setText(QApplication::translate("GuiGestionArticle", "Genre:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnGererGenre->setToolTip(QApplication::translate("GuiGestionArticle", "Permet de g\303\251rer les genres", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnGererGenre->setText(QString());
        lblFournisseur->setText(QApplication::translate("GuiGestionArticle", "Fournisseur :", Q_NULLPTR));
        lblPrixVente->setText(QApplication::translate("GuiGestionArticle", "Prix de vente :", Q_NULLPTR));
        dspPrixVente->setSuffix(QApplication::translate("GuiGestionArticle", " \342\202\254", Q_NULLPTR));
        lblPrixAchat->setText(QApplication::translate("GuiGestionArticle", "Prix d'achat :", Q_NULLPTR));
        dspPrixAchat->setSuffix(QApplication::translate("GuiGestionArticle", " \342\202\254", Q_NULLPTR));
        gbDescription->setTitle(QApplication::translate("GuiGestionArticle", "Description :", Q_NULLPTR));
        gbPhoto->setTitle(QApplication::translate("GuiGestionArticle", "Photo :", Q_NULLPTR));
        lblPhoto->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAjouterPhoto->setToolTip(QApplication::translate("GuiGestionArticle", "Permet d'ajouter une photo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnAjouterPhoto->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnModifierPhoto->setToolTip(QApplication::translate("GuiGestionArticle", "permet de modifier la photo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnModifierPhoto->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSupprimerPhoto->setToolTip(QApplication::translate("GuiGestionArticle", "Permet de supprimer la photo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnSupprimerPhoto->setText(QString());
        gbRoles->setTitle(QApplication::translate("GuiGestionArticle", "R\303\264les associ\303\251s :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnAjouterRole->setToolTip(QApplication::translate("GuiGestionArticle", "Permet d'ajouter un r\303\264le", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnAjouterRole->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnModifierRole->setToolTip(QApplication::translate("GuiGestionArticle", "Permet de modifier un r\303\264le", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnModifierRole->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSupprimerRole->setToolTip(QApplication::translate("GuiGestionArticle", "Permet de supprrimer un r\303\264le", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnSupprimerRole->setText(QString());
        btnAjouter->setText(QApplication::translate("GuiGestionArticle", "Ajouter", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("GuiGestionArticle", "Modifier", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("GuiGestionArticle", "Supprimer", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiGestionArticle", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiGestionArticle", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionArticle: public Ui_GuiGestionArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONARTICLE_H
