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

	essaiRequeteModel();

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
	m_mModel->setRelation(5, QSqlRelation("Genre", "IdGenre", "LibelleGenre"));
	m_mModel->setRelation(7, QSqlRelation("Fournisseur", "IdFournisseur", "NomFournisseur"));

	// Récupération des données
	m_mModel->select();

	m_mModel->sort(0, Qt::AscendingOrder);

	// Modification des titres des colonnes
	m_mModel->setHeaderData(0, Qt::Horizontal, trUtf8("Référence"));
	m_mModel->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	m_mModel->setHeaderData(2, Qt::Horizontal, trUtf8("Prix"));
	m_mModel->setHeaderData(3, Qt::Horizontal, trUtf8("PhotoArticle"));
	m_mModel->setHeaderData(4, Qt::Horizontal, trUtf8("DescriptionArticle"));
	m_mModel->setHeaderData(5, Qt::Horizontal, trUtf8("Genre"));
	m_mModel->setHeaderData(6, Qt::Horizontal, trUtf8("Prix Achat"));
	m_mModel->setHeaderData(7, Qt::Horizontal, trUtf8("Fournisseur"));
}

void EssaiGuiArticle::majAffichage()
{
	// récupération des index des comboBosx pour pouvoir les repositionné
	m_nIndexGenre = ui.cbGenre->currentIndex();
	m_nIndexFournisseur = ui.cbFournisseur->currentIndex();

	// Réinitialisation de l'affichage de chaque élément
	initModel();
	initTable();
	initCombo();
}

void EssaiGuiArticle::initCombo()
{
	// initialisation de la comboBox de sélection du genre
	ui.cbGenre->setModel(m_mModel->relationModel(5));
	ui.cbGenre->setModelColumn(m_mModel->relationModel(5)->fieldIndex("LibelleGenre"));

	// repositionnement de l'index
	if (m_nIndexGenre > -1 && m_nIndexGenre < ui.cbGenre->count())
	{
		ui.cbGenre->setCurrentIndex(m_nIndexGenre);
	}

	// initialisation de la comboBox de sélection du fournisseur
	ui.cbFournisseur->setModel(m_mModel->relationModel(7));
	ui.cbFournisseur->setModelColumn(m_mModel->relationModel(7)->fieldIndex("NomFournisseur"));

	// repositionnement de l'index
	if (m_nIndexFournisseur > -1 && m_nIndexFournisseur < ui.cbFournisseur->count())
	{
		ui.cbFournisseur->setCurrentIndex(m_nIndexFournisseur);
	}
}

void EssaiGuiArticle::essaiQVariantArticle()
{
	Article article = Article("essai", 12.3f, "", "", 1, 4.3f, 1, false);
	QVariant var;
	var.setValue(article);

	Article article2;
	if (var.canConvert<Article>())
	{
		article2 = var.value<Article>();
	}
	else
	{
		article2 = Article("non", 0.0f, "", "", 0, 0.0f, 0, false);
	}

	article2.setLibelle("change");

	QMessageBox *essai = new QMessageBox(QMessageBox::Icon::Information, "essai", "article 2 : " + article2.getLibelle() + "  ; article 1 : " + article.getLibelle() + "      " + QString::number(article2.getIdFournisseur()));
	int reponse = essai->exec();
}

void EssaiGuiArticle::essaiRequeteModel()
{
	//// récupération de la connexion
	//std::shared_ptr<Connexion> conn = Connexion::getInstance();

	////récupération de la base de données
	//QSqlDatabase db = conn->getConnexion();

	//QSqlTableModel model;
	//model.setTable("Article");
	//model.select();
	//QString libelle = model.record(1).value("LibelleArticle").toString();
	//m_mModel->setSort(1, Qt::SortOrder::DescendingOrder);

	QString libelle = m_mModel->record(0).value("LibelleArticle").toString();
	
	QMessageBox *essai = new QMessageBox(QMessageBox::Icon::Information, "essai", libelle);
	int reponse = essai->exec();
	
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

	// Couleur des lignes alternées
	ui.tvArticles->setAlternatingRowColors(true);

	// Triage des données activées
	ui.tvArticles->setSortingEnabled(true);

	// Affichage de la table
	ui.tvArticles->show();
}

void EssaiGuiArticle::creerArticle()
{	
	// Récupération des infos
	QString nomFournisseur = ui.cbFournisseur->currentText();
	QString libelleGenre = ui.cbGenre->currentText();

	// Récupération des identifiants 
	int idFournisseur = ManagerFournisseur::getIdFournisseur(nomFournisseur);
	//int idGenre = ManagerGenre::getIdGenre(libelleGenre);
	int idGenre = -1;

	if (idFournisseur != -1 && idGenre != -1)
	{
		// Création et ajout de l'article dans la base de données
		Article nouvelArticle = Article(ui.leSaisieLibelle->text(), (float)ui.spPrixVente->value(), QString(""), QString(""), idGenre, (float)ui.spPrixFournisseur->value(), idFournisseur, ui.ckReapprovisionnable->isChecked());
		ManagerArticle::addArticle(nouvelArticle);
	}
	else
	{
		QString messageErreur;
		if (idFournisseur == -1)
		{
			messageErreur = "Le fournisseur fourni n'existe pas dans la base de données!";
		}
		else
		{
			messageErreur = "Le genre fourni n'existe pas dans la base de données!";
		}
		unique_ptr<QMessageBox> erreur = make_unique<QMessageBox>(QMessageBox::Icon::Critical, trUtf8("Création de l'article impossible!"), messageErreur);
		int reponse = erreur->exec();
	}

	// mise à jour de l'affichage
	majAffichage();
}

