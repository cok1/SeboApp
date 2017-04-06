#include "EssaiGuiArticle.h"

EssaiGuiArticle::EssaiGuiArticle(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Récupération du pointeur vers l'instance unique de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	initModel();

	initTable();

	initCombo();

	ui.btnModifier->setVisible(false);

	connect(ui.btnAjouter, SIGNAL(clicked()), SLOT(creerArticle()));
}

EssaiGuiArticle::~EssaiGuiArticle()
{
}

void EssaiGuiArticle::initModel()
{
	// récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	//récupération de la base de données
	QSqlDatabase db = conn->getConnexion();

	m_mModel = new QSqlRelationalTableModel();

	// Choix de la table à afficher
	m_mModel->setTable("Article");

	// Récupération des relation
	m_mModel->setRelation(3, QSqlRelation("Genre", "IdGenre", "LibelleGenre"));
	m_mModel->setRelation(5, QSqlRelation("Fournisseur", "IdFournisseur", "NomFournisseur"));

	// Récupération des données
	m_mModel->select();

	// Modification des titres des colonnes
	m_mModel->setHeaderData(0, Qt::Horizontal, trUtf8("Référence"));
	m_mModel->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	m_mModel->setHeaderData(2, Qt::Horizontal, trUtf8("Prix"));
	m_mModel->setHeaderData(3, Qt::Horizontal, trUtf8("Genre"));
	m_mModel->setHeaderData(4, Qt::Horizontal, trUtf8("Prix Achat"));
	m_mModel->setHeaderData(5, Qt::Horizontal, trUtf8("Fournisseur"));
}

void EssaiGuiArticle::majAffichage()
{
	initModel();
	initTable();
}

void EssaiGuiArticle::initCombo()
{
	// initialisation de la comboBox de sélection du genre
	ui.cbGenre->setModel(m_mModel->relationModel(3));
	ui.cbGenre->setModelColumn(m_mModel->relationModel(3)->fieldIndex("LibelleGenre"));

	// initialisation de la comboBox de sélection du fournisseur
	ui.cbFournisseur->setModel(m_mModel->relationModel(5));
	ui.cbFournisseur->setModelColumn(m_mModel->relationModel(5)->fieldIndex("NomFournisseur"));
}

void EssaiGuiArticle::initTable()
{
	// Application du modèle à la vue
	ui.tvArticles->setModel(m_mModel);

	// Masquage des nom de ligne
	ui.tvArticles->verticalHeader()->hide();

	// Mise en place du rendu
	ui.tvArticles->setItemDelegate(new QSqlRelationalDelegate(ui.tvArticles));

	// Ajustement de la taille des colonnes
	ui.tvArticles->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	// sélection ligne unique complète
	ui.tvArticles->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tvArticles->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Affichage de la table
	ui.tvArticles->show();
}

void EssaiGuiArticle::creerArticle()
{
	ui.lblGenre->setText(ui.cbFournisseur->currentText());
	Article nouvelArticle = Article(ui.leSaisieLibelle->text(), (float)ui.spPrixVente->value(), 1, (float) ui.spPrixFournisseur->value(), 1, ui.ckReapprovisionnable->isChecked());
	ManagerArticle::addArticle(nouvelArticle);
	majAffichage();
}
