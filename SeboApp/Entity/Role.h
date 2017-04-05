#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Role
{
public:
	/// <summary>
	/// Constructeur par d�faut
	/// </summary>
	Role();

	/// <summary>
	/// Constructeur param�tr�
	/// </summary>
	/// <param name="libelle">libell� du r�le</param>
	/// <param name="id">id du r�le (par d�faut -1)</param>
	Role(QString libelle, int id = -1);

	/// <summary>
	/// Destructeur par d�faut
	/// </summary>
	~Role();

	/// <summary>
	/// Cette m�thode permet de modifier le libell� du r�le 
	/// </summary>
	/// <param name="libelle"></param>
	/// <returns></returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de r�cup�rer le libell� du r�le
	/// </summary>
	/// <returns>le libell� du r�le</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de r�cup�rer l'id du r�le
	/// </summary>
	/// <returns>l'id du r�le</returns>
	int getId();

private:
	/// <summary>
	/// Id du r�le
	/// </summary>
	int m_nId;

	/// <summary>
	/// Libell� du r�le
	/// </summary>
	QString m_strLibelle;
};

