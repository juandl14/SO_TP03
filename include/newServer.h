#ifndef NEW_SERVER_H
#define NEW_SERVER_H

#define MY_PORT 8080
#define BACKLOG 10

#include "lib.h"

void buildSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, socklen_t addressLength);
void endSocket(int serverFd, int clientFd);
void startGame(int socketFd);

#endif