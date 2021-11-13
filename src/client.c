#include <client.h>

int main(int argc, const char *argv[]) {
    struct sockaddr_in serv_addr;
    int socketFd = 0;

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        errorHandler("Error creating socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(MY_PORT);

    if (inet_pton(AF_INET, MY_ADDR, &serv_addr.sin_addr) <= 0) {
        errorHandler("Invalid address");
    }

    if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == ERROR_CODE) {
        errorHandler("Connection failed");
    }

    printf("Succesful connection!\n");

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);

    printf("Enter your answer: ");

    while (fgets(buffer, MAX_BUFFER - 1, stdin) != NULL) {

        if (send(socketFd, buffer, strlen(buffer), 0) == ERROR_CODE) {
            errorHandler("Error sending answer");
        }

        memset(buffer, 0, MAX_BUFFER);

        printf("Enter your next answer: ");
    }

    close(socketFd);
    
}
