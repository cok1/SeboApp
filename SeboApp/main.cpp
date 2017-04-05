#include "SeboApp.h"
#include "GuiCategorie.h"
#include "GuiGenre.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GuiGenre w;
	w.show();
	return a.exec();
}
