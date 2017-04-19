//#pragma execution_character_set("utf-8")

#include "SeboApp.h"
#include "GuiGenreNew.h"
#include "GuiCategorie.h"
#include "EssaiGuiArticle.h"
#include "GuiGestionCategorie.h"
#include "GuiGestionGenre.h"
#include <QtWidgets/QApplication>
#include "Tools\Connexion.h"
#include "GuiGestionArticle.h"
#include "GuiGestionRole.h"
#include "GuiGestionActeur.h"
#include "GuiTest.h"
#include "AffichageArticles.h"
#include "GuiAjoutActeurArticle.h"


int main(int argc, char *argv[])
{
	// TODO: à supprimer
	// Récupération du pointeur vers l'instance unique de la connexion 
	std::shared_ptr<Connexion> conn = Connexion::getInstance();

	if (conn != nullptr)
		conn->etablirConnexion("capelli", "developpeur");

	QApplication a(argc, argv);
	GuiAjoutActeurArticle w(1);
	w.show();
	return a.exec();
}
