#include "ManagerFournisseur.h"

QString ManagerFournisseur::m_strLastError = "";

ManagerFournisseur::ManagerFournisseur()
{
}


ManagerFournisseur::~ManagerFournisseur()
{
}

vector<shared_ptr<Fournisseur>> ManagerFournisseur::getListeFournisseur()
{
	// Définitions
	vector<shared_ptr<Fournisseur>> listeFournisseur;	// va contenir les fournisseurs récupérées de la base de données

	// Initialisation
	listeFournisseur = vector<shared_ptr<Fournisseur>>();

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from Fournisseur order by idFournisseur");

		// Enregistrement des fournisseurs dans le vecteur
		while (requete.next())
		{
			// Insertion du fournisseur dans le vecteur
			listeFournisseur.push_back(make_shared<Fournisseur>(requete.value("NomFournisseur").toString(), requete.value("IdFournisseur").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les fournisseurs
	return listeFournisseur;
}

shared_ptr<Fournisseur> ManagerFournisseur::getFournisseurWithName(QString nom)
{
	// Declaration
	shared_ptr<Fournisseur> fournisseur = nullptr;

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("select * from Fournisseur where NomFournisseur = :nomFournisseur");

		// binding des valeurs
		requete.bindValue(":nomFournisseur", QString("Glénat"));

		// exécution de la requête
		requete.exec();

		if (requete.next())
		{
			fournisseur = make_shared<Fournisseur>(requete.value("NomFournisseur").toString(), requete.value("IdFournisseur").toInt());
		}

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour de la catégorie
	return fournisseur;
}

bool ManagerFournisseur::addFournisseur(Fournisseur fournisseurAAJouter)
{
	return addFournisseur(fournisseurAAJouter.getNomFournisseur());
}

bool ManagerFournisseur::addFournisseur(QString NomFournisseur)
{
	// Déclarations
	bool resultat;	// va contenir le résultat de la procédure

	// Initialisation
	resultat = false;

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("INSERT INTO Fournisseur (NomFournisseur) VALUES (:nom)");

		// binding des valeurs
		requete.bindValue(":nom", NomFournisseur);

		// exécution de la requête
		resultat = requete.exec();

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	//retour du résultat de la fonction
	return resultat;
}

bool ManagerFournisseur::modifFournisseur(Fournisseur fournisseurAModifier)
{
	// Déclarations
	bool resultat;	// va contenir le résultat de la procédure

	// Initialisation
	resultat = false;

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("UPDATE Fournisseur set nomFournisseur=:nom where idFournisseur=:id");

		// binding des valeurs
		requete.bindValue(":nom", fournisseurAModifier.getNomFournisseur());
		requete.bindValue(":id", fournisseurAModifier.getIdFournisseur());

		// exécution de la requête
		resultat = requete.exec();

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	//retour du résultat de la fonction
	return resultat;
}

bool ManagerFournisseur::supFournisseur(Fournisseur fournisseurASupprimmer)
{
	return supFournisseur(fournisseurASupprimmer.getIdFournisseur());
}

bool ManagerFournisseur::supFournisseur(int idFournisseurASupprimer)
{
	// Déclarations
	bool resultat;	// va contenir le résultat de la procédure

	// Initialisation
	resultat = false;

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("delete from Fournisseur where idFournisseur = :idFournisseur");

		// binding des valeurs
		requete.bindValue(":idFournisseur", idFournisseurASupprimer);

		// exécution de la requête
		resultat = requete.exec();

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du résultat de la fonction
	return resultat;
}