#ifndef SERVER_H
#define SERVER_H

#ifdef __WIN32__
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

#include "../rest/rest.h"

#define PORT 30000

#define MAX_CONNECTION_REQUESTS 2
#define TCP_RECV_BUFFER_SIZE 1000

#ifdef __WIN32__
void serverStartup(void);
void serverClean(void);
#endif

void serverSocketCreate(void);
void serverSocketBind(void);
void serverListen(void);
void serverProcess(void);

#endif //SERVER_H