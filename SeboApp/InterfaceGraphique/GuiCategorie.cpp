#include "GuiCategorie.h"

GuiCategorie::GuiCategorie(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiCategorie();
	// mise en place des éléments
	ui->setupUi(this);

	// Récupération du pointeur vers l'instance unique de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	// mise à jour de la table
	majTable();

	// connexion des boutons et des méthodes associées
	connect(ui->btnValider, SIGNAL(clicked()), SLOT(ajouterArticle()));
	connect(ui->btnMajAffichage, SIGNAL(clicked()), SLOT(majTable()));
	connect(ui->btnAfficheId, SIGNAL(clicked()), SLOT(afficheId()));
	connect(ui->tvCategorie->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(afficheId()));
}



GuiCategorie::~GuiCategorie()
{
}

void GuiCategorie::ajouterArticle()
{
	Categorie *nouvelleCategorie = new Categorie(ui->leSaisieLibelle->text(), ui->spTauxTva->value());

	if (ManagerCategorie::addCategorie(nouvelleCategorie))
	{
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Information, "Création achevée", "L'identifiant de la nouvelle catégorie est : " + QString::number(nouvelleCategorie->getId()));
		int reponse = erreur->exec();
	}
	else
	{
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, "Problème lors de la création de la base de données", ManagerCategorie::getLastError());
		int reponse = erreur->exec();
	}
	majTable();
}

void GuiCategorie::majTable()
{
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du model à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	// sélection de la table à afficher
	model->setTable("DetailCategorie");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Ajustement des titres des colonnes
	model->setHeaderData(0, Qt::Horizontal, trUtf8("Id cat"));
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Tva"));

	// Application du modèle à la table View
	ui->tvCategorie->setModel(model);

	// Masquage du header vertical(nom des lignes)
	ui->tvCategorie->verticalHeader()->hide();

	// Masquage de la première colonne
	ui->tvCategorie->hideColumn(0);
	ui->tvCategorie->hideColumn(3);

	// Ajustement de la taille des colonnes pour remplir l'espace dispo
	ui->tvCategorie->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

	// La table devient non éditable
	ui->tvCategorie->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// mode sélection ligne unique complète
	ui->tvCategorie->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	ui->tvCategorie->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui->tvCategorie->setAlternatingRowColors(true);

	// Autorisation du tri
	ui->tvCategorie->setSortingEnabled(true);

	// affichage de la table
	ui->tvCategorie->show();
}

void GuiCategorie::afficheId()
{
	QItemSelectionModel *select = ui->tvCategorie->selectionModel();

	QVariant var = select->selectedRows(3).first().data(); // sélection de la valeur de la première ligne 3ème colonne

	if (var.toInt() == 0)
	{
		ui->btnMajAffichage->setEnabled(true);
	}
	else
	{
		ui->btnMajAffichage->setEnabled(false);
	}
}