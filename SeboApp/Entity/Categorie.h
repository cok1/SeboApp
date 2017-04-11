#pragma once
#include <qstring.h>
#include <ToolBox.h>
#include <qobject.h>

class Categorie : QObject
{
	Q_OBJECT

public:
	/// <summary>
	/// Constructeur par défaut
	/// </summary>
	Categorie();

	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="libelle">libellé de la catégorie</param>
	/// <param name="tva">taux de TVA associé à la catégorie</param>
	/// <param name="id">Identifiant de la catégorie (par défaut -1)</param>
	Categorie(QString libelle, double tva, int id = -1);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	~Categorie();

	/// <summary>
	/// Cette fonction permet de récupérer l'identifiant de la catégorie
	/// </summary>
	/// <returns>l'identifiant de la catégorie</returns>
	int getId();

	/// <summary>
	/// Cette fonction permet de récupérer le libellé de la catégorie
	/// </summary>
	/// <returns>le libellé de la catégorie</returns>
	QString getLibelle();

	/// <summary>
	/// Cette fonction permet de récupérer le taux de TVA associé à la catégorie
	/// </summary>
	/// <returns>le taux de TVA associé à la catégorie</returns>
	double getTauxTva();

	/// <summary>
	/// Cette fonction permet de modifier le libellé de la catégorie
	/// </summary>
	/// <param name="libelle">nouveau libellé de la catégorie</param>
	/// <returns>true si la modification a été effectuée, false sinon.</returns>
	bool setLibelle(QString libelle);

	/// <summary>
	/// Cette fonction permet de modifier le taux de TVA associé à la catégorie
	/// </summary>
	/// <param name="tva">nouveau taux de TVA associé à la catégorie</param>
	/// <returns>true si la modification a été faite, false sinon.</returns>
	bool setTauxTva(double tva);

	/// <summary>
	/// Cette fonction permet de modifier l'identifiant de la catégorie
	/// </summary>
	/// <param name="id">nouvel identifiant de la catégorie</param>
	/// <returns>true si la modification a été effectuée, false sinon.</returns>
	bool setId(int id);

private:
	/// <summary>
	/// Identifiant de la catégorie
	/// </summary>
	int m_nId;

	/// <summary>
	/// Libellé de la catégorie
	/// </summary>
	QString m_strLibelle;

	/// <summary>
	/// Taux de TVA associé à la catégorie
	/// </summary>
	double m_fTauxTva;
};

