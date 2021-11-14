#include <challenges.h>

// TODO: this function
void genericChallenge() {

}

// 4th challenge
void badFileDescriptorChallenge() {
    if(write(13, "La respuesta es fk3wfLCm3QvS\n", 30) == ERROR_CODE)
        perror("write in fd 13 failed");
}

// TODO: this function
// 7th challenge
void filterErrorChallenge() {

}

// 8th challenge
void questionChallenge() {
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
}

// 10th challenge
void quineChallenge() {

    int isPresent = system("gcc quine.c -o quine");

    if(isPresent == VALID) {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

        int isValid = system("./quine | diff - quine.c");

        if(isValid == VALID)
            printf("La respuesta es chin_chu_lan_cha\n\n");
        else
            printf("\n%s\n", "diff encontró diferencias.");

    } else {
        printf("\n\nENTER para reintentar.\n");
    }
}