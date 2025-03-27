#ifndef IUSER_H
#define IUSER_H
#include "Player.h"
#include "PlaylistManager.h"

class IUser {
public:
   IUser(Player& player, PlaylistManager& playlistManager, ILogger* logger);
   void Start();

private:
   Player& _player; // Ссылка на объект плеера
   PlaylistManager& _playlistManager; // Ссылка на менеджер плейлистов
   ILogger* _logger; 
};

#endif
