#pragma once

#include <QWidget>
namespace Ui { class GuiGenreNew; };

class GuiGenreNew : public QWidget
{
	Q_OBJECT

public:
	GuiGenreNew(QWidget *parent = Q_NULLPTR);
	~GuiGenreNew();

private:
	Ui::GuiGenreNew *ui;
};
