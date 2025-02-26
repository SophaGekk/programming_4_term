#include "Track.h"

Track::Track(const std::string& title, const std::string& artist)
    : _title(title), _artist(artist) {}

std::string Track::GetTitle() const {
    return _title;
}

std::string Track::GetArtist() const {
    return _artist;
}
