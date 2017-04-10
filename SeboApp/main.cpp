#include "SeboApp.h"
#include "GuiCategorie.h"
#include "GuiGenre.h"
#include "EssaiGuiArticle.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GuiCategorie w;
	w.show();
	return a.exec();
}
