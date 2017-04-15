#include "GuiGestionPhoto.h"
#include "ui_GuiGestionPhoto.h"

GuiGestionPhoto::GuiGestionPhoto(QString url, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGestionPhoto();
	ui->setupUi(this);

	// Récupération des éléments
	btnValider = ui->btnValider;
	btnAnnuler = ui->btnAnnuler;
	leSaisieUrl = ui->leSaisieUrl;

	// affichage de l'url existante
	leSaisieUrl->setText(url);

	// Connexion des signaux
	connect(btnValider, SIGNAL(clicked()), SLOT(btnClickValider()));
	connect(btnAnnuler, SIGNAL(clicked()), SLOT(btnClickAnnuler()));
}

GuiGestionPhoto::~GuiGestionPhoto()
{
	delete ui;
}

void GuiGestionPhoto::btnClickValider()
{
	emit editionTerminee(leSaisieUrl->text());
	close();
}

void GuiGestionPhoto::btnClickAnnuler()
{
	emit editionTerminee("");
	close();
}

//QString GuiGestionPhoto::editionTerminee(QString url)
//{
//	return url;
//}
