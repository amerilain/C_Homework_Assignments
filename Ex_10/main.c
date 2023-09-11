#include <stdio.h>
#include <string.h>

#define maxStringSize 256

int main(void) {
    char userInput[maxStringSize];
    int length;

    do {
        printf("Please enter a string: ");
        fgets(userInput, maxStringSize, stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        if (strcmp(userInput, "stop") != 0) {
            length = strlen(userInput);
            printf("Length of the string: %d\n", length);
        }

    } while (strcmp(userInput, "stop") != 0);

    printf("Program stopped.\n");
    return 0;
}
