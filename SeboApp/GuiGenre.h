#pragma once

#include <QWidget>
#include "Tools\Connexion.h"
#include <qsqlrelationaltablemodel.h>
#include <qsqldatabase.h>
#include <qsqlrelationaldelegate.h>
#include <qdatawidgetmapper.h>
#include "RenduEssai.h"


namespace Ui { class GuiGenre; };

class GuiGenre : public QWidget
{
	Q_OBJECT

public:
	GuiGenre(QWidget *parent = Q_NULLPTR);
	~GuiGenre();

public slots:
	void majTable();

private:
	Ui::GuiGenre *ui;
};
