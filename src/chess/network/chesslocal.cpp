#include "chesslocal.h"

ChessLocal::ChessLocal() {
    t_server_socket = new QUdpSocket(this);
    t_client_socket = new QUdpSocket(this);

    t_server_socket->bind(60030, QUdpSocket::ShareAddress);
    connect(t_server_socket, &QUdpSocket::readyRead, this, &ChessLocal::ReadUdpData);

    t_home_data.reserve(100);
    for(int i=0; i<100; i++){
        t_home_data.append(static_cast<E_Home_Status>(NoPeople));
    }
}

void ChessLocal::run(){
    while(1){}
}

void ChessLocal::ReadUdpData() {
    while(t_server_socket->hasPendingDatagrams()){
        QByteArray v_data;
        v_data.resize(t_server_socket->pendingDatagramSize());
        QHostAddress v_client_addr;
        quint16 v_client_port;
        t_server_socket->readDatagram(v_data.data(), v_data.size(), &v_client_addr, &v_client_port);
        S_Data *v_s_data = (S_Data*)v_data.data();
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
}

void ChessLocal::SendUdpBroadcast(const QByteArray &data) {
    qint64 sendLen = t_client_socket->writeDatagram(data, QHostAddress::Broadcast,60030);
}
