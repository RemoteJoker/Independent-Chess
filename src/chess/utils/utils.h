#ifndef UTILS_H
#define UTILS_H

#include <QAudioOutput>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QHostInfo>
#include <QLabel>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QRandomGenerator>
#include <QSettings>
#include <QStandardPaths>
#include <QString>
#include <QVBoxLayout>
#include <QButtonGroup>

class Utils
{
public:
    static bool InitApp();//初始化APP
    static bool StartMusic();//开始播放音乐
    static bool ChangeMusic(QUrl);//修改音乐
    static bool EnableGame();//开机自启
    static bool SavePath(QString);//保存文件
    static bool DeleteGame();//卸载游戏
    static QString GetName();

private:
    static QString v_name;//主机
    static QString v_save_path;//保存路径
    static QString v_cache_path;//缓存路径
    static QMediaPlayer *v_player;
    static QAudioOutput *v_audio_output;
};

#endif // UTILS_H
