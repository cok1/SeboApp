#pragma once
#include <qobject.h>
#include <qstring.h>
#include <ToolBox.h>

class Fournisseur : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("author", "Corentin Rogeré")

public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Fournisseur();

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="nomFournisseur">nom du fournisseur</param>
	/// <param name="idFournisseur">identifiant du fournisseur (par défaut -1)</param>
	Fournisseur(QString nomFournisseur, int idFournisseur = -1);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~Fournisseur();

	/// <summary>
	/// Cette fonction permet de modifier le nom du fournisseur
	/// </summary>
	/// <param name="nomFournisseur">nouveau nom du fournisseur</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setNomFournisseur(QString nomFournisseur);

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant du fournisseur
	/// </summary>
	/// <returns>l'identifiant du fournisseur</returns>
	int getIdFournisseur();

	/// <summary>
	/// Cette fonction permet de récupérer le nom du fournisseur
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