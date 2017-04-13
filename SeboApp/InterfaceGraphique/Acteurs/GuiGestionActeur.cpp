#include "GuiGestionActeur.h"
#include "ui_GuiGestionActeur.h"



GuiGestionActeur::GuiGestionActeur(QWidget *parent)
	: QWidget(parent)
{
	// création de l'interface
	ui = new Ui::GuiGestionActeur();
	ui->setupUi(this);

	// récupération des éléments
	btnModifier = ui->btnModifier;
	btnAjouter = ui->btnAjouter;
	btnSupprimer = ui->btnSupprimer;
	tvActeur = ui->tvActeur;
	btnToutAfficher = ui->btnToutAfficher;
	cbFiltreRole = ui->cbFiltreRole;

	// mise à jour de la table
	majTable();
	majComboFiltre();

	// Connexions des actions
	connect(btnAjouter, SIGNAL(clicked()), SLOT(ajouterActeur()));
	connect(btnModifier, SIGNAL(clicked()), SLOT(modifierActeur()));
	connect(btnSupprimer, SIGNAL(clicked()), SLOT(supprimer()));
	connect(btnToutAfficher, SIGNAL(clicked()), SLOT(toutAfficher()));
	connect(cbFiltreRole, SIGNAL(currentIndexChanged(QString)), SLOT(filtrerRole(QString)));
}

GuiGestionActeur::~GuiGestionActeur()
{
	delete ui;
}

void GuiGestionActeur::majTable()
{
	// Récupération de la connexion
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// récupération du modèle à partir de la base de données
	QSqlTableModel *model = new QSqlTableModel();
	model->setTable("DetailActeur");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	proxy = new QSortFilterProxyModel(model);
	proxy->setSourceModel(model);

	// Affichage du modèle dans la table
	tvActeur->setModel(proxy);
	tvActeur->hideColumn(0);
	tvActeur->hideColumn(3);
	tvActeur->hideColumn(4);
	tvActeur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	// connexion des signaux et des slots
	connect(tvActeur->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majAffichage()));

	majAffichage();
}

void GuiGestionActeur::ajouterActeur()
{
	// Ouverture de la fenêtre de saisie des infos
	GuiAjoutModifierActeur *ajout = new GuiAjoutModifierActeur();
	connect(ajout, SIGNAL(editionnTerminee()), SLOT(majTable()));
	ajout->show();
}

void GuiGestionActeur::modifierActeur()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvActeur->selectionModel();
	
	// identifiant de l'acteur
	QVariant var = select->selectedRows(0).first().data();
	int idActeur = var.toInt();

	// nom de l’acteur
	var = select->selectedRows(1).first().data();
	QString nomActeur = var.toString();

	// identifiant du rôle de l'acteur
	var = select->selectedRows(3).first().data();
	int idRole = var.toInt();

	// Ouverture de la fenêtre de modification
	GuiAjoutModifierActeur *modification = new GuiAjoutModifierActeur(new Acteur(nomActeur, idRole, idActeur));
	connect(modification, SIGNAL(editionTerminee()), SLOT(majTable()));
	modification->show();
}

void GuiGestionActeur::supprimer()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvActeur->selectionModel();

	// nom acteur
	QVariant var = select->selectedRows(1).first().data();
	QString nomActeur = var.toString();

	// récupération du rôle
	var = select->selectedRows(2).first().data();
	QString libelleRole = var.toString();

	// Affichage d'une boîte de dialogue de confirmation
	QMessageBox *confirmation = new QMessageBox();
	confirmation->setIcon(QMessageBox::Question);
	confirmation->setWindowTitle(trUtf8("Confirmation de la suppression"));
	confirmation->setText(trUtf8("Suppression Acteur"));
	confirmation->setInformativeText(trUtf8("Êtes-vous sûr de vouloir supprimer l'acteur ") + nomActeur + trUtf8(" avec le rôle '") + libelleRole + "' ?");
	confirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	confirmation->setDefaultButton(QMessageBox::No);

	int reponse = confirmation->exec();

	// Traitement de la réponse
	if (reponse == QMessageBox::Yes)
	{
		// Récupération de l'identifiant du genre à supprimer
		QVariant var = select->selectedRows(0).first().data();
		int idActeur = var.toInt();

		// Affichage du résultat de la suppression
		if (ManagerActeur::supActeur(idActeur))
		{
			QMessageBox *info = new QMessageBox(QMessageBox::Information, trUtf8("Suppression effectuée"), trUtf8("L'acteur ") + nomActeur + trUtf8(" avec le rôle '") + libelleRole + trUtf8("' a été supprimé!"));
			int rep = info->exec();
		}
		else
		{
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Problème lors de la suppression"), trUtf8("L'acteur ") + nomActeur + trUtf8(" avec le rôle '") + libelleRole + trUtf8("' n'a pas été supprimé!\n\nDétail de l'erreur :\n") + ManagerActeur::getLastError());
			int rep = erreur->exec();
		}

		// Mise à jour de la table
		majTable();
	}
}

void GuiGestionActeur::majAffichage()
{
	if (tvActeur->currentIndex().row() != -1)
	{
		// récupération de la sélection
		QItemSelectionModel *select = tvActeur->selectionModel();
		QVariant var = select->selectedRows(4).first().data();

		// Activation des boutons en fonction de la sélection
		btnSupprimer->setEnabled(var.toInt() == 0);
		btnModifier->setEnabled(true);
	}
	else
	{
		btnModifier->setEnabled(false);
		btnSupprimer->setEnabled(false);
	}
}

void GuiGestionActeur::majComboFiltre()
{
	// Récupération de la connexion
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// création model
	QSqlTableModel *modelCb = new QSqlTableModel();
	modelCb->setTable("RoleActeur");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);
	modelCb->select();

	// remplissage de la comboBox
	cbFiltreRole->setModel(modelCb);
	cbFiltreRole->setModelColumn(1);

	// aucune sélection par défaut
	cbFiltreRole->setCurrentIndex(-1);
}

void GuiGestionActeur::filtrerRole(QString texte)
{
	proxy->setFilterKeyColumn(2);
	proxy->setDynamicSortFilter(true);
	proxy->setFilterRegExp(texte);
}

void GuiGestionActeur::toutAfficher()
{
	cbFiltreRole->setCurrentIndex(-1);
}
