#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "../global/globaldata.h"

class Player
{
public:
    Player();
    virtual ~Player();

public:
    virtual void SetPlayerStatus(E_PlayerStatus) = 0;
    virtual E_PlayerStatus GetPlayerStatus() = 0;
    virtual void SetPlayerId(E_PlayerId) = 0;
    virtual E_PlayerId GetPlayerId() = 0;
};

#endif // PLAYER_H
