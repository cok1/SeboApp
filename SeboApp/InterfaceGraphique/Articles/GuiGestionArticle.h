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

#include "Tools\Connexion.h"

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
	QGraphicsView *gvPhoto;

	// Boutons
	QPushButton *btnAjouter;
	QPushButton *btnModifier;
	QPushButton *btnValider;
	QPushButton *btnAnnuler;
	QPushButton *btnSupprimer;

	// modèle
	QSqlTableModel *model;

	void majModel();

private slots:
	void majTable();
	void majDetailArticle();
	void suppFiltre();
	void ajoutArticle();
	void modifierArticle();
	void supprimerArticle();
	void annuler();
	void valider();
};
