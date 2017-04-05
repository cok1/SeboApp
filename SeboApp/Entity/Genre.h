#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Genre
{
public:
	/// <summary>
	/// Constructeur par d�faut
	/// </summary>
	Genre();

	/// <summary>
	/// Constructeur param�tr�
	/// </summary>
	/// <param name="libelle">libell� du genre</param>
	/// <param name="idCategorie">identifiant de la cat�gorie associ�e au genre</param>
	/// <param name="id">identifiant du genre (par d�faut -1)</param>
	Genre(QString libelle, int idCategorie, int id = -1);

	/// <summary>
	/// Destructeur par d�faut
	/// </summary>
	~Genre();


	/// <summary>
	/// Cette fonction permet de modifier le libell� du genre
	/// </summary>
	/// <param name="libelle">nouveau libell� du genre</param>
	/// <returns>true si la modification a �t� faite, false sinon.</returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant de la cat�gorie associ�e au genre
	/// </summary>
	/// <param name="idCategorie">nouvel identifiant de la cat�gorie associ�e au genre</param>
	/// <returns>true si la modification a �t� faite, false sinon.</returns>
	bool setIdCategorie(int idCategorie);


	/// <summary>
	/// Cette fonction permet de r�cup�rer l'identifiant du genre
	/// </summary>
	/// <returns>l'identifiant du genre</returns>
	int getId();

	/// <summary>
	/// Cette fonction permet de r�cup�rer le libell� du genre
	/// </summary>
	/// <returns>libell� du genre</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de r�cup�rer l'identifiant de la cat�gorie associ�e au genre
	/// </summary>
	/// <returns>l'identifiant de la cat�gorie associ�e au genre</returns>
	int getIdCategorie();

private:
	/// <summary>
	/// Identifiant du genre
	/// </summary>
	int m_nId;

	/// <summary>
	/// Libell� du genre
	/// </summary>
	QString m_stLibelle;

	/// <summary>
	/// Identifiant de la cat�gorie associ�e au genre
	/// </summary>
	int m_nIdCategorie;
};

