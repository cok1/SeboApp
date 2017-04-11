#include "GuiGestionGenre.h"
#include "ui_GuiGestionGenre.h"

GuiGestionGenre::GuiGestionGenre(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGestionGenre();
	ui->setupUi(this);
}

GuiGestionGenre::~GuiGestionGenre()
{
	delete ui;
}
