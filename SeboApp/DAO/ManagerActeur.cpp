#include "ManagerActeur.h"

QString ManagerActeur::m_strLastError = "";

ManagerActeur::ManagerActeur()
{
}


ManagerActeur::~ManagerActeur()
{
}

vector<shared_ptr<Acteur>> ManagerActeur::getListeActeur()
{
	// Définitions
	vector<shared_ptr<Acteur>> listeActeur;	// va contenir les acteurs récupérés de la base de données

	// Initialisation
	listeActeur = vector<shared_ptr<Acteur>>();

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from Acteur order by nomActeur");

		// Enregistrement des Acteurs dans le vecteur
		while (requete.next())
		{
			// Insertion de l'acteur dans le vecteur
			listeActeur.push_back(make_shared<Acteur>(requete.value("NomActeur").toString(), requete.value("IdRole").toFloat(), requete.value("IdActeur").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les acteurs
	return listeActeur;
}

bool ManagerActeur::addActeur(Acteur acteurAAjouter)
{
	return addActeur(acteurAAjouter.getNom(), acteurAAjouter.getIdRole());
}

bool ManagerActeur::addActeur(QString nomActeur, int idRole)
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
		requete.prepare("INSERT INTO Acteur (NomActeur, IdRole) VALUES (:nom, :idRole)");

		// binding des valeurs
		requete.bindValue(":nom", nomActeur);
		requete.bindValue(":idRole", idRole);

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

bool ManagerActeur::modifActeur(Acteur acteurAModifier)
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
		requete.prepare("UPDATE Acteur set NomActeur=:nom, IdRole=:idRole where idActeur=:id");

		// binding des valeurs
		requete.bindValue(":nom", acteurAModifier.getNom());
		requete.bindValue(":idRole", acteurAModifier.getIdRole());
		requete.bindValue(":id", acteurAModifier.getId());

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

bool ManagerActeur::supActeur(Acteur acteurASupprimer)
{
	return supActeur(acteurASupprimer.getId());
}

bool ManagerActeur::supActeur(int idActeurASupprimer)
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
		requete.prepare("delete from Acteur where idActeur= :idActeur");

		// binding des valeurs
		requete.bindValue(":idActeur", idActeurASupprimer);

		// exécution de la requête
		resultat = requete.exec();

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception&)
	{
	}

	// retour du résultat de la fonction
	return resultat;
}
