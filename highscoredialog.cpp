/***************************************************************************
 *   Copyright (C) 2005-2006 by Albert Astals Cid <aacid@kde.org>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "highscoredialog.h"

#include <qpainter.h>
#include <qpixmap.h>
#include <qtabbar.h>

#include <QtGlobal>
#include <QTabWidget>

#include "counter.h"

static const int margin = 15;
static const int smallMargin = 5;
static const int namesFontSize = 25;

/* scoresWidget */

class scoresWidget : public QWidget
{
	public:
		scoresWidget(QWidget *parent, const QList< QPair<int, QString> > &scores, QSvgRenderer *renderer);
		QSize calcSize();

	protected:
		void paintEvent(QPaintEvent *);
	
	private:
		const QList< QPair<int, QString> > &m_scores;
		QSvgRenderer *m_renderer;
};

scoresWidget::scoresWidget(QWidget *parent, const QList< QPair<int, QString> > &scores, QSvgRenderer *renderer)
 : QWidget(parent), m_scores(scores), m_renderer(renderer)
{
	setAttribute(Qt::WA_StaticContents);
}

void scoresWidget::paintEvent(QPaintEvent *)
{
	int w = width();
	int h = height();
	QFont f;
	QPixmap buf(w, h);
	QPainter p(&buf);
	QRect r;
	QColor bg = palette().window().color();
 
	// bg color
	p.fillRect(0, 0, w, h, bg);
	
	p.setPen(Qt::black);
	
        f = QFont("Steve");
	p.setFont(f);
        f.setPointSize(10);
	p.setFont(f);
	
	p.translate(margin, margin);
	
	QList< QPair<int, QString> >::const_iterator it;
	for (it = m_scores.begin(); it != m_scores.end(); ++it)
	{
		counter::paint(p, !(*it).second.isEmpty(), (*it).first, false, QColor(), QColor(), QColor(), m_renderer);
		p.setPen(Qt::black);
		p.drawText(counter::width(false) + 2 * smallMargin, 30, (*it).second);
		p.translate(0, counter::height() + smallMargin);
	}
	
	QPainter p2(this);
	p2.drawPixmap(0, 0, buf);
}


QSize scoresWidget::calcSize()
{
	int mw, mh, lt;
	QRect r;
	QPixmap dummyPixmap(2000, 2000);
	QPainter p(&dummyPixmap);
	QFont f;
	
        f = QFont("Steve");
	p.setFont(f);
        f.setPointSize(10);
	p.setFont(f);
	for (int i = 0; i < 3; i++)
	{
		lt = 0;
		QList< QPair<int, QString> >::const_iterator it;
		for (it = m_scores.begin(); it != m_scores.end(); ++it)
		{
			r = p.boundingRect(QRect(), Qt::AlignLeft, (*it).second);
			lt = qMax(lt, r.width());
		}
	}
	
	mw = margin + counter::width(false) + 2 * smallMargin + lt + margin;
	mh = margin * 2 + counter::height() * 5 + smallMargin * 4;
	
	QSize size(mw, mh);
	setMinimumSize(size);
	resize(size);
	
	return size;
}

/* myTabWidget */

class myTabWidget : public QTabWidget
{
	public:
                myTabWidget(QWidget *parent) : QTabWidget(parent) {}
		
		QSize tabBarSizeHint() const
		{
			return tabBar() -> sizeHint();
		}
};

/* highScoreDialog */

highScoreDialog::highScoreDialog(QWidget *parent, QSvgRenderer *renderer) : QDialog(parent)
{

}

bool highScoreDialog::scoreGoodEnough(int level, int score)
{
 return true;
}

void highScoreDialog::addScore(int level, int score, const QString &name)
{

}

void highScoreDialog::showLevel(int level)
{
}
