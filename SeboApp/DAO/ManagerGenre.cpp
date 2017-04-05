#include "ManagerGenre.h"
#include "ManagerGenre.h"


QString ManagerGenre::m_strLastError = "";

ManagerGenre::ManagerGenre()
{
}


ManagerGenre::~ManagerGenre()
{
}

vector<shared_ptr<Genre>> ManagerGenre::getListeGenre()
{
	// Définitions
	vector<shared_ptr<Genre>> listeGenre;		// va contenir les genres récupérées de la base de données
								
	listeGenre = vector<shared_ptr<Genre>>();	// Initialisation

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		std::shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from genre order by idCategorie");

		// Enregistrement des genres dans le vecteur
		while (requete.next())
		{
			// Insertion du genre dans le vecteur
			listeGenre.push_back(make_shared<Genre>(requete.value("LibelleGenre").toString(), requete.value("IdCategorie").toInt(), requete.value("idGenre").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les genres

	return listeGenre;
}

bool ManagerGenre::addGenre(Genre genreAAjouter)
{
	return addGenre(genreAAjouter.getLibelle(), genreAAjouter.getIdCategorie());
}

bool ManagerGenre::addGenre(QString libelle, int idCategorie)
{
	// Déclarations
	bool resultat;	// va contenir le résultat de la requête

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
		requete.prepare("INSERT INTO Genre (LibelleGenre, idCategorie) VALUES (:libelle, :idCategorie)");

		// binding des valeurs
		requete.bindValue(":libelle", libelle);
		requete.bindValue(":idCategorie", idCategorie);

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

bool ManagerGenre::modifGenre(Genre genreAModifier)
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
		requete.prepare("UPDATE Genre set LibelleGenre=:libelle, IdCategorie=:idCategorie where idGenre=:id");

		// binding des valeurs
		requete.bindValue(":libelle", genreAModifier.getLibelle());
		requete.bindValue(":idCategorie", genreAModifier.getIdCategorie());
		requete.bindValue(":id", genreAModifier.getId());

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

bool ManagerGenre::supGenre(Genre genreASupprimer)
{
	return supGenre(genreASupprimer.getId());
}

bool ManagerGenre::supGenre(int idGenreASupprimer)
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
		requete.prepare("delete from genre where idGenre = :idGenre");

		// binding des valeurs
		requete.bindValue(":idGenre", idGenreASupprimer);

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
