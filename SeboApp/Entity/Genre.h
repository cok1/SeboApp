#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Genre
{
public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Genre();

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="libelle">libellé du genre</param>
	/// <param name="idCategorie">identifiant de la catégorie associée au genre</param>
	/// <param name="id">identifiant du genre (par défaut -1)</param>
	Genre(QString libelle, int idCategorie, int id = -1);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~Genre();


	/// <summary>
	/// Cette fonction permet de modifier le libellé du genre
	/// </summary>
	/// <param name="libelle">nouveau libellé du genre</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant de la catégorie associée au genre
	/// </summary>
	/// <param name="idCategorie">nouvel identifiant de la catégorie associée au genre</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setIdCategorie(int idCategorie);


	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du genre
	/// </summary>
	/// <returns>l'identifiant du genre</returns>
	int getId();

	/// <summary>
	/// Cette fonction permet de récupérer le libellé du genre
	/// </summary>
	/// <returns>libellé du genre</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant de la catégorie associée au genre
	/// </summary>
	/// <returns>l'identifiant de la catégorie associée au genre</returns>
	int getIdCategorie();

private:
	/// <summary>
	/// Identifiant du genre
	/// </summary>
	int m_nId;

	/// <summary>
	/// Libellé du genre
	/// </summary>
	QString m_stLibelle;

	/// <summary>
	/// Identifiant de la catégorie associée au genre
	/// </summary>
	int m_nIdCategorie;
};

