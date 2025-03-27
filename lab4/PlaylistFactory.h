#ifndef PLAYLISTFACTORY_H
#define PLAYLISTFACTORY_H
#include "Playlist.h"

class PlaylistFactory {
public:
    virtual ~PlaylistFactory() = default;
    virtual void CreatePlaylist() = 0;
};
    
#endif

