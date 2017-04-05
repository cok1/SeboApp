#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Role
{
public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Role();

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="libelle">libellé du rôle</param>
	/// <param name="id">id du rôle (par défaut -1)</param>
	Role(QString libelle, int id = -1);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~Role();

	/// <summary>
	/// Cette méthode permet de modifier le libellé du rôle 
	/// </summary>
	/// <param name="libelle"></param>
	/// <returns></returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de récupérer le libellé du rôle
	/// </summary>
	/// <returns>le libellé du rôle</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de récupérer l'id du rôle
	/// </summary>
	/// <returns>l'id du rôle</returns>
	int getId();

private:
	/// <summary>
	/// Id du rôle
	/// </summary>
	int m_nId;

	/// <summary>
	/// Libellé du rôle
	/// </summary>
	QString m_strLibelle;
};

