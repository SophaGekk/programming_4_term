#include "widget.h"
#include "ui_widget.h"
#include "C:/Users/Sopha/Downloads/gg/lab4/ConsoleLogger.h"
#include <QDir>
#include <QPushButton>
#include <QAudioOutput>
#include <QTimer>
#include "playlistselector.h"
#include <QDirIterator>
#include <QLineEdit>
#include <QInputDialog>
#include <QMessageBox>

int currentTrackIndex = 0;

Widget::Widget(const QString &playlistName, PlaylistSelector *selector, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    playlistName(playlistName),
    playlistSelector(selector)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::checkMediaPlayerState);
    timer->start(100); // Проверять каждые 100 мс


    // 1. Настройка TableView
    m_playListModel = new QStandardItemModel(this);
    loadPlaylistData(playlistName);
    ui->playlistView->setModel(m_playListModel);
    m_playListModel->setHorizontalHeaderLabels(QStringList() << tr("Audio Track") << tr("File Path"));
    ui->playlistView->hideColumn(1);
    ui->playlistView->verticalHeader()->setVisible(false);
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);
    ui->progressSlider->setRange(0, 100); //макс слайдер

    // 2. Инициализация QMediaPlayer
    m_player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    m_player->setAudioOutput(audioOutput);

    // 4. Connect для управления плеером
    connect(ui->btn_play, &QPushButton::clicked, this, &Widget::on_btn_play_clicked);
    connect(ui->btn_pause, &QPushButton::clicked, this, &Widget::on_btn_pause_clicked);
    connect(ui->btn_previous, &QPushButton::clicked, this, &Widget::on_btn_previous_clicked);
    connect(ui->btn_next, &QPushButton::clicked, this, &Widget::on_btn_next_clicked);
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &Widget::on_volumeSlider_valueChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &Widget::onMediaPlayerPositionChanged);

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &Widget::onMediaStatusChanged); // Подключаем новый сигнал
    connect(ui->progressSlider, &QSlider::sliderPressed, [this]() { isSeeking = true; // Начало перемотки
 });
    connect(ui->progressSlider, &QSlider::sliderReleased, [this]() { isSeeking = false; // Конец перемотки
        // Вызываем обработчик перемотки
        on_progressSlider_sliderReleased();
    });

    // Для плавной перемотки при перемещении ползунка
    connect(ui->progressSlider, &QSlider::sliderMoved, [this](int value) {
        if(isSeeking) {
            int newPosition = static_cast<double>(value) / 100 * m_player->duration();
            m_player->setPosition(newPosition);
        }
    });

    // 5. Connect для выбора трека
    connect(ui->playlistView, &QTableView::doubleClicked, this, &Widget::on_playlistView_doubleClicked);
    connect(ui->btnBack, &QPushButton::clicked, this, &Widget::on_btnBack_clicked);
    connect(ui->btnRemove, &QPushButton::clicked, this, &Widget::on_btn_remove_clicked);

    connect(ui->playlistView, &QListView::doubleClicked, this, &Widget::on_playlistView_doubleClicked);
    connect(ui->playlistView, &QListView::clicked, this, &Widget::on_playlistView_clicked);
    connect(ui->btnRename, &QPushButton::clicked, this, &Widget::on_renameButton_clicked);

    ui->progressSlider->setStyleSheet(R"(
    QSlider::groove:horizontal {
        height: 8px;
        background: #404040;
        border-radius: 4px;
    }
    QSlider::sub-page:horizontal {
        background: #00ff88;
        border-radius: 4px;
    }
    QSlider::handle:horizontal {
        background: #ffffff;
        width: 16px;
        margin: -4px 0;
        border-radius: 8px;
    }
)");
}


Widget::~Widget() {
    delete ui;
    delete m_playListModel;
    delete m_player;
}
#include <QFileInfo>

void Widget::checkMediaPlayerState() {
    qint64 position = m_player->position();
    if (position > 0) {
        isPlaying = true;
    } else {
        isPlaying = false;
    }
}


