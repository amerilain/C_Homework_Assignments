#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value) {
    char input[32];
    int number;

    printf("Enter a positive number: ");
    fgets(input, sizeof(input), stdin);

    // Check if the input is a valid number and is positive
    if (sscanf(input, "%d", &number) == 1 && number > 0) {
        *value = number;
        return true;
    }
    return false;
}

int main(void) {
    int guess;
    int attempts = 0;

    printf("Guess how much money I have!\n");

    while (attempts < 3) {
        if (read_positive(&guess)) {
            printf("You didn’t get it right. I have %d euros.\n", 2 * guess + 20);
            printf("Guess how much money I have!\n");
        } else {
            printf("Incorrect input\n");
            attempts++;
            if (attempts < 3) {
                printf("Guess how much money I have!\n");
            }
        }
    }

    printf("I give up! See you later!\n");
    return 0;
}
