#include "ManagerCategorie.h"

QString ManagerCategorie::m_strLastError = "";

ManagerCategorie::ManagerCategorie()
{
}


ManagerCategorie::~ManagerCategorie()
{
}

vector<shared_ptr<Categorie>> ManagerCategorie::getListCategorie()
{
	// Définitions
	vector<shared_ptr<Categorie>> listeCategorie;	// va contenir les catégories récupérées de la base de données

	// Initialisation
	listeCategorie = vector<shared_ptr<Categorie>>();

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from categorie order by idCategorie");

		// Enregistrement des Catégorie dans le vecteur
		while (requete.next())
		{
			// Insertion de la catégorie dans le vecteur
			listeCategorie.push_back(make_shared<Categorie>(requete.value("LibelleCategorie").toString(), requete.value("Tva").toFloat(), requete.value("IdCategorie").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les catégories
	return listeCategorie;
}

shared_ptr<Categorie> ManagerCategorie::getCategorieWithLibelle(QString libelle)
{
	// Declaration
	shared_ptr<Categorie> categorie = nullptr;

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
		requete.prepare("select * from Categorie where LibelleCategorie = :libelleCategorie");

		// binding des valeurs
		requete.bindValue(":libelleCategorie", libelle);

		// exécution de la requête
		requete.exec();

		if (requete.next())
		{
			categorie = make_shared<Categorie>(requete.value("LibelleCategorie").toString(), requete.value("Tva").toFloat(), requete.value("IdCategorie").toInt());
		}

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour de la catégorie
	return categorie;
}

shared_ptr<Categorie> ManagerCategorie::getCategorieWithId(int idCategorie)
{
	// Déclaration
	shared_ptr<Categorie> categorie = nullptr;

	try
	{
		//// Récupération du pointeur vers l'instance unique de la connexion
		//std::shared_ptr<Connexion> conn = Connexion::getInstance();

		//// récupération de la connexion
		//QSqlDatabase db = conn->getConnexion();

		//// ouverture de la connexion
		//db.open();

		//// Création de la requête
		//QSqlQuery requete;
		//requete.prepare("select * from Categorie where IdCategorie = :idCategorie");

		//// binding des valeurs
		//requete.bindValue(":idCategorie", 1);

		//// exécution de la requête
		//requete.exec();

		//if (requete.next())
		//{
		//	categorie = make_shared<Categorie>(requete.value("LibelleCategorie").toString(), requete.value("Tva").toDouble(), requete.value("IdCategorie").toInt());
		//}

		//// fermeture de la connexion
		//db.close();
		categorie = make_shared<Categorie>("CD", 5.5, 1);
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
		//Connexion::getInstance()->getConnexion().close();
	}

	// retour de la catégorie
	return categorie;
}

bool ManagerCategorie::supCategorie(Categorie catASupprimer)
{
	return supCategorie(catASupprimer.getId());
}

bool ManagerCategorie::supCategorie(int idCategorie)
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
		requete.prepare("EXEC ps_SuppressionCategorie :idCategorie, :message");

		// binding des valeurs
		requete.bindValue(":idCategorie", idCategorie);
		requete.bindValue(":message", QString(127, ' '), QSql::InOut);


		// exécution de la requête
		resultat = requete.exec();

		// Récupération du message de retour de la procédure stockée
		QString message = requete.boundValue(":message").toString();

		// on enlève les espaces au début et à la fin
		message = message.simplified();

		// Test du message de retour
		resultat = message.length()<4;

		if (!resultat)
		{
			// Il y a eu un problème
			m_strLastError = message;
		}

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

bool ManagerCategorie::addCategorie(Categorie *catAAjouter)
{
	// Déclarations
	bool resultat;	// va contenir le résultat de la procédure
	int codeRetour;

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

		//requete.setForwardOnly(true);
		requete.prepare("EXEC ps_CreationCategorie :libelle, :tauxTva, :id, :message");

		// binding des valeurs
		requete.bindValue(":libelle", catAAjouter->getLibelle());
		requete.bindValue(":tauxTva", catAAjouter->getTauxTva());
		requete.bindValue(":id", 0, QSql::InOut);
		requete.bindValue(":message", QString(127, ' '), QSql::InOut);

		// exécution de la requête
		resultat = requete.exec();

		// récupération de l'identifiant de la nouvelle catégorie
		catAAjouter->setId(requete.boundValue(":id").toInt());

		// Récupération du message de retour de la procédure stockée
		QString message = requete.boundValue(":message").toString();

		// on enlève les espaces au début et à la fin
		message = message.simplified();

		// Test du message de retour
		resultat = message.length()<4;

		if (!resultat)
		{
			// Il y a eu un problème
			m_strLastError = message;
		}

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

bool ManagerCategorie::addCategorie(QString libelle, double tauxTva)
{

	return addCategorie(new Categorie(libelle, tauxTva));
}

bool ManagerCategorie::modifCategorie(Categorie *categorieAModifier)
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
		requete.prepare("UPDATE Categorie set libelleCategorie = :libelle, Tva = :tauxTva where idCategorie=:id");

		// binding des valeurs
		requete.bindValue(":libelle", categorieAModifier->getLibelle());
		//requete.bindValue(":tauxTva", 17.0);
		requete.bindValue(":tauxTva", categorieAModifier->getTauxTva());
		requete.bindValue(":id", categorieAModifier->getId());

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