#pragma once

#include <QSqlTableModel>

class TestModeleGenre : public QSqlTableModel
{
	Q_OBJECT

public:
	TestModeleGenre(QObject *parent);
	~TestModeleGenre();
};
