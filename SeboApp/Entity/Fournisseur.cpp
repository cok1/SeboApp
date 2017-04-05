#include "Fournisseur.h"



Fournisseur::Fournisseur()
{
}

Fournisseur::Fournisseur(QString nomFournisseur, int idFournisseur): m_strNomFournisseur(nomFournisseur), m_nIdFournisseur(idFournisseur)
{
}


Fournisseur::~Fournisseur()
{
}

bool Fournisseur::setNomFournisseur(QString nomFournisseur)
{
	// Déclaration
	bool resultat;		// va contenir le résultat de la fonction

						// Test du paramètre en entrée
	resultat = ToolBox::isValide(nomFournisseur.toStdString(), 1, true);

	// modification de l'attribut
	if (resultat)
	{
		m_strNomFournisseur = nomFournisseur;
	}

	// retour du résultat de la fonction
	return resultat;
}

int Fournisseur::getIdFournisseur()
{
	return m_nIdFournisseur;
}

QString Fournisseur::getNomFournisseur()
{
	return QString(m_strNomFournisseur);
}
