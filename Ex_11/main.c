#include <stdio.h>
#include <string.h>

#define maxStringSize 256

int replace_char(char *str, const char *repl);

int main() {
    char text[maxStringSize];
    char repl[3];

    // User input
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter characters to be replaced: ");
    fgets(repl, sizeof(repl), stdin);
    repl[strcspn(repl, "\n")] = '\0';

    int count = replace_char(text, repl);

    if (count > 0) {
        printf("Number of characters replaced: %d\n", count);
        printf("String that was modified: %s\n", text);
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
