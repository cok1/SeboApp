#pragma once

#include <QWidget>
namespace Ui { class GuiGestionGenre; };

class GuiGestionGenre : public QWidget
{
	Q_OBJECT

public:
	GuiGestionGenre(QWidget *parent = Q_NULLPTR);
	~GuiGestionGenre();

private:
	Ui::GuiGestionGenre *ui;
};
