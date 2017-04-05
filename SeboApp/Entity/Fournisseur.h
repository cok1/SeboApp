#pragma once
#include <qstring.h>
#include <ToolBox.h>

class Fournisseur
{
public:
	/// <summary>
	/// Constructeur par d�faut
	/// </summary>
	Fournisseur();

	/// <summary>
	/// Constructeur param�tr�
	/// </summary>
	/// <param name="nomFournisseur">nom du fournisseur</param>
	/// <param name="idFournisseur">identifiant du fournisseur (par d�faut -1)</param>
	Fournisseur(QString nomFournisseur, int idFournisseur = -1);

	/// <summary>
	/// Destructeur par d�faut
	/// </summary>
	~Fournisseur();

	/// <summary>
	/// Cette fonction permet de modifier le nom du fournisseur
	/// </summary>
	/// <param name="nomFournisseur">nouveau nom du fournisseur</param>
	/// <returns>true si la modification a �t� faite, false sinon.</returns>
	bool setNomFournisseur(QString nomFournisseur);

	/// <summary>
	/// Cette fonction permet de r�cup�rer l'identifiant du fournisseur
	/// </summary>
	/// <returns>l'identifiant du fournisseur</returns>
	int getIdFournisseur();

	/// <summary>
	/// Cette fonction permet de r�cup�rer le nom du fournisseur
	/// </summary>
	/// <returns>le nom du fournisseur</returns>
	QString getNomFournisseur();

private:
	/// <summary>
	/// Identifiant du fournisseur
	/// </summary>
	int m_nIdFournisseur;

	/// <summary>
	/// Nom du fournisseur
	/// </summary>
	QString m_strNomFournisseur;
};

