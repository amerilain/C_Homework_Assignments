#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 256

int main(void) {
    char userInput[MAX_STRING_SIZE];
    int length;

    do {
        printf("Please enter a string: ");
        fgets(userInput, MAX_STRING_SIZE, stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        length = strlen(userInput);
        printf("Length of the string: %d\n", length);

    } while (strcmp(userInput, "stop") != 0);

    printf("Program stopped.\n");
    return 0;
}
