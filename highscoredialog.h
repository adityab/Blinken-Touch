/***************************************************************************
 *   Copyright (C) 2005-2006 by Albert Astals Cid <aacid@kde.org>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef HIGHSCOREDIALOG_H
#define HIGHSCOREDIALOG_H

#include <qpair.h>
#include <qlist.h>

#include <QDialog>

class QSvgRenderer;

class myTabWidget;

class highScoreDialog : private QDialog
{
	public:
		highScoreDialog(QWidget *parent, QSvgRenderer *renderer);
		
		bool scoreGoodEnough(int level, int score);
		void addScore(int level, int score, const QString &name);
		void showLevel(int level);
	
		QList< QPair<int, QString> > m_scores[3];
		myTabWidget *m_tw;
};

#endif
