#include "GuiGenre.h"
#include "ui_GuiGenre.h"

GuiGenre::GuiGenre(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGenre();
	ui->setupUi(this);

	// Récupération du pointeur vers l'instance unique de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	// mise à jour de la table
	majTable();
}

GuiGenre::~GuiGenre()
{
	delete ui;
}

void GuiGenre::majTable()
{
	// récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	//récupération de la base de données
	QSqlDatabase db = conn->getConnexion();

	QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
	//QSqlTableModel *model = new QSqlTableModel();

	model->setTable("Genre");

	model->setRelation(2, QSqlRelation("Categorie", "IdCategorie", "LibelleCategorie"));

	model->select();

	ui->view->setModel(model);
}
