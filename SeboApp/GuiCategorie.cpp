#include "GuiCategorie.h"

GuiCategorie::GuiCategorie(QWidget *parent)
	: QWidget(parent)
{
	// mise en place des éléments
	ui.setupUi(this);

	// Récupération du pointeur vers l'instance unique de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	// mise à jour de la table
	majTable();

	// connexion des boutons et des méthodes associées
	connect(ui.btnValider, SIGNAL(clicked()), SLOT(ajouterArticle()));
	connect(ui.btnMajAffichage, SIGNAL(clicked()), SLOT(majTable()));
}



GuiCategorie::~GuiCategorie()
{
}

void GuiCategorie::ajouterArticle()
{
	ManagerCategorie::addCategorie(ui.leSaisieLibelle->text(), ui.spTauxTva->value());
	majTable();
}

void GuiCategorie::majTable()
{
	std::shared_ptr<Connexion> conn = Connexion::getInstance();
	/*if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");*/

	QSqlDatabase db = conn->getConnexion();

	// création du model à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	// sélection de la table à afficher
	model->setTable("Categorie");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Ajustement des titres des colonnes
	model->setHeaderData(0, Qt::Horizontal, trUtf8("Id cat"));
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Tva"));

	// Application du modèle à la table View
	ui.tvCategorie->setModel(model);

	// Masquage du header vertical(nom des lignes)
	ui.tvCategorie->verticalHeader()->hide();

	// Masquage de la première colonne
	ui.tvCategorie->hideColumn(0);

	// Ajustement de la taille des colonnes pour remplir l'espace dispo
	ui.tvCategorie->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

	// La table devient non éditable
	ui.tvCategorie->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// mode sélection ligne unique complète
	ui.tvCategorie->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui.tvCategorie->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Autorisation du tri
	ui.tvCategorie->setSortingEnabled(true);


	// affichage de la table
	ui.tvCategorie->show();
}
