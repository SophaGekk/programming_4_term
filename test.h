#include <cassert>
#include "playlistselector.h"
#include "widget.h"

// Функция для тестирования
void runTests() {
    // Создание экземпляров
    PlaylistSelector *playlistSelector = new PlaylistSelector();
    Widget *widget = new Widget("Test Playlist", playlistSelector);


    // Тестирование метода isTrackNameValid
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
    assert(!widget->isTrackNameValid("Invalid*Track|Name")); // Возвращает false
    std::cout << "OK" << std::endl;

    std::cout << "Invalid_name_three..." << std::flush;
    assert(!widget->isTrackNameValid("Invalid<Track>Name")); // Возвращает false
    std::cout << "OK" << std::endl;


    // Освобождение ресурсов
    delete widget;
    delete playlistSelector;
}
