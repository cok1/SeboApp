#include "GuiGestionArticle.h"
#include "ui_GuiGestionArticle.h"

GuiGestionArticle::GuiGestionArticle(QWidget *parent)
	: QWidget(parent)
{
	// mise en place de l'interface graphique
	ui = new Ui::GuiGestionArticle();
	ui->setupUi(this);

	// récupération des éléments de l'interface
	recupElements();

	// Mise à jour du modèle
	majModel();

	// mise à jour de la table
	majTable();

	// Initialisation des comboBox
	majCbFournisseur();
	cbFournisseur->setCurrentIndex(-1);

	majCbGenre();

	majCbCategorie();

	// désactivation de la groupBox d'affichage des détails de l'article
	gbDetail->setEnabled(false);
	frEdition->setVisible(false);
	btnSupprimer->setEnabled(false);
	btnModifier->setEnabled(false);


	// connection des signaux
	connectionSignaux();
}

GuiGestionArticle::~GuiGestionArticle()
{
	delete ui;
}

void GuiGestionArticle::majTable()
{
	// Création d'un moèle de filtre
	proxyModel = new QSortFilterProxyModel();
	proxyModel->setSourceModel(model);

	// récupération du modèle
	tvArticle->setModel(proxyModel);

	// Gestion des largeur de colonnes
	tvArticle->setColumnWidth(0, 60);
	tvArticle->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	tvArticle->setColumnWidth(5, 120);
	tvArticle->setColumnWidth(7, 120);
	tvArticle->setColumnWidth(9, 120);
	tvArticle->setColumnWidth(10, 80);
	tvArticle->horizontalHeader()->setStretchLastSection(false);

	// Masquage des colonnes non utilisées
	tvArticle->hideColumn(2);
	tvArticle->hideColumn(3);
	tvArticle->hideColumn(4);
	tvArticle->hideColumn(6);
	tvArticle->hideColumn(8);
	tvArticle->hideColumn(11);
	tvArticle->hideColumn(12);
	tvArticle->hideColumn(13);



	// écoute du changement de sélection sur la table article
	connect(tvArticle->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), SLOT(majDetailArticle()));

	btnSupprimer->setEnabled(false);
	btnModifier->setEnabled(false);
}

void GuiGestionArticle::majModel()
{
	// récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	//récupération de la base de données
	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	model = new QSqlTableModel();

	model->setTable("DetailArticle");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	model->select();

	// tri des articles
	model->sort(0, Qt::AscendingOrder);
}

void GuiGestionArticle::recupElements()
{
	// récupération des éléments
	cbFiltreCategorie = ui->cbFiltreCategorie;
	cbFiltreGenre = ui->cbFiltreGenre;
	leFiltreLibelle = ui->leFiltreLibelle;
	btnToutAfficher = ui->btnToutAfficher;

	//Partie affichage
	tvArticle = ui->tvArticle;

	// Partie Modification Ajout
	gbDetail = ui->gbDetailArticle;
	leReference = ui->leReference;
	leSaisieLibelle = ui->leSaisieLibelle;
	ckReapprovisionnable = ui->ckReapprovisionable;
	cbCategorie = ui->cbCategorie;
	cbGenre = ui->cbGenre;
	cbFournisseur = ui->cbFournisseur;
	dspPrixVente = ui->dspPrixVente;
	dspPrixAchat = ui->dspPrixAchat;
	teDescription = ui->teDescription;
	lblPhoto = ui->lblPhoto;

	// Boutons
	btnAjouter = ui->btnAjouter;
	btnModifier = ui->btnModifier;
	btnValider = ui->btnValider;
	btnAnnuler = ui->btnAnnuler;
	btnSupprimer = ui->btnSupprimer;
	btnGererCategorie = ui->btnGererCategorie;
	btnGererGenre = ui->btnGererGenre;
	btnAjouterPhoto = ui->btnAjouterPhoto;
	btnModifierPhoto = ui->btnModifierPhoto;
	btnSupprimerPhoto = ui->btnSupprimerPhoto;
	btnAjouterRole = ui->btnAjouterRole;
	btnModifierRole = ui->btnModifierRole;
	btnSupprimerRole = ui->btnSupprimerRole;

	// Ensemble de boutons
	frEdition = ui->frEdition;
	frGestion = ui->frGestion;
}

