#pragma once

#include <QWidget>
#include <GuiGestionActeur.h>
#include <GuiGestionRole.h>

#include "Entity\Article.h"
#include "DAO\ManagerArticle.h"

namespace Ui { class GuiAjoutActeurArticle; };

class GuiAjoutActeurArticle : public QWidget
{
	Q_OBJECT

public:
	GuiAjoutActeurArticle(int referenceArticle = -1, QWidget *parent = Q_NULLPTR);
	~GuiAjoutActeurArticle();

private:
	Ui::GuiAjoutActeurArticle *ui;
	int m_nReferenceArticle;

	QComboBox *cbFiltrerRole;
	QPushButton *btnToutAfficher;

	QTableView *tvActeursDispos;
	QSqlTableModel *modelActeursDispos;
	QPushButton *btnGererActeur;
	QPushButton *btnGererRole;

	QPushButton *btnAjouter;
	QPushButton *btnRetirer;

	QTableView *tvActeursLies;
	QSqlTableModel *modelActeursLies;

	QPushButton *btnValider;



private slots:
	void majTableActeurDispos();
	void majTableActeurLies();
	void initModelActeursDispos();
	void initModelActeursLies();
	void filtrerRole(QString texte);
	void toutAfficher();
	void ajouter();
	void retirer();
	void gererActeurs();
	void gererRoles();
	void valider();
};
