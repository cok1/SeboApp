#pragma once

#include <QWidget>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtableview.h>
#include <qsqltablemodel.h>
#include <qsortfilterproxymodel.h>

#include "DAO\ManagerCategorie.h"
#include "Entity\Categorie.h"
#include "DAO\ManagerGenre.h"
#include "Entity\Genre.h"

#include "Tools\Connexion.h"

namespace Ui { class AffichageArticles; };

class AffichageArticles : public QWidget
{
	Q_OBJECT

public:
	AffichageArticles(QWidget *parent = Q_NULLPTR);
	~AffichageArticles();
	void setSelectionnable(bool selectionnable);
	void setActif(bool actif);


signals:
	int choixArticle(int);

public slots:
	void majTableArticle();

private:
	Ui::AffichageArticles *ui;
	QComboBox *cbFiltreCategorie;
	QComboBox *cbFiltreGenre;
	QLineEdit *leFiltreLibelle;
	QPushButton *btnToutAfficher;
	QTableView *tvArticle;
	QSqlTableModel *model;
	QSortFilterProxyModel *proxyModel;

	void majModel();

private slots:
	void majCbFiltreCategorie(int idCategorie = -1);
	void majCbFiltreGenre(int idGenre = -1);
	void filtrerSaisieGenre(QString texte);
	void filtrerSaisieCategorie(QString texte);
	void filtrerLibelle(QString texte);
	void supprimerFiltre();
	void selectionTable();
};
