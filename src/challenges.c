#include <challenges.h>

static void gdbme();

// 4th challenge
void badFileDescriptorChallenge() {
    if(write(13, "La respuesta es fk3wfLCm3QvS\n", 30) == ERROR_CODE)
        perror("write");
}

// 7th challenge
void filterErrorChallenge() {
    char *answer = "La respuesta es K5n2UFfpFMUN";
    int len = strlen(answer);
    putchar('\n');

    for(int i = 0; i < len; i++) {
        char aux1[2] = {answer[i], 0};
        write(1, aux1, 1);
        for(int j = 0; j < (rand() % (20 - 6 + 1)) + 6; j++) {
            char c = (rand() % (122 - 65 + 1)) + 65;
            char aux2[2] = {c, 0};
            write(STDERR, aux2, 1);
        }
    }

    putchar('\n');
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

// 11th challenge
void gdbmeChallenge() {
    gdbme();
}

// 12th challenge
void randChallenge() {
    double x, y, num;
    for(int i = 0; i < 1000; i++) {
        x = rand() / ((double) RAND_MAX + 1);
        y = rand() / ((double) RAND_MAX + 1);
        num = sqrt(-2 * log(x)) * cos(2* M_PI * y);
        printf("%.6f ", num);
    }
    putchar('\n');
}

static void gdbme() {
    if(getpid() == 0x12345678)
        printf("La respuesta es gdb_rules\n\n");
}