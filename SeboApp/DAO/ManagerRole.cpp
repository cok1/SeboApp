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

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete("Select * from Role order by idRole");

		// Enregistrement des rôles dans le vecteur
		while (requete.next())
		{
			// Insertion du rôle dans le vecteur
			listeRole.push_back(make_shared<Role>(requete.value("LibelleRole").toString(), requete.value("IdRole").toInt()));
		}
		db.close();
	}
	catch (const std::exception& e)
	{
		m_strLastError = e.what();
	}

	// retour du vecteur contenant les rôles
	return listeRole;
}

bool ManagerRole::addRole(Role roleAAjouter)
{
	return addRole(roleAAjouter.getLibelle());
}

bool ManagerRole::addRole(QString libelleRole)
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
		requete.prepare("INSERT INTO Role (LibelleRole) VALUES (:libelle)");

		// binding des valeurs
		requete.bindValue(":libelle", libelleRole);

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

bool ManagerRole::modifRole(Role roleAModifier)
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
		requete.prepare("UPDATE Role set libelleRole=:libelle where idRole=:id");

		// binding des valeurs
		requete.bindValue(":libelle", roleAModifier.getLibelle());
		requete.bindValue(":id", roleAModifier.getId());

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

bool ManagerRole::supRole(Role roleASupprimer)
{
	return supRole(roleASupprimer.getId());
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

		// ouverture de la connexion
		db.open();

		// Création de la requête
		QSqlQuery requete;
		requete.prepare("delete from Role where idRole= :idRole");

		// binding des valeurs
		requete.bindValue(":idRole", idRoleASupprimer);

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