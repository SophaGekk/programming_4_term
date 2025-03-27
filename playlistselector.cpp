#include "playlistselector.h"
#include "ui_playlistselector.h"
#include "widget.h"
#include <QInputDialog>
#include <QSettings>

PlaylistSelector::PlaylistSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistSelector)
{
    ui->setupUi(this);
    playlistListWidget = ui->playlistListWidget;

    connect(ui->playlistListWidget, &QListWidget::itemDoubleClicked, this, &PlaylistSelector::onPlaylistItemDoubleClicked);
    connect(ui->btnAddPlaylist, &QPushButton::clicked, this, &PlaylistSelector::on_btnAddPlaylist_clicked);
    connect(ui->btnRemovePlaylist, &QPushButton::clicked, this, &PlaylistSelector::on_btnRemovePlaylist_clicked);

    loadPlaylistsFromFolders();
}


void PlaylistSelector::on_btnAddPlaylist_clicked()
{
    if (!isADD)
    {
        QString newPlaylistName = QInputDialog::getText(this, "Добавление плейлиста", "Введите имя плейлиста");
        if (!newPlaylistName.isEmpty()) {
            // Проверка на уникальность имени плейлиста
            if (playlistListWidget->findItems(newPlaylistName, Qt::MatchExactly).isEmpty()) {
               addPlaylist(newPlaylistName);
            } else {
                qDebug() << "Плейлист с таким именем уже существует: " << newPlaylistName;
            }
        }
    }
    else
    {
        isADD = false;
        return;
    }
}

void PlaylistSelector::on_btnRemovePlaylist_clicked()
{
    // Проверяем, выбран ли элемент в списке
    QListWidgetItem *currentItem = playlistListWidget->currentItem();
    if (currentItem) {
        QString playlistName = currentItem->text();
        if (!isRemoving)
        {
            removePlaylist(playlistName);
        }
        else
        {
            isRemoving = false;
            return;
        }

    } else {
        qDebug() << "Не выбран ни один плейлист для удаления.";
    }
}



PlaylistSelector::~PlaylistSelector()
{
    delete ui;
}


void PlaylistSelector::addPlaylist(const QString &name)
{
    if (isADD) return; // Если уже в процессе, выходим
    isADD = true;
    // 1. Создаем папку для плейлиста
    QString playlistFolderPath = "C:/Users/Sopha/Downloads/gg/Music/" + name;  //Путь где будут храниться плейлисты
    QDir playlistDir(playlistFolderPath);
    if (!playlistDir.exists()) {
        if (!playlistDir.mkpath(".")) {
            qDebug() << "Не удалось создать папку плейлиста: " << playlistFolderPath;
            return;
        }
        qDebug() << "Создана папка плейлиста: " << playlistFolderPath;
    } else {
        qDebug() << "Папка плейлиста уже существует: " << playlistFolderPath;
    }

    // 2. Добавляем плейлист в список
    playlistListWidget->addItem(name);
    qDebug() << "Плейлист добавлен в список: " << name;

}
void PlaylistSelector::removePlaylist(const QString &name)
{
    if (isRemoving) return; // Если уже в процессе удаления, выходим
    isRemoving = true;
    // 1. Удаляем папку плейлиста
    QString playlistFolderPath = "C:/Users/Sopha/Downloads/gg/Music/" + name;
    QDir playlistDir(playlistFolderPath);

    if (playlistDir.exists()) {
        // Удаляем все содержимое папки (если нужно)
        if (playlistDir.removeRecursively()) {
            qDebug() << "Папка плейлиста удалена: " << playlistFolderPath;
        } else {
            qDebug() << "Не удалось удалить папку плейлиста: " << playlistFolderPath;
        }
    } else {
        qDebug() << "Папка плейлиста не существует: " << playlistFolderPath;
    }

    // 2. Удаляем плейлист из списка
    QList<QListWidgetItem*> items = playlistListWidget->findItems(name, Qt::MatchExactly);
    for (QListWidgetItem* item : items) {
        delete playlistListWidget->takeItem(playlistListWidget->row(item)); // Удаляем элемент из памяти
        qDebug() << "Плейлист удален из списка: " << name;
        break; // Удаляем только один элемент
    }
}


void PlaylistSelector::loadPlaylistsFromFolders()
{
    QString musicFolderPath = "C:/Users/Sopha/Downloads/gg/Music/";
    QDir musicDir(musicFolderPath);

    if (!musicDir.exists()) {
        qDebug() << "Папка Music не существует: " << musicFolderPath;
        return;
    }

    // Устанавливаем фильтр для получения только директорий (плейлистов)
    musicDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList folderList = musicDir.entryInfoList();

    for (const QFileInfo &folderInfo : folderList) {
        // Проверяем, является ли это директорией и не находится ли она в папке backup
        if (folderInfo.isDir() && !folderInfo.fileName().contains("backup", Qt::CaseInsensitive)) {
            QString folderName = folderInfo.fileName();
            playlistListWidget->addItem(folderName); // Добавляем название папки в список
            qDebug() << "Загружен плейлист из папки: " << folderName;
        }
    }
}

void PlaylistSelector::onPlaylistItemDoubleClicked(QListWidgetItem *item)
{
    QString playlistName = item->text();
    Widget *widget = new Widget(playlistName, this); // Передаем имя плейлиста в конструктор Widget
    widget->show();
    this->hide(); // Закрываем текущее окно
}



