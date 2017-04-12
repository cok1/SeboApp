#include "ManagerRole.h"


QString ManagerRole::m_strLastError = "";

ManagerRole::ManagerRole()
{
}


ManagerRole::~ManagerRole()
{
}

vector<shared_ptr<Role>> ManagerRole::getListeRole()
{
	// Définitions
	vector<shared_ptr<Role>> listeRole;	// va contenir les rôles récupérées de la base de données

	// Initialisation
	listeRole = vector<shared_ptr<Role>>();

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
		QSqlQuery requete("Select * from Role order by idRole");

		if (!requete.exec())
		{
			m_strLastError = requete.lastError().text();
		}

		// Enregistrement des rôles dans le vecteur
		while (requete.next())
		{
			// Insertion du rôle dans le vecteur
			listeRole.push_back(make_shared<Role>(requete.value("LibelleRole").toString(), requete.value("IdRole").toInt()));
		}
		// fermeture de la connexion
		if (fermerConnexion)
			db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les rôles
	return listeRole;
}

bool ManagerRole::addRole(Role *roleAAjouter)
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
		requete.prepare("EXEC :codeRetour = ps_CreationRoleActeur :libelle, :id, :message");

		// binding des valeurs
		requete.bindValue(":codeRetour", -1, QSql::InOut);
		requete.bindValue(":libelle", roleAAjouter->getLibelle());
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
			// Récupération des valeurs de retour de la procédure stockée
			roleAAjouter->setId(requete.boundValue(":id").toInt());

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

bool ManagerRole::addRole(QString libelleRole)
{
	return addRole(new Role(libelleRole));
}

bool ManagerRole::modifRole(Role *roleAModifier)
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
		requete.prepare("UPDATE RoleActeur set LibelleRoleActeur = :libelle where IdRoleActeur = :id");

		// binding des valeurs
		requete.bindValue(":libelle", roleAModifier->getLibelle());
		requete.bindValue(":id", roleAModifier->getId());

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

bool ManagerRole::supRole(Role *roleASupprimer)
{
	return supRole(roleASupprimer->getId());
}


bool ManagerRole::supRole(int idRoleASupprimer)
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
		requete.prepare("EXEC :codeRetour = ps_SuppressionRoleActeur :idRole, :message");

		// binding des valeurs
		requete.bindValue(":codeRetour", -1, QSql::InOut);
		requete.bindValue(":idRole", idRoleASupprimer);
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