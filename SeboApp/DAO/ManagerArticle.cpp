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

		bool fermerConnexion = !db.isOpen();

		// ouverture de la connexion
		if (fermerConnexion)
		{
			db.open();
		}

		// Création de la requête
		QSqlQuery requete("Select * from Article order by Reference");

		if (!requete.exec())
		{
			m_strLastError = requete.lastError().text();
		}
		else
		{
			// Enregistrement des Articles dans le vecteur
			while (requete.next())
			{
				// Insertion de l'Article dans le vecteur
				listeArticle.push_back(make_shared<Article>(requete.value("LibelleArticle").toString(), requete.value("Prix").toFloat(), requete.value("PhotoArticle").toString(), requete.value("DescriptionArticle").toString(), requete.value("IdGenre").toInt(),
					requete.value("PrixFournisseur").toFloat(), requete.value("IdFournisseur").toInt(), requete.value("Reapprovisionnable").toBool(), requete.value("Reference").toInt()));
			}
		}
		// fermeture de la connexion
		if (fermerConnexion)
			db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les articles
	return listeArticle;
}

bool ManagerArticle::addArticle(Article *newArticle)
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

		bool fermerConnexion = !db.isOpen();

		// ouverture de la connexion
		if (fermerConnexion)
		{
			db.open();
		}

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("EXEC :codeRetour = ps_CreationArticle :libelleArticle, :prix, :photo, :description, :idGenre, :prixFournisseur, :idFournisseur, :isReapprovisionnable, :reference, :message");

		// binding des valeurs
		requete.bindValue(":codeRetour", -1, QSql::InOut);
		requete.bindValue(":libelleArticle", newArticle->getLibelle());
		requete.bindValue(":prix", newArticle->getPrix());
		requete.bindValue(":photo", newArticle->getPhoto());
		requete.bindValue(":description", newArticle->getDescription());
		requete.bindValue(":idGenre", newArticle->getIdGenre());
		requete.bindValue(":prixFournisseur", newArticle->getPrixFournisseur());
		requete.bindValue(":idFournisseur", newArticle->getIdFournisseur());
		requete.bindValue(":isReapprovisionnable", newArticle->isReapprovisionnable());
		requete.bindValue(":reference", -1, QSql::InOut);
		requete.bindValue(":message", QString(127, ' '), QSql::InOut);

		// exécution de la requête
		resultat = requete.exec();
		if (!resultat)
		{
			m_strLastError = requete.lastError().text();
		}
		else
		{
			// récupération de l'identifiant du nouveau genre
			newArticle->setReference(requete.boundValue(":reference").toInt());

			resultat = requete.boundValue(":codeRetour").toInt() == 0;

			if (!resultat)
			{
				// récupération du message d'erreur
				QString message = requete.boundValue(":message").toString();

				// on enlève les espaces au début et à la fin
				message = message.simplified();

				// Il y a eu un problème
				m_strLastError = message;
			}
		}

		// fermeture de la connexion
		if (fermerConnexion)
			db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	//retour du résultat de la fonction
	return resultat;
}

bool ManagerArticle::addArticle(QString libelle, double prixVenteHT, QString photo, QString description, int idGenre, double prixFournisseur, int idFournisseur, bool isReapprovisionnable)
{
	return addArticle(new Article(libelle, prixVenteHT, photo, description, idGenre, prixFournisseur, idFournisseur, isReapprovisionnable));
}

bool ManagerArticle::modifArticle(Article *articleAModifier)
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

		bool fermerConnexion = !db.isOpen();

		// ouverture de la connexion
		if (fermerConnexion)
		{
			db.open();
		}

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("UPDATE Article set LibelleArticle = :libelleArticle, Prix = :prix, PhotoArticle = :photo, DescriptionArticle = :description, IdGenre = :idGenre, PrixAchat = :prixFournisseur, IdFournisseur = :idFournisseur where Reference = :reference");

		// binding des valeurs
		requete.bindValue(":libelleArticle", articleAModifier->getLibelle());
		requete.bindValue(":prix", articleAModifier->getPrix());
		requete.bindValue(":photo", articleAModifier->getPhoto());
		requete.bindValue(":description", articleAModifier->getDescription());
		requete.bindValue(":idGenre", articleAModifier->getIdGenre());
		requete.bindValue(":prixFournisseur", articleAModifier->getPrixFournisseur());
		requete.bindValue(":idFournisseur", articleAModifier->getIdFournisseur());
		requete.bindValue(":reference", articleAModifier->getReference());

		// exécution de la requête
		resultat = requete.exec();

		if (!resultat)
		{
			m_strLastError = requete.lastError().text();
		}

		// fermeture de la connexion
		if (fermerConnexion)
			db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	//retour du résultat de la fonction
	return resultat;
}

bool ManagerArticle::supArticle(Article *articleASup)
{
	return supArticle(articleASup->getReference());
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

		bool fermerConnexion = !db.isOpen();

		// ouverture de la connexion
		if (fermerConnexion)
		{
			db.open();
		}

		// Création de la requête
		QSqlQuery requete;
		//requete.prepare("delete from Article where Reference = :refArticle");
		requete.prepare("EXEC :codeRetour = ps_SuppressionArticle :refArticle, :message");

		// binding des valeurs
		requete.bindValue(":codeRetour", -1, QSql::InOut);
		requete.bindValue(":refArticle", refArticle);
		requete.bindValue(":message", QString(127, ' '), QSql::InOut);

		// exécution de la requête
		resultat = requete.exec();

		if (!resultat)
		{
			m_strLastError = requete.lastError().text();
		}
		else
		{
			resultat = requete.boundValue(":codeRetour").toInt() == 0;

			if (!resultat)
			{
				// récupération du message d'erreur
				QString message = requete.boundValue(":message").toString();

				// on enlève les espaces au début et à la fin
				message = message.simplified();

				// Il y a eu un problème
				m_strLastError = message;
			}
		}

		// fermeture de la connexion
		if (fermerConnexion)
			db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du résultat de la fonction
	return resultat;
}
