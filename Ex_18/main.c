#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int shiftAmount;
    srand(time(NULL));

    while (1) {
        printf("Enter a number in the range from 0 to 15 or a negative number to stop: ");
        scanf("%d", &shiftAmount);

        if (shiftAmount < 0) {
            printf("Program stopped.\n");
            return 0;
        }

        if (shiftAmount >= 0 && shiftAmount <= 15) {
            int randomNumber = rand();
            printf("Random number in hexadecimal: %X\n", randomNumber);

            int shiftedNumber = (randomNumber >> shiftAmount) & 0x3F;
            printf("Shifted and masked number in hexadecimal: %02X\n", shiftedNumber);
        } else {
            printf("Invalid input. Please enter a number between 0 and 15.\n");
        }
    }

    return 0;
}
