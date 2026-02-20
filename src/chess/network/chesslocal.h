#ifndef CHESSLOCAL_H
#define CHESSLOCAL_H

#include <QThread>
#include <QUdpSocket>

#include "../global/globaldata.h"

class ChessLocal : public QThread
{
    Q_OBJECT
public:
    ChessLocal();

protected:
    void run();

private:
    void ReadUdpData();
    void SendUdpBroadcast(const QByteArray &data);

private:
    QUdpSocket *t_server_socket;
    QUdpSocket *t_client_socket;
    QVector<E_Home_Status>t_home_data;
};

#endif // CHESSLOCAL_H
