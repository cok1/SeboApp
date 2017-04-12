#pragma once

#include <QWidget>
#include <qtableview.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qgraphicsview.h>
#include <QDoubleSpinBox>
#include <qcheckbox.h>
#include <qsqltablemodel.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qpixmap.h>
#include <QModelIndex>
#include <qframe.h>
#include <qsortfilterproxymodel.h>

#include "Tools\Connexion.h"
#include "GuiGestionGenre.h"
#include "GuiGestionCategorie.h"
#include "Entity\Article.h"
#include "DAO\ManagerArticle.h"
#include "DAO\ManagerGenre.h"
#include "DAO\ManagerFournisseur.h"

namespace Ui { class GuiGestionArticle; };

class GuiGestionArticle : public QWidget
{
	Q_OBJECT

public:
	GuiGestionArticle(QWidget *parent = Q_NULLPTR);
	~GuiGestionArticle();

private:
	Ui::GuiGestionArticle *ui;

	// Partie filtrage
	QComboBox *cbFiltreCategorie;
	QComboBox *cbFiltreGenre;
	QLineEdit *leFiltreLibelle;
	QPushButton *btnToutAfficher;

	//Partie affichage
	QTableView *tvArticle;

	// Partie Modification Ajout
	QGroupBox *gbDetail;
	QLineEdit *leReference;
	QLineEdit *leSaisieLibelle;
	QCheckBox *ckReapprovisionnable;
	QComboBox *cbCategorie;
	QComboBox *cbGenre;
	QComboBox *cbFournisseur;
	QDoubleSpinBox *dspPrixVente;
	QDoubleSpinBox *dspPrixAchat;
	QTextEdit *teDescription;
	QLabel *lblPhoto;

	// Boutons
	QPushButton *btnAjouter;
	QPushButton *btnModifier;
	QPushButton *btnValider;
	QPushButton *btnAnnuler;
	QPushButton *btnSupprimer;
	QPushButton *btnGererCategorie;
	QPushButton *btnGererGenre;
	QPushButton *btnAjouterPhoto;
	QPushButton *btnModifierPhoto;
	QPushButton *btnSupprimerPhoto;
	QPushButton *btnAjouterRole;
	QPushButton *btnModifierRole;
	QPushButton *btnSupprimerRole;

	// modèle
	QSqlTableModel *model;
	QSortFilterProxyModel *proxyModel;

	// QFrame
	QFrame *frGestion;
	QFrame *frEdition;

	// Fonctions
	void majModel();
	void recupElements();
	void connectionSignaux();

private slots:
	void majTable();
	void majDetailArticle();
	void suppFiltre();
	void ajoutArticle();
	void modifierArticle();
	void supprimerArticle();
	void annuler();
	void valider();
	void gererCategorie();
	void gererGenre();
	void majCbCategorie();
	void majCbGenre();
	void majCbFournisseur();
	void filtrerCategorie(QString texte);
	void filtrerGenre(QString texte);
	void filtrerLibelle(QString texte);
	void toutAfficher();
};
