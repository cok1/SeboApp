#pragma once

#include <QWidget>
#include <qlineedit.h>
#include <qpushbutton.h>

namespace Ui { class GuiGestionPhoto; };

class GuiGestionPhoto : public QWidget
{
	Q_OBJECT

signals:
	QString editionTerminee(QString url);

public:
	GuiGestionPhoto(QString url = "", QWidget *parent = Q_NULLPTR);
	~GuiGestionPhoto();

private:
	Ui::GuiGestionPhoto *ui;
	QLineEdit *leSaisieUrl;
	QPushButton *btnValider;
	QPushButton *btnAnnuler;

private slots:
	void btnClickValider();
	void btnClickAnnuler();
};
