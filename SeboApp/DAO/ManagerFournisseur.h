#pragma once
#include <vector>
#include "Entity\Fournisseur.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <memory>

class ManagerFournisseur
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerFournisseur();

	/// <summary>
	/// Cette fonction permet de récupérer l'ensemble des fournisseurs de la base de données
	/// </summary>
	/// <returns>un vecteur contenant l'ensemble des fournisseurs</returns>
	static vector<shared_ptr<Fournisseur>> getListeFournisseur();

	/// <summary>
	/// Cette fonction permet de récupérer le fournisseur ayant le libellé donné en paramètre
	/// </summary>
	/// <param name="libelle">libellé du fournisseur que l'on souhaite récupéré</param>
	/// <returns>Fournisseur correspondant au libellé fourni.</returns>
	static shared_ptr<Fournisseur> getFournisseurWithName(QString nom);

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du fournisseur ayant le libellé donné en paramètre
	/// </summary>
	/// <param name="libelle">libellé du fournisseur que l'on souhaite récupéré</param>
	/// <returns>L'identifiant du fournisseur correspondant au libellé fourni.</returns>
	static int getIdFournisseur(QString nom);

	/// <summary>
	/// Cette fonction permet d'ajouter un fournisseur dans la base de données
	/// </summary>
	/// <param name="fournisseurAAJouter">fournisseur que l'on souhaite ajouter</param>
	/// <returns>true si l'ajout a été effectué, false sinon.</returns>
	static bool addFournisseur(Fournisseur fournisseurAAJouter);

	/// <summary>
	/// Cette fonction permet d'ajouter un fournisseur à la base de données
	/// </summary>
	/// <param name="NomFournisseur">nom du fournisseur que l'on souhaite ajouter</param>
	/// <returns>true si l'ajout a été effectué, false sinon.</returns>
	static bool addFournisseur(QString NomFournisseur);

	/// <summary>
	/// Cette fonction permet de modifier un fournisseur dans la base de données
	/// </summary>
	/// <param name="fournisseurAModifier">fournisseur que l'on souhaite modifier</param>
	/// <returns>true si la modification a été effectuée, false sinon.</returns>
	static bool modifFournisseur(Fournisseur fournisseurAModifier);

	/// <summary>
	/// Cette fonction permet de supprimer un fournisseur de la base de données
	/// </summary>
	/// <param name="fournisseurASupprimmer">fournisseur que l'on souhaite supprimer</param>
	/// <returns>true si la suppression a été effectuée, false sinon.</returns>
	static bool supFournisseur(Fournisseur fournisseurASupprimmer);

	/// <summary>
	/// Cette fonction permet de supprimer un fournisseur de la base de données
	/// </summary>
	/// <param name="idFournisseurASupprimer">identifiant du fournisseur que l'on souhaite supprimer</param>
	/// <returns>true si la suppression a été effectuée, false sinon.</returns>
	static bool supFournisseur(int idFournisseurASupprimer);

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
	ManagerFournisseur();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

