/* ############################################################################################################################################
 *-------------------------------------------------------------- РУССКИЙ ----------------------------------------------------------------------
 *
 *  Kласс-оболочка для экземпляров QTCPSocket -
 *
 *  Класс решает следующие проблемы "из коробки":
 *
 *      - Передача разных форматов данных (текст, файлы, байтовая передача);
 *      - Многопоточная работа (прием и передача осуществляются в отдельных потоках);
 *      - Работа одновременно с несколькими портами;
 *      -
 *
 * ############################################################################################################################################*/




#ifndef IW_TCP_CLIENT_H
#define IW_TCP_CLIENT_H

#pragma once

#include "headers.h"
#include "tcp_client_parent.h"

//class TCP_Client_bytes :    public TCP_Client_parent {};
//class TCP_Client_string :   public TCP_Client_parent {};
//class TCP_Client_files :    public TCP_Client_parent {};


class IW_TCP_client : public QObject
{
    Q_OBJECT
/*
    TCP_Client_bytes* _client_bytes;
    //TCP_Client_string* _client_string;
    //TCP_Client_files* _client_files;

    QVector<TCP_Client_parent*> prof_ports
                {_client_bytes, _client_string, _client_files};

    QByteArray* _buffer_data;

    quint32 id;                              // id присваивается при первом подключении к серверу

    quint32 set_client_id (quint32 n_id);

public:
    IW_TCP_client (QString server_ip,
                    quint32 port_bytes, quint32 port_string, quint32 port_files);
    ~IW_TCP_client();

    bool connect ();
    bool disconnect ();

    // ########################## SENDING different messages ##########################
    void send_bytes     (QByteArray data);
    void send_message   (QString str);
    void send_files     (QString file_name);

    // ########################## READING bytes     ##########################
    void read_bytes();

    // ########################## SETTINGS & INFOS  ##########################
        // getters
    //QString get_port_list_info ();                  // получить информацию о списке портов и их назначении
    QVector<quint32> get_port_list ();              // получитх список активных портов

    quint32 get_id();

        // setters
    void setup_anchor_port (quint32 port);          // задать "опорный" номер порта - относительно него построятся остальные порты
    void setup_buffer_pointer (QByteArray* _arr);


public slots:
    //
    void clear_buffer ();

signals:
    //
    void ready_read_bytes ();
    void ready_read_string ();
    void ready_read_file ();
*/
};

#endif // IW_TCP_CLIENT_H
