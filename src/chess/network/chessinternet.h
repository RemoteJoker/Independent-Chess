#ifndef CHESSINTERNET_H
#define CHESSINTERNET_H

#include <QThread>
#include <QTcpSocket>

#include "../global/globaldata.h"

class ChessInternet : public QThread
{
    Q_OBJECT
public:
    ChessInternet();

protected:
    void run();

private:
    void ReadTcpData();

private:
    QTcpSocket *t_client_socket;
    QVector<E_Home_Status>t_home_data;
};

#endif // CHESSINTERNET_H
