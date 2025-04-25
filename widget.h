#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDir>
#include "C:/Users/Sopha/Downloads/gg/lab4/PlaylistManager.h"
#include "C:/Users/Sopha/Downloads/gg/lab4/Player.h"
#include <QAudioOutput>
#include "playlistselector.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(const QString &playlistName, PlaylistSelector *selector, QWidget *parent = nullptr);
    ~Widget() override;


    bool isTrackNameValid(const QString &trackName) const {
        QRegularExpression regex("^[^<>:\"/\\\\|?*]+$");
        return regex.match(trackName).hasMatch();
    }

private slots:
    void on_btn_add_clicked();      // Добавить треки
    void on_btn_play_clicked();     // Воспроизвести
    void on_playlistView_doubleClicked(const QModelIndex &index); // Двойной клик по треку

    void on_volumeSlider_valueChanged(int value); //уровень громкости - микшер
    void on_progressSlider_sliderReleased(); //прогресс трека

    void on_btn_next_clicked(); //Следующий трек

    void on_btn_previous_clicked();//Предыдущий трек
    void onMediaPlayerPositionChanged(int position); //Перемещение полузнка
    void updateTimeDisplay(int position); //Прогресс трека - время

    void checkMediaPlayerState(); //Обновление состояния ползунка
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status); //Отслеживание конца трека

    void loadPlaylistData(const QString &playlistName); //загрузка данных
    void on_btnBack_clicked(); //Вовзращение в меню
    void on_btn_pause_clicked(); // Пауза
    void on_btn_remove_clicked(); //Удаление трека
    void on_playlistView_clicked(const QModelIndex &index); // Статус выделения песни
    void on_renameButton_clicked(); //Переименование трека



protected:
    Ui::Widget *ui;
    QStandardItemModel *m_playListModel; // Модель данных плейлиста для отображения
    QMediaPlayer *m_player;           // Проигрыватель треков

    QString playlistName;

    bool isSeeking = false; //флаг перемотки
    bool isPlaying = false; //флаг проигрывания

    PlaylistSelector *playlistSelector;

    QListView *m_playListView;
};

#endif // WIDGET_H
