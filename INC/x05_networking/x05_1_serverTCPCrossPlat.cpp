#include "x05_1_serverTCPCrossPlat.h"
#ifdef INC_X05_1_serverTCPCrossPlat_H

void CALL_Networktest(void)
{
    #ifdef _WIN32
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) 
        {
            std::cerr << "-- ERROR: WSAStartup failed." << std::endl;
            return 1;
        }
    #endif // _WIN32
    //----------------------------------------------------------------------------------------

    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) 
    {
        std::cerr << "-- ERROR: Socket creation failed." << std::endl;

    #ifdef _WIN32
        WSACleanup();
    #endif // _WIN32

        return 1;
    }
    //----------------------------------------------------------------------------------------

    // Bind the socket
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(12345); // Port number
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) 
    {
        std::cerr << "-- ERROR: Bind failed." << std::endl;

    #ifdef _WIN32
        closesocket(serverSocket);
        WSACleanup();
    #else   
        close(serverSocket);
    #endif // _WIN32

        return 1;
    }
    //----------------------------------------------------------------------------------------

    // Listen for incoming connections
    if (listen(serverSocket, 5) == SOCKET_ERROR) 
    {
        std::cerr << "-- ERROR: Listen failed." << std::endl;

    #ifdef _WIN32
        closesocket(serverSocket);
        WSACleanup();
    #else
        close(serverSocket);
    #endif // _WIN32

        return 1;
    }
    //----------------------------------------------------------------------------------------

    std::cout << "Server listening on port 12345..." << std::endl;
    while (true) 
    {
        // Accept incoming connections
        struct sockaddr_in clientAddr;
        #ifdef _WIN32
            int clientAddrSize = sizeof(clientAddr);
        #else
            socklen_t clientAddrSize = sizeof(clientAddr);
        #endif // _WIN32

        SOCKET clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);
        if (clientSocket == INVALID_SOCKET) 
        {
            std::cerr << "-- ERROR: Accept failed." << std::endl;
            break;
        }
        //------------------------------------------------

        std::cout << "Client connected." << std::endl;

        // Main loop to receive and echo data
        char buffer[1024];
        int bytesRead;
        while (true) 
        {
            bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesRead <= 0) 
            {
                std::cerr << "-- ERROR: Connection closed or error occurred." << std::endl;
                break;
            }

            // Echo received data back to the client
            send(clientSocket, buffer, bytesRead, 0);
        }
        //------------------------------------------------

        // Close the client socket
        #ifdef _WIN32
            closesocket(clientSocket);
        #else
            close(clientSocket);
        #endif

        std::cout << "Client disconnected." << std::endl;
    }
    //----------------------------------------------------------------------------------------

    // Cleanup and close the server socket
    #ifdef _WIN32
        closesocket(serverSocket);
        WSACleanup();
    #else
        close(serverSocket);
    #endif
    //----------------------------------------------------------------------------------------
}

bool NetworkStartup(WSADATA& ref_wsaData)
{
    return false;
}
bool NetworkCreateSocket(SOCKET& ref_serverSocket);
bool NetworkBindSocket(sockaddr_in ref_serverAddress);
bool NetworkListenConnections(SOCKET& ref_serverSocket);
bool NetworkCleanAndClose(SOCKET& ref_serverSocket);
void CALL_NetworkCreate(void)
{
    // Step 1. Intialization WSA - WSAStartup()
    WSAData tWSAData;
    int terror;
    WORD wVersionRequested;

    wVersionRequested = MAKEWORD(2,2);
    terror = WSAStartup(wVersionRequested, &tWSAData);
    if(terror != 0)
    {   std::cout << "-- ERROR: The Winsock dll not fould!" << std::endl;
        return; }
    else    
    {   std::cout << "-- INFO: The Winsock dll fould!" << std::endl; 
        std::cout << "-- INFO: szSystemStatus= " << tWSAData.szSystemStatus << std::endl; }
    //-------------------------------------------------------------------------------------

    // Step 2. Create a socket - socket()
    SOCKET tserverSocket;
    tserverSocket = INVALID_SOCKET;

    tserverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(tserverSocket == INVALID_SOCKET)
    {   std::cout << "-- ERROR: Socket problem!" << std::endl;
        WSACleanup();
        return; }
    else
    {   std::cout << "-- INFO: Function scoket() alocated!" << std::endl; }
    //-------------------------------------------------------------------------------------

    // Step 3. Bind the socket - bind()
    struct sockaddr_in tsockaddr;
    tsockaddr.sin_family = AF_INET;
    tsockaddr.sin_addr.s_addr = INADDR_ANY;
    tsockaddr.sin_port = htons(port); // Port number
    terror = bind(tserverSocket, (SOCKADDR*)&tsockaddr, sizeof(tsockaddr));
    if(terror == SOCKET_ERROR)
    {   std::cout << "-- ERROR: Function bind() fail!" << WSAGetLastError() << std::endl;
        closesocket(tserverSocket); 
        WSACleanup();
        return;}
    else
    {   std::cout << "-- INFO: Function bind() OK" << std::endl;}
    //-------------------------------------------------------------------------------------

    // Step 4. Listen on the socket - listen()
    //-------------------------------------------------------------------------------------

    // Step 5. Accept a connection - accept(), connect()
    SOCKET tacceptSocket;
    tacceptSocket = accept(tserverSocket, NULL, NULL);
    if(tacceptSocket == INVALID_SOCKET)
    {   std::cout << "-- ERROR: Function accept() fail! " << WSAGetLastError() << std::endl;
        WSACleanup(); 
        return; }
    //-------------------------------------------------------------------------------------

    // Step 6. Send and recieve data - recv(), send(), recvfrom(), sendto()
    //-------------------------------------------------------------------------------------

    std::cout << "-- " << std::endl;

    // Step 7. Desconect - closesecket()
    closesocket((SOCKET)tserverSocket);
    //-------------------------------------------------------------------------------------
}

#endif // INC_X05_1_serverTCPCrossPlat_H