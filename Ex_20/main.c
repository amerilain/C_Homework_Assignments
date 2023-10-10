#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int user_debug_level;

    printf("Enter debug level (0-4): ");
    scanf("%d", &user_debug_level);

    if (user_debug_level < 0 || user_debug_level > 4) {
        printf("Invalid debug level\n");
        return 1;
    }

    set_debug_level(user_debug_level);

    srand(time(NULL));

    for (int i = 1; i <= 5; i++) {
        int random_debug_level = rand() % 5;
        dprintf(random_debug_level, "Message %d with random debug level %d\n", i, random_debug_level);
    }

    return 0;
}
