#include "Player.h"
#include <iostream>

Player::Player(PlaylistManager& playlistManager, TrackFactory& trackFactory, ILogger* logger)
   : _playlistManager(playlistManager), _trackFactory(trackFactory), _logger(logger) {}
   
void Player::Play(int playlistIndex) {
    if (_playlistManager.GetPlaylistCount() == 0) {
        _logger->Log("Нет доступных плейлистов.");
        return;
    }

    Playlist* currentPlaylist = _playlistManager.GetPlaylist(playlistIndex);
    if (!currentPlaylist) {
        _logger->Log("Некорректный индекс плейлиста.");
        return;
    }

    if (currentPlaylist->GetTrackCount() == 0) {
        _logger->Log("Нет треков для воспроизведения в выбранном плейлисте.");
        return;
    }

    for (int i = 0; i < currentPlaylist->GetTrackCount(); ++i) {
        Track track = currentPlaylist->GetTrack(i);
        std::string message = "Воспроизведение: " + track.GetTitle() + " - " + track.GetArtist();
        _logger->Log(message);
    }
}

void Player::Stop() {
   _logger->Log("Воспроизведение остановлено.");
}

void Player::AddTrackToPlaylist(int playlistIndex, const std::string& title, const std::string& artist) {
    Track track = _trackFactory.CreateTrack(title, artist);
    _playlistManager.AddTrackToPlaylist(playlistIndex, track);
    _logger->Log("Трек добавлен в плейлист.");
 }