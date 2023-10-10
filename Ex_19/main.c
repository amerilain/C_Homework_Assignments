#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int compareByName(const void *a, const void *b);
int compareByPrice(const void *a, const void *b);

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

    // Prompt user for sorting order
    printf("Choose sorting order:\n");
    printf("1. Sort by name\n");
    printf("2. Sort by price\n");
    int choice;
    scanf("%d", &choice);

    // Sort based on user's choice
    if (choice == 1) {
        qsort(items, itemCount, sizeof(menu_item), compareByName);
    } else if (choice == 2) {
        qsort(items, itemCount, sizeof(menu_item), compareByPrice);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Sorted items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%8.2lf %s\n", items[i].price, items[i].name);
    }

    return 0;
}


int compareByName(const void *a, const void *b) {
    return strcmp(((menu_item *)a)->name, ((menu_item *)b)->name);
}

int compareByPrice(const void *a, const void *b) {
    double priceA = ((menu_item *)a)->price;
    double priceB = ((menu_item *)b)->price;
    return (priceA > priceB) - (priceA < priceB);
}

