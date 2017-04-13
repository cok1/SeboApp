#pragma once

#include <QWidget>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qmessagebox.h>
#include <qsqltablemodel.h>

#include <Entity\Acteur.h>
#include <DAO\ManagerActeur.h>
#include <Entity\Role.h>
#include <DAO\ManagerRole.h>

namespace Ui { class GuiAjoutModifierActeur; };

class GuiAjoutModifierActeur : public QWidget
{
	Q_OBJECT

public:
	GuiAjoutModifierActeur(Acteur *acteurAModifier = Q_NULLPTR, QWidget *parent = Q_NULLPTR);
	~GuiAjoutModifierActeur();

signals:
	void editionTerminee();

private:
	Ui::GuiAjoutModifierActeur *ui;
	QLineEdit *leLibelle;
	QComboBox *cbRole;
	QPushButton *btnValider;
	Acteur *acteurEnCours;

	void initCombo();
	void afficherMessageErreur(QString messageErreur = "");

private slots:
	void creationActeur();
	void modificationActeur();
};
