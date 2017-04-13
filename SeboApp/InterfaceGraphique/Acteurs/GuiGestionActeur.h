#pragma once

#include <QWidget>
#include <qtableview.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qsqltablemodel.h>
#include <qcombobox.h>
#include <qsortfilterproxymodel.h>

#include "Entity\Acteur.h"
#include "Tools\Connexion.h"
#include "DAO\ManagerActeur.h"
#include "GuiAjoutModifierActeur.h"

namespace Ui { class GuiGestionActeur; };

class GuiGestionActeur : public QWidget
{
	Q_OBJECT

public:
	GuiGestionActeur(QWidget *parent = Q_NULLPTR);
	~GuiGestionActeur();

private:
	Ui::GuiGestionActeur *ui;
	QPushButton *btnAjouter;
	QPushButton *btnModifier;
	QPushButton *btnSupprimer;
	QPushButton *btnToutAfficher;
	QComboBox *cbFiltreRole;
	QTableView *tvActeur;
	//QSqlTableModel *model;
	QSortFilterProxyModel *proxy;

private slots:
	void majTable();
	void ajouterActeur();
	void modifierActeur();
	void supprimer();
	void majAffichage();
	void majComboFiltre();
	void filtrerRole(QString texte);
	void toutAfficher();
};
