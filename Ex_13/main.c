#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char filename[256];
    FILE *file;
    int num, count = 0, min = 0, max = 0, first = 1;

    printf("Enter the filename: ");
    scanf("%255s", filename);

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fscanf(file, "%d", &num) == 1) {
        if (first) {
            min = max = num;
            first = 0;
        } else {
            if (num < min) min = num;
            if (num > max) max = num;
        }
        count++;
    }

    fclose(file);

    if (count > 0) {
        printf("Count of numbers: %d\n", count);
        printf("Lowest number: %d\n", min);
        printf("Highest number: %d\n", max);
    } else {
        printf("No numbers found in the file.\n");
    }

    return 0;
}
