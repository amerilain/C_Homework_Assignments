#include <stdio.h>
#include <string.h>

#define maxStringSize 256

int count_words(const char* str, const char *word) {
    int count = 0;
    const char* currentPosition = str;

    while ((currentPosition = strstr(currentPosition, word)) != NULL) {
        count++;
        currentPosition += strlen(word);
    }

    return count;
}

int main(void) {
    char userInput[maxStringSize];
    char searchWord[maxStringSize];
    int count;

    printf("Enter a sentence: ");
    fgets(userInput, maxStringSize, stdin);
    userInput[strcspn(userInput, "\n")] = '\0';

    do {
        printf("Enter a word to search for - Or enter 'stop' to exit: ");
        fgets(searchWord, maxStringSize, stdin);
        searchWord[strcspn(searchWord, "\n")] = '\0';

        if (strlen(searchWord) == 0) {
            printf("Please enter a valid word.\n");
            continue;
        }

        if (strcmp(searchWord, "stop") == 0) {
            printf("Program stopped.\n");
            break;
        } else {
            count = count_words(userInput, searchWord);
            printf("The word '%s' appears %d times in the string.\n", searchWord, count);
        }

    } while (1);

    return 0;
}
