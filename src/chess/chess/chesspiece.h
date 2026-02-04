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
    bool GetFlag();
    bool SetFlag(bool);

    bool GetStatus();
    bool SetStatus(bool);

    quint32 GetId();
    bool SetId(quint32);

    QPair<quint32,quint32> GetPos();
    bool SetPos(const QPair<quint32,quint32>);

    quint32 GetWeight();
    bool SetWeight(quint32);

public:
    bool CheckAvalible();

private:
    bool v_flag;
    bool v_status;
    quint32 v_id;
    quint32 v_x;
    quint32 v_y;
    quint32 v_weight;
};

#endif // CHESSPIECE_H
