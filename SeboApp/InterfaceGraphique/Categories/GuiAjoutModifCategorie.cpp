#include "GuiAjoutModifCategorie.h"
#include "ui_GuiAjoutModifCategorie.h"

GuiAjoutModifCategorie::GuiAjoutModifCategorie(Categorie *categorieAModifier, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiAjoutModifCategorie();
	ui->setupUi(this);

	// Récupération des éléments
	btnValider = ui->btnValider;
	leSaisieLibelle = ui->leSaisieLibelle;
	spSaisieTaux = ui->spTauxTva;
	categorieEnCours = categorieAModifier;

	if (categorieEnCours != Q_NULLPTR)
	{
		leSaisieLibelle->setText(categorieEnCours->getLibelle());
		spSaisieTaux->setValue(categorieEnCours->getTauxTva());

		// Connexion signal et slot
		connect(btnValider, SIGNAL(clicked()), SLOT(modifier()));
	}
	else
	{
		// Connexion signal et slot
		connect(btnValider, SIGNAL(clicked()), SLOT(creer()));
	}
}

GuiAjoutModifCategorie::~GuiAjoutModifCategorie()
{
	delete ui;
}

void GuiAjoutModifCategorie::modifier()
{
	categorieEnCours->setLibelle(leSaisieLibelle->text());
	categorieEnCours->setTauxTva(spSaisieTaux->value());

	// Essai de création de la catégorie grâce au manager
	if (ManagerCategorie::modifCategorie(categorieEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;
		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Modification terminée"), trUtf8("La modification s'est bien passée."));
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Problème lors de la création de la base de données"), ManagerCategorie::getLastError());
		int reponse = erreur->exec();
	}

	// Émission du signal de fin d’édition
	emit editionTerminee();

	// fermeture de la fenêtre
	close();
}

void GuiAjoutModifCategorie::creer()
{
	categorieEnCours = new Categorie(leSaisieLibelle->text(), spSaisieTaux->value());

	// Essai de création de la catégorie grâce au manager
	if (ManagerCategorie::addCategorie(categorieEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;

		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Création achevée"), trUtf8("L'identifiant de la nouvelle catégorie est : ") + QString::number(categorieEnCours->getId()));
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Problème lors de la création de la base de données"), ManagerCategorie::getLastError());
		int reponse = erreur->exec();
	}

	// Émission du signal de fin d’édition
	emit editionTerminee();

	// fermeture de la fenêtre
	close();
}