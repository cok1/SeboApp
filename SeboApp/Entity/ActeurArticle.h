#pragma once
#include <qstring.h>
#include <ToolBox.h>

class ActeurArticle
{
public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	ActeurArticle();

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="referenceArticle">référence de l'article</param>
	/// <param name="idActeur">identifiant de l'acteur</param>
	ActeurArticle(int referenceArticle, int idActeur);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~ActeurArticle();

	/// <summary>
	/// Cette fonction permet de modifier la référence de l'article associée à l'acteur
	/// </summary>
	/// <param name="referenceArticle">nouvelle référence de l'article associée à l'acteur</param>
	/// <returns>true si la modification a pu se faire, false sinon.</returns>
	bool setReferenceArticle(int referenceArticle);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant de l'acteur associé à l'article
	/// </summary>
	/// <param name="idActeur">nouvel identifiant de l'acteur associé à l'article</param>
	/// <returns>true si la modification a pu se faire, false sinon.</returns>
	bool setIdActeur(int idActeur);

	/// <summary>
	/// Cette fonction permet de récupérer la référence de l'article associé à l'acteur
	/// </summary>
	/// <returns>la référence de l'article</returns>
	int getReferenceArticle();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant de l'acteur associé à l'article
	/// </summary>
	/// <returns>l'identifiant de l'article</returns>
	int getIdActeur();
private:
	/// <summary>
	/// Référence de l'article
	/// </summary>
	int m_nReferenceArticle;

	/// <summary>
	/// Identifiant de l'article
	/// </summary>
	int m_nIdActeur;
};

