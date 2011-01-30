/***************************************************************************
 *   Copyright (C) 2005-2007 by Albert Astals Cid <aacid@kde.org>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "blinken.h"

#include <QApplication>

#include <QFontDatabase>
#include <QFontInfo>

int main(int argc, char *argv[])
{

        QApplication app(argc, argv);
        app.setApplicationName("Blinken Touch");
        app.setApplicationVersion("0.1");

        //Q_INIT_RESOURCE(Resource);
	app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));

	QFont f("Steve", 12, QFont::Normal, true);
	// Works with Steve may need some tweaking to work with other fonts
	if (!QFontInfo(f).exactMatch())
	{
                QFontDatabase::addApplicationFont(":/fonts/steve.ttf");
	}

        blinken* game = new blinken();


game->setWindowIcon(QIcon(":/icons/hi64-app-blinken.png"));
game->setWindowTitle("Blinken Touch");

game->show();
	return app.exec();
}
