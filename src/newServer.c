#include <newServer.h>

static void buildSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, socklen_t addressLength);
static void endSocket(int serverFd, int clientFd);
static void startGame(int socketFd);
static void clearScreen();

static Challenge challengeArray[] = {
    {
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n

        En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n
        Además tendrán que investigar otras preguntas para responder durante la defensa.\n
        El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\n
        Además, deberán implementar otro programa para comunicarse conmigo.\n\n

        Deberán estar atentos a los easter eggs.\n\n

        Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra \'entendido\\n\'\n\n\n",
        "entendido\n",
        "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n\n",
        genericChallenge // TODO: hacer esta funcion
    },
    {
        "The Wire S1E5\n
        5295 888 6288\n\n\n",
        "itba\n",
        "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n\n",
        genericChallenge
    },
    {
        "https://ibb.co/tc0Hb6w\n\n\n",
        "M4GFKZ289aku\n",
        "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n\n",
        genericChallenge
    },
    {
        "EBADF... \n",
        "fk3wfLCm3QvS\n",
        "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?",
        badFileDescriptorChallenge
    }
};

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

static void buildSocket(int * serverFd, int * optValue, int * clientFd, struct sockaddr_in * address, socklen_t addressLength) {

    if ((*serverFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_CODE) {
        errorHandler("Error creating socket");
    }

    if(setsockopt(*serverFd, SOL_SOCKET, SO_REUSEADDR, optValue, sizeof(*optValue)) == ERROR_CODE) {
        errorHandler("Error setting socket opt");
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(MY_PORT);

    if(bind(*serverFd, (struct sockaddr *) &address, addressLength) == ERROR_CODE) {
        errorHandler("Error binding socket");
    }

    if(listen(*serverFd,BACKLOG) == ERROR_CODE) {
        errorHandler("Error listening socket");
    }

    if((*clientFd = accept(*serverFd, (struct sockaddr *) &address, &addressLength)) == ERROR_CODE) {
        errorHandler("Error accepting socket");
    }

    return;
}

static void endSocket(int serverFd, int clientFd) {
    if(close(serverFd) == ERROR_CODE) {
        errorHandler("Error closing socket");
    }

    if(close(clientFd) == ERROR_CODE) {
        errorHandler("Error closing socket");
    }
}

static void startGame(int socketFd) {
    unsigned int currentLevel = 1;
    char * buffer = malloc(sizeof(char) * BUFFER_SIZE);

    if(buffer == NULL) {
        errorHandler("Error creating space for a buffer");
    }

    while(currentLevel < MAX_LEVELS) {
        clearScreen();
        //TODO
        printf("----- CHALLENGE ----------\n");
        printf("----- PISTA --------------\n");
    }

    clearScreen();
    printf("----- GAME OVER ----------\n");
    free(buffer);
}

static void clearScreen() {
    printf("\033[1;1H\033[2J");
}