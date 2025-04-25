#ifndef PLAYLISTSELECTOR_H
#define PLAYLISTSELECTOR_H

#include <QWidget>
#include <QListWidget>
#include <QWidget>


namespace Ui {
class PlaylistSelector;
}

class PlaylistSelector : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistSelector(QWidget *parent = nullptr);
    ~PlaylistSelector();

    void loadPlaylistsFromFolders();
    void addPlaylist();
    void removePlaylist(const QString &name);
    bool isRemoving = false;
    bool isADD = false;


    bool isPlaylistNameValid(const QString &playlistName) const {
        QRegularExpression regex("^[^<>:\"/|?*]+$");
        return regex.match(playlistName).hasMatch();
    }

private:
    Ui::PlaylistSelector *ui;
    QListWidget *playlistListWidget;
    static PlaylistSelector *instance;



private slots:
    void on_btnAddPlaylist_clicked();
    void on_btnRemovePlaylist_clicked();
    void onPlaylistItemDoubleClicked(QListWidgetItem *item);


};

#endif // PLAYLISTSELECTOR_H
