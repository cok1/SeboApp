#pragma once
#include <string>
#include <memory>
#include <qsqldatabase.h>
#include <qsqldriver.h>

class Connexion
{
public:
	/// <summary>
	/// Cette fonction permet de récupérer l'instance unique de connexion à la base de données
	/// </summary>
	/// <returns></returns>
	static std::shared_ptr<Connexion> getInstance()
	{
		// Récupération de l'instance unique, si elle n'existe pas, on la créé
		static std::shared_ptr<Connexion> _instance = std::make_shared<Connexion>();

		return _instance;
	}

	/// <summary>
	/// Cette fonction permet d'établir la connexion à la base de données
	/// </summary>
	/// <param name="login">login de l'utilisateur</param>
	/// <param name="password">mot de passe de l'utilisateur</param>
	/// <returns>la connexion active à la base de données</returns>
	QSqlDatabase etablirConnexion(QString login, QString password);

	/// <summary>
	/// Cette méthode permet de se déconnecter de la base de données
	/// </summary>
	void fermerConnexion();

	QSqlDatabase getConnexion();

	Connexion();
	~Connexion();

private:
	static std::shared_ptr<Connexion> _instance;

	std::shared_ptr<QSqlDatabase> connexion;
};