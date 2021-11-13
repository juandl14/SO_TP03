#include "newServer.h"
#include <sys/socket.h>

int main () {
    struct sockaddr_in serverAddress;
    unsigned int addressLength;
    int serverSocketFd, clientSocketFd;
    int optValue = 1;

    setUpSocket(&serverSocketFd, &optValue, &clientSocketFd, &serverAddress, addressLength);

    close(socketFd);
    close(clientSocketFd);

    return 0;
}

void setUpSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, unsigned int addressLength) {

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(*serverFd, SOL_SOCKET, SO_REUSEADDR, optValue, sizeof(*optValue)) == ERROR_CODE) {
        perror("Error setting socket opt");
        exit(EXIT_FAILURE);
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(MY_PORT);

    if(bind(serverFd)) {

    }

    if() {

    }

    return socketFd;
}

