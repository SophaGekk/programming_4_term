
#ifndef PLAYER_H
#define PLAYER_H

#include "PlaylistManager.h"
#include "TrackFactory.h"
#include "PlaylistFactory.h"
#include "ILogger.h"

class Player {
public:
    Player(PlaylistManager& playlistManager, TrackFactory& trackFactory, ILogger* logger);
    
    void Play(int playlistIndex);
    void Stop();
    
    void AddTrackToPlaylist(int playlistIndex, const std::string& title, const std::string& artist);

private:
    PlaylistManager& _playlistManager;
    TrackFactory& _trackFactory;
    ILogger* _logger; 
};
#endif