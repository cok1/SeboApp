#include "GuiAjoutModifRole.h"
#include "ui_GuiAjoutModifRole.h"

GuiAjoutModifRole::GuiAjoutModifRole(Role *roleAModifier, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiAjoutModifRole();
	ui->setupUi(this);

	// récupération des éléments
	roleEnCours = roleAModifier;
	leSaisieLibelle = ui->leSaisieLibelle;
	btnAnnuler = ui->btnAnnuler;
	btnValider = ui->btnValider;

	if (roleEnCours != Q_NULLPTR)
	{
		// Modification d'un rôle
		setWindowTitle(trUtf8("Modification rôle"));
		ui->leSaisieLibelle->setText(roleEnCours->getLibelle());
		connect(btnValider, SIGNAL(clicked()), SLOT(modifierRole()));
	}
	else
	{
		connect(btnValider, SIGNAL(clicked()), SLOT(creerRole()));
	}
}

GuiAjoutModifRole::~GuiAjoutModifRole()
{
	delete ui;
}

void GuiAjoutModifRole::creerRole()
{
	roleEnCours = new Role(leSaisieLibelle->text());
	if (ManagerRole::addRole(roleEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;

		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Création achevée"), trUtf8("L'identifiant du nouveau rôle est : ") + QString::number(roleEnCours->getId()) + ManagerRole::getLastError());
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Erreur"), trUtf8("Problème lors de la création du rôle dans la base de données") + ManagerRole::getLastError());
		int reponse = erreur->exec();
	}

	// Émission du signal de fin d’édition
	emit editionTerminee();

	// fermeture de la fenêtre
	close();
}

void GuiAjoutModifRole::modifierRole()
{
	roleEnCours->setLibelle(leSaisieLibelle->text());

	if (ManagerRole::modifRole(roleEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;
		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Modification terminée"), trUtf8("La modification s'est bien passée."));
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Erreur"),trUtf8("Problème lors de la modification du rôle dans la base de données :") + ManagerRole::getLastError());
		int reponse = erreur->exec();
	}

	// Émission du signal de fin d’édition
	emit editionTerminee();

	// fermeture de la fenêtre
	close();
}
