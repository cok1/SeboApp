#include "GuiAjoutModifierActeur.h"
#include "ui_GuiAjoutModifierActeur.h"

GuiAjoutModifierActeur::GuiAjoutModifierActeur(Acteur *acteurAModifier, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiAjoutModifierActeur();
	ui->setupUi(this);

	// récupération des éléments
	btnValider = ui->btnValider;
	leLibelle = ui->leSaisieLibelle;
	cbRole = ui->cbRole;
	acteurEnCours = acteurAModifier;

	initCombo();

	if (acteurAModifier != Q_NULLPTR)
	{
		setWindowTitle("Modification Acteur");
		leLibelle->setText(acteurEnCours->getNom());

		// récupération du rôle
		shared_ptr<Role> role = ManagerRole::getRoleWithId(acteurEnCours->getIdRole());

		if (role != nullptr)
		{
			cbRole->setCurrentText(role->getLibelle());
		}

		// click valider == modifier
		connect(btnValider, SIGNAL(clicked()), SLOT(modificationActeur()));
	}
	else
	{
		// click valider == créer
		connect(btnValider, SIGNAL(clicked()), SLOT(creationActeur()));
	}
}

GuiAjoutModifierActeur::~GuiAjoutModifierActeur()
{
	delete ui;
}

void GuiAjoutModifierActeur::initCombo()
{
	// récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	// création du modèle
	QSqlTableModel *model = new QSqlTableModel();
	model->setTable("RoleActeur");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// récupération des données
	model->select();

	// remplissage de la comboBox
	cbRole->setModel(model);
	cbRole->setModelColumn(1);

	// aucune sélection sur la comboBox
	cbRole->setCurrentIndex(-1);
}

void GuiAjoutModifierActeur::creationActeur()
{
	// Déclarations
	QString nomActeur = leLibelle->text();

	if (!nomActeur.isEmpty() && cbRole->currentIndex() != -1)
	{
		// Récupération de l'identifiant du rôle
		QVariant var = cbRole->model()->index(cbRole->currentIndex(), 0).data();
		int idRole = var.toInt();
		acteurEnCours = new Acteur(nomActeur, idRole);

		// création de l'acteur à l'aide du manager
		if (ManagerActeur::addActeur(acteurEnCours))
		{
			// Affichage d'un message d'information
			QMessageBox *info;
			info = new QMessageBox(QMessageBox::Information, trUtf8("Création terminée"), trUtf8("L'identifiant du nouvel acteur est : ") + QString::number(acteurEnCours->getId()));
			int reponse = info->exec();

			// sortie de la fenêtre
			emit editionTerminee();
			close();
		}
		else
		{
			afficherMessageErreur(trUtf8("Problème lors de la création du nouvel acteur dans la base de données.\n\nDétail du message d'erreur :\n") + ManagerActeur::getLastError());
		}
	}
	else
		afficherMessageErreur();
}

void GuiAjoutModifierActeur::modificationActeur()
{
	QString nomActeur = leLibelle->text();

	if (!nomActeur.isEmpty() && cbRole->currentIndex() != -1)
	{
		// récupération des infos
		acteurEnCours->setNom(nomActeur);

		// Récupération de l'identifiant du rôle
		QVariant var = cbRole->model()->index(cbRole->currentIndex(), 0).data();
		acteurEnCours->setIdRole(var.toInt());

		// création de l'acteur à l'aide du manager
		if (ManagerActeur::modifActeur(acteurEnCours))
		{
			// Affichage d'un message d'information
			QMessageBox *info;
			info = new QMessageBox(QMessageBox::Information, trUtf8("Modification terminée"), trUtf8("La modification a été effectuée avec succès."));
			int reponse = info->exec();

			// sortie de la fenêtre
			emit editionTerminee();
			close();
		}
		else
		{
			afficherMessageErreur(trUtf8("Problème lors de la modification de l'acteur dans la base de données.\n\nDétail du message d'erreur :\n") + ManagerActeur::getLastError());
		}
	}
	else
		afficherMessageErreur();
}

void GuiAjoutModifierActeur::afficherMessageErreur(QString messageErreur)
{
	if (messageErreur.isEmpty())
	{
		if (leLibelle->text().isEmpty())
		{
			messageErreur = trUtf8("Veuillez saisir le nom de l'acteur");
			leLibelle->setFocus();
		}
		else
		{
			messageErreur = trUtf8("Veuillez saisir le rôle de l'acteur");
			cbRole->setFocus();
		}
	}

	QMessageBox *erreur = new QMessageBox(QMessageBox::Critical, trUtf8("Erreur"), messageErreur);
	int reponse = erreur->exec();
}