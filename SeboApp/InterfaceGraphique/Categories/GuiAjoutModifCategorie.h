#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <QDoubleSpinBox>

#include "Entity\Categorie.h"
#include "DAO\ManagerCategorie.h"

namespace Ui { class GuiAjoutModifCategorie; };

class GuiAjoutModifCategorie : public QWidget
{
	Q_OBJECT

public:
	GuiAjoutModifCategorie(Categorie *categorieAModifier = Q_NULLPTR, QWidget *parent = Q_NULLPTR);
	~GuiAjoutModifCategorie();

signals:
	/// <summary>
	/// Signal émit lorsque l'édition est terminée
	/// </summary>
	void editionTerminee();

private:
	Ui::GuiAjoutModifCategorie *ui;
	QPushButton *btnValider;
	QLineEdit *leSaisieLibelle;
	QDoubleSpinBox *spSaisieTaux;
	Categorie *categorieEnCours;

private slots:
	void creer();
	void modifier();
};