void Widget::on_btn_add_clicked() {
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Open files"), QString(), tr("Audio Files (*.mp3)"));

    // 1. Создаем папку для плейлиста
    QDir playlistDir("C:/Users/Sopha/Downloads/gg/Music/" + playlistName); //Путь сохранения музыки
    if (!playlistDir.exists()) {
        if (!playlistDir.mkpath(".")) {
            qDebug() << "Не удалось создать папку плейлиста!";
            return;
        }
    }

    foreach (QString filePath, files) {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        QString newFilePath = playlistDir.path() + "/" + fileName;

        // 2. Копируем файл
        if (QFile::copy(filePath, newFilePath)) {
            qDebug() << "Файл скопирован в: " << newFilePath;

            // 3. Добавляем в QStandardItemModel для отображения
            QList<QStandardItem *> items;
            items.append(new QStandardItem(fileName)); // Используем название файла
            items.append(new QStandardItem(newFilePath)); //Сохраняем новый путь
            m_playListModel->appendRow(items);
        } else {
            qDebug() << "Не удалось скопировать файл!";
        }
    }
}

void Widget::on_btn_play_clicked() {
    if (m_playListModel->rowCount() > 0) {
        if (m_player->source().isEmpty()) {
            QString filePath = m_playListModel->data(m_playListModel->index(0, 1)).toString();
            QString trackName = m_playListModel->data(m_playListModel->index(0, 0)).toString();
            ui->currentTrackLabel->setText("Now Playing: " + trackName); // Обновляем текст метки
            m_player->setSource(QUrl::fromLocalFile(filePath));
        }

        // Начинаем воспроизведение
        m_player->play(); // Запускаем воспроизведение
        isPlaying = true; // Обновляем состояние

        // Обновляем иконку кнопки "Play"
        ui->btn_play->setEnabled(false); // Деактивируем кнопку "Play"
        ui->btn_pause->setEnabled(true);  // Активируем кнопку "Pause"
    } else {
        qDebug() << "Плейлист пуст. Добавьте треки в плейлист";
    }
}

void Widget::on_btn_pause_clicked() {
    if (isPlaying) {
        m_player->pause(); // Ставим на паузу
        isPlaying = false; // Обновляем состояние

        // Обновляем иконку кнопки
        ui->btn_play->setEnabled(true); // Активируем кнопку "Play"
        ui->btn_pause->setEnabled(false); // Деактивируем кнопку "Pause"
    }
}



// Обработчик изменения статуса медиа
void Widget::onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::EndOfMedia) { // Проверяем, закончился ли трек
        on_btn_next_clicked();
    }
}


void Widget::on_playlistView_doubleClicked(const QModelIndex &index) {
    QString filePath = m_playListModel->data(m_playListModel->index(index.row(), 1)).toString();
    QString trackName = m_playListModel->data(m_playListModel->index(index.row(), 0)).toString();
    ui->currentTrackLabel->setText("Now Playing: " + trackName); // Обновляем текст метки
    m_player->setSource(QUrl::fromLocalFile(filePath));
    m_player->play();
}


