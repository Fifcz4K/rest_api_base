#include "server.h"

#ifdef __WIN32__
void serverStartup(void)
{
    WSADATA data;
    WSAStartup(MAKEWORD(2,2), &data);
}

void serverClean(void)
{
    WSACleanup();
}
#endif

int serverSocket;

void serverSocketCreate(void)
{
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("cannot create socket");
        exit(0);
    }

    printf("socket created\n");
}

void serverSocketBind(void)
{
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address)); 
    
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT); 

    if(bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) < 0) 
    { 
        perror("bind failed"); 
        exit(0);
    }

    printf("socked binded\n");
}

void serverListen(void)
{
    if(listen(serverSocket, MAX_CONNECTION_REQUESTS) < 0) 
    { 
        perror("listen failed");
        exit(0);
    }

    printf("listening\n");
}

void serverProcess(void)
{
    int clientSocket;
    struct sockaddr_in clientAddress;
    int clientAddressLen = sizeof(clientAddress);
    char readBuffer[TCP_RECV_BUFFER_SIZE];
    char *response = NULL;

    while(1)
    {
        if((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen)) < 0)
        {
            exit(0);     
        }
        
        printf("connection accepted\n");   
        memset(readBuffer, 0, TCP_RECV_BUFFER_SIZE);

        recv(clientSocket, readBuffer, TCP_RECV_BUFFER_SIZE, 0);

        response = rest_processRequest(readBuffer);

        send(clientSocket, response, strlen(response), 0);

        close(clientSocket);
    }
}