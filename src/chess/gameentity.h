#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "chess/chessboard.h"

class GameEntity
{
public:
    GameEntity();
    ~GameEntity();

public:
    void FlushGame(QWidget*,quint32);

private:
    ChessBoard* g_chess_board;
};

#endif // GAMEENTITY_H
