#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gameentity.h"
#include "network/chessinternet.h"
#include "network/chesslocal.h"

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

protected:
    void resizeEvent(QResizeEvent *event) override;

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

    quint32 m_user_select_mode;

    GameEntity *g_game_entity;

    ChessInternet *t_chess_internet;
    ChessLocal *t_chess_local;

private:
    void CheckShowMode();
    void SelectAiLevel();
    void SetBackMusic();
    void EnableStart();
    void SavePath();
    void DeleteGame();

private:
    bool s_show_mode;
    E_Ai_Level s_ai_level;
};
#endif // MAINWINDOW_H
