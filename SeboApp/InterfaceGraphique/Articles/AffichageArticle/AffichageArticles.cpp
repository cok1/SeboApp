#include "AffichageArticles.h"
#include "ui_AffichageArticles.h"

AffichageArticles::AffichageArticles(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AffichageArticles();
	ui->setupUi(this);

	// R�cup�ration des �l�ments
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

	// �coute de la modification des filtres
	connect(cbFiltreCategorie, SIGNAL(currentTextChanged(QString)), SLOT(filtrerSaisieCategorie(QString)));
	connect(cbFiltreGenre, SIGNAL(currentTextChanged(QString)), SLOT(filtrerSaisieGenre(QString)));
	connect(btnToutAfficher, SIGNAL(clicked()), SLOT(supprimerFiltre()));

	// �coute de l'�dition de la ligne de libell�
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
		// D�sactivation de la s�lection sur la table
		tvArticle->setSelectionMode(QAbstractItemView::NoSelection);
	}
}

void AffichageArticles::setActif(bool actif)
{
	setEnabled(actif);
}

void AffichageArticles::majModel()
{
	// R�cup�ration de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// cr�ation du mod�le
	model = new QSqlTableModel();
	model->setTable("DetailArticle");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// R�cup�ration des donn�es
	model->select();

	// tri des articles
	model->sort(0, Qt::AscendingOrder);
}

void AffichageArticles::majTableArticle()
{
	// Cr�ation d'un mod�le de filtre
	proxyModel = new QSortFilterProxyModel();
	proxyModel->setSourceModel(model);

	// r�cup�ration du mod�le
	tvArticle->setModel(proxyModel);

	// Gestion des largeur de colonnes
	tvArticle->setColumnWidth(0, 80);
	tvArticle->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tvArticle->setColumnWidth(5, 120);
	tvArticle->setColumnWidth(7, 120);
	tvArticle->setColumnWidth(9, 120);
	tvArticle->setColumnWidth(10, 90);
	tvArticle->horizontalHeader()->setStretchLastSection(false);

	// Masquage des colonnes non utilis�es
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
	// R�cup�ration de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// cr�ation du mod�le � partir de la base de donn�e
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Categorie");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// R�cup�ration des donn�es
	modelCb->select();

	// Remplissage de la comboBox filtre cat�gorie
	cbFiltreCategorie->setModel(modelCb);
	cbFiltreCategorie->setModelColumn(1);

	// aucune s�lection par d�faut
	cbFiltreCategorie->setCurrentIndex(-1);
}

void AffichageArticles::majCbFiltreGenre(int idCategorie)
{
	// R�cup�ration de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// cr�ation du mod�le � partir de la base de donn�e
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Genre");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	if (idCategorie != -1)
	{
		modelCb->setFilter(QString("IdCategorie = '%1'").arg(idCategorie));
	}

	// R�cup�ration des donn�es
	modelCb->select();

	// Remplissage de la comboBox de filtre du genre
	cbFiltreGenre->setModel(modelCb);
	cbFiltreGenre->setModelColumn(1);

	// aucune s�lection par d�faut
	cbFiltreGenre->setCurrentIndex(-1);
}

void AffichageArticles::filtrerSaisieGenre(QString texte)
{
	if (cbFiltreGenre->currentIndex() != -1)
	{
		// r�cup�ration de l'identifiant associ� au genre
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
		// r�cup�ration de l'identifiant de la cat�gorie
		int idCat = ManagerCategorie::getCategorieWithLibelle(texte)->getId();

		majCbFiltreGenre(idCat);
	}

	// filtrage cat�gorie
	proxyModel->setFilterKeyColumn(5);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterRegExp(texte);
}

void AffichageArticles::filtrerLibelle(QString texte)
{
	// filtrage libell�
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
	// D�claration
	int reference(-1);		// va stocker la r�f�rence de l'article s�lectionn�

	if (tvArticle->currentIndex().row() != -1)
	{
		// R�cup�ration de la s�lection
		QItemSelectionModel *select = tvArticle->selectionModel();

		// R�cup�ration de la r�f�rence
		QVariant var = select->selectedRows(0).first().data();
		reference = var.toInt();
	}

	emit choixArticle(reference);
}

