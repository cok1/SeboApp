#include "EditionArticle.h"
#include "ui_EditionArticle.h"

EditionArticle::EditionArticle(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::EditionArticle();
	ui->setupUi(this);
}

EditionArticle::~EditionArticle()
{
	delete ui;
}
