#include "GuiAjoutModifierGenre.h"
#include "ui_GuiAjoutModifierGenre.h"

GuiAjoutModifierGenre::GuiAjoutModifierGenre(Genre *genreAModifier, QWidget *parent)
	: QWidget(parent)
{
	// mise en place de l'interface
	ui = new Ui::GuiAjoutModifierGenre();
	ui->setupUi(this);

	// Récupération des éléments
	btnValider = ui->btnValider;
	leLibelle = ui->leSaisieLibelle;
	cbCategorie = ui->cbCategorie;
	genreEnCours = genreAModifier;

	initCombo();

	if (genreEnCours != Q_NULLPTR)
	{
		setWindowTitle("Modification d'un genre");
		leLibelle->setText(genreEnCours->getLibelle());

		// récupération de la catégorie
		shared_ptr<Categorie> categorie = ManagerCategorie::getCategorieWithId(genreEnCours->getIdCategorie());

		if (categorie != nullptr)
		{
			cbCategorie->setCurrentText(categorie->getLibelle());
		}

		// Connexion su click sur le bouton valider à la modification d'un genre
		connect(btnValider, SIGNAL(clicked()), SLOT(modificationGenre()));
	}
	else
	{
		setWindowTitle("Création d'un genre");

		// connexion d'un click sur le bouton valider à la création d'un genre
		connect(btnValider, SIGNAL(clicked()), SLOT(creationGenre()));
	}
}

GuiAjoutModifierGenre::~GuiAjoutModifierGenre()
{
	delete ui;
}

void GuiAjoutModifierGenre::creationGenre()
{
	// Récupération de l'id de la catégorie
	QVariant var = cbCategorie->model()->index(cbCategorie->currentIndex(), 0).data();
	int idCat = var.toInt();

	genreEnCours = new Genre(leLibelle->text(), idCat);

	// Essai de création du genre grâce au manager
	if (ManagerGenre::addGenre(genreEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;
		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Création terminée"), trUtf8("L'identifiant du nouveau genre est : ") + QString::number(genreEnCours->getId())+ " " + ManagerGenre::getLastError());
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Problème lors de la création du nouveau genre dans la base de données"), ManagerCategorie::getLastError());
		int reponse = erreur->exec();
	}

	// Émission du signal de fin d’édition
	emit editionTerminee();

	// fermeture de la fenêtre
	close();
}

void GuiAjoutModifierGenre::initCombo()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	model->setTable("Categorie");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// remplissage de la comboBox
	cbCategorie->setModel(model);
	cbCategorie->setModelColumn(1);
}

void GuiAjoutModifierGenre::modificationGenre()
{
	// récupération des infos saisies
	genreEnCours->setLibelle(leLibelle->text());

	// Récupération de l'id de la catégorie
	QVariant var = cbCategorie->model()->index(cbCategorie->currentIndex(), 0).data();
	int idCat = var.toInt();
	genreEnCours->setIdCategorie(idCat);

	// Essai de modification du genre grâce au manager
	if (ManagerGenre::modifGenre(genreEnCours))
	{
		// Affichage d'un message d'information
		QMessageBox *info;
		info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Modification terminée"), trUtf8("La modification s'est bien passée."));
		int reponse = info->exec();
	}
	else
	{
		// Affichage d'un message d'erreur
		QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Problème lors de la modification de la base de données"), ManagerCategorie::getLastError());
		int reponse = erreur->exec();
	}

	// Émission du signal de fin d’édition
	emit editionTerminee();

	// fermeture de la fenêtre
	close();
}

