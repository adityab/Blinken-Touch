/***************************************************************************
 *   Copyright (C) 2005 by Albert Astals Cid <tsdgeos@terra.es>            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "soundsplayer.h"


#include <phonon/Path>

//#include "settings.h"

soundsPlayer::soundsPlayer()
    : m_audioOutput(Phonon::GameCategory)
{
	m_audioOutput.setVolume( 0.8f );
	Phonon::createPath(&m_mediaObject, &m_audioOutput);
	connect(&m_mediaObject, SIGNAL(finished()), this, SLOT(playEnded()));

        m_allSound = "sounds/lose.wav";
        m_greenSound = "sounds/1.wav";
        m_redSound = "appdata","sounds/2.wav";
        m_blueSound = "appdata","sounds/3.wav";
        m_yellowSound = "appdata","sounds/4.wav";

        connect(&m_warnTimer, SIGNAL(timeout()), this, SIGNAL(ended()));
        m_warnTimer.setSingleShot(true);
}

soundsPlayer::~soundsPlayer()
{
}

void soundsPlayer::play(blinkenGame::color c)
{
		QString soundFile;
		switch (c)
		{
			case blinkenGame::red:
				soundFile = m_redSound;
			break;
			
			case blinkenGame::green:
				soundFile = m_greenSound;
			break;
			
			case blinkenGame::blue:
				soundFile = m_blueSound;
			break;
			
			case blinkenGame::yellow:
				soundFile = m_yellowSound;
			break;
			
			case blinkenGame::all:
				soundFile = m_allSound;
			break;
			
			default:
			break;
		}
		if (!soundFile.isEmpty())
		{
                        m_mediaObject.setCurrentSource(soundFile);
                        m_mediaObject.play();
                        m_warnTimer.start(250);

		}

}

void soundsPlayer::playEnded()
{

	{
                //m_warnTimer.start(250);-
	}
}

//#include "soundsplayer.moc"
