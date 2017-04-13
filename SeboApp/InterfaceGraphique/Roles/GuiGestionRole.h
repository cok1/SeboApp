#pragma once
////#pragma execution_character_set("utf-8")

#include <QWidget>
#include <qsqltablemodel.h>
#include <qtableview.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

#include "GuiAjoutModifRole.h"
#include <Tools\Connexion.h>
#include "DAO\ManagerRole.h"
#include "Entity\Role.h"

namespace Ui { class GuiGestionRole; };

class GuiGestionRole : public QWidget
{
	Q_OBJECT

public:
	GuiGestionRole(QWidget *parent = Q_NULLPTR);
	~GuiGestionRole();

private:
	Ui::GuiGestionRole *ui;
	QPushButton *btnAjouter;
	QPushButton *btnModifier;
	QPushButton *btnSupprimer;

	QTableView *tvRole;

private slots:
	void majTable();
	void ajouterRole();
	void modifierRole();
	void supprimerRole();
	void majAffichage();
};
