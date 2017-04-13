#pragma once
#include <qobject.h>
#include <qstring.h>
#include <qmetatype.h>
#include <ToolBox.h>

class Acteur : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("author", "Corentin Rogeré")

public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Acteur();

	Acteur(const Acteur &acteur);

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="nom">nom de l'acteur</param>
	/// <param name="idRole">id du rôle de l'acteur</param>
	/// <param name="id">id de l'acteur (par défaut -1)</param>
	Acteur(QString nom, int idRole, int id = -1);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~Acteur();

	/// <summary>
	/// Cette fonction permet de mettre à jour l'identifiant de l'acteur
	/// </summary>
	/// <param name="id">nouvel identifiant de l'acteur</param>
	/// <returns>true si la modification a eu lieu, false sinon.</returns>
	bool setId(int id);

	/// <summary>
	/// Cette fonction permet de modifier le nom de l'acteur
	/// </summary>
	/// <param name="nom">nouveau nom de l'acteur</param>
	/// <returns>true si la modification a eu lieu, false sinon.</returns>
	bool setNom(QString nom);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant du rôle de l'acteur
	/// </summary>
	/// <param name="idRole">nouvel identifiant du rôle de l'acteur</param>
	/// <returns>true si la modification a eu lieu, false sinon.</returns>
	bool setIdRole(int idRole);

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant de l'acteur
	/// </summary>
	/// <returns>l'identifiant de l'acteur</returns>
	int getId();

	/// <summary>
	/// Cette fonction permet de récupérer le nom de l'acteur
	/// </summary>
	/// <returns>le nom de l'acteur</returns>
	QString getNom();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du rôle de l'acteur
	/// </summary>
	/// <returns>l'identifiant du rôle de l'acteur</returns>
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
	/// Rôle de l'acteur
	/// </summary>
	int m_nIdRole;
};

Q_DECLARE_METATYPE(Acteur)