#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>

#include "../global/globaldata.h"

class ChessPiece
{
public:
    ChessPiece();
    virtual ~ChessPiece();

public:
    bool GetFlag();//获取棋标志
    bool SetFlag(E_ChessFLag);

    bool GetStatus();//获取棋状态
    bool SetStatus(bool);

    E_ChessId GetId();//获取棋ID
    bool SetId(E_ChessId);

    QPair<quint32,quint32> GetPos();//获取坐标
    bool SetPos(const QPair<quint32,quint32>);

    quint32 GetWeight();//获取棋子权重
    bool SetWeight(quint32);

public:
    bool CheckAvalible(QPair<quint32,quint32>,QPair<quint32,quint32>,E_ChessId);

private:
    bool v_flag;
    bool v_status;
    E_ChessId v_id;
    quint32 v_x;
    quint32 v_y;
    quint32 v_weight;
};

#endif // CHESSPIECE_H
