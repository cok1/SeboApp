#pragma once

#include <QWidget>
namespace Ui { class EditionArticle; };

class EditionArticle : public QWidget
{
	Q_OBJECT

public:
	EditionArticle(QWidget *parent = Q_NULLPTR);
	~EditionArticle();

private:
	Ui::EditionArticle *ui;
};
