#include "newServer.h"

void buildSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, socklen_t addressLength);
void endSocket(int serverFd, int clientFd);
void startGame(int socketFd);


int main () {

    struct sockaddr_in serverAddress;
    socklen_t addressLength = sizeof(serverAddress);
    int serverSocketFd, clientSocketFd;
    int optValue = 1;

    buildSocket(&serverSocketFd, &optValue, &clientSocketFd, &serverAddress, addressLength);

    startGame(clientSocketFd);

    endSocket(serverSocketFd, clientSocketFd);

    return 0;
}

void buildSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, socklen_t addressLength) {

    if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        errorHandler("Error creating socket");
    }

    if(setsockopt(*serverFd, SOL_SOCKET, SO_REUSEADDR, optValue, sizeof(*optValue)) == ERROR_CODE) {
        errorHandler("Error setting socket opt");
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(MY_PORT);

    if(bind(*serverFd, address, addressLength) == ERROR_CODE) {
        errorHandler("Error binding socket");
    }

    if(listen(*serverFd,BACKLOG) == ERROR_CODE) {
        errorHandler("Error listening socket");
    }

    if((*clientFd = accept(*serverFd, address, &addressLength)) == ERROR_CODE) {
        errorHandler("Error accepting socket");
    }

    return;
}

void endSocket(int serverFd, int clientFd) {
    if(close(serverFd) == ERROR_CODE) {
        errorHandler("Error closing socket");
    }

    if(close(clientFd) == ERROR_CODE) {
        errorHandler("Error closing socket");
    }
}

void startGame(int socketFd) {
    printf("Building game in process");
}