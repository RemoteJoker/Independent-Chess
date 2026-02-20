#include "chessinternet.h"

ChessInternet::ChessInternet()
{
    t_client_socket = new QTcpSocket(this);
    t_client_socket->connectToHost(QHostAddress("127.0.0.1"),60000);
    connect(t_client_socket, &QTcpSocket::readyRead, this, &ChessInternet::ReadTcpData);

    t_home_data.reserve(100);
    for(int i=0; i<100; i++){
        t_home_data.append(static_cast<E_Home_Status>(NoPeople));
    }
}

void ChessInternet::run(){
    while(1){}
}

void ChessInternet::ReadTcpData(){
    QByteArray v_recv_data = t_client_socket->readAll();
    S_Data *v_s_data = (S_Data*)v_recv_data.data();
    switch(v_s_data->s_id){
    case HomeMsg:{
        QString v_str_data = QString::fromUtf8(v_s_data->s_data);
        QPair<int, int> v_pair = {v_str_data.split(":").at(0).toInt(), v_str_data.split(":").at(1).toInt()};
        if(v_pair.second == 0){
            t_home_data[v_pair.first] = NoPeople;
        }else if(v_pair.second == 1){
            t_home_data[v_pair.first] = OnePeople;
        }else if(v_pair.second == 2){
            t_home_data[v_pair.first] = TwoPeople;
        }
    }break;
    default:{}break;
    }
}
