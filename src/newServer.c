#include "newServer.h"

int main () {
    struct sockaddr_in serverAddress;
    unsigned int addressLength;
    int serverSocketFd, clientSocketFd;
    int optValue = 1;

    setUpSocket(&serverSocketFd, &optValue, &clientSocketFd, &serverAddress, addressLength);

    close(serverSocketFd);
    close(clientSocketFd);

    return 0;
}

void setUpSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, unsigned int addressLength) {

    if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        errorHandler("Error creating socket");
    }

    if(setsockopt(*serverFd, SOL_SOCKET, SO_REUSEADDR, optValue, sizeof(*optValue)) == ERROR_CODE) {
        errorHandler("Error setting socket opt");
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(MY_PORT);

    if(bind(serverFd)) {

    }

    if() {

    }

    return serverFd;
}