void GuiGestionArticle::connectionSignaux()
{
	// écoute des divers boutons
	connect(btnGererCategorie, SIGNAL(clicked()), SLOT(gererCategorie()));
	connect(btnGererGenre, SIGNAL(clicked()), SLOT(gererGenre()));
	connect(btnModifier, SIGNAL(clicked()), SLOT(modifierArticle()));
	connect(btnAnnuler, SIGNAL(clicked()), SLOT(annuler()));
	connect(btnToutAfficher, SIGNAL(clicked()), SLOT(toutAfficher()));
	connect(btnValider, SIGNAL(clicked()), SLOT(valider()));
	connect(btnAjouter, SIGNAL(clicked()), SLOT(ajoutArticle()));
	connect(btnSupprimer, SIGNAL(clicked()), SLOT(supprimerArticle()));

	// Écoute des changement de sélection sur les comboBox de filtre
	connect(cbFiltreCategorie, SIGNAL(currentIndexChanged(QString)), SLOT(filtrerCategorie(QString)));
	connect(cbFiltreGenre, SIGNAL(currentIndexChanged(QString)), SLOT(filtrerGenre(QString)));

	// Écoute de l'édition de la ligne de libellé
	connect(leFiltreLibelle, SIGNAL(textChanged(const QString &)), SLOT(filtrerLibelle(QString)));
}

void GuiGestionArticle::majDetailArticle()
{
	if (tvArticle->currentIndex().row() != -1)
	{
		// Récupération de la sélection
		QItemSelectionModel *select = tvArticle->selectionModel();

		// Récupération de la référence
		QVariant var = select->selectedRows(0).first().data();
		leReference->setText(var.toString());

		// Récupération du libellé
		var = select->selectedRows(1).first().data();
		leSaisieLibelle->setText(var.toString());

		// Récupération de la description
		var = select->selectedRows(2).first().data();
		teDescription->setText(var.toString());

		// Récupération du nom de la photo
		//var = select->selectedRows(3).first().data();
		//QString nomPhoto = var.toString();

		// Récupération de la catégorie
		var = select->selectedRows(5).first().data();
		cbCategorie->setCurrentText(var.toString());

		// Récupération du genre
		var = select->selectedRows(7).first().data();
		cbGenre->setCurrentText(var.toString());

		// Récupération du fournisseur
		var = select->selectedRows(9).first().data();
		cbFournisseur->setCurrentText(var.toString());

		// Récupération du prix de vente
		var = select->selectedRows(10).first().data();
		dspPrixVente->setValue(var.toDouble());

		// Récupération du prix d'achat
		var = select->selectedRows(11).first().data();
		dspPrixAchat->setValue(var.toDouble());

		// Récupération du statut de réapprovisionnement
		var = select->selectedRows(12).first().data();
		ckReapprovisionnable->setChecked(var.toBool());

		// Récupération du nombre d'utilisation
		var = select->selectedRows(13).first().data();
		btnSupprimer->setEnabled(var.toInt() == 0);

		// Activation du bouton de modification
		btnModifier->setEnabled(true);
	}
	else
	{
		// réinitialisation champs
		reinitChamps();
	}
}

void GuiGestionArticle::suppFiltre()
{
}

void GuiGestionArticle::ajoutArticle()
{
	tvArticle->selectRow(-1);

	// Désactivation de la sélection sur la table
	tvArticle->setSelectionMode(QAbstractItemView::NoSelection);

	// réinitialisation des champs
	reinitChamps();

	// activation de la zone d'édition
	gbDetail->setEnabled(true);

	frEdition->setVisible(true);
	frGestion->setVisible(false);
}

void GuiGestionArticle::modifierArticle()
{
	if (tvArticle->currentIndex().row() != -1)
	{
		// Désactivation de la sélection sur la table
		tvArticle->setSelectionMode(QAbstractItemView::NoSelection);

		// activation de l'édition
		gbDetail->setEnabled(true);
		frEdition->setVisible(true);

		// on masque le frame de gestion
		frGestion->setVisible(false);
	}
}

