#include <challenges.h>

void badFileDescriptorChallenge() {
    if(write(13, "La respuesta es fk3wfLCm3QvS\n", 30) == ERROR_CODE)
        perror("write in fd 13 failed");
}

void challenge7() {

}

void questionChallenge() {
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
}

void challenge10() {

}