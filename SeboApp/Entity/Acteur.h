#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Acteur
{
public:
	/// <summary>
	/// Constructeur par d�faut
	/// </summary>
	Acteur();

	/// <summary>
	/// Constructeur param�tr�
	/// </summary>
	/// <param name="nom">nom de l'acteur</param>
	/// <param name="idRole">id du r�le de l'acteur</param>
	/// <param name="id">id de l'acteur (par d�faut -1)</param>
	Acteur(QString nom, int idRole, int id = -1);

	/// <summary>
	/// Destructeur par d�faut
	/// </summary>
	~Acteur();

	/// <summary>
	/// Cette fonction permet de modifier le nom de l'acteur
	/// </summary>
	/// <param name="nom">nouveau nom de l'acteur</param>
	/// <returns>true si la modification a eu lieu, false sinon.</returns>
	bool setNom(QString nom);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant du r�le de l'acteur
	/// </summary>
	/// <param name="idRole">nouvel identifiant du r�le de l'acteur</param>
	/// <returns>true si la modification a eu lieu, false sinon.</returns>
	bool setIdRole(int idRole);

	/// <summary>
	/// Cette fonction permet de r�cup�rer l'identifiant de l'acteur
	/// </summary>
	/// <returns>l'identifiant de l'acteur</returns>
	int getId();

	/// <summary>
	/// Cette fonction permet de r�cup�rer le nom de l'acteur
	/// </summary>
	/// <returns>le nom de l'acteur</returns>
	QString getNom();

	/// <summary>
	/// Cette fonction permet de r�cup�rer l'identifiant du r�le de l'acteur
	/// </summary>
	/// <returns>l'identifiant du r�le de l'acteur</returns>
	int getIdRole();

private:
	/// <summary>
	/// identifiant de l'acteur
	/// </summary>
	int m_nId;

	/// <summary>
	/// Nom de l'acteur
	/// </summary>
	QString m_strNom;

	/// <summary>
	/// R�le de l'acteur
	/// </summary>
	int m_nIdRole;
};

