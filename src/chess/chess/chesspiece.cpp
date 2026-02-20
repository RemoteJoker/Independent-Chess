#include "chesspiece.h"

ChessPiece::ChessPiece() {}

ChessPiece::~ChessPiece() {}

bool ChessPiece::GetFlag(){
    return v_flag;
}
bool ChessPiece::SetFlag(E_ChessFLag v_flag){
    if(v_flag == Red){
        return true;
    }else{
        return false;
    }
}

bool ChessPiece::GetStatus(){
    return v_status;
}
bool ChessPiece::SetStatus(bool v){
    v_status = v;
    return true;
}

E_ChessId ChessPiece::GetId(){
    return v_id;
}
bool ChessPiece::SetId(E_ChessId v){
    if(v<0){
        return false;
    }
    v_id = v;
    return true;
}

QPair<quint32,quint32> ChessPiece::GetPos(){
    return QPair<quint32, quint32>((quint32)v_x,(quint32)v_y);
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

bool ChessPiece::CheckAvalible(QPair<quint32,quint32> v_source,QPair<quint32,quint32> v_target,E_ChessId v_id){
    quint32 v_src_x = v_source.first;
    quint32 v_src_y = v_source.second;
    quint32 v_tgt_x = v_target.first;
    quint32 v_tgt_y = v_target.second;
    if(((v_src_x>=1)&&(v_src_x<=9))||((v_src_y>=1)&&(v_src_y<=10))||((v_tgt_x>=1)&&(v_tgt_x<=9))||((v_tgt_y>=1)&&(v_tgt_y<=10))){
        return false;
    }
    //判断车的合法性
    if((v_id == Chariot_R_L)||(v_id == Chariot_R_R)||(v_id == Chariot_B_L)||(v_id == Chariot_B_R)){
        if((v_src_x!=v_tgt_x)&&(v_src_y!=v_tgt_y)){
            return false;
        }
    }
    //判断🐎的合法性
    if((v_id == Knight_R_L)||(v_id == Knight_R_R)||(v_id == Knight_B_L)||(v_id == Knight_B_R)){
        if(((v_src_x-v_tgt_x)*(v_src_x-v_tgt_x)+(v_src_y-v_tgt_y)*(v_src_y-v_tgt_y))!=5){
            return false;
        }
    }
    //判断象的合法性
    if((v_id == Elephant_R_L)||(v_id == Elephant_R_R)||(v_id == Elephant_B_L)||(v_id == Elephant_B_R)){
        if(((v_src_x-v_tgt_x)*(v_src_x-v_tgt_x)+(v_src_y-v_tgt_y)*(v_src_y-v_tgt_y))!=8){
            return false;
        }
    }
    //判断士的合法性
    if((v_id == Guard_R_L)||(v_id == Guard_R_R)||(v_id == Guard_B_L)||(v_id == Guard_B_R)){
        if(((v_src_x-v_tgt_x)!=1)||((v_src_y-v_tgt_y)!=1)){
            return false;
        }
    }
    //判断将的合法性
    if((v_id == General_R)||(v_id == General_B)){
        if(((v_src_x-v_tgt_x)!=1)||((v_src_y-v_tgt_y)!=1)){
            return false;
        }
    }
    //判断炮的合法性
    if((v_id == Cannon_R_L)||(v_id == Cannon_R_R)||(v_id == Cannon_B_L)||(v_id == Cannon_B_R)){
        if((v_src_x!=v_tgt_x)&&(v_src_y!=v_tgt_y)){
            return false;
        }
    }
    //判断兵的合法性
    if(((v_src_x-v_tgt_x)!=1)||((v_src_y-v_tgt_y)!=1)){
        return false;
    }
    return true;
}
