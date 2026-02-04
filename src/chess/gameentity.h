#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "chess/chessboard.h"

class GameEntity
{
public:
    GameEntity();
    ~GameEntity();

private:
    ChessBoard* g_chess_board;
};

#endif // GAMEENTITY_H
