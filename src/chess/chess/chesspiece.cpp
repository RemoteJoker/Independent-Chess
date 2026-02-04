#include "chesspiece.h"

ChessPiece::ChessPiece() {}

ChessPiece::~ChessPiece() {}

bool ChessPiece::GetFlag(){
    return v_flag;
}
bool ChessPiece::SetFlag(bool v){
    v_flag = v;
    return true;
}

bool ChessPiece::GetStatus(){
    return v_status;
}
bool ChessPiece::SetStatus(bool v){
    v_status = v;
    return true;
}

quint32 ChessPiece::GetId(){
    return v_id;
}
bool ChessPiece::SetId(quint32 v){
    if(v<0){
        return false;
    }
    v_id = v;
    return true;
}

QPair<quint32,quint32> ChessPiece::GetPos(){
    return QPair((quint32)v_x,(quint32)v_y);
}
bool ChessPiece::SetPos(const QPair<quint32,quint32> v){
    if(v.first<0){
        return false;
    }
    if(v.first<0){
        return false;
    }
    v_x = v.first;
    v_y = v.second;
    return true;
}

quint32 ChessPiece::GetWeight(){
    return v_weight;
}
bool ChessPiece::SetWeight(quint32 v){
    if(v<0){
        return false;
    }
    v_weight = v;
    return true;
}

bool ChessPiece::CheckAvalible(){}
