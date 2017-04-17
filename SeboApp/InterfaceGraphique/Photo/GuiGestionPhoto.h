#pragma once

#include <QWidget>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <FileDownloader.h>

namespace Ui { class GuiGestionPhoto; };

/// <summary>
/// Cette classe permet de gérer la photo associée à l'article
/// </summary>
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
	QPushButton *btnCharger;
	FileDownloader *m_pImgCtrl;
	QLabel *photo;

private slots:
	void btnClickValider();
	void btnClickAnnuler();
	void btnClickCharger();
	void chargerPhoto();
};
