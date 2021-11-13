#include "client.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>

#define ERROR_CODE -1

int main(int argc, const char *argv[]) {
    struct sockaddr_in serv_addr;
    int socketFd = 0;

    if (argc != 3) {
        fprintf(stderr, "Incorrect amount of arguments\n");
        exit(EXIT_FAILURE);
    }

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(argv[2]);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == ERROR_CODE) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}