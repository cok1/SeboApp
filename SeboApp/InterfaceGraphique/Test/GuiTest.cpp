#include "GuiTest.h"
#include "ui_GuiTest.h"

GuiTest::GuiTest(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GuiTest();
	ui->setupUi(this);

	tvActeurArticle = ui->tvActeurArticle;

	// Récupération de la connexion
	shared_ptr<Connexion> conn = Connexion::getInstance();
	QSqlDatabase db = conn->getConnexion();

	QSqlTableModel *model = new QSqlTableModel();
	model->setTable("Acteur");
	model->select();

	model->setFilter("IdActeur = 1");

	tvActeurArticle->setModel(model);
}

GuiTest::~GuiTest()
{
	delete ui;
}
