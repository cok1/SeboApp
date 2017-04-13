#include "GuiGestionRole.h"
#include "ui_GuiGestionRole.h"

GuiGestionRole::GuiGestionRole(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGestionRole();
	ui->setupUi(this);

	// Récupération des éléments
	tvRole = ui->tvRoles;
	btnAjouter = ui->btnAjouter;
	btnModifier = ui->btnModifier;
	btnSupprimer = ui->btnSupprimer;

	// initialisation de la table
	majTable();

	connect(btnAjouter, SIGNAL(clicked()), SLOT(ajouterRole()));
	connect(btnModifier, SIGNAL(clicked()), SLOT(modifierRole()));
	connect(btnSupprimer, SIGNAL(clicked()), SLOT(supprimerRole()));
}

GuiGestionRole::~GuiGestionRole()
{
	delete ui;
}

void GuiGestionRole::majTable()
{
	// Récupération de la connexion
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// Création du modèle à partir de la base de données
	QSqlTableModel *model = new QSqlTableModel();

	// Sélection de la table
	model->setTable("detailRole");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// récupération des données
	model->select();
	model->setHeaderData(0, Qt::Horizontal, trUtf8("Id"));
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé"));

	// Application du model sur la table
	tvRole->setModel(model);

	// Mise en forme de la table
	tvRole->hideColumn(0);
	tvRole->hideColumn(2);

	// Connexion des actions aux événements
	connect(tvRole->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majAffichage()));

	// Désactivation des boutons de suppression et de modification
	btnModifier->setEnabled(false);
	btnSupprimer->setEnabled(false);
}

void GuiGestionRole::ajouterRole()
{
	GuiAjoutModifRole *ajout = new GuiAjoutModifRole();
	connect(ajout, SIGNAL(editionTerminee()), SLOT(majTable()));
	ajout->show();
}

void GuiGestionRole::modifierRole()
{
	// récupération de la sélection
	QItemSelectionModel *select = tvRole->selectionModel();
	
	// récupération de l'identifiant du rôle
	QVariant var = select->selectedRows(0).first().data();
	int idRole = var.toInt();

	// récupération du nom du rôle
	var = select->selectedRows(1).first().data();
	QString libelleRole = var.toString();

	// affichage de la fenêtre de modification
	GuiAjoutModifRole *modif = new GuiAjoutModifRole(new Role(libelleRole, idRole));
	connect(modif, SIGNAL(editionTerminee()), SLOT(majTable()));
	modif->show();
}

void GuiGestionRole::supprimerRole()
{
	// récupération de la sélection
	QItemSelectionModel *select = tvRole->selectionModel();
	QVariant var = select->selectedRows(1).first().data();

	// récupération du nom du rôle
	QString libelleRole = var.toString();

	// Affichage d'une boîte de dialogue de confirmation
	QMessageBox *confirmation = new QMessageBox();
	confirmation->setIcon(QMessageBox::Question);
	confirmation->setWindowTitle(trUtf8("Confirmation de la suppression"));
	confirmation->setText(trUtf8("Suppression Rôle"));
	confirmation->setInformativeText(trUtf8("Êtes-vous sûr de vouloir supprimer le rôle ") + libelleRole + " ?");
	confirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	confirmation->setDefaultButton(QMessageBox::No);

	int reponse = confirmation->exec();

	// Traitement de la réponse
	if (reponse == QMessageBox::Yes)
	{
		// Récupération de l'identifiant de la catégorie à supprimer
		QVariant var = select->selectedRows(0).first().data();
		int idRole = var.toInt();

		// Affichage du résultat de la suppression
		if (ManagerRole::supRole(idRole))
		{
			QMessageBox *info = new QMessageBox(QMessageBox::Information, trUtf8("Suppression effectuée"), trUtf8("Le rôle ") + libelleRole + trUtf8(" a été supprimé!"));
			int rep = info->exec();
		}
		else
		{
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Problème lors de la suppression"), trUtf8("Le rôle ") + libelleRole + trUtf8(" n'a été supprimé!") + ManagerRole::getLastError());
			int rep = erreur->exec();
		}

		// Mise à jour de la table
		majTable();
	}
}

void GuiGestionRole::majAffichage()
{
	if (tvRole->currentIndex().row() != -1)
	{
		// Récupération de la sélection
		QItemSelectionModel *select = tvRole->selectionModel();
		QVariant var = select->selectedRows(2).first().data();

		btnSupprimer->setEnabled(var.toInt() == 0);
		btnModifier->setEnabled(true);
	}
	else
	{
		btnModifier->setEnabled(false);
		btnSupprimer->setEnabled(false);
	}
}
