
#ifndef TRACKFACTORY_H
#define TRACKFACTORY_H
    
#include "Track.h"

class TrackFactory {
public:
    virtual ~TrackFactory() = default;
    virtual Track CreateTrack(const std::string& title, const std::string& artist);
};
    
#endif