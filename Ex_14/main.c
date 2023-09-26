#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_LINES 100

int main(void) {
    char lines[MAX_LINES][MAX_LINE_LENGTH + 1];
    char line[MAX_LINE_LENGTH + 1];
    int lineCount = 0;
    char filename[256];

    // Get the filename from the user
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // open the file and return error and exit if it doesn't exist
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open %s\n", filename);
        return 1;
    }

    // read the file line by line
    while (lineCount < MAX_LINES && fgets(line, MAX_LINE_LENGTH + 1, file)) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(lines[lineCount], line);
        lineCount++;
    }
    fclose(file);

    // convert the lines to uppercase
    int i, j;
    for (i = 0; i < lineCount; i++) {
        int lengthOfCurrentLine = strlen(lines[i]);
        for (j = 0; j < lengthOfCurrentLine; j++) {
            char currentCharacter = lines[i][j];
            char upperCaseCharacter = toupper(currentCharacter);
            lines[i][j] = upperCaseCharacter;
        }
    }

    // open the file again for writing updated lines
    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Couldn't open %s \n", filename);
        return 1;
    }

    for (i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);

    printf("%s has been updated with uppercase letters.\n", filename);
    return 0;
}
