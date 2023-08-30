#include <stdio.h>

// Function declaration
int read_integer(void);

int main() {
    int num, count = 0;
    double sum = 0.0;
    int continueReading = 1; // Control variable for the loop

    // Loop to read integers until a negative number is entered
    while (continueReading) {
        printf("Enter positive numbers or negative to stop: ");
        num = read_integer(); // Call read_integer function to read an integer

        if (num < 0) {
            continueReading = 0; // Set control variable to false if a negative number is entered
        } else {
            sum += num; // Add the entered number to the sum
            count++; // Increment the count of entered numbers
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

// Function definition
int read_integer(void) {
    int num;
    int isValid = 0;

    while (!isValid) {
        if (scanf("%d", &num) == 1) {
            isValid = 1;
        } else {
            // Clear the input buffer and print an error message
            while (getchar() != '\n');
            printf("invalid input\n");
        }
    }
    return num;
}