void GuiGestionArticle::supprimerArticle()
{
	// Récupération de la sélection
	QItemSelectionModel *select = tvArticle->selectionModel();
	QVariant var = select->selectedRows(1).first().data();

	// récupération du nom de la catégorie
	QString libelleArticle = var.toString();

	// Affichage d'une boîte de dialoque de confirmation
	QMessageBox *confirmation = new QMessageBox();
	confirmation->setIcon(QMessageBox::Question);
	confirmation->setWindowTitle(trUtf8("Confirmation de la suppression"));
	confirmation->setText(trUtf8("Suppression Article"));
	confirmation->setInformativeText(trUtf8("Êtes-vous sûr de vouloir supprimer l'article ") + libelleArticle + " ?");
	confirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	confirmation->setDefaultButton(QMessageBox::No);

	int reponse = confirmation->exec();

	// Traitement de la réponse
	if (reponse == QMessageBox::Yes)
	{
		// Récupération de a référence de l'article à supprimer
		QVariant var = select->selectedRows(0).first().data();
		int reference = var.toInt();

		// Affichage du résultat de la suppression
		if (ManagerArticle::supArticle(reference))
		{
			QMessageBox *info = new QMessageBox(QMessageBox::Information, trUtf8("Suppression effectuée"), trUtf8("L'article ") + libelleArticle + trUtf8(" a été supprimée!"));
			int rep = info->exec();
		}
		else
		{
			QMessageBox *erreur = new QMessageBox(QMessageBox::Information, trUtf8("Problème lors de la suppression"), trUtf8("L'article ") + libelleArticle + trUtf8(" n'a été supprimée!") + ManagerArticle::getLastError());
			int rep = erreur->exec();
		}

		// Mise à jour de la table
		majModel();
		majTable();
		annuler();
	}
}

void GuiGestionArticle::annuler()
{
	// mise à jour du détail à partir des infos enregistrée
	majDetailArticle();

	// Désactivation de la description
	gbDetail->setEnabled(false);

	// masquage du frame d'eddition
	frEdition->setVisible(false);

	// réaffichage du frame de gestion
	frGestion->setVisible(true);

	// réactivation de la sélection sur la table article
	tvArticle->setSelectionMode(QAbstractItemView::SingleSelection);
}

void GuiGestionArticle::valider()
{
	// Déclarations
	Article *article;		// va contenir le nouvel article ou l'article à mettre à jour
	QString libelle;		// va contenir le libellé de l'article
	double prixVente;		// va contenir le prix de vente
	QString photo;			// va contenir le nom du fichier de la photo
	QString description;	// va contenir la description de l'article
	bool reapprovisionnable;// va contenir l'info sur le réapprovisionnement
	int idGenre;			// va contenir l'identifiant du genre de l'article
	double prixAchat;		// va contenir le prix d'achat de l'article
	int idFournisseur;		// va contenir l'identifiant du fournisseur

	// Récupération des infos
	libelle = leSaisieLibelle->text();
	prixVente = dspPrixVente->value();
	photo = "";	// TODO à modifier par la suite
	description = teDescription->toPlainText();
	reapprovisionnable = ckReapprovisionnable->isChecked();
	idGenre = ManagerGenre::getIdGenre(cbGenre->currentText());
	prixAchat = dspPrixAchat->value();
	idFournisseur = ManagerFournisseur::getIdFournisseur(cbFournisseur->currentText());

	if (leReference->text().isEmpty())
	{
		// création de l'article
		article = new Article(libelle, prixVente, photo, description, idGenre, prixAchat, idFournisseur, reapprovisionnable);

		// Appel ps_creation
		if (ManagerArticle::addArticle(article))
		{
			// Affichage d'un message d'information
			QMessageBox *info;

			info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Création achevée"), trUtf8("La référence du nouvel article est : ") + QString::number(article->getReference()));
			int reponse = info->exec();
			majModel();
			majTable();
			annuler();
		}
		else
		{
			// Affichage d'un message d'erreur
			QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Problème lors de la création de l'article dans la base de données"), ManagerCategorie::getLastError());
			int reponse = erreur->exec();
		}
	}
	else
	{
		int reference = leReference->text().toInt();

		// modification de l'article
		article = new Article(libelle, prixVente, photo, description, idGenre, prixAchat, idFournisseur, reapprovisionnable, reference);

		// Appel modifier Article
		if (ManagerArticle::modifArticle(article))
		{
			// Affichage d'un message d'information
			QMessageBox *info;
			info = new QMessageBox(QMessageBox::Icon::Information, trUtf8("Modification terminée"), trUtf8("La modification s'est bien passée."));
			int reponse = info->exec();

			majModel();
			majTable();
			annuler();
		}
		else
		{
			// Affichage d'un message d'erreur
			QMessageBox *erreur = new QMessageBox(QMessageBox::Icon::Critical, trUtf8("Problème lors de la modification de l'article dans la base de données"), ManagerCategorie::getLastError());
			int reponse = erreur->exec();
		}
	}
}

