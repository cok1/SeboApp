#include "Article.h"



Article::Article()
{
}

Article::Article(QString libelle, float prix, int idGenre, float prixFournisseur, int idFournisseur, bool reapprovisionnable, int reference)
	: m_strLibelle(libelle), m_fPrix(prix), m_nIdGenre(idGenre), m_fPrixFournisseur(prixFournisseur), m_nIdFournisseur(idFournisseur), m_isReapprovisionnable(reapprovisionnable), m_nReference(reference)
{
}


Article::~Article()
{
}

bool Article::setLibelle(QString libelle)
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

bool Article::setPrix(float prix)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_fPrix = prix;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Article::setIdGenre(int idGenre)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_nIdGenre = idGenre;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Article::setPrixFournisseur(float prixFournisseur)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_fPrixFournisseur = prixFournisseur;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Article::setIdFournisseur(int idFournisseur)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_nIdFournisseur = idFournisseur;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Article::setReapprovissionnable(bool etat)
{
	m_isReapprovisionnable = etat;

	return true;
}

int Article::getReference()
{
	return m_nReference;
}

QString Article::getLibelle()
{
	return QString(m_strLibelle);
}

float Article::getPrix()
{
	return m_fPrix;
}

int Article::getIdGenre()
{
	return m_nIdGenre;
}

float Article::getPrixFournisseur()
{
	return m_fPrixFournisseur;
}

int Article::getIdFournisseur()
{
	return m_nIdFournisseur;
}

bool Article::isReapprovisionnable()
{
	return m_isReapprovisionnable;
}
