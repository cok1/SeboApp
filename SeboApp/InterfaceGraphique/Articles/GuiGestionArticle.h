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
#include <qbuffer.h>
#include <qurl.h>

#include "Tools\Connexion.h"
#include "GuiGestionGenre.h"
#include "GuiGestionCategorie.h"
#include "GuiGestionPhoto.h"
#include "Entity\Article.h"
#include "DAO\ManagerArticle.h"
#include "DAO\ManagerGenre.h"
#include "DAO\ManagerFournisseur.h"
#include "FileDownloader.h"

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
	QTableView *tvRole;

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
	QSqlTableModel *modelActeur;

	// QFrame
	QFrame *frGestion;
	QFrame *frEdition;

	QString urlPhoto;
	FileDownloader *m_pImgCtrl;

	// Fonctions
	void majModel();
	void recupElements();
	void connectionSignaux();
	void chargerPhoto();

private slots:
	void majTableArticle();
	void majTableRole(int Reference);
	void majDetailArticle();
	void suppFiltre();
	void ajoutArticle();
	void modifierArticle();
	void supprimerArticle();
	void annuler();
	void valider();
	void gererCategorie();
	void gererGenre();
	void majCbCategorie(int idCategorie = -1);
	void majCbGenre(int idCategorie = -1);
	void majCbFournisseur();
	void filtrerCategorie(QString texte);
	void filtrerGenre(QString texte);
	void filtrerLibelle(QString texte);
	void toutAfficher();
	void reinitChamps();
	void filtrerSaisieGenre(QString texte);
	void filtrerSaisieCategorie(QString texte);
	void majBtnPhoto();
	void ajouterPhoto();
	void modifierPhoto();
	void supprimerPhoto();
	void majUrlPhoto(QString url);
	void afficherPhoto();
	void ajouterRole();
	void supprimerRole();
};
