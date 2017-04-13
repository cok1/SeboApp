#pragma once
#include <vector>
#include "Entity\Acteur.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <memory>

class ManagerActeur
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerActeur();

	/// <summary>
	/// Cette fonction permet de récupérer un vecteur contenant l'intégralité des acteurs présent dans la base de données
	/// </summary>
	/// <returns>un vecteur contenant les acteurs de la base de données</returns>
	static vector<shared_ptr<Acteur>> getListeActeur();

	/// <summary>
	/// Cette fonction permet d'ajouter un nouvel acteur dans la base de données
	/// </summary>
	/// <param name="acteurAAjouter">acteur que l'on souhaite ajouter à la base de données</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addActeur(Acteur *acteurAAjouter);

	/// <summary>
	/// Cette méthode permet d'ajouter un acteur dans la base de données
	/// </summary>
	/// <param name="nomActeur">nom de l'acteur à ajouter</param>
	/// <param name="idRole">identifiant du rôle de l'acteur</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addActeur(QString nomActeur, int idRole);
	
	/// <summary>
	/// Cette fonction permet de modifier un acteur dans la base de données
	/// </summary>
	/// <param name="acteurAModifier">acteur que l'on souhaite modifier</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool modifActeur(Acteur *acteurAModifier);

	/// <summary>
	/// Cette fonction permet de supprimer un acteur de la base de données
	/// </summary>
	/// <param name="acteurASupprimer">acteur que l'on souhaite supprimer</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool supActeur(Acteur *acteurASupprimer);

	/// <summary>
	/// Cette fonction permet de supprimer un acteur de la base de données
	/// </summary>
	/// <param name="idActeurASupprimer">identifiant de l'acteur que l'on souhaite supprimer</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool supActeur(int idActeurASupprimer);

	/// <summary>
	/// cette fonction permet de récupérer le dernier message d'erreur
	/// </summary>
	/// <returns>le dernier message d'erreur de la classe</returns>
	static QString getLastError()
	{
		return m_strLastError;
	}

private:	
	/// <summary>
	/// Constructeur par défaut privé pour empêcher l'instanciation de la classe
	/// </summary>
	ManagerActeur();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

