#include "GuiGestionArticle.h"
#include "ui_GuiGestionArticle.h"

GuiGestionArticle::GuiGestionArticle(QWidget *parent)
	: QWidget(parent)
{
	// mise en place de l'interface graphique
	ui = new Ui::GuiGestionArticle();
	ui->setupUi(this);

	// récupération des éléments de l'interface
	recupElements();

	// Mise à jour du modèle
	majModel();

	// mise à jour de la table
	majTable();

	// Initialisation des comboBox
	majCbFournisseur();
	cbFournisseur->setCurrentIndex(-1);

	majCbGenre();
	cbGenre->setCurrentIndex(-1);

	majCbCategorie();
	cbCategorie->setCurrentIndex(-1);

	// désactivation de la groupBox d'affichage des détails de l'article
	gbDetail->setEnabled(false);
	frEdition->setVisible(false);
	btnSupprimer->setEnabled(false);
	btnModifier->setEnabled(false);


	// connection des signaux
	connectionSignaux();
}

GuiGestionArticle::~GuiGestionArticle()
{
	delete ui;
}

void GuiGestionArticle::majTable()
{
	// récupération du modèle
	tvArticle->setModel(model);

	tvArticle->hideColumn(2);
	tvArticle->hideColumn(3);
	tvArticle->hideColumn(4);
	tvArticle->hideColumn(6);
	tvArticle->hideColumn(8);
	tvArticle->hideColumn(11);
	tvArticle->hideColumn(12);
	tvArticle->hideColumn(13);
}

void GuiGestionArticle::majModel()
{
	// récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	//récupération de la base de données
	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	model = new QSqlTableModel();

	model->setTable("DetailArticle");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// tri des articles
	model->sort(0, Qt::AscendingOrder);
}

void GuiGestionArticle::recupElements()
{
	// récupération des éléments
	cbFiltreCategorie = ui->cbFiltreCategorie;
	cbFiltreGenre = ui->cbFiltreGenre;
	leFiltreLibelle = ui->leFiltreLibelle;
	btnToutAfficher = ui->btnToutAfficher;

	//Partie affichage
	tvArticle = ui->tvArticle;

	// Partie Modification Ajout
	gbDetail = ui->gbDetailArticle;
	leReference = ui->leReference;
	leSaisieLibelle = ui->leSaisieLibelle;
	ckReapprovisionnable = ui->ckReapprovisionable;
	cbCategorie = ui->cbCategorie;
	cbGenre = ui->cbGenre;
	cbFournisseur = ui->cbFournisseur;
	dspPrixVente = ui->dspPrixVente;
	dspPrixAchat = ui->dspPrixAchat;
	teDescription = ui->teDescription;
	lblPhoto = ui->lblPhoto;

	// Boutons
	btnAjouter = ui->btnAjouter;
	btnModifier = ui->btnModifier;
	btnValider = ui->btnValider;
	btnAnnuler = ui->btnAnnuler;
	btnSupprimer = ui->btnSupprimer;
	btnGererCategorie = ui->btnGererCategorie;
	btnGererGenre = ui->btnGererGenre;
	btnAjouterPhoto = ui->btnAjouterPhoto;
	btnModifierPhoto = ui->btnModifierPhoto;
	btnSupprimerPhoto = ui->btnSupprimerPhoto;
	btnAjouterRole = ui->btnAjouterRole;
	btnModifierRole = ui->btnModifierRole;
	btnSupprimerRole = ui->btnSupprimerRole;

	// Ensemble de boutons
	frEdition = ui->frEdition;
	frGestion = ui->frGestion;
}

void GuiGestionArticle::connectionSignaux()
{
	connect(tvArticle->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majDetailArticle()));
	connect(btnGererCategorie, SIGNAL(clicked()), SLOT(gererCategorie()));
	connect(btnGererGenre, SIGNAL(clicked()), SLOT(gererGenre()));
	connect(btnModifier, SIGNAL(clicked()), SLOT(modifierArticle()));
	connect(btnAnnuler, SIGNAL(clicked()), SLOT(annuler()));
}

