#ifndef GLOBALDATA_H
#define GLOBALDATA_H

/*所有界面*/
enum E_ViewId{
    NoneView,/*无界面*/
    InitView,/*初始化界面*/
    SingleView,/*单人界面*/
    LocalView,/*局域网界面*/
    InternetView,/*互联网界面*/
    HallView,/*大厅界面*/
    GameView,/*游戏界面*/
    ResultView,/*结算界面*/
    SettingView,/*设置界面*/
};

/*模式选择*/
enum E_ModuleId{
    NoneModule,/*无模式*/
    SingleModule,/*单人模式*/
    LocalModule,/*局域网模式*/
    InteretModule,/*互联网模式*/
};

/*棋子ID*/
enum E_ChessId{
    Chariot_R_L,//车
    Chariot_R_R,
    Knight_R_L,//马
    Knight_R_R,
    Elephant_R_L,//象
    Elephant_R_R,
    Guard_R_L,//士
    Guard_R_R,
    General_R,//将
    Cannon_R_L,//炮
    Cannon_R_R,
    Pawn_R_0,//兵
    Pawn_R_1,
    Pawn_R_2,
    Pawn_R_3,
    Pawn_R_4,
    Chariot_B_L,//车
    Chariot_B_R,
    Knight_B_L,//马
    Knight_B_R,
    Elephant_B_L,//象
    Elephant_B_R,
    Guard_B_L,//士
    Guard_B_R,
    General_B,//将
    Cannon_B_L,
    Cannon_B_R,//炮
    Pawn_B_0,//兵
    Pawn_B_1,
    Pawn_B_2,
    Pawn_B_3,
    Pawn_B_4,
};

/*棋方*/
enum E_ChessFLag{
    Red,/*红*/
    Black,/*黑*/
};

/*玩家ID*/
enum E_PlayerId{
    People,/*人类*/
    Ai,/*AI*/
};

/*玩家状态*/
enum E_PlayerStatus{
    Ready,/*准备*/
    Wait,/*等待*/
    Move,/*移动*/
    Finish,/*结束*/
};

/*AI水平*/
enum E_Ai_Level{
    Easy,/*简单*/
    Normal,/*正常*/
    Master,/*大师*/
};

/*房间状态*/
enum E_Home_Status{
    NoPeople,/*无人*/
    OnePeople,/*等待*/
    TwoPeople,/*满员*/
};

/*协议ID*/
enum E_Data_Id{
    NoneMsg,
    HomeMsg,/*房间信息*/
};

typedef struct S_Data{
    E_Data_Id s_id;//0:房间信息  1:
    char s_data[64];
}S_Data;

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
