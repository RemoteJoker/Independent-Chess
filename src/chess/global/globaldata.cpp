#include "globaldata.h"

int GlobalData::g_view_id = NoneView;
int GlobalData::g_module_id = NoneModule;
char* GlobalData::g_user_name = nullptr;

bool GlobalData::SetViewId(int v){
    if(v<0){
        return false;
    }
    g_view_id = v;
    return true;
}
int GlobalData::GetViewId(){
    return g_view_id;
}

bool GlobalData::SetModuleId(int v){
    if(v<0){
        return false;
    }
    g_module_id = v;
    return true;
}
int GlobalData::GetModuleId(){
    return g_module_id;
}

bool GlobalData::SetUserName(char* v){
    if(v==nullptr){
        return false;
    }
    g_user_name = v;
    return true;
}
char* GlobalData::GetUserName(){
    return g_user_name;
}
