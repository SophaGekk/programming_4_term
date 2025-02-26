#include "PlaylistManager.h"
#include <iostream>

void PlaylistManager::CreatePlaylist() {
    _playlists.push_back(std::make_unique<Playlist>());
    std::cout << "Плейлист создан. Всего плейлистов: " << GetPlaylistCount() << std::endl;
}

void PlaylistManager::RemovePlaylist(int index) {
    if (index >= 0 && index < _playlists.size()) {
        int trackCount = _playlists[index]->GetTrackCount(); // Получаем количество треков до удаления
        
        _playlists.erase(_playlists.begin() + index);
        
        std::cout << "Плейлист удален. Удалено " << trackCount << " треков." << std::endl;
    } else {
        std::cout << "Некорректный индекс." << std::endl;
    }
}



void PlaylistManager::AddTrackToPlaylist(int playlistIndex, const Track& track) {
    if (playlistIndex >= 0 && playlistIndex < _playlists.size()) {
        _playlists[playlistIndex]->AddTrack(track);
        std::cout << "Трек добавлен в плейлист." << std::endl;
    } else {
        std::cout << "Некорректный индекс плейлиста." << std::endl;
    }
}

Playlist* PlaylistManager::GetPlaylist(int index) {
    if (index >= 0 && index < _playlists.size()) {
        return _playlists[index].get(); // Возвращаем указатель на плейлист
    }
    return nullptr; // Если индекс некорректен
}

int PlaylistManager::GetPlaylistCount() const {
    return static_cast<int>(_playlists.size());
}
