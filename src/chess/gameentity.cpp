#include "gameentity.h"

GameEntity::GameEntity() {
    g_chess_board = new ChessBoard;
    g_chess_board->InitChessBoard();
}

GameEntity::~GameEntity() {}

void GameEntity::FlushGame(QWidget*,quint32){
    //g_chess_board->FlushChessBoard();
}
