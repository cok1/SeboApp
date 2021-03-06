#include "Article.h"



Article::Article()
{
}

Article::Article(const Article &article)
{
	m_fPrix = article.m_fPrix;
	m_fPrixFournisseur = article.m_fPrixFournisseur;
	m_isReapprovisionnable = article.m_isReapprovisionnable;
	m_nIdFournisseur = article.m_nIdFournisseur;
	m_nIdGenre = article.m_nIdGenre;
	m_nReference = article.m_nReference;
	m_strDescription = article.m_strDescription;
	m_strLibelle = article.m_strLibelle;
	m_strPhoto = article.m_strPhoto;
}

Article::Article(QString libelle, float prix, QString photo, QString description, int idGenre, float prixFournisseur, int idFournisseur, bool reapprovisionnable, int reference)
	: m_strLibelle(libelle), m_fPrix(prix), m_strPhoto(photo), m_strDescription(description), m_nIdGenre(idGenre), m_fPrixFournisseur(prixFournisseur), m_nIdFournisseur(idFournisseur), m_isReapprovisionnable(reapprovisionnable), m_nReference(reference)
{
}


Article::~Article()
{
}

Article& Article::operator=(const Article& article)
{
	if (this != &article)
	{
		Article tmp(article);
		swap(tmp);
	}
	return *this;
}

void Article::swap(Article & autreArticle) throw()
{
	using std::swap;
	swap(m_fPrix, autreArticle.m_fPrix);
	swap(m_fPrixFournisseur, autreArticle.m_fPrixFournisseur);
	swap(m_isReapprovisionnable, autreArticle.m_isReapprovisionnable);
	swap(m_nIdFournisseur, autreArticle.m_nIdFournisseur);
	swap(m_nIdGenre, autreArticle.m_nIdGenre);
	swap(m_nReference, autreArticle.m_nReference);
	swap(m_strDescription, autreArticle.m_strDescription);
	swap(m_strLibelle, autreArticle.m_strLibelle);
	swap(m_strPhoto, autreArticle.m_strPhoto);
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

bool Article::setPhoto(QString photo)
{
	m_strPhoto = photo;
	return true;
}

bool Article::setDescription(QString description)
{
	m_strDescription = description;
	return true;
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

QString Article::getPhoto()
{
	return QString(m_strPhoto);
}

QString Article::getDescription()
{
	return QString(m_strDescription);
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
