#pragma once

#include <QWidget>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qmessagebox.h>

#include "Tools\Connexion.h"
#include "DAO\ManagerRole.h"
#include "Entity\Role.h"

namespace Ui { class GuiAjoutModifRole; };

class GuiAjoutModifRole : public QWidget
{
	Q_OBJECT

public:
	GuiAjoutModifRole(Role *roleAModifier = Q_NULLPTR, QWidget *parent = Q_NULLPTR);
	~GuiAjoutModifRole();

signals:
	void editionTerminee();

private:
	Ui::GuiAjoutModifRole *ui;
	Role *roleEnCours;
	QLineEdit *leSaisieLibelle;
	QPushButton *btnValider;
	QPushButton *btnAnnuler;

private slots:
	void creerRole();
	void modifierRole();
};
