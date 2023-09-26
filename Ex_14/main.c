#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_LINES 100

int main(void) {
    char lines[MAX_LINES][MAX_LINE_LENGTH + 1]; // +1 for the null terminator
    int lineCount = 0;
    char filename[256];

    // Ask user for filename
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read lines from file
    while (lineCount < MAX_LINES && fgets(lines[lineCount], MAX_LINE_LENGTH + 1, file)) {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0'; // Remove newline character
        lineCount++;
    }
    fclose(file);

    // Convert to uppercase
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < strlen(lines[i]); j++) {
            lines[i][j] = toupper(lines[i][j]);
        }
    }

    // Open file for writing
    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename);
        return 1;
    }

    // Write lines to file
    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);

    printf("File %s has been updated with uppercase letters.\n", filename);
    return 0;
}