void Widget::on_renameButton_clicked() {
    // Остановите воспроизведение, если оно активно
    if (m_player->playbackState() == QMediaPlayer::PlayingState) {
        m_player->stop(); // Останавливаем воспроизведение
    }
    QModelIndex index = ui->playlistView->currentIndex(); // Получаем текущий индекс
    if (!index.isValid()) return; // Проверяем, что индекс действителен

    // Получаем текущее название трека и путь к файлу
    QString currentTrackName = m_playListModel->data(index.sibling(index.row(), 0)).toString(); // Название трека
    QString filePath = m_playListModel->data(m_playListModel->index(index.row(), 1)).toString(); // Путь к файлу

    // Получаем расширение файла
    QFileInfo fileInfo(filePath);
    QString extension = fileInfo.suffix(); // Получаем расширение файла (например, "mp3")

    // Убираем расширение из currentTrackName
    currentTrackName = currentTrackName.remove("." + extension, Qt::CaseInsensitive);

    bool ok;
    QString newTrackName;

    do {
        newTrackName = QInputDialog::getText(this, tr("Rename Track"), tr("New track name:"), QLineEdit::Normal, currentTrackName, &ok);
        if (!ok) return; // Если пользователь отменил, выходим из функции
        if (newTrackName.isEmpty()) {
            QMessageBox::warning(this, tr("Invalid Name"), tr("Имя трека не может быть пустым."));
            continue; // Повторяем запрос
        }
        if (!isTrackNameValid(newTrackName)) {
            QMessageBox::warning(this, tr("Invalid Name"), tr("Пожалуйста, придумайте другое название треку. Без символов < > : \" / \\ | ? *"));
        }
    } while (!isTrackNameValid(newTrackName) || newTrackName.isEmpty());

    // Формируем новый путь с измененным именем
    QString newFilePath = fileInfo.absolutePath() + "/" + newTrackName + "." + extension;

    // Копируем файл с новым именем
    if (QFile::copy(filePath, newFilePath)) {
        if (QFile::remove(filePath)) {
            // Обновляем модель
            m_playListModel->setData(index.sibling(index.row(), 0), newTrackName);
            m_playListModel->setData(index.sibling(index.row(), 1), newFilePath);
        } else {
            qDebug() << "Ошибка удаления оригинала";
        }
    } else {
        qDebug() << "Ошибка переимнования.";
    }

}

void Widget::on_playlistView_clicked(const QModelIndex &index) {
    // Активируем кнопку "Rename", если элемент выделен
    ui->btnRename->setEnabled(index.isValid());
}


void Widget::on_volumeSlider_valueChanged(int value) {
    QAudioOutput *audioOutput = qobject_cast<QAudioOutput*>(m_player->audioOutput());
    if (audioOutput) {
        audioOutput->setVolume(value / 100.0); // Преобразование в диапазон 0.0 - 1.0
    }
}

void Widget::on_progressSlider_sliderReleased() {
    int sliderValue = ui->progressSlider->value();
    int trackDuration = m_player->duration(); // Получаем общую длину трека

    // Перематываем на процент от общей длины
    int newPosition = (sliderValue / 100.0) * trackDuration;

    m_player->setPosition(newPosition);
}

void Widget::on_btn_next_clicked() {
    if (currentTrackIndex < ui->playlistView->model()->rowCount() - 1) {
        currentTrackIndex++;
        QString filePath = ui->playlistView->model()->data(ui->playlistView->model()->index(currentTrackIndex, 1)).toString();
        QString trackName = ui->playlistView->model()->data(ui->playlistView->model()->index(currentTrackIndex, 0)).toString();
        ui->currentTrackLabel->setText("Now Playing: " + trackName); // Обновляем текст метки
        m_player->setSource(QUrl::fromLocalFile(filePath));
        m_player->play();
    }
}

void Widget::on_btn_previous_clicked() {
    if (currentTrackIndex > 0) {
        currentTrackIndex--;
        QString filePath = ui->playlistView->model()->data(ui->playlistView->model()->index(currentTrackIndex, 1)).toString();
        QString trackName = ui->playlistView->model()->data(ui->playlistView->model()->index(currentTrackIndex, 0)).toString();
        ui->currentTrackLabel->setText("Now Playing: " + trackName); // Обновляем текст метки
        m_player->setSource(QUrl::fromLocalFile(filePath));
        m_player->play();
    }
}

void Widget::onMediaPlayerPositionChanged(int position) {
    if(!isSeeking) { // Обновляем только если не в процессе перемотки
        int trackDuration = m_player->duration();
        updateTimeDisplay(position);
        if(trackDuration > 0) {
            int sliderValue = static_cast<double>(position) / trackDuration * 100;
            ui->progressSlider->setValue(sliderValue);
        }
    }
}

