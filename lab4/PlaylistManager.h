#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <vector>
#include <memory>
#include "Playlist.h"
#include "PlaylistFactory.h"

class PlaylistManager : public PlaylistFactory {
public:
    void CreatePlaylist() override;
    void RemovePlaylist(int index);
    
    void AddTrackToPlaylist(int playlistIndex, const Track& track);
    
    Playlist* GetPlaylist(int index);
    
    int GetPlaylistCount() const;

private:
    std::vector<std::unique_ptr<Playlist>> _playlists; // Динамический вектор плейлистов
};
    
#endif


