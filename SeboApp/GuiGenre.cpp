#include "GuiGenre.h"
#include "ui_GuiGenre.h"

GuiGenre::GuiGenre(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGenre();
	ui->setupUi(this);

	// Récupération du pointeur vers l'instance unique de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	// mise à jour de la table
	majTable();
}

GuiGenre::~GuiGenre()
{
	delete ui;
}

void GuiGenre::majTable()
{
	// récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	//récupération de la base de données
	QSqlDatabase db = conn->getConnexion();

	QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
	//QSqlTableModel *model = new QSqlTableModel();

	// Choix de la table à afficher
	model->setTable("Genre");

	// Enregistrement de la relation sur la table catégorie et affichage du libellé
	model->setRelation(2, QSqlRelation("Categorie", "IdCategorie", "LibelleCategorie"));

	// Récupération des données
	model->select();

	// Ajustement des titres des colonnes
	model->setHeaderData(0, Qt::Horizontal, trUtf8("Id Genre"));
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Catégorie"));

	// Application du modèle sur la vue
	ui->view->setModel(model);

	// Masquage de la colonne d’en-tête
	ui->view->verticalHeader()->hide();

	// Masquage de la première colonne contenant l'id
	ui->view->hideColumn(0);

	ui->view->setItemDelegate(new QSqlRelationalDelegate(ui->view));
	
	// Ajustement de la taille des colonnes pour remplir l'espace dispo
	ui->view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

	// Suppression de l'édition de la table
	//ui->view->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// mode sélection ligne unique complète
	ui->view->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui->view->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Autorisation du tri
	ui->view->setSortingEnabled(true);


	// affichage de la table
	ui->view->show();
}
