#pragma once
#include <qobject.h>
#include <qmetatype.h>
#include <qstring.h>
#include <ToolBox.h>

class Article: public QObject
{
	Q_OBJECT
	Q_CLASSINFO("author", "Corentin Rogeré")
	
public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Article();

	/// <summary>
	/// Constructeur de copie de la classe article
	/// </summary>
	/// <param name="article">article à partir duquel on souhaite construire le nouvel article</param>
	Article(const Article &article);

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="libelle">libellé de l'article</param>
	/// <param name="prix">prix de vente de l'article HT</param>
	/// <param name="photo">chemin de la photo de l'article</param>
	/// <param name="description">description de l'article</param>
	/// <param name="idGenre">genre de l'article</param>
	/// <param name="prixFournisseur">prix d'achat</param>
	/// <param name="idFournisseur">identifiant du fournisseur de l'article</param>
	/// <param name="reapprovisionnable">permet de savoir si l'article est réapprovisionnable</param>
	/// <param name="reference">référence de l'article (par défaut -1)</param>
	Article(QString libelle, double prix, QString photo, QString description, int idGenre, double prixFournisseur, int idFournisseur, bool reapprovisionnable, int reference=-1);

	/// <summary>
	/// Destructeur par défaut de l'article
	/// </summary>
	~Article();

	/// <summary>
	/// Redéfinition de l'opérateur d'affectation
	/// </summary>
	/// <param name="article">article que l'on veut affecter à l'article d'origine</param>
	/// <returns>la copie de l'article d'origine</returns>
	Article& operator =(const Article& article);

	/// <summary>
	/// Cette fonction permet de récupérer les attributs d'un autre article
	/// </summary>
	/// <param name="autreArticle">article à partir duquel on souhaite récupérer les attributs</param>
	/// <returns>l'article avec les attributs récupérés</returns>
	void swap(Article& autreArticle) throw();



	//**********************************************************************************************************************************************
	//															Modificateurs
	//**********************************************************************************************************************************************
	
	/// <summary>
	/// Cette fonction permet de modifier la référence de l'article
	/// </summary>
	/// <param name="reference">nouvelle référence</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setReference(int reference);

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
	bool setPrix(double prix);

	/// <summary>
	/// Cette fonction permet de modifier le nom du fichier contenant la photo l'article
	/// </summary>
	/// <param name="photo">nom du fichier contenant la photo de l'article</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setPhoto(QString photo);

	/// <summary>
	/// Cette fonction permet de modifier la description de l'article
	/// </summary>
	/// <param name="description">description de l'article</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setDescription(QString description);

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
	bool setPrixFournisseur(double prixFournisseur);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant du fournisseur
	/// </summary>
	/// <param name="idFournisseur">identifiant du fournisseur</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setIdFournisseur(int idFournisseur);

	/// <summary>
	/// Cette fonction permet de modifier la possibilité de réapprovisionnement
	/// </summary>
	/// <param name="etat">nouvel état de réapprovisionnement</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setReapprovissionnable(bool etat);


	//**********************************************************************************************************************************************
	//															Accesseur
	//**********************************************************************************************************************************************

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
	/// Cette fonction permet de récupérer le nom de fichier de la photo de l'article avec l'extension
	/// </summary>
	/// <returns>le nom de fichier de la photo de l'article avec l'extension</returns>
	QString getPhoto();

	/// <summary>
	/// Cette fonction permet de récupérer la description de l'article
	/// </summary>
	/// <returns>la description de l'article</returns>
	QString getDescription();

	/// <summary>
	/// Cette fonction permet de récupérer le prix de vente HT de l'article
	/// </summary>
	/// <returns>le prix de vente HT de l'article</returns>
	double getPrix();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du genre de l'article
	/// </summary>
	/// <returns>l'identifiant du genre de l'article</returns>
	int getIdGenre();

	/// <summary>
	/// Cette fonction permet de récupérer le prix d'achat de l'article
	/// </summary>
	/// <returns>le prix d'achat de l'article</returns>
	double getPrixFournisseur();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du fournisseur de l'article
	/// </summary>
	/// <returns>l'identifiant du fournisseur de l'article</returns>
	int getIdFournisseur();

	/// <summary>
	/// Cette fonction permet de savoir si l'article est réapprovisionnable
	/// </summary>
	/// <returns>true si l'article est réapprovisionnable, false sinon.</returns>
	bool isReapprovisionnable();

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
	/// nom du fichier contenant la photo avec l'extension
	/// </summary>
	QString m_strPhoto;

	/// <summary>
	/// Description complète de l'article
	/// </summary>
	QString m_strDescription;

	/// <summary>
	/// Prix de vente Hors Taxe de l'article
	/// </summary>
	double m_fPrix;

	/// <summary>
	/// Identifiant du genre de l'article
	/// </summary>
	int m_nIdGenre;

	/// <summary>
	/// Prix d'achat de l'article
	/// </summary>
	double m_fPrixFournisseur;

	/// <summary>
	/// Identifiant du fournisseur de l'article
	/// </summary>
	int m_nIdFournisseur;

	/// <summary>
	/// Permet de savoir si l'article est réapprovisionnable
	/// </summary>
	bool m_isReapprovisionnable;
};

Q_DECLARE_METATYPE(Article)