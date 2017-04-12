#pragma once

#include <QWidget>
namespace Ui { class GuiGestionRole; };

class GuiGestionRole : public QWidget
{
	Q_OBJECT


public:
	GuiGestionRole(QWidget *parent = Q_NULLPTR);
	~GuiGestionRole();

private:
	Ui::GuiGestionRole *ui;
};
