#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Categorie
{
public:
	/// <summary>
	/// Constructeur par d�faut
	/// </summary>
	Categorie();

	/// <summary>
	/// Constructeur param�tr�
	/// </summary>
	/// <param name="libelle">libell� de la cat�gorie</param>
	/// <param name="tva">taux de TVA associ� � la cat�gorie</param>
	/// <param name="id">Identifiant de la cat�gorie (par d�faut -1)</param>
	Categorie(QString libelle, float tva, int id = -1);

	/// <summary>
	/// Destructeur par d�faut
	/// </summary>
	~Categorie();

	/// <summary>
	/// Cette fonction permet de r�cup�rer l'identifiant de la cat�gorie
	/// </summary>
	/// <returns>l'identifiant de la cat�gorie</returns>
	int getId();

	/// <summary>
	/// Cette fonction permet de r�cup�rer le libell� de la cat�gorie
	/// </summary>
	/// <returns>le libell� de la cat�gorie</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de r�cup�rer le taux de TVA associ� � la cat�gorie
	/// </summary>
	/// <returns>le taux de TVA associ� � la cat�gorie</returns>
	float getTauxTva();

	/// <summary>
	/// Cette fonction permet de modifier le libell� de la cat�gorie
	/// </summary>
	/// <param name="libelle">nouveau libell� de la cat�gorie</param>
	/// <returns>true si la modification a �t� effectu�e, false sinon.</returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de modifier le taux de TVA associ� � la cat�gorie
	/// </summary>
	/// <param name="tva">nouveau taux de TVA associ� � la cat�gorie</param>
	/// <returns>true si la modification a �t� faite, false sinon.</returns>
	bool setTauxTva(float tva);

private:
	/// <summary>
	/// Identifiant de la cat�gorie
	/// </summary>
	int m_nId;

	/// <summary>
	/// Libell� de la cat�gorie
	/// </summary>
	QString m_strLibelle;

	/// <summary>
	/// Taux de TVA associ� � la cat�gorie
	/// </summary>
	float m_fTauxTva;
};

