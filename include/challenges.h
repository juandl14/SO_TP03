#ifndef CHALLENGES_H
#define CHALLENGES_H

#include <lib.h>

#define CHALLENGE_HEADER "----- CHALLENGE ----------"
#define EXTRA_QUESTION_HEADER "----- EXTRA --------------"
#define END_GAME "----- GAME OVER ----------"
#define CONGRATS "Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto"
#define MAX_LEVELS 12

typedef struct Challenge {
    char * hint;
    char * ans;
    char * extraQ;
    void (*func)(void);
} Challenge;

void badFileDescriptorChallenge();
void filterErrorChallenge();
void questionChallenge();
void quineChallenge();
void gdbmeChallenge();
void randChallenge();

#endif