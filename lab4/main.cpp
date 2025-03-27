#include <iostream>
#include "Player.h"
#include "IUser.h"
#include "PlaylistManager.h"

#include "TrackFactory.h"
#include "PlaylistFactory.h"
#include "LoggerFactory.h"

int main() {
   
   auto consoleLogger = LoggerFactory::CreateLogger(1); // Консольный логгер
   auto fileLogger = LoggerFactory::CreateLogger(2, "user_interface.log"); // Файловый логгер
   
   PlaylistManager playlistManager; // Создаем менеджер плейлистов.
   TrackFactory trackFactory; // Создаем фабрику треков.
   
   Player player(playlistManager, trackFactory, consoleLogger); // Создаем плеер с менеджером и фабрикой.
   
   IUser userInterface(player, playlistManager, consoleLogger); // Создаем интерфейс пользователя.
   
   userInterface.Start(); // Запускаем интерфейс пользователя.
   
   return 0; 
}


