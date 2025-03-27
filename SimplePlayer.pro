QT       += core gui multimedia
QT += core gui multimedia widgets
CONFIG += c++17
TARGET = SimplePlayer
TEMPLATE = app
INCLUDEPATH += "C:/Users/Sopha/Downloads/gg/lab4"

SOURCES += playlistselector.cpp main.cpp widget.cpp lab4/Playlist.cpp lab4/Player.cpp lab4/PlaylistManager.cpp lab4/Track.cpp lab4/TrackFactory.cpp lab4/ConsoleLogger.cpp lab4/LoggerFactory.cpp lab4/FileLogger.cpp
HEADERS += playlistselector.h widget.h lab4/Playlist.h lab4/Player.h lab4/PlaylistManager.h lab4/Track.h lab4/TrackFactory.h lab4/ILogger.h lab4/ConsoleLogger.h lab4/LoggerFactory.h lab4/FileLogger.h
FORMS += widget.ui playlistselector.ui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


RESOURCES += \
    buttons.qrc
