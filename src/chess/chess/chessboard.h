#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chesspiece.h"

class ChessBoard
{
public:
    ChessBoard();
    virtual ~ChessBoard();

    bool InitChessBoard();
    bool FlushChessBoard(E_ChessFLag);

private:
    QString GetUrl();
    bool SetUrl(QString);

    quint32 GetChessNum();
    bool SetChessNum(quint32);

    quint32 GetWidth();
    bool SetWidth(quint32);

    quint32 GetHeight();
    bool SetHeight(quint32);

private:
    QString v_url;
    quint32 v_chess_num;
    quint32 v_width;
    quint32 v_height;

    QList<ChessPiece>v_chess_list;
};

#endif // CHESSBOARD_H
