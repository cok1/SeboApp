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
	btnCharger = ui->btnChargerPhoto;
	leSaisieUrl = ui->leSaisieUrl;
	photo = ui->lblPhoto;

	// affichage de l'url existante
	leSaisieUrl->setText(url);

	if (!url.isEmpty())
		btnClickCharger();

	// Connexion des signaux
	connect(btnCharger, SIGNAL(clicked()), SLOT(btnClickCharger()));
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

void GuiGestionPhoto::btnClickCharger()
{
	// récupération de l'url saisie
	QUrl imageUrl(leSaisieUrl->text());

	// lancement du téléchargement
	m_pImgCtrl = new FileDownloader(imageUrl, this);
	photo->setText("Chargement de l'image...");

	// connexion au signal de fin de téléchargement
	connect(m_pImgCtrl, SIGNAL(downloaded()), SLOT(chargerPhoto()));
}

void GuiGestionPhoto::chargerPhoto()
{
	// Récupération de l'image à partir du téléchargement
	QPixmap image;
	image.loadFromData(m_pImgCtrl->downloadedData());

	// Adaptation de l'image au cadre
	if (image.height() < image.width())
		image = image.scaledToWidth(570, Qt::SmoothTransformation);
	else
		image = image.scaledToHeight(550, Qt::SmoothTransformation);

	// affichage de l'image
	photo->setPixmap(image);

	//photo->show();

	//photo->setText("Ok!");

	//photo->setScaledContents(true);
}

