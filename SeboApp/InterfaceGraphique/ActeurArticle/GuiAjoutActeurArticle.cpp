#include "GuiAjoutActeurArticle.h"
#include "ui_GuiAjoutActeurArticle.h"

GuiAjoutActeurArticle::GuiAjoutActeurArticle(int referenceArticle, QWidget *parent)
	: m_nReferenceArticle(referenceArticle), QWidget(parent)
{
	// Mise en place de l'interface
	ui = new Ui::GuiAjoutActeurArticle();
	ui->setupUi(this);

	// récupération des éléments
	cbFiltrerRole = ui->cbFiltrerRoles;
	tvActeursDispos = ui->tvActeursDispos;
	btnGererActeur = ui->btnGererActeurs;
	btnGererRole = ui->btnGererRoles;

	btnAjouter = ui->btnAjouter;
	btnRetirer = ui->btnRetirer;

	tvActeursLies = ui->tvActeursLies;
	btnValider = ui->btnValider;

	// Initialisation des modèles
	initModelActeursDispos();
	initModelActeursLies();

	// Initialisation des tables
	majTableActeurDispos();
	majTableActeurLies();

}

GuiAjoutActeurArticle::~GuiAjoutActeurArticle()
{
	delete ui;
}

void GuiAjoutActeurArticle::majTableActeurDispos()
{
	tvActeursDispos->setModel(modelActeursDispos);
}

void GuiAjoutActeurArticle::majTableActeurLies()
{
	tvActeursLies->setModel(modelActeursLies);

	tvActeursLies->hideColumn(0);
	tvActeursLies->hideColumn(1);
	tvActeursLies->hideColumn(2);
	tvActeursLies->hideColumn(4);
}

void GuiAjoutActeurArticle::initModelActeursDispos()
{
	// Récupération de la connexion à la base de données
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// récupérations des infos
	modelActeursDispos = new QSqlTableModel();
	modelActeursDispos->setTable("Acteur");
	modelActeursDispos->setEditStrategy(QSqlTableModel::OnManualSubmit);

	//modelActeursDispos->setFilter(QString("Reference <> '%1'").arg(m_nReferenceArticle));

	modelActeursDispos->select();
}

void GuiAjoutActeurArticle::initModelActeursLies()
{
	// Récupération de la connexion à la base de données
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// récupérations des infos
	modelActeursLies = new QSqlTableModel();
	modelActeursLies->setTable("DetailActeurArticle");
	modelActeursLies->setEditStrategy(QSqlTableModel::OnManualSubmit);

	modelActeursLies->setFilter(QString("Reference = '%1'").arg(m_nReferenceArticle));
	modelActeursLies->select();
}

void GuiAjoutActeurArticle::filtrerRole(QString texte)
{
}

void GuiAjoutActeurArticle::toutAfficher()
{
}

void GuiAjoutActeurArticle::ajouter()
{
}

void GuiAjoutActeurArticle::retirer()
{
}

void GuiAjoutActeurArticle::gererActeurs()
{
}

void GuiAjoutActeurArticle::gererRoles()
{
}

void GuiAjoutActeurArticle::valider()
{
}
