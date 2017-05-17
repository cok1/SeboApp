#include "GuiAjoutActeurArticle.h"
#include "ui_GuiAjoutActeurArticle.h"

GuiAjoutActeurArticle::GuiAjoutActeurArticle(int referenceArticle, QWidget *parent)
	: m_nReferenceArticle(referenceArticle), QWidget(parent)
{
	// Mise en place de l'interface
	ui = new Ui::GuiAjoutActeurArticle();
	ui->setupUi(this);

	QString libelle = ManagerArticle::getLibelle(m_nReferenceArticle);
	setWindowTitle("Modification des acteurs de l'article : " + libelle);

	// r�cup�ration des �l�ments
	cbFiltrerRole = ui->cbFiltrerRoles;
	tvActeursDispos = ui->tvActeursDispos;
	btnGererActeur = ui->btnGererActeurs;
	btnGererRole = ui->btnGererRoles;

	btnAjouter = ui->btnAjouter;
	btnRetirer = ui->btnRetirer;

	tvActeursLies = ui->tvActeursLies;
	btnValider = ui->btnValider;
	
	// Initialisation des tables
	majTableActeurDispos();
	majTableActeurLies();

	// connexion des signaux et des slots
	connect(btnGererActeur, SIGNAL(clicked()), SLOT(gererActeurs()));
	connect(btnGererRole, SIGNAL(clicked()), SLOT(gererRoles()));
	connect(btnAjouter, SIGNAL(clicked()), SLOT(ajouter()));
	connect(btnRetirer, SIGNAL(clicked()), SLOT(retirer()));
}

GuiAjoutActeurArticle::~GuiAjoutActeurArticle()
{
	delete ui;
}

void GuiAjoutActeurArticle::majTableActeurDispos()
{
	// initialisation du mod�le des acteurs dispos
	initModelActeursDispos();

	// ajout du mod�le
	tvActeursDispos->setModel(modelActeursDispos);

	tvActeursDispos->hideColumn(0);
	tvActeursDispos->hideColumn(3);
	tvActeursDispos->hideColumn(4);
}

void GuiAjoutActeurArticle::majTableActeurLies()
{
	// initialisation du mod�le des acteurs li�s
	initModelActeursLies();

	// ajout du mod�le
	tvActeursLies->setModel(modelActeursLies);

	tvActeursLies->hideColumn(0);
	tvActeursLies->hideColumn(1);
	tvActeursLies->hideColumn(2);
	tvActeursLies->hideColumn(4);
}

void GuiAjoutActeurArticle::initModelActeursDispos()
{
	// R�cup�ration de la connexion � la base de donn�es
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// r�cup�rations des infos
	modelActeursDispos = new QSqlTableModel();
	modelActeursDispos->setTable("DetailActeur");
	modelActeursDispos->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// on enl�ve les acteurs d�j� pr�sent sur l'article
	modelActeursDispos->setFilter(QString("Id not in (Select IdActeur from DetailActeurArticle where reference = '%1')").arg(m_nReferenceArticle));

	modelActeursDispos->select();
}

void GuiAjoutActeurArticle::initModelActeursLies()
{
	// R�cup�ration de la connexion � la base de donn�es
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// r�cup�rations des infos
	modelActeursLies = new QSqlTableModel();
	modelActeursLies->setTable("DetailActeurArticle");
	modelActeursLies->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// on r�cup�re uniquement les infos de l'article que l'on �dite
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
	// r�cup�ration des id des lignes s�lectionn�es
	for each (QModelIndex ligne in tvActeursDispos->selectionModel()->selectedRows())
	{
		if (!ManagerActeurArticle::addActeurArticle(ligne.data().toInt(), m_nReferenceArticle))
		{
			// r�cup�ration du nom de l'acteur
			//tvActeursDispos->model.row(ligne.row())

			// message d'erreur
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Probl�me lors de l'ajout de l'acteur"), trUtf8("L'acteur ") + ligne.row() + trUtf8(" n'a pu �tre ajout� � l'article!") + ManagerActeurArticle::getLastError());
			int rep = erreur->exec();
		}
	}

	// mise � jour des tables
	majTableActeurDispos();
	majTableActeurLies();
}

void GuiAjoutActeurArticle::retirer()
{
	// r�cup�ration des id des lignes s�lectionn�es
	for each (QModelIndex ligne in tvActeursLies->selectionModel()->selectedRows(2))
	{
		if (!ManagerActeurArticle::supActeurArticle(ligne.data().toInt(), m_nReferenceArticle))
		{
			// message d'erreur
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Probl�me lors de la suppression de l'acteur"), trUtf8("L'acteur ") + ligne.row() + trUtf8(" n'a pu �tre retir� � l'article!") + ManagerActeurArticle::getLastError());
			int rep = erreur->exec();
		}
	}

	// mise � jour des tables
	majTableActeurDispos();
	majTableActeurLies();
}

void GuiAjoutActeurArticle::gererActeurs()
{
	GuiGestionActeur *gestionActeur = new GuiGestionActeur();
	gestionActeur->setWindowModality(Qt::ApplicationModal);
	gestionActeur->show();

	// mise � jour de la table � la sortie de la fen�tre gestionActeur
	connect(gestionActeur, SIGNAL(editionTerminee()), SLOT(majTableActeurDispos()));
}

void GuiAjoutActeurArticle::gererRoles()
{
	GuiGestionRole *gestionRole = new GuiGestionRole();
	gestionRole->setWindowModality(Qt::ApplicationModal);
	gestionRole->show();

	// mise � jour de la table � la sortie de la fen�tre gestionRole
	connect(gestionRole, SIGNAL(editionTerminee()), SLOT(majTableActeurDispos()));
}

void GuiAjoutActeurArticle::valider()
{
	// TODO : Sauvegarder les changements
	close();
}