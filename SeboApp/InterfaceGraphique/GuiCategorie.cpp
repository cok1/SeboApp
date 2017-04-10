#include "GuiCategorie.h"
#include "ui_GuiCategorie.h"

GuiCategorie::GuiCategorie(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiCategorie();
	ui->setupUi(this);
}

GuiCategorie::~GuiCategorie()
{
	delete ui;
}
