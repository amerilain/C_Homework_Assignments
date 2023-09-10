#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array, unsigned int what);

int main(void) {
    const int size = 20;
    unsigned int numbers[size];
    unsigned int userInput;
    int index;

    srand(time(NULL));

    // Fill numbers[] with random numbers between 1 and 20
    for (int i = 0; i < size - 1; i++) {
        numbers[i] = (rand() % 20) + 1; // 1 - 20 instead of 0 - 19
        printf("%u\n", numbers[i]);
    }

    // Set last element to zero
    numbers[size - 1] = 0;
    printf("%u\n", numbers[size - 1]);

    do {
        printf("\nEnter number to search for or zero to stop: ");
        scanf("%u", &userInput);

        if (userInput != 0) {
            index = find_first(numbers, userInput);
            if (index != -1) {
                printf("Number found at index: %d\n", index);
            } else {
                printf("Number not found.\n");
            }
        }
    } while (userInput != 0);

    return 0;
}

// Returns the index of the first occurrence of what in array, or -1 if not found
int find_first(const unsigned int *array, unsigned int what) {
    int i = 0;
    while (array[i] != 0) {
        if (array[i] == what) {
            return i;
        }
        i++;
    }
    return -1;
}
