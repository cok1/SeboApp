/********************************************************************************
** Form generated from reading UI file 'EssaiGuiArticle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESSAIGUIARTICLE_H
#define UI_ESSAIGUIARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_EssaiGuiArticle
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitreAjoutArticle;
    QHBoxLayout *laySaisie1;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QLabel *lblPV;
    QDoubleSpinBox *spPrixVente;
    QLabel *lblGenre;
    QComboBox *cbGenre;
    QHBoxLayout *LaySaisie2;
    QLabel *lblFournisseur;
    QComboBox *cbFournisseur;
    QLabel *lblPA;
    QDoubleSpinBox *spPrixFournisseur;
    QCheckBox *ckReapprovisionnable;
    QHBoxLayout *layBtn1;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnModifier;
    QPushButton *btnAjouter;
    QLabel *lblTitreTable;
    QTableView *tvArticles;
    QHBoxLayout *layBtn2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSupprimer;

    void setupUi(QWidget *EssaiGuiArticle)
    {
        if (EssaiGuiArticle->objectName().isEmpty())
            EssaiGuiArticle->setObjectName(QStringLiteral("EssaiGuiArticle"));
        EssaiGuiArticle->resize(579, 501);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        EssaiGuiArticle->setFont(font);
        verticalLayout = new QVBoxLayout(EssaiGuiArticle);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblTitreAjoutArticle = new QLabel(EssaiGuiArticle);
        lblTitreAjoutArticle->setObjectName(QStringLiteral("lblTitreAjoutArticle"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblTitreAjoutArticle->setFont(font1);

        verticalLayout->addWidget(lblTitreAjoutArticle);

        laySaisie1 = new QHBoxLayout();
        laySaisie1->setSpacing(6);
        laySaisie1->setObjectName(QStringLiteral("laySaisie1"));
        lblLibelle = new QLabel(EssaiGuiArticle);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));
        lblLibelle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        laySaisie1->addWidget(lblLibelle);

        leSaisieLibelle = new QLineEdit(EssaiGuiArticle);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leSaisieLibelle->sizePolicy().hasHeightForWidth());
        leSaisieLibelle->setSizePolicy(sizePolicy);

        laySaisie1->addWidget(leSaisieLibelle);

        lblPV = new QLabel(EssaiGuiArticle);
        lblPV->setObjectName(QStringLiteral("lblPV"));
        lblPV->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        laySaisie1->addWidget(lblPV);

        spPrixVente = new QDoubleSpinBox(EssaiGuiArticle);
        spPrixVente->setObjectName(QStringLiteral("spPrixVente"));

        laySaisie1->addWidget(spPrixVente);

        lblGenre = new QLabel(EssaiGuiArticle);
        lblGenre->setObjectName(QStringLiteral("lblGenre"));
        lblGenre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        laySaisie1->addWidget(lblGenre);

        cbGenre = new QComboBox(EssaiGuiArticle);
        cbGenre->setObjectName(QStringLiteral("cbGenre"));

        laySaisie1->addWidget(cbGenre);


        verticalLayout->addLayout(laySaisie1);

        LaySaisie2 = new QHBoxLayout();
        LaySaisie2->setSpacing(6);
        LaySaisie2->setObjectName(QStringLiteral("LaySaisie2"));
        lblFournisseur = new QLabel(EssaiGuiArticle);
        lblFournisseur->setObjectName(QStringLiteral("lblFournisseur"));
        lblFournisseur->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LaySaisie2->addWidget(lblFournisseur);

        cbFournisseur = new QComboBox(EssaiGuiArticle);
        cbFournisseur->setObjectName(QStringLiteral("cbFournisseur"));

        LaySaisie2->addWidget(cbFournisseur);

        lblPA = new QLabel(EssaiGuiArticle);
        lblPA->setObjectName(QStringLiteral("lblPA"));
        lblPA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LaySaisie2->addWidget(lblPA);

        spPrixFournisseur = new QDoubleSpinBox(EssaiGuiArticle);
        spPrixFournisseur->setObjectName(QStringLiteral("spPrixFournisseur"));

        LaySaisie2->addWidget(spPrixFournisseur);

        ckReapprovisionnable = new QCheckBox(EssaiGuiArticle);
        ckReapprovisionnable->setObjectName(QStringLiteral("ckReapprovisionnable"));

        LaySaisie2->addWidget(ckReapprovisionnable);


        verticalLayout->addLayout(LaySaisie2);

        layBtn1 = new QHBoxLayout();
        layBtn1->setSpacing(6);
        layBtn1->setObjectName(QStringLiteral("layBtn1"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layBtn1->addItem(horizontalSpacer);

        btnModifier = new QPushButton(EssaiGuiArticle);
        btnModifier->setObjectName(QStringLiteral("btnModifier"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon);

        layBtn1->addWidget(btnModifier);

        btnAjouter = new QPushButton(EssaiGuiArticle);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/Ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAjouter->setIcon(icon1);

        layBtn1->addWidget(btnAjouter);


        verticalLayout->addLayout(layBtn1);

        lblTitreTable = new QLabel(EssaiGuiArticle);
        lblTitreTable->setObjectName(QStringLiteral("lblTitreTable"));
        lblTitreTable->setFont(font1);
        lblTitreTable->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTitreTable);

        tvArticles = new QTableView(EssaiGuiArticle);
        tvArticles->setObjectName(QStringLiteral("tvArticles"));

        verticalLayout->addWidget(tvArticles);

        layBtn2 = new QHBoxLayout();
        layBtn2->setSpacing(6);
        layBtn2->setObjectName(QStringLiteral("layBtn2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layBtn2->addItem(horizontalSpacer_2);

        btnSupprimer = new QPushButton(EssaiGuiArticle);
        btnSupprimer->setObjectName(QStringLiteral("btnSupprimer"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon2);

        layBtn2->addWidget(btnSupprimer);


        verticalLayout->addLayout(layBtn2);


        retranslateUi(EssaiGuiArticle);

        QMetaObject::connectSlotsByName(EssaiGuiArticle);
    } // setupUi

    void retranslateUi(QWidget *EssaiGuiArticle)
    {
        EssaiGuiArticle->setWindowTitle(QApplication::translate("EssaiGuiArticle", "EssaiGuiArticle", Q_NULLPTR));
        lblTitreAjoutArticle->setText(QApplication::translate("EssaiGuiArticle", "Ajouter un article :", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("EssaiGuiArticle", "Libell\303\251 :", Q_NULLPTR));
        lblPV->setText(QApplication::translate("EssaiGuiArticle", "Prix vente (HT) :", Q_NULLPTR));
        lblGenre->setText(QApplication::translate("EssaiGuiArticle", "Genre :", Q_NULLPTR));
        lblFournisseur->setText(QApplication::translate("EssaiGuiArticle", "Fournisseur :", Q_NULLPTR));
        lblPA->setText(QApplication::translate("EssaiGuiArticle", "Prix d'achat :", Q_NULLPTR));
        ckReapprovisionnable->setText(QApplication::translate("EssaiGuiArticle", "R\303\251approvisionnable", Q_NULLPTR));
        btnModifier->setText(QApplication::translate("EssaiGuiArticle", "Modifier", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("EssaiGuiArticle", "Ajouter", Q_NULLPTR));
        lblTitreTable->setText(QApplication::translate("EssaiGuiArticle", "Liste des articles :", Q_NULLPTR));
        btnSupprimer->setText(QApplication::translate("EssaiGuiArticle", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EssaiGuiArticle: public Ui_EssaiGuiArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESSAIGUIARTICLE_H
