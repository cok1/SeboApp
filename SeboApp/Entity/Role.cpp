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

bool Role::setLibelle(QString libelle)
{
	// D�clarations
	bool resultat;		// va contenir le r�sultat de la fonction

	// Test du param�tre en entr�e
	resultat = ToolBox::isValide(libelle.toStdString(), 1, true);

	if (resultat)
	{
		m_strLibelle = libelle;
	}

	// Retour du r�sultat
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
