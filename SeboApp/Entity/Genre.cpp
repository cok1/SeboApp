#include "Genre.h"



Genre::Genre()
{
}

Genre::Genre(QString libelle, int idCategorie, int id):m_stLibelle(libelle), m_nIdCategorie(idCategorie), m_nId(id)
{
}


Genre::~Genre()
{
}

bool Genre::setLibelle(QString libelle)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

	// Test du paramètre en entrée
	resultat = ToolBox::isValide(libelle.toStdString(), 1, true);

	// modification de l'attribut
	if (resultat)
	{
		m_stLibelle = libelle;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Genre::setIdCategorie(int idCategorie)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_nIdCategorie = idCategorie;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Genre::setId(int id)
{
	// Déclarations
	bool resultat;

	resultat = id > 0 && m_nId == -1;

	if (resultat)
		m_nId = id;

	return resultat;
}

int Genre::getId()
{
	return m_nId;
}

QString Genre::getLibelle()
{
	return QString(m_stLibelle);
}

int Genre::getIdCategorie()
{
	return m_nIdCategorie;
}
