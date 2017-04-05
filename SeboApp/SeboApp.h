#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SeboApp.h"

class SeboApp : public QMainWindow
{
	Q_OBJECT

public:
	SeboApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::SeboAppClass ui;
};
