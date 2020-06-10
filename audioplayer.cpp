#include "audioplayer.h"
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
QString LOCATION ="E:\\Code\\C++2020\\TowerDefenseQt\\music\\"; //在次填写路径否则相关音效真的难顶
//经过实验，用常规方法做的循环音乐会导致卡顿，故使用该方法。
static const QString s_curDir = QDir::currentPath();
QMediaPlayer *player =new QMediaPlayer;
AudioPlayer::AudioPlayer(QObject *parent)
    : QObject(parent)
    , m_backgroundMusic(NULL)
{
    player->setMedia(QUrl("qrc:/music/Bgmusic.mp3"));
    player->setVolume(30);
    player->play();
    // 创建一直播放的背景音乐

}

void AudioPlayer::startBGM()
{
    if (m_backgroundMusic)
        m_backgroundMusic->play();
}

void AudioPlayer::playSound(SoundType soundType)
{
    static const QUrl mediasUrls[] =
    {
        QUrl::fromLocalFile(LOCATION+"tower_place.wav"),
        QUrl::fromLocalFile(LOCATION+"life_lose.wav"),
        QUrl::fromLocalFile(LOCATION+"laser_shoot.wav"),
        QUrl::fromLocalFile(LOCATION+"enemy_destroy.wav")
    };
    static QMediaPlayer player;

    if (QFile::exists(mediasUrls[soundType].toLocalFile()))
    {
        player.setMedia(mediasUrls[soundType]);
        player.setVolume(10);
        player.play();

    }
}

