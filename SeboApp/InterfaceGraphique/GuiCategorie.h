#pragma once

#include <QWidget>
namespace Ui { class GuiCategorie; };

class GuiCategorie : public QWidget
{
	Q_OBJECT

public:
	GuiCategorie(QWidget *parent = Q_NULLPTR);
	~GuiCategorie();

private:
	Ui::GuiCategorie *ui;
};
