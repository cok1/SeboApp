#include "GuiGestionGenre.h"
#include "ui_GuiGestionGenre.h"

GuiGestionGenre::GuiGestionGenre(QWidget *parent)
	: QWidget(parent)
{
	// création de l'interface
	ui = new Ui::GuiGestionGenre();
	ui->setupUi(this);

	// récupération des éléments
	btnModifier = ui->btnModifier;
	btnAjouter = ui->btnAjouter;
	btnSupprimer = ui->btnSupprimer;
	tvGenre = ui->tvGenre;

	// mise à jour de la table
	majTable();

	// Connexions des actions
	connect(btnAjouter, SIGNAL(clicked()), SLOT(ajouterGenre()));
	connect(btnModifier, SIGNAL(clicked()), SLOT(modifierGenre()));
	connect(btnSupprimer, SIGNAL(clicked()), SLOT(supprimer()));
}

GuiGestionGenre::~GuiGestionGenre()
{
	delete ui;
}

void GuiGestionGenre::ajouterGenre()
{
	// Ouverture d'une fenêtre pour la saisie des infos
	GuiAjoutModifierGenre *ajout = new GuiAjoutModifierGenre();

	// connexion à l'événement de fin d'édition
	connect(ajout, SIGNAL(editionTerminee()), SLOT(majTable()));

	// affichage de la fenêtre
	ajout->show();
}

void GuiGestionGenre::modifierGenre()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvGenre->selectionModel();

	// récupération du genre
	QVariant var = select->selectedRows(1).first().data();
	QString libelleGenre = var.toString();

	// Récupération de l'identifiant du genre
	var = select->selectedRows(0).first().data();
	int idGenre = var.toInt();

	// Récupération de l'identifiant de la catégorie associée
	var = select->selectedRows(4).first().data();
	int idCategorie = var.toInt();

	// Ouverture d'une fenêtre pour la modification des infos
	GuiAjoutModifierGenre *modification = new GuiAjoutModifierGenre(new Genre(libelleGenre, idCategorie, idGenre));

	// connexion à la fin de création de la catégorie
	connect(modification, SIGNAL(editionTerminee()), this, SLOT(majTable()));

	// Affichage de la fenêtre
	modification->show();
}

void GuiGestionGenre::supprimer()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvGenre->selectionModel();

	// récupération du genre
	QVariant var = select->selectedRows(1).first().data();
	QString libelleGenre = var.toString();

	// récupération du nom de la catégorie
	var = select->selectedRows(2).first().data();
	QString libelleCategorie = var.toString();

	// Affichage d'une boîte de dialoque de confirmation
	QMessageBox *confirmation = new QMessageBox();
	confirmation->setIcon(QMessageBox::Question);
	confirmation->setWindowTitle(trUtf8("Confirmation de la suppression"));
	confirmation->setText(trUtf8("Suppression Genre"));
	confirmation->setInformativeText(trUtf8("Êtes-vous sûr de vouloir supprimer le genre ") + libelleGenre + trUtf8(" de la catégorie ") + libelleCategorie + " ?");
	confirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	confirmation->setDefaultButton(QMessageBox::No);

	int reponse = confirmation->exec();

	// Traitement de la réponse
	if (reponse == QMessageBox::Yes)
	{
		// Récupération de l'identifiant du genre à supprimer
		QVariant var = select->selectedRows(0).first().data();
		int idGenre = var.toInt();

		// Affichage du résultat de la suppression
		if (ManagerGenre::supGenre(idGenre))
		{
			QMessageBox *info = new QMessageBox(QMessageBox::Information, trUtf8("Suppression effectuée"), trUtf8("Le genre ") + libelleGenre + trUtf8(" de la catégorie ") + libelleCategorie + trUtf8(" a été supprimée!"));
			int rep = info->exec();
		}
		else
		{
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Problème lors de la suppression"), trUtf8("Le genre ") + libelleGenre + trUtf8(" de la catégorie ") + libelleCategorie +trUtf8(" n'a pas été supprimée!") + ManagerGenre::getLastError());
			int rep = erreur->exec();
		}

		// Mise à jour de la table
		majTable();
	}
}

void GuiGestionGenre::majAffichage()
{
	if (tvGenre->currentIndex().row() != -1)
	{

		// Récupération du modèle de sélection
		QItemSelectionModel *select = tvGenre->selectionModel();

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

void GuiGestionGenre::majTable()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *model = new QSqlTableModel();

	// sélection de la table à afficher
	model->setTable("DetailGenre");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// Ajustement des titres des colonnes
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));
	model->setHeaderData(2, Qt::Horizontal, trUtf8("Catégorie"));

	// Application du modèle à la table View
	tvGenre->setModel(model);

	// Masquage du header vertical(nom des lignes)
	tvGenre->verticalHeader()->hide();

	// Masquage de la première colonne
	tvGenre->hideColumn(0);
	tvGenre->hideColumn(3);
	tvGenre->hideColumn(4);

	// Ajustement de la taille des colonnes pour remplir l'espace dispo
	tvGenre->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

	// La table devient non éditable
	tvGenre->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// mode sélection ligne unique complète
	tvGenre->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	tvGenre->setSelectionBehavior(QAbstractItemView::SelectRows);

	// Alternance des couleurs des lignes
	tvGenre->setAlternatingRowColors(true);

	// Autorisation du tri
	tvGenre->setSortingEnabled(true);

	// affichage de la table
	tvGenre->show();

	// connexion des signaux et des slots
	connect(tvGenre->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majAffichage()));

	// désactivation des boutons supprimer et modifier
	btnModifier->setEnabled(false);
	btnSupprimer->setEnabled(false);
}