#ifndef NEW_SERVER_H
#define NEW_SERVER_H

#include "lib.h"

#define MY_PORT 8080
#define BACKLOG 10

#define BUFFER_SIZE 100

#define MAX_LEVELS 13
const char * EASTER_EGG =  
"_______________________\n"
"< ESTO ES UN EASTER_EGG >\n"
 "-----------------------\n"
    "    \\   ^__^\n"
    "    \\  (oo)\\_______\n"
    "        (__)\\       )\\/\\\n"
    "           ||----w |\n"
    "           ||     ||\n";


void buildSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, socklen_t addressLength);
void endSocket(int serverFd, int clientFd);
void startGame(int socketFd);
void clearScreen();

#endif