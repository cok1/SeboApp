#pragma once

#include <QWidget>
#include <qtableview.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qsqltablemodel.h>

#include "Entity\Genre.h"
#include "Tools\Connexion.h"
#include "DAO\ManagerGenre.h"
#include "GuiAjoutModifierGenre.h"

namespace Ui { class GuiGestionGenre; };

class GuiGestionGenre : public QWidget
{
	Q_OBJECT

public:
	GuiGestionGenre(QWidget *parent = Q_NULLPTR);
	~GuiGestionGenre();

private:
	Ui::GuiGestionGenre *ui;
	QPushButton *btnAjouter;
	QPushButton *btnModifier;
	QPushButton *btnSupprimer;
	QTableView *tvGenre;

private slots:
	void majTable();
	void ajouterGenre();
	void modifierGenre();
	void supprimer();
	void majAffichage();
};
