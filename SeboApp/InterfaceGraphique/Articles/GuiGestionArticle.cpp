#include "GuiGestionArticle.h"
#include "ui_GuiGestionArticle.h"

GuiGestionArticle::GuiGestionArticle(QWidget *parent)
	: QWidget(parent)
{
	// mise en place de l'interface graphique
	ui = new Ui::GuiGestionArticle();
	ui->setupUi(this);

	// r�cup�ration des �l�ments
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
	gvPhoto = ui->gvPhoto;

	// Boutons
	btnAjouter = ui->btnAjouter;
	btnModifier = ui->btnModifier;
	btnValider = ui->btnValider;
	btnAnnuler = ui->btnAnnuler;
	btnSupprimer = ui->btnSupprimer;

	majModel();

	majTable();

	gbDetail->setEnabled(false);
}

GuiGestionArticle::~GuiGestionArticle()
{
	delete ui;
}

void GuiGestionArticle::majTable()
{
	// r�cup�ration du mod�le
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
	// r�cup�ration de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	//r�cup�ration de la base de donn�es
	QSqlDatabase db = conn->getConnexion();

	// cr�ation du mod�le � partir de la base de donn�e
	model = new QSqlTableModel();

	model->setTable("DetailArticle");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// R�cup�ration des donn�es
	model->select();

	// tri des articles
	model->sort(0, Qt::AscendingOrder);
}

void GuiGestionArticle::majDetailArticle()
{
}

void GuiGestionArticle::suppFiltre()
{
}

void GuiGestionArticle::ajoutArticle()
{
}

void GuiGestionArticle::modifierArticle()
{
}

void GuiGestionArticle::supprimerArticle()
{
}

void GuiGestionArticle::annuler()
{
}

void GuiGestionArticle::valider()
{
}
