#include "peopleplayer.h"

PeoplePlayer::PeoplePlayer() {
    SetPlayerStatus(Ready);
    SetPlayerId(Ai);
}

PeoplePlayer::~PeoplePlayer() {}

void PeoplePlayer::SetPlayerStatus(E_PlayerStatus v_status){
    g_play_status = v_status;
}

E_PlayerStatus PeoplePlayer::GetPlayerStatus(){
    return g_play_status;
}

void PeoplePlayer::SetPlayerId(E_PlayerId v_id){
    g_chess_flag = v_id;
}

E_PlayerId PeoplePlayer::GetPlayerId(){
    return g_chess_flag;
}
