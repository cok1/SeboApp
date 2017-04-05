#include "ManagerActeurArticle.h"

QString ManagerActeurArticle::m_strLastError = "";

ManagerActeurArticle::ManagerActeurArticle()
{
}


ManagerActeurArticle::~ManagerActeurArticle()
{
}

vector<shared_ptr<ActeurArticle>> ManagerActeurArticle::getListeActeurArticle()
{
	// Définitions
	vector<shared_ptr<ActeurArticle>> listeActeurArticle;	// va contenir les relations acteur/article récupérées de la base de données

	// Initialisation
	listeActeurArticle = vector<shared_ptr<ActeurArticle>>();

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from ActeurArticle order by Reference");

		// Enregistrement des ActeurArticles dans le vecteur
		while (requete.next())
		{
			// Insertion de la relation acteur/article dans le vecteur
			listeActeurArticle.push_back(make_shared<ActeurArticle>(requete.value("Reference").toInt(), requete.value("IdActeur").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les relations acteur/article
	return listeActeurArticle;
}

bool ManagerActeurArticle::addActeurArticle(ActeurArticle acteurArticleAAjouter)
{
	return addActeurArticle(acteurArticleAAjouter.getIdActeur(), acteurArticleAAjouter.getReferenceArticle());
}

bool ManagerActeurArticle::addActeurArticle(int idActeur, int refArticle)
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
		requete.prepare("INSERT INTO ActeurArticle (Reference, IdActeur) VALUES (:refArticle, :idActeur)");

		// binding des valeurs
		requete.bindValue(":refArticle", refArticle);
		requete.bindValue(":idActeur", idActeur);

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

bool ManagerActeurArticle::supActeurArticle(ActeurArticle acteurArticleASupprimer)
{
	return supActeurArticle(acteurArticleASupprimer.getIdActeur(), acteurArticleASupprimer.getReferenceArticle());
}


bool ManagerActeurArticle::supActeurArticle(int idActeur, int refArticle)
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
		requete.prepare("delete from ActeurArticle where Reference = :refArticle and IdActeur = :idArticle");

		// binding des valeurs
		requete.bindValue(":refArticle", refArticle);
		requete.bindValue(":idArticle", idActeur);

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

QString ManagerActeurArticle::getLastError()
{
	return m_strLastError;
}
