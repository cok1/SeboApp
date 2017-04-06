#pragma once

#include <QWidget>
#include "ui_EssaiGuiArticle.h"
#include <qsqlrelationaltablemodel.h>
#include <qsqlrelationaldelegate.h>
#include "Tools\Connexion.h"
#include "Entity\Article.h"
#include "DAO\ManagerArticle.h"

class EssaiGuiArticle : public QWidget
{
	Q_OBJECT

public:
	EssaiGuiArticle(QWidget *parent = Q_NULLPTR);
	~EssaiGuiArticle();

private:
	Ui::EssaiGuiArticle ui;
	QSqlRelationalTableModel *m_mModel;

	void majAffichage();
	void initCombo();

private slots:
	void initModel();
	void initTable();
	void creerArticle();
};
