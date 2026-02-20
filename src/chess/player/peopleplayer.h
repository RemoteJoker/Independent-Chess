#ifndef PEOPLEPLAYER_H
#define PEOPLEPLAYER_H

#include "player.h"

class PeoplePlayer: public Player
{
public:
    PeoplePlayer();
    virtual ~PeoplePlayer();

    void SetPlayerStatus(E_PlayerStatus);
    E_PlayerStatus GetPlayerStatus();
    void SetPlayerId(E_PlayerId);
    E_PlayerId GetPlayerId();

private:
    E_PlayerStatus g_play_status;
    E_PlayerId g_chess_flag;
};

#endif // PEOPLEPLAYER_H
