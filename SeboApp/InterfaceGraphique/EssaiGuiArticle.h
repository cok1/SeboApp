#pragma once

#include <QWidget>
#include "ui_EssaiGuiArticle.h"
#include <qsqlrelationaltablemodel.h>
#include <qsqlrelationaldelegate.h>
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <qsortfilterproxymodel.h>

#include "Tools\Connexion.h"
#include "Entity\Article.h"
#include "Entity\Genre.h"
#include "Entity\Fournisseur.h"
#include "DAO\ManagerArticle.h"
#include "DAO\ManagerGenre.h"
#include "DAO\ManagerFournisseur.h"

class EssaiGuiArticle : public QWidget
{
	Q_OBJECT

public:
	EssaiGuiArticle(QWidget *parent = Q_NULLPTR);
	~EssaiGuiArticle();

private:
	Ui::EssaiGuiArticle ui;
	QSqlRelationalTableModel *m_mModel;
	int m_nIndexFournisseur = -1;
	int m_nIndexGenre = -1;
	QSortFilterProxyModel *m_pmProxyModel;

	void majAffichage();
	void initCombo();
	void essaiQVariantArticle();
	void essaiRequeteModel();

private slots:
	void initModel();
	void initTable();
	void creerArticle();
	void filtrerFournisseur(QString texte);
	void filtrerCategorie(QString texte);
};
