#pragma once
#include <memory>
#include <vector>
#include "Entity\ActeurArticle.h"
#include "Tools\Connexion.h"
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>

class ManagerActeurArticle
{
public:
	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ManagerActeurArticle();

	/// <summary>
	/// Cette fonction permet de récupérer la liste des relations acteurs/articles de la base de données
	/// </summary>
	/// <returns>la liste des acteurs par articles</returns>
	static vector<shared_ptr<ActeurArticle>> getListeActeurArticle();

	/// <summary>
	/// Cette fonction permet de supprimer une relation acteur article de la base de données
	/// </summary>
	/// <param name="acteurArticleAAjouter">relation acteur article que l'on souhaite ajouter</param>
	/// <returns>true si l'ajout a été effectué, false sinon.</returns>
	static bool addActeurArticle(ActeurArticle acteurArticleAAjouter);

	/// <summary>
	/// Cette fonction permet de supprimer une relation acteur article de la base de données
	/// </summary>
	/// <param name="idActeur">identifiant de l'acteur</param>
	/// <param name="refArticle">référence de l'article</param>
	/// <returns>true si l'ajout a été effectué, false sinon.</returns>
	static bool addActeurArticle(int idActeur, int refArticle);

	/// <summary>
	/// Cette fonction permet de supprimer une relation acteur/Article de la base de données
	/// </summary>
	/// <param name="acteurArticleASupprimer">relation acteur article à supprimer</param>
	/// <returns>true si la suppression a été effectuée, false sinon.</returns>
	static bool supActeurArticle(ActeurArticle acteurArticleASupprimer);

	/// <summary>
	/// Cette fonction permet de supprimer une relation acteur/Article de la base de données
	/// </summary>
	/// <param name="idActeur">identifiant de l'acteur de la relation</param>
	/// <param name="refArticle">référence de l'article de la relation</param>
	/// <returns>true si la suppression a été effectuée, false sinon.</returns>
	static bool supActeurArticle(int idActeur, int refArticle);

	/// <summary>
	/// Cette fonction le dernier message d'erreur de la classe
	/// </summary>
	/// <returns>le dernier message d'erreur</returns>
	static QString getLastError();

private:
	/// <summary>
	/// Constructeur par défaut privé pour empêcher l'instanciation de la classe
	/// </summary>
	ManagerActeurArticle();

	/// <summary>
	/// Stocke le dernier message d'erreur
	/// </summary>
	static QString m_strLastError;
};

