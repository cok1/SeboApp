#include "GuiGestionCategorie.h"
#include "ui_GuiGestionCategorie.h"


GuiGestionCategorie::GuiGestionCategorie(QWidget *parent)
	: QWidget(parent)
{
	// Création de l'interface
	ui = new Ui::GuiGestionCategorie();
	ui->setupUi(this);

	// Récupération des éléments
	btnAjouter = ui->btnAjouter;
	btnModifier = ui->btnModifier;
	btnSupprimer = ui->btnSupprimer;
	tvCategorie = ui->tvCategories;

	// mise à jour de la table
	majTable();

	// Connexion des actions
	connect(btnAjouter, SIGNAL(clicked()), SLOT(ajouterCategorie()));
	connect(btnModifier, SIGNAL(clicked()), SLOT(modifierCategorie()));
	connect(btnSupprimer, SIGNAL(clicked()), SLOT(supprimerCategorie()));
}

GuiGestionCategorie::~GuiGestionCategorie()
{
	delete ui;
}

//bool GuiGestionCategorie::close()
//{
//	bool resultat = QWidget::close();
//	emit(editionTerminee());
//	return resultat;
//}

void GuiGestionCategorie::majTable()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	// sélection de la table à afficher
	model->setTable("DetailCategorie");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Ajustement des titres des colonnes
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Tva"));

	// Application du modèle à la table View
	tvCategorie->setModel(model);

	// Masquage du header vertical(nom des lignes)
	tvCategorie->verticalHeader()->hide();

	// Masquage de la première colonne
	tvCategorie->hideColumn(0);
	tvCategorie->hideColumn(3);

	// Ajustement de la taille des colonnes pour remplir l'espace dispo
	tvCategorie->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

	// La table devient non éditable
	tvCategorie->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// mode sélection ligne unique complète
	tvCategorie->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	tvCategorie->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Alternance des couleurs des lignes
	tvCategorie->setAlternatingRowColors(true);

	// Autorisation du tri
	tvCategorie->setSortingEnabled(true);

	// affichage de la table
	tvCategorie->show();

	// connexion des signaux et des slots
	connect(tvCategorie->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majAffichage()));

	// désactivation des boutons supprimer et modifier
	btnModifier->setEnabled(false);
	btnSupprimer->setEnabled(false);
}

void GuiGestionCategorie::majAffichage()
{
	if (tvCategorie->currentIndex().row() != -1)
	{

		// Récupération du modèle de sélection
		QItemSelectionModel *select = tvCategorie->selectionModel();

		// Récupération de la sélection
		QVariant var = select->selectedRows(3).first().data(); // sélection de la valeur de la première ligne 3ème colonne

		// Affichage en fonction de la valeur stockée
		btnSupprimer->setEnabled(var.toInt() == 0);

		btnModifier->setEnabled(true);
	}
	else
	{
		btnModifier->setEnabled(false);
		btnSupprimer->setEnabled(false);
	}
}

void GuiGestionCategorie::ajouterCategorie()
{
	// Ouverture d'une fenêtre pour la saisie des infos
	GuiAjoutModifCategorie *ajout = new GuiAjoutModifCategorie();

	// connexion à la fin de création de la catégorie
	connect(ajout, SIGNAL(editionTerminee()),this, SLOT(majTable()));

	// affichage de la fenêtre
	ajout->show();
}

void GuiGestionCategorie::modifierCategorie()
{
	// récupération des infos sur la sélection
	// Récupération de la sélection
	QItemSelectionModel *select = tvCategorie->selectionModel();

	QVariant var = select->selectedRows(0).first().data();
	int id = var.toInt();

	var = select->selectedRows(1).first().data();
	QString libelle = var.toString();

	var = select->selectedRows(2).first().data();
	double tva = var.toDouble();

	// Ouverture d'une fenêtre pour la saisie des infos
	GuiAjoutModifCategorie *modification = new GuiAjoutModifCategorie(new Categorie(libelle, tva, id));

	// connexion à la fin de création de la catégorie
	connect(modification, SIGNAL(editionTerminee()), this, SLOT(majTable()));

	// Affichage de la fenêtre
	modification->show();
}

void GuiGestionCategorie::supprimerCategorie()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvCategorie->selectionModel();
	QVariant var = select->selectedRows(1).first().data();

	// récupération du nom de la catégorie
	QString nomCategorie = var.toString();

	// Affichage d'une boîte de dialoque de confirmation
	QMessageBox *confirmation = new QMessageBox();// = new QMessageBox(QMessageBox::Information, "Veuillez confirmer.", "Êtes-vous sûr de vouloir supprimer la catégorie " + nomCategorie + "?", QMessageBox::Yes | QMessageBox::No);
	confirmation->setIcon(QMessageBox::Question);
	confirmation->setWindowTitle(trUtf8("Confirmation de la suppression"));
	confirmation->setText(trUtf8("Suppression Catégorie"));
	confirmation->setInformativeText(trUtf8("Êtes-vous sûr de vouloir supprimer la catégorie ") + nomCategorie + " ?");
	confirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	confirmation->setDefaultButton(QMessageBox::No);

	int reponse = confirmation->exec();
	
	// Traitement de la réponse
	if (reponse == QMessageBox::Yes)
	{
		// Récupération de l'identifiant de la catégorie à supprimer
		QVariant var = select->selectedRows(0).first().data();
		int idCat = var.toInt();

		// Affichage du résultat de la suppression
		if (ManagerCategorie::supCategorie(idCat))
		{
			QMessageBox *info = new QMessageBox(QMessageBox::Information, trUtf8("Suppression effectuée"), trUtf8("La catégorie ") + nomCategorie + trUtf8(" a été supprimée!"));
			int rep = info->exec();
		}
		else
		{
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Problème lors de la suppression"), trUtf8("La catégorie ") + nomCategorie + trUtf8(" n'a été supprimée!") + ManagerCategorie::getLastError());
			int rep = erreur->exec();
		}

		// Mise à jour de la table
		majTable();
	}
}

