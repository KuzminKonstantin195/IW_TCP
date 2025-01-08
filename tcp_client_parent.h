#ifndef TCP_CLIENT_PARENT_H
#define TCP_CLIENT_PARENT_H

#pragma once

#include "headers.h"

#define QDS_SIZE_MSG 4      //

class TCP_Client_parent : public QObject
{
    Q_OBJECT

    QTcpSocket* _socket;
    QDataStream* _stream;

    QString server_ip;
    quint32 port;
    quint16 client_id;

    bool connect_status;

    void set_port (quint32 port_num);
    void set_ip (QString ip);

    bool    msg_locker;             // флаг-блокировщик чтения сообщения
    quint64 msg_size;               // указатель на размер получаемого сообщения
    quint8 message_type;            // идентификатор отправляемых данных

private:    // methods

    void set_id (quint16 id);

public:     // methods

    QByteArray buffer;

    TCP_Client_parent(QString ip, quint32 port_num);
    ~TCP_Client_parent();

    quint32 get_port ();

    bool connect_to_host ();

    bool disconnect_from_host ();

    bool get_connect_status ();
    bool get_stream_status ();

    void set_locker (bool flag);
    bool get_locker ();

    void set_size (quint64 size_val);
    quint64 get_size ();

    quint16 get_id ();

    quint64 socket_bytes_aveilable ();


private slots:
    //
    void ready_read(QByteArray &b_arr);                // принимает байтово сообщение и записывает его в buffer
    void send (QByteArray &b_arr);
public slots:
    //
    void socket_readyRead_slot ();
    void clear_buffer ();
signals:
    //
    void socket_readyRead_signal ();
    void full_packege_accepted();
};

#endif // TCP_CLIENT_PARENT_H
