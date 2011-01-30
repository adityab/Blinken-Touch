######################################################################
# Automatically generated by qmake (2.01a) Thu Dec 16 13:58:00 2010
######################################################################

QT       += svg phonon

TEMPLATE = app
TARGET = BlinkenTouch
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += blinken.h \
           blinkengame.h \
           button.h \
           counter.h \
           highscoredialog.h \
           number.h \
           soundsplayer.h

SOURCES += blinken.cpp \
           blinkengame.cpp \
           button.cpp \
           counter.cpp \
           highscoredialog.cpp \
           main.cpp \
           number.cpp \
           soundsplayer.cpp

OTHER_FILES += \
    fonts/steve.ttf \
    icons/hisc-app-blinken.svgz \
    icons/hi128-app-blinken.png \
    icons/hi64-app-blinken.png \
    icons/hi48-app-blinken.png \
    icons/hi32-app-blinken.png \
    icons/hi22-app-blinken.png \
    icons/hi16-app-blinken.png \
    images/blinken.svg \
    sounds/lose.wav \
    sounds/4.wav \
    sounds/3.wav \
    sounds/2.wav \
    sounds/1.wav

RESOURCES += \
    Resource.qrc

ICON = icon.png