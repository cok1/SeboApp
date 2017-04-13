#pragma once
////#pragma execution_character_set("utf-8")

#include <QWidget>
#include "Tools\Connexion.h"
#include <qsqltablemodel.h>
#include <qtableview.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include "DAO\ManagerCategorie.h"
#include "Categories\GuiAjoutModifCategorie.h"

namespace Ui { class GuiGestionCategorie; };

class GuiGestionCategorie : public QWidget
{
	Q_OBJECT

public:
	GuiGestionCategorie(QWidget *parent = Q_NULLPTR);
	~GuiGestionCategorie();

signals:
	void editionTerminee();

	//virtual bool close();

public slots:
	void majTable();

private:
	Ui::GuiGestionCategorie *ui;
	QTableView *tvCategorie;
	QPushButton *btnAjouter;
	QPushButton *btnSupprimer;
	QPushButton *btnModifier;

private slots:
	void majAffichage();
	void ajouterCategorie();
	void supprimerCategorie();
	void modifierCategorie();
};
