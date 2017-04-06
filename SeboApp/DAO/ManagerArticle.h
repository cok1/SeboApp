#pragma once
#include <memory>
#include <vector>
#include "Entity\Article.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>
#include <qstring.h>

class ManagerArticle
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerArticle();

	/// <summary>
	/// Cette fonction permet de récupérer l'ensemble des articles du stocks
	/// </summary>
	/// <returns>un vecteur contenant l'ensemble des articles de la base de données</returns>
	static vector<shared_ptr<Article>> getListeArticle();

	/// <summary>
	/// Cette fonction permet d'ajouter un article dans la base de données
	/// </summary>
	/// <param name="newArticle">Article à ajouter</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addArticle(Article newArticle);

	/// <summary>
	/// Cette fonction permet d'ajouter un article dans la base de données
	/// </summary>
	/// <param name="libelle">libellé de l'article à ajouter</param>
	/// <param name="prixVenteHT">prix de vente hors taxe de l'article</param>
	/// <param name="idGenre">identifiant du genre de l'article</param>
	/// <param name="prixFournisseur">prix d'achat fournisseur de l'article</param>
	/// <param name="idFournisseur">identifiant du fournisseur de l'article</param>
	/// <returns>true si l'ajout a été réalisé, false sinon.</returns>
	static bool addArticle(QString libelle, double prixVenteHT, int idGenre, double prixFournisseur, int idFournisseur, bool isReapprovisionnable);

	/// <summary>
	/// Cette fonction permet de modifier un article de la base de données
	/// </summary>
	/// <param name="articleAModifier">article que l'on souhaite modifier</param>
	/// <returns>true si la modification a été réalisée, false sinon.</returns>
	static bool modifArticle(Article articleAModifier);

	/// <summary>
	/// Cette fonction permet de supprimer un article de la base de données
	/// </summary>
	/// <param name="articleASup">article à supprimer de la base de données</param>
	/// <returns>true si la suppression a été réalisée, false sinon.</returns>
	static bool supArticle(Article articleASup);

	/// <summary>
	/// Cette fonction permet de supprimer un article de la base de données
	/// </summary>
	/// <param name="refArticle">référence de l'article que l'on souhaite supprimer</param>
	/// <returns>true si la suppression a été réalisée, false sinon.</returns>
	static bool supArticle(int refArticle);

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
	/// Constructeur par défaut privé pour empêcher 
	/// </summary>
	ManagerArticle();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

