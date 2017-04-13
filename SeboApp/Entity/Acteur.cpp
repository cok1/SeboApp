#include "Acteur.h"



Acteur::Acteur()
{
}

Acteur::Acteur(const Acteur &acteur):m_strNom(acteur.m_strNom), m_nIdRole(acteur.m_nIdRole), m_nId(acteur.m_nId)
{
}

Acteur::Acteur(QString nom, int idRole, int id): m_strNom(nom), m_nIdRole(idRole), m_nId(id)
{
}


Acteur::~Acteur()
{
}

bool Acteur::setId(int id)
{
	// déclaration
	bool resultat;

	resultat = id > 0 && m_nId == -1;

	if (resultat)
		m_nId = id;

	return resultat;
}

bool Acteur::setNom(QString nom)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

	// Test du paramètre en entrée
	resultat = ToolBox::isValide(nom.toStdString(), 1, true);

	// modification de l'attribut
	if (resultat)
	{
		m_strNom = nom;
	}

	// retour du résultat de la fonction
	return resultat;
}

bool Acteur::setIdRole(int idRole)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = true;

	// modification de l'attribut
	if (resultat)
	{
		m_nIdRole = idRole;
	}

	// retour du résultat de la fonction
	return resultat;
}

int Acteur::getId()
{
	return m_nId;
}

QString Acteur::getNom()
{
	return QString(m_strNom);
}

int Acteur::getIdRole()
{
	return m_nIdRole;
}
