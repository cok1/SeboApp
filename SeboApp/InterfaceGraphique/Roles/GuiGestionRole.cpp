#pragma encoding=utf8;
#include "GuiGestionRole.h"
#include "ui_GuiGestionRole.h"

GuiGestionRole::GuiGestionRole(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGestionRole();
	ui->setupUi(this);

	// R�cup�ration des �l�ments
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
	// R�cup�ration de la connexion
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// Cr�ation du mod�le � partir de la base de donn�es
	QSqlTableModel *model = new QSqlTableModel();

	// S�lection de la table
	model->setTable("detailRole");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// r�cup�ration des donn�es
	model->select();
	model->setHeaderData(0, Qt::Horizontal, trUtf8("Id"));
	model->setHeaderData(1, Qt::Horizontal, trUtf8("Libell�"));

	// Application du model sur la table
	tvRole->setModel(model);

	// Mise en forme de la table
	tvRole->hideColumn(0);
	tvRole->hideColumn(2);

	// Connexion des actions aux �v�nements
	connect(tvRole->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majAffichage()));

	// D�sactivation des boutons de suppression et de modification
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
	// r�cup�ration de la s�lection
	QItemSelectionModel *select = tvRole->selectionModel();
	
	// r�cup�ration de l'identifiant du r�le
	QVariant var = select->selectedRows(0).first().data();
	int idRole = var.toInt();

	// r�cup�ration du nom du r�le
	var = select->selectedRows(1).first().data();
	QString libelleRole = var.toString();

	// affichage de la fen�tre de modification
	GuiAjoutModifRole *modif = new GuiAjoutModifRole(new Role(libelleRole, idRole));
	connect(modif, SIGNAL(editionTerminee()), SLOT(majTable()));
	modif->show();
}

void GuiGestionRole::supprimerRole()
{
	// r�cup�ration de la s�lection
	QItemSelectionModel *select = tvRole->selectionModel();
	QVariant var = select->selectedRows(1).first().data();

	// r�cup�ration du nom du r�le
	QString libelleRole = var.toString();

	// Affichage d'une bo�te de dialogue de confirmation
	QMessageBox *confirmation = new QMessageBox();
	confirmation->setIcon(QMessageBox::Question);
	confirmation->setWindowTitle(trUtf8("Confirmation de la suppression"));
	confirmation->setText(trUtf8("Suppression R�le"));
	confirmation->setInformativeText(trUtf8("�tes-vous s�r de vouloir supprimer le r�le ") + libelleRole + " ?");
	confirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	confirmation->setDefaultButton(QMessageBox::No);

	int reponse = confirmation->exec();

	// Traitement de la r�ponse
	if (reponse == QMessageBox::Yes)
	{
		// R�cup�ration de l'identifiant de la cat�gorie � supprimer
		QVariant var = select->selectedRows(0).first().data();
		int idRole = var.toInt();

		// Affichage du r�sultat de la suppression
		if (ManagerRole::supRole(idRole))
		{
			QMessageBox *info = new QMessageBox(QMessageBox::Information, trUtf8("Suppression effectu�e"), trUtf8("Le r�le ") + libelleRole + trUtf8(" a �t� supprim�!"));
			int rep = info->exec();
		}
		else
		{
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Probl�me lors de la suppression"), trUtf8("Le r�le ") + libelleRole + trUtf8(" n'a �t� supprim�!") + ManagerRole::getLastError());
			int rep = erreur->exec();
		}

		// Mise � jour de la table
		majTable();
	}
}

void GuiGestionRole::majAffichage()
{
	if (tvRole->currentIndex().row() != -1)
	{
		// R�cup�ration de la s�lection
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