void GuiGestionArticle::majDetailArticle()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvArticle->selectionModel();

	// Récupération de la référence
	QVariant var = select->selectedRows(0).first().data();
	leReference->setText(var.toString());

	// Récupération du libellé
	var = select->selectedRows(1).first().data();
	leSaisieLibelle->setText(var.toString());

	// Récupération de la description
	var = select->selectedRows(2).first().data();
	teDescription->setText(var.toString());

	// Récupération du nom de la photo
	//var = select->selectedRows(3).first().data();
	//QString nomPhoto = var.toString();

	// Récupération de la catégorie
	var = select->selectedRows(5).first().data();
	cbCategorie->setCurrentText(var.toString());

	// Récupération du genre
	var = select->selectedRows(7).first().data();
	cbGenre->setCurrentText(var.toString());

	// Récupération du fournisseur
	var = select->selectedRows(9).first().data();
	cbFournisseur->setCurrentText(var.toString());

	// Récupération du prix de vente
	var = select->selectedRows(10).first().data();
	dspPrixVente->setValue(var.toDouble());

	// Récupération du prix d'achat
	var = select->selectedRows(11).first().data();
	dspPrixAchat->setValue(var.toDouble());

	// Récupération du statut de réapprovisionnement
	var = select->selectedRows(12).first().data();
	ckReapprovisionnable->setChecked(var.toBool());

	// Récupération du nombre d'utilisation
	var = select->selectedRows(13).first().data();
	btnSupprimer->setEnabled(var.toInt() == 0);

	// Activation du bouton de modification
	btnModifier->setEnabled(true);
}

void GuiGestionArticle::suppFiltre()
{
}

void GuiGestionArticle::ajoutArticle()
{
}

void GuiGestionArticle::modifierArticle()
{
	// Désactivation de la sélection sur la table
	tvArticle->setSelectionMode(QAbstractItemView::NoSelection);

	if (tvArticle->currentIndex().row() != -1)
	{
		// activation de l'édition
		gbDetail->setEnabled(true);
		frEdition->setVisible(true);

		// on masque le frame de gestion
		frGestion->setVisible(false);
	}
}

void GuiGestionArticle::supprimerArticle()
{
	// Appel de la procédure stockée de suppression
}

void GuiGestionArticle::annuler()
{
	// mise à jour du détail à partir des infos enregistrée
	majDetailArticle();

	// Désactivation de la description
	gbDetail->setEnabled(false);

	// masquage du frame d'eddition
	frEdition->setVisible(false);

	// réaffichage du frame de gestion
	frGestion->setVisible(true);

	// réactivation de la sélection sur la table article
	tvArticle->setSelectionMode(QAbstractItemView::SingleSelection);
}

void GuiGestionArticle::valider()
{
	// Appel des procédure stockées
}

void GuiGestionArticle::gererCategorie()
{
	GuiGestionCategorie *gererCat = new GuiGestionCategorie();
	gererCat->setWindowModality(Qt::ApplicationModal);
	gererCat->show();
}

void GuiGestionArticle::gererGenre()
{
	GuiGestionGenre *gererGen = new GuiGestionGenre();
	gererGen->setWindowModality(Qt::ApplicationModal);
	gererGen->show();
}

void GuiGestionArticle::majCbCategorie()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	model->setTable("Categorie");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Remplissage de la comboBox fournisseur
	cbCategorie->setModel(model);
	cbCategorie->setModelColumn(1);
}

void GuiGestionArticle::majCbGenre()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	model->setTable("Genre");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Remplissage de la comboBox fournisseur
	cbGenre->setModel(model);
	cbGenre->setModelColumn(1);
}

void GuiGestionArticle::majCbFournisseur()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	model->setTable("Fournisseur");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Remplissage de la comboBox fournisseur
	cbFournisseur->setModel(model);
	cbFournisseur->setModelColumn(1);
}

