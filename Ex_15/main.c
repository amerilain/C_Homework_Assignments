#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main(void) {
    menu_item items[MAX_ITEMS];
    int itemCount = 0;
    char filename[256];

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open %s\n", filename);
        return 1;
    }

    while (itemCount < MAX_ITEMS && fscanf(file, "%[^;]; %lf\n", items[itemCount].name, &items[itemCount].price) != EOF) {
        itemCount++;
    }
    fclose(file);

    printf("Items from the file:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%8.2lf %s\n", items[i].price, items[i].name);
    }

    return 0;
}
