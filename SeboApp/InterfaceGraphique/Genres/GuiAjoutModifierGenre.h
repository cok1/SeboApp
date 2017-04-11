#pragma once

#include <QWidget>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qsqltablemodel.h>

#include "Entity\Genre.h"
#include "DAO\ManagerGenre.h"
#include "Entity\Categorie.h"
#include "DAO\ManagerCategorie.h"


namespace Ui { class GuiAjoutModifierGenre; };

class GuiAjoutModifierGenre : public QWidget
{
	Q_OBJECT

public:
	GuiAjoutModifierGenre(Genre *genreAModifier = Q_NULLPTR, QWidget *parent = Q_NULLPTR);
	~GuiAjoutModifierGenre();

signals:
	void editionTerminee();

private:
	Ui::GuiAjoutModifierGenre *ui;
	QLineEdit *leLibelle;
	QComboBox *cbCategorie;
	QPushButton *btnValider;
	Genre *genreEnCours;
	//QSqlTableModel *model;

	void initCombo();

private slots:
	void creationGenre();
	void modificationGenre();
};
