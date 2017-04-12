#include "GuiGestionRole.h"
#include "ui_GuiGestionRole.h"

GuiGestionRole::GuiGestionRole(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiGestionRole();
	ui->setupUi(this);
}

GuiGestionRole::~GuiGestionRole()
{

	delete ui;
}
