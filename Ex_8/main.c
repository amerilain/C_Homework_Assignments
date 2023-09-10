#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_numbers(const int *array, int count);

const int size = 15;

int main(void) {
    int numbers[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand();
    }

    print_numbers(numbers, size);
    return 0;
}

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++)
    {
        printf("%8d\n", array[i] % 100000000);
    }
}
