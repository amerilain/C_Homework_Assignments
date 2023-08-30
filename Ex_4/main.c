#include <stdio.h>

int read_integer(void);

int main() {
    int num, count = 0;
    double sum = 0.0;
    int continueReading = 1;

    // read integers until a negative number is entered
    while (continueReading) {
        printf("Enter positive numbers or negative to stop: ");
        num = read_integer();

        if (num < 0) {
            continueReading = 0;
        } else {
            sum += num;
            count++;
        }
    }

    // Calculate and print the average
    if (count > 0) {
        double average = sum / count;
        printf("You entered %d positive numbers. The average is: %.3f\n", count, average);
    } else {
        printf("No positive numbers entered.\n");
    }

    return 0;
}


int read_integer(void) {
    int num;
    int isValid = 0;

    while (!isValid) {
        if (scanf("%d", &num) == 1) {
            isValid = 1;
        } else {
            while (getchar() != '\n');
            printf("invalid input\n");
        }
    }
    return num;
}
