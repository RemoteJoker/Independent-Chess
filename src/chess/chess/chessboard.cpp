#include "chessboard.h"

ChessBoard::ChessBoard() {
    ChessPiece v_0;
    v_0.SetFlag(Red);
    v_0.SetId(Chariot_R_L);
    v_0.SetPos(QPair((quint32)0,(quint32)0));
    v_0.SetStatus(true);
    ChessPiece v_1;
    v_1.SetFlag(Red);
    v_1.SetId(Chariot_R_R);
    v_1.SetPos(QPair((quint32)0,(quint32)0));
    v_1.SetStatus(true);
    ChessPiece v_2;
    v_2.SetFlag(Red);
    v_2.SetId(Knight_R_L);
    v_2.SetPos(QPair((quint32)0,(quint32)0));
    v_2.SetStatus(true);
    ChessPiece v_3;
    v_3.SetFlag(Red);
    v_3.SetId(Knight_R_R);
    v_3.SetPos(QPair((quint32)0,(quint32)0));
    v_3.SetStatus(true);
    ChessPiece v_4;
    v_4.SetFlag(Red);
    v_4.SetId(Elephant_R_L);
    v_4.SetPos(QPair((quint32)0,(quint32)0));
    v_4.SetStatus(true);
    ChessPiece v_5;
    v_5.SetFlag(Red);
    v_5.SetId(Elephant_R_R);
    v_5.SetPos(QPair((quint32)0,(quint32)0));
    v_5.SetStatus(true);
    ChessPiece v_6;
    v_6.SetFlag(Red);
    v_6.SetId(Guard_R_L);
    v_6.SetPos(QPair((quint32)0,(quint32)0));
    v_6.SetStatus(true);
    ChessPiece v_7;
    v_7.SetFlag(Red);
    v_7.SetId(Guard_R_R);
    v_7.SetPos(QPair((quint32)0,(quint32)0));
    v_7.SetStatus(true);
    ChessPiece v_8;
    v_8.SetFlag(Red);
    v_8.SetId(General_R);
    v_8.SetPos(QPair((quint32)0,(quint32)0));
    v_8.SetStatus(true);
    ChessPiece v_9;
    v_9.SetFlag(Red);
    v_9.SetId(Cannon_R_L);
    v_9.SetPos(QPair((quint32)0,(quint32)0));
    v_9.SetStatus(true);
    ChessPiece v_10;
    v_10.SetFlag(Red);
    v_10.SetId(Cannon_R_R);
    v_10.SetPos(QPair((quint32)0,(quint32)0));
    v_10.SetStatus(true);
    ChessPiece v_11;
    v_11.SetFlag(Red);
    v_11.SetId(Pawn_R_0);
    v_11.SetPos(QPair((quint32)0,(quint32)0));
    v_11.SetStatus(true);
    ChessPiece v_12;
    v_12.SetFlag(Red);
    v_12.SetId(Pawn_R_1);
    v_12.SetPos(QPair((quint32)0,(quint32)0));
    v_12.SetStatus(true);
    ChessPiece v_13;
    v_13.SetFlag(Red);
    v_13.SetId(Pawn_R_2);
    v_13.SetPos(QPair((quint32)0,(quint32)0));
    v_13.SetStatus(true);
    ChessPiece v_14;
    v_14.SetFlag(Red);
    v_14.SetId(Pawn_R_3);
    v_14.SetPos(QPair((quint32)0,(quint32)0));
    v_14.SetStatus(true);
    ChessPiece v_15;
    v_15.SetFlag(Red);
    v_15.SetId(Pawn_R_4);
    v_15.SetPos(QPair((quint32)0,(quint32)0));
    v_15.SetStatus(true);
    ChessPiece v_16;
    v_16.SetFlag(Black);
    v_16.SetId(Chariot_B_L);
    v_16.SetPos(QPair((quint32)0,(quint32)0));
    v_16.SetStatus(true);
    ChessPiece v_17;
    v_17.SetFlag(Black);
    v_17.SetId(Chariot_B_R);
    v_17.SetPos(QPair((quint32)0,(quint32)0));
    v_17.SetStatus(true);
    ChessPiece v_18;
    v_18.SetFlag(Black);
    v_18.SetId(Knight_B_L);
    v_18.SetPos(QPair((quint32)0,(quint32)0));
    v_18.SetStatus(true);
    ChessPiece v_19;
    v_19.SetFlag(Black);
    v_19.SetId(Knight_B_R);
    v_19.SetPos(QPair((quint32)0,(quint32)0));
    v_19.SetStatus(true);
    ChessPiece v_20;
    v_20.SetFlag(Black);
    v_20.SetId(Elephant_B_L);
    v_20.SetPos(QPair((quint32)0,(quint32)0));
    v_20.SetStatus(true);
    ChessPiece v_21;
    v_21.SetFlag(Black);
    v_21.SetId(Elephant_B_R);
    v_21.SetPos(QPair((quint32)0,(quint32)0));
    v_21.SetStatus(true);
    ChessPiece v_22;
    v_22.SetFlag(Black);
    v_22.SetId(Guard_B_L);
    v_22.SetPos(QPair((quint32)0,(quint32)0));
    v_22.SetStatus(true);
    ChessPiece v_23;
    v_23.SetFlag(Black);
    v_23.SetId(Guard_B_R);
    v_23.SetPos(QPair((quint32)0,(quint32)0));
    v_23.SetStatus(true);
    ChessPiece v_24;
    v_24.SetFlag(Black);
    v_24.SetId(General_B);
    v_24.SetPos(QPair((quint32)0,(quint32)0));
    v_24.SetStatus(true);
    ChessPiece v_25;
    v_25.SetFlag(Black);
    v_25.SetId(Cannon_B_L);
    v_25.SetPos(QPair((quint32)0,(quint32)0));
    v_25.SetStatus(true);
    ChessPiece v_26;
    v_26.SetFlag(Black);
    v_26.SetId(Cannon_B_R);
    v_26.SetPos(QPair((quint32)0,(quint32)0));
    v_26.SetStatus(true);
    ChessPiece v_27;
    v_27.SetFlag(Black);
    v_27.SetId(Pawn_B_0);
    v_27.SetPos(QPair((quint32)0,(quint32)0));
    v_27.SetStatus(true);
    ChessPiece v_28;
    v_28.SetFlag(Black);
    v_28.SetId(Pawn_B_1);
    v_28.SetPos(QPair((quint32)0,(quint32)0));
    v_28.SetStatus(true);
    ChessPiece v_29;
    v_29.SetFlag(Black);
    v_29.SetId(Pawn_B_2);
    v_29.SetPos(QPair((quint32)0,(quint32)0));
    v_29.SetStatus(true);
    ChessPiece v_30;
    v_30.SetFlag(Black);
    v_30.SetId(Pawn_B_3);
    v_30.SetPos(QPair((quint32)0,(quint32)0));
    v_30.SetStatus(true);
    ChessPiece v_31;
    v_31.SetFlag(Black);
    v_31.SetId(Pawn_B_4);
    v_31.SetPos(QPair((quint32)0,(quint32)0));
    v_31.SetStatus(true);
    v_chess_list.append(v_0);
    v_chess_list.append(v_1);
    v_chess_list.append(v_2);
    v_chess_list.append(v_3);
    v_chess_list.append(v_4);
    v_chess_list.append(v_5);
    v_chess_list.append(v_6);
    v_chess_list.append(v_7);
    v_chess_list.append(v_8);
    v_chess_list.append(v_9);
    v_chess_list.append(v_10);
    v_chess_list.append(v_11);
    v_chess_list.append(v_12);
    v_chess_list.append(v_13);
    v_chess_list.append(v_14);
    v_chess_list.append(v_15);
    v_chess_list.append(v_16);
    v_chess_list.append(v_17);
    v_chess_list.append(v_18);
    v_chess_list.append(v_19);
    v_chess_list.append(v_20);
    v_chess_list.append(v_21);
    v_chess_list.append(v_22);
    v_chess_list.append(v_23);
    v_chess_list.append(v_24);
    v_chess_list.append(v_25);
    v_chess_list.append(v_26);
    v_chess_list.append(v_27);
    v_chess_list.append(v_28);
    v_chess_list.append(v_29);
    v_chess_list.append(v_30);
    v_chess_list.append(v_31);
}

ChessBoard::~ChessBoard() {}

bool ChessBoard::InitChessBoard(){
    if(!SetChessNum(32)){
        return false;
    }
    if(!SetWidth(9)){
        return false;
    }
    if(!SetHeight(11)){
        return false;
    }
    return true;
}

bool ChessBoard::FlushChessBoard(E_ChessFLag v){
    if(v == Red){
        //
    }else{
        //
    }
}

QString ChessBoard::GetUrl(){}
bool ChessBoard::SetUrl(QString v){
    if(v==""){
        return false;
    }
}

quint32 ChessBoard::GetChessNum(){
    return v_chess_num;
}
bool ChessBoard::SetChessNum(quint32 v){
    if(v<0){
        return false;
    }
    v_chess_num = v;
    return true;
}

quint32 ChessBoard::GetWidth(){
    return v_width;
}
bool ChessBoard::SetWidth(quint32 v){
    if(v<0){
        return false;
    }
    v_width = v;
    return true;
}

quint32 ChessBoard::GetHeight(){
    return v_height;
}
bool ChessBoard::SetHeight(quint32 v){
    if(v<0){
        return false;
    }
    v_height = v;
    return true;
}
