#include "aiplayer.h"

AIPlayer::AIPlayer() {
    SetPlayerStatus(Ready);
    SetPlayerId(Ai);
}

AIPlayer::~AIPlayer() {}

void AIPlayer::SetPlayerStatus(E_PlayerStatus v_status){
    g_play_status = v_status;
}

E_PlayerStatus AIPlayer::GetPlayerStatus(){
    return g_play_status;
}

void AIPlayer::SetPlayerId(E_PlayerId v_id){
    g_chess_flag = v_id;
}

E_PlayerId AIPlayer::GetPlayerId(){
    return g_chess_flag;
}
