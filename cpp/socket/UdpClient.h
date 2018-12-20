#pragma once
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#pragma comment(lib,"ws2_32.lib") 
//#define SERVER "192.168.0.2" 
 
const char SERVER_MC[50] = "127.0.0.1" ;
class UdpClient
{
    static const int BUFLEN = 512;
    static const int PORT = 8888;
    struct sockaddr_in si_other;
    int s, slen;
    char buf[BUFLEN];
    char message[BUFLEN];
    WSADATA wsa;
    int kill;
    HANDLE hIOMutex;    
    static void staticUdpClientCallback(void*);
    void udpClientCallback(void);
    bool bMessageSet;

public:
    UdpClient(void);
    ~UdpClient(void);
    int sendMessageToServer(char *);
};

