#pragma once
#include <cstdio>
#include <cstdlib>
//#define USING_WINSOCK
#ifdef USING_WINSOCK
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

using SOCKET = int;

#endif

class UdpServer
{
    SOCKET s;
    struct sockaddr_in server, si_other;
    int slen, recv_len;
    static const int BUFLEN = 512;
    static const int PORT = 9888;
    char buf[BUFLEN];

#ifdef USING_WINSOCK
    WSADATA wsa;
    HANDLE hIOMutex;
#endif
    int kill;
    static void staticUdpServerCallback(void*);
    void udpServerCallback(void);

public:
    bool bReceivedTTT;
    bool bReceivedKKK;
    bool bReceivedPPP;
    bool bReceivedRRR;
    bool bReceivedName;
    char sNameOfDataFile[512];
    UdpServer();
    ~UdpServer();
};

