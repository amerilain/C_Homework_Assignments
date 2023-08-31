#include <stdio.h>

int read_range(int low, int high);

int main() {
    printf("Let’s play!\n");
    for (int i = 0; i < 3; i++) {
        printf("Roll a die and enter your result.\n");
        int user_roll = read_range(1, 6);

        if (user_roll == 6) {
            printf("I got 6. It is a tie!\n");
        } else {
            printf("I got %d. I win!\n", user_roll + 1);
        }
    }
    printf("Better luck next time. Bye!\n");
    return 0;
}

int read_range(int low, int high) {
    int num, valid;

    do {
        printf("Enter a number between %d and %d: ", low, high);

        if (scanf("%d", &num) != 1) {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');
            valid = 0;
        } else if (num < low || num > high) {
            printf("Error: Number not in range.\n");
            valid = 0;
        } else {
            valid = 1;
        }
    } while(!valid);

    return num;
}
