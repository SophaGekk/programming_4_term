#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include "Track.h"

class Playlist {
public:
    void AddTrack(const Track& track);
    void RemoveTrack(int index);
    Track GetTrack(int index) const;
    int GetTrackCount() const;

private:
    std::vector<Track> _tracks; // Список треков
};

#endif
