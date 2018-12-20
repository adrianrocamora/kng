#include "UdpServer.h"

UdpServer::UdpServer()
{
    bReceivedPPP = false;
    bReceivedKKK = false;
    bReceivedTTT = false;
    bReceivedRRR = false;
    bReceivedName = false;
    kill = 0;
#ifdef USING_WINSOCK
    hIOMutex = CreateMutex(NULL, FALSE, NULL);
    _beginthread(UdpServer::staticUdpServerCallback, 0, this);
#endif
}


UdpServer::~UdpServer(void)
{
    bReceivedPPP = false;
    bReceivedKKK = false;
    bReceivedTTT = false;
    bReceivedRRR = false;
    bReceivedName = false;
    kill = 1;
    closesocket(s);
#ifdef USING_WINSOCK
    WSACleanup();
#endif
}

void UdpServer::staticUdpServerCallback(void *a)
{
    ((UdpServer *) a)->udpServerCallback();
}

void UdpServer::udpServerCallback(void)
{
    slen = sizeof(si_other);

    //Initialize winsock
#ifdef USING_WINSOCK
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Initialised.\n");
#endif

    //Create a socket
    if((s = socket(AF_INET , SOCK_DGRAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
    printf("Socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( PORT );

    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    puts("Bind done");

    //keep listening for data
    while(!kill)
    {
        //printf("Waiting for data...");
        fflush(stdout);

        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);

        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
        {
            if (kill) {
                break;
            }
            else {
                //printf("recvfrom() failed with error code : %d" , WSAGetLastError());
                exit(EXIT_FAILURE);
            }
        }

        //print details of the client/peer and the data received
        //printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        //printf("Data: %s\n" , buf);

        if (buf[0] == 'P' && buf[1] == 'P' && buf[2] == 'P' && buf[3] == '\0') {
            bReceivedPPP = true;
        }
        else if (buf[0] == 'K' && buf[1] == 'K' && buf[2] == 'K' && buf[3] == '\0') {
            bReceivedKKK = true;
        }
        else if (buf[0] == 'R' && buf[1] == 'R' && buf[2] == 'R' && buf[3] == '\0') {
            bReceivedRRR = true;
        }
        else if (buf[0] == 'T' && buf[1] == 'T' && buf[2] == 'T' && buf[3] == '\0') {
            bReceivedTTT = true;
        }
        else if (buf[0] != '\0') {
            // Get the name of the file
            strcpy(sNameOfDataFile, buf);
            bReceivedName = true;
        }
        
        //now reply the client with the same data
        if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
        {
#ifdef USING_WINSOCK
            printf("sendto() failed with error code : %d" , WSAGetLastError());
#endif
            exit(EXIT_FAILURE);
        }
    }
} 

