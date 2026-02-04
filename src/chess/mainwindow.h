#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gameentity.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *m_init_view;
    QWidget *m_single_view;
    QWidget *m_local_view;
    QWidget *m_internet_view;
    QWidget *m_hall_view;
    QWidget *m_game_view;
    QWidget *m_result_view;
    QWidget *m_setting_view;

    GameEntity *g_game_entity;
};
#endif // MAINWINDOW_H
