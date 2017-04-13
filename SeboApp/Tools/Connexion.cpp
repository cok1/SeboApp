#include "Connexion.h"

Connexion::Connexion()
{
}

void Connexion::fermerConnexion()
{
	// fermeture de la base de donnée
	connexion->close();
}

QSqlDatabase Connexion::getConnexion()
{
	return *connexion;
}

Connexion::~Connexion()
{
}

QSqlDatabase Connexion::etablirConnexion(QString login, QString password)
{
	// Vérification de la validité de la connexion
	if (connexion == nullptr || !connexion->isOpen())
	{
		// Création du template de la chaîne de connexion
		QString connectionTemplate = "DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;";

		// Remplissage des paramètres
		QString connectionString = connectionTemplate.arg("serveur-sql2012\\server2012").arg("Sebo_Carys");
		//QString connectionString = connectionTemplate.arg("CORENTIN\\SQLEXPRESS").arg("Sebo_Carys");

		// initialisation de la connexion
		connexion = std::make_shared<QSqlDatabase>();
		*connexion = QSqlDatabase::addDatabase("QODBC3");

		// paramétrage de la connexion
		connexion->setDatabaseName(connectionString);
		connexion->setUserName(login);
		connexion->setPassword(password);
	}

	// retour du résultat de la connexion
	return *connexion;
}
