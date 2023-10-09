#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool password_generator(char *password, int size, const char *word);

int main() {
    char word[32];
    char password[65];
    srand(time(NULL));

    int isRunning = 1;
    while (isRunning) {
        printf("Enter a word to place in the password or 'stop' to stop: ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "stop") == 0) {
            isRunning = 0;
            continue;
        }

        if (password_generator(password, sizeof(password), word)) {
            printf("Generated password: %s\n", password);
        } else {
            printf("Error: Password could not be generated.\n");
        }
    }

    return 0;
}

bool password_generator(char *password, int size, const char *word) {
    int word_length = strlen(word);
    int password_length = word_length * 2 + 1;

    if (password_length >= size) {
        return false;
    }

    for (int i = 0, j = 0; i < password_length; i++) {
        if (i % 2 == 0) {
            password[i] = (char)(33 + rand() % 94);
        } else {
            password[i] = word[j++];
        }
    }
    password[password_length] = '\0';
    return true;
}
