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

		bool fermerConnexion = !db.isOpen();

		// ouverture de la connexion
		if (fermerConnexion)
		{
			db.open();
		}

		// Création de la requête
		QSqlQuery requete("Select * from Acteur order by nomActeur");

		if (!requete.exec())
		{
			m_strLastError = requete.lastError().text();
		}
		else
		{
			// Enregistrement des Acteurs dans le vecteur
			while (requete.next())
			{
				// Insertion de l'acteur dans le vecteur
				listeActeur.push_back(make_shared<Acteur>(requete.value("NomActeur").toString(), requete.value("IdRole").toFloat(), requete.value("IdActeur").toInt()));
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

	// retour du vecteur contenant les acteurs
	return listeActeur;
}

bool ManagerActeur::addActeur(Acteur *acteurAAjouter)
{	// Déclarations
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
		requete.prepare("EXEC :codeRetour = ps_CreationActeur :nomActeur, :idRole, :id, :message");

		// binding des valeurs
		requete.bindValue(":codeRetour", -1, QSql::InOut);
		requete.bindValue(":nomActeur", acteurAAjouter->getNom());
		requete.bindValue(":idRole", acteurAAjouter->getIdRole());
		requete.bindValue(":id", -1, QSql::InOut);
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

			if (resultat)
			{
				acteurAAjouter->setId(requete.boundValue(":id").toInt());
			}
			else
			{
				QString message = requete.boundValue(":message").toString();

				message.simplified();

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

bool ManagerActeur::addActeur(QString nomActeur, int idRole)
{
	return addActeur(new Acteur(nomActeur, idRole));
}

bool ManagerActeur::modifActeur(Acteur *acteurAModifier)
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
		requete.prepare("UPDATE Acteur set NomActeur=:nom, IdRoleActeur=:idRole where idActeur=:id");

		// binding des valeurs
		requete.bindValue(":nom", acteurAModifier->getNom());
		requete.bindValue(":idRole", acteurAModifier->getIdRole());
		requete.bindValue(":id", acteurAModifier->getId());

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

bool ManagerActeur::supActeur(Acteur *acteurASupprimer)
{
	return supActeur(acteurASupprimer->getId());
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

		bool fermerConnexion = !db.isOpen();

		// ouverture de la connexion
		if (fermerConnexion)
		{
			db.open();
		}

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("EXEC :codeRetour = ps_SuppressionActeur :idActeur, :message");

		// binding des valeurs
		requete.bindValue(":codeRetour", 0, QSql::InOut);
		requete.bindValue(":idActeur", idActeurASupprimer);
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
				QString message = requete.boundValue(":message").toString();
				message.simplified();
				m_strLastError = message;
			}
		}

		// fermeture de la connexion
		if (fermerConnexion)
			db.close();
	}
	catch (const std::exception&)
	{
	}

	// retour du résultat de la fonction
	return resultat;
}
