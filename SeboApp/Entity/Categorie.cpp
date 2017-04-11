#include "Categorie.h"



Categorie::Categorie()
{
}

Categorie::Categorie(QString libelle, double tva, int id): m_strLibelle(libelle), m_fTauxTva(tva), m_nId(id)
{
}


Categorie::~Categorie()
{
}

int Categorie::getId()
{
	return m_nId;
}

QString Categorie::getLibelle()
{
	return QString(m_strLibelle);
}

double Categorie::getTauxTva()
{
	return m_fTauxTva;
}

bool Categorie::setLibelle(QString libelle)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

	// Test du paramètre en entrée
	resultat = ToolBox::isValide(libelle.toStdString(), 1, true);

	// modification de l'attribut
	if (resultat)
	{
		m_strLibelle = libelle;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Categorie::setTauxTva(double tva)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = tva < 1.0f && tva >= 0.0f;

	// modification de l'attribut
	if (resultat)
	{
		m_fTauxTva = tva;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Categorie::setId(int id)
{
	m_nId = id;

	return true;
}
