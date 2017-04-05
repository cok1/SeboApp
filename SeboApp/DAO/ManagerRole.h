#pragma once
#include <vector>
#include "Entity\Role.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>

class ManagerRole
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerRole();

	/// <summary>
	/// Cette fonction permet de récupérer l'ensemble des rôles de la base de données
	/// </summary>
	/// <returns>un vecteur contenant l'ensemble des rôles de la base de données</returns>
	static vector<shared_ptr<Role>> getListeRole();

	/// <summary>
	/// Cette fonction permet d'ajouter un rôle dans la base de données
	/// </summary>
	/// <param name="roleAAjouter">rôle que l'on souhaite ajouter dans la base de données</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addRole(Role roleAAjouter);
	
	/// <summary>
	/// Cette fonction permet d'ajouter un rôle dans la base de données
	/// </summary>
	/// <param name="libelleRole">libellé du rôle que l'on souhaite ajouter</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addRole(QString libelleRole);

	/// <summary>
	/// Cette fonction permet de modifier un rôle dans la base de données
	/// </summary>
	/// <param name="roleAModifier">rôle que l'on souhaite modifier</param>
	/// <returns>true si la modification a été réalisée, false sinon.</returns>
	static bool modifRole(Role roleAModifier);

	/// <summary>
	/// Cette fonction permet de supprimer un rôle dans la base de données
	/// </summary>
	/// <param name="roleASupprimer">rôle que l'on souhaite supprimer</param>
	/// <returns>true si la suppression a été réalisée, false sinon.</returns>
	static bool supRole(Role roleASupprimer);

	/// <summary>
	/// Cette fonction permet de supprimer un rôle dans la base de données
	/// </summary>
	/// <param name="idRoleASupprimer">identifiant du rôle que l'on souhaite supprimer</param>
	/// <returns>true si la suppression a été réalisée, false sinon.</returns>
	static bool supRole(int idRoleASupprimer);

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
	ManagerRole();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

