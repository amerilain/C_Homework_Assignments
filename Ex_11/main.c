#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 80

int replace_char(char *str, const char *repl);

int main() {
    char text[MAX_STRING_SIZE];
    char repl[3];

    // User input
    printf("Enter the string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Enter two characters for replacement (e.g. e3): ");
    fgets(repl, sizeof(repl), stdin);
    repl[strcspn(repl, "\n")] = '\0';

    int count = replace_char(text, repl);

    if (count > 0) {
        printf("Number of characters replaced: %d\n", count);
        printf("Modified string: %s\n", text);
    } else {
        printf("String was not modified\n");
    }

    return 0;
}


int replace_char(char *str, const char *repl) {
    if (strlen(repl) < 2) {
        return 0;
    }

    int count = 0;
    char *ptr = str;

    while (*ptr != '\0') {
        if (*ptr == repl[0]) {
            *ptr = repl[1];
            count++;
        }
        ptr++;
    }

    return count;
}
