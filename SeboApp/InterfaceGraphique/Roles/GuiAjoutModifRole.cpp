#include "GuiAjoutModifRole.h"
#include "ui_GuiAjoutModifRole.h"

GuiAjoutModifRole::GuiAjoutModifRole(Role *roleAModifier, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiAjoutModifRole();
	ui->setupUi(this);

	// r�cup�ration des �l�ments
	roleEnCours = roleAModifier;
	leSaisieLibelle = ui->leSaisieLibelle;
	btnAnnuler = ui->btnAnnuler;
	btnValider = ui->btnValider;

	if (roleEnCours != Q_NULLPTR)
	{
		// Modification d'un r�le
		setWindowTitle(trUtf8("Modification r�le"));
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

		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Cr�ation achev�e"), trUtf8("L'identifiant du nouveau r�le est : ") + QString::number(roleEnCours->getId()) + ManagerRole::getLastError());
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Erreur"), trUtf8("Probl�me lors de la cr�ation du r�le dans la base de donn�es") + ManagerRole::getLastError());
		int reponse = erreur->exec();
	}

	// �mission du signal de fin d��dition
	emit editionTerminee();

	// fermeture de la fen�tre
	close();
}

void GuiAjoutModifRole::modifierRole()
{
	roleEnCours->setLibelle(leSaisieLibelle->text());

	if (ManagerRole::modifRole(roleEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;
		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Modification termin�e"), trUtf8("La modification s'est bien pass�e."));
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Erreur"),trUtf8("Probl�me lors de la modification du r�le dans la base de donn�es :") + ManagerRole::getLastError());
		int reponse = erreur->exec();
	}

	// �mission du signal de fin d��dition
	emit editionTerminee();

	// fermeture de la fen�tre
	close();
}
