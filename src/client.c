#include <client.h>

static char *answers[] = {
    "entendido\n",
    "itba\n",
    "M4GFKZ289aku\n",
    "fk3wfLCm3QvS\n",
    "too_easy\n",
    ".RUN_ME\n",
    "K5n2UFfpFMUN\n",
    "BUmyYq5XxXGt\n",
    "u^v\n",
    "chin_chu_lan_cha\n",
    "gdb_rules\n",
    "normal\n",
    NULL
};

static int socketFd = 0;

static void solveManually();
static void solveAutomatically(int challengesToSolve);

int main(int argc, const char *argv[]) {

    if (argc > 2 || argc < 1) {
        fprintf(stderr, "Incorrect amount of arguments\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 2 && (atoi(argv[1]) > 12 || atoi(argv[1]) < 1)) {
        fprintf(stderr, "Incorrect amount of challenges to solve");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    socklen_t addrLength = sizeof(serv_addr);

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        errorHandler("Error creating socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(MY_PORT);

    if (inet_pton(AF_INET, MY_ADDR, &serv_addr.sin_addr) <= 0) {
        errorHandler("Invalid address");
    }

    if (connect(socketFd, (struct sockaddr *)&serv_addr, addrLength) == ERROR_CODE) {
        errorHandler("Connection failed");
    }

    printf("Succesful connection!\n");

    if (argc != 1) {
        solveAutomatically(atoi(argv[1]));
    }

    solveManually();
    close(socketFd);
    
}

static void solveManually() {

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);

    printf("Inserte su respuesta: ");
    
    while (fgets(buffer, MAX_BUFFER - 1, stdin) != NULL) {

        if (send(socketFd, buffer, strlen(buffer), 0) == ERROR_CODE) {
            errorHandler("Error sending answer");
        }

        memset(buffer, 0, MAX_BUFFER);
        printf("Inserte su respuesta: ");
    }
}

static void solveAutomatically(int challengesToSolve) {

    for (int i = 0; i < challengesToSolve - 1 && answers[i]; i++) {

        if (send(socketFd, answers[i], strlen(answers[i]), 0) == ERROR_CODE) {
            errorHandler("Error sending answer");
        }
    }
}
