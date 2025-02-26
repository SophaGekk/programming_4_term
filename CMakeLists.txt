cmake_minimum_required(VERSION 3.10.0)
project(laba4 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(laba4 ConsoleLogger.cpp FileLogger.cpp IUser.cpp LoggerFactory.cpp main.cpp Player.cpp Playlist.cpp PlaylistManager.cpp Track.cpp TrackFactory.cpp)

