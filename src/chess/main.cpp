#include "mainwindow.h"

#include <QApplication>
#include <QSoundEffect>

#include "utils/utils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    bool v_init = Utils::InitApp();
    if(v_init){
        Utils::StartMusic();
        w.show();
    }
    return a.exec();
}
