#include "x05_include.h"
#ifdef INC_X05_1_serverTCPCrossPlat_H

#include <iostream>
#include <string>
#include <cstring>
#include <Ws2tcpip.h>  

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #define SOCKET int
    #define INVALID_SOCKET (-1)
    #define SOCKET_ERROR (-1)
#endif // _WIN32

bool NetworkStartup(WSADATA& ref_wsaData);
bool NetworkCreateSocket(SOCKET& ref_serverSocket);
bool NetworkBindSocket(sockaddr_in ref_serverAddress);
bool NetworkListenConnections(SOCKET& ref_serverSocket);
bool NetworkCleanAndClose(SOCKET& ref_serverSocket);
void CALL_NetworkCreate(void);


void CALL_Networktest(void);


#endif // INC_X05_1_serverTCPCrossPlat_H