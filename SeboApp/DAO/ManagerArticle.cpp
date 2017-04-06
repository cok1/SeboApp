#include "ManagerArticle.h"

QString ManagerArticle::m_strLastError = "";

ManagerArticle::ManagerArticle()
{
}


ManagerArticle::~ManagerArticle()
{
}

vector<shared_ptr<Article>> ManagerArticle::getListeArticle()
{
	// Définitions
	vector<shared_ptr<Article>> listeArticle;	// va contenir les articles récupérés de la base de données

	// Initialisation
	listeArticle = vector<shared_ptr<Article>>();

	try
	{
		// Récupération du pointeur vers l'instance unique de la connexion
		shared_ptr<Connexion> conn = Connexion::getInstance();

		// récupération de la connexion
		QSqlDatabase db = conn->getConnexion();

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from Article order by Reference");

		// Enregistrement des Articles dans le vecteur
		while (requete.next())
		{
			// Insertion de l'Article dans le vecteur
			listeArticle.push_back(make_shared<Article>(requete.value("LibelleArticle").toString(), requete.value("Prix").toFloat(), requete.value("PhotoArticle").toString(), requete.value("DescriptionArticle").toString(), requete.value("IdGenre").toInt(),
				requete.value("PrixFournisseur").toFloat(), requete.value("IdFournisseur").toInt(), requete.value("Reapprovisionnable").toBool(), requete.value("Reference").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les articles
	return listeArticle;
}

bool ManagerArticle::addArticle(Article newArticle)
{
	return addArticle(newArticle.getLibelle(), newArticle.getPrix(), newArticle.getPhoto(), newArticle.getDescription(),newArticle.getIdGenre(), newArticle.getPrixFournisseur(), newArticle.getIdFournisseur(), newArticle.isReapprovisionnable());
}

bool ManagerArticle::addArticle(QString libelle, double prixVenteHT, QString photo, QString description, int idGenre, double prixFournisseur, int idFournisseur, bool isReapprovisionnable)
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
		requete.prepare("INSERT INTO Article (LibelleArticle, Prix, PhotoArticle, DescriptionArticle, IdGenre, PrixFournisseur, IdFournisseur, Reapprovisionnable) VALUES (:libelleArticle, :prix, :photo, :description, :idGenre, :prixFournisseur, :idFournisseur, :isReapprovisionnable)");

		// binding des valeurs
		requete.bindValue(":libelleArticle", libelle);
		requete.bindValue(":prix", prixVenteHT);
		requete.bindValue(":photo", photo);
		requete.bindValue(":description", description);
		requete.bindValue(":idGenre", idGenre);
		requete.bindValue(":prixFournisseur", prixFournisseur);
		requete.bindValue(":idFournisseur", idFournisseur);
		requete.bindValue(":isReapprovisionnable", isReapprovisionnable);

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

bool ManagerArticle::modifArticle(Article articleAModifier)
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
		requete.prepare("UPDATE Article set LibelleArticle=:libelleArticle, Prix = :prix, PhotoArticle = :photo, DescriptionArticle = :description, IdGenre = :idGenre, PrixFournisseur = :prixFournisseur, IdFournisseur = :idFournisseur");

		// binding des valeurs
		requete.bindValue(":libelleArticle", articleAModifier.getLibelle());
		requete.bindValue(":prix", articleAModifier.getPrix());
		requete.bindValue(":photo", articleAModifier.getPhoto());
		requete.bindValue(":description", articleAModifier.getDescription());
		requete.bindValue(":idGenre", articleAModifier.getIdGenre());
		requete.bindValue(":prixFournisseur", articleAModifier.getPrixFournisseur());
		requete.bindValue(":idFournisseur", articleAModifier.getIdFournisseur());

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

bool ManagerArticle::supArticle(Article articleASup)
{
	return supArticle(articleASup.getReference());
}

bool ManagerArticle::supArticle(int refArticle)
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
		requete.prepare("delete from Article where Reference = :refArticle");

		// binding des valeurs
		requete.bindValue(":refArticle", refArticle);

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
