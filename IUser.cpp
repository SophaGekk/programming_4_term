#include "IUser.h"
#include <iostream>

IUser::IUser(Player & player, PlaylistManager & playlistManager, ILogger* logger)
	: _player(player), _playlistManager(playlistManager), _logger(logger) {}

void IUser::Start() {
	int choice;
	
	do {
		std::cout <<
			"\n1. Создать новый плейлист\n"
			"2. Удалить плейлист\n"
			"3. Добавить трек в плейлист\n"
			"4. Удалить трек из плейлиста\n"
			"5. Воспроизвести\n"
			"6. Остановить\n"
			"0. Выход\n"
			"Выберите опцию: ";
	
		if (!(std::cin >> choice)) {
			std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
			std::cin.clear(); // Очистка флага ошибки
			std::cin.ignore(10000, '\n'); // Игнорирование оставшихся символов в буфере
			continue; // Переход к следующей итерации
		}
	
		if (choice == 1) {
	
			_playlistManager.CreatePlaylist();
			_logger->Log("Создан новый плейлист.");
	
		} else if (choice == 2) {
	
			int index;
	
			std::cout <<
				"Введите индекс плейлиста для удаления: ";
	
			if (!(std::cin >> index)) {
				std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
	
			_playlistManager.RemovePlaylist(index);
			_logger->Log("Плейлист удален.");
	
		} else if (choice == 3) {
	
			int playlistIndex;
	
			std::cout <<
				"Введите индекс плейлиста: ";
	
			if (!(std::cin >> playlistIndex)) {
				std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
	
			std::string title, artist;
	
			std::cout <<
				"Введите название трека: ";
	
			std::cin.ignore(); // Игнорирование символа перевода строки в буфере
	
			std::getline(std::cin, title);
	
			std::cout <<
				"Введите исполнителя: ";
	
			std::getline(std::cin, artist);
	
			_player.AddTrackToPlaylist(playlistIndex, title, artist);
			_logger->Log("Трек добавлен в плейлист.");
	
		} else if (choice == 4) {
	
			int playlistIndex, trackIndex;
	
			std::cout <<
				"Введите индекс плейлиста: ";
	
			if (!(std::cin >> playlistIndex)) {
				std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
	
			std::cout <<
				"Введите индекс трека для удаления: ";
	
			if (!(std::cin >> trackIndex)) {
				std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
	
			Playlist* playlist = _playlistManager.GetPlaylist(playlistIndex);
			if (playlist) {
				playlist->RemoveTrack(trackIndex);
				_logger->Log("Трек удален из плейлиста.");
			} else {
				_logger->Log("Некорректный индекс плейлиста.");
			}
	
		} else if (choice == 5) {
	
			int playlistIndex;
	
			std::cout <<
				"Введите индекс плейлиста для воспроизведения: ";
	
			if (!(std::cin >> playlistIndex)) {
				std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
	
			_player.Play(playlistIndex);
			_logger->Log("Воспроизведение плейлиста.");
	
		} else if (choice == 6) {
	
			_player.Stop();
			_logger->Log("Воспроизведение остановлено.");
	
		}
	
	} while (choice != 0);
}
	 