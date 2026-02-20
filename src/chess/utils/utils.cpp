#include "utils.h"

QString Utils::v_name = "None";
QString Utils::v_save_path = QDir::homePath();
QString Utils::v_cache_path = QDir::currentPath()+"/cache";
QMediaPlayer *Utils::v_player = nullptr;
QAudioOutput *Utils::v_audio_output = nullptr;

/*初始化APP*/
bool Utils::InitApp(){
    QDir v_dir;
    if(!v_dir.exists(v_cache_path)){
        v_dir.mkdir(v_cache_path);
        v_dir.mkdir(v_cache_path+"/log");
        v_dir.mkdir(v_cache_path+"/music");

        v_player = new QMediaPlayer;
        v_audio_output = new QAudioOutput;

        int v_rand_num = QRandomGenerator::global()->bounded(10000);
        v_name = QHostInfo::localHostName()+"_"+QString("%1").arg(v_rand_num, 4, 10, QChar('0'));
        return true;
    }else{
        v_player = new QMediaPlayer;
        v_audio_output = new QAudioOutput;

        int v_rand_num = QRandomGenerator::global()->bounded(10000);
        v_name = QHostInfo::localHostName()+"_"+QString("%1").arg(v_rand_num, 4, 10, QChar('0'));
        return true;
    }
}

/*播放音乐*/
bool Utils::StartMusic(){
    if(1){
        v_player->setAudioOutput(v_audio_output);
        v_player->setSource(QUrl(v_cache_path+"/music/chess.wav"));
        v_player->setLoops(QMediaPlayer::Infinite);
        v_audio_output->setVolume(1.0);
        v_player->play();
        return true;
    }else{
        return false;
    }
}

/*修改音乐*/
bool Utils::ChangeMusic(QUrl v_url){
    v_player->pause();
    v_player->setAudioOutput(v_audio_output);
    v_player->setSource(v_url);
    v_player->setLoops(QMediaPlayer::Infinite);
    v_audio_output->setVolume(1.0);
    v_player->play();
    return true;
}

/*开机自启*/
bool Utils::EnableGame(){
    QSettings v_registry("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    v_registry.setValue("Chess", QDir::currentPath()+"/chess.exe");
    return true;
}

/*保存路径*/
bool Utils::SavePath(QString v_str){
    if(v_str == ""){
        return false;
    }
    v_save_path = v_str;
    return true;
}

/*卸载游戏*/
bool Utils::DeleteGame(){
    QString v_game_path = QDir::currentPath();
    QDir v_game_dir(v_game_path);
    if(!v_game_dir.exists()){
        return true;
    }
    QFileInfoList v_file_list = v_game_dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for(QFileInfo v_file_info : v_file_list){
        if(v_file_info.isDir()){
            QDir v_sub_dir(v_file_info.absoluteFilePath());
            v_sub_dir.removeRecursively();
        }else{
            QFile v_file(v_file_info.absoluteFilePath());
            v_file.remove();
        }
    }
    return v_game_dir.rmdir(v_game_path);
}

QString Utils::GetName(){
    return v_name;
}
