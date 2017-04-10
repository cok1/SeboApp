#pragma once
#include <vector>
#include "Entity\Categorie.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>
#include <memory>

class ManagerCategorie
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerCategorie();

	/// <summary>
	/// Cette fonction permet de récupérer un vecteur contenant les catégories contenues dans la base de données
	/// </summary>
	/// <returns>un vecteur contenant l'intégralité des catégorie de la base de données</returns>
	static vector<shared_ptr<Categorie>> getListCategorie();

	/// <summary>
	/// Cette fonction permet de récupérer la catégorie correspondante au libelle fourni en paramètre
	/// </summary>
	/// <param name="libelle">libelle de la catégorie que l'on souhaite récupérer</param>
	/// <returns>la catégorie correspondante au libellé fourni</returns>
	static shared_ptr<Categorie> getCategorieWithLibelle(QString libelle);

	/// <summary>
	/// Cette Méthode permet de supprimer une catégorie de la base de données
	/// </summary>
	/// <param name="catASupprimer">Catégorie à supprimer</param>
	/// <returns>true si la suppression a été réalisé, false sinon.</returns>
	static bool supCategorie(Categorie catASupprimer);

	/// <summary>
	/// Cette Méthode permet de supprimer une catégorie de la base de données
	/// </summary>
	/// <param name="idCategorie">id de la catégorie à supprimer</param>
	/// <returns>true si la suppression a été réalisé, false sinon.</returns>
	static bool supCategorie(int idCategorie);

	/// <summary>
	/// Cette méthode permet d'ajouter une catégorie à la base de données
	/// </summary>
	/// <param name="catAAjouter">Catégorie que l'on souhaite ajouter</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addCategorie(Categorie *catAAjouter);

	/// <summary>
	/// Cette méthode permet d'ajouter une catégorie à la base de données
	/// </summary>
	/// <param name="libelle">libellé de la catégorie à ajouter</param>
	/// <param name="tauxTva">taux de TVA de la catégorie</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addCategorie(QString libelle, double tauxTva);

	/// <summary>
	/// Cette méthode permet de modifier une catégorie
	/// </summary>
	/// <param name="categorieAModifier">catégorie que l'on souhaite modifier</param>
	/// <returns>true si la modification a été effectuée, false sinon.</returns>
	static bool modifCategorie(Categorie categorieAModifier);

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
	/// Constructeur privé pour empêcher la création d'une instance de cette classe
	/// </summary>
	ManagerCategorie();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

