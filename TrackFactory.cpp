#include "TrackFactory.h"

Track TrackFactory::CreateTrack(const std::string& title, const std::string& artist) {
    return Track(title, artist);
}
