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

shared_ptr<Genre> ManagerGenre::getGenreWithLibelle(QString libelle)
{
	// Declaration
	shared_ptr<Genre> genre = nullptr;

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
		requete.prepare("select * from Genre where LibelleGenre = :libelleGenre");

		// binding des valeurs
		requete.bindValue(":libelleGenre", libelle);

		// exécution de la requête
		requete.exec();

		if (requete.next())
		{
			genre = make_shared<Genre>(requete.value("LibelleGenre").toString(), requete.value("IdCategorie").toInt(), requete.value("IdGenre").toInt());
		}

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour de la catégorie
	return genre;
}

int ManagerGenre::getIdGenre(QString libelle)
{
	// Declaration
	int idGenre = -1;

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
		requete.prepare("select IdGenre from Genre where LibelleGenre = :libelleGenre");

		// binding des valeurs
		requete.bindValue(":libelleGenre", libelle);

		// exécution de la requête
		requete.exec();

		if (requete.next())
		{
			idGenre = requete.value("IdGenre").toInt();
		}

		// fermeture de la connexion
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour de la catégorie
	return idGenre;
}

bool ManagerGenre::addGenre(Genre *genreAAjouter)
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
		requete.prepare("EXEC ps_CreationGenre :libelle, :idCategorie, :id, :message");

		// binding des valeurs
		requete.bindValue(":libelle", genreAAjouter->getLibelle());
		requete.bindValue(":idCategorie", genreAAjouter->getIdCategorie());
		requete.bindValue(":id", 0, QSql::InOut);
		requete.bindValue(":message", QString(127, ' '), QSql::InOut);

		// exécution de la requête
		resultat = requete.exec();

		// récupération de l'identifiant du nouveau genre
		genreAAjouter->setId(requete.boundValue(":id").toInt());

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

bool ManagerGenre::addGenre(QString libelle, int idCategorie)
{
	return addGenre(new Genre(libelle, idCategorie));
}

bool ManagerGenre::modifGenre(Genre *genreAModifier)
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
		requete.bindValue(":libelle", genreAModifier->getLibelle());
		requete.bindValue(":idCategorie", genreAModifier->getIdCategorie());
		requete.bindValue(":id", genreAModifier->getId());

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