void GuiGestionArticle::gererCategorie()
{
	GuiGestionCategorie *gererCat = new GuiGestionCategorie();
	gererCat->setWindowModality(Qt::ApplicationModal);
	gererCat->show();
	majCbCategorie();
}

void GuiGestionArticle::gererGenre()
{
	GuiGestionGenre *gererGen = new GuiGestionGenre();
	gererGen->setWindowModality(Qt::ApplicationModal);
	gererGen->show();
	majCbGenre();
}

void GuiGestionArticle::majCbCategorie()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Categorie");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	modelCb->select();

	// Remplissage de la comboBox catégorie
	cbCategorie->setModel(modelCb);
	cbCategorie->setModelColumn(1);

	// Remplissage de la comboBox filtre catégorie
	cbFiltreCategorie->setModel(modelCb);
	cbFiltreCategorie->setModelColumn(1);

	// aucune sélection par défaut
	cbCategorie->setCurrentIndex(-1);
	cbFiltreCategorie->setCurrentIndex(-1);
}

void GuiGestionArticle::majCbGenre()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Genre");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	modelCb->select();

	// Remplissage de la comboBox genre
	cbGenre->setModel(modelCb);
	cbGenre->setModelColumn(1);

	// Remplissage de la comboBox de filtre du genre
	cbFiltreGenre->setModel(modelCb);
	cbFiltreGenre->setModelColumn(1);

	// aucune sélection par défaut
	cbGenre->setCurrentIndex(-1);
	cbFiltreGenre->setCurrentIndex(-1);
}

void GuiGestionArticle::majCbFournisseur()
{
	// Récupération de la connexion
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	QSqlDatabase db = conn->getConnexion();

	// création du modèle à partir de la base de donnée
	QSqlTableModel *modelCb = new QSqlTableModel();

	modelCb->setTable("Fournisseur");
	modelCb->setEditStrategy(QSqlTableModel::OnManualSubmit);

	// Récupération des données
	modelCb->select();

	// Remplissage de la comboBox fournisseur
	cbFournisseur->setModel(modelCb);
	cbFournisseur->setModelColumn(1);
}

void GuiGestionArticle::filtrerCategorie(QString texte)
{
	// filtrage catégorie
	proxyModel->setFilterKeyColumn(5);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterRegExp(texte);
}

void GuiGestionArticle::filtrerGenre(QString texte)
{
	// filtrage genre
	proxyModel->setFilterKeyColumn(7);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterRegExp(texte);
}

void GuiGestionArticle::filtrerLibelle(QString texte)
{
	// filtrage libellé
	proxyModel->setFilterKeyColumn(1);
	proxyModel->setDynamicSortFilter(true);
	proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
	proxyModel->setFilterRegExp(texte);
}

void GuiGestionArticle::toutAfficher()
{
	proxyModel->invalidate();
	leFiltreLibelle->clear();
	cbFiltreCategorie->setCurrentIndex(-1);
	cbFiltreGenre->setCurrentIndex(-1);
}

void GuiGestionArticle::reinitChamps()
{
	leReference->clear();

	leSaisieLibelle->clear();

	teDescription->clear();

	// Récupération du nom de la photo
	//var = select->selectedRows(3).first().data();
	//QString nomPhoto = var.toString();

	cbCategorie->setCurrentIndex(-1);

	cbGenre->setCurrentIndex(-1);

	cbFournisseur->setCurrentIndex(-1);

	dspPrixVente->setValue(0);

	dspPrixAchat->setValue(0);

	ckReapprovisionnable->setChecked(true);

	btnSupprimer->setEnabled(false);

	// Activation du bouton de modification
	btnModifier->setEnabled(false);
}

