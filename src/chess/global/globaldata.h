#ifndef GLOBALDATA_H
#define GLOBALDATA_H

enum E_ViewId{
    NoneView,
    InitView,
    SingleView,
    LocalView,
    InternetView,
    HallView,
    GameView,
    ResultView,
    SettingView,
};
enum E_ModuleId{
    NoneModule,
    SingleModule,
    LocalModule,
    InteretModule,
};
enum E_ChessId{
    Chariot_R_L,
    Chariot_R_R,
    Knight_R_L,
    Knight_R_R,
    Elephant_R_L,
    Elephant_R_R,
    Guard_R_L,
    Guard_R_R,
    General_R,
    Cannon_R_L,
    Cannon_R_R,
    Pawn_R_0,
    Pawn_R_1,
    Pawn_R_2,
    Pawn_R_3,
    Pawn_R_4,
    Chariot_B_L,
    Chariot_B_R,
    Knight_B_L,
    Knight_B_R,
    Elephant_B_L,
    Elephant_B_R,
    Guard_B_L,
    Guard_B_R,
    General_B,
    Cannon_B_L,
    Cannon_B_R,
    Pawn_B_0,
    Pawn_B_1,
    Pawn_B_2,
    Pawn_B_3,
    Pawn_B_4,
};
enum E_ChessFLag{
    Red,
    Black,
};
enum E_PlayerId{
    People,
    Ai,
};
enum E_PlayerStatus{
    Ready,
    Wait,
    Move,
    Finish,
};

class GlobalData
{
public:
    static bool SetViewId(int);
    static int GetViewId();

    static bool SetModuleId(int);
    static int GetModuleId();

    static bool SetUserName(char*);
    static char* GetUserName();

private:
    static int g_view_id;
    static int g_module_id;
    static char* g_user_name;

public:
    GlobalData(const GlobalData&) = delete;
    GlobalData& operator=(const GlobalData&) = delete;

    static GlobalData& getInstance() {
        static GlobalData instance;
        return instance;
    }

private:
    GlobalData() = default;
};

#endif // GLOBALDATA_H
