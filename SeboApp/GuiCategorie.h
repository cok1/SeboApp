#pragma once

#include <QWidget>
#include "ui_GuiCategorie.h"
#include "Tools/Connexion.h"
#include <qsqldatabase.h>
#include <qsqltablemodel.h>
#include <qsqlrelationaldelegate.h>
#include "DAO\ManagerCategorie.h"
#include "Entity\Categorie.h"
#include <vector>

class GuiCategorie : public QWidget
{
	Q_OBJECT

public:
	GuiCategorie(QWidget *parent = Q_NULLPTR);
	~GuiCategorie();
	

public slots:
	void ajouterArticle();
	void majTable();

private:
	Ui::GuiCategorie ui;
};
