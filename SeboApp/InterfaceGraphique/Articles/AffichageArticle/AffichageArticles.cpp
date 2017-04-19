#include "AffichageArticles.h"
#include "ui_AffichageArticles.h"

AffichageArticles::AffichageArticles(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AffichageArticles();
	ui->setupUi(this);

	// Récupération des éléments
	cbFiltreCategorie = ui->cbFiltreCategorie;
	cbFiltreGenre = ui->cbFiltreGenre;
	leFiltreLibelle = ui->leFiltreLibelle;
	btnToutAfficher = ui->btnToutAfficher;
	tvArticle = ui->tvArticle;

	// Initialisation des composants
	majModel();
	majTableArticle();
	majCbFiltreCategorie();
	majCbFiltreGenre();

	// Écoute de la modification des filtres
	connect(cbFiltreCategorie, SIGNAL(currentTextChanged(QString)), SLOT(filtrerSaisieCategorie(QString)));
	connect(cbFiltreGenre, SIGNAL(currentTextChanged(QString)), SLOT(filtrerSaisieGenre(QString)));
	connect(btnToutAfficher, SIGNAL(clicked()), SLOT(supprimerFiltre()));

	// Écoute de l'édition de la ligne de libellé
	connect(leFiltreLibelle, SIGNAL(textChanged(const QString &)), SLOT(filtrerLibelle(QString)));
}

AffichageArticles::~AffichageArticles()
{
	delete ui;
}

void AffichageArticles::setSelectionnable(bool selectionnable)
{
	if (selectionnable)
	{
		tvArticle->setSelectionMode(QAbstractItemView::SingleSelection);
	}
	else
	{
		tvArticle->selectRow(-1);
		// Désactivation de la sélection sur la table
		tvArticle->setSelectionMode(QAbstractItemView::NoSelection);
	}
}

void AffichageArticles::setActif(bool actif)
{
	setEnabled(actif);
}

void AffichageArticles::majModel()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// création du modèle
	model = new QSqlTableModel();
	model->setTable("DetailArticle");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// tri des articles
	model->sort(0, Qt::AscendingOrder);
}

void AffichageArticles::majTableArticle()
{
	// Création d'un modèle de filtre
	proxyModel = new QSortFilterProxyModel();
	proxyModel->setSourceModel(model);

	// récupération du modèle
	tvArticle->setModel(proxyModel);

	// Gestion des largeur de colonnes
	tvArticle->setColumnWidth(0, 80);
	tvArticle->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tvArticle->setColumnWidth(5, 120);
	tvArticle->setColumnWidth(7, 120);
	tvArticle->setColumnWidth(9, 120);
	tvArticle->setColumnWidth(10, 90);
	tvArticle->horizontalHeader()->setStretchLastSection(false);

	// Masquage des colonnes non utilisées
	tvArticle->hideColumn(2);
	tvArticle->hideColumn(3);
	tvArticle->hideColumn(4);
	tvArticle->hideColumn(6);
	tvArticle->hideColumn(8);
	tvArticle->hideColumn(11);
	tvArticle->hideColumn(12);
	tvArticle->hideColumn(13);

	// Connexion du signal
	connect(tvArticle->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(selectionTable()));
}

void AffichageArticles::majCbFiltreCategorie(int idCategorie)
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Categorie");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	modelCb->select();

	// Remplissage de la comboBox filtre catégorie
	cbFiltreCategorie->setModel(modelCb);
	cbFiltreCategorie->setModelColumn(1);

	// aucune sélection par défaut
	cbFiltreCategorie->setCurrentIndex(-1);
}

void AffichageArticles::majCbFiltreGenre(int idCategorie)
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Genre");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	if (idCategorie != -1)
	{
		modelCb->setFilter(QString("IdCategorie = '%1'").arg(idCategorie));
	}

	// Récupération des données
	modelCb->select();

	// Remplissage de la comboBox de filtre du genre
	cbFiltreGenre->setModel(modelCb);
	cbFiltreGenre->setModelColumn(1);

	// aucune sélection par défaut
	cbFiltreGenre->setCurrentIndex(-1);
}

void AffichageArticles::filtrerSaisieGenre(QString texte)
{
	if (cbFiltreGenre->currentIndex() != -1)
	{
		// récupération de l'identifiant associé au genre
		int idCat = ManagerGenre::getGenreWithLibelle(texte)->getIdCategorie();
		cbFiltreCategorie->setCurrentText(ManagerCategorie::getCategorieWithId(idCat)->getLibelle());

		cbFiltreGenre->setCurrentText(texte);
	}
	// filtrage genre
	proxyModel->setFilterKeyColumn(7);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterRegExp(texte);
}

void AffichageArticles::filtrerSaisieCategorie(QString texte)
{
	// filtrage de
	if (cbFiltreCategorie->currentIndex() != -1)
	{
		// récupération de l'identifiant de la catégorie
		int idCat = ManagerCategorie::getCategorieWithLibelle(texte)->getId();

		majCbFiltreGenre(idCat);
	}

	// filtrage catégorie
	proxyModel->setFilterKeyColumn(5);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterRegExp(texte);
}

void AffichageArticles::filtrerLibelle(QString texte)
{
	// filtrage libellé
	proxyModel->setFilterKeyColumn(1);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
	proxyModel->setFilterRegExp(texte);
}

void AffichageArticles::supprimerFiltre()
{
	proxyModel->invalidate();
	leFiltreLibelle->clear();
	majCbFiltreGenre();
	majCbFiltreCategorie();
}

void AffichageArticles::selectionTable()
{
	// Déclaration
	int reference(-1);		// va stocker la référence de l'article sélectionné

	if (tvArticle->currentIndex().row() != -1)
	{
		// Récupération de la sélection
		QItemSelectionModel *select = tvArticle->selectionModel();

		// Récupération de la référence
		QVariant var = select->selectedRows(0).first().data();
		reference = var.toInt();
	}

	emit choixArticle(reference);
}

