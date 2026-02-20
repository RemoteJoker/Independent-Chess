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
    QString GetUrl();//获取棋盘背景文件
    bool SetUrl(QString);

    quint32 GetChessNum();//获取棋子总数
    bool SetChessNum(quint32);

    quint32 GetWidth();//获取纵轴数
    bool SetWidth(quint32);

    quint32 GetHeight();//获取横轴数
    bool SetHeight(quint32);

private:
    QString v_url;
    quint32 v_chess_num;
    quint32 v_width;
    quint32 v_height;

    QList<ChessPiece>v_chess_list;
};

#endif // CHESSBOARD_H