void Widget::updateTimeDisplay(int position) {
    int seconds = (position / 1000) % 60;
    int minutes = (position / 1000) / 60;
    ui->timeLabel->setText(QString("%1:%2")
                               .arg(minutes, 2, 10, QLatin1Char('0'))
                               .arg(seconds, 2, 10, QLatin1Char('0')));
}

void Widget::loadPlaylistData(const QString &playlistName) {
    QDir playlistDir("C:/Users/Sopha/Downloads/gg/Music/" + playlistName);

    // Проверяем, существует ли папка плейлиста
    if (!playlistDir.exists()) {
        qDebug() << "Папка плейлиста не существует: " << playlistDir.path();
        return;
    }

    // Создаем итератор для поиска .mp3 файлов
    QDirIterator it(playlistDir.path(), QStringList() << "*.mp3", QDir::Files, QDirIterator::Subdirectories);

    // Очищаем модель перед загрузкой новых данных
    m_playListModel->clear();

    // Загружаем файлы в модель
    while (it.hasNext()) {
        QString filePath = it.next();
        QFileInfo fileInfo(filePath);

        // Проверяем, является ли файл действительным
        if (fileInfo.exists() && fileInfo.isFile()) {
            QString fileName = fileInfo.fileName();

            // Добавляем в QStandardItemModel для отображения
            QList<QStandardItem *> items;
            items.append(new QStandardItem(fileName)); // Используем название файла
            items.append(new QStandardItem(filePath)); // Сохраняем путь
            m_playListModel->appendRow(items);

            qDebug() << "Загружен трек: " << fileName << " из " << filePath;
        } else {
            qDebug() << "Файл не найден или не является файлом: " << filePath;
        }
    }
}


void Widget::on_btnBack_clicked()
{
    if (playlistSelector) {
        playlistSelector->show(); // Показываем существующее окно PlaylistSelector
        this->hide(); // Скрываем текущее окно Widget
        m_player->pause();
        m_player->stop();

    } else {
        qDebug() << "Error: playlistSelector is null!"; // Обработка ошибки, если указатель null
    }
}

void Widget::on_btn_remove_clicked() {
    QModelIndex currentIndex = ui->playlistView->currentIndex();
    if (!currentIndex.isValid()) {
        qDebug() << "Выберите песню для удаления.";
        return;
    }

    QString filePath = m_playListModel->item(currentIndex.row(), 1)->text();
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists()) {
        qDebug() << "Файл не существует: " << filePath;
        return;
    }

    // Останавливаем воспроизведение, если оно активно
    if (isPlaying) {
        m_player->stop();
        isPlaying = false;
    }

    // Путь для резервной копии
    QString backupDir = "C:/Users/Sopha/Downloads/gg/Music/backup/";
    QString backupPath = backupDir + fileInfo.fileName();

    // Проверяем, существует ли директория для резервных копий
    QDir dir(backupDir);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) { // Создаем директорию, если она не существует
            qDebug() << "Не удалось создать директорию для резервных копий: " << backupDir;
            return;
        }
    }

    // Пытаемся создать копию файла
    if (QFile::copy(filePath, backupPath)) {
        qDebug() << "Копия файла создана: " << backupPath;

        // Теперь пытаемся удалить оригинал
        if (QFile::remove(filePath)) {
            qDebug() << "Файл удален: " << filePath;
            m_playListModel->removeRow(currentIndex.row());

            // Удаляем резервную копию
            if (QFile::remove(backupPath)) {
                qDebug() << "Резервная копия удалена: " << backupPath;
            } else {
                qDebug() << "Не удалось удалить резервную копию: " << backupPath;
            }
        } else {
            qDebug() << "Не удалось удалить файл: " << filePath;
        }
    } else {
        qDebug() << "Не удалось создать копию файла: " << filePath;}
}

