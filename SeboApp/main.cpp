#pragma encoding=utf8;

#include "SeboApp.h"
#include "GuiGenreNew.h"
#include "GuiCategorie.h"
#include "EssaiGuiArticle.h"
#include "GuiGestionCategorie.h"
#include <QtWidgets/QApplication>
#include "Tools\Connexion.h"



int main(int argc, char *argv[])
{
	// TODO: à supprimer
	// Récupération du pointeur vers l'instance unique de la connexion 
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	QApplication a(argc, argv);
	GuiGestionCategorie w;
	w.show();
	return a.exec();
}
