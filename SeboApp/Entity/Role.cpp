#include "Role.h"



Role::Role()
{
}

Role::Role(QString libelle, int id): m_strLibelle(libelle), m_nId(id)
{
}


Role::~Role()
{
}

bool Role::setId(int nouvelId)
{
	// Déclaration
	bool resultat;

	// Test paramètre
	resultat = nouvelId > 0 && m_nId == -1;

	if (resultat)
	{
		m_nId = nouvelId;
	}

	// retour du résultat
	return resultat;
}

bool Role::setLibelle(QString libelle)
{
	// Déclarations
	bool resultat;		// va contenir le résultat de la fonction

	// Test du paramètre en entrée
	resultat = ToolBox::isValide(libelle.toStdString(), 1, true);

	if (resultat)
	{
		m_strLibelle = libelle;
	}

	// Retour du résultat
	return resultat;
}

QString Role::getLibelle()
{
	return QString(m_strLibelle);
}

int Role::getId()
{
	return m_nId;
}
