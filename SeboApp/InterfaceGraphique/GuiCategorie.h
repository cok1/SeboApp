#pragma once

#include <QWidget>
#include "ui_GuiCategorie.h"
#include "Tools/Connexion.h"
#include <qsqldatabase.h>
#include <qsqltablemodel.h>
#include "DAO\ManagerCategorie.h"
#include "Entity\Categorie.h"
#include <vector>
#include <qmessagebox.h>
#include <qabstractitemmodel.h>

class GuiCategorie : public QWidget
{
	Q_OBJECT

public:
	GuiCategorie(QWidget *parent = Q_NULLPTR);
	~GuiCategorie();
	

public slots:
	void ajouterArticle();
	void majTable();
	void afficheId();

private:
	Ui::GuiCategorie *ui;
};
