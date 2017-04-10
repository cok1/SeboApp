#include "GuiGenreNew.h"
#include "ui_GuiGenreNew.h"

GuiGenreNew::GuiGenreNew(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGenreNew();
	ui->setupUi(this);
}

GuiGenreNew::~GuiGenreNew()
{
	delete ui;
}
