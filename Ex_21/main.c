#include <stdio.h>
#include <string.h>

int calculate_checksum(const char *line) {
    int checksum = 0;
    for (int i = 1; i < strlen(line) && line[i] != '*'; i++) {
        checksum ^= line[i];
    }
    return checksum;
}

int main(void) {
    char filename[256];
    char line[512];
    int expected_checksum, calculated_checksum;

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '$' && strchr(line, '*')) {
            sscanf(strchr(line, '*') + 1, "%2x", &expected_checksum);
            calculated_checksum = calculate_checksum(line);
            if (calculated_checksum == expected_checksum) {
                printf("[ OK ] %s", line);
            } else {
                printf("[FAIL] %s", line);
            }
        }
    }

    fclose(file);
    return 0;
}
