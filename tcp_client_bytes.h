#ifndef TCP_CLIENT_BYTES_H
#define TCP_CLIENT_BYTES_H

#pragma once

#include "tcp_client_parent.h"

class TCP_Client_bytes : public TCP_Client_parent
{
    Q_OBJECT

public:
    //bool connect_to_host () override;
public slots:
    //
    QByteArray ready_read ();
signals:
    //
};

#endif // TCP_CLIENT_BYTES_H
