#include "client.h"

int main(int argc, const char *argv[]) {
    struct sockaddr_in serv_addr;
    int socketFd = 0;

    if (argc != 3) {
        fprintf(stderr, "Incorrect amount of arguments\n");
        exit(EXIT_FAILURE);
    }

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        errorHandler("Error creating socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(argv[2]);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        errorHandler("Invalid address");
    }

    if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == ERROR_CODE) {
        errorHandler("Connection failed");
    }
}
