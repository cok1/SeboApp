#include "RenduEssai.h"

void RenduEssai::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QString val = index.data().toString();
	// coloration des lignes paires
	if (index.row() % 2 == 0)
	{
		painter->fillRect(option.rect, option.palette.highlight());
	}
	//QItemDelegate::paint(painter, option, index);
	painter->drawText(option.rect, Qt::AlignCenter, val);
}