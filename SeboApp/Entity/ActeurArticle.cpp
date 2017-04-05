#include "ActeurArticle.h"



ActeurArticle::ActeurArticle()
{
}

ActeurArticle::ActeurArticle(int referenceArticle, int idActeur): m_nReferenceArticle(referenceArticle), m_nIdActeur(idActeur)
{
}


ActeurArticle::~ActeurArticle()
{
}

bool ActeurArticle::setReferenceArticle(int referenceArticle)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_nReferenceArticle = referenceArticle;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool ActeurArticle::setIdActeur(int idActeur)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_nIdActeur = idActeur;
	}

	// retour du résultat de la fonction
	return resultat;
}

int ActeurArticle::getReferenceArticle()
{
	return m_nReferenceArticle;
}

int ActeurArticle::getIdActeur()
{
	return m_nIdActeur;
}
