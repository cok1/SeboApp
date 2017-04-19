/********************************************************************************
** Form generated from reading UI file 'EditionArticle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITIONARTICLE_H
#define UI_EDITIONARTICLE_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditionArticle
{
public:
    QVBoxLayout *verticalLayout;
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
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *lblPhoto;
    QHBoxLayout *hlBoutonsPhoto;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btnAjouterPhoto;
    QPushButton *btnModifierPhoto;
    QPushButton *btnSupprimerPhoto;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *gbRoles;
    QVBoxLayout *verticalLayout_4;
    QTableView *tvRoles;
    QHBoxLayout *hlBoutonsRoles;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnAjouterRole;
    QPushButton *btnModifierRole;
    QPushButton *btnSupprimerRole;
    QHBoxLayout *hlBoutons;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frGestion;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblUrlPhoto;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QFrame *frEdition;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *EditionArticle)
    {
        if (EditionArticle->objectName().isEmpty())
            EditionArticle->setObjectName(QStringLiteral("EditionArticle"));
        EditionArticle->resize(1186, 422);
        verticalLayout = new QVBoxLayout(EditionArticle);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbDetailArticle = new QGroupBox(EditionArticle);
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGererCategorie->setIcon(icon);

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
        btnGererGenre->setIcon(icon);

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
        gbPhoto->setMinimumSize(QSize(250, 0));
        gbPhoto->setMaximumSize(QSize(461, 250));
        verticalLayout_2 = new QVBoxLayout(gbPhoto);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_4->addItem(verticalSpacer);

        lblPhoto = new QLabel(gbPhoto);
        lblPhoto->setObjectName(QStringLiteral("lblPhoto"));
        sizePolicy1.setHeightForWidth(lblPhoto->sizePolicy().hasHeightForWidth());
        lblPhoto->setSizePolicy(sizePolicy1);
        lblPhoto->setMinimumSize(QSize(0, 0));
        lblPhoto->setMaximumSize(QSize(250, 250));
        lblPhoto->setSizeIncrement(QSize(0, 0));
        lblPhoto->setBaseSize(QSize(0, 0));
        lblPhoto->setTextFormat(Qt::AutoText);
        lblPhoto->setScaledContents(false);
        lblPhoto->setAlignment(Qt::AlignCenter);
        lblPhoto->setMargin(2);
        lblPhoto->setIndent(0);

        horizontalLayout_4->addWidget(lblPhoto);


        verticalLayout_2->addLayout(horizontalLayout_4);

        hlBoutonsPhoto = new QHBoxLayout();
        hlBoutonsPhoto->setSpacing(6);
        hlBoutonsPhoto->setObjectName(QStringLiteral("hlBoutonsPhoto"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlBoutonsPhoto->addItem(horizontalSpacer_10);

        btnAjouterPhoto = new QPushButton(gbPhoto);
        btnAjouterPhoto->setObjectName(QStringLiteral("btnAjouterPhoto"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/add2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouterPhoto->setIcon(icon1);

        hlBoutonsPhoto->addWidget(btnAjouterPhoto);

        btnModifierPhoto = new QPushButton(gbPhoto);
        btnModifierPhoto->setObjectName(QStringLiteral("btnModifierPhoto"));
        btnModifierPhoto->setIcon(icon);

        hlBoutonsPhoto->addWidget(btnModifierPhoto);

        btnSupprimerPhoto = new QPushButton(gbPhoto);
        btnSupprimerPhoto->setObjectName(QStringLiteral("btnSupprimerPhoto"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/delete2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimerPhoto->setIcon(icon2);

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
        tvRoles = new QTableView(gbRoles);
        tvRoles->setObjectName(QStringLiteral("tvRoles"));
        tvRoles->setMinimumSize(QSize(175, 0));
        tvRoles->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvRoles->setAlternatingRowColors(true);
        tvRoles->setSelectionMode(QAbstractItemView::SingleSelection);
        tvRoles->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvRoles->setShowGrid(false);
        tvRoles->horizontalHeader()->setVisible(false);
        tvRoles->horizontalHeader()->setStretchLastSection(true);
        tvRoles->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(tvRoles);

        hlBoutonsRoles = new QHBoxLayout();
        hlBoutonsRoles->setSpacing(6);
        hlBoutonsRoles->setObjectName(QStringLiteral("hlBoutonsRoles"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlBoutonsRoles->addItem(horizontalSpacer_9);

        btnAjouterRole = new QPushButton(gbRoles);
        btnAjouterRole->setObjectName(QStringLiteral("btnAjouterRole"));
        btnAjouterRole->setIcon(icon1);

        hlBoutonsRoles->addWidget(btnAjouterRole);

        btnModifierRole = new QPushButton(gbRoles);
        btnModifierRole->setObjectName(QStringLiteral("btnModifierRole"));
        btnModifierRole->setIcon(icon);

        hlBoutonsRoles->addWidget(btnModifierRole);

        btnSupprimerRole = new QPushButton(gbRoles);
        btnSupprimerRole->setObjectName(QStringLiteral("btnSupprimerRole"));
        btnSupprimerRole->setIcon(icon2);

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

        frGestion = new QFrame(EditionArticle);
        frGestion->setObjectName(QStringLiteral("frGestion"));
        frGestion->setFrameShape(QFrame::StyledPanel);
        frGestion->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frGestion);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblUrlPhoto = new QLabel(frGestion);
        lblUrlPhoto->setObjectName(QStringLiteral("lblUrlPhoto"));

        horizontalLayout_2->addWidget(lblUrlPhoto);

        btnAjouter = new QPushButton(frGestion);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        btnAjouter->setIcon(icon1);

        horizontalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(frGestion);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        btnModifier->setIcon(icon);

        horizontalLayout_2->addWidget(btnModifier);

        btnSupprimer = new QPushButton(frGestion);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        btnSupprimer->setIcon(icon2);

        horizontalLayout_2->addWidget(btnSupprimer);


        hlBoutons->addWidget(frGestion);

        frEdition = new QFrame(EditionArticle);
        frEdition->setObjectName(QStringLiteral("frEdition"));
        frEdition->setFrameShape(QFrame::StyledPanel);
        frEdition->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frEdition);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnValider = new QPushButton(frEdition);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon3);

        horizontalLayout_3->addWidget(btnValider);

        btnAnnuler = new QPushButton(frEdition);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon4);

        horizontalLayout_3->addWidget(btnAnnuler);


        hlBoutons->addWidget(frEdition);


        verticalLayout->addLayout(hlBoutons);


        retranslateUi(EditionArticle);

        QMetaObject::connectSlotsByName(EditionArticle);
    } // setupUi

    void retranslateUi(QWidget *EditionArticle)
    {
        EditionArticle->setWindowTitle(QApplication::translate("EditionArticle", "EditionArticle", Q_NULLPTR));
        gbDetailArticle->setTitle(QApplication::translate("EditionArticle", "D\303\251tail :", Q_NULLPTR));
        lblReference->setText(QApplication::translate("EditionArticle", "R\303\251f\303\251rence :", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("EditionArticle", "Libell\303\251 :", Q_NULLPTR));
        ckReapprovisionable->setText(QApplication::translate("EditionArticle", "R\303\251approvisionnable", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("EditionArticle", "Cat\303\251gorie :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnGererCategorie->setToolTip(QApplication::translate("EditionArticle", "Permet de g\303\251rer les cat\303\251gories", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnGererCategorie->setText(QString());
        lblGenre->setText(QApplication::translate("EditionArticle", "Genre:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnGererGenre->setToolTip(QApplication::translate("EditionArticle", "Permet de g\303\251rer les genres", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnGererGenre->setText(QString());
        lblFournisseur->setText(QApplication::translate("EditionArticle", "Fournisseur :", Q_NULLPTR));
        lblPrixVente->setText(QApplication::translate("EditionArticle", "Prix de vente :", Q_NULLPTR));
        dspPrixVente->setSuffix(QApplication::translate("EditionArticle", " \342\202\254", Q_NULLPTR));
        lblPrixAchat->setText(QApplication::translate("EditionArticle", "Prix d'achat :", Q_NULLPTR));
        dspPrixAchat->setSuffix(QApplication::translate("EditionArticle", " \342\202\254", Q_NULLPTR));
        gbDescription->setTitle(QApplication::translate("EditionArticle", "Description :", Q_NULLPTR));
        gbPhoto->setTitle(QApplication::translate("EditionArticle", "Photo :", Q_NULLPTR));
        lblPhoto->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAjouterPhoto->setToolTip(QApplication::translate("EditionArticle", "Permet d'ajouter une photo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnAjouterPhoto->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnModifierPhoto->setToolTip(QApplication::translate("EditionArticle", "permet de modifier la photo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnModifierPhoto->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSupprimerPhoto->setToolTip(QApplication::translate("EditionArticle", "Permet de supprimer la photo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnSupprimerPhoto->setText(QString());
        gbRoles->setTitle(QApplication::translate("EditionArticle", "R\303\264les associ\303\251s :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnAjouterRole->setToolTip(QApplication::translate("EditionArticle", "Permet d'ajouter un r\303\264le", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnAjouterRole->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnModifierRole->setToolTip(QApplication::translate("EditionArticle", "Permet de modifier un r\303\264le", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnModifierRole->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSupprimerRole->setToolTip(QApplication::translate("EditionArticle", "Permet de supprrimer un r\303\264le", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnSupprimerRole->setText(QString());
        lblUrlPhoto->setText(QString());
        btnAjouter->setText(QApplication::translate("EditionArticle", "Ajouter", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("EditionArticle", "Modifier", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("EditionArticle", "Supprimer", Q_NULLPTR));
        btnValider->setText(QApplication::translate("EditionArticle", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("EditionArticle", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditionArticle: public Ui_EditionArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITIONARTICLE_H
