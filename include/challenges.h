#ifndef CHALLENGES_H
#define CHALLENGES_H

#include <lib.h>

#define CHALLENGE_HEADER "------------- DESAFIO -------------"
#define EXTRA_QUESTION_HEADER "----- PREGUNTA PARA INVESTIGAR -----"
#define MAX_LEVELS 12

typedef struct Challenge {
    char * hint;
    char * ans;
    char * extraQ;
    void (*func)(void);
} Challenge;

void genericChallenge();
void badFileDescriptorChallenge();
void filterErrorChallenge();
void questionChallenge();
void quineChallenge();

#endif