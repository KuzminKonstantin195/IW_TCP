#include "tcp_client_parent.h"

TCP_Client_parent::TCP_Client_parent(QString ip, quint32 port_num)
{
    _socket = new QTcpSocket;
    _stream = new QDataStream;

    set_ip(ip);
    set_port(port_num);

/*
    if (! connect_to_host())
    {
        return;
    }
*/
}

TCP_Client_parent::~TCP_Client_parent()
{
    delete _socket;
    delete _stream;
}

//########################################################################

void TCP_Client_parent::set_port (quint32 port_num)
{
    if (get_connect_status())
    {
        disconnect_from_host();
    }

    this->port = port_num;
}

void TCP_Client_parent::set_ip (QString ip)
{
    if (get_connect_status())
    {
        disconnect_from_host();
    }

    this->server_ip = ip;
}

bool TCP_Client_parent::connect_to_host ()
{
    _socket->connectToHost(server_ip, port);

    if (! _socket->isOpen() )
    {
        return false;
    }

    _stream->setDevice(_socket);
    _stream->setVersion(QDataStream::Qt_6_8);

    if (_stream->status() != QDataStream::Ok)
    {
        return false;
    }

    connect(_socket, &QTcpSocket::disconnected, _socket, &QTcpSocket::deleteLater);
    connect(_socket, &QTcpSocket::disconnected, [&](){delete _stream;});
    connect(_socket, &QTcpSocket::readyRead, this, &TCP_Client_parent::socket_readyRead_slot);

    connect_status = true;
    return true;
}

bool TCP_Client_parent::disconnect_from_host()
{
    _socket->disconnectFromHost();

    if (_socket->isOpen() )
    {
        return false;
    }
    connect_status = false;
    return true;
}

bool TCP_Client_parent::get_connect_status ()
{
    return connect_status;
}

bool TCP_Client_parent::get_stream_status ()
{
    if (_stream->status() == QDataStream::Ok)
    {
        return true;
    } else
    {
        return false;
    }
}

//########################################################################

void TCP_Client_parent::set_id (quint16 id)
{
    this->client_id = id;
}

quint16 TCP_Client_parent::get_id ()
{
    return client_id;
}

void TCP_Client_parent::set_locker (bool flag)
{
    this->msg_locker = flag;
}

bool TCP_Client_parent::get_locker ()
{
    return msg_locker;
}

void TCP_Client_parent::set_size (quint64 size_val)
{
    this->msg_size = size_val;
}

quint64 TCP_Client_parent::get_size ()
{
    return msg_size;
}

quint64 TCP_Client_parent::socket_bytes_aveilable ()
{
    if (get_connect_status())
    {
        return _socket->bytesAvailable();
    }
    return 0;
}

//##################################### SLOTS #################################

void TCP_Client_parent::ready_read(QByteArray &b_arr)
{
    if (get_stream_status() && get_connect_status())
    {
        // если флаг false, то читаем начало сообщения
        if (!get_locker())
        {
            *_stream >> msg_size;

            if (socket_bytes_aveilable() < msg_size + QDS_SIZE_MSG)
            {
                set_locker(true);
            }
        }

        if (socket_bytes_aveilable() == msg_size + QDS_SIZE_MSG)
        {
            buffer.resize(msg_size, NULL);

            *_stream >> buffer;

            return;
        }
    } else
    {
        qDebug() << "Read failed! Check connection state!";
        return;
    }
}

void TCP_Client_parent::socket_readyRead_slot ()
{
    socket_readyRead_signal ();
}
