#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Article
{
public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Article();

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="libelle">libellé de l'article</param>
	/// <param name="prix">prix de vente de l'article HT</param>
	/// <param name="idGenre">genre de l'article</param>
	/// <param name="prixFournisseur">prix d'achat</param>
	/// <param name="idFournisseur">identifiant du fournisseur de l'article</param>
	/// <param name="reference">référence de l'article (par défaut -1)</param>
	Article(QString libelle, float prix, int idGenre, float prixFournisseur, int idFournisseur, int reference=-1);

	/// <summary>
	/// Destructeur par défaut de l'article
	/// </summary>
	~Article();
	
	/// <summary>
	/// Cette fonction permet de modifier le libellé de l'article
	/// </summary>
	/// <param name="libelle">nouveau libellé de l'article</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de modifier le prix de vente de l'article
	/// </summary>
	/// <param name="prix">nouveau prix de vente HT</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setPrix(float prix);

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du genre de l'article
	/// </summary>
	/// <param name="idGenre">identifiant du genre de l'article</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setIdGenre(int idGenre);

	/// <summary>
	/// Cette fonction permet de modifier le prix d'achat de l'article
	/// </summary>
	/// <param name="prixFournisseur">nouveau prix d'achat</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setPrixFournisseur(float prixFournisseur);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant du fournisseur
	/// </summary>
	/// <param name="idFournisseur">identifiant du fournisseur</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setIdFournisseur(int idFournisseur);

	/// <summary>
	/// Cette fonction permet de récupérer la référence de l'article
	/// </summary>
	/// <returns>la référence de l'article</returns>
	int getReference();

	/// <summary>
	/// Cette fonction permet de récupérer le libellé de l'article
	/// </summary>
	/// <returns>le libellé de l'article</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de récupérer le prix de vente HT de l'article
	/// </summary>
	/// <returns>le prix de vente HT de l'article</returns>
	float getPrix();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du genre de l'article
	/// </summary>
	/// <returns>l'identifiant du genre de l'article</returns>
	int getIdGenre();

	/// <summary>
	/// Cette fonction permet de récupérer le prix d'achat de l'article
	/// </summary>
	/// <returns>le prix d'achat de l'article</returns>
	float getPrixFournisseur();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du fournisseur de l'article
	/// </summary>
	/// <returns>l'identifiant du fournisseur de l'article</returns>
	int getIdFournisseur();

private:
	/// <summary>
	/// Référence de l'article
	/// </summary>
	int m_nReference;

	/// <summary>
	/// Libellé de l'article
	/// </summary>
	QString m_strLibelle;

	/// <summary>
	/// Prix de vente Hors Taxe de l'article
	/// </summary>
	float m_fPrix;

	/// <summary>
	/// Identifiant du genre de l'article
	/// </summary>
	int m_nIdGenre;

	/// <summary>
	/// Prix d'achat de l'article
	/// </summary>
	float m_fPrixFournisseur;

	/// <summary>
	/// Identifiant du fournisseur de l'article
	/// </summary>
	int m_nIdFournisseur;
};

