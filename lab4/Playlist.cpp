#include "Playlist.h"
#include <iostream>

void Playlist::AddTrack(const Track& track) {
    _tracks.push_back(track);
}

void Playlist::RemoveTrack(int index) {
    if (index >= 0 && index < _tracks.size()) {
        _tracks.erase(_tracks.begin() + index);
        std::cout << "Трек удален из плейлиста." << std::endl;
    } else {
        std::cout << "Некорректный индекс трека." << std::endl;
    }
}

Track Playlist::GetTrack(int index) const {
    if (index >= 0 && index < _tracks.size()) {
        return _tracks[index];
    }
    throw std::out_of_range("Индекс вне диапазона.");
}

int Playlist::GetTrackCount() const {
    return static_cast<int>(_tracks.size());
}
