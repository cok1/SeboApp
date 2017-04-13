#pragma once

#include <QWidget>
#include <qtableview.h>
#include <qsqltablemodel.h>
#include "Tools\Connexion.h"

namespace Ui { class GuiTest; };

using namespace std;

class GuiTest : public QWidget
{
	Q_OBJECT

public:
	GuiTest(QWidget *parent = Q_NULLPTR);
	~GuiTest();

private:
	Ui::GuiTest *ui;
	QTableView *tvActeurArticle;
};
