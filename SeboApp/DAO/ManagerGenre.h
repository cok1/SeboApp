#pragma once

#include <vector>
#include "Entity\Genre.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>
#include <memory>

class ManagerGenre
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerGenre();

	/// <summary>
	/// Cette fonction permet de récupérer la liste des genres contenus dans la base de données
	/// </summary>
	/// <returns>un vecteur contenant la liste des genres contenus dans la base de données.</returns>
	static vector<shared_ptr<Genre>> getListeGenre();

	/// <summary>
	/// Cette fonction permet de récupérer le genre avec le libellé fourni en paramètre
	/// </summary>
	/// <param name="libelle">libellé du genre que l'on souhaite récupérer</param>
	/// <returns>le genre correspondant au libellé fourni</returns>
	static shared_ptr<Genre> getGenreWithLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du genre avec le libellé fourni en paramètre
	/// </summary>
	/// <param name="libelle">libellé du genre que l'on souhaite récupérer</param>
	/// <returns>L'identifiant du genre correspondant au libellé fourni</returns>
	static int getIdGenre(QString libelle);

	/// <summary>
	/// Cette fonction permet d'ajouter un genre dans la base de données
	/// </summary>
	/// <param name="genreAAjouter">Genre que l'on souhaite ajouté dans la base de données</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addGenre(Genre genreAAjouter);

	/// <summary>
	/// Cette fonction permet s'ajouter un genre dans la base de données
	/// </summary>
	/// <param name="libelle">libellé du genre à ajouter</param>
	/// <param name="idCategorie">id de la catégorie associée au genre</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addGenre(QString libelle, int idCategorie);

	/// <summary>
	/// Cette fonction permet de modifier un genre dans la base de données
	/// </summary>
	/// <param name="genreAModifier">catégorie que l'on souhaite modifier</param>
	/// <returns>true si la modification a été effectuée, false sinon.</returns>
	static bool modifGenre(Genre genreAModifier);

	/// <summary>
	/// Cette fonction permet de supprimer un genre de la base de donnée
	/// </summary>
	/// <param name="genreASupprimer">genre que l'on souhaite supprimer</param>
	/// <returns>true si la suppression à été effectuée, false sinon.</returns>
	static bool supGenre(Genre genreASupprimer);

	/// <summary>
	/// Cette fonction permet de supprimer un genre de la base de donnée
	/// </summary>
	/// <param name="idGenreASupprimer">id du genre à supprimer</param>
	/// <returns>true si la suppression à été effectuée, false sinon.</returns>
	static bool supGenre(int idGenreASupprimer);

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
	ManagerGenre();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

