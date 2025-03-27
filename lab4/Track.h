#ifndef TRACK_H
#define TRACK_H

#include <string>

class Track {
public:
    Track(const std::string& title, const std::string& artist);
    std::string GetTitle() const;
    std::string GetArtist() const;

private:
    std::string _title;
    std::string _artist;
};
    
#endif
