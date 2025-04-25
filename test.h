#include <cassert>
#include "playlistselector.h"
#include "widget.h"

// Функция для тестирования TrackName
void runTests_TrackName() {
    // Создание экземпляров
    PlaylistSelector *playlistSelector = new PlaylistSelector();
    Widget *widget = new Widget("Test Playlist", playlistSelector);

    std::cout << "Valid_name_one..." << std::flush;
    assert(widget->isTrackNameValid("ValidTrackName.mp3")); // Возвращает true
    std::cout << "OK" << std::endl;

    std::cout << "Valid_name_two..." << std::flush;
    assert(widget->isTrackNameValid("Another_Valid_Track+$.mp3")); // Возвращает true
    std::cout << "OK" << std::endl;

    std::cout << "Invalid_name_one..." << std::flush;
    assert(!widget->isTrackNameValid("Invalid/Track:Name?")); // Возвращает false
    std::cout << "OK" << std::endl;

    std::cout << "Invalid_name_two..." << std::flush;
    assert(!widget->isTrackNameValid("   ")); // Возвращает false
    std::cout << "OK" << std::endl;

    std::cout << "Invalid_name_three..." << std::flush;
    assert(!widget->isTrackNameValid("Invalid<Track>Name")); // Возвращает false
    std::cout << "OK" << std::endl;


    // Освобождение ресурсов
    delete widget;
    delete playlistSelector;
}

// Функция для тестирования PlaylistName
void runTests_PlaylistName(){
    // Создание экземпляров
    PlaylistSelector *playlistSelector = new PlaylistSelector();


    std::cout << "Valid_PlaylistName_one..." << std::flush;
    assert(playlistSelector->isPlaylistNameValid("Rock_and_Roll")); // Возвращает true
    std::cout << "OK" << std::endl;

    std::cout << "Valid_PlaylistName_two..." << std::flush;
    assert(playlistSelector->isPlaylistNameValid("2025 Hits")); // Возвращает true
    std::cout << "OK" << std::endl;

    std::cout << "Valid_PlaylistName_one..." << std::flush;
    assert(playlistSelector->isPlaylistNameValid("Rock & Roll")); // Возвращает true
    std::cout << "OK" << std::endl;

    std::cout << "Invalid_PlaylistName_two..." << std::flush;
    assert(!playlistSelector->isPlaylistNameValid("Bad/Name")); // Возвращает false
    std::cout << "OK" << std::endl;

    std::cout << "Invalid_PlaylistName_three..." << std::flush;
    assert(!playlistSelector->isPlaylistNameValid(":|?")); // Возвращает false
    std::cout << "OK" << std::endl;


    // Освобождение ресурсов
    delete playlistSelector;

}


void runTests() {

    std::cout << "runTests_TrackName..." << std::flush;
    runTests_TrackName();
    std::cout << "OK" << std::endl;


    std::cout << "runTests_PlaylistName..." << std::flush;
    runTests_PlaylistName();
    std::cout << "OK" << std::endl;

}
