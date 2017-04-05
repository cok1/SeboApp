#pragma once

#include <QItemDelegate>
#include <qpainter.h>
#include <qvariant.h>

class RenduEssai : public QItemDelegate
{
	Q_OBJECT

public:
	RenduEssai(QObject *parent=0) :QItemDelegate(parent) {}
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
