/********************************************************************************
** Form generated from reading UI file 'AffichageArticles.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHAGEARTICLES_H
#define UI_AFFICHAGEARTICLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AffichageArticles
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbFiltre;
    QHBoxLayout *horizontalLayout;
    QLabel *lblCategorie;
    QComboBox *cbFiltreCategorie;
    QLabel *lblGenre;
    QComboBox *cbFiltreGenre;
    QLabel *lblLibelle;
    QLineEdit *leFiltreLibelle;
    QPushButton *btnToutAfficher;
    QTableView *tvArticle;

    void setupUi(QWidget *AffichageArticles)
    {
        if (AffichageArticles->objectName().isEmpty())
            AffichageArticles->setObjectName(QStringLiteral("AffichageArticles"));
        AffichageArticles->resize(1087, 789);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        AffichageArticles->setFont(font);
        verticalLayout = new QVBoxLayout(AffichageArticles);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbFiltre = new QGroupBox(AffichageArticles);
        gbFiltre->setObjectName(QStringLiteral("gbFiltre"));
        horizontalLayout = new QHBoxLayout(gbFiltre);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblCategorie = new QLabel(gbFiltre);
        lblCategorie->setObjectName(QStringLiteral("lblCategorie"));

        horizontalLayout->addWidget(lblCategorie);

        cbFiltreCategorie = new QComboBox(gbFiltre);
        cbFiltreCategorie->setObjectName(QStringLiteral("cbFiltreCategorie"));
        cbFiltreCategorie->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(cbFiltreCategorie);

        lblGenre = new QLabel(gbFiltre);
        lblGenre->setObjectName(QStringLiteral("lblGenre"));

        horizontalLayout->addWidget(lblGenre);

        cbFiltreGenre = new QComboBox(gbFiltre);
        cbFiltreGenre->setObjectName(QStringLiteral("cbFiltreGenre"));
        cbFiltreGenre->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(cbFiltreGenre);

        lblLibelle = new QLabel(gbFiltre);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));

        horizontalLayout->addWidget(lblLibelle);

        leFiltreLibelle = new QLineEdit(gbFiltre);
        leFiltreLibelle->setObjectName(QStringLiteral("leFiltreLibelle"));

        horizontalLayout->addWidget(leFiltreLibelle);

        btnToutAfficher = new QPushButton(gbFiltre);
        btnToutAfficher->setObjectName(QStringLiteral("btnToutAfficher"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/toutAfficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToutAfficher->setIcon(icon);

        horizontalLayout->addWidget(btnToutAfficher);


        verticalLayout->addWidget(gbFiltre);

        tvArticle = new QTableView(AffichageArticles);
        tvArticle->setObjectName(QStringLiteral("tvArticle"));
        tvArticle->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvArticle->setAlternatingRowColors(true);
        tvArticle->setSelectionMode(QAbstractItemView::SingleSelection);
        tvArticle->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvArticle->setSortingEnabled(true);
        tvArticle->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvArticle);


        retranslateUi(AffichageArticles);

        QMetaObject::connectSlotsByName(AffichageArticles);
    } // setupUi

    void retranslateUi(QWidget *AffichageArticles)
    {
        AffichageArticles->setWindowTitle(QApplication::translate("AffichageArticles", "AffichageArticles", Q_NULLPTR));
        gbFiltre->setTitle(QApplication::translate("AffichageArticles", "Filtrer par :", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("AffichageArticles", "Cat\303\251gorie :", Q_NULLPTR));
        lblGenre->setText(QApplication::translate("AffichageArticles", "Genre :", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("AffichageArticles", "Libell\303\251 :", Q_NULLPTR));
        btnToutAfficher->setText(QApplication::translate("AffichageArticles", "Tout Afficher", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AffichageArticles: public Ui_AffichageArticles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHAGEARTICLES_H
